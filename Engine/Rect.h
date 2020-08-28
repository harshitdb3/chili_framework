#pragma once

#include "Vec2.h"
template <typename T>
class Rect
{
public:
	Rect() = default;
	/*Rect( T left_in,T right_in,T top_in,T bottom_in );
	Rect( const Vec2_<T>& topLeft,const Vec2_<T>& bottomRight );
	Rect( const Vec2_<T>& topLeft,T width,T height );
	bool IsOverlappingWith( const Rect& other ) const;
	bool IsContainedBy( const Rect& other ) const;
	bool Contains( const Vec2_<T>& poT ) const;
	static Rect FromCenter( const Vec2_<T>& center,T halfWidth,T halfHeight );
	Rect GetExpanded( T offset ) const;
	Vec2_<T> GetCenter() const;
	T GetWidth(const Rect& rect) const;
	T GetHeight(const Rect& rect) const;
	T GetWidth();
	T GetHeight();*/
public:


	Rect(T left_in, T right_in, T top_in, T bottom_in)
		:
		left(left_in),
		right(right_in),
		top(top_in),
		bottom(bottom_in)
	{
	}

	Rect(const Vec2_<T>& topLeft, const Vec2_<T> & bottomRight)
		:
		Rect(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
	{
	}

	Rect(const Vec2_<T>& topLeft, T width, T height)
		:
		Rect(topLeft, topLeft + Vec2_<T>(width, height))
	{
	}

	bool IsOverlappingWith(const Rect& other) const
	{
		return right > other.left && left < other.right
			&& bottom > other.top && top < other.bottom;
	}

	bool IsContainedBy(const Rect & other) const
	{
		return left >= other.left && right <= other.right &&
			top >= other.top && bottom <= other.bottom;
	}

	bool Contains(const Vec2_<T>& poT) const
	{
		return poT.x >= left && poT.x < right && poT.y >= top && poT.y < bottom;
	}

	Rect FromCenter(const Vec2_<T> & center, T halfWidth, T halfHeight)
	{
		const Vec2_<T> half(halfWidth, halfHeight);
		return Rect(center - half, center + half);
	}

	Rect GetExpanded(T offset) const
	{
		return Rect(left - offset, right + offset, top - offset, bottom + offset);
	}

	Vec2_<T> GetCenter() const
	{
		return Vec2_<T>((left + right) / 2, (top + bottom) / 2);
	}

	T GetWidth(const Rect& rect) const
	{

		return (rect.right - rect.left);
	}

	T GetHeight(const Rect& rect) const
	{

		return (rect.bottom - rect.top);
	}

	T GetWidth()
	{
		return (left - right);
	}

	T GetHeight()
	{
		return (bottom - top);
	}


	T left;
	T right;
	T top;
	T bottom;
};
typedef Rect<int> RectI;
typedef Rect<float> RectF;