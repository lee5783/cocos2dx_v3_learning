//
//  SceneManager.cpp
//  MenuTutorial
//
//  Created by Denger on 14-2-12.
//
//

#include "SceneManager.h"
USING_NS_CC;

void SceneManager::goMenu()
{
    Layer *layer = MenuLayer::create();
    SceneManager::go(layer);
}

void SceneManager::go(Layer* layer)
{
    Director *director = Director::getInstance();
    Scene *newScene = SceneManager::wrap(layer);
    if ( director->getRunningScene() )
    {
        director->replaceScene(newScene);
    }
    else
    {
        director->runWithScene(newScene);
    }
}

Scene* SceneManager::wrap(Layer *layer)
{
    Scene *newScene = Scene::create();
    newScene->addChild(layer);
    return newScene;
}
