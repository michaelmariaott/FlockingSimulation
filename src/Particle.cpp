//
//  Particle.cpp
//  Flocks
//
//  Created by Michael Ott on 26.11.21.
//

#include "Particle.hpp"
Particle::Particle(vec2 loc) {
    mLoc = loc;
    mVel = randVec2();
    mRadius = 5.0f;
    mAge = 0;
    mLifespan = 2000;
    mIsDead = false;
}

void Particle::update() {
    mAge++;
    if(mAge > mLifespan) {
        mIsDead = true;
    }
    mLoc += mVel;
}

void Particle::draw() {
    gl::drawSolidCircle(mLoc, mRadius);
}
