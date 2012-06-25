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
    float scaledVolume = ofMap(volume, 0.0, 0.17, 0.0, 1.0, true) * 190.0f;
    ofCircle(200, 200, scaledVolume);
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

