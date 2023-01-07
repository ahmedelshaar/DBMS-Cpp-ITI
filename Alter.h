#ifndef ALTER_H
#define ALTER_H

#include <bits/stdc++.h>
#include <vector>
#include "Helper.h"

class Alter
{
    public:
        Alter(vector<string> &cmd);

    private:
        void renameTable(string old_name, string new_name);
        void renameDatabase(string old_name, string new_name);
        void renameColumn(string database, string old_coumn, string new_coumn);
        void addColumn(string database, string column);
        void dropColumn(string database, string column);
};

#endif // ALTER_H
