//
//  MyFirstScene.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/22/18.
//

#include "MyFirstScene.hpp"
using namespace std;
USING_NS_CC;

Scene* MyFirstScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MyFirstScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool MyFirstScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    //Sets visibleSize and origin variables for use for sprites and GUI items
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("To Infinity and Beyond", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr) {
        return false;
    } else {
        label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2 - label->getContentSize().height));
        this->addChild(label);
    }
    
    auto sprite1 = Sprite::create("sister.png");
    auto sprite2 = Sprite::create("luigi.png");
    
    if (sprite1 == nullptr || sprite2 == nullptr) {
        return false;
    } else {
    sprite1->setPosition(Vec2(origin.x + visibleSize.width/3, origin.y));
    sprite2->setPosition(Vec2(origin.x + visibleSize.width * (2/3), origin.y));
    
    }
    this->addChild(sprite1, 0);
    this->addChild(sprite2, 1);
    return true;
}
