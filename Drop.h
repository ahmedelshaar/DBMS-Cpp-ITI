#ifndef DROP_H
#define DROP_H

#include <bits/stdc++.h>
#include "Helper.h"

class Drop
{
    public:
        Drop(vector<string> &cmd);
    private:
        void dropDatabase(string& name);
        void dropTable(string& name);
};

#endif // DROP_H
