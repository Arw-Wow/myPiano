#pragma once

#include <string>
#include <graphics.h>
#include <iostream>

#include "Timer.h"
#include "MusicNote.h"



extern bool is_over;



class MusicPlayer
{

public:
	MusicPlayer()
	{
		current_note_index = 0;
		for (int i = 0; i < 10; i++)
			current_note[i] = MusicNote::Invalid;

		timer_one_sound.set_oneshot(false);
		timer_one_sound.set_wait_time(interval);
		timer_one_sound.set_shot_callback(
			[&]() {
				can_play = true;
			}
		);
	}

	~MusicPlayer() = default;

	void reset()
	{
		current_note_index = 0;
		for (int i = 0; i < 10; i++)
		{
			str_music_source[i] = "";
			current_note[i] = MusicNote::Invalid;
		}
		is_end = false;
		is_start = false;
		can_play = true;
		timer_one_sound.restart();
	}

	void set_start(bool in)
	{
		is_start = in;
	}

	void set_music_source(const std::string *in_music_source)
	{
		for (int i = 0; i < 10; i++)
			str_music_source[i] = in_music_source[i];
	}

	void set_interval(int _interval)
	{
		interval = _interval;
		timer_one_sound.set_wait_time(interval);
	}

	void on_update(int delta)
	{
		if (is_end || !is_start)
			return;

		timer_one_sound.on_update(delta);
		
		bool flag = true;
		if (can_play)
		{
			for (int i = 0; i < 10; i++)
			{
				if (current_note_index >= str_music_source[i].size())
					continue;

				flag = false;

				switch (str_music_source[i][current_note_index])
				{
				case ' ':
					current_note[i] = MusicNote::Space;
					break;
				case 'z':
					current_note[i] = MusicNote::c;
					break;
				case 'x':
					current_note[i] = MusicNote::d;
					break;
				case 'c':
					current_note[i] = MusicNote::e;
					break;
				case 'v':
					current_note[i] = MusicNote::f;
					break;
				case 'm':
					current_note[i] = MusicNote::g;
					break;
				case ',':
					current_note[i] = MusicNote::a;
					break;
				case '.':
					current_note[i] = MusicNote::b;
					break;

				case 'a':
					current_note[i] = MusicNote::c1;
					break;
				case 's':
					current_note[i] = MusicNote::d1;
					break;
				case 'd':
					current_note[i] = MusicNote::e1;
					break;
				case 'f':
					current_note[i] = MusicNote::f1;
					break;
				case 'j':
					current_note[i] = MusicNote::g1;
					break;
				case 'k':
					current_note[i] = MusicNote::a1;
					break;
				case 'l':
					current_note[i] = MusicNote::b1;
					break;

				case 'q':
					current_note[i] = MusicNote::c2;
					break;
				case 'w':
					current_note[i] = MusicNote::d2;
					break;
				case 'e':
					current_note[i] = MusicNote::e2;
					break;
				case 'r':
					current_note[i] = MusicNote::f2;
					break;
				case 'u':
					current_note[i] = MusicNote::g2;
					break;
				case 'i':
					current_note[i] = MusicNote::a2;
					break;
				case 'o':
					current_note[i] = MusicNote::b2;
					break;

				case 'b':
					current_note[i] = MusicNote::cs;
					break;
				case 'n':
					current_note[i] = MusicNote::ds;
					break;
				case '1':
					current_note[i] = MusicNote::fs;
					break;
				case '2':
					current_note[i] = MusicNote::gs;
					break;
				case '3':
					current_note[i] = MusicNote::as;
					break;

				case 'g':
					current_note[i] = MusicNote::c1s;
					break;
				case 'h':
					current_note[i] = MusicNote::d1s;
					break;
				case '4':
					current_note[i] = MusicNote::f1s;
					break;
				case '5':
					current_note[i] = MusicNote::g1s;
					break;
				case '6':
					current_note[i] = MusicNote::a1s;
					break;

				case 't':
					current_note[i] = MusicNote::c2s;
					break;
				case 'y':
					current_note[i] = MusicNote::d2s;
					break;
				case '7':
					current_note[i] = MusicNote::f2s;
					break;
				case '8':
					current_note[i] = MusicNote::g2s;
					break;
				case '9':
					current_note[i] = MusicNote::a2s;
					break;

				case Space:
					break;
				case Invalid:
					break;

				default:
					break;
				}
			}
				
			current_note_index++;

			if (flag)
			{
				std::cout << "该乐曲已播放完毕" << std::endl;
				is_end = true;
				is_over = true;
				is_start = false;
				return;
			}
		}
	}

