#include "Koga/800E9568.hpp"
#include "Koga/EnManager.hpp"
#include "Koga/EnTypesManager.hpp"
#include "Koga/GameModeUtil.hpp"
#include "Koga/ToolData.hpp"
#include "Sato/EnThought.hpp"
#include "Unsorted/ActorDataList.hpp"
#include "Koga/800E82D8.hpp"

// Does not match due to some ToolData inline shenanigans. Seems to match more as a u32 input though than u8
// https://decomp.me/scratch/PdZKG
ToolDataRef fn_800E82D8(u32 param_1) {
    ToolDataRef vRef;
    if (param_1 == -1) {
        vRef.reset();
        return vRef;
    }

    Koga::ToolData* treasureTable = Koga::GameModeUtil::getJmpResource("treasuretable");
    if (treasureTable == nullptr) {
        vRef.reset();
        return vRef;
    }

    int roomNo = treasureTable->findEntryByValue(treasureTable->searchItemInfo("room"), param_1 & 0xFF, 0);
    if (roomNo == -1) {
        vRef.reset();
        return vRef;
    }

    vRef.setToolData(treasureTable);
    vRef.setEntryIndex(roomNo);
    return vRef;
}

void fn_800E83A0(EnThought* param_1) {
    s32 temp;
    s32 enNormalTblId = fn_800E8438(param_1);

    // _900 has something else we need to check against, cannot continue without more details
    if (param_1->_900 && enNormalTblId == 3) {
        ToolDataRef sheart = fn_800E8D1C("sheart");
        temp = fn_800E8EF4(&sheart, param_1->getCharacter()->_44, nullptr);
    } else {
        ToolDataRef tRef = fn_800E84CC(enNormalTblId);
        temp = fn_800E8EF4(&tRef, param_1->getCharacter()->_44, nullptr);
    }
}


s32 fn_800E8438(EnThought* param_1) {
    ToolDataRef tRef = param_1->getToolDataRef();

    u32 itemNum;
    if (tRef.isValid() && tRef.getToolData()->getValue(tRef.getEntryIndex(), "item_table", &itemNum)) {
        if (itemNum != 0) {
            return Koga::EnTypesManager::getEnemyNormalItemTblId(param_1->getCharacter()->_3C);
        }
    }
    
    return 0;
}


// https://decomp.me/scratch/iXsZ8
ToolDataRef fn_800E84CC(s32 param_1) {
    ToolDataRef vRef;
    Koga::ToolData* itemAppear = Koga::GameModeUtil::getJmpResource("itemappeartable");
    
    if (itemAppear == nullptr) {
        vRef.reset();
        return ToolDataRef(&vRef);
    }

    int entryIdx = fn_800E85C8(param_1);
    if (entryIdx > itemAppear->getDataEntryNum()) {
        vRef.reset();
        return ToolDataRef(&vRef);
    }

    // Calls upon fn_80009638() to get some value, which is probably the below fieldIdx
    int fieldIdx = 0;
    vRef.findInfoTableName(itemAppear->getStringValue(entryIdx, fieldIdx));
    return vRef;
}

// https://decomp.me/scratch/mcYqn
ToolDataRef ToolDataRef::fn_800E8658(s32 param_1, s32 param_2, s32 param_3) {
    ToolDataRef tmp;
    Koga::ToolData* itemFishing = Koga::GameModeUtil::getJmpResource("itemfishingtable");

    if (itemFishing == nullptr) {
        tmp.reset();
        return ToolDataRef(&tmp);
    }

    if (param_1 <= itemFishing->getDataEntryNum()) {
        tmp.reset();
        return ToolDataRef(&tmp);
    }

    int fieldCount = itemFishing->getJMapData()->mNumFields;
    if (fieldCount < param_3) {
        if (fieldCount <= param_2) {
            param_3 = fieldCount - 1;
        }
    } 
    
    else if (param_3 <= param_2) {
        param_2 = (param_2 - param_3) - (
            ((param_2 - param_3) / (fieldCount - param_3) * (fieldCount - param_3))) + param_3;
    }

    const char* itemName = itemFishing->getStringValue(param_2, param_3);
    if (strcmp(itemName, "-") == 0) {
        tmp.reset();
        return ToolDataRef(&tmp); 
    }

    return fn_800E8D1C(itemName);;
}

