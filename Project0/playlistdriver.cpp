#include <iostream>
#include "playlist.h"
#include <string>
using namespace std;
Playlist::Playlist(){
    this->Songs=new Song[1];
}
int Playlist::add_Song(Song q)
{
    if (this->empty == this->list_length)
    {
        cout << "can not insert" << q.get_name() << ";" << q.get_artist() << endl;
        return 0;
    }
    for (int i = 0; i < this->list_length; i++)
    {
        if (*(this->Songs + i) == q)
        {
            cout << "can not insert" << q.get_name() << ";" << q.get_artist() << endl;
            return 0;
        }
    }
    *(this->Songs + this->empty) = q;
    this->empty++;
    cout << "success" << endl;
    return 1;
}
int Playlist::remove_Song(int n)
{
    if (n > this->list_length || (this->Songs + n-1)->get_name() == " ")
    {
        cout << "can not erase "<< n << endl;
        return 0;
    }
    else
    {
        if (n == this->list_length)
        {
            *(this->Songs + n-1) = Song();
            cout << "success" << endl;
            this->empty--;
            return 1;
        }
        else
        {
            for (int i = n; i < this->list_length; i++)
            {
                *(this->Songs + i - 1) = *(this->Songs + i);
            }
            cout << "success" << endl;
            this->empty--;
            return 1;
        }
    }
}

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
        int num;
        while (cin >> a)
        {
            if (a == "m")
            {
                cin >> num;
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
                    cout << "played " << n << " " << (new_list.Songs + n - 1)->get_name()<< ";" << (new_list.Songs + n-1)->get_artist()<< endl;
                }

            }
            else if (a == "e")
            {
                int n;
                cin >> n;
                new_list.remove_Song(n);
            }
        }
    }
