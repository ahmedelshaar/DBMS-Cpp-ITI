#ifndef SHOW_H
#define SHOW_H

#include <bits/stdc++.h>
#include "Helper.h"

class Show
{
    public:
        Show(vector<string>& cmd);
    private:
        void showDatabase();
        void showTable(string& cmd);
};

#endif // SHOW_H
