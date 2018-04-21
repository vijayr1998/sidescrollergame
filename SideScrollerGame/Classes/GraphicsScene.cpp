//
//  GraphicsScene.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/20/18.
//

#include "GraphicsScene.hpp"

USING_NS_CC;

Scene* GraphicsScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GraphicsScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool GraphicsScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto sprite = Sprite::create("luigi.png");
    sprite->setAnchorPoint(Vec2(0.5,0.5));
    sprite->setPosition(0, 0);
    
    this->addChild(sprite, 0);
    
    return true;
}
