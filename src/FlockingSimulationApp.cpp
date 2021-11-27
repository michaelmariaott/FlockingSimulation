#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "Particle.hpp"
#include "ParticleController.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class FlockingSimulationApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void keyDown(KeyEvent event) override;
    void mouseMove(MouseEvent mouseMove) override;
    void mouseDrag(MouseEvent mouseDrag) override;
    void mouseUp(MouseEvent event) override;
    
    const float mScale = 8.0f;
    ParticleController mParticleController = ParticleController();
    
    vec2 mMouseLoc;
    bool mIsPressed;
};

void FlockingSimulationApp::setup()
{

}

void FlockingSimulationApp::mouseDown( MouseEvent event )
{
    mIsPressed = true;
}

void FlockingSimulationApp::mouseUp(MouseEvent event)
{
    mIsPressed = false;
}

void FlockingSimulationApp::mouseMove(MouseEvent mouseMove)
{
    mMouseLoc = mouseMove.getPos();
}

void FlockingSimulationApp::mouseDrag(MouseEvent mouseDrag)
{
    mouseMove(mouseDrag);
}

void FlockingSimulationApp::keyDown(KeyEvent event)
{

}


void FlockingSimulationApp::update()
{
    if(mIsPressed) {
        mParticleController.addParticles(5, mMouseLoc);
    }
}

void FlockingSimulationApp::draw()
{
    gl::clear(Color(0, 0, 0));
    mParticleController.update();
    mParticleController.draw();
}

CINDER_APP( FlockingSimulationApp, RendererGl, [&]( App::Settings *settings ) {
    settings -> setWindowSize(900, 600);
    settings -> setFrameRate(60.0f);
} )

