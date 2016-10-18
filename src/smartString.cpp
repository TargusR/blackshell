//
//  smartString.cpp
//  particles3_0
//
//  Created by Josué Saul Martín Hernández on 10/10/16.
//
//
#include "smartString.h"

//--------------------------------------------------------------
unsigned long smartString::stoMCL(string st){
    // String to multicharacter literal, Returns long value of the bytes of the strings
    unsigned long acum = 0;
    unsigned long cval = 0;
    for(int i = 0; i < st.length(); i++ ){
        cval = (int)st[i] * pow(256,(st.length()-1)-i);
        //cout << st[i] << "=" << (int)st[i] << ", " << cval << endl;
        acum += cval;
    }
    return acum;
}

//--------------------------------------------------------------
string smartString::stoLower(string st){
    // String to lowercase string
    for(int i = 0; i < st.length(); i++ )
        st[i] = tolower(st[i]);
    return st;
}

//--------------------------------------------------------------
list <string> smartString::stoTok(string st, string key) {
    // Split string into tokens and return it as a vector of tokens
    list <string> tokens;
    int begin = 0;
    
    for(int i = 0; i < st.length(); i++) {
        for(int j = 0; j < key.length(); j++){
            //st[i+j] vs key[j]
            if(st[i+j] != key[j]) break; // Romper ciclo si no hay coincidencia
            if(j+1 >= key.length()) { // Trabajar si se ha comparado el ultimo caracter de key
                if((i - begin) > 0) { // Comparar si hay algo que guardar
                    string tempS = st.substr(begin,i-begin);
                    tokens.push_back(tempS);
                }
                begin = i = i+key.length();
            }
        }
        if(i+1 >= st.length()) {
            string tempS = st.substr(begin);
            tokens.push_back(tempS);
        }
    }
    return tokens;
}

//--------------------------------------------------------------
string smartString::cleanWhitespaces(string st) {
    int begin = 0;
    string product = "";
    
    for(int i = 0; i < st.length(); i++) {
        if((int)st[i] == ' ') {
            product += st.substr(begin, i-begin);
            begin = i+1;
        }
        if(i == st.length()-1 && (int)st[i] != ' ') {
            product += st.substr(begin, (i+1)-begin);
        }
    }
    
    return product;
}

//--------------------------------------------------------------
string smartString::trimWhitespaces(string st) {
    string product = "";
    int i = 0;
    
    // cortar el principio
    while(i < st.length() && (int)st[i] == ' ')
        i++;
    product = st.substr(i, st.length()-i);
    
    i = product.length() - 1;
    // cortar el final
    while(i > 0 && (int)st[i] == ' ')
        i--;
    product = product.substr(0, i+1);
    
    return product;
}

string smartString::addHttp(string st) {
    if(st.substr(0,4) != "http")
        st = "http://" + st;
    return st;
}

//--------------------------------------------------------------
// Non Static Methods
//--------------------------------------------------------------
void smartString::fill() {
    // Clean string for params
    for(int i = 0; i < smartString::primitive.length(); i++) {
        if((int)smartString::primitive[i] == '-') {
            // Cleaned String
            smartString::cleaned = smartString::primitive.substr(0,i);
            
            // Parameters List
            string paramString = smartString::primitive.substr(i,smartString::primitive.length() - i);
            paramString = cleanWhitespaces(paramString);
            smartString::params = stoTok(paramString, "-");
            break;
        }
    }
    // word tokens
    if(smartString::cleaned == "")
        smartString::cleaned = smartString::primitive;
    smartString::cleaned = trimWhitespaces(smartString::cleaned);
    smartString::tokens = stoTok(smartString::cleaned, " ");
}

//--------------------------------------------------------------
void smartString::setup(string sentence) {
    smartString::primitive = stoLower(sentence);
    smartString::fill();
}

//--------------------------------------------------------------
bool smartString::compareSentences(string references[]) {
    for(int i = 0; i < references->size(); i++) {
        // comparar longitudes
        if(references[i].length() != smartString::cleaned.length())
            continue;
        // comparar cantidad de tokens
        list <string> referenceTokens = stoTok(references[i], " ");
        if(referenceTokens.size() != smartString::tokens.size())
            continue;
        // comparar token por token
        list <string> commandTokens = smartString::tokens;
        while(referenceTokens.size() > 0) {
            if(referenceTokens.front() != commandTokens.front())
                break;
            referenceTokens.pop_front();
            commandTokens.pop_front();
        }
        // revisar si se alcanzó el final de cadena
        if(referenceTokens.size() > 0)
            continue;
        // retornar verdadero si se ha llegado hasta aquí
        return true;
    }
    return false;
}
