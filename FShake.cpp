// Code by Francois Guibert
// Contact: www.frozax.com - http://twitter.com/frozax - www.facebook.com/frozax
#include "FShake.h"
#include "cocos2d.h"

USING_NS_CC;

// not really useful, but I like clean default constructors
FShake::FShake() : _strength_x(0), _strength_y(0), _initial_x(0), _initial_y(0)
{
}

FShake* FShake::actionWithDuration( float d, float strength )
{
	// call other construction method with twice the same strength
	return actionWithDuration( d, strength, strength );
}

FShake* FShake::actionWithDuration(float duration, float strength_x, float strength_y)
{
	FShake *p_action = new FShake();
	p_action->initWithDuration(duration, strength_x, strength_y);
	p_action->autorelease();

	return p_action;
}

bool FShake::initWithDuration(float duration, float strength_x, float strength_y)
{
	if (cocos2d::ActionInterval::initWithDuration(duration))
	{
		_strength_x = strength_x;
		_strength_y = strength_y;
		return true;
	}

	return false;
}

// Helper function. I included it here so that you can compile the whole file
// it returns a random value between min and max included
float fgRangeRand( float min, float max )
{
	float rnd = ((float)rand()/(float)RAND_MAX);
	return rnd*(max-min)+min;
}

void FShake::update(float time)
{
	float rand_x = fgRangeRand( -_strength_x, _strength_x );
	float rand_y = fgRangeRand( -_strength_y, _strength_y );

	// move the target to a shaked position
	this->getTarget()->setPosition( Vec2( this->_initial_x+rand_x, this->_initial_y+rand_y) );
}

void FShake::startWithTarget(Node *pTarget)
{
	ActionInterval::startWithTarget( pTarget );

	// save the initial position
	_initial_x = pTarget->getPosition().x;
	_initial_y = pTarget->getPosition().y;
}

void FShake::stop(void)
{
	// Action is done, reset clip position
	this->getTarget()->setPosition( Vec2( _initial_x, _initial_y ) );

	ActionInterval::stop();
}

FShake* FShake::clone()
{
    // no copy constructor
    auto a = new (std::nothrow) FShake();
    a->initWithDuration(_duration, _strength_x, _strength_y);
    a->autorelease();
    return a;
}
