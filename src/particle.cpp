#include "particle.h"

Particle::Particle(){
}

void Particle::setup(ofPoint pos, int mass, vector<ofColor> &Palette){
    Particle::mass = mass;
    
    x = pos.x;
    y = pos.y;
    z = pos.z;
    
    //cout << "Attemp at [" << x << " " << y << " " << z << "] with mass: " << mass << endl;
    
    speedX = ofRandom(-1, 1) / mass;           // and random direction and mass inverse-proportional speed
    speedY = ofRandom(-1, 1) / mass;
    speedZ = ofRandom(-1, 1) / mass;
    Particle::definePalette(Palette);
    //color = Palette[1 + ceil((Palette.size() - 2) * mass/10)];
    
    //int cf = ceil((mass/10) * 16777215);
    //color.set(ofRandom(255),ofRandom(255),ofRandom(255)); // one way of defining digital color is by addressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
}

void Particle::definePalette(vector<ofColor> &Palette){
    Particle::color = Palette[1 + ceil((Palette.size() - 2) * mass/10)];
}

void Particle::acelerate(int speedModule) {
    speedX *= speedModule;
    speedY *= speedModule;
    speedZ *= speedModule;
}

void Particle::deacelerate(int speedModule) {
    speedX /= speedModule;
    speedY /= speedModule;
    speedZ /= speedModule;
}

void Particle::update(){
    if(x < (mass + 1) ){
        x = (mass + 1);
        speedX *= -1;
    } else if(x > ofGetWidth() - (mass + 1)){
        x = ofGetWidth() - (mass + 1);
        speedX *= -1;
    }
    
    if(y < (mass + 1) ){
        y = (mass + 1);
        speedY *= -1;
    } else if(y > ofGetHeight() - (mass + 1)){
        y = ofGetHeight() - (mass + 1);
        speedY *= -1;
    }
    
    // Cambiar por estados (maquina de estados)
    x += (speedX * sin(y * PI/180));
    //x = (speedX * 10) + (yOff*2) + (100 * cos(y * PI/180)) + (100 * sin(y * PI/180));
    y += (speedY * cos(x * PI/180));
    //y = (speedY * 10) + yOff + ((100 * tan(x * PI/180))/2);
    
    
    //y = yOff + (100 * sin(x * PI/180));
    //cout << "Seno de " << x << " es " << sin(x * PI/180) << endl;
    
}

void Particle::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, mass);
}
