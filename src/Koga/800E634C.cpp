#include <JSystem/JGeometry/JGVec3.hpp>

#include "Sato/EnThought.hpp"
#include "Koga/800E634C.hpp"
#include "Unsorted/MoveObj.hpp"

bool fn_800E6ED0(EnThought* param_1) {
    ToolDataRef ref = param_1->getToolDataRef();
    if (!ref.isValid()) {
        return false;
    }

    SomeStruct temp;
    temp._0 = 0;
    temp._2 = 0;
    temp._4 = 0;
    param_1->fn_800BF8D8(&temp._8->_vec44);
    param_1->fn_800BF980(&temp._0, &temp._2, &temp._4);

    param_1->getCharacter()->fn_80067CB0(temp._8->_vec44.x, temp._8->_vec44.y, temp._8->_vec44.z);
    param_1->getCharacter()->vt_0C(temp._0, temp._2, temp._4);

    return true;
}
