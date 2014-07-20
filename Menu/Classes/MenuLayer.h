//
//  MenuLayer.h
//  MenuTutorial
//
//  Created by Denger on 14-2-12.
//
//

#ifndef __MenuTutorial__MenuLayer__
#define __MenuTutorial__MenuLayer__

#include "cocos2d.h"

class MenuLayer : public cocos2d::Layer
{
public:
    bool init();
    
    void onNewGame(cocos2d::Object* pSender);
    void onCredits(cocos2d::Object* pSender);
    
    
    CREATE_FUNC(MenuLayer);
};

#endif /* defined(__MenuTutorial__MenuLayer__) */
