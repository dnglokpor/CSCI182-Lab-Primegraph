#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// window setup
	ofBackground(0, 0, 0); // black background
	ofSetCircleResolution(50);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	// fill vector with primes
	fillWithPrimes();
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	// move to the center
	ofTranslate(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);

	// color seting
	ofSetColor(ofColor::yellow);

	// loop through the vector
	for(auto prime : PrimeNumbers){
		// push matrix
		ofPushMatrix();

		// rotate
		ofRotateRad(prime);

		// move to the point of drawing
		ofTranslate(0.0f, resolutionFactor * prime, 0.0f);
	
		// draw
		ofDrawCircle(0.0f, 0.0f, resolutionFactor); // a one pixel radius circle

		// pop the matrix
		ofPopMatrix();
	}
}

/// <summary>
/// fills the array with primes numbers
/// </summary>
/// <param name="myArray"></param>
void ofApp::fillWithPrimes() {
	bool isPrime = true, isLessThanRoot = true;
	int i = 0;

	// prefill the vector with the prime numbers
	PrimeNumbers.push_back(1); PrimeNumbers.push_back(2); // push 1 and 2 on it already
	// we know that 1 and 2 are prime numbers because they're the smallest integers to
	// vefify the condition.
	for (int number = 3; number <= MAX_NUMBER; number++) {
		//cheking if this number is prime:
		// while looping through the numbers we will use the prime numbers already found to
		// test each number. If they can be divided by any already found prime they're
		// not prime. Arithmetics tell us that a number is prime if it can't be divided
		// by any prime less than its square root. Thus we will stop the testing at the prime
		// which square is more than the number.

		isPrime = isLessThanRoot = true; // reinitialises each runthrough
		i = 1; // start with the 2nd element
		while (isPrime && isLessThanRoot) { // guarantees that we won't reach the last element of the array so I can skip controlling for #OutOfBounds exception
			isPrime = (number % PrimeNumbers[i]) != 0; // returns true if #number can't be divided by #PrimeNumber[i]
			isLessThanRoot = (PrimeNumbers[i] * PrimeNumbers[i]) < number;
			i++; // increment freely since we don't need that identifier for anything else
		}

		if (isPrime) { // add to the vector
			PrimeNumbers.push_back(number);
		} // else skip
	}
}

/// <summary>
/// returns a random color.
/// </summary>
/// <returns></returns>
ofColor ofApp::randomColor() {
	srand(time(NULL));

	return ofColor(rand() % 255, rand() % 255, rand() % 255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// zoom in
	if (key == ofKey::OF_KEY_UP) {
		if (resolutionFactor < 1.0f)
			resolutionFactor += 0.01f;
		else if(resolutionFactor < 50.0f)
			resolutionFactor += 1.0f;
		else if (resolutionFactor < 100.0f)
			resolutionFactor += 5.0f;
		else{}
	}
	
	// zoom out
	if (key == ofKey::OF_KEY_DOWN) {
		if (resolutionFactor > 50.0f)
			resolutionFactor -= 5.0f;
		else if (resolutionFactor > 1.0f)
			resolutionFactor -= 1.0f;
		else if (resolutionFactor > 0.1f)
			resolutionFactor -= 0.01f;
		else{}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
