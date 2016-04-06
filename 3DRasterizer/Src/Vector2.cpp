#include "stdafx.h"
#include "MathUtils.h"
#include "Vector.h"

Vector2 Vector2::Zero(0.0f, 0.0f);
Vector2 Vector2::One(1.0f, 1.0f);
Vector2 Vector2::Right(1.0f, 0.0f);
Vector2 Vector2::Up(0.0f, 1.0f);

Vector2::Vector2(float InF) :
	X(InF),
	Y(InF)
{

}

Vector2::Vector2(float InX, float InY) :
	X(InX),
	Y(InY)
{

}

Vector2::Vector2(const Vector2& InV) :
	X(InV.X),
	Y(InV.Y)
{

}

float& Vector2::operator[](int ElementIndex)
{
	switch (ElementIndex)
	{
	case 0:
		return X;

	case 1:
		return Y;

	default:
		if (ElementIndex < 0)
		{
			return X;
		}
		else
		{
			return Y;
		}
	}
}

float Vector2::operator[](int ElementIndex) const
{
	switch (ElementIndex)
	{
	case 0:
		return X;

	case 1:
		return Y;

	default:
		if (ElementIndex < 0)
		{
			return X;
		}
		else
		{
			return Y;
		}
	}
}

Vector2& Vector2::operator=(float InF)
{
	X = InF;
	Y = InF;

	return *this;
}

Vector2& Vector2::operator=(const Vector2& InV)
{
	X = InV.X;
	Y = InV.Y;

	return *this;
}

Vector2 Vector2::operator-() const
{
	return Vector2(-X, -Y);
}

bool Vector2::operator==(const Vector2& InV) const
{
	return (X == InV.X) && (Y == InV.Y);
}

bool Vector2::operator!=(const Vector2& InV) const
{
	return (X != InV.X) || (Y != InV.Y);
}

Vector2 Vector2::operator+(float Bias) const
{
	return Vector2(X + Bias, Y + Bias);
}

Vector2 Vector2::operator+(const Vector2& InV) const
{
	return Vector2(X + InV.X, Y + InV.Y);
}

Vector2 Vector2::operator-(float Bias) const
{
	return Vector2(X - Bias, Y - Bias);
}

Vector2 Vector2::operator-(const Vector2& InV) const
{
	return Vector2(X - InV.X, Y - InV.Y);
}

Vector2 Vector2::operator*(float Scale) const
{
	return Vector2(X * Scale, Y * Scale);
}

Vector2 Vector2::operator*(const Vector2& InV) const
{
	return Vector2(X * InV.X, Y * InV.Y);
}

Vector2 Vector2::operator/(float Scale) const
{
	if (Scale != 0.0f)
	{
		return Vector2(X / Scale, Y / Scale);
	}

	return Vector2();
}

Vector2 Vector2::operator/(const Vector2& InV) const
{
	Vector2 Vector(0.0f, 0.0f);
	if (InV.X != 0.0f && InV.Y != 0.0f)
	{
		Vector.X = X / InV.X;
		Vector.Y = Y / InV.Y;
	}

	return Vector;
}

float Vector2::operator|(const Vector2& InV) const
{
	//||A|| * ||B|| * cos(t)
	return (X * InV.X) + (Y * InV.Y);
}

float Vector2::DotProduct(const Vector2& A, const Vector2& B)
{
	return (A | B);
}

float Vector2::Size() const
{
	float SquareSum = (X * X) + (Y * Y);
	return std::sqrtf(SquareSum);
}

float Vector2::SizeSquared() const
{
	// Same with Dot Product Self
	return (X * X) + (Y * Y);
}

void Vector2::Normalize()
{
	float SizeInverse = 1.0f / Size();
	X *= SizeInverse;
	Y *= SizeInverse;
}

float Vector2::AngleBetween(const Vector2& A, const Vector2& B)
{
	float ASize = A.Size();
	float BSize = B.Size();
	float ABSize = (ASize * BSize);
	float ABDot = A | B;

	if (ABSize != 0.0f)
	{
		return std::acosf(ABDot / ABSize);
	}

	return 0.0f;
}

bool Vector2::IsZero() const
{
	return (X == 0.0f) && (Y == 0.0f);
}

std::ostream& ::operator<<(std::ostream& Os, const Vector2& InV)
{
	Os << "(" << InV.X << ", " << InV.Y << ")";
	return Os;
}

std::string Vector2::ToString() const
{
	return '(' + std::to_string(X) + ", " + std::to_string(Y) + ")";
}

Vector3 Vector2::ToVector3() const
{
	return Vector3(X, Y, 0.0f);
}

Vector4 Vector2::ToVector4(bool bIsPoint) const
{
	if (bIsPoint)
	{
		return Vector4(X, Y, 0.0f, 0.0f);
	}
	else
	{
		return Vector4(X, Y);
	}
}