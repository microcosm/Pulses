//
//  calculator.h
//  pulses
//
//  Created by Andrew McWilliams on 6/25/12.
//  www.jahya.net
//

#include "ofMain.h"

#ifndef pulses_calculator_h
#define pulses_calculator_h

class Calculator
{
    private:
        int bufferSize;
    
    public:
        void setBufferSize(int bufferSize);
        void deinterleave(float *buffer, vector<float> &channel1, vector<float> &channel2);
        float getApproximateVolume(vector<float> &channel1, vector<float> &channel2);
        float smoothVolume(float previousVolume, float nextVolume);
        
};

#endif