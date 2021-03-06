#pragma once

// If Windows and not in Debug, this will run without a console window
// You can use this to output information when debugging using cout or cerr
#ifdef WIN32 
	#ifndef _DEBUG
		#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
	#endif
#endif

// Include S2D and use namespace
#include "Sounds.h"
#include "S2D/S2D.h"
using namespace S2D;

// Include our types
#include "MenuState.h"
#include "Player.h"
#include "Cherry.h"
#include "Munchie.h"
#include "Wall.h"
#include "GhostEnemy.h"

// Screen width and height
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 658
#define GAME_OVER_SCORE_X 263
#define GAME_OVER_SCORE_Y 360

// Number of entities of each type to spawn
#define MUNCHIE_COUNT 50
#define CHERRY_COUNT 10
#define WALL_COUNT 30
#define GHOST_COUNT 4

// Declares the Pacman class which inherits from the Game class.
// This allows us to overload the Game class methods to help us
// load content, draw and update our game.
class Pacman : public Game
{
private:
	// Structs for menu data and sounds
	MenuState _menu;
	Sounds _sounds;

	// Data to represent Pacman
	Player* _player;

	// Data to represent munchies, walls and ghosts
	Munchie* _munchies[MUNCHIE_COUNT];
	Cherry* _cherries[CHERRY_COUNT];
	Wall* _walls[WALL_COUNT];
	GhostEnemy* _ghosts[GHOST_COUNT];

	// Global textures
	Texture2D* _munchieTexture;
	Texture2D* _cherryTexture;
	Texture2D* _wallTexture;
	Texture2D* _ghostTexture;

	// Current number of collisions
	int _collisionCount;
	
	// Position for score display
	Vector2* _gameScorePosition;
	Vector2* _gameOverScorePosition;

	/// <summary> Check the start menu input </summary>
	void CheckStart(Input::KeyboardState* keyboardState, Input::Keys startKey);

	/// <summary> Check the pause menu input </summary>
	void CheckPaused(Input::KeyboardState* keyboardState, Input::Keys pauseKey);

	/// <summary> Check the pause menu input </summary>
	void CheckQuit(Input::KeyboardState* keyboardState);

	/// <summary> Check and handle collisions between pacman and munchies </summary>
	void CheckFoodCollisions();
	
	/// <summary> Check and handle collisions between pacman and walls </summary>
	bool CheckWallCollisions(int x, int y, int width, int height);

	/// <summary> Randomises the positions of the munchies, cherries and walls </summary>
	void SetRandomEntityPositions();
	
	/// <summary> Update movement of ghosts </summary>
	void UpdateGhosts(int elapsedTime);
	void CheckPlayerCollisions(int elapsedTime);

public:
	/// <summary> Constructs the Pacman class. </summary>
	Pacman(int argc, char* argv[]);

	/// <summary> Destroys any data associated with Pacman class. </summary>
	virtual ~Pacman();

	/// <summary> All content should be loaded in this method. </summary>
	void virtual LoadContent();

	/// <summary> Called every frame - update game logic here. </summary>
	void virtual Update(int elapsedTime);

	/// <summary> Called every frame - draw game here. </summary>
	void virtual Draw(int elapsedTime);
};