#ifndef EN_ITEM_HPP
#define EN_ITEM_HPP

#include "Koga/CharacterEventObserver.hpp"
#include "Sato/EnemyStrategy.hpp"


class EnItem : public EnemyStrategy, public Koga::CharacterEventObserver {
    public:
        virtual ~EnItem();
};

#endif
