#include "Delete.h"

Delete::Delete(vector<string>& cmd)
{
    if(cmd.size() == 7){
        if(cmd[1] == "from" && cmd[3] == "where" && cmd[5] == "="){
            deleteRows(cmd[2], cmd[4], cmd[6]);
        }else{
            cout<<"Syntax Invalid"<<endl;
        }
    }else{
        cout<<"Syntax Invalid"<<endl;
    }
}

void Delete::deleteRows(string database, string col_where, string value){
    vector<string> database_table = Helper::split(database, '.');
    if(database_table.size() != 2){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(database_table[0]) || !Helper::checkName(database_table[1])){
        cout<<"name of table Invalid"<<endl;
        return;
    }

    if(!Helper::checkName(col_where)){
        cout<<"name of selection Invalid"<<endl;
        return;
    }

    if(Helper::checkDatabaseExist(database_table[0])){
        string table_path = database_table[0] + "/" + database_table[1];
        if(Helper::checkTableExist(table_path)){
            vector<vector<string> > data_of_table = Helper::readTable(database_table[0], database_table[1]);
            int index_selection = Helper::indexColumn(data_of_table[0], col_where);
            if(index_selection == -1){
                cout<<"the column for search does not exist"<<endl;
                return;
            }
            int count = 0;
            for(int i = 1; i < data_of_table.size(); i++){
                if(data_of_table[i][index_selection] == value){
                    data_of_table.erase(data_of_table.begin() + i);
                    count++;
                }
            }
            Helper::writeTable(database_table[0], database_table[1], data_of_table);
            cout<<count<<" rows have been deleted from the table"<<endl;
        }else{
            cout<<"This table does not exist"<<endl;
        }
    }
}
