#include "Create.h"

Create::Create(vector<string> &cmd)
{
    int cmdsize = cmd.size();
    if(cmdsize >= 2){
        if(cmd[1] == "table" ){
            createTable(cmd);
        }else if (cmd[1] == "database"){
            createDatabase(cmd);
        }else{
            cout<<"Syntax Invalid: create database - create table"<<endl;
        }
    }else{
        cout<<"Syntax Invalid"<<endl;
    }
}

void Create::createDatabase(vector<string> &cmd){
    if(cmd.size() == 2){
        cout<<"Missed database name"<<endl;
        return;
    }
    if(cmd.size() > 3 || !Helper::checkName(cmd[2])){
        cout<<"name of database Invalid"<<endl;
        return;
    }

    string  dirName = "./database/" + cmd[2];
    if(_mkdir(dirName.c_str()) == 0){
        cout<<"The database has been created successfully"<<endl;
    }else{
        cout<<"Database Already exists"<<endl;
    }
}

void Create::createTable(vector<string>& cmd){
    if(cmd.size() == 2){
        cout<<"Missed database and table name"<<endl;
        return;
    }

    if(cmd.size() == 3){
        cout<<"Missed columns"<<endl;
        return;
    }

    if(!Helper::checkColumnsName(cmd[3]) || cmd.size() > 4){
        cout<<"name of Columns Invalid"<<endl;
        return;
    }

    vector<string> database_table = Helper::split(cmd[2], '.');
    if(database_table.size() != 2){
        cout<<"name of table Invalid"<<endl;
        return;
    }

    if(!Helper::checkName(database_table[1])){
        cout<<"name of table Invalid"<<endl;
        return;
    }

    if(Helper::checkDatabaseExist(database_table[0])){
        string name = database_table[0] + "/" + database_table[1];
        if(Helper::checkTableExist(name)){
            cout<<"The table already exists"<<endl;
            return;
        }
        Helper::trim(cmd[3], ',');
        if(Helper::checkDuplicateColumns(cmd[3])){
            cout<<"More than one column cannot have the same name"<<endl;
            return;
        }

        ofstream file(("./database/" + name + ".txt").c_str());
        file << cmd[3];
        file.close();
        cout<<"The table has been created successfully"<<endl;
    }
}
