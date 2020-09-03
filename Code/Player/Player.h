#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Physics/Physical.h"

class Player : public Physical
{
    public:
    static const float MAX_VELOCITY;
    static const float RECTANGLE_SIZE; //We can get rid of it later when collision system is finnished
    static const float JUMP_VELOCITY;
    
    Player();

    void update(float deltaTime) override;
    void jump();

    private:
    void updateVelocity(float deltaTime) override;
    bool jumping;
};

#endif