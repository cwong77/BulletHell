#include "Windows.h"
#include "Mmsystem.h"
#include "Winnt.h"
//#include <dirent.h>
#include <filesystem>
#include <string>
//#include <FileAPI.h>

class Jukebox {
	std::vector<std::string> playlist;	//holds playlist
	int playlistIndex;	//where we are in the playlist
	bool playing = false; //playing right now

public:
	Jukebox();
	void load();	//load playlist from music folder
	void play(std::string filepath);	//play sound, handles whether or not the jukebox is playing
	void next();	//next in playlist
	bool isPlaying();
	~Jukebox();
};