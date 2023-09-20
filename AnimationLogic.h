#pragma once
#include <SFML/Graphics.hpp>
#include <map>

enum class AnimState
{
	Idle = 0,
	Run,
	Jump,
	Slide
};

struct Frames
{
	Frames(const sf::IntRect& _rect, int _countFrames = 1) 
		: rect(_rect),
		countFrames(_countFrames)
	{}

	int countFrames;
	sf::IntRect rect;
};

class AnimationLogic
{
public:
	explicit AnimationLogic(const float& msBetweenFrames);
	~AnimationLogic() = default;

	void update(const float& time);
	void addAnim(AnimState animState, const sf::IntRect& rect, int colomn);
	void setState(const AnimState& animState);
	const sf::IntRect& getRect()const;
protected:
	const float _msBetweenFrames;
	float _currentTime;
	int _currentFrame;

	AnimState _currentState;
	sf::IntRect _currentRect;
	std::map<AnimState, Frames> _frames;
};