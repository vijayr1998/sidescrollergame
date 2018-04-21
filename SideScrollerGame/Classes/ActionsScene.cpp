//
//  ActionsScene.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/20/18.
//

#include "ActionsScene.hpp"

cocos2d::Scene* ActionsScene::createScene()
{
    auto scene = cocos2d::Scene::create();
    auto layer = ActionsScene::create();
    scene->addChild(layer);
    return scene;
}

bool ActionsScene::initWithColor()
{
    if (!LayerColor::init())
    {
        return false;
    }
    
    sprite = cocos2d::Sprite::create("sister.png");
    sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    this->addChild(sprite, 0);
    
    auto listener = cocos2d::EventListenerKeyboard::create();
    listener->onKeyPressed = [=](cocos2d:: EventKeyboard::KeyCode code, cocos2d::Event * event)->void{
        // This is where our different actions are going to be implemented
        
        //Moves sprite to bottom left corner(0, 0).
        //auto action = cocos2d::MoveTo::create(2, cocos2d::Vec2(0, 0));
        //sprite->runAction(action);
        
        //Increases image, makes it more red, and fades it.
        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
        actions.pushBack(cocos2d::ScaleBy::create(4, 1.5));
        actions.pushBack(cocos2d::TintTo::create(4, 255, 0, 0));
        actions.pushBack(cocos2d::FadeTo::create(4, 30));
        auto parallel = cocos2d::Spawn::create(actions);
        //sprite ->runAction(parallel);
        
        // Repeating actions:
        // Moves sprite 10 pixels to right every 0.2 seconds
        auto action1 = cocos2d::MoveBy::create(0.2, cocos2d::Vec2(10, 0));
        //Repeats action 10 times, for a total of 2 seconds.
        auto repeat = cocos2d::Repeat::create(action1, 10);
        //sprite->runAction(repeat);
        
        //Instant Actions:
        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions2;
        actions2.pushBack(cocos2d::CallFunc::create([=]()->void {
            this->setColor(cocos2d::Color3B::RED);
        }));
        actions2.pushBack(cocos2d::DelayTime::create(1));
        actions2.pushBack(cocos2d::RemoveSelf::create(false));
        auto sequence = cocos2d::Sequence::create(actions2);
        sprite->runAction(sequence);
    };
    
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    return true;
}
