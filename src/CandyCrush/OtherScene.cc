#include "OtherScene.hh"
#include "ID.hh"
#include "InputManager.hh"
#include "Logger.hh"
#include "GameScene.hh"
#include "SceneManager.hh"
using namespace Logger;


OtherScene::OtherScene() {
	play = { { 450,250,W.GetWidth() / 6, W.GetHeight() / 6 }, ObjectID::BG_02 };
	exit = { { 450,550,W.GetWidth() / 6, W.GetHeight() / 6 }, ObjectID::BG_03 };
	background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::BG_01 }; //defines el background de la escena, instanciando a window para el tamaño y con la clase ID dices q el tipo es background

}
OtherScene::~OtherScene() {
}
void OtherScene::OnEntry(void) {
}
void OtherScene::OnExit(void) {
}
void OtherScene::Update(void) {
	static MouseCoords mouseCoords(0, 0);
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		mouseCoords = IM.GetMouseCoords();
		//play button
		if ((mouseCoords.x >= 460 && mouseCoords.x<=606) && (mouseCoords.y >=260 && mouseCoords.y <=360)) {
			//cambio esceca
			printf("play");
			SM.SetCurScene<GameScene>();
		}
		else if ((mouseCoords.x >= 455 && mouseCoords.x <= 616) && (mouseCoords.y >= 555 && mouseCoords.y <= 670)) {
			printf("exit");
			SetState<SceneState::EXIT>();
		}
	}
	
}
void OtherScene::Draw(void) {
	background.Draw();
	play.Draw();
	exit.Draw();
	
}