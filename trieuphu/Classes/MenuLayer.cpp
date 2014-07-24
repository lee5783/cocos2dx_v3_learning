//
//  MenuLayer.cpp
//  MenuTutorial
//
//  Created by Denger on 14-2-12.
//
//

#include "MenuLayer.h"
#include "SceneManager.h"
USING_NS_CC;

bool MenuLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
   Size visibleSize = Director::getInstance()->getVisibleSize();

	auto background = Sprite::create("mainbackground.jpg");  
	background->setPosition( Point(visibleSize.width/2, visibleSize.height/2) );
	//background->setAnchorPoint(Point(0.5,0.5));
	
	float scaleX = visibleSize.width/800;
	float scaleY = visibleSize.height/480;
	background->setScaleX(scaleX);
	background->setScaleY(scaleY);
	this->addChild(background,1);

	auto logo = Sprite::create("mlogo.png");  
	logo->setScale(scaleX);
	
	logo->setPosition(
            Point(visibleSize.width  - (visibleSize.width * 70) / 100,

				  visibleSize.height - (visibleSize.height * 50) / 100    

    )); 
	this->addChild(logo,1);

        
    MenuItemImage *startNew = MenuItemImage::create("play.png",
                                           "play_press.png", CC_CALLBACK_1(MenuLayer::onNewGame, this));
	MenuItemImage *hightScore = MenuItemImage::create("highscore.png",
                                           "highscore_press.png", CC_CALLBACK_1(MenuLayer::onNewGame, this));
	MenuItemImage *helpUser = MenuItemImage::create("help.png",
                                           "help_press.png", CC_CALLBACK_1(MenuLayer::onNewGame, this));
	MenuItemImage *updateVersion = MenuItemImage::create("update.png",
                                           "update_press.png", CC_CALLBACK_1(MenuLayer::onNewGame, this));
	MenuItemImage *exitGame = MenuItemImage::create("exit.png",
                                           "exit_press.png", CC_CALLBACK_1(MenuLayer::onExit, this));

    //MenuItemFont *credits = MenuItemFont::create("Credits", CC_CALLBACK_1(MenuLayer::onCredits, this));

    Menu *menu = Menu::create(startNew, hightScore,helpUser,updateVersion,exitGame, NULL);
    
   

    menu->setPosition(
            Point(visibleSize.width  - (visibleSize.width * 15) / 100,

				  visibleSize.height - (visibleSize.height * 35) / 100

    )); 

    menu->alignItemsVerticallyWithPadding(10.0f);
	
	menu->setScaleX(scaleX);
	menu->setScaleY(scaleY);
    this->addChild(menu, 3);


    return true;
}

void MenuLayer::onNewGame(Object* pSender)
{
    SceneManager::goMenu();
}

void MenuLayer::onCredits(Object* pSender)
{
    SceneManager::goMenu();
}

void MenuLayer::onExit(Object* pSender)
{
     #if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
		MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
		return;
	#endif

    Director::getInstance()->end();

	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		 exit(0);
	#endif
}