#pragma once

#include <functional>

class Timer
{
public:

	Timer() = default;
	~Timer() = default;

	void set_oneshot(bool in)
	{
		oneshot = in;
	}

	void set_wait_time(int time)
	{
		wait_time = time;
	}

	void set_shot_callback(std::function < void() > callback)
	{
		shot_callback = callback;
	}

	void restart()
	{
		pass_time = 0;
		shotted = false;
	}
	

	void on_update(int delta)
	{
		pass_time += delta;

		if (pass_time >= wait_time)
		{
			if (((oneshot && !shotted) || !oneshot) && shot_callback)
				shot_callback();

			shotted = true;

			if (!oneshot)
				pass_time -= wait_time;
			else
				pass_time = 0;
		}
	}


private:

	int wait_time = 0;	//�ȴ�ʱ�䣨shot���ڣ�
	int pass_time = 0;	//�ѹ�ʱ��
	bool oneshot = false;
	bool shotted = false;
	std::function <void()> shot_callback;

};

