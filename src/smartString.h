//
//  smartString.h
//  particles3_0
//
//  Created by Josué Saul Martín Hernández on 10/10/16.
//
//

#ifndef smartString_h
#define smartString_h
#include "ofMain.h"

class smartString {
public:
    unsigned long stoMCL(string st);
    string stoLower(string st);
    list <string> stoTok(string st, string key);
    string cleanWhitespaces(string st); // borra espacios en blanco en toda la cadena
    string trimWhitespaces(string st); // borra espacios en blanco de inicio y final
    string addHttp(string st); // añade http:// al inicio de la cadena si no lo tiene
    
    void setup(string sentence);
    
    string primitive = "";
    string cleaned = "";
    list <string> tokens;
    list <string> params;
    
    bool compareSentences(string []);

private:
    void fill();
  
};

#endif /* smartString_h */
