//
//  wconsole.cpp
//  particles3_0
//
//  Created by Josué Saul Martín Hernández on 10/7/16.
//
//

#include "wconsole.h"

//--------------------------------------------------------------
void wConsole::setup(int positionX, int positionY, ofColor color, int lineHeight, int maxLines) {
    wConsole::positionX = positionX;
    wConsole::positionY = positionY;
    wConsole::textColor = color;
    wConsole::lineHeight = lineHeight;
    wConsole::maxLines = maxLines;
}

//--------------------------------------------------------------
void wConsole::recolor(ofColor color) {
    wConsole::textColor = color;
}

//--------------------------------------------------------------
void wConsole::print() {
    ofSetColor(wConsole::textColor);
    
    for(int i = 0; i < wConsole::consoleBuffer.size(); i++) {
        ofDrawBitmapString(wConsole::consoleBuffer[i],
                           wConsole::positionX + LINEPADDING,
                           wConsole::positionY + (wConsole::lineActive * wConsole::lineHeight)
                           );
        wConsole::lineActive++;
    }
    
    // Línea activa
    ofDrawBitmapString(wConsole::sentence,
                       wConsole::positionX + LINEPADDING,
                       wConsole::positionY + (wConsole::lineActive * wConsole::lineHeight)
                       );
    if(wConsole::showPointer) {
        int sentenceDifference = wConsole::sentence.length() - wConsole::sentenceOffset;
        ofDrawBitmapString("|",
                           wConsole::positionX + (LINEPADDING * 0.8) + (8 * sentenceDifference),
                           wConsole::positionY + (wConsole::lineActive * wConsole::lineHeight)
                           );
    }
    
    wConsole::lineActive = 0;
}

//--------------------------------------------------------------
void wConsole::log(string newLine) {
    wConsole::consoleBuffer.push_back(newLine);
}

//--------------------------------------------------------------
string wConsole::update(int key) {
    //cout<< key << endl;
    switch(key) {
        case 13: // Enter
            if(wConsole::sentence.size() > 0) {
                wConsole::log(wConsole::sentence);
                string returnSentence = wConsole::sentence;
                wConsole::sentenceRemember(wConsole::sentence);
                wConsole::sentence = "";
                wConsole::sentenceOffset = 0;
                wConsole::check();
                return returnSentence;
            }
            break;
            
        case 127: // Backspace / Delete
            {
                int sentenceDiff = wConsole::sentence.length() - wConsole::sentenceOffset;
                if(sentenceDiff > 0)
                    wConsole::sentence = wConsole::sentence.substr(0, sentenceDiff - 1) + wConsole::sentence.substr(sentenceDiff, wConsole::sentenceOffset);
                else if(wConsole::sentence.length() > 0) {
                    wConsole::sentenceOffset--;
                    sentenceDiff = wConsole::sentence.length() - wConsole::sentenceOffset;
                    wConsole::sentence = wConsole::sentence.substr(0, sentenceDiff - 1) + wConsole::sentence.substr(sentenceDiff, wConsole::sentenceOffset);
                }
            }
            break;
            
        case 356: // Backwards
            if(wConsole::sentenceOffset < wConsole::sentence.length())
                wConsole::sentenceOffset++;
            else
                wConsole::sentenceOffset = wConsole::sentence.length();
            break;
        case 358: // Forwards
            if(wConsole::sentenceOffset > 0)
                wConsole::sentenceOffset--;
            break;
            
        case 357: // arrow up
            if(wConsole::sentenceHist.size() > 0) {
                wConsole::sentence = wConsole::sentenceHist[wConsole::sentenceHist.size() - wConsole::sentenceHistIndex];
                if(wConsole::sentenceHistIndex < wConsole::sentenceHist.size())
                    wConsole::sentenceHistIndex++;
            }
            //cout << wConsole::sentenceHistIndex << endl;
            break;
        case 359: // arrow down
            if(wConsole::sentenceHistIndex == 1)
                wConsole::sentence = "";
            else {
                wConsole::sentenceHistIndex--;
                wConsole::sentence = wConsole::sentenceHist[wConsole::sentenceHist.size() - wConsole::sentenceHistIndex];
            }
            //cout << wConsole::sentenceHistIndex << endl;
            break;
            
            
        case -1: // MAYUS, FN & Others (Caused By, Eq to NULL)
        case 0: // NULL
        case 1: // SOH
        case 9: // TAB
        case 768: // CTRL
        case 769: // CTRL indicador de tecla izquierda(?)
        case 1280: // ALT
        case 1281: // ALT indicador de tecla izquierda
        case 1282: // ALT indicador de tecla derecha
        case 2304: // Shift
        case 2305: // Shift indicador de tecla izquierda
        case 2306: // Shift indicador de tecla derecha
        case 4352: // CMD
        case 4353: // CMD indicador de tecla izquierda
        case 4354: // CMD indicador de tecla derecha
            // do nothing;
            break;
            
        default:
            // capture key
            if (wConsole::sentenceOffset > 0) {
                int sentenceDiff = wConsole::sentence.length() - wConsole::sentenceOffset;
                wConsole::sentence = wConsole::sentence.substr(0, sentenceDiff) + (char)key + wConsole::sentence.substr(sentenceDiff, wConsole::sentenceOffset);
            } else
                wConsole::sentence = wConsole::sentence + (char)key;
    }
    return "";
}

//--------------------------------------------------------------
void wConsole::sentenceRemember(string sentence) {
    wConsole::sentenceHist.push_back(sentence);
    if(wConsole::sentenceHist.size() > MAXSENTENCEHIST)
        wConsole::sentenceHist.erase(wConsole::sentenceHist.begin());
}

//--------------------------------------------------------------
void wConsole::check() {
    while(wConsole::consoleBuffer.size() > wConsole::maxLines)
        wConsole::consoleBuffer.erase(wConsole::consoleBuffer.begin());
}

//--------------------------------------------------------------
void wConsole::clear() {
    wConsole::consoleBuffer.clear();
}
