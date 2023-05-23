#include <fmod.h>
#include "fmod.h"
#include <stdio.h>

FMOD_SYSTEM* g_System;
FMOD_SOUND* sound[15];
FMOD_CHANNEL* channel[15];

typedef enum {

	SOUND_Start = 0,
	SOUND_SELECT = 1,
	SOUND_HIT = 2,
	SOUND_JUMP = 3,
	SOUND_CLICK = 4,
	SOUND_GEN = 5,
	SOUND_CARROTDIE = 6,
	SOUND_SCREENOPEN = 7,
	SOUND_GameOver = 8

} EffectSound;


void Music_Stop(int i) {
	FMOD_Sound_Release(sound[i]);
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
	FMOD_System_PlaySound(g_System, sound[SOUND_Start], NULL, 0, &channel[SOUND_Start]);
	FMOD_Channel_SetVolume(channel[SOUND_Start], 0.1f);
	FMOD_System_Update(g_System);
}

void Music_GameOver() {
	Music_Init();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Game_Over.mp3", FMOD_DEFAULT, 0, &sound[SOUND_GameOver]);
	FMOD_System_PlaySound(g_System, sound[SOUND_GameOver], NULL, 0, &channel[SOUND_GameOver]);
	FMOD_Channel_SetVolume(channel[SOUND_GameOver], 0.4f);
	FMOD_System_Update(g_System);
}

void Music_Select() {
	//Music_Init();
	Music_Stop(0); //메인화면 노래 재생중지
	Music_Init();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Sound_click.mp3", FMOD_DEFAULT, 0, &sound[SOUND_SELECT]);
	FMOD_System_PlaySound(g_System, sound[SOUND_SELECT], NULL, 0, &channel[SOUND_SELECT]);
	FMOD_Channel_SetVolume(channel[SOUND_SELECT], 0.4f);
	FMOD_System_Update(g_System);
}
