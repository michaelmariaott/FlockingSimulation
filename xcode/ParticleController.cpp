//
//  ParticleController.cpp
//  Flocks
//
//  Created by Michael Ott on 26.11.21.
//
#include "ParticleController.hpp"

ParticleController::ParticleController()
{
}

void ParticleController::addParticles(int amt, vec2 &loc) {
    for(int i = 0; i < amt; i++) {
        vec2 randOff = randVec2() * 10.0f;
        mParticles.push_back(Particle(loc + randOff));
    }
}

void ParticleController::removeParticles(int amt) {
    for(int i = 0; i < amt; ++i) {
        mParticles.pop_back();
    }
}

void ParticleController::update() {
    for(list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p) {
        if(p -> mIsDead) {
            p = mParticles.erase(p);
        }
        else {
            p -> update();
            p++;
        }
    }
}

void ParticleController::draw() {
    for(list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p) {
        p -> draw();
    }
}
