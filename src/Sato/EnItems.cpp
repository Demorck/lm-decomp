#include "Sato/EnItems.hpp"

#include "macros.h"

dummy_float_data()
EnItem::EnItem() {}
EnItem::~EnItem() {}


void EnItem::doBehavior() {

}

void EnItem::doBehaviorInit() {

}

bool EnItem::onCaptureEnd(Koga::CharacterEvent* msg) {
    return false;
}

bool EnItem::onPlayerLeftRoom(Koga::CharacterEvent* msg) {
    return false;
}


void EnItem::EnItem_fn_800CFFD8() {}

void EnItem::EnItem_fn_800D00A8() {}

void EnItem::EnItem_fn_800D00AC() {}

void EnItem::EnItem_fn_800D00B0() {}

bool EnItem::EnItem_fn_800D00B4() {
    return false;
}

///////////////////////////////

EnItemThrowUp::EnItemThrowUp() {}

void EnItemThrowUp::EnItem_fn_800D00A8() {

}

void EnItemThrowUp::EnItem_fn_800D00AC() {

}

void EnItemThrowUp::EnItemThrowUp_fn_800D036C() {
    
}

///////////////////////////////

EnFiniteItem::~EnFiniteItem() {}

void EnNegativeItem::EnItem_fn_800CFFD8() {}
void EnNegativeItem::EnItem_fn_800D00A8() {}
void EnNegativeItem::EnItem_fn_800D00AC() {}
void EnNegativeItem::EnItemThrowUp_fn_800D036C() {}
void EnNegativeItem::EnItem_fn_800D00B0() {}



EnFiniteItem::EnFiniteItem() {}
EnItemThrowUp::~EnItemThrowUp() {}


///////////////////////////////

void EnHeartItem::init() {}
EnHeartItem::~EnHeartItem() {}
void EnHeartItem::EnItem_fn_800CFFD8() {}
void EnHeartItem::EnItem_fn_800D00A8() {}
void EnHeartItem::EnItem_fn_800D00AC() {}
void EnHeartItem::EnItemThrowUp_fn_800D036C() {}
void EnHeartItem::EnItem_fn_800D00B0() {}


///////////////////////////////

EnJewel::~EnJewel() {}
void EnJewel::EnItem_fn_800CFFD8() {}
void EnJewel::EnItem_fn_800D00B0() {}
void EnJewel::EnItem_fn_800D00A8() {}
void EnJewel::EnItem_fn_800D00AC() {}
void EnJewel::EnItemThrowUp_fn_800D036C() {}

///////////////////////////////

EnPearl::EnPearl() {}
void EnPearl::EnItem_fn_800CFFD8() {}
bool EnPearl::EnItem_fn_800D00B4() { return true; }


void EnGold::EnItem_fn_800CFFD8() {}
void EnGold::EnItemThrowUp_fn_800D036C() {}


EnElementJewel::EnElementJewel() {}
EnElementJewel::~EnElementJewel() {}
bool EnElementJewel::onCaptureEnd(Koga::CharacterEvent* msg) { return true; }
void EnElementJewel::EnItem_fn_800CFFD8() {}
void EnElementJewel::EnItem_fn_800D00B0() {}
void EnElementJewel::EnItemThrowUp_fn_800D036C() {}


void EnCrown::EnItemThrowUp_fn_800D036C() {}


EnCrown::~EnCrown() {}
EnGold::~EnGold() {}
EnPearl::~EnPearl() {}

///////////////////////////////

EnNegativeItem::~EnNegativeItem() {}
