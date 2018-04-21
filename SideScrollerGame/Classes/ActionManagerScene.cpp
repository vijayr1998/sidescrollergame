//
//  ActionManagerScene.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/21/18.
//

#include "ActionManagerScene.hpp"

cocos2d::Scene* ActionManagerScene::createScene()
{
    auto scene = cocos2d::Scene::create();
    auto layer = ActionManagerScene::create();
    scene->addChild(layer);
    return scene;
}

void ActionManagerScene::callOnce() {
    cocos2d::MessageBox("Called after 5 seconds", "Message");
}

bool ActionManagerScene::init()
{
    if (!LayerColor::initWithColor(cocos2d::Color4B::BLACK))
    {
        return false;
    }
    
    //this->scheduleOnce(schedule_selector(ActionManagerScene::callOnce), 10);
    
    
    // Prints out text
    label = cocos2d::Label::createWithSystemFont("Press space to pause all, 1 to pause left", "Arial", 30);
    label->setPosition(cocos2d::Vec2(this->getBoundingBox().getMidX(), this->getBoundingBox().getMaxY() - 20));
    
    // Creates sprite images
    sprite = cocos2d::Sprite::create("sister.png");
    sprite2 = cocos2d::Sprite::create("sister.png");
    sprite->setPosition(300, this->getBoundingBox().getMidY());
    sprite2->setPosition(1000, this->getBoundingBox().getMidY());
    
    // Creates actions
    auto rotate = cocos2d::RotateBy::create(1, 45);
    auto rotate2 = cocos2d::RotateBy::create(1, -45);
    
    auto repeat1 = cocos2d::RepeatForever::create(rotate);
    auto repeat2 = cocos2d::RepeatForever::create(rotate2);
    
    // Cocos2d makes most objects nodes in a tree.
    this->addChild(label,0);
    this->addChild(sprite, 0);
    this->addChild(sprite2, 0);
    
    sprite->runAction(repeat1);
    sprite2->runAction(repeat2);
    
    auto listener = cocos2d::EventListenerKeyboard::create();
    listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event)->void{
        
        // On Spacebar, Pause/Unpause all actions and updates
        if (code == cocos2d::EventKeyboard::KeyCode::KEY_SPACE){
            if (pausedNodes.size()){
                cocos2d::Director::getInstance()->getActionManager()->resumeTargets(pausedNodes);
                pausedNodes.clear();
                spritePaused = false; // In case user currently has 1 pressed too
            }
            else
                pausedNodes = cocos2d::Director::getInstance()->getActionManager()->pauseAllRunningActions();
            label->setString("Spacebar pressed");
        }
        // Pause/UnPause just sprite 1
        if (code == cocos2d::EventKeyboard::KeyCode::KEY_1){
            if (spritePaused)
                sprite->resumeSchedulerAndActions();
            else
                sprite->pauseSchedulerAndActions();
            spritePaused = !spritePaused;
            label->setString("1 pressed");
        }
        
        if (code == cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE) {
            
            exit(0); // Terminates the running of the program.
        }
        
        
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    return true;
}
