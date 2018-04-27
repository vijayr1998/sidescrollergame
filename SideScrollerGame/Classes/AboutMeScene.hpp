//
//  AboutMeScene.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/25/18.
//

#ifndef AboutMeScene_hpp
#define AboutMeScene_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <stdio.h>

class AboutMeScene : public cocos2d::Layer {
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(AboutMeScene);
    void onBack(Ref* pSender);
    
private:
    cocos2d::Label* label;
};

#endif /* AboutMeScene_hpp */
