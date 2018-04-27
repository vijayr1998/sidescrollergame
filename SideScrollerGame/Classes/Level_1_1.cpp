//
//  Level 1-1.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/26/18.
//

#include "Level_1_1.hpp"

USING_NS_CC;

Scene* Level_1_1::createScene()
{
    auto scene = Scene::create();
    auto layer = Level_1_1::create();
    scene->addChild(layer);
    return scene;
}

bool Level_1_1::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // Accesses SpriteSheet for efficient drawing of sprites.
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/HDR/:sprites.plist");
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 visibleSize = Director::getInstance()->getVisibleSize();
    
    // background
    // Will decide to use background if need be.
//    auto background = Sprite::createWithSpriteFrameName("background.png");
//    background->setPosition(origin.x + visibleSize.x / 2,origin.y + visibleSize.y/2);
//    this->addChild(background);
    
    auto frames = getAnimation("adventurer_walk%01d.png", 2);
    auto sprite = Sprite::createWithSpriteFrame(frames.front());
    auto animation = Animation::createWithSpriteFrames(frames, 1.0f/8);
    //sprite->runAction(RepeatForever::create(Animate::create(animation)));
    this->addChild(sprite);
    sprite->setPosition(100,320);
    
    
    
//    auto movement = MoveTo::create(10, Vec2(2148,320));
//    auto resetPosition = MoveTo::create(0, Vec2(-150,320));
//    auto sequence = Sequence::create(movement, resetPosition, NULL);
//    sprite->runAction(RepeatForever::create(sequence));
    
    auto listener = cocos2d::EventListenerKeyboard::create();
    
    listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event)->void {
        
        Vec2 loc = event->getCurrentTarget()->getPosition();
        
        switch(code) {
                //Escape Key
            case cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE:
                exit(0);
            case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case cocos2d::EventKeyboard::KeyCode::KEY_D:
                
                //sprite->runAction(Animate::create(animation));
                event->getCurrentTarget()->setPosition(loc.x + 10, loc.y);
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case cocos2d::EventKeyboard::KeyCode::KEY_A:
                event->getCurrentTarget()->setPosition(loc.x - 10, loc.y);
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
            case cocos2d::EventKeyboard::KeyCode::KEY_W:
            case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
                // Implement physics for jump.
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case cocos2d::EventKeyboard::KeyCode::KEY_S:
                //Duck
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_P:
                if (Director::getInstance()->isPaused()) {
                    Director::getInstance()->resume();
                } else {
                    Director::getInstance()->pause();
                }
                //TODO: Pause all running nodes here
        }
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    return true;
}

// From https://www.codeandweb.com/blog/2015/12/15/animations-and-spritesheets-in-cocos2d-x
cocos2d::Vector<SpriteFrame*> Level_1_1::getAnimation(const char *format, int count)
{
    auto spritecache = SpriteFrameCache::getInstance();
    
    Vector<SpriteFrame*> animFrames;
    char str[100];
    for(int i = 1; i <= count; i++)
    {
        sprintf(str, format, i);
        animFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }
    return animFrames;
}
