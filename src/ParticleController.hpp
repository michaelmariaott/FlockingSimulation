//
//  ParticleController.hpp
//  FlockingSimulation
//
//  Created by Michael Ott on 25.11.21.
//

#ifndef ParticleController_hpp
#define ParticleController_hpp

#pragma once
#include <stdio.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Particle.hpp"
#include <list>

class ParticleController {
    
public:
    ParticleController();
    void update();
    void draw();
    void addParticles(int amt, vec2 &loc);
    void removeParticles(int amount);
    std::list<Particle> mParticles;
};

#endif /* ParticleController_hpp */
