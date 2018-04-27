//
//  Menu.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/24/18.
//

#include "Menu.hpp"

USING_NS_CC;

cocos2d::Scene* Menu::createScene()
{
    
    auto scene = cocos2d::Scene::create();
    auto layer = Menu::create();
    scene->addChild(layer);
    return scene;
}

