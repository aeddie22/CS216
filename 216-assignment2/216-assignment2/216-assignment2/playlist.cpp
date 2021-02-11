#include <iostream>
#include "playlist.h"
#include "song.h"

using namespace std;

Node head;

PlayList :: PlayList()
{
    head = NULL;
    currentSong = -1;
    numSong = 0;
}

void PlayList:: AddSong(const class Song &s)
{
    Node *p = new Node;
    p->info = s;
    p->next = head;
    if (head == NULL) {
        head = p;
        currentSong = 0;
    }else{
        Node *q;
        for (q = head ; q->next != NULL ; q = q->next) {
            q->next = p;
        }
        numSong++;
    }
}

bool PlayList:: DeleteSong(const class Song &s)
{
    Node *p,*q = NULL;
    if (head == NULL) {
        return false;
    }for (p = head ; p != NULL; p = p->next) {
        if (p->info == s) {
            break;
        }
        q = p;
    }
    if (p == NULL) {
        return  false;
    }
    if (q == NULL) {
        head = head->next;
        if (head == NULL) {
            currentSong = -1;
        }
    }else
        q->next = p->next;
    delete p;
    numSong--;
    if (currentSong == numSong) {
        currentSong = 0;
    }
    return true;
}

void PlayList:: ShowAll()const
{
    Node *p = head;
    int num = 0;
    cout << ":";
    while (p) {
        cout << "NO." << num << ": " << p->info << endl;
        num++;
        p = p->next;
    }
    
}

void PlayList:: Play(int a)
{
    
}

void PlayList:: ShowStatus()const
{
    cout << ":PlayList status: " << numSong << "song(s), currently at song No. " << currentSong << endl;
}

PlayList:: ~PlayList()
{
    Node *p = head, *q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        delete q;
    }
    head = NULL;
}
