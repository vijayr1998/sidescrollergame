//
//  TouchScene.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/20/18.
//
#include "TouchScene.hpp"

USING_NS_CC;

Scene* TouchScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TouchScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool TouchScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto sprite = Sprite::create("luigi.png");
    sprite->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
                             Director::getInstance()->getVisibleSize().height / 2));
    
    // Add a "touch" event listener to our sprite
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
        
        auto bounds = event->getCurrentTarget()->getBoundingBox();
        
        if (bounds.containsPoint(touch->getLocation())){
            std::stringstream touchDetails;
            touchDetails << "Touched at OpenGL coordinates: " <<
            touch->getLocation().x << "," << touch->getLocation().y << std::endl <<
            "Touched at UI coordinate: " <<
            touch->getLocationInView().x << "," << touch->getLocationInView().y << std::endl <<
            "Touched at local coordinate:" <<
            event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).x << "," <<
            event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).y << std::endl <<
            "Touch moved by:" << touch->getDelta().x << "," << touch->getDelta().y;
            
            MessageBox(touchDetails.str().c_str(), "Touched");
        }
        return true;
    };
    
    // Touch event will only fire if user clicked on luigi in scene.
    // Here, second param "sprite" determines target of Event
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener,sprite);
    this->addChild(sprite, 0);
    
    return true;
}
