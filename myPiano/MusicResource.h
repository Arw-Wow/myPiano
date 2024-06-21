#pragma once

#include <string>

enum MusicName
{
	Under_Tale, Name_Unkown, Air, Castle_in_the_Sky, Always_with_me, Jingle_Bells, Canon, Far_Sky
};

struct Music
{
	std::string source[10];
	int interval;
};

class MusicResource
{
public:
	MusicResource()
	{

		music_under_tale.source[0] = "   a j f a d  d  f   a f a d  d  f a j f a d  d  f   a f k j  f  j   ";
		music_under_tale.interval = 200;

		music_name_unknown.source[0] = "   e  u w w q quw w q leq q l k ddqqlljj   ";
		music_name_unknown.interval = 400;

		music_air.source[0] = "   .    g s k 4   4 d4            d 4 k d g s g   g .1            .   g s k 4   4 d4            d 4 k d 4 w t  l  4       d 4   k   l   t   7 7 7 e7            e 7 i e t w t   t l4            l   t w i 7   7 e7            e 7 i e 7    ";
		music_air.interval = 200;

		music_castle_in_the_sky.source[0] = "   s df  df k d     z s  as f a    ";
		music_castle_in_the_sky.interval = 350;

		music_always_with_me.source[0] = "   asdaj  ds j s a,, .am   ";
		music_always_with_me.interval = 330;

		music_jingle_bells.source[0] = "   ddd ddd djasd   fff fdd dssds j ddd ddd djasd   fff fdd jjfsa   ";
		music_jingle_bells.interval = 350;

		music_canon.source[0] = "   a d j q m s j l , a d k c . a j v , a f z m a d v , a f m . a j e d j q w . s j q a d k l e u i r e w r e w q l k j f d s f d s a s d f . s j f d k j f j f d s a , k l q l k j f d s k j k j u eru erujklqwere qwe dfjkjfj     ";
		music_canon.source[1] = "                                                                   a       m       ,       c       v       z       v       m       m       m       ,       c       v       z       v             d       m       ,       .         ";
		music_canon.interval = 250;
		
		music_far_sky.source[0] = "   4 l               k d               4 l   w i       twtkd4k   . , .   4 g  sg,.  gsdklk   .   4 k g , .   2 d 4 g .   4 g  sg,.  gsdklk   .   4 k g , .  ,g .             4 k l   klk   d 4 k g s   sd4  4d4d   sd4 j k 6 l t l   klk   d 4 k t w e 7 7   ewt   ktw  wtl6 l t 7   ewt k 4 l     ";
		music_far_sky.source[1] = "   s                 d                 s                             1     ,     m     s     1     d     1   c g     1   m ,     m     4     1   m d     1     1                  x.    c,    cd    1,     .    b,    x1.1x b136  x.    c,    c,g,  1,     xcm  bc,1  x1.1  bc3   x. 1  bc,1       ";
		music_far_sky.source[2] = "                                                                     x     c     x           x     .           3     x  x  1     x     g     x  x  .     c     n                   1     c     g     1     m     c             4   1     c           1                             1               ";
		music_far_sky.source[3] = "                                                                                                               b                                                                   x     b     .     x     x     b             g   x     b           x                             x               ";
		music_far_sky.source[4] = "   ";
		music_far_sky.source[5] = "   ";
		music_far_sky.source[6] = "   ";
		music_far_sky.source[7] = "   ";
		music_far_sky.source[8] = "   ";
		music_far_sky.source[9] = "   ";
		music_far_sky.interval = 250;
	}

	const Music& getMusic(MusicName in)
	{
		Music* get = nullptr;
		switch (in)	
		{
		case Under_Tale:
			get = &music_under_tale;
			break;
		case Name_Unkown:
			get = &music_name_unknown;
			break;
		case Air:
			get = &music_air;
			break;
		case Castle_in_the_Sky:
			get = &music_castle_in_the_sky;
			break;
		case Always_with_me:
			get = &music_always_with_me;
			break;
		case Jingle_Bells:
			get = &music_jingle_bells;
			break;
		case Canon:
			get = &music_canon;
			break;
		case Far_Sky:
			get = &music_far_sky;
			break;
		default:
			break;
		}

		return *get;
	}

private:

	Music music_under_tale;					// 传说之下
	Music music_name_unknown;				// 伤感音乐
	Music music_air;						// 鸟之诗
	Music music_castle_in_the_sky;			// 天空之城
	Music music_always_with_me;				// 千与千寻
	Music music_jingle_bells;				// 圣诞歌
	Music music_canon;						// 卡农
	Music music_far_sky;					// 远空(?)

};
