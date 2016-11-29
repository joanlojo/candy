/******************************************************************
* Copyright (C) 2016 Jordi Serrano Berbel <jsberbel95@gmail.com> *
* This can not be copied, modified and/or distributed without    *
* express permission of the copyright owner.                     *
******************************************************************/

#include "GUI.hh"
#include "System.hh"
#include "Logger.hh"
#include "GameScene.hh"
#include "OtherScene.hh"
using namespace Logger;
bool vel = false;

#define CELL_WIDTH 80
#define CELL_HEIGHT 80
GameScene::GameScene(void) : m_grid("lvl/testLvl.dat", CELL_WIDTH, CELL_HEIGHT) {
	m_background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::BG_00 }; //defines el background con el tama�o y ID
	pj = { { 0, 0, W.GetWidth()/4, W.GetHeight()/4 }, ObjectID::BG_04 };
	bala = { { pj.transform.x, pj.transform.y, W.GetWidth() / 6, W.GetHeight() / 6 }, ObjectID::BG_05 };
}

GameScene::~GameScene(void){
}

void GameScene::OnEntry(void) {
}

void GameScene::OnExit(void) {
}

void GameScene::Update(void) {
	static MouseCoords mouseCoords(0,0);
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) { //compruevas la tecla apretada del mouse con la instancia de Input Manager
		Println("===============");
		Println("mxp: ", mouseCoords);
		mouseCoords = IM.GetMouseCoords();
	} else if (IM.IsMouseUp<MOUSE_BUTTON_LEFT>()) {
		Println("mxn: ", IM.GetMouseCoords());
		m_grid.CheckMouseSwift(mouseCoords, IM.GetMouseCoords());
	}
	m_grid.Update(m_score); // Update grid
	// Test InputManager key methods
	if (IM.IsKeyHold<'a'>()) Println("a hold");
	if (IM.IsKeyDown<'0'>()) Println("0 down");
	if (IM.IsKeyUp<KEY_BUTTON_DOWN>()) Println("down arrow up");
	if (IM.IsKeyUp<KEY_BUTTON_ESCAPE>()) {
		SM.SetCurScene<OtherScene>();
	}
	
	if (IM.IsKeyHold<KEY_BUTTON_DOWN>()) {
		pj.transform.y += TM.GetDeltaTime();
		bala.transform.y = pj.transform.y;
	}
	if (IM.IsKeyHold<KEY_BUTTON_UP>()) {
		pj.transform.y-= TM.GetDeltaTime();
		bala.transform.y = pj.transform.y;
	}
	 if (IM.IsKeyHold<KEY_BUTTON_RIGHT>()) {
		pj.transform.x+= TM.GetDeltaTime();
		bala.transform.x = pj.transform.x;
	}
	 if (IM.IsKeyHold<KEY_BUTTON_LEFT>()) {
		pj.transform.x-= TM.GetDeltaTime();
		bala.transform.x = pj.transform.x;
	}
	 if (IM.IsKeyHold<KEY_BUTTON_ENTER>()) {
		 bala.transform.x += 1;
		
	 }
}

void GameScene::Draw(void) {
	m_background.Draw(); // Render background
	//m_grid.Draw(); // Render grid
	bala.Draw();
	pj.Draw();
	
	GUI::DrawTextShaded<FontID::FACTORY>("ENTI CRUSH",
										{ W.GetWidth() >> 1, int(W.GetHeight()*.1f), 1, 1 }, 
										{ 190, 0, 160 }, { 50, 200, 230 }); // Render score that will be different when updated
	GUI::DrawTextBlended<FontID::CANDY>("Score: " + std::to_string(m_score), 
										{ W.GetWidth() >> 1, int(W.GetHeight()*.9f), 1, 1 }, 
										{ 115, 0, 180 }); // Render score that will be different when updated

}
