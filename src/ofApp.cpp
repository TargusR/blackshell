#include "ofApp.h"

#define RECONNECT_TIME 400

void ofApp::paletteSelector(int paletteN){
    ofColor newColor;
    Palette.clear();
    sizePalette = 0;
    vector <ofColor> voidPalette;
    Palette = voidPalette;
    switch (paletteN) {
        case 1:
            // Cheer Up Emo Kid
            PaletteName = "Cheer Up Emo Kid";
            newColor.set(85,98,112);
            Palette.push_back(newColor);
            newColor.set(78,205,196);
            Palette.push_back(newColor);
            newColor.set(199,244,100);
            Palette.push_back(newColor);
            newColor.set(255,107,107);
            Palette.push_back(newColor);
            newColor.set(196,77,88);
            Palette.push_back(newColor);
            break;
            
        case 2:
            // Ocean Five
            PaletteName = "Ocean Five";
            newColor.set(0,160,176);
            Palette.push_back(newColor);
            newColor.set(106,74,60);
            Palette.push_back(newColor);
            newColor.set(204,51,63);
            Palette.push_back(newColor);
            newColor.set(235,104,65);
            Palette.push_back(newColor);
            newColor.set(237,201,81);
            Palette.push_back(newColor);
            break;
            
        case 3:
            // Tought Provoking
            PaletteName = "Tought Provoking";
            newColor.set(236,208,120);
            Palette.push_back(newColor);
            newColor.set(217,91,67);
            Palette.push_back(newColor);
            newColor.set(192,41,66);
            Palette.push_back(newColor);
            newColor.set(84,36,55);
            Palette.push_back(newColor);
            newColor.set(83,119,122);
            Palette.push_back(newColor);
            break;
            
        case 4:
            // Dream Magnet
            PaletteName = "Dream Magnet";
            newColor.set(52,56,56);
            Palette.push_back(newColor);
            newColor.set(0,95,107);
            Palette.push_back(newColor);
            newColor.set(0,140,158);
            Palette.push_back(newColor);
            newColor.set(0,180,204);
            Palette.push_back(newColor);
            newColor.set(0,223,252);
            Palette.push_back(newColor);
            break;
            
        case 5:
            // Undecided
            PaletteName = "Undecided";
            newColor.set(218,214,202);
            Palette.push_back(newColor);
            newColor.set(27,176,206);
            Palette.push_back(newColor);
            newColor.set(79,134,153);
            Palette.push_back(newColor);
            newColor.set(106,94,114);
            Palette.push_back(newColor);
            newColor.set(86,52,68);
            Palette.push_back(newColor);
            break;
            
        case 6:
            // All in all
            PaletteName = "All in all";
            newColor.set(254,249,240);
            Palette.push_back(newColor);
            newColor.set(174,232,251);
            Palette.push_back(newColor);
            newColor.set(0,188,209);
            Palette.push_back(newColor);
            newColor.set(176,248,255);
            Palette.push_back(newColor);
            newColor.set(118,211,222);
            Palette.push_back(newColor);
            break;
            
        case 7:
            // Sailboat
            PaletteName = "Sailboat";
            newColor.set(226,88,88);
            Palette.push_back(newColor);
            newColor.set(233,214,175);
            Palette.push_back(newColor);
            newColor.set(255,255,221);
            Palette.push_back(newColor);
            newColor.set(192,239,210);
            Palette.push_back(newColor);
            newColor.set(56,66,82);
            Palette.push_back(newColor);
            break;
            
        case 8:
            // Invisible Look
            PaletteName = "Invisible Look";
            newColor.set(2,157,175);
            Palette.push_back(newColor);
            newColor.set(229,213,153);
            Palette.push_back(newColor);
            newColor.set(255,194,25);
            Palette.push_back(newColor);
            newColor.set(240,124,25);
            Palette.push_back(newColor);
            newColor.set(227,37,81);
            Palette.push_back(newColor);
            break;
            
        case 9:
            // Last Night
            PaletteName = "Last Night";
            newColor.set(204,38,73);
            Palette.push_back(newColor);
            newColor.set(153,44,75);
            Palette.push_back(newColor);
            newColor.set(102,50,76);
            Palette.push_back(newColor);
            newColor.set(51,56,78);
            Palette.push_back(newColor);
            newColor.set(0,62,79);
            Palette.push_back(newColor);
            break;
            
        case 10:
            // High Contrast
            PaletteName = "High Contrast";
            newColor.set(24,24,24);
            Palette.push_back(newColor);
            newColor.set(224,224,224);
            Palette.push_back(newColor);
            newColor.set(232,232,232);
            Palette.push_back(newColor);
            newColor.set(240,240,240);
            Palette.push_back(newColor);
            newColor.set(248,248,248);
            Palette.push_back(newColor);
            break;
            
        default:
        {
            int nRandomPalette = 10;
            while(nRandomPalette > 0) {
                newColor.set(ceil(ofRandom(0,255)),ceil(ofRandom(0,255)),ceil(ofRandom(0,255)));
                Palette.push_back(newColor);
                nRandomPalette--;
            }
        }
            PaletteName = "Poison Active!!";
            break;
    }
    sizePalette = Palette.size();
}

