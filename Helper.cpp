#include "Helper.h"

void Helper::tolowerString(string& line){
         for (int i = 0; i < line.size(); i++) {
            line[i] = tolower(line[i]);
          }
}

void Helper::removeDuplicateSpace(string& line){
    for(int i=line.size()-1; i >= 0; i-- )
    {
        if(line[i]==' '&&line[i]==line[i-1])
        {
            line.erase( line.begin() + i );
        }
    }
}

void Helper::trim(string& line, char ch = ' '){
        int start, end;
        string trimmedString;
        for(int i =0;i < line.size(); i++){
            if(line[i] != ch){
                start=i;
                break;
            }
        }
        for(int i=line.size() - 1; i >=0; i--){
            if(line[i] != ch){
                end = i;
                break;
             }
         }
        for( int i =start;  i<= end;i++){
            trimmedString +=line[i];
        }
        line = trimmedString;
}

 vector<string> Helper::split(string line, char split){
    stringstream ss(line);
    vector<string> vector_string;
    string tok;
    while (getline(ss, tok, split)) {
        vector_string.push_back(tok);
    }
    return vector_string;
}

string Helper::join(vector<string>& v, string delim){
    string s = "";
    for (int i = 0; i < v.size(); i++) {
        s += v[i];
        if (i != v.size() - 1) {
            s += delim;
        }
    }
    return s;
}

 vector<string>  Helper::PrepareCommand(string& line){
    tolowerString(line);
    removeDuplicateSpace(line);
    trim(line);
    return split(line);
}

bool Helper::checkName(string name){
    if(name.size() == 0) return false;

    for(int i = 0; i < name.size(); i++){
        if(isalpha(name[i]) == 0){
            return false;
        }
    }
    return true;
}

bool Helper::checkColumnsName(string column){
    vector<string> cols = Helper::split(column, ',');
    for (vector<string>::iterator col = cols.begin(); col != cols.end(); col++) {
        if(!Helper::checkName(col->c_str())){
            return false;
        }
    }
    return true;
}

bool Helper::checkDuplicateColumns(string cols)
{
    vector<string> v = Helper::split(cols, ',');
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i + 1])
        {
            return true;
        }
    }
    return false;
}

bool Helper::checkTableExist(string name){
    ifstream file(("./database/" + name + ".txt").c_str());
    if(file){
        return true;
    }
    return false;
}

bool Helper::checkDatabaseExist(string database, bool show_massage){
    vector<string> databases = Helper::getDirectory("./database");
    vector<string>::iterator checkExist = find(databases.begin(), databases.end(), database);
    if(checkExist==databases.end()){
        if(show_massage){
            cout<<"Not Found Database"<<endl;
        }
        return false;
    }
    return true;
}


vector<string> Helper::getDirectory(string path){
    vector<string> directory;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path.c_str())) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
          if(ent->d_name[0] != '.')
            directory.push_back(ent->d_name);
      }
      closedir (dir);
    }
    return directory;
}

vector<vector<string> > Helper::readTable(string database, string table){
    vector<vector<string> > data;
    string path = "./database/" + database + "/" + table +".txt";
    ifstream file(path.c_str());
    string line;
    while(getline(file, line)){
        data.push_back(Helper::split(line, ','));
    }
    file.close();
    return data;
}

void Helper::writeTable(string database, string table, vector<vector<string> >& data){
    string path = "./database/" + database + "/" + table +".txt";
    ofstream file(path.c_str(), ios::out | ios::trunc);
    for(int i = 0; i < data.size(); i++){
        if(data[i].size() > 0)
            file << Helper::join(data[i])<<endl;
    }
    file.close();
}


int Helper::indexColumn(vector<string>& cols, string col){
    for(int i = 0; i < cols.size(); i++){
        if(cols[i] == col){
            return i;
        }
    }
    return -1;
}


void Helper::help()
{
    cout<<"NOTE => name_of_database and name_of_table and column_name: Only letters and numbers are allowed"<<endl;
    cout<<endl;
    cout<<"Create Command"<<endl;
    cout<<"Create Database\t\t=> create database name_of_database"<<endl;
    cout<<"Create Table\t\t=> create table name_of_database.name_of_table column_name1,column_name2,column_name3"<<endl;
    cout<<endl;
    cout<<"Show Command"<<endl;
    cout<<"Show Database\t\t=> show database"<<endl;
    cout<<"Show Table\t\t=> show table name_of_database"<<endl;
    cout<<endl;
    cout<<"Drop Command"<<endl;
    cout<<"Drop Database\t\t=> drop database name_of_database"<<endl;
    cout<<"Drop Table\t\t=> drop table name_of_database.name_of_table"<<endl;
    cout<<endl;
    cout<<"Alter Command"<<endl;
    cout<<"Alter Rename Table\t\t=> alter table rename name_of_database.old_name_of_table new_name_of_table"<<endl;
    cout<<"Alter Rename Database\t\t=> alter database rename old_name_of_database new_name_of_database"<<endl;
    cout<<"Alter Rename Column\t\t=> alter table name_of_database.name_of_table rename column old_column new_column"<<endl;
    cout<<"Alter Table Add Column\t\t=> alter table name_of_database.name_of_table add column name_column"<<endl;
    cout<<"Alter Table Drop Column\t\t=> alter table name_of_database.name_of_table drop column name_column"<<endl;
    cout<<endl;
    cout<<"Select Command"<<endl;
    cout<<"Select all from Table\t\t=> select * from name_of_database.name_of_table"<<endl;
    cout<<"Select specific columns\t\t=> select column_name1,column_name2 from name_of_database.name_of_table"<<endl;
    cout<<"Select all With Where\t\t=> select * from name_of_database.name_of_table where"<<endl;
    cout<<"Select columns & Where\t\t=> select column_name1,column_name2 from name_of_database.name_of_table where column = value"<<endl;
    cout<<endl;
    cout<<"Insert Command"<<endl;
    cout<<"Insert into table\t\t=> insert into name_of_database.name_of_table value value1,value2,value3"<<endl;
    cout<<endl;
    cout<<"Update Command"<<endl;
    cout<<"update rows\t\t=> update  name_of_database.name_of_table set column = value where selection_column = selection_value"<<endl;
    cout<<endl;
    cout<<"Delete Command"<<endl;
    cout<<"delete rows\t\t=> delete from name_of_database.name_of_table where column_name = value"<<endl;
    cout<<endl;
    cout<<"help\t\t=> for show document"<<endl;
    cout<<"clear\t\t=> for clear console"<<endl;
    cout<<"exit\t\t=> for close program"<<endl;
    cout<<endl;
}
