#include "Drop.h"

Drop::Drop(vector<string> &cmd)
{
    int cmdsize = cmd.size();
    if(cmdsize == 3 && cmd[1] == "database"){
        dropDatabase(cmd[2]);
    }else if(cmdsize == 3 && cmd[1] == "table"){
        dropTable(cmd[2]);
    }else{
        cout<<"Syntax Invalid"<<endl;
    }
}

void Drop::dropDatabase(string& name){
    if(!Helper::checkName(name)){
        cout<<"Name of database invalid"<<endl;
        return;
    }
    if(Helper::checkDatabaseExist(name)){
        string command = "rmdir /s /q " + (".\\database\\" + name);
        system(command.c_str());
        cout<<"The database has been deleted successfully"<<endl;
    }
}

void Drop::dropTable(string& name){
    vector<string> database_table = Helper::split(name, '.');
    if(database_table.size() != 2){
        cout<<"name of table Invalid"<<endl;
        return;
    }

    if(!Helper::checkName(database_table[0])){
        cout<<"name of database Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(database_table[1])){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(Helper::checkDatabaseExist(database_table[0])){
        string table = database_table[0] + "/" + database_table[1];
        if(!Helper::checkTableExist(table)){
            cout<<"The table Not exists"<<endl;
            return;
        }
        string command = ".\\database\\" + database_table[0] + "\\" + database_table[1] + ".txt";
        remove(command.c_str());
        cout<<"The table has been deleted successfully"<<endl;
    }
}
