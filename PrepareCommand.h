#ifndef PREPARECOMMAND_H
#define PREPARECOMMAND_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class PrepareCommand
{
    public:
        PrepareCommand(string& line);

    protected:

    private:
        void tolowerString(string& line);
        void removeDuplicateSpace(string& line);
        void trim(string& line);

};

#endif // PREPARECOMMAND_H
