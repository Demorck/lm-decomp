#ifndef EN_ATTACK_BASE_H_
#define EN_ATTACK_BASE_H_

#include "Ajioka/AEnAtStructs.hpp"
#include "Koga/BaseParam.hpp"
#include "Koga/ParamInst.hpp"
#include "Koga/Params.hpp"
#include <Koga/CharacterEventObserver.hpp>
#include <Sato/EnemyStrategy.hpp>

class EnAttackBase : public EnemyStrategy, public Koga::CharacterEventObserver {
public:
    EnAttackBase() : 
        mParams("/param/th/EnAttackBase.prm"),
        mDamage(&mParams, 0, "mDamage", TBaseParam::calcKeyCode("mDamage")),
        mAttackType(&mParams, 0, "mAttackType", TBaseParam::calcKeyCode("mAttackType"))
    {
    }
    /* 0x08 */ virtual ~EnAttackBase() { };
    /* 0x70 */ virtual TParams* vt_70();

    void EnAttackBase_fn_800DDD5C();

public:
    /* 0x18 */ const AEnAtStruct2* _18;
    /* 0x1C */ s32 _1C;
    /* 0x20 */ TParams mParams;
    /* 0x2C */ TParamT<long> mDamage;
    /* 0x40 */ TParamT<short> mAttackType;
};

#endif
