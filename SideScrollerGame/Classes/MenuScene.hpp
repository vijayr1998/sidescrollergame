//
//  MenuScene.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/24/18.
//

#ifndef MenuScene_hpp
#define MenuScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class MenuScene : public cocos2d::Layer {
    
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(MenuScene);
    void onQuit(Ref* pSender);
    void onStart(Ref* pSender);
    void onAbout(Ref* pSender);
    
private:
    cocos2d::Label* label;
};


#endif /* MenuScene_hpp */
