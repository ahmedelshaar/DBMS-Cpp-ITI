#ifndef UPDATE_H
#define UPDATE_H

#include <bits/stdc++.h>
#include "Helper.h"

class Update
{
    public:
        Update(vector<string>& cmd);
    private:
        void updateRows(string database, string& col_set, string& value_set, string& col_search, string& value_search);
};

#endif // UPDATE_H
