#ifndef EN_ITEMS_HPP
#define EN_ITEMS_HPP
#include "Koga/CharacterEventObserver.hpp"
#include "Sato/EnemyStrategy.hpp"

class EnItem : public EnemyStrategy, public Koga::CharacterEventObserver {
public:
    EnItem();
    virtual ~EnItem();

    // From EnemyStrategy
    virtual void doBehavior(); // fn_800CFB5C
    virtual void doBehaviorInit(); // fn_800CFBC0

    // From Koga::CharacterEventObserver
    virtual bool onCaptureEnd(Koga::CharacterEvent* msg); // fn_800D04A4
    virtual bool onPlayerLeftRoom(Koga::CharacterEvent* msg); // fn_800CFC6C

    // From this class
    virtual void EnItem_fn_800CFFD8();
    virtual void EnItem_fn_800D00A8();
    virtual void EnItem_fn_800D00AC();
    virtual void EnItem_fn_800D00B0();
    virtual bool EnItem_fn_800D00B4();
};

class EnItemThrowUp : public EnItem {
public:
    EnItemThrowUp();
    virtual ~EnItemThrowUp();

    // From EnItem
    virtual void EnItem_fn_800D00A8();
    virtual void EnItem_fn_800D00AC();

    // From this class
    virtual void EnItemThrowUp_fn_800D036C();
};

class EnFiniteItem : public EnItemThrowUp {
public:
    EnFiniteItem();
    virtual ~EnFiniteItem();
};

class EnHeartItem : public EnFiniteItem {
public:
    EnHeartItem() {};
    virtual ~EnHeartItem();

    // From EnFiniteItem -> EnItemThrowUp -> EnItem -> EnemyStrategy
    virtual void init();

    // From EnFiniteItem -> EnItemThrowUp -> EnItem
    virtual void EnItem_fn_800CFFD8();
    virtual void EnItem_fn_800D00A8();
    virtual void EnItem_fn_800D00AC();
    virtual void EnItem_fn_800D00B0();
    
    // From EnFiniteItem -> EnItemThrowUp
    virtual void EnItemThrowUp_fn_800D036C();
};

class EnJewel : public EnFiniteItem {
public:
    EnJewel() {};
    virtual ~EnJewel();

    // From EnFiniteItem -> EnItemThrowUp -> EnItem
    virtual void EnItem_fn_800CFFD8();
    virtual void EnItem_fn_800D00A8();
    virtual void EnItem_fn_800D00AC();
    virtual void EnItem_fn_800D00B0();
    
    // From EnFiniteItem -> EnItemThrowUp
    virtual void EnItemThrowUp_fn_800D036C();
};

class EnPearl : public EnJewel {
public:
    EnPearl();
    virtual ~EnPearl();

    // From EnJewel -> EnFiniteItem -> EnItemThrowUp -> EnItem
    virtual void EnItem_fn_800CFFD8();
    virtual bool EnItem_fn_800D00B4();
};

class EnGold : public EnJewel {
public:
    EnGold() {};
    virtual ~EnGold();

    // From EnJewel -> EnFiniteItem -> EnItemThrowUp -> EnItem
    virtual void EnItem_fn_800CFFD8();

    // From EnJewel -> EnFiniteItem -> EnItemThrowUp
    virtual void EnItemThrowUp_fn_800D036C();
};

class EnElementJewel : public EnJewel {
public:
    EnElementJewel();
    virtual ~EnElementJewel();

    
    // From EnJewel -> EnFiniteItem -> EnItemThrowUp -> EnItem -> Koga::CharacterEventObserver
    virtual bool onCaptureEnd(Koga::CharacterEvent* msg);

    // From EnJewel -> EnFiniteItem -> EnItemThrowUp -> EnItem
    virtual void EnItem_fn_800CFFD8();
    virtual void EnItem_fn_800D00B0();

    // From EnJewel -> EnFiniteItem -> EnItemThrowUp
    virtual void EnItemThrowUp_fn_800D036C();
};

class EnCrown : public EnJewel {
public:
    EnCrown() {};
    virtual ~EnCrown();

    // From EnJewel -> EnFiniteItem -> EnItemThrowUp
    virtual void EnItemThrowUp_fn_800D036C();
};

class EnNegativeItem : public EnFiniteItem {
public:
    EnNegativeItem() {};
    virtual ~EnNegativeItem();

    // From -> EnFiniteItem -> EnItemThrowUp -> EnItem
    virtual void EnItem_fn_800CFFD8();
    virtual void EnItem_fn_800D00A8();
    virtual void EnItem_fn_800D00AC();
    virtual void EnItem_fn_800D00B0();

    // From EnFiniteItem -> EnItemThrowUp
    virtual void EnItemThrowUp_fn_800D036C();
};

#endif
