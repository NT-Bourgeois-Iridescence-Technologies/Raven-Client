#include "MenuState.h"
#include <GFX/RenderCore.h>
#include <Utilities/Input.h>
#include "../Config.h"
#include "ClientState.h"

MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}

Audio::AudioClip* btn;
void exitHandler() {
	btn->Stop();
	btn->Play(7);


#if CURRENT_PLATFORM == PLATFORM_PSP
	sceKernelExitGame();
#else
	exit(0);
#endif
}

bool switchToClient = false;
void sspHandler() {
	btn->Stop();
	btn->Play(7);

	parseClientConfig();
	g_Config.ip = "127.0.0.1";
	g_Config.port = 1337;

	//Launch craft server - (PC only for now)
	//Wait for now

	//Switch State
	switchToClient = true;
}

void smpHandler() {
	btn->Stop();
	btn->Play(7);

	parseClientConfig();
	//Switch State
	switchToClient = true;
}

void dummyHandler() {
	btn->Stop();
	btn->Play(7);
}



void MenuState::init()
{
	g_TranslationOBJ.init();
	g_TranslationOBJ.setTranslation("en_us");

	GFX::UI::textVShift = 3;
	GFX::g_RenderCore->setClearColor(0.f, 0.f, 0.f, 1.f);

	cam = new GFX::Render3D::Camera({ 0, 0, 0 }, { 0, 0, 0 }, 90.0f, 480.0f / 272.0f, 0.1f, 1000.0f);
	GFX::g_RenderCore->bindCamera(cam);

	std::array<std::string, 6> tex;
	for(int i = 0; i < 6; i++){
		tex[i] = "./assets/minecraft/textures/gui/title/background/panorama_" + std::to_string(i) + ".png";
	}

	Utilities::g_AppTimer.deltaTime();
	panorama = new GFX::Render3D::Skybox(tex, 0.5f);

	logoTexture = GFX::g_TextureManager->loadTex("./assets/minecraft/textures/gui/title/raven.png", GFX_FILTER_LINEAR, GFX_FILTER_LINEAR, false);
	logoSprite = new GFX::Render2D::Sprite(logoTexture);
	logoSprite->setScale(0.75f, 0.75f);
	logoSprite->setPosition( 240, 72);

	textRender = new GFX::UI::TextRenderer();
	textRender->init("./assets/fonts/font.pgf");

	widgets = GFX::g_TextureManager->loadTex("./assets/minecraft/textures/gui/widgets.png", GFX_FILTER_NEAREST, GFX_FILTER_NEAREST, false);

	unselected = new GFX::Render2D::Sprite(widgets, { 0, 66 }, { 200, 20 });
	unselected->setPosition(240, 136);
	selected = new GFX::Render2D::Sprite(widgets, { 0, 86 }, { 200, 20 });
	selected->setPosition(240, 136);

	halfUnselected = new GFX::Render2D::Sprite(widgets, { 0, 66 }, { 200, 20 });
	halfUnselected->setPosition(240, 136);
	halfUnselected->setScale(0.475f, 1.0f);
	halfSelected = new GFX::Render2D::Sprite(widgets, { 0, 86 }, { 200, 20 });
	halfSelected->setPosition(240, 136);
	halfSelected->setScale(0.475f, 1.0f);

	quitButton = new GFX::UI::UIButton(halfSelected, halfUnselected, { 100, 20 }, textRender, exitHandler);
	quitButton->setPosition(240 + 52, 232);
	quitButton->setText(g_TranslationOBJ.getText("menu.quit"), { 255, 255, 255, 255, TEXT_SIZE, TEXT_RENDERER_CENTER, TEXT_RENDERER_CENTER, 0.0f, true });

	optionButton = new GFX::UI::UIButton(halfSelected, halfUnselected, { 100, 20 }, textRender, dummyHandler);
	optionButton->setPosition(240 - 52, 232);
	optionButton->setText(g_TranslationOBJ.getText("menu.options"), { 255, 255, 255, 255, TEXT_SIZE, TEXT_RENDERER_CENTER, TEXT_RENDERER_CENTER, 0.0f, true });

	sspButton = new GFX::UI::UIButton(selected, unselected, { 200, 20 }, textRender, sspHandler);
	sspButton->setPosition(240, 136);
	sspButton->setText(g_TranslationOBJ.getText("menu.singleplayer"), { 255, 255, 255, 255, TEXT_SIZE, TEXT_RENDERER_CENTER, TEXT_RENDERER_CENTER, 0.0f, true });

	smpButton = new GFX::UI::UIButton(selected, unselected, { 200, 20 }, textRender, smpHandler);
	smpButton->setPosition(240, 164);
	smpButton->setText(g_TranslationOBJ.getText("menu.multiplayer"), { 255, 255, 255, 255, TEXT_SIZE, TEXT_RENDERER_CENTER, TEXT_RENDERER_CENTER, 0.0f, true });

	mcrButton = new GFX::UI::UIButton(selected, unselected, { 200, 20 }, textRender, dummyHandler);
	mcrButton->setPosition(240, 192);
	mcrButton->setText(g_TranslationOBJ.getText("menu.online"), { 255, 255, 255, 255, TEXT_SIZE, TEXT_RENDERER_CENTER, TEXT_RENDERER_CENTER, 0.0f, true });

	mus = new Audio::AudioClip("./assets/music/menu" + std::to_string(rand() % 3 + 1) + SYSTEM_AUDIO_EXT, true);
	btn = new Audio::AudioClip("./assets/sounds/click.wav", false);

	mus->Play();
	vsel = 0;

	if (Utilities::getCursorPos().x < 0 && Utilities::getCursorPos().y < 0){
		sspButton->select();
	}
}




