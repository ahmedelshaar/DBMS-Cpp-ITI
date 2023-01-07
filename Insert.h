#ifndef INSERT_H
#define INSERT_H

#include <bits/stdc++.h>
#include "Helper.h"

class Insert
{
    public:
        Insert(vector<string>& cmd);

    private:
        void insertRow(string database, string& columns);
};

#endif // INSERT_H
