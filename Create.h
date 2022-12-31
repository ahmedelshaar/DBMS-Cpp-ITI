#ifndef CREATE_H
#define CREATE_H

#include <iostream>
#include <vector>
#include <direct.h>

using namespace std;

class Create
{
    public:
        Create(vector<string> &cmd);

    protected:

    private:
        void createDatabase(vector<string> &cmd);
        bool checkName(string name);
};

#endif // CREATE_H
