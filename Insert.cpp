#include "Insert.h"

Insert::Insert(vector<string>& cmd)
{
    if(cmd.size() == 5){
        if(cmd[1] == "into" && cmd[3] == "value"){
            insertRow(cmd[2], cmd[4]);
        }else{
            cout<<"Syntax Invalid"<<endl;
        }
    }else{
        cout<<"Syntax Invalid"<<endl;
    }
}

void Insert::insertRow(string database, string& columns){
    vector<string> database_table = Helper::split(database, '.');
    if(database_table.size() != 2){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(database_table[0]) || !Helper::checkName(database_table[1])){
        cout<<"name of table Invalid"<<endl;
        return;
    }

    if(Helper::checkDatabaseExist(database_table[0])){
        string table_path = database_table[0] + "/" + database_table[1];
        if(Helper::checkTableExist(table_path)){
            vector<vector<string> > data_of_table = Helper::readTable(database_table[0], database_table[1]);
            Helper::trim(columns, ',');
            vector<string> v_columns = Helper::split(columns, ',');
            if(data_of_table[0].size() != v_columns.size()){
                cout<<"The number of values is not equal on the columns"<<endl;
                return;
            }
            data_of_table.push_back(v_columns);
            Helper::writeTable(database_table[0], database_table[1], data_of_table);
            cout<<"It has been inserted successfully"<<endl;
        }else{
            cout<<"This table does not exist"<<endl;
        }
    }
}
