#pragma once
#include "Scene.hh"
#include "Sprite.hh"

class OtherScene : public Scene
{
public:
	explicit OtherScene();
	~OtherScene() override;
	void OnEntry(void) override; 
	void OnExit(void) override;  
	void Update(void) override; 
	void Draw(void) override;   
private:
	Sprite background; //en algun lado hay q decir q background es
	Sprite play;
	Sprite exit;

};