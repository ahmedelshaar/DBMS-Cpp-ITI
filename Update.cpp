#include "Update.h"

Update::Update(vector<string>& cmd)
{
    if(cmd.size() == 10){
        if(cmd[2] == "set" && cmd[4] == "=" && cmd[6] == "where" && cmd[8] == "="){
            updateRows(cmd[1], cmd[3], cmd[5], cmd[7], cmd[9]);
        }else{
            cout<<"Syntax Invalid"<<endl;
        }
    }else{
        cout<<"Syntax Invalid"<<endl;
    }
}

void Update::updateRows(string database, string& col_set, string& value_set, string& col_search, string& value_search){
    vector<string> database_table = Helper::split(database, '.');
    if(database_table.size() != 2){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(database_table[0]) || !Helper::checkName(database_table[1])){
        cout<<"name of table Invalid"<<endl;
        return;
    }

    if(!Helper::checkName(col_search) || !Helper::checkName(col_set)){
        cout<<"name of column Invalid"<<endl;
        return;
    }

    if(Helper::checkDatabaseExist(database_table[0])){
        string table_path = database_table[0] + "/" + database_table[1];
        if(Helper::checkTableExist(table_path)){
            vector<vector<string> > data_of_table = Helper::readTable(database_table[0], database_table[1]);
            int index_search = Helper::indexColumn(data_of_table[0], col_search);
            int index_set = Helper::indexColumn(data_of_table[0], col_set);
            if(index_search == -1){
                cout<<"the column for search does not exist"<<endl;
                return;
            }
            if(index_set == -1){
                cout<<"the column for update does not exist"<<endl;
                return;
            }
            int count = 0;
            for(int i = 1; i < data_of_table.size(); i++){
                if(data_of_table[i][index_search] == value_search){
                    data_of_table[i][index_set] = value_set;
                    count++;
                }
            }
            Helper::writeTable(database_table[0], database_table[1], data_of_table);
            cout<<count<<" rows have been updated from the table"<<endl;
        }else{
            cout<<"This table does not exist"<<endl;
        }
    }
}
