# FrozaxShake-v3
Frozax's Shake Action ported to cocos2dx-v3

http://www.frozax.com/blog/2012/02/how-to-create-shake-action-cocos2d-x-source-code/


#Usage

Include the header, create the Action:

  FShake* shake = FShake::actionWithduration(1.0f, 10.0f);
    
Then give it a target, and have it do its thing

  my_node->runAction(shake);
  
Easy.
