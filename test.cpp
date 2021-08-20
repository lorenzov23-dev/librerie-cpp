#include "data_management.h"



int main() 
    {
        map<string, string> mappa;
        mappa = leggi_file();
        bool found = false;
        map<string, string>::iterator it = mappa.begin(); // internalMap is std::map
        while(it != mappa.end())
            {
                found = (it->second == "mario1");
                if(found)
                    {
                        cout << "trovato";
                    }
                ++it;
            }
        return 0;
    }