#ifndef DELETE_H
#define DELETE_H

#include <bits/stdc++.h>
#include "Helper.h"

class Delete
{
    public:
        Delete(vector<string>& cmd);

    protected:

    private:
        void deleteRows(string database, string col_where, string value);
};

#endif // DELETE_H
