//
//  OpeningScene.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/22/18.
//

#include "OpeningScene.hpp"
#include "MenuScene.hpp"

USING_NS_CC;

cocos2d::Scene* OpeningScene::createScene()
{
    auto scene = cocos2d::Scene::create();
    auto layer = OpeningScene::create();
    scene->addChild(layer);
    return scene;
}

bool OpeningScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    //Sets visibleSize and origin variables for use for sprites and GUI items
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Creates Title
    auto label = Label::createWithTTF("Vijay's Game", "fonts/Avenir Next Condensed.ttc", 72);
    label->setOpacity(0);
    if (label == nullptr) {
        return false;
    } else {
        auto fadeIn = cocos2d::FadeTo::create(2, 255);
        label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + 2 * visibleSize.height/3 - label->getContentSize().height));
        label->enableGlow(cocos2d::Color4B::YELLOW);
        this->addChild(label, 1);
        label->runAction(fadeIn);
    }
    
    /**
    * Using generatePolygon draws the sprites using triangles instead of rectangles.
    * This uses more vertices, but less pixels, making the program more efficient on the GPU.
    */
    auto polygonInfo1 = AutoPolygon::generatePolygon("sister.png");
    auto polygonInfo2 = AutoPolygon::generatePolygon("Oshawott.png");

    auto sprite1 = Sprite::create(polygonInfo1);
    auto sprite2 = Sprite::create(polygonInfo2);
    
    if (sprite1 == nullptr || sprite2 == nullptr) {
        return false;
    } else {
        sprite1->setPosition(Vec2(visibleSize.width/3, origin.y + visibleSize.height/3));
        sprite2->setPosition(Vec2(visibleSize.width * 2/3, origin.y + visibleSize.height/3));
        sprite1->setScale(0.5);
        sprite2->setScale(0.5);
    }
    
    auto background = Sprite::create();
    background->setAnchorPoint(cocos2d::Vec2(0,0));
    background->initWithFile("stars2.png");
    background->setPosition(visibleSize.width/2, visibleSize.height/2);
    float scale = MIN(visibleSize.width / background->getContentSize().width, visibleSize.height / background->getContentSize().height);
    background->setScale(scale);
    
    this->addChild(background, 0);
    this->addChild(sprite1, 1);
    this->addChild(sprite2, 1);
    
    auto listener = cocos2d::EventListenerKeyboard::create();
    
    auto name = Label::createWithTTF("Press ENTER to start", "fonts/Optima.ttc", 24);
    auto fadeIn = cocos2d::FadeTo::create(3, 255);
    name->setOpacity(0);
    name->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + 2 * visibleSize.height/5 - name->getContentSize().height));
    name->enableGlow(cocos2d::Color4B::YELLOW);
    this->addChild(name, 0);
    name->runAction(fadeIn);
    
    listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event)->void {
        
        if (code == cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE) {
            exit(0); // Terminates the running of the program.
        } else if (code == cocos2d::EventKeyboard::KeyCode::KEY_SPACE) {
        
            
            
            auto bounceAction1 = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(0, 100));
            auto bounceAction2 = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(0, -100));
            
            cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
            actions.pushBack(bounceAction1);
            actions.pushBack(bounceAction2);
            auto bounce1 = cocos2d::Sequence::create(actions);
            auto repeat = cocos2d::RepeatForever::create(bounce1);
            sprite1->runAction(repeat);
            sprite2->runAction(repeat->clone()); //Actions have internal states from acting on other nodes. Clone creates a fresh Action
        }
        
        // Kills current scene and goes to menu screen
        if (code == cocos2d::EventKeyboard::KeyCode::KEY_ENTER) {
            
            Director::getInstance()->replaceScene(TransitionFade::create(0.5, MenuScene::createScene(), Color3B(0, 0, 0)));
        }
    };
    
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    return true;
}
