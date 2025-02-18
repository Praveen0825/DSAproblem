/*
Given a playlist of songs, you have to design a song shuffler.
This song shuffler is not like the normal song shuffler that shuffles the complete playlist at the start and returns a shuffled list, but instead when asked for a next song to be played, returns a random song from the list of songs.
The next random song to be played should satisfy a condition that the song was not played in the last 'k' turns.
You have to make sure, that at each call, all the eligible (not played during last k turns) songs have equal probability of being played next.
*/

#include<bits/stdc++.h>

class SongShuffler {
public:    
    SongShuffler(vector<char> & songs, int k) {
        this->k = k;
        this->songs = songs;
        for (int i = 0; i < songs.size(); i++) {
            mp[songs[i]] = i;
        }
    }
    
    char getNextSong() {
        int n = songs.size();
        int randIdx = rand() % n;
        char song = songs[randIdx];
        removeFromList(song);
        if (q.size() >= k) {
            char addingSong = q.front();
            addToList(addingSong);
            q.pop();
        }
        q.push(song);
        return song;
    }
    
private:
    queue<char> q;
    int k;
    unordered_map<char, int> mp;
    vector<char> songs;
    
    void addToList(char c) {
        songs.push_back(c);
        mp[c] = songs.size() - 1;
    }
    
    void removeFromList(char c) {
        char lastSong = songs.back();
        mp[lastSong] = mp[c];
        songs[mp[c]] = lastSong;
        
        songs.pop_back();
        mp.erase(c);
    }
    
};


int main() {
    vector<char> songs {'A', 'B', 'C', 'D'};
    int k = 3;
    SongShuffler sf(songs, k);
    
    for (int i = 0; i < 10; i++) {
        cout <<sf.getNextSong() << " ";
    }
    return 0;
}