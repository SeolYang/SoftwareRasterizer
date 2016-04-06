#include "stdafx.h"
#include "MathUtils.h"
#include "Vector.h"

Vector3 Vector3::Zero(0.0f, 0.0f, 0.0f);
Vector3 Vector3::One(1.0f, 1.0f, 1.0f);
Vector3 Vector3::Right(1.0f, 0.0f, 0.0f);
Vector3 Vector3::Up(0.0f, 1.0f, 0.0f);
Vector3 Vector3::Forward(0.0f, 0.0f, 1.0f);

Vector3::Vector3(float InF) :
	X(InF),
	Y(InF),
	Z(InF)
{

}

Vector3::Vector3(float InX, float InY, float InZ) :
	X(InX),
	Y(InY),
	Z(InZ)
{

}

Vector3::Vector3(const Vector2& InV, float InZ) :
	X(InV.X),
	Y(InV.Y),
	Z(InZ)
{

}

Vector3::Vector3(const Vector3& InV) :
	X(InV.X),
	Y(InV.Y),
	Z(InV.Z)
{

}

float& Vector3::operator[](int ElementIndex)
{
	switch (ElementIndex)
	{
	case 0:
		return X;

	case 1:
		return Y;

	case 2:
		return Z;

	default:
		if (ElementIndex < 0)
		{
			return X;
		}
		else
		{
			return Z;
		}
	}
}

float Vector3::operator[](int ElementIndex) const
{
	switch (ElementIndex)
	{
	case 0:
		return X;

	case 1:
		return Y;

	case 2:
		return Z;

	default:
		if (ElementIndex < 0)
		{
			return X;
		}
		else
		{
			return Z;
		}
	}
}

Vector3& Vector3::operator=(float InF)
{
	X = InF;
	Y = InF;
	Z = InF;

	return *this;
}

Vector3& Vector3::operator=(const Vector3& InV)
{
	X = InV.X;
	Y = InV.Y;
	Z = InV.Z;

	return *this;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-X, -Y, -Z);
}

bool Vector3::operator==(const Vector3& InV) const
{
	return (X == InV.X) && (Y == InV.Y) && (Z == InV.Z);
}

bool Vector3::operator!=(const Vector3& InV) const
{
	return (X != InV.X) || (Y != InV.Y) || (Z != InV.Z);
}

Vector3 Vector3::operator+(float Bias) const
{
	return Vector3(X + Bias, Y + Bias, Z + Bias);
}

Vector3 Vector3::operator+(const Vector3& InV) const
{
	return Vector3(X + InV.X, Y + InV.Y, Z + InV.Z);
}

Vector3 Vector3::operator-(float Bias) const
{
	return Vector3(X - Bias, Y - Bias, Z - Bias);
}

Vector3 Vector3::operator-(const Vector3& InV) const
{
	return Vector3(X - InV.X, Y - InV.Y, Z - InV.Z);
}

Vector3 Vector3::operator*(float Scale) const
{
	return Vector3(X * Scale, Y * Scale, Z * Scale);
}

Vector3 Vector3::operator*(const Vector3& InV) const
{
	return Vector3(X * InV.X, Y * InV.Y, Z * InV.Z);
}

Vector3 Vector3::operator/(float Scale) const
{
	if (Scale != 0.0f)
	{
		return Vector3(X / Scale, Y / Scale, Z / Scale);
	}

	return Vector3();
}

Vector3 Vector3::operator/(const Vector3& InV) const
{
	Vector3 Vector(0.0f, 0.0f, 0.0f);
	if (InV.X != 0.0f && InV.Y != 0.0f &&  InV.Z != 0.0f)
	{
		Vector.X = X / InV.X;
		Vector.Y = Y / InV.Y;
		Vector.Z = Z / InV.Z;
	}

	return Vector;
}

float Vector3::operator|(const Vector3& InV) const
{
	// ||A||*||B||*cos(t)
	return (X * InV.X) + (Y * InV.Y) + (Z * InV.Z);
}

float Vector3::DotProduct(const Vector3& A, const Vector3& B)
{
	return A | B;
}

Vector3 Vector3::operator^(const Vector3& InV) const
{
	return Vector3((Y*InV.Z - Z*InV.Y), (Z*InV.X - X*InV.Z), (X*InV.Y - Y*InV.X));
}

Vector3 Vector3::CrossProduct(const Vector3& A, const Vector3& B)
{
	return A ^ B;
}

float Vector3::Size() const
{
	float SquareSum = (X * X) + (Y * Y) + (Z * Z);
	return std::sqrtf(SquareSum);
}

float Vector3::SizeSquared() const
{
	return (X * X) + (Y * Y) + (Z * Z);
}

void Vector3::Normalize()
{
	float SizeInverse = 1.0f / Size();
	X *= SizeInverse;
	Y *= SizeInverse;
	Z *= SizeInverse;
}

float Vector3::AngleBetween(const Vector3& A, const Vector3& B)
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

bool Vector3::IsZero() const
{
	return (X == 0.0f) && (Y == 0.0f) && (Z == 0.0f);
}

std::ostream& operator<<(std::ostream& Os, const Vector3& InV)
{
	Os << "(" << InV.X << ", " << InV.Y << ", " << InV.Z << ")";
	return Os;
}

std::string Vector3::ToString() const
{
	return '(' + std::to_string(X) + ", " + std::to_string(Y) + ", " + std::to_string(Z) + ")";
}