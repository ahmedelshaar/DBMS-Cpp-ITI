#include "Alter.h"

Alter::Alter(vector<string> &cmd)
{
    if(cmd.size() == 5){
        if(cmd[1] == "table" && cmd[2] == "rename"){
                renameTable(cmd[3], cmd[4]);
        }else if(cmd[1] == "database" && cmd[2] == "rename"){
                renameDatabase(cmd[3], cmd[4]);
        }else{
            cout<<"Syntax Invalid"<<endl;
        }
    }else if(cmd.size() == 7){
        if(cmd[1] == "table" && cmd[3] == "rename" && cmd[4] == "column"){
            renameColumn(cmd[2], cmd[5], cmd[6]);
        }else{
            cout<<"Syntax Invalid"<<endl;
        }
    }else if(cmd.size() == 6){
        if(cmd[1] == "table" && cmd[3] == "add" && cmd[4] == "column"){
            addColumn(cmd[2], cmd[5]);
        }else if(cmd[1] == "table" && cmd[3] == "drop" && cmd[4] == "column"){
            dropColumn(cmd[2], cmd[5]);
        }else{
            cout<<"Syntax Invalid"<<endl;
        }
    }else {
        cout<<"Syntax Invalid"<<endl;
    }
}

void Alter::renameTable(string old_name, string new_name){
    vector<string> database_table = Helper::split(old_name, '.');
    if(database_table.size() != 2){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(database_table[0]) || !Helper::checkName(database_table[1]) || !Helper::checkName(new_name)){
        cout<<"name of table Invalid"<<endl;
        return;
    }

    string old_table = database_table[0] + "/" + database_table[1];
    string new_table = database_table[0] + "/" + new_name;

    if(Helper::checkDatabaseExist(database_table[0])){
        if(!Helper::checkTableExist(old_table)){
            cout<<"You do not have a table with this name"<<endl;
            return;
        }
        if(Helper::checkTableExist(new_table)){
            cout<<"There is a table with the same name"<<endl;
            return;
        }
        old_table = "./database/"+ old_table +".txt";
        new_table = "./database/"+ new_table +".txt";
        rename(old_table.c_str(), new_table.c_str());
        cout<<"The table name has been changed successfully"<<endl;
    }
}

void Alter::renameDatabase(string old_name, string new_name){
    if(!Helper::checkName(old_name) && !Helper::checkName(new_name)){
        cout<<"name of database Invalid"<<endl;
        return;
    }
    if(Helper::checkDatabaseExist(old_name)){
        if(Helper::checkDatabaseExist(new_name, false)){
            cout<<"The database name already exists"<<endl;
            return;
        }
        old_name = "./database/"+ old_name;
        new_name = "./database/"+ new_name;
        rename(old_name.c_str(), new_name.c_str());
        cout<<"The database name has been changed successfully"<<endl;
    }
}

void Alter::renameColumn(string table, string old_column, string new_column){
    vector<string> database_table = Helper::split(table, '.');
    if(database_table.size() != 2){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(database_table[0]) || !Helper::checkName(database_table[1])){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(old_column) || !Helper::checkName(new_column)){
        cout<<"name of column Invalid"<<endl;
        return;
    }
    if(Helper::checkDatabaseExist(database_table[0])){
        string table_path = database_table[0] + "/" + database_table[1];
        if(Helper::checkTableExist(table_path)){
            vector<vector<string> > data_of_table = Helper::readTable(database_table[0], database_table[1]);
            int index_old_column = Helper::indexColumn(data_of_table[0], old_column);
            if(index_old_column == -1){
                cout<<"This column does not exist in the table"<<endl;
                return;
            }
            int index_new_column = Helper::indexColumn(data_of_table[0], new_column);
            if(index_new_column != -1){
                cout<<"This column already exists"<<endl;
                return;
            }
            data_of_table[0][index_old_column] = new_column;
            Helper::writeTable(database_table[0], database_table[1], data_of_table);
            cout<<"Column name changed successfully"<<endl;
        }else{
            cout<<"This table does not exist"<<endl;
        }
    }
}
void Alter::addColumn(string database, string column){
    vector<string> database_table = Helper::split(database, '.');
    if(database_table.size() != 2){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(database_table[0]) || !Helper::checkName(database_table[1])){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(column)){
        cout<<"name of column Invalid"<<endl;
        return;
    }
    if(Helper::checkDatabaseExist(database_table[0])){
        string table_path = database_table[0] + "/" + database_table[1];
        if(Helper::checkTableExist(table_path)){
            vector<vector<string> > data_of_table = Helper::readTable(database_table[0], database_table[1]);
            int index_column = Helper::indexColumn(data_of_table[0], column);
            if(index_column != -1){
                cout<<"This column already exists"<<endl;
                return;
            }
            data_of_table[0].push_back(column);
            for(int i = 1; i < data_of_table.size(); i++){
                data_of_table[i].push_back("null");
            }
            Helper::writeTable(database_table[0], database_table[1], data_of_table);
            cout<<"Add Column successfully"<<endl;
        }else{
            cout<<"This table does not exist"<<endl;
        }
    }
}
void Alter::dropColumn(string database, string column){
    vector<string> database_table = Helper::split(database, '.');
    if(database_table.size() != 2){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(database_table[0]) || !Helper::checkName(database_table[1])){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(column)){
        cout<<"name of column Invalid"<<endl;
        return;
    }
    if(Helper::checkDatabaseExist(database_table[0])){
        string table_path = database_table[0] + "/" + database_table[1];
        if(Helper::checkTableExist(table_path)){
            vector<vector<string> > data_of_table = Helper::readTable(database_table[0], database_table[1]);
            int index_column = Helper::indexColumn(data_of_table[0], column);
            if(index_column == -1){
                cout<<"This column does not exist in the table"<<endl;
                return;
            }
            if(data_of_table[0].size() == 1){
                cout<<"There must be at least one column in the table"<<endl;
                return;
            }
            for(int i = 0; i < data_of_table.size(); i++){
                data_of_table[i].erase(data_of_table[i].begin() + index_column);
            }
            Helper::writeTable(database_table[0], database_table[1], data_of_table);
            cout<<"Drop Column successfully"<<endl;
        }else{
            cout<<"This table does not exist"<<endl;
        }
    }
}