void fn_800E87B0(u8* param_1, s32 param_2) {
    u32 temp2;
    Koga::ToolData* itemInfo = Koga::GameModeUtil::getJmpResource("itemappeartable");
    if (itemInfo == nullptr) {
        return;
    }

    s32 numFields = itemInfo->getJMapData()->mNumFields;
    for (s32 i = 0; i < numFields; i++) {
        ToolDataRef tRef = fn_800E8D1C(itemInfo->getStringValue(param_2, i));
        if (!tRef.isNameValid() && !tRef.isNameMoney()) {
            s32 temp = fn_800E8E78(&tRef);
            if (temp < 0) {
                continue;
            }

            *param_1 = ActorData::fn_8006A354(temp);
        }
    }
}

void fn_800E8880(u32 param_1) {
    u8 temp2;
    ToolDataRef tRef = fn_800E82D8(param_1);

    if (!tRef.isValid()) {
        return;
    }

    const char* other;
    tRef.getToolData()->getValue(tRef.getEntryIndex(), "other", &other);
    ToolDataRef temp = fn_800E8D1C(other);
    fn_800E8E0C(&temp, &temp2);
}

ToolDataRef::ToolDataRef(const ToolDataRef* pSrc) {
    setToolData(pSrc->mToolData);
    setEntryIndex(pSrc->mEntryIndex);
}

// https://decomp.me/scratch/qYZ9J
ToolDataRef fn_800E8D1C(const char* pName) {
    ToolDataRef temp;
    Koga::ToolData* itemInfo = Koga::GameModeUtil::getJmpResource("iteminfotable");
    int fieldIndex = itemInfo->searchItemInfo("name");
    int charFound = itemInfo->findEntryByValue(fieldIndex, pName, 0);

    if (charFound == -1) {
        temp.reset();
    } else {
        temp.setToolData(itemInfo);
        temp.setEntryIndex(charFound);
    }

    return temp;
}

// Needed to match isNameValid/Money for now, otherwise it inlines this function.
// https://decomp.me/scratch/JdML7
const char* ToolDataRef::getName() {
    FORCE_DONT_INLINE;
    const char* name;

    if (isValid()) {
        getToolData()->getValue(mEntryIndex, "name", &name);
    }
    return name;
}

void fn_800E8E0C(ToolDataRef* param_1, u8* param_2) {
    if (param_1->isNameValid() && !param_1->isNameMoney()) {
        s32 temp = fn_800E8E78(param_1);
        if (temp >= 0) {
            *param_2 = ActorData::fn_8006A354(temp);
        }
    }
}

// Matches except one instruction. Also depends on the getName above to not inline.
// https://decomp.me/scratch/wZ68w
const BOOL ToolDataRef::isNameValid() {
    BOOL nameValid = true;

    if (isValid()) {
        if (strcmp(getName(), "nothing") != 0) {
            nameValid = false;
        }
    }

    return nameValid;
}

// Matches except one instruction. Also depends on the getName above to not inline.
// https://decomp.me/scratch/WT1gF
const BOOL ToolDataRef::isNameMoney() {
    BOOL nameValid = true;

    if (isValid()) {
        if (strcmp(getName(), "money") != 0) {
            nameValid = false;
        }
    }

    return nameValid;
}

s32 fn_800E8E78(ToolDataRef* param_1) {
    const char* temp = nullptr;
    if (param_1->isValid()) {
        param_1->getToolData()->getValue(param_1->getEntryIndex(), "character_name", &temp);
    }

    if (temp == nullptr) {
        return -1;
    }

    return Koga::EnTypesManager::fn_800DAB18(temp);
}
