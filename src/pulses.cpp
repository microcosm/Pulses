#include "pulses.h"

void Pulses::setup()
{
    ofSetDataPathRoot("../../../../data/");
    bufferCounter = 0;
}

void Pulses::audioIn(float * input, int bufferSize, int nChannels){	
	
    calculator.setBufferSize(bufferSize);
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

