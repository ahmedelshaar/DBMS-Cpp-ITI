#ifndef SELECT_H
#define SELECT_H

#include <bits/stdc++.h>
#include "Helper.h"

class Select
{
    public:
        Select(vector<string>& cmd);

    private:
        void selectAll(string& database, string cols, string col_where = "", string value ="");
        void selectWithColumn(string& cols, vector<vector<string> >& data_of_table, int index_search = -1, string value = "");
};

#endif // SELECT_H
