#include "AnimationLogic.h"

AnimationLogic::AnimationLogic(const float& msBetweenFrames)
	: _msBetweenFrames(msBetweenFrames),
	_currentTime(msBetweenFrames),
	_currentFrame(0),
	_currentState(AnimState::Idle)
{

}

void AnimationLogic::update(const float& time)
{
	if ((_currentTime -= time) < 0)
	{
		_currentTime = _msBetweenFrames;

		if (++_currentFrame > _frames.at(_currentState).countFrames)
		{
			if (_frames.at(_currentState).rect.width < 0)
				_currentFrame = 1;
			else
				_currentFrame = 0;
		}
	}
	_currentRect.left = abs(_frames.at(_currentState).rect.width) * _currentFrame;
}

void AnimationLogic::addAnim(AnimState animState, const sf::IntRect& rect, int colomn)
{
	_frames.emplace(std::make_pair(animState, Frames(rect, colomn)));
}

const sf::IntRect& AnimationLogic::getRect() const
{
	return _currentRect;
}

void AnimationLogic::setState(const AnimState& animState)
{
	_currentState = animState;
	_currentRect = _frames.at(animState).rect;
}
