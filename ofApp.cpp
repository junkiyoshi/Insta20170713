#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofEnableDepthTest();
	ofSetWindowTitle("Insta");
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);

	this->font_size = 24;
	this->font_span = ofGetWidth() / this->font_size;

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", this->font_size);
	this->moji = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();

	float noise_value;

	ofRotateY(ofGetFrameNum() % 360);

	for (int x = -ofGetWidth() / 2 + font_span / 2; x < ofGetWidth() / 2 + this->font_span / 2; x += this->font_span) {
		for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += this->font_span) {

			noise_value = ofMap(ofNoise(x * 0.0005, y * 0.0005, ofGetWidth() / 2 * 0.0005, ofGetFrameNum() * 0.0025), 0, 1, 0, 25);
			ofPushMatrix();
			ofTranslate(ofVec3f(x, y, ofGetWidth() / 2));

			ofSetColor(255);
			this->font.drawString(this->moji.substr(noise_value, 1), 0, 0);

			ofPopMatrix();

			noise_value = ofMap(ofNoise(x * 0.0005, y * 0.0005, -ofGetWidth() / 2 * 0.0005, ofGetFrameNum() * 0.0025), 0, 1, 0, 25);
			ofPushMatrix();
			ofTranslate(ofVec3f(x, y, -ofGetWidth() / 2));
			ofRotateY(180);

			ofSetColor(255);
			this->font.drawString(this->moji.substr(noise_value, 1), 0, 0);

			ofPopMatrix();
		}
	}

	for (int z = -ofGetWidth() / 2 + this->font_span / 2; z < ofGetWidth() / 2 + this->font_span / 2; z += this->font_span) {
		for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += this->font_span) {

			noise_value = ofMap(ofNoise(ofGetWidth() / 2 * 0.0005, y * 0.0005, z * 0.0005, ofGetFrameNum() * 0.0025), 0, 1, 0, 25);
			ofPushMatrix();
			ofTranslate(ofVec3f(ofGetWidth() / 2, y, z));
			ofRotateY(90);

			ofSetColor(255);
			this->font.drawString(this->moji.substr(noise_value, 1), 0, 0);
			
			ofPopMatrix();

			noise_value = ofMap(ofNoise(-ofGetWidth() / 2 * 0.0005, y * 0.0005, z * 0.0005, ofGetFrameNum() * 0.0025), 0, 1, 0, 25);
			ofPushMatrix();
			ofTranslate(ofVec3f(-ofGetWidth() / 2, y, z));
			ofRotateY(90 + 180);

			ofSetColor(255);
			this->font.drawString(this->moji.substr(noise_value, 1), 0, 0);

			ofPopMatrix();
		}
	}
	

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
