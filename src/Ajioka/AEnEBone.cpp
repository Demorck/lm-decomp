#include "Ajioka/AEnEBone.hpp"

dummy_float_data()
enemies_float_data()

static EnemyStrategyState enemiesStates[3] = {
    {
        0, 
        (EnemyStrategyStateFn)&AEnEBone::state_0_Init, 
        (EnemyStrategyStateFn)&AEnEBone::state_0_Behavior
    },

    {
        1, 
        (EnemyStrategyStateFn)&AEnEBone::state_1_Init, 
        (EnemyStrategyStateFn)&AEnEBone::state_1_Behavior
    },

    {
        2, 
        (EnemyStrategyStateFn)&AEnEBone::state_2_Init, 
        (EnemyStrategyStateFn)&AEnEBone::state_2_Behavior
    },
};

float pos[3] = { -3300, 100, -2800 };

void AEnEBone::doBehavior() {

}

void AEnEBone::doBehaviorInit() {

}

bool AEnEBone::state_0_Init() {
    return true;
}

bool AEnEBone::state_0_Behavior() {
    return true;
}

bool AEnEBone::state_1_Init() {
    return true;
}

bool AEnEBone::state_1_Behavior() {
    return true;
}

bool AEnEBone::state_2_Init() {
    return true;
}

bool AEnEBone::state_2_Behavior() {
    return true;
}

bool AEnEBone::onPlayerLeftRoom(Koga::CharacterEvent* msg) {
    return true;
}

AEnEBone::~AEnEBone() {
    
}
