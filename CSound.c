#include <fmod.h>
#include "fmod.h"
#include <stdio.h>

FMOD_SYSTEM* g_System;
FMOD_SOUND* sound[15];
FMOD_CHANNEL* channel1;
FMOD_CHANNEL* channel2;

typedef enum {
	SOUND_Start = 0,
	SOUND_SELECT = 1,
	SOUND_GameOver = 8
} EffectSound;

void StopSound()
{
	FMOD_Channel_Stop(&channel1);
}

void PauseSound() {
	FMOD_Channel_SetPaused(channel1, 1);
}

void UnPauseSound() {
	FMOD_Channel_SetPaused(channel1, 0);
}

void Music_Stop() {
	for (int i = 0; i < 15; i++) {
		FMOD_Sound_Release(sound[i]);
	}
	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}

void Music_Init() {
	FMOD_System_Create(&g_System, FMOD_VERSION);
	FMOD_System_Init(g_System, 3, FMOD_INIT_NORMAL, NULL);
	for (int i = 0; i < 15; i++) {
		sound[i] = NULL; // 배열 요소를 초기화
	}
}

void Music_Start() {
	Music_Init();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Sts_Main.mp3", FMOD_DEFAULT, 0, &sound[SOUND_Start]);
	//링크주소 바꿔야함.
	//데스크탑용 /Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Sts_Main.mp3
	//노트북용 /Users/user/source/repos/TermProject/src/Sts_Main.mp3
	FMOD_System_PlaySound(g_System, sound[SOUND_Start], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}

void Music_GameOver() {
	//Music_Init();	
	PauseSound();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Game_Over.mp3", FMOD_DEFAULT, 0, &sound[SOUND_GameOver]);
	//데스크탑용 /Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Game_Over.mp3
	//노트북용 /Users/user/source/repos/TermProject/src/Game_Over.mp3
	FMOD_System_PlaySound(g_System, sound[SOUND_GameOver], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}

void Music_Select() {
	Music_Init();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Sound_click.mp3", FMOD_DEFAULT, 0, &sound[SOUND_SELECT]);
	//데스크탑용 /Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Sound_click.mp3
	//노트북용 /Users/user/source/repos/TermProject/src/Sound_click.mp3
	FMOD_System_PlaySound(g_System, sound[SOUND_SELECT], NULL, 0, &channel2);
	FMOD_Channel_SetVolume(channel2, 0.1f);
	FMOD_System_Update(g_System);
}