	void on_play()
	{
		if (is_end || !is_start)
			return;

		if (can_play)
		{
			for (int i = 0; i < 10; i++)
			{
				switch (current_note[i])
				{
				case c:
					mciSendString("play c from 0", NULL, 0, NULL);
					break;
				case d:
					mciSendString("play d from 0", NULL, 0, NULL);
					break;
				case e:
					mciSendString("play e from 0", NULL, 0, NULL);
					break;
				case f:
					mciSendString("play f from 0", NULL, 0, NULL);
					break;
				case g:
					mciSendString("play g from 0", NULL, 0, NULL);
					break;
				case a:
					mciSendString("play a from 0", NULL, 0, NULL);
					break;
				case b:
					mciSendString("play b from 0", NULL, 0, NULL);
					break;

				case c1:
					mciSendString("play c1 from 0", NULL, 0, NULL);
					break;
				case d1:
					mciSendString("play d1 from 0", NULL, 0, NULL);
					break;
				case e1:
					mciSendString("play e1 from 0", NULL, 0, NULL);
					break;
				case f1:
					mciSendString("play f1 from 0", NULL, 0, NULL);
					break;
				case g1:
					mciSendString("play g1 from 0", NULL, 0, NULL);
					break;
				case a1:
					mciSendString("play a1 from 0", NULL, 0, NULL);
					break;
				case b1:
					mciSendString("play b1 from 0", NULL, 0, NULL);
					break;

				case c2:
					mciSendString("play c2 from 0", NULL, 0, NULL);
					break;
				case d2:
					mciSendString("play d2 from 0", NULL, 0, NULL);
					break;
				case e2:
					mciSendString("play e2 from 0", NULL, 0, NULL);
					break;
				case f2:
					mciSendString("play f2 from 0", NULL, 0, NULL);
					break;
				case g2:
					mciSendString("play g2 from 0", NULL, 0, NULL);
					break;
				case a2:
					mciSendString("play a2 from 0", NULL, 0, NULL);
					break;
				case b2:
					mciSendString("play b2 from 0", NULL, 0, NULL);
					break;

				case cs:
					mciSendString("play cs from 0", NULL, 0, NULL);
					break;
				case ds:
					mciSendString("play ds from 0", NULL, 0, NULL);
					break;
				case fs:
					mciSendString("play fs from 0", NULL, 0, NULL);
					break;
				case gs:
					mciSendString("play gs from 0", NULL, 0, NULL);
					break;
				case as:
					mciSendString("play as from 0", NULL, 0, NULL);
					break;

				case c1s:
					mciSendString("play c1s from 0", NULL, 0, NULL);
					break;
				case d1s:
					mciSendString("play d1s from 0", NULL, 0, NULL);
					break;
				case f1s:
					mciSendString("play f1s from 0", NULL, 0, NULL);
					break;
				case g1s:
					mciSendString("play g1s from 0", NULL, 0, NULL);
					break;
				case a1s:
					mciSendString("play a1s from 0", NULL, 0, NULL);
					break;

				case c2s:
					mciSendString("play c2s from 0", NULL, 0, NULL);
					break;
				case d2s:
					mciSendString("play d2s from 0", NULL, 0, NULL);
					break;
				case f2s:
					mciSendString("play f2s from 0", NULL, 0, NULL);
					break;
				case g2s:
					mciSendString("play g2s from 0", NULL, 0, NULL);
					break;
				case a2s:
					mciSendString("play a2s from 0", NULL, 0, NULL);
					break;

				case Space:
					break;
				case Invalid:
					break;

				default:
					break;
				}
			}
			can_play = false;
		}
	}

	void music_note_push_back(char c)
	{
		str_music_source[0] += c;
	}


private:

	Timer timer_one_sound;
	bool can_play = true;
	bool is_start = false;
	bool is_end = false;
	std::string str_music_source[10];

	int current_note_index;
	MusicNote current_note[10];

	int interval = 350;

};

