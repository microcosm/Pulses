#include "pulses.h"

void Pulses::setup()
{
    ofSetDataPathRoot("../../../../data/");
    
	int bufferSize = 256;
    bufferCounter = 0;
    
	soundStream.listDevices();
	soundStream.setDeviceID(4);
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
	
	channel1.assign(bufferSize, 0.0);
	channel2.assign(bufferSize, 0.0);
    
    calculator.setBufferSize(bufferSize);
    
    ofSetWindowShape(500, 500);
	ofSetVerticalSync(true);
    ofEnableSmoothing();   
    ofBackground(ofColor::black);
    ofSetCircleResolution(50);
}

void Pulses::audioIn(float * input, int bufferSize, int nChannels){	
	
    calculator.deinterleave(input, channel1, channel2);
	float nextVolume = calculator.getApproximateVolume(channel1, channel2);
	volume = calculator.smoothVolume(volume, nextVolume);
    
	bufferCounter++;
}

void Pulses::update()
{
    
}

void Pulses::draw()
{
    ofSetColor(ofColor::red);
    float scaledVolume = ofMap(volume, 0.0, 0.17, 0.0, 1.0, true) * 290.0f;
    ofCircle(150, 150, scaledVolume);
    ofCircle(350, 350, scaledVolume);
    ofCircle(150, 350, scaledVolume);
    ofCircle(350, 150, scaledVolume);
}

void Pulses::keyPressed(int key)
{

}

void Pulses::keyReleased(int key)
{

}

void Pulses::mouseMoved(int x, int y )
{
    
}

void Pulses::mouseDragged(int x, int y, int button)
{
    
}

void Pulses::mousePressed(int x, int y, int button)
{
    
}

void Pulses::mouseReleased(int x, int y, int button)
{
    
}

void Pulses::windowResized(int w, int h)
{

}

