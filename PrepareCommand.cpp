#include "PrepareCommand.h"

PrepareCommand::PrepareCommand(string& line)
{
    tolowerString(line);
    removeDuplicateSpace(line);
    trim(line);
}

void PrepareCommand::tolowerString(string& line){
         for (int i = 0; i < line.size(); i++) {
            line[i] = tolower(line[i]);
          }
    }
void PrepareCommand::removeDuplicateSpace(string& line){
    for(int i=line.size()-1; i >= 0; i-- )
    {
        if(line[i]==' '&&line[i]==line[i-1])
        {
            line.erase( line.begin() + i );
        }
    }
}
void PrepareCommand::trim(string& line){
        int start, end;
        string trimmedString;
        for(int i =0;i < line.size(); i++){
            if(line[i] != ' '){
                start=i;
                break;
            }
        }
        for(int i=line.size() - 1; i >=0; i--){
            if(line[i] != ' '){
                end = i;
                break;
             }
         }
        for( int i =start;  i<= end;i++){
            trimmedString +=line[i];
        }
        line = trimmedString;
}
