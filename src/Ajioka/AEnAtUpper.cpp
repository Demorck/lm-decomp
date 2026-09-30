#include "Ajioka/AEnAtUpper.hpp"


dummy_float_data()
enemies_float_data()

static EnemyStrategyState enemiesStates[9] = {
    {
        0, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_0_Init, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_0_Behavior
    },

    {
        1, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_1_Init, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_1_Behavior
    },

    {
        2, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_2_Init, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_2_Behavior
    },

    {
        3, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_3_Init, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_3_Behavior
    },

    {
        4, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_4_Init, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_4_Behavior
    },

    {
        5, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_5_Init, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_5_Behavior
    },

    {
        0x102, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_0x102_Init, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_0x102_Behavior
    },

    {
        0x100, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_0x100_Init, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_0x100_Behavior
    },

    {
        0x101, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_0x101_Init, 
        (EnemyStrategyStateFn)&AEnAtUpper::state_0x101_Behavior
    },
};

float data_float[] = { -10.f, 0.f, 35.f, -10.f, 0.f, -35.f };
char enAttackBasePath[] = "/param/th/EnAttackBase.prm";
char attackTypeField[] = "mAttackType";
char aEnAtUpperPath[] = "/param/th/AEnAtUpper.prm";
char kamaeru2[] = "KAMAERU2";

AEnAtUpper::AEnAtUpper() {

}

void AEnAtUpper::doBehavior() {

}

void AEnAtUpper::doBehaviorInit() {

}

bool AEnAtUpper::vt_14() {
    return true;
}

bool AEnAtUpper::state_0_Init() {
    return false;
}

bool AEnAtUpper::state_0_Behavior() {
    return true;
}

bool AEnAtUpper::state_1_Init() {
    return true;
}

bool AEnAtUpper::state_1_Behavior() {
    return false;
}

bool AEnAtUpper::state_2_Init() {
    return false;
}

bool AEnAtUpper::state_2_Behavior() {
    return false;
}

bool AEnAtUpper::state_3_Init() {
    return false;
}

bool AEnAtUpper::state_3_Behavior() {
    return false;
}

bool AEnAtUpper::state_4_Init() {
    return false;
}

bool AEnAtUpper::state_4_Behavior() {
    return false;
}

bool AEnAtUpper::state_5_Init() {
    return true;
}

bool AEnAtUpper::state_5_Behavior() {
    return false;
}

bool AEnAtUpper::state_0x102_Init() {
    return true;
}

bool AEnAtUpper::state_0x102_Behavior() {
    return true;
}

bool AEnAtUpper::state_0x100_Init() {
    return true;
}

bool AEnAtUpper::state_0x100_Behavior() {
    return true;
}

bool AEnAtUpper::state_0x101_Init() {
    return true;
}

bool AEnAtUpper::state_0x101_Behavior() {
    return true;
}


bool AEnAtUpper::onCollideWithPlayer(Koga::CharacterEvent* msg) {
    return false;
}

AEnAtUpper::~AEnAtUpper() {
    
}
