//
//  HUDLayer.cpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 5/2/18.
//

#include "HUDLayer.hpp"

using namespace cocos2d;

bool HUDLayer::init()
{
    if (Layer::init()) {
        Size winSize = CCDirector::sharedDirector()->getWinSize();
        
        _label = new Label();
        _label->initWithTTF("0", "fonts/arial.ttf", 18);
        //_label->setColor(ccc3(0,0,0));
        _label->setColor(Color3B(0,0,0));
        
        int margin = 10;
        //_label->setPosition(ccp(winSize.width - (_label->getContentSize().width/2) - margin, _label->getContentSize().height/2 + margin));
        _label->setPosition(Vec2(winSize.width - (_label->getContentSize().width/2) - margin, _label->getContentSize().height/2 + margin));
        this->addChild(_label);
    }
    
    return true;
}

void HUDLayer::numCollectedChanged(int numCollected)
{
    CCString *labelCollected = new CCString();
    labelCollected->initWithFormat("%d",numCollected);
    _label->setString(labelCollected->getCString());
}
