#include <string>
#include <iostream>
#include "playlist.h"
using namespace std;
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
Playlist::~Playlist(){
    delete[] this->Songs;
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