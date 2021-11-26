#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ParticleController.hpp"
#include "Particle.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class FlocksApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    void mouseUp(MouseEvent event) override;
    void mouseMove(MouseEvent event) override;
    void mouseDrag(MouseEvent event) override;

    ParticleController mParticleController = ParticleController();
    
    vec2 mMouseLoc;
    bool mIsPressed;
};

void FlocksApp::setup()
{
}

void FlocksApp::mouseMove(MouseEvent event)
{
    mMouseLoc = event.getPos();
}

void FlocksApp::mouseDrag(MouseEvent event)
{
    mouseMove(event);
}

void FlocksApp::mouseDown( MouseEvent event )
{
    mIsPressed = true;
}

void FlocksApp::mouseUp(MouseEvent event)
{
    mIsPressed = false;
}

void FlocksApp::update()
{
    if(mIsPressed) {
        mParticleController.addParticles(5, mMouseLoc);
    }
}

void FlocksApp::draw()
{
    gl::clear(Color(0, 0, 0));
    mParticleController.update();
    mParticleController.draw();
}

CINDER_APP( FlocksApp, RendererGl )
