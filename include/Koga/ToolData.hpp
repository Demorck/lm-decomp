#ifndef TOOL_DATA_H_
#define TOOL_DATA_H_

#include "dolphin/macros.h"
#include <types.h>
#include <JSystem/JORReflexible.hpp>
#include <JSystem/JGeometry/JGVec3.hpp>

// Very similar to https://github.com/doldecomp/sms/blob/main/include/MarioUtil/ToolData.hpp
// But searchItemInfo() isn't inlined here, and there are more getValue*() variants.

namespace Koga {
    class ToolData : public JORReflexible {
    public:
        ToolData();
        virtual ~ToolData();

        #define JMAP_VALUE_TYPE_LONG       0
        #define JMAP_VALUE_TYPE_STRING     1
        #define JMAP_VALUE_TYPE_FLOAT      2
        #define JMAP_VALUE_TYPE_LONG_2     3
        #define JMAP_VALUE_TYPE_SHORT      4
        #define JMAP_VALUE_TYPE_BYTE       5
        #define JMAP_VALUE_TYPE_STRING_PTR 6
        #define JMAP_VALUE_TYPE_NULL       7

        struct JMapItem {
            u32 mHash;     // 0x0
            u32 mMask;     // 0x4
            u16 mOffsData; // 0x8
            u8 mShift;     // 0xA
            u8 mType;      // 0xB
        };

        struct JMapData {
            const JMapItem *getItem(u32 i) const {
                return &mItems[i];
            }

            s32 mNumEntries;         // 0x0
            s32 mNumFields;          // 0x4
            s32 mDataOffset;         // 0x8
            u32 mEntrySize;          // 0xC
            const JMapItem mItems[]; // 0x10
        };

        inline const JMapData* getJMapData() {
            return mData;
        }

        inline void setJMapData(JMapData* pData) {
            mData = pData;
        }

        inline s32 getDataEntryNum() {
            return mData->mNumEntries;
        }

        template<typename T>
        inline T getUnsignedValue(int entryIndex, int fieldIndex) const {
            const JMapItem* pField = &mData->mItems[fieldIndex];
            const void* ptr = reinterpret_cast<const u32*>(reinterpret_cast<const u8*>(mData) + mData->mDataOffset +
                (entryIndex * mData->mEntrySize) + pField->mOffsData);
            return (*reinterpret_cast<const T*>(ptr) & pField->mMask) >> pField->mShift;
        }

        template<typename T>
        inline const T getSignedValue(int entryIndex, int fieldIndex) const {
            const void* ptr = getDataPointer(mData, &mData->mItems[fieldIndex], entryIndex, fieldIndex);
            return *reinterpret_cast<const T*>(ptr);
        }

        BOOL attach(const JMapData*);
        void reset();
        bool getValue(int, const char*, u32*) const;
        bool getValue(int, const char*, s32*) const;
        bool getValue(int, const char*, u8*) const;
        bool getValue(int, const char*, f32*) const;
        bool getValue(int, const char*, const char**) const;
        s32 searchItemInfo(const char*) const;
        s32 findEntryByValue(int, const u32, int);
        s32 findEntryByValue(int, const char*, int);

    private:
        /* 0x04 */ const JMapData* mData;

        inline u32 hashString(const char* key) const
        {
            u32 stringHash = 0;
            char current_char;

            while ((current_char = *key) != 0) {
                key++;
                stringHash = (current_char + (stringHash << 8)) % 0x1FFFFD9;
            }
            return stringHash;
        }

        inline const void* getDataPointer(const JMapData* pData, const JMapItem* pField, int entryIndex, int fieldIndex) const {
            return reinterpret_cast<const u32*>(reinterpret_cast<const u8*>(pData) + pData->mDataOffset +
                (entryIndex * pData->mEntrySize) + pField->mOffsData);
        }

        inline const bool getBoolValue(int entryIndex, int fieldIndex) const {
            const JMapItem* pField = &mData->mItems[fieldIndex];
            u32 entryOffset = entryIndex * mData->mEntrySize;
            const void* ptr = reinterpret_cast<const u32*>(reinterpret_cast<const u8*>(mData) + mData->mDataOffset +
                entryOffset + pField->mOffsData);
            return *reinterpret_cast<const u32*>(ptr) & pField->mMask;
        }

public:
        inline const char* getStringValue(int entryIndex, int fieldIndex) const {
            return reinterpret_cast<const char*>(getDataPointer(mData, &mData->mItems[fieldIndex], entryIndex, fieldIndex));
        };

        inline const f32 getFloatValue(int entryIndex, int fieldIndex) const {
            return *reinterpret_cast<const f32*>(getDataPointer(mData, &mData->mItems[fieldIndex], entryIndex, fieldIndex));
        }

        inline const u32 getExpectedUnsignedValue(int entryIndex, int fieldIndex) {
            const JMapItem* pField = mData->getItem(fieldIndex);
            const void* ptr = getDataPointer(mData, pField, entryIndex, fieldIndex);
            return (*reinterpret_cast<const u32*>(ptr) & pField->mMask) >> pField->mShift;
        }
    };
}

// Fabricated, a better name probably would be worth looking into.
// Defined in EnManager Split.
class ToolDataRef {
    public:
        inline ToolDataRef() {}
        inline ToolDataRef(Koga::ToolData* pData, s32 idx) {
            mToolData = pData;
            mEntryIndex = idx;
        }
        ToolDataRef(const ToolDataRef*);
        
        void init(Koga::ToolData* pData, s32 entryIdx) {
            FORCE_DONT_INLINE
            mToolData = pData;
            mEntryIndex = entryIdx;    
        }

        inline Koga::ToolData* getToolData() { return mToolData; }
        inline void setToolData(Koga::ToolData* pData) { mToolData = pData; }
        inline s32 getEntryIndex() { return mEntryIndex; }
        inline void setEntryIndex(s32 entryIndex) { mEntryIndex = entryIndex; }

        inline void reset() { 
            mToolData = nullptr; 
            mEntryIndex = -1;
        }
        
        inline bool isValid() const { 
            return mToolData != nullptr && mEntryIndex >= 0; 
        }
        static inline bool isValid(Koga::ToolData* pData, s32 idx) { 
            return pData != nullptr && idx >= 0; 
        }
        inline bool isSameEntry(const ToolDataRef& rOther) const {
            return mEntryIndex == rOther.mEntryIndex &&
                mToolData != nullptr && rOther.mToolData != nullptr && 
                mToolData->getJMapData() == rOther.mToolData->getJMapData();
        }

        inline const char* getStringValue(const char* field_name) {
            const char* charName = nullptr;
            if (isValid()) {
                mToolData->getValue(mEntryIndex, field_name, &charName);
            }

            return charName;
        }

        template<typename T>
        static inline bool getValue(ToolDataRef* pRef, const char* field_name, T* val) {
            Koga::ToolData* pData = pRef->mToolData;
            s32 idx = pRef->mEntryIndex;
            return isValid(pData, idx) && pData->getValue(idx, field_name, val);
        }

        inline bool checkValidString(ToolDataRef* pRef, const char* strToCmp) {
            return pRef->isValid() && strcmp(strToCmp, "nothing") != 0;
        }

    public:
        /* 0x0 */ Koga::ToolData* mToolData;
        /* 0x4 */ s32 mEntryIndex;
};

#endif
