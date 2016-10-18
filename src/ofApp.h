#pragma once

#include "ofMain.h"
#include "particle.h"
#include "wconsole.h"
#include "smartString.h"
// ALIAS BLACKSHELL

// json parser
#include "ofxJSON.h"

#include <vector>

class ofApp : public ofBaseApp{
    
public:
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
    
    // Command Launcher
    void execute(string command);
    
    // Window calculation
    ofPoint origen, window;
    
    // Time Perception
    int secondStart = 0;
    bool secondState = false;
    
    // Particle
    vector<Particle> Particles;
    int sizeParticles = 0;
    
    // Palettes and colors
    vector<ofColor> Palette;
    string PaletteName;
    int sizePalette = 0;
    void paletteSelector(int paletteN);
    
    // Visuals
    bool boundToFirst = false;
    bool boundToLast = false;
    bool boundToNext = false;
    
    // Mouse Tracking
    bool generate = false;
    ofPoint generatePos;
    
    // Keyboard Interaction
    /*
    string command = "";
    int commandOffset = 0;
    vector<string> consoleBuff;
    bool consoleShow = true;
    */
    
    // Console
    wConsole console;
    
    // json object
    ofxJSONElement result;
    
    // Killing
    bool deleteStepper = false;
    bool yetDeleted = false;
};
