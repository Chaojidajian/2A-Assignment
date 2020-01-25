//
//  playlist.h
//  project0
//
//  Created by Grant Du on 2020-01-10.
//  Copyright © 2020 Grant Du. All rights reserved.
//

#include <string>
#include "song.h"
using namespace std;
class Playlist{
  public:
    Song *Songs;
    size_t empty;
    size_t list_length;
    int add_Song(Song a);
    int remove_Song(int n);
    Playlist()=default;
    ~Playlist();
};

