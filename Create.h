#ifndef CREATE_H
#define CREATE_H

#include <bits/stdc++.h>
#include "Helper.h"

class Create
{
    public:
        Create(vector<string> &cmd);
    private:
        void createDatabase(vector<string> &cmd);
        void createTable(vector<string> &cmd);
};

#endif // CREATE_H
