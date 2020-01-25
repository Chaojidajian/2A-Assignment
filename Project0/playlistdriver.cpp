#include <iostream>
#include "playlist.h"
#include <string>
using namespace std;
    void extract_input(string input, string & name, string & artist)
    {
        bool c = true;
        for (size_t i = 0; i != input.length(); i++)
        {
            if (input[i] != ';' && c)
            {
                name = name + input[i];
            }
            if (input[i] == ';' && c)
            {
                c = false;
            }
            if (input[i] != ';' && !c)
            {
                artist = artist + input[i];
            }
        }
    }
    int main()
    {
        Playlist new_list;
        string a;
        
        while (cin >> a)
        {
            if (a == "m")
            {   
                int num;
                cin >> num;
                new_list.Songs=new Song[num];
                new_list.list_length = num;
                new_list.empty = 0;
                cout << "success" << endl;
            }
            else if (a == "i")
            {
                string temp1;
                getline(cin, temp1);
                string name;
                string artist;
                extract_input(temp1, name, artist);
                Song temp(name, artist);
                new_list.add_Song(temp);
            }
            else if (a == "p")
            {
                int n;
                cin >> n;
                if(n>new_list.list_length||(new_list.Songs + n - 1)->get_name() == " "){
                     cout << "can not play " << n << endl;
                }
                else
                {
                    cout << "played " << n<< (new_list.Songs + n - 1)->get_name()<< ";" << (new_list.Songs + n-1)->get_artist()<< endl;
                }

            }
            else if (a == "e")
            {
                int n;
                cin >> n;
                new_list.remove_Song(n);
            }
        }
        return 0;
    }
