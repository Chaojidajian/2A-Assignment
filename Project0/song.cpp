//
//  song.cpp
//  project0
//
//  Created by Grant Du on 2020-01-10.
//  Copyright © 2020 Grant Du. All rights reserved.
//
#include <string>
#include "song.h"
using namespace std;
Song::Song(string name,string artist){
    this->name=name;
    this->artist=artist;
}
Song::Song(){
    this->name=" ";
    this->artist=" ";
}
bool Song::operator==(const Song &a)
{   
    return (a.name == this-> name);
}
string Song::get_name(){
    return this->name;
}
string Song::get_artist(){
    return this->artist;
}
