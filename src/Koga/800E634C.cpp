#include <JSystem/JGeometry/JGVec3.hpp>

#include "Sato/EnThought.hpp"
#include "Koga/800E634C.hpp"
#include "Unsorted/MoveObj.hpp"


bool fn_800E6ED0(EnThought* param_1) {
    if (!param_1->getToolDataRef().isValid()) {
        return false;
    }

    SomeStruct temp;
    temp._0 = 0;
    temp._2 = 0;
    temp._4 = 0;
    param_1->getPosition(&temp._C);
    param_1->getDirectionNormalized(&temp._0, &temp._2, &temp._4);

    JGeometry::TVec3f vec(temp._C);

    param_1->getCharacter()->fn_80067CB0(vec.x, vec.y, vec.z);
    param_1->getCharacter()->vt_0C(temp._0, temp._2, temp._4);

    return true;
}
