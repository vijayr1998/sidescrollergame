//
//  Level 1-1.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/26/18.
//

#include "Level_1_1.hpp"
#include "cocos2d.h"
#include <iostream>

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
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    // background:
    auto background = TMXTiledMap::create("/Users/Vijay/final-project-vijayr1998/SideScrollerGame/Resources/game_map.tmx");
    //background->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
    background->setAnchorPoint(Vec2(0, 0));
    background->setScale(1.25);
    background->setMapSize(cocos2d::Size(24, 15));
    addChild(background, 1); // with a tag of '99'
    background->pause();
    
    // Player character spawn:
    auto frames = getAnimation("adventurer_walk%01d.png", 2);
    auto sprite = Sprite::createWithSpriteFrame(frames.front());
    //auto animation = Animation::createWithSpriteFrames(frames, 1.0f/2);
    //sprite->runAction(RepeatForever::create(Animate::create(animation)));
    this->addChild(sprite, 2);
    sprite->setPosition(100, 260);
    this->setViewPointCenter(sprite->getPosition());
    
    // When Paused:
    auto label = cocos2d::Label::createWithTTF("Game is Paused","fonts/Optima.ttc", 32);
    label->setPosition(840, 525);
    label->setOpacity(0);
    addChild(label, 5);
    
    // Setting up platforms:
    CCTMXObjectGroup *objectGroup = background->objectGroupNamed("Objects");
    
    if(objectGroup == NULL){
        log("tile map has no objects object layer");
        return false;
    }
    
    //CCDictionary *spawnPoint = objectGroup->objectNamed("SpawnPoint");
    
    //auto *platform3 = objectGroup->objectNamed("Platform3");


    
//    auto movement = MoveTo::create(10, Vec2(2148,320));
//    auto resetPosition = MoveTo::create(0, Vec2(-150,320));
//    auto sequence = Sequence::create(movement, resetPosition, NULL);
//    sprite->runAction(RepeatForever::create(sequence));
    
    
    auto listener = cocos2d::EventListenerKeyboard::create();
    
    //TODO: Fix changing sprite direction
    listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event)->void {
        
        Vec2 loc = event->getCurrentTarget()->getPosition();
        auto animation = Animation::createWithSpriteFrames(frames, 1.0f/6);
        auto walk = Animate::create(animation);
        switch(code) {
            case cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE:
                exit(0);
            case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case cocos2d::EventKeyboard::KeyCode::KEY_D:
                if (sprite->isFlippedX()) {
                    sprite->setFlippedX(true);
                }
                sprite->runAction(walk);
                event->getCurrentTarget()->setPosition(loc.x + 20, loc.y);
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case cocos2d::EventKeyboard::KeyCode::KEY_A:
                if (!sprite->isFlippedX()) {
                    sprite->setFlippedX(true);
                }
                sprite->runAction(walk);
                event->getCurrentTarget()->setPosition(loc.x - 20, loc.y);
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
                    label->setOpacity(0);
                } else {
                    Director::getInstance()->pause();
                    label->setOpacity(255);
                    //Director::getInstance()->pause();
                }
                
        }
    };
    
    listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event){
        // remove the key.  std::map.erase() doesn't care if the key doesnt exist
        keys.erase(keyCode);
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    this->scheduleUpdate();
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

bool Level_1_1::isKeyPressed(EventKeyboard::KeyCode code) {
    // Check if the key is currently pressed by seeing it it's in the std::map keys
    if(keys.find(code) != keys.end())
        return true;
    return false;
}

double Level_1_1::keyPressedDuration(EventKeyboard::KeyCode code) {
    if(!isKeyPressed(EventKeyboard::KeyCode::KEY_CTRL))
        return 0;  // Not pressed, so no duration obviously
    
    // Return the amount of time that has elapsed between now and when the user
    // first started holding down the key in milliseconds
    // Obviously the start time is the value we hold in our std::map keys
    return std::chrono::duration_cast<std::chrono::milliseconds>
    (std::chrono::high_resolution_clock::now() - keys[code]).count();
}

void Level_1_1::update(float delta) {
    // Register an update function that checks to see if the CTRL key is pressed
    // and if it is displays how long, otherwise tell the user to press it
    Node::update(delta);
}
// Because cocos2d-x requires createScene to be static, I need to make other non-pointer members static
std::map<cocos2d::EventKeyboard::KeyCode,
std::chrono::high_resolution_clock::time_point> Level_1_1::keys;

void Level_1_1::setViewPointCenter(cocos2d::Point position) {
    
    //CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    cocos2d::Size winSize = Director::getInstance()->getWinSize();
    
    int x = MAX(position.x, winSize.width/2);
    int y = MAX(position.y, winSize.height/2);
    x = MIN(x, (background->getMapSize().width * background->getTileSize().width) - winSize.width / 2);
    y = MIN(y, (background->getMapSize().height * background->getTileSize().height) - winSize.height/2);
    Point actualPosition = Point(x, y);
    
    Point centerOfView = Point(winSize.width/2, winSize.height/2);
    //Point viewPoint = ccpSub(centerOfView, actualPosition);
    auto viewPoint = centerOfView - actualPosition;
    this->setPosition(viewPoint);
}
