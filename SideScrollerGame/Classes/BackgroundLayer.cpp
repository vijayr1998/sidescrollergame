//
//  BackgroundLayer.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/30/18.
//

#include "BackgroundLayer.hpp"
USING_NS_CC;

bool BackgroundLayer::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(! Layer::init());
        
        Size winSize = Director::getInstance()->getWinSize();
        
        // background:
        auto background = TMXTiledMap::create("/Users/Vijay/final-project-vijayr1998/SideScrollerGame/Resources/game_map.tmx");
        //background->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
        //background->setAnchorPoint(Vec2(0, 0));
        background->setScale(1.25);
        background->setMapSize(cocos2d::Size(24, 15));
        addChild(background, 1, 99); // with a tag of '99'
        bRet = true;
    } while (0);
    
    return bRet;
}

Scene* BackgroundLayer::scene()
{
    Scene* scene = NULL;
    do
    {
        // ‘scene’ is an autorelease object
        scene = Scene::create();
        CC_BREAK_IF(!scene);
        // ‘layer’ is an autorelease object
        BackgroundLayer *layer1 = BackgroundLayer::create();
        CC_BREAK_IF(! layer1);
        
        // add the layers as a child to scene
        scene->addChild(layer1, 1);
    } while (0);
    
    // return the Main menu scene
    return scene;
}
