#include "Helper.h"

static vector<string> Helper::split(string& line, char split = ' '){
    stringstream ss(line);
    vector<string> vector_string;
    string tok;
    while (getline(ss, tok, split)) {
        vector_string.push_back(tok);
    }
    return vector_string;
}
