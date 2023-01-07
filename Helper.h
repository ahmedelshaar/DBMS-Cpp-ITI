#ifndef HELPER_H
#define HELPER_H

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <dirent.h>

using namespace std;

class Helper
{
    public:
        static void tolowerString(string& line);
        static void removeDuplicateSpace(string& line);
        static void trim(string& line, char ch);
        static vector<string> split(string line, char split = ' ');
        static string join(vector<string>& v, string delim = ",");
        static vector<string> PrepareCommand(string& line);
        static bool checkName(string name);
        static bool checkColumnsName(string column);
        static bool checkDuplicateColumns(string cols);
        static bool checkTableExist(string name);
        static bool checkDatabaseExist(string database, bool show_massage = true);
        static vector<string> getDirectory(string path);
        static vector<vector<string> > readTable(string database, string table);
        static void writeTable(string database, string table, vector<vector<string> >& data);
        static int indexColumn(vector<string>& cols, string col);
        static void help();
    private:
        Helper();
};
#endif // HELPER_H
