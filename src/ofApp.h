#pragma once

#include <vector>
#include <time.h>
#include "ofMain.h"

class ofApp : public ofBaseApp{
private:
	// constant
	static const int MAX_NUMBER = 50000;
	vector<int> PrimeNumbers;
	float resolutionFactor = 1.0f; // allow me to change the resolution at which I draw
	public:
		// fill given array with prime numbers
		void fillWithPrimes();
		// randomize the color
		ofColor randomColor();
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
