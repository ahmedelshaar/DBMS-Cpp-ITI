#include "Create.h"

Create::Create(vector<string> &cmd)
{
    int cmdsize = cmd.size();
    if(cmdsize > 2){
        if(cmd[1] == "table" ){
        }else if (cmd[1] == "database"){
            createDatabase(cmd);
        }else{
            cout<<"Syntax Invalid"<<endl;
        }
    }else{
        cout<<"Syntax Invalid"<<endl;
    }
}

void Create::createDatabase(vector<string> &cmd){
    if(cmd.size() > 3){
        cout<<"name of database Invalid"<<endl;
        return;
    }
    if(checkName(cmd[2])){
        string  dirName = "./database/" + cmd[2];
        if(_mkdir(dirName.c_str()) == 0){
            cout<<"Database Created Done"<<endl;
        }else{
            cout<<"Database Already exists"<<endl;
        }
    }else{
        cout<<"name of database Invalid"<<endl;
    }
}

bool Create::checkName(string name){
    for(int i = 0; i < name.size(); i++){
        if(isalpha(name[i]) == 0){
            return false;
        }
    }
    return true;
}
