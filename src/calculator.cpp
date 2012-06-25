//
//  calculator.cpp
//  pulses
//
//  Created by Andrew McWilliams on 6/25/12.
//  www.jahya.net
//

#include "calculator.h"

void Calculator::setBufferSize(int newBufferSize){ 
    bufferSize = newBufferSize;
}

void Calculator::deinterleave(float *buffer, vector<float> &channel1, vector<float> &channel2){
    
    for (int i = 0; i < bufferSize; i++){
		channel1[i]= buffer[i * 2] * 0.5;
		channel2[i] = buffer[i * 2 + 1] * 0.5;
	}
}

float Calculator::getApproximateVolume(vector<float> &channel1, vector<float> &channel2)
{
    //Method: Root mean square
    //http://en.wikipedia.org/wiki/Root_mean_square
    //"The name comes from the fact that it is the square root of the mean of the squares of the values"
    
	float volume = 0.0;
	int numSamples = channel1.size() * 2;
    
    //squares of the values
	for (int i = 0; i < channel1.size(); i++){
		volume += channel1[i] * channel1[i];
		volume += channel2[i] * channel2[i];
	}
	
	//mean
	volume /= numSamples;
	
    //square root
	volume = sqrt(volume);
    return volume;
}

float Calculator::smoothVolume(float previousVolume, float nextVolume)
{
	previousVolume *= 0.93;
	previousVolume += 0.07 * nextVolume;
    return previousVolume;
}