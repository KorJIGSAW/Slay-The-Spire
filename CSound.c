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
	SOUND_ROUND1 = 2,
	SOUND_ROUND2 = 3,
	SOUND_ROUND3 = 4,
	SOUND_ROUND4 = 5,
	SOUND_ROUND5 = 6,
	SOUND_ROUND6 = 7,
	SOUND_ROUND7 = 8,
	SOUND_ROUND8 = 9,
	SOUND_ROUND9 = 10,
	SOUND_ROUND10 = 11,
	SOUND_GameOver = 12
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

void Music_Round1() {
	Music_Init();
	PauseSound();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Round_1.mp3", FMOD_DEFAULT, 0, &sound[SOUND_ROUND1]);
	FMOD_System_PlaySound(g_System, sound[SOUND_ROUND1], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}

void Music_Round2() {
	Music_Init();
	PauseSound();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Round_2.mp3", FMOD_DEFAULT, 0, &sound[SOUND_ROUND2]);
	FMOD_System_PlaySound(g_System, sound[SOUND_ROUND2], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}

void Music_Round3() {
	Music_Init();
	PauseSound();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Round_3.mp3", FMOD_DEFAULT, 0, &sound[SOUND_ROUND3]);
	FMOD_System_PlaySound(g_System, sound[SOUND_ROUND3], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}

void Music_Round4() {
	Music_Init();
	PauseSound();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Round_4.mp3", FMOD_DEFAULT, 0, &sound[SOUND_ROUND4]);
	FMOD_System_PlaySound(g_System, sound[SOUND_ROUND4], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}

void Music_Round5() {
	Music_Init();
	PauseSound();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Round_5.mp3", FMOD_DEFAULT, 0, &sound[SOUND_ROUND5]);
	FMOD_System_PlaySound(g_System, sound[SOUND_ROUND5], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}

void Music_Round6() {
	Music_Init();
	PauseSound();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Round_6.mp3", FMOD_DEFAULT, 0, &sound[SOUND_ROUND6]);
	FMOD_System_PlaySound(g_System, sound[SOUND_ROUND6], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}

void Music_Round7() {
	Music_Init();
	PauseSound();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Round_7.mp3", FMOD_DEFAULT, 0, &sound[SOUND_ROUND7]);
	FMOD_System_PlaySound(g_System, sound[SOUND_ROUND7], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}

void Music_Round8() {
	Music_Init();
	PauseSound();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Round_8.mp3", FMOD_DEFAULT, 0, &sound[SOUND_ROUND8]);
	FMOD_System_PlaySound(g_System, sound[SOUND_ROUND8], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}

void Music_Round9() {
	Music_Init();
	PauseSound();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Round_9.mp3", FMOD_DEFAULT, 0, &sound[SOUND_ROUND9]);
	FMOD_System_PlaySound(g_System, sound[SOUND_ROUND9], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}

void Music_Round10() {
	Music_Init();
	PauseSound();
	FMOD_System_CreateSound(g_System, "/Users/bm838/source/repos/Slay the Spire/Slay the Spire/src/Round_10.mp3", FMOD_DEFAULT, 0, &sound[SOUND_ROUND10]);
	FMOD_System_PlaySound(g_System, sound[SOUND_ROUND10], NULL, 0, &channel1);
	FMOD_Channel_SetVolume(channel1, 0.1f);
	FMOD_System_Update(g_System);
}





