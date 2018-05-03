//
//  Level 1-1.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/26/18.
//

#include "Level_1_1.hpp"
#include "cocos2d.h"
#include <iostream>
#include "BackgroundLayer.hpp"

USING_NS_CC;

Scene* Level_1_1::createScene()
{
    auto scene = Scene::create();
    auto layer = Level_1_1::create();
    scene->addChild(layer);
    HUDLayer *hud = new HUDLayer();
    hud->init();
    scene->addChild(hud);
    layer->_hud = hud;
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
//    auto background = TMXTiledMap::create("/Users/Vijay/final-project-vijayr1998/SideScrollerGame/Resources/game_map.tmx");
//    //background->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
//    //background->setAnchorPoint(Vec2(0, 0));
//    background->setScale(1.25);
//    background->setMapSize(cocos2d::Size(24, 15));
//    addChild(background, 1, 99); // with a tag of '99'
    addChild(BackgroundLayer::scene(), 1);
    
    // Player character spawn:
    auto frames = getAnimation("adventurer_stand.png", 1); //Size 1
    frames.pushBack(getAnimation("adventurer_walk%01d.png", 2)); //Size 3
    frames.pushBack(getAnimation("adventurer_jump.png", 1));
    frames.pushBack(getAnimation("adventurer_duck.png", 1));
    
    Level_1_1::sprite = Sprite::createWithSpriteFrame(frames.front());
    
    this->addChild(sprite, 2);
    sprite->setPosition(100, 260);
    
    
    
    
    // When Paused:
    auto label = cocos2d::Label::createWithTTF("Game is Paused","fonts/Optima.ttc", 32);
    label->setPosition(840, 525);
    label->setOpacity(0);
    addChild(label, 5);
    
    // Setting up platforms:
//    CCTMXObjectGroup *objectGroup = background->objectGroupNamed("Platforms");
//
//    if(objectGroup == NULL){
//        log("tile map has no objects object layer");
//        return false;
//    }
    
    
    //CCDictionary *platform3 = objectGroup->getObject("Platform3");
    

    
//    auto movement = MoveTo::create(10, Vec2(2148,320));
//    auto resetPosition = MoveTo::create(0, Vec2(-150,320));
//    auto sequence = Sequence::create(movement, resetPosition, NULL);
//    sprite->runAction(RepeatForever::create(sequence));
    auto bounceAction1 = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(0, 100));
    auto bounceAction2 = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(0, -100));
    cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
    actions.pushBack(bounceAction1);
    actions.pushBack(bounceAction2);
    
    
    auto listener = cocos2d::EventListenerKeyboard::create();
    //TODO: Fix changing sprite direction
    listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event)->void {
        if (sprite->getPositionX() >= visibleSize.width) {
            Director::getInstance()->replaceScene(Level_1_1::createScene());
        }
        if (sprite->getPositionX() == 420) {
            _numCollected++;
            _hud->numCollectedChanged(_numCollected);
        }
        if (sprite->getPositionX() == 1120) {
            _numCollected++;
            _hud->numCollectedChanged(_numCollected);
        }
        if (sprite->getPositionX() == origin.x) {
            sprite->setPositionX(1);
        }
        //Vec2 loc = event->getCurrentTarget()->getPosition();
        Vec2 loc = sprite->getPosition();
        Vector<SpriteFrame *> standing_vec;
        standing_vec.pushBack(frames.at(0));
        auto walk_animation = Animation::createWithSpriteFrames(standing_vec);
        auto stand = Animate::create(walk_animation);
        
        Vector<cocos2d::SpriteFrame *> walk_vec;
        walk_vec.pushBack(frames.at(1));
        walk_vec.pushBack(frames.at(2));
        auto animation = Animation::createWithSpriteFrames(walk_vec, 1.0f/6);
        auto walk = Animate::create(animation);
        
        Vector<cocos2d::SpriteFrame *> jump;
        jump.pushBack(frames.at(0));
        jump.pushBack(frames.at(3));
        jump.pushBack(frames.at(0));
        auto jumpFrames = Animation::createWithSpriteFrames(jump);
        auto jump_animation = Animate::create(jumpFrames);
        //https://stackoverflow.com/questions/23488307/how-to-make-a-sprite-jump-using-ccjumpto-in-cocos2d-x
        JumpTo *jumping= new JumpTo();
        jumping->initWithDuration(1, sprite->getPosition(), 300, 1);
        
        Vector<cocos2d::SpriteFrame *> duck;
        duck.pushBack(frames.at(0));
        duck.pushBack(frames.at(4));
        duck.pushBack(frames.at(0));
        auto duckFrames = Animation::createWithSpriteFrames(duck);
        auto duck_animation = Animate::create(duckFrames);
        
        switch(code) {
            case cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE:
                exit(0);
            case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case cocos2d::EventKeyboard::KeyCode::KEY_D:
                if (sprite->isFlippedX()) {
                    sprite->setFlippedX(true);
                }
                sprite->runAction(walk);
                //event->getCurrentTarget()->setPosition(loc.x + 20, loc.y);
                //sprite->setPosition(loc.x + 20, loc.y);
                xMovement++;
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case cocos2d::EventKeyboard::KeyCode::KEY_A:
                if (!sprite->isFlippedX()) {
                    sprite->setFlippedX(true);
                }
                sprite->runAction(walk);
                //event->getCurrentTarget()->setPosition(loc.x - 20, loc.y);
                //sprite->setPosition(loc.x - 20, loc.y);
                xMovement--;
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
            case cocos2d::EventKeyboard::KeyCode::KEY_W:
            case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
                
                sprite->runAction(jump_animation);
                //sprite->runAction(bounce1);
                //sprite->setPosition(loc.x, loc.y + 50);
                //sprite->setPosition(loc.x, loc.y - 30);
                //yMovement++;
                sprite->runAction(jumping);
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case cocos2d::EventKeyboard::KeyCode::KEY_S:
                
                sprite->runAction(duck_animation);
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
            default:
                sprite->runAction(stand);
                
        }
    };
    
    listener->onKeyReleased = [=](EventKeyboard::KeyCode code, Event* event)->void {
        
        if (sprite->getPositionX() >= visibleSize.width) {
            Director::getInstance()->replaceScene(Level_1_1::createScene());
        }
            //Vec2 loc = event->getCurrentTarget()->getPosition();
            Vec2 loc = sprite->getPosition();
            Vector<SpriteFrame *> standing_vec;
            standing_vec.pushBack(frames.at(0));
            auto walk_animation = Animation::createWithSpriteFrames(standing_vec);
            auto stand = Animate::create(walk_animation);
            
            Vector<cocos2d::SpriteFrame *> walk_vec;
            walk_vec.pushBack(frames.at(1));
            walk_vec.pushBack(frames.at(2));
            walk_vec.pushBack(frames.at(1));
            walk_vec.pushBack(frames.at(2));
            auto animation = Animation::createWithSpriteFrames(walk_vec, 1.0f/6);
            auto walk = Animate::create(animation);
            
            Vector<cocos2d::SpriteFrame *> duck;
            duck.pushBack(frames.at(0));
            duck.pushBack(frames.at(4));
            duck.pushBack(frames.at(0));
            auto duckFrames = Animation::createWithSpriteFrames(duck);
            auto duck_animation = Animate::create(duckFrames);
            
            //auto bounce1 = cocos2d::Sequence::create(actions);
            switch(code) {
                case cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE:
                    exit(0);
                case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
                case cocos2d::EventKeyboard::KeyCode::KEY_D:
                    if (sprite->isFlippedX()) {
                        sprite->setFlippedX(true);
                    }
                    sprite->runAction(walk);
                    //event->getCurrentTarget()->setPosition(loc.x + 20, loc.y);
                    //sprite->setPosition(loc.x - 20, loc.y);
                    xMovement--;
                    break;
                case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                case cocos2d::EventKeyboard::KeyCode::KEY_A:
                    if (!sprite->isFlippedX()) {
                        sprite->setFlippedX(true);
                    }
                    sprite->runAction(walk);
                    //event->getCurrentTarget()->setPosition(loc.x - 20, loc.y);
                    //sprite->setPosition(loc.x + 20, loc.y);
                    xMovement++;
                    break;
                case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
                case cocos2d::EventKeyboard::KeyCode::KEY_W:
                case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
                    
//                        sprite->runAction(jump_animation);
                        //sprite->setPosition(loc.x, loc.y - 50);
                        //sprite->setPosition(loc.x, loc.y + 30);
                    //yMovement--;
                    break;
                case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
                case cocos2d::EventKeyboard::KeyCode::KEY_S:
                    
                    sprite->runAction(duck_animation->reverse());
                    break;
                default:
                    sprite->runAction(stand);
            }
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

void Level_1_1::update(float delta) {
    // Register an update function that checks to see if the CTRL key is pressed
    // and if it is displays how long, otherwise tell the user to press it
    Node::update(delta);
    float newPosX = sprite->getPositionX() + (xMovement * 20.f);
    float newPosY = sprite->getPositionY();// + (yMovement * 10.f);
    sprite->setPosition(newPosX, newPosY);
    
}
// Because cocos2d-x requires createScene to be static, I need to make other non-pointer members static
std::map<cocos2d::EventKeyboard::KeyCode,
std::chrono::high_resolution_clock::time_point> Level_1_1::keys;

//void Level_1_1::setPlayerPosition(Point position)
//{
//    Point tileCoord = this->tileCoord(position);
//    int tileGid = BackgroundLayer::meta->getTileGIDAt(tileCoord);
//    if (tileGid) {
//        //auto properties = background->propertiesForGID(tileGid);
//        //cocos2d::ValueMap *properties = background->getPropertiesForGID(tileGid);
//        auto kek = background->getPropertiesForGID(tileGid);
//        Value *lel = &kek;
//        if (lel) {
//             auto *collision = lel->valueForKey("Collidable");
//            auto col = lel->asValueMap();
//            string omg = col.find("Collidable");
//            if (collision && (collision->compare("True") == 0)) {
//                return;
//            }
//        }
//    }
//    sprite->setPosition(position);
//}

Point Level_1_1::tileCoord(Point position)
{
    int x = position.x / background->getTileSize().width;
    int y = ((background->getMapSize().height * background->getTileSize().height) - position.y) / background->getTileSize().height;
    return ccp(x, y);
}
