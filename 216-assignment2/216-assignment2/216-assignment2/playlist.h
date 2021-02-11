#ifndef playlist_h
#define playlist_h
#include "song.h"

class Node
{
public:
    Song info;
    Node *next;
};
class PlayList
{
    Node *head;
    int currentSong,numSong;
public:
    PlayList();
    void AddSong(const class Song &s);
    bool DeleteSong(const class  Song &s);
    void ShowAll() const;
    void Play(int num = 1);
    void ShowStatus()const;
    ~PlayList();
};


#endif
