//
//  song.h
//  project0
//
//  Created by Grant Du on 2020-01-10.
//  Copyright © 2020 Grant Du. All rights reserved.
//
#include <string>
using namespace std;
class Song{
  private:
    string name;
    string artist;
  public:
    string get_name();
    string get_artist();
    Song(string name,string artist);
    Song();
    ~Song()=default;
    bool operator==(const Song &a);
};
