//
//  wconsole.h
//  particles3_0
//
//  Created by Josué Saul Martín Hernández on 10/7/16.
//
//

#ifndef _WCONSOLE
#define _WCONSOLE
#include "ofMain.h"

#include <vector>

class wConsole {
public:
    #define LINEHEIGHT 16
    #define MAXCONSOLESSIZE 18
    #define LINEPADDING 10
    #define MAXSENTENCEHIST 20
    
    bool show = true;
    bool showPointer = true;
    
    int positionX, positionY;
    
    int lineHeight;
    int lineActive = 0;
    int maxLines;
    
    ofColor textColor;
    
    void setup(int positionX = 0, int positionY = 0, ofColor color = (255,255,255), int lineHeight = LINEHEIGHT, int maxLines = MAXCONSOLESSIZE);
    void print(); // imprime el buffer de la consola y la sentencia actual
    void log(string newLine); // añade una linea al buffer de la consola
    string update(int key); // procesa un caracter ingresado
    void check(); // revisa y corrige si el buffer de la consola se desborda de su máximo de lineas
    void clear(); // Borra el buffer de la consola
    void recolor(ofColor color = (255,255,255));
    
private:
    string sentence = "";
    int sentenceOffset = 0;
    vector<string> sentenceHist;
    int sentenceHistIndex = 1;
    vector<string> consoleBuffer;
    
    void sentenceRemember(string sentence);
};

#endif
