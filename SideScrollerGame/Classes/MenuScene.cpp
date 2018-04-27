//
//  Menu.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/24/18.
//

#include "MenuScene.hpp"
#include "AboutMeScene.hpp"
#include "ui/CocosGUI.h"

USING_NS_CC;

cocos2d::Scene* MenuScene::createScene()
{
    
    auto scene = cocos2d::Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    return scene;
}

bool MenuScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    
    
    //Sets visibleSize and origin variables for use for sprites and GUI items
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = Label::createWithTTF("Vijay's Game", "fonts/Avenir Next Condensed.ttc", 72);
    label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + 3 * visibleSize.height/4 - label->getContentSize().height));
    label->enableGlow(cocos2d::Color4B::YELLOW);
    this->addChild(label, 1);
    
//    auto start_game_label = Label::createWithTTF("Start Game!", "fonts/Avenir Next Condensed.ttc", 28);
//    auto quit_game_label = Label::createWithTTF("Quit", "fonts/Avenir Next Condensed.ttc", 28);
//    auto settings_label = Label::createWithTTF("Settings", "fonts/Avenir Next Condensed.ttc", 28);
//    auto about_label = Label::createWithTTF("About Me!", "fonts/Avenir Next Condensed.ttc", 28);
//
//    auto quitItem = MenuItemLabel::create(quit_game_label);
//    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
//                                           [&](Ref* sender){
//                                               // your code here
//                                           });
    
    //TODO: Replace deprecated code.
    auto start_game_button = MenuItemFont::create("Start Game!", this, menu_selector(MenuScene::onQuit));
    auto about_button = MenuItemFont::create("About Me", this, menu_selector(MenuScene::onAbout));
    auto quit_button = cocos2d::MenuItemFont::create("Quit", this, menu_selector(MenuScene::onQuit));
    auto menu = Menu::create(start_game_button, about_button, quit_button, nullptr);
    menu->alignItemsVertically();
    this->addChild(menu);

    return true;
};

//void MenuScene::onMenuCloseCallback(Ref* sender)
//{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//    return;
//#endif
//
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}

void MenuScene::onQuit(Ref* pSender)
{
    // Exit game
    //CCDirector::sharedDirector()->end();
    Director::getInstance()->end();
}

void MenuScene::onAbout(Ref* pSender) {

    // Go to About Me Page
    Director::getInstance()->pushScene(AboutMeScene::createScene());
    //Director::getInstance()->replaceScene(TransitionFade::create(0.5, AboutMeScene::createScene(), Color3B(0, 0, 0)));
}

//cocos2d::Scene* AboutMeScene::createScene()
//{
//    auto scene = cocos2d::Scene::create();
//    auto layer = MenuScene::create();
//    scene->addChild(layer);
//    return scene;
//}
//
//bool AboutMeScene::init() {
//
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//    auto label = Label::createWithTTF("About Me", "fonts/Avenir Next Condensed.ttc", 72);
//    label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + 3 * visibleSize.height/4 - label->getContentSize().height));
//    label->enableGlow(cocos2d::Color4B::YELLOW);
//    this->addChild(label, 1);
//
//    if (!Layer::init())
//    {
//        return false;
//    }
//    auto aboutMe = Label::createWithTTF("I'm Vijay, and I built this game for my CS 126 Final Project! \n I don't really know what else to put here!", "fonts/arial.ttf", 56);
//    aboutMe->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + 3 * visibleSize.height/4 - aboutMe->getContentSize().height));
//    aboutMe->enableGlow(Color4B::BLUE);
//    this->addChild(aboutMe, 1);
//
//    auto back_button = cocos2d::MenuItemFont::create("Back to Main Menu", this, menu_selector(AboutMeScene::onBack));
//    back_button->setPosition(Vec2(visibleSize.width/2, visibleSize.height/5 - back_button->getContentSize().height));
//    this->addChild(back_button);
//    return true;
//};
//
//void AboutMeScene::onBack(Ref* sender) {
//    Director::getInstance()->replaceScene(MenuScene::createScene());
//}
