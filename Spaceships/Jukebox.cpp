#include "Jukebox.h"

Jukebox::Jukebox() {

}

void Jukebox::load() {
	WIN32_FIND_DATA FindFileData;
	HANDLE hfind;
	char* path = "C:/Users/C.WONG/Documents/GitHub/BulletHell/Spaceships/Sound/*.wav";
	hfind = FindFirstFile(path, &FindFileData);
	if (hfind == INVALID_HANDLE_VALUE) {
		printf("FindFirstFailed\n");
	}
	else {
		//printf(TEXT("The first file found is %s\n"), FindFileData.cFileName);
		do{
			//printf("loop\n");
			//printf(TEXT("The next file found is %s\n"), FindFileData.cFileName);
			std::string path = "../Sound/";
			playlist.push_back(path + FindFileData.cFileName);
		} while (FindNextFile(hfind, &FindFileData) != 0);
	}
	printf("Playlist:\n");
	for (int i = 0; i < playlist.size(); ++i) {
		printf(playlist[i].c_str()); printf("\n");
	}
	playlistIndex = 0;
}

void Jukebox::play(std::string _path) {
	playing = true;
	printf("in play\n");
	printf(_path.c_str());
	PlaySound(_path.c_str(), NULL, SND_ASYNC);
}

void Jukebox::next() {
	//++playlistIndex;
	printf("in next\n");
	printf(playlist[++playlistIndex].c_str());
	play(playlist[playlistIndex]);
}

bool Jukebox::isPlaying() {
	return playing;
}

Jukebox::~Jukebox() {

}