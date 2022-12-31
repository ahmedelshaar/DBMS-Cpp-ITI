#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include "PrepareCommand.h"
#include "Create.h"

using namespace std;

vector<string> split(string& line, char split = ' '){
    stringstream ss(line);
    vector<string> vector_string;
    string tok;
    while (getline(ss, tok, split)) {
        vector_string.push_back(tok);
    }
    return vector_string;
}


int main()
{

    bool flag = true;
    while(flag){
        string line;
        getline(cin, line);
        PrepareCommand pre(line);
        vector<string> cmd = split(line);
        if(cmd.size() > 0){
            if(cmd[0] == "select"){

            }else if(cmd[0] == "insert"){
            }else if(cmd[0] == "update"){
            }else if(cmd[0] == "delete"){
            }else if(cmd[0] == "alter"){
            }else if(cmd[0] == "create"){
                Create create(cmd);
            }else if(cmd[0] == "show"){
            }else if(cmd[0] == "drop"){
            }else if(cmd[0] == "exit" && cmd.size() == 1){
                flag = false;
            }else{
                cout<<"Syntax Invalid"<<endl;
            }
        }
    }
    return 0;
}