void MenuState::cleanup()
{
	delete quitButton;
	delete unselected;
	delete selected;
	GFX::g_TextureManager->deleteTex(widgets);
	textRender->cleanup();
	delete cam;
	cam = NULL;
	GFX::g_RenderCore->bindCamera(NULL);
	delete logoSprite;
	delete textRender;
	delete panorama;
	GFX::g_TextureManager->deleteTex(logoTexture);
}

void MenuState::enter()
{

}

void MenuState::pause()
{
	mus->Stop();
}

void MenuState::resume()
{
}

void MenuState::update(GameStateManager* st)
{
	if(switchToClient){
		ClientState* state = new ClientState();
		state->init();
		st->addState(state);
		return;
	}

	double dt =	Utilities::g_AppTimer.deltaTime();
	cam->rot.y += dt * (360.0f / 180.0f);
	cam->rot.x = sinf((cam->rot.y + 90) / 180 * 3.14159) * 30.0f + 5.0f;
	cam->update();
	GFX::g_RenderCore->bindCamera(cam);


	quitButton->update();
	optionButton->update();
	mcrButton->update();
	sspButton->update();
	smpButton->update();

	bool changeTrigger = false;
	if (Utilities::KeyPressed(PSP_CTRL_DOWN)) {
		vsel++;

		if (vsel > 4) {
			vsel = 4;
		}
		changeTrigger = true;
	}
	if (Utilities::KeyPressed(PSP_CTRL_UP)) {
		vsel--;

		if (vsel < 0) {
			vsel = 0;
		}
		changeTrigger = true;
	}

	if(changeTrigger){
		switch (vsel) {
		case 0:
			sspButton->select();
			smpButton->unselect();
			mcrButton->unselect();
			optionButton->unselect();
			quitButton->unselect();
			break;

		case 1:
			sspButton->unselect();
			smpButton->select();
			mcrButton->unselect();
			optionButton->unselect();
			quitButton->unselect();
			break;

		case 2:
			sspButton->unselect();
			smpButton->unselect();
			mcrButton->select();
			optionButton->unselect();
			quitButton->unselect();
			break;

		case 3:
			sspButton->unselect();
			smpButton->unselect();
			mcrButton->unselect();
			optionButton->select();
			quitButton->unselect();
			break;

		case 4:
			sspButton->unselect();
			smpButton->unselect();
			mcrButton->unselect();
			optionButton->unselect();
			quitButton->select();
			break;
		}
	}

	if (Utilities::KeyPressed(PSP_CTRL_CROSS)){
		switch(vsel){
		case 0:
			sspButton->click();
			break;

		case 1:
			smpButton->click();
			break;

		case 2:
			mcrButton->click();
			break;

		case 3:
			optionButton->click();
			break;

		case 4:
			quitButton->click();
			break;
		}
	}
}

void MenuState::draw(GameStateManager* st)
{
	GFX::g_RenderCore->clear();
	GFX::g_RenderCore->set3DMode();
	panorama->draw();

	GFX::g_RenderCore->setDefault2DMode();
	logoSprite->draw();

	quitButton->draw();
	optionButton->draw();
	sspButton->draw();
	smpButton->draw();
	mcrButton->draw();

	textRender->setStyle({ 255, 255, 255, 255, TEXT_SIZE, TEXT_RENDERER_BOTTOM, TEXT_RENDERER_LEFT, 0.0f, true });
	textRender->draw("Minecraft 1.13.2 - compatible", { 0, 267 + CORRECTION_FACTOR });

	textRender->setStyle({ 255, 255, 255, 255, TEXT_SIZE, TEXT_RENDERER_BOTTOM, TEXT_RENDERER_RIGHT, 0.0f, true });
	textRender->draw("Fan Version. Not Made by Mojang!", { 480, 267 + CORRECTION_FACTOR});

}
