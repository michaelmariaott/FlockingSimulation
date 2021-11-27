//
//  Particle.hpp
//  FlockingSimulation
//
//  Created by Michael Ott on 25.11.21.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace std;

class Particle {
    vec2 mLoc;
    vec2 mDir;
    vec2 mDirToMouse;
    vec2 mVel;
    float mRadius;
    Color mColor;
    int mAge;
    int mLifespan;
    
    
public:
    Particle(vec2 location);
    void update();
    void draw();
    bool mIsDead;
};

#endif /* Particle_hpp */
