//
//  AboutMeScene.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/25/18.
//

#include "AboutMeScene.hpp"
#include "MenuScene.hpp"
#include "ui/CocosGUI.h"

USING_NS_CC;

cocos2d::Scene* AboutMeScene::createScene()
{
    auto scene = cocos2d::Scene::create();
    auto layer = AboutMeScene::create();
    scene->addChild(layer);
    return scene;
}

bool AboutMeScene::init() {
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto label = Label::createWithTTF("About Me", "fonts/Avenir Next Condensed.ttc", 72);
    label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + 3 * visibleSize.height/4));
    label->enableGlow(cocos2d::Color4B::YELLOW);
    this->addChild(label, 1);
    
    if (!Layer::init())
    {
        return false;
    }
    auto aboutMe = Label::createWithTTF("I'm Vijay, and I built this game for my CS 126 Final Project! \n I don't really know what else to put here!", "fonts/Marker Felt.ttf", 24);
    aboutMe->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y +  2 * visibleSize.height/3 - aboutMe->getContentSize().height));
    aboutMe->enableGlow(Color4B::BLUE);
    this->addChild(aboutMe, 1);
    
    auto back_button = cocos2d::MenuItemFont::create("Back to Main Menu", this, menu_selector(AboutMeScene::onBack));
    //back_button->setPosition(Vec2(visibleSize.width/2, visibleSize.height/5 - back_button->getContentSize().height));
    auto menu = Menu::create(back_button, nullptr);
    menu->setPosition(840, 100);
    this->addChild(menu, 0);
    return true;
};

void AboutMeScene::onBack(Ref* sender) {
    //Director::getInstance()->replaceScene(MenuScene::createScene());
    Director::getInstance()->popScene();
}
