#include "Show.h"

Show::Show(vector<string> &cmd)
{
    int cmdsize = cmd.size();
    if(cmdsize == 2 && cmd[1] == "database"){
        showDatabase();
    }else if(cmdsize == 3 && cmd[1] == "table"){
        showTable(cmd[2]);
    }else{
        cout<<"Syntax Invalid"<<endl;
    }
}

void Show::showDatabase()
{
    vector<string> databases = Helper::getDirectory("./database");
    if(databases.size() == 0){
        cout<<"No databases"<<endl;
        return;
    }
    for (vector<string>::iterator database = databases.begin(); database != databases.end(); database++) {
        cout<<database->c_str()<<endl;
    }
}

void Show::showTable(string& database)
{
    if(Helper::checkDatabaseExist(database)){
        vector<string> tables = Helper::getDirectory("./database/" + database);
        if(tables.size() == 0){
            cout<<"No Tables"<<endl;
            return;
        }
        for (vector<string>::iterator table = tables.begin(); table != tables.end(); table++) {
            vector<string> name = Helper::split(table->c_str(), '.');
            cout<<name[0]<<endl;
        }
    }
}
