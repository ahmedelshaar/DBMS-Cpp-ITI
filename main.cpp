#include <iostream>
#include <stdlib.h>

#include "Helper.h"
#include "Create.h"
#include "Show.h"
#include "Drop.h"
#include "Alter.h"
#include "Select.h"
#include "Insert.h"
#include "Update.h"
#include "Delete.h"

using namespace std;

int main()
{
    Helper::help();
    bool flag = true;
    while(flag){
        cout<<">>";
        string line;
        getline(cin, line);
        vector<string> cmd = Helper::PrepareCommand(line);
        if(cmd.size() > 0){
            if(cmd[0] == "create"){
                Create create(cmd);
            }else if(cmd[0] == "show"){
                Show show(cmd);
            }else if(cmd[0] == "drop"){
                Drop drop(cmd);
            }else if(cmd[0] == "alter"){
                Alter alter(cmd);
            }else if(cmd[0] == "select"){
                Select select(cmd);
            }else if(cmd[0] == "insert"){
                Insert insert(cmd);
            }else if(cmd[0] == "update"){
                Update update(cmd);
            }else if(cmd[0] == "delete"){
                Delete del(cmd);
            }else if(cmd[0] == "help" && cmd.size() == 1){
                Helper::help();
            }else if(cmd[0] == "clear" && cmd.size() == 1){
                system("cls");
            }else if(cmd[0] == "exit" && cmd.size() == 1){
                flag = false;
            }else{
                cout<<"Syntax Invalid"<<endl;
            }
        }
    }
    return 0;
}
