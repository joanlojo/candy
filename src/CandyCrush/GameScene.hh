/******************************************************************
* Copyright (C) 2016 Jordi Serrano Berbel <jsberbel95@gmail.com> *
* This can not be copied, modified and/or distributed without    *
* express permission of the copyright owner.                     *
******************************************************************/

#pragma once
#include "Grid.hh"
#include "Scene.hh"

// GameScene class with the main gameplay mode
class GameScene : public Scene {
public:
	explicit GameScene();
	~GameScene() override;
	void OnEntry(void) override; //
	void OnExit(void) override;  //
	void Update(void) override;  // lo mismo que en Scene?
	void Draw(void) override;   //
private:
	Grid m_grid;
	Sprite m_background;
	Sprite pj;
	Sprite bala;
	int m_score{ 0 };
};