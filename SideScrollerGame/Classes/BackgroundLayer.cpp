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
        std::string file_path;
        std::vector<std::string> filePaths;
        filePaths.push_back("/Users/Vijay/final-project-vijayr1998/SideScrollerGame/Resources/game_map.tmx");
        filePaths.push_back("/Users/Vijay/final-project-vijayr1998/SideScrollerGame/Resources/game_map_2.tmx");
        filePaths.push_back("/Users/Vijay/final-project-vijayr1998/SideScrollerGame/Resources/game_map_3.tmx");
        filePaths.push_back("/Users/Vijay/final-project-vijayr1998/SideScrollerGame/Resources/game_map_4.tmx");
        filePaths.push_back("/Users/Vijay/final-project-vijayr1998/SideScrollerGame/Resources/game_map_5.tmx");
        filePaths.push_back("/Users/Vijay/final-project-vijayr1998/SideScrollerGame/Resources/game_map_6.tmx");
        filePaths.push_back("/Users/Vijay/final-project-vijayr1998/SideScrollerGame/Resources/game_map_7.tmx");
        filePaths.push_back("/Users/Vijay/final-project-vijayr1998/SideScrollerGame/Resources/game_map_8.tmx");
        file_path = filePaths.at(random(0, 7));
        // background:
        //auto background = TMXTiledMap::create(file_path);
        auto background = TMXTiledMap::create(file_path);
//        meta = background->getLayer("Meta");
//        meta->setVisible(false);
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

Point BackgroundLayer::tileCoord(Point position)
{
    int x = position.x / background->getTileSize().width;
    int y = ((background->getMapSize().height * background->getTileSize().height) - position.y) / background->getTileSize().height;
    return ccp(x, y);
}

