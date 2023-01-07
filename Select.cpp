#include "Select.h"

Select::Select(vector<string>& cmd)
{
    if(cmd.size() == 4){
        if(cmd[2] == "from"){
            selectAll(cmd[3], cmd[1]);
        }else{
            cout<<"Syntax Invalid"<<endl;
        }
    }else if(cmd.size() == 8){
        if(cmd[2] == "from" && cmd[4] == "where" && cmd[6] == "="){
            selectAll(cmd[3], cmd[1], cmd[5], cmd[7]);
        }else{
            cout<<"Syntax Invalid"<<endl;
        }
    }else{
            cout<<"Syntax Invalid"<<endl;
    }
}

void Select::selectAll(string& database, string cols, string col_where, string value){
    vector<string> database_table = Helper::split(database, '.');
    if(database_table.size() != 2){
        cout<<"name of table Invalid"<<endl;
        return;
    }
    if(!Helper::checkName(database_table[0]) || !Helper::checkName(database_table[1])){
        cout<<"name of table Invalid"<<endl;
        return;
    }

    if(col_where != "" && !Helper::checkName(col_where)){
        cout<<"name of selection Invalid"<<endl;
        return;
    }

    if(!Helper::checkColumnsName(cols) && cols != "*"){
        cout<<"name of columns Invalid"<<endl;
        return;
    }

    if(Helper::checkDatabaseExist(database_table[0])){
        string table_path = database_table[0] + "/" + database_table[1];
        if(Helper::checkTableExist(table_path)){
            vector<vector<string> > data_of_table = Helper::readTable(database_table[0], database_table[1]);
            // check where
            int index_selection  = -2;
            if(col_where != ""){
                index_selection = Helper::indexColumn(data_of_table[0], col_where);
                if(index_selection == -1){
                    cout<<"the column for search does not exist"<<endl;
                    return;
                }
            }

            if(cols != "*"){
                if(index_selection != -2){
                    selectWithColumn(cols, data_of_table, index_selection, value);
                }else{
                    selectWithColumn(cols, data_of_table);
                }
            }else{
                cout<<Helper::join(data_of_table[0], "\t\t")<<endl;
                for(int i = 1; i < data_of_table.size(); i++){
                    if(index_selection != -2){
                        if(data_of_table[i][index_selection] != value){
                            continue;
                        }
                    }
                    cout<<Helper::join(data_of_table[i], "\t\t")<<endl;
                }
            }
        }else{
            cout<<"This table does not exist"<<endl;
        }
    }
}

void Select::selectWithColumn(string& cols, vector<vector<string> >& data_of_table, int index_search, string value){
    Helper::trim(cols, ',');
    vector<int> index_columns;
    vector<string> selection = Helper::split(cols, ',');
    for(int i= 0; i < selection.size(); i++){
        int index = Helper::indexColumn(data_of_table[0], selection[i]);
        if(index != -1){
            index_columns.push_back(index);
        }else{
            cout<<"not found column "<<selection[i]<<endl;
            return;
        }
    }
    // name of columns
    for(int j = 0; j < index_columns.size(); j++){
        cout<<data_of_table[0][index_columns[j]]<<"\t\t";
    }
    cout<<endl;
    for(int i = 1; i < data_of_table.size(); i++){
        if(index_search != -1){
            if(data_of_table[i][index_search] != value){
                continue;
            }
        }
        for(int j = 0; j < index_columns.size(); j++){
            cout<<data_of_table[i][index_columns[j]]<<"\t\t";
        }
        cout<<endl;
    }
}
