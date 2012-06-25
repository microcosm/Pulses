#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "calculator.h"

class Pulses : public ofBaseApp
{

	public:
		void setup();
		void update();
		void draw();
		void stop();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
	
        void audioIn(float * input, int bufferSize, int nChannels);
    
        vector <float> channel1;
        vector <float> channel2;
    
        ofSoundStream soundStream;
        int bufferCounter;
        Calculator calculator;
    
        float volume;
};

#endif
