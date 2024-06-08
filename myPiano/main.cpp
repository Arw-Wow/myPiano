#include <iostream>
#include <graphics.h>
#include <string>

#include "MusicPlayer.h"
#include "MusicResource.h"
#include "Tools.h"

#pragma comment(lib, "Winmm.lib")



constexpr int FPS = 144;



MusicResource music_resource;

MusicPlayer music_player;

bool is_record = false;

bool can_play = true;

bool is_over = false;

/*！！！！！！！！！！！！！！！！！！！！！！！彿坿蕗苧！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/

IMAGE img_background;

/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/

void Load_Resource()
{
	loadimage(&img_background, "res/img_background.jpg", 1280, 720);
	
	mciSendString(_T("open res/c.mp3 alias c"), NULL, 0, NULL);
	mciSendString(_T("open res/d.mp3 alias d"), NULL, 0, NULL);
	mciSendString(_T("open res/e.mp3 alias e"), NULL, 0, NULL);
	mciSendString(_T("open res/f.mp3 alias f"), NULL, 0, NULL);
	mciSendString(_T("open res/g.mp3 alias g"), NULL, 0, NULL);
	mciSendString(_T("open res/a.mp3 alias a"), NULL, 0, NULL);
	mciSendString(_T("open res/b.mp3 alias b"), NULL, 0, NULL);

	mciSendString(_T("open res/c1.mp3 alias c1"), NULL, 0, NULL);
	mciSendString(_T("open res/d1.mp3 alias d1"), NULL, 0, NULL);
	mciSendString(_T("open res/e1.mp3 alias e1"), NULL, 0, NULL);
	mciSendString(_T("open res/f1.mp3 alias f1"), NULL, 0, NULL);
	mciSendString(_T("open res/g1.mp3 alias g1"), NULL, 0, NULL);
	mciSendString(_T("open res/a1.mp3 alias a1"), NULL, 0, NULL);
	mciSendString(_T("open res/b1.mp3 alias b1"), NULL, 0, NULL);

	mciSendString(_T("open res/c2.mp3 alias c2"), NULL, 0, NULL);
	mciSendString(_T("open res/d2.mp3 alias d2"), NULL, 0, NULL);
	mciSendString(_T("open res/e2.mp3 alias e2"), NULL, 0, NULL);
	mciSendString(_T("open res/f2.mp3 alias f2"), NULL, 0, NULL);
	mciSendString(_T("open res/g2.mp3 alias g2"), NULL, 0, NULL);
	mciSendString(_T("open res/a2.mp3 alias a2"), NULL, 0, NULL);
	mciSendString(_T("open res/b2.mp3 alias b2"), NULL, 0, NULL);

	mciSendString(_T("open res/cs.mp3 alias cs"), NULL, 0, NULL);
	mciSendString(_T("open res/ds.mp3 alias ds"), NULL, 0, NULL);
	mciSendString(_T("open res/fs.mp3 alias fs"), NULL, 0, NULL);
	mciSendString(_T("open res/gs.mp3 alias gs"), NULL, 0, NULL);
	mciSendString(_T("open res/as.mp3 alias as"), NULL, 0, NULL);

	mciSendString(_T("open res/c1s.mp3 alias c1s"), NULL, 0, NULL);
	mciSendString(_T("open res/d1s.mp3 alias d1s"), NULL, 0, NULL);
	mciSendString(_T("open res/f1s.mp3 alias f1s"), NULL, 0, NULL);
	mciSendString(_T("open res/g1s.mp3 alias g1s"), NULL, 0, NULL);
	mciSendString(_T("open res/a1s.mp3 alias a1s"), NULL, 0, NULL);

	mciSendString(_T("open res/c2s.mp3 alias c2s"), NULL, 0, NULL);
	mciSendString(_T("open res/d2s.mp3 alias d2s"), NULL, 0, NULL);
	mciSendString(_T("open res/f2s.mp3 alias f2s"), NULL, 0, NULL);
	mciSendString(_T("open res/g2s.mp3 alias g2s"), NULL, 0, NULL);
	mciSendString(_T("open res/a2s.mp3 alias a2s"), NULL, 0, NULL);
}

void on_draw()
{
	putimage(0, 0, &img_background);

	if (is_record)
	{
		outtextxy(getwidth() / 2 - 200, getheight() / 2, "厮序秘芝村庁塀��壅肝梓指概潤崩芝村旺處怙");
	}
}



int main()
{
	initgraph(1280, 720);

	Load_Resource();

	// music_player.set_music_source(music_resource.getMusic(Canon).source);
	// music_player.set_interval(music_resource.getMusic(Canon).interval);
	music_player.set_start(true);
	// can_play = false;

	ExMessage msg;

	BeginBatchDraw();

	while (1)
	{
		DWORD begin_time = GetTickCount();

		while (can_play && peekmessage(&msg))
		{
			if (is_record)
			{
				if (msg.message == WM_KEYFIRST)
				{
					music_player.music_note_push_back(vkcode_to_char(msg.vkcode));
					std::cout << vkcode_to_char(msg.vkcode) << std::endl;
					// music_player.music_note_push_back(msg.ch);
					// std::cout << msg.ch << std::endl;
				}
			}

			switch (msg.message)
			{
			case WM_KEYDOWN:
				switch (msg.vkcode)
				{
				case VK_RETURN:	//俳算庁塀
					if (!is_record)
					{
						is_record = true;
						music_player.reset();
						// can_play = true;
					}
					else
					{
						is_record = false;
						can_play = false;
						music_player.set_interval(200);
						music_player.set_start(true);
					}
					break;

				case VK_SPACE:
					break;
				case 0x5A:	//z
					mciSendString(_T("play c from 0"), NULL, 0, NULL);
					std::cout << "c" << std::endl;
					break;
				case 0x58:	//x
					mciSendString(_T("play d from 0"), NULL, 0, NULL);
					std::cout << "d" << std::endl;
					break;
				case 0x43:	//c
					mciSendString(_T("play e from 0"), NULL, 0, NULL);
					std::cout << "e" << std::endl;
					break;
				case 0x56:	//v
					mciSendString(_T("play f from 0"), NULL, 0, NULL);
					std::cout << "f" << std::endl;
					break;
				case 0x4D:	//m
					mciSendString(_T("play g from 0"), NULL, 0, NULL);
					std::cout << "g" << std::endl;
					break;
				case VK_OEM_COMMA:	//,
					mciSendString(_T("play a from 0"), NULL, 0, NULL);
					std::cout << "a" << std::endl;
					break;
				case VK_OEM_PERIOD:	//.
					mciSendString(_T("play b from 0"), NULL, 0, NULL);
					std::cout << "b" << std::endl;
					break;


				case 0x41:	//a
					mciSendString(_T("play c1 from 0"), NULL, 0, NULL);
					std::cout << "c1" << std::endl;
					break;
				case 0x53:	//s
					mciSendString(_T("play d1 from 0"), NULL, 0, NULL);
					std::cout << "d1" << std::endl;
					break;
				case 0x44:	//d
					mciSendString(_T("play e1 from 0"), NULL, 0, NULL);
					std::cout << "e1" << std::endl;
					break;
				case 0x46:	//f
					mciSendString(_T("play f1 from 0"), NULL, 0, NULL);
					std::cout << "f1" << std::endl;
					break;
				case 0x4A:	//j
					mciSendString(_T("play g1 from 0"), NULL, 0, NULL);
					std::cout << "g1" << std::endl;
					break;
				case 0x4B:	//k
					mciSendString(_T("play a1 from 0"), NULL, 0, NULL);
					std::cout << "a1" << std::endl;
					break;
				case 0x4C:	//l
					mciSendString(_T("play b1 from 0"), NULL, 0, NULL);
					std::cout << "b1" << std::endl;
					break;


				case 0x51:	//q
					mciSendString(_T("play c2 from 0"), NULL, 0, NULL);
					std::cout << "c2" << std::endl;
					break;
				case 0x57:	//w
					mciSendString(_T("play d2 from 0"), NULL, 0, NULL);
					std::cout << "d2" << std::endl;
					break;
				case 0x45:	//e
					mciSendString(_T("play e2 from 0"), NULL, 0, NULL);
					std::cout << "e2" << std::endl;
					break;
				case 0x52:	//r
					mciSendString(_T("play f2 from 0"), NULL, 0, NULL);
					std::cout << "f2" << std::endl;
					break;
				case 0x55:	//u
					mciSendString(_T("play g2 from 0"), NULL, 0, NULL);
					std::cout << "g2" << std::endl;
					break;
				case 0x49:	//i
					mciSendString(_T("play a2 from 0"), NULL, 0, NULL);
					std::cout << "a2" << std::endl;
					break;
				case 0x4F:	//o
					mciSendString(_T("play b2 from 0"), NULL, 0, NULL);
					std::cout << "b2" << std::endl;
					break;


				case 0x42:	//b
					mciSendString(_T("play cs from 0"), NULL, 0, NULL);
					std::cout << "cs" << std::endl;
					break;
				case 0x4E:	//n
					mciSendString(_T("play ds from 0"), NULL, 0, NULL);
					std::cout << "ds" << std::endl;
					break;
				case 0x31:	//1
					mciSendString(_T("play fs from 0"), NULL, 0, NULL);
					std::cout << "fs" << std::endl;
					break;
				case 0x32:	//2
					mciSendString(_T("play gs from 0"), NULL, 0, NULL);
					std::cout << "gs" << std::endl;
					break;
				case 0x33:	//3
					mciSendString(_T("play as from 0"), NULL, 0, NULL);
					std::cout << "as" << std::endl;
					break;


				case 0x47:	//g
					mciSendString(_T("play c1s from 0"), NULL, 0, NULL);
					std::cout << "c1s" << std::endl;
					break;
				case 0x48:	//h
					mciSendString(_T("play d1s from 0"), NULL, 0, NULL);
					std::cout << "d1s" << std::endl;
					break;
				case 0x34:	//4
					mciSendString(_T("play f1s from 0"), NULL, 0, NULL);
					std::cout << "f1s" << std::endl;
					break;
				case 0x35:	//5
					mciSendString(_T("play g1s from 0"), NULL, 0, NULL);
					std::cout << "g1s" << std::endl;
					break;
				case 0x36:	//6
					mciSendString(_T("play a1s from 0"), NULL, 0, NULL);
					std::cout << "a1s" << std::endl;
					break;


				case 0x54:	//t
					mciSendString(_T("play c2s from 0"), NULL, 0, NULL);
					std::cout << "c2s" << std::endl;
					break;
				case 0x59:	//y
					mciSendString(_T("play d2s from 0"), NULL, 0, NULL);
					std::cout << "d2s" << std::endl;
					break;
				case 0x37:	//7
					mciSendString(_T("play f2s from 0"), NULL, 0, NULL);
					std::cout << "f2s" << std::endl;
					break;
				case 0x38:	//8
					mciSendString(_T("play g2s from 0"), NULL, 0, NULL);
					std::cout << "g2s" << std::endl;
					break;
				case 0x39:	//9
					mciSendString(_T("play a2s from 0"), NULL, 0, NULL);
					std::cout << "a2s" << std::endl;
					break;
				}
				break;

			default:
				break;
			}
		}

		static DWORD last_time = GetTickCount();
		DWORD current_time = GetTickCount();
		
		music_player.on_update(current_time - last_time);
		music_player.on_play();
		if (is_over)
		{
			can_play = true;
			is_record = false;
			is_over = false;
			music_player.reset();
		}

		last_time = current_time;
		
		cleardevice();
		on_draw();
		FlushBatchDraw();

		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - begin_time;
		if (delta_time <= 1000 / FPS)
		{
			Sleep(1000 / FPS - delta_time);
		}
	}

	EndBatchDraw();

	return 0;
}