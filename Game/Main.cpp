#include "Player.h"
#include "Enemy.h"
#include "Spray.h"
#include "Engine.h"
#include "Shooty.h"
#include <iostream>

using namespace std;
using namespace digi;


int main() {

	initMem();
	SetFilepath("../Assets");
	g_Innie.Initialize();
	g_Ren.Initialize();
	g_Miku.Initialize();
	g_Ren.CreateWindow(800, 600, "Funny Joke Name");

	{
		Shooty game;
		game.Initialize();

		bool quit = false;
		while (!quit) {
			game.Update();
			g_Ren.BeginFrame();

			game.Draw(g_Ren);

			g_Ren.EndFrame();
			quit = g_Innie.GetKeyDown(key_escape);
		}
	}
	g_Ren.Shutdown();
	g_Miku.Shutdown();
}