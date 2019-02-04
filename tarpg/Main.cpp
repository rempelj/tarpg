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

int main()
{
	// vars for storing delta time
	auto tp1 = std::chrono::system_clock::now();
	auto tp2 = std::chrono::system_clock::now();

	// Create Screen Buffer
	Screen::screen = new wchar_t[Screen::screenSizeX * Screen::screenSizeY];
#if defined(_WIN64) || defined(_WIN32)
	WindowsScreenBuffer screenBuffer = WindowsScreenBuffer();
#elif defined(__APPLE__)
	AppleScreenBuffer = screenBuffer = AppleScreenBuffer();
#elif defined(__linux__)
	LinuxScreenBuffer = screenBuffer = LinuxScreenBuffer();
#elif defined(__unix__)
	UnixScreenBuffer = screenBuffer = UnixScreenBuffer();
#else
#   error "Unknown platform"
#endif

	// Setup game
	Game::activeScene = Scene();

	std::wstring playerGfx;
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
		tp2 = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		Time::deltaTime = elapsedTime.count();

		// Update Game Objects
		Game::activeScene.Update();
		Game::activeScene.Render();

		// Refresh the screen
		screenBuffer.Refresh();
	}

	return 0;
}