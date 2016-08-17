# FrozaxShake-v3
Frozax's Shake Action ported to cocos2dx-v3

http://www.frozax.com/blog/2012/02/how-to-create-shake-action-cocos2d-x-source-code/


#Usage

Include the header, create the Action:

    #include "FShake.h"
    FShake* shake = FShake::actionWithduration(1.0f, 10.0f);
    
Then give it a target, and have it do its thing

    my_node->runAction(shake);
  
Easy.

###Notes

* Don't forget to add it to your `Android.mk` file, so that it'll compile for Android. 
* Tested on Windows 7, cocos2dx-v3.6

###Changelog

* v3.01 added `FShake.clone`
* v3.02 added mertkasar's fix for shaking
* v3.03 fix shaking crash if target is null
