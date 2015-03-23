#pragma once

enum states
{
	mainMenu = 1,
	mapMode = 2
};

class StateManager
{
public:
	StateManager();
	~StateManager();

	inline void SwitchState(int newState){ currentState = newState; }

	inline int GetState(){ return currentState; }

private:

	int currentState = 1;
};