//--------------------------------------------------------------
void ofApp::setup(){
    // Aplication setup
    window.set(ofGetWidth(), ofGetHeight());
    ofSetFrameRate(60);
    generatePos.set(0,0,0);
    
    // Time
    secondStart = ceil(ofGetSystemTimeMicros() / 1000000);

    #define PALETTE 10
    // Define Palette
    ofApp::paletteSelector(PALETTE);
    //int paletteSelector = ceil(ofRandom(11));
    
    
    ofBackground(Palette[0].r, Palette[0].g, Palette[0].b);
    //ofBackground(0,0,0);
    
    // Inicializar consola
    ofColor textColor = (Palette.back().r,
                         Palette.back().g,
                         Palette.back().b);
    console.setup(0, 20, textColor);
    //console.log("Lista para trabajar");
    
    //sizeBalls = 8000;
    //for(int i = 0; i < sizeBalls; i++){
    //Particle newParticle;
    //float factor = (float)i/(float)sizeBalls;
    //newBall.setup(ceil(6 * factor), 100 + ceil(300 * factor));
    //Balls.push_back(newBall);
    //}
    
    // our send and recieve strings
    msgTx	= "";
    msgRx	= "";
    
    // connect to the server - if this fails or disconnects
    // we'll check every few seconds to see if the server exists
    tcpClient.setup("127.0.0.1", 1337);
    
    // optionally set the delimiter to something else.  The delimiter in the client and the server have to be the same
    tcpClient.setMessageDelimiter("\r\n");
    
    connectTime = 0;
    deltaTime = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    //Actualizar particulas
    for(int i = 0; i < sizeParticles; i++){
        Particles[i].update();
    }
    
    // Time calculation - Seconds
    int actualSeconds = ceil(ofGetSystemTimeMicros() / 1000000);
    if( actualSeconds - secondStart > 0) {
        if(secondState) secondState = false;
        else secondState = true;
        secondStart = actualSeconds;
    }
    
    if(deleteStepper) {
        // Borrar una particula por segundo
        if(sizeParticles <= 0) {
            deleteStepper = false;
        }
        else if(yetDeleted != secondState){
            yetDeleted = secondState;
            Particles.pop_back();
            sizeParticles--;
        }
    }
    
    if(tcpClient.isConnected()){
        // we are connected - lets try to receive from the server
        cout << "TCP esta conectado" << endl;
        string str = tcpClient.receive();
        if( str.length() > 0 ){
            msgRx = str;
            cout << "Obtuvimos algo." << endl;
            cout << msgRx << endl;
        }
    }else{
        cout << "TCP esta desconectado" << endl;
        msgTx = "";
        // if we are not connected lets try and reconnect every 5 seconds
        deltaTime = ofGetElapsedTimeMillis() - connectTime;
        
        if( deltaTime > 5000 ){
            tcpClient.setup("127.0.0.1", 1337);
            connectTime = ofGetElapsedTimeMillis();
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < sizeParticles; i++){
        // Interconexion
        if(boundToNext){
            if(i < sizeParticles -1) ofDrawLine(Particles[i].x,Particles[i].y,Particles[i+1].x,Particles[i+1].y);
            else ofDrawLine(Particles[i].x,Particles[i].y,Particles[0].x,Particles[0].y);
        }
        
        // Single particle
        Particles[i].draw();
        
        // La primera con todas
        if(i > 0 && boundToFirst) {
         ofSetColor(Particles[i].color);
         ofDrawLine(Particles[i].x,Particles[i].y,Particles[0].x,Particles[0].y);
         Particles[i].draw();
        }

        // Todas con la ultima
        if(i < sizeParticles-1 && boundToLast) {
         ofDrawLine(Particles[i].x,Particles[i].y,Particles[sizeParticles-1].x,Particles[sizeParticles-1].y);
         Particles[i].draw();
        }
    }
    // La primera con todas (anexo)
    if(sizeParticles > 0 && boundToFirst) Particles[0].draw();
    // Todas con la ultima (anexo)
    if(sizeParticles > 0 && boundToLast) Particles[sizeParticles-1].draw();
    
    if(console.show) {
        console.showPointer = secondState;
        console.print();
    }
    
}

//--------------------------------------------------------------
void ofApp::execute(string command){
    
    if(command == "")
        return false;
    
    smartString scommand;
    scommand.setup(command);
    
    /* :: Cerrar Programa :: */ {
        string ref[] = {"exit","close this","cierra esto","apaga esto","vamonos","apagalo","log out","logout"};
        if(scommand.compareSentences(ref))
            ofExit();
    }
    
    /* :: Saludo :: */ {
        string ref[] = {"hola","hi","hello","gretings"};
        if(scommand.compareSentences(ref)){
            console.log(" Hi Human");
            return true;
        }
    }
    
    /* :: url get :: */ {
        string ref[] = {"get from"};
        if(scommand.compareSentences(ref)){
            if(scommand.params.front() != "") {
                //console.log(" ok, go check debugger console");
                
                //char* url = scommand.params.front();
                string url = scommand.addHttp(scommand.params.front());
                
                //ofHttpResponse httpContent = ofLoadURL(url);
                
                //scommand.params.front() = "&" + scommand.params.front() + "&";
                //cout << url << endl;
                
                //ofHttpResponse resp = ofLoadURL("http://127.0.0.1");
                //ofHttpResponse resp = ofLoadURL("http://local.test.com/json_feeds/");
                //cout << httpContent.data << endl;
                if(result.open(url)) {
                    console.log(" I got it!");
                    if(result.isMember("error")){
                        Json::Value& error_s = result["error"]["def"];
                        Json::Value& error_c = result["error"]["code"];
                        console.log(" ERROR " + ofToString(error_c) + ": " + ofToString(error_s));
                    }
                    else if(result.isMember("clusters")) {
                        Json::Value& cluster_size = result["clusters"]["size"];
                        Json::Value& cluster_x = result["clusters"]["position_x"];
                        Json::Value& cluster_y = result["clusters"]["position_y"];
                        // to int
                        int nParticles = stoi(ofToString(cluster_size));
                        int x = stoi(ofToString(cluster_x));
                        int y = stoi(ofToString(cluster_y));
                        // generate
                        while(nParticles){
                            generatePos.set(x,y);
                            Particle newParticle;
                            newParticle.setup(generatePos, ceil(ofRandom(0, 10)), Palette);
                            Particles.push_back(newParticle);
                            sizeParticles++;
                            nParticles--;
                        }
                    }
                } else {
                    console.log(" I got nothing...");
                    return false;
                }
            } else
                console.log(" You didn't tell me from where");
            return true;
        }
    }
    
    /* :: Limpieza de consola :: */ {
        string ref[] = {"clear","clear the console","limpia","limpia la consola"};
        if(scommand.compareSentences(ref)){
            console.clear();
            return true;
        }
    }
    
    /* :: Ocultar Consola :: */ {
        string ref[] = {"hide","escondete","huye"};
        if(scommand.compareSentences(ref)){
            console.show = false;
            return true;
        }
    }
    
    /* :: Quien eres :: */ {
        string ref[] = {"who are you?","quien eres?"};
        if(scommand.compareSentences(ref)){
            console.log(" The System");
            return true;
        }
    }
    
    /* :: Quienes son ellos :: */ {
        string ref[] = {"who are they?","who are them?","quienes son ellos?","quienes son?"};
        if(scommand.compareSentences(ref)){
            if (sizeParticles < 1)
                console.log(" Who?");
            else
                console.log(" Oh, those are trivial beings");
            return true;
        }
    }
    
    /* :: Dime el color :: */ {
        string ref[] = {"que color esta activo?","dime el color","nombra la paleta de colores","tell me the color","name color palette"};
        if(scommand.compareSentences(ref)){
            console.log(" Color Palette is: " + PaletteName);
            return true;
        }
    }
    
    /* :: Crea una particula :: */ {
        string ref[] = {"create a particle","create particle","make one"};
        if(scommand.compareSentences(ref)){
            console.log(" Here you go...");
            int x = 0, y = 0;
            if(scommand.params.size() < 2) {
                if(scommand.params.size() > 0)
                    console.log(" ...but watchout those parameters");
                x = ofRandom(0, window.x);
                y = ofRandom(0, window.y);
            }
            else {
                x = stoi(scommand.params.front());
                scommand.params.pop_front();
                y = stoi(scommand.params.front());
            }
            generatePos.set(x,y);
            Particle newParticle;
            newParticle.setup(generatePos, ceil(ofRandom(0, 10)), Palette);
            Particles.push_back(newParticle);
            sizeParticles++;
            return true;
        }
    }
    
    /* :: Crea una mont—n de particulas :: */ {
        string ref[] = {"create a bunch","generate particles","make a lot"};
        if(scommand.compareSentences(ref)){
            console.log(" Here we go...");
            int x = 0, y = 0, nParticles = 0;
            if(scommand.params.size() < 3) {
                if(scommand.params.size() > 0)
                    console.log(" ...but watchout those parameters");
                x = ofRandom(0, window.x);
                y = ofRandom(0, window.y);
                nParticles = ofRandom(1, 1000);
            }
            else {
                nParticles = stoi(scommand.params.front());
                scommand.params.pop_front();
                x = stoi(scommand.params.front());
                scommand.params.pop_front();
                y = stoi(scommand.params.front());
            }
            if(nParticles > 1000)
                console.log(" God help us...");
            while(nParticles){
                generatePos.set(x,y);
                Particle newParticle;
                newParticle.setup(generatePos, ceil(ofRandom(0, 10)), Palette);
                Particles.push_back(newParticle);
                sizeParticles++;
                nParticles--;
            }
            return true;
        }
    }
    
    /* :: Acelerar :: */ {
        string ref[] = {"acelerate"};
        if(scommand.compareSentences(ref)){
            int nParticles = sizeParticles;
            if(scommand.params.size() > 1) {
                int newSpeedM = stoi(scommand.params.front());
                if(newSpeedM < 0) newSpeedM = 0;
                while(nParticles){
                    Particles[nParticles-1].acelerate(newSpeedM);
                    nParticles--;
                }
            } else {
                while(nParticles){
                    Particles[nParticles-1].acelerate();
                    nParticles--;
                }
            }
            return true;
        }
    }

    /* :: Desacelerar :: */ {
        string ref[] = {"deacelerate"};
        if(scommand.compareSentences(ref)){
            int nParticles = sizeParticles;
            if(scommand.params.size() > 1) {
                int newSpeedM = stoi(scommand.params.front());
                if(newSpeedM < 1) newSpeedM = 1;
                while(nParticles){
                    Particles[nParticles-1].deacelerate(newSpeedM);
                    nParticles--;
                }
            } else {
                while(nParticles){
                    Particles[nParticles-1].deacelerate();
                    nParticles--;
                }
            }
            return true;
        }
    }

    /* :: Mostrar todas las Uniones :: */ {
        string ref[] = {"show all bounds"};
        if(scommand.compareSentences(ref)){
            console.log(" Are you sure you want this?");
            boundToFirst = true;
            boundToLast = true;
            boundToNext = true;
            return true;
        }
    }
    
    /* :: Mostrar todas las Uniones :: */ {
        string ref[] = {"hide all bounds"};
        if(scommand.compareSentences(ref)){
            console.log(" let's see them bare naked...");
            boundToFirst = false;
            boundToLast = false;
            boundToNext = false;
            return true;
        }
    }
    
    /* :: Mostrar la primera con todas :: */ {
        string ref[] = {"show all to first","show bound to first","connect all to first"};
        if(scommand.compareSentences(ref)){
            console.log(" Now them look like a sea creature");
            boundToFirst = true;
            return true;
        }
    }
    
    /* :: Cambia Color :: */ {
        string ref[] = {"change color to", "change color", "change palette"};
        if(scommand.compareSentences(ref)){
            if(scommand.params.size() > 0) {
                int nPalette = stoi(scommand.params.front());
                ofApp::paletteSelector(nPalette);
                console.log(" Ok, changed to: " + PaletteName);
                int nParticles = sizeParticles;
                while(nParticles){
                    Particles[nParticles-1].definePalette(Palette);
                    nParticles--;
                }
                ofBackground(Palette[0].r, Palette[0].g, Palette[0].b);
                ofColor textColor = (Palette.back().r,
                                     Palette.back().g,
                                     Palette.back().b);
                console.recolor(textColor);
                return true;
            }
            else console.log(" You need a number for that...");
        }
    }
    
    /* :: Cuenta particulas :: */ {
        string ref[] = {"cuantas hay?","how many?"};
        if(scommand.compareSentences(ref)){
            if(sizeParticles == 1)
                console.log(" Only an alone spark...");
            else if(sizeParticles > 0)
                console.log(" There are " + ofToString(sizeParticles) + " living in here");
            else
                console.log(" How many what?");
            return true;
        }
    }
    
    /* :: Kill them all :: */ {
        string ref[] = {"kill them all!","kill them all","kill everyone","nuke them","caput"};
        if(scommand.compareSentences(ref)){
            console.log(" It will be no pain...");
            Particles.clear();
            sizeParticles = 0;
            vector <Particle> voidParticles;
            Particles = voidParticles;
            return true;
        }
    }
    
    /* :: Kill them one by one :: */ {
        string ref[] = {"kill them one by one!","kill them one by one","kill one by one"};
        if(scommand.compareSentences(ref)){
            console.log(" You'll see them fade...");
            deleteStepper = true;
            return true;
        }
    }
    
    /* :: Limpieza absoluta :: */ {
        string ref[] = {"clear everything","clean universe","limpia todo","limpieza total"};
        if(scommand.compareSentences(ref)){
            console.clear();
            Particles.clear();
            sizeParticles = 0;
            vector <Particle> voidParticles;
            Particles = voidParticles;
            return true;
        }
    }
    
    // Ninguna coincidencia
    console.log(" I can't Understand...");
    return false;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //cout << key << endl;
    console.show = true;
    execute(console.update(key));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    generatePos.set(x,y);
    Particle newParticle;
    newParticle.setup(generatePos, ceil(ofRandom(0, 10)), Palette);
    Particles.push_back(newParticle);
    sizeParticles++;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    generatePos.set(x,y);
    Particle newParticle;
    newParticle.setup(generatePos, ceil(ofRandom(0, 10)), Palette);
    Particles.push_back(newParticle);
    sizeParticles++;
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
    //cam.setup(w, h);
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
