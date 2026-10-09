#ifndef ACTORLIST_HPP
#define ACTORLIST_HPP

// Starting at 0x8033B590 is an Actor Object List. The list contains elements up to 24 bytes long,
// broken down by the ActorData class. Actor Data global list ends at 0x8033DF40

#include <types.h>
#include <JSystem/JUtility/JUTColor.hpp>

struct unkActorData1 { //Might be a class, would need to dig further.
    u32 _0; //Potentially fabricated, but based on lwz instructions
    u32 _4;
    u32 _8;
    u32 _C;
    u32 _10;
};

class ActorData {
    public:
        /* 0x0 */ int _0;
        /* 0x4 */ u32 _4;
        /* 0x8 */ u32 _8;
        /* 0xC */ unkActorData1* _C;
        /* 0x10 */ unkActorData1* _10; // Could be the same as the above.
        /* 0x14 */ u16 _14;
        /* 0x16 */ u16 _16; // padding?
        /* 0x18 */ char* mActorName;
 
        // This might make more sense in a Util class, unsure at this time without digging more.
        static u32 fn_8006A354(s32);
        static u16 fn_8006A36C(s32);
        static JUtility::TColor fn_8006A384(s32);
        static char* getActorName(s32);
};

ActorData* lbl_8038E118; //Some Pointer to some ActorData, possibly pointers to what slot the Actor is loaded into?
ActorData* lbl_8038DD00; //Some array pointer to some actor part or something similar?

#endif
