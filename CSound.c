#include <fmod.h>
#include "fmod.h"
#include <stdio.h>

FMOD_SYSTEM* g_System;
FMOD_SOUND* sound;
FMOD_CHANNEL* channel;

void Music_Stop() {
	FMOD_Sound_Release(sound);
	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}

void Music_Init() {
	FMOD_System_Create(&g_System, FMOD_VERSION);
	FMOD_System_Init(g_System, 3, FMOD_INIT_NORMAL, NULL);
}

void Music_Start() {
	Music_Init();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Sts_Main.mp3", FMOD_DEFAULT, 0, &sound);
	

	for (;;) {
		FMOD_System_PlaySound(g_System, sound, NULL, 0, &channel);
		FMOD_Channel_SetVolume(channel, 0.01f);
		FMOD_System_Update(g_System);
	}
}
