#include <locale>
#include <codecvt>
#include <string>
#include <chrono>

#include "Main.h"
#include "Screen.h"
#include "PlayerCharacter.h"
#include "GameObject.h"
#include "Transform.h"
#include "GameComponent.h"
#include "Renderer.h"
#include "WindowsScreenBuffer.h"

using namespace std;

int main()
{
	// vars for storing delta time
	auto tp1 = chrono::system_clock::now();
	auto tp2 = chrono::system_clock::now();

	// Create Screen Buffer
	Screen::screen = new wchar_t[Screen::screenSizeX * Screen::screenSizeY];
	ScreenBuffer *screenBuffer;
#if defined(_WIN64) || defined(_WIN32)
	screenBuffer = &WindowsScreenBuffer();
#elif defined(__APPLE__)
	screenBuffer = &AppleScreenBuffer();
#elif defined(__linux__)
	screenBuffer = &LinuxScreenBuffer();
#elif defined(__unix__)
	screenBuffer = &UnixScreenBuffer();
#else
#   error "Unknown platform"
#endif

	// Setup game
	Game::activeScene = Scene();

	wstring playerGfx;
	playerGfx += LR"( __  @    /)";
	playerGfx += LR"(|  | .   / )";
	playerGfx += LR"(\__/ .  O  )";
	playerGfx += LR"(    / \    )";
	playerGfx += LR"(    L  L   )";

	GameObject player = GameObject("Player");
	player.AddComponent<PlayerCharacter>();
	player.renderer->SetGraphic(playerGfx, 11, 5);
	player.transform->x = 10;
	player.transform->y = 10;

	while (1)
	{
		// Update delta time
		tp2 = chrono::system_clock::now();
		chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		Time::deltaTime = elapsedTime.count();

		// Update Game Objects
		Game::activeScene.Update();
		Game::activeScene.Render();

		// Refresh the screen
		screenBuffer->Refresh();
	}

	return 0;
}