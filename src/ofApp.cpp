#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sound.load("sound.mp3");
    sound.play();
    
    gui.setup();
    gui.add(volume.set("volume", 0.5, 0.0, 1.0));
    gui.add(decay.set("decay", 0.5, 0.0, 1.0));
    
    fft = new float[128];
    for(int i = 0; i < 128; i++){
        fft[i] = 0;
    }
    bands = 64;
    
    for (int i = 0; i < 4; i++){
        rectangleCoordinates[i][0] = ofRandom(0, ofGetWidth() - 100);
        rectangleCoordinates[i][1] = ofRandom(0, ofGetHeight() - 100);
        rectangleCoordinates[i][2] = ofRandom(200, 800);
        rectangleCoordinates[i][3] = ofRandom(200, 800);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    
    sound.setVolume(volume);
    
    soundSpectrum = ofSoundGetSpectrum(bands);
    for(int i = 0; i < bands; i++){
        fft[i] *= decay;
        if (fft[i] < soundSpectrum[i]){
            fft[i] = soundSpectrum[i];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float noise = ofNoise(ofGetElapsedTimef());
    float randomHeight = ofRandom(0, ofGetHeight());
    float randomWidth = ofRandom(0, ofGetWidth());
    
    float sin_time = sin(ofGetElapsedTimef());
    float cos_time = cos(ofGetElapsedTimef());
    int circleAngle = 0;
    
    for (int i = 0; i < bands; i++) {
        
        //ofDrawRectangle(400 + fft[i] * 200, 120 + fft[i] * 200, 128 * noise, 300 * noise, fft[i] * 500);
        for(int j = 0; j < 4; j++){
            ofDrawRectangle((rectangleCoordinates[j][0] + (fft[i] * 50)), rectangleCoordinates[j][1], rectangleCoordinates[j][2] * fft[i] * noise, rectangleCoordinates[j][3] * fft[i]);
        }
        ofDrawCircle(ofGetWidth() / 2 + cos_time * 400, ofGetHeight() / 2 + sin_time * 200, fft[i] * 300);
        ofDrawCircle(ofGetWidth() / 3 + cos_time * 200, ofGetHeight() / 3 + sin_time * 300, fft[i] * 150);
        
    }
    for (int k = 0; k < bands; k+= 15){
        ofDrawCircle(randomWidth, randomHeight, fft[k] * 150);
    }
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
