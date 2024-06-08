#pragma once

#include <graphics.h>

char vkcode_to_char(int vk)
{
	char ret = ' ';

	switch (vk)
	{
	case VK_SPACE:	//' '
		ret = ' ';
		break;

	case 0x5A:	//z
		ret = 'z';
		break;
	case 0x58:	//x
		ret = 'x';
		break;
	case 0x43:	//c
		ret = 'c';
		break;
	case 0x56:	//v
		ret = 'v';
		break;
	case 0x4D:	//m
		ret = 'm';
		break;
	case VK_OEM_COMMA:	//,
		ret = ',';
		break;
	case VK_OEM_PERIOD:	//.
		ret = '.';
		break;


	case 0x41:	//a
		ret = 'a';
		break;
	case 0x53:	//s
		ret = 's';
		break;
	case 0x44:	//d
		ret = 'd';
		break;
	case 0x46:	//f
		ret = 'f';
		break;
	case 0x4A:	//j
		ret = 'j';
		break;
	case 0x4B:	//k
		ret = 'k';
		break;
	case 0x4C:	//l
		ret = 'l';
		break;


	case 0x51:	//q
		ret = 'q';
		break;
	case 0x57:	//w
		ret = 'w';
		break;
	case 0x45:	//e
		ret = 'e';
		break;
	case 0x52:	//r
		ret = 'r';
		break;
	case 0x55:	//u
		ret = 'u';
		break;
	case 0x49:	//i
		ret = 'i';
		break;
	case 0x4F:	//o
		ret = 'o';
		break;


	case 0x42:	//b
		ret = 'b';
		break;
	case 0x4E:	//n
		ret = 'n';
		break;
	case 0x31:	//1
		ret = '1';
		break;
	case 0x32:	//2
		ret = '2';
		break;
	case 0x33:	//3
		ret = '3';
		break;


	case 0x47:	//g
		ret = 'g';
		break;
	case 0x48:	//h
		ret = 'h';
		break;
	case 0x34:	//4
		ret = '4';
		break;
	case 0x35:	//5
		ret = '5';
		break;
	case 0x36:	//6
		ret = '6';
		break;


	case 0x54:	//t
		ret = 't';
		break;
	case 0x59:	//y
		ret = 'y';
		break;
	case 0x37:	//7
		ret = '7';
		break;
	case 0x38:	//8
		ret = '8';
		break;
	case 0x39:	//9
		ret = '9';
		break;
	}

	return ret;
}
