#include "stdafx.h"
#include "MathUtils.h"
#include "Vector.h"

Vector4 Vector4::Right(1.0f, 0.0f, 0.0f, 1.0f);
Vector4 Vector4::Up(0.0f, 1.0f, 0.0f, 1.0f);
Vector4 Vector4::Forward(0.0f, 0.0f, 1.0f, 1.0f);
Vector4 Vector4::Zero(0.0f, 0.0f, 0.0f, 0.0f);
Vector4 Vector4::One(1.0f, 1.0f, 1.0f, 1.0f);
Vector4 Vector4::Point(0.0f, 0.0f, 0.0f, 0.0f);
Vector4 Vector4::Vector(0.0f, 0.0f, 0.0f, 1.0f);

Vector4::Vector4(float InF) :
	X(InF),
	Y(InF),
	Z(InF),
	W(InF)
{

}

Vector4::Vector4(float InX, float InY, float InZ, float InW) :
	X(InX),
	Y(InY),
	Z(InZ),
	W(InW)
{

}

Vector4::Vector4(const Vector2& InV1, const Vector2& InV2) :
	X(InV1.X),
	Y(InV1.Y),
	Z(InV2.X),
	W(InV2.Y)
{

}

Vector4::Vector4(const Vector3& InV, float InF) :
	X(InV.X),
	Y(InV.Y),
	Z(InV.Z),
	W(InF)
{

}

Vector4::Vector4(const Vector4& InV) :
	X(InV.X),
	Y(InV.Y),
	Z(InV.Z),
	W(InV.W)
{

}

float& Vector4::operator[](int ElementIndex)
{
	//@TODO: Add Error Message
	switch (ElementIndex)
	{
	case 0:
		return X;

	case 1:
		return Y;

	case 2:
		return Z;

	case 3:
		return W;

	default:
		if (ElementIndex < 0)
		{
			return X;
		}
		else
		{
			return W;
		}
	}
}

float Vector4::operator[](int ElementIndex) const
{
	//@TODO: Add Error Message
	switch (ElementIndex)
	{
	case 0:
		return X;

	case 1:
		return Y;

	case 2:
		return Z;

	case 3:
		return W;

	default:
		if (ElementIndex < 0)
		{
			return X;
		}
		else
		{
			return W;
		}
	}
}

Vector4& Vector4::operator=(float InF)
{
	X = InF;
	Y = InF;
	Z = InF;
	W = InF;

	return *this;
}

Vector4& Vector4::operator=(const Vector4& InV)
{
	X = InV.X;
	Y = InV.Y;
	Z = InV.Z;
	W = InV.W;

	return *this;
}

Vector4 Vector4::operator-() const
{
	return Vector4(-X, -Y, -Z, -W);
}

bool Vector4::operator==(const Vector4& InV) const
{
	return (X == InV.X) && (Y == InV.Y) && (Z == InV.Z) && (W == InV.W);
}

bool Vector4::operator!=(const Vector4& InV) const
{
	return (X != InV.X) || (Y != InV.Y) || (Z != InV.Z) || (W != InV.W);
}

Vector4 Vector4::operator+(float Bias) const
{
	return Vector4(X + Bias, Y + Bias, Z + Bias, W + Bias);
}

Vector4 Vector4::operator+(const Vector4& InV) const
{
	return Vector4(X + InV.X, Y + InV.Y + Y, Z + InV.Z, W + InV.W);
}

Vector4 Vector4::operator-(float Bias) const
{
	return Vector4(X - Bias, Y - Bias, Z - Bias, W - Bias);
}

Vector4 Vector4::operator-(const Vector4& InV) const
{
	return Vector4(X - InV.X, Y - InV.Y, Z - InV.Z, W - InV.W);
}

Vector4 Vector4::operator*(float Scale) const
{
	return Vector4(X * Scale, Y * Scale, Z * Scale, W * Scale);
}

Vector4 Vector4::operator*(const Vector4& InV) const
{
	return Vector4(X * InV.X, Y * InV.Y, Z * InV.Z, W * InV.W);
}

Vector4 Vector4::operator/(float Scale) const
{
	Vector4 Vector(0.0f, 0.0f, 0.0f, 0.0f);
	if (Scale != 0.0f)
	{
		Vector.X = X / Scale;
		Vector.Y = Y / Scale;
		Vector.Z = Z / Scale;
		Vector.W = W / Scale;
	}

	return Vector;
}

Vector4 Vector4::operator/(const Vector4& InV) const
{
	Vector4 Vector(0.0f, 0.0f, 0.0f, 0.0f);

	if (InV.X != 0.0f && InV.Y != 0.0f && InV.Z != 0.0f && InV.W != 0.0f)
	{
		Vector.X = X / InV.X;
		Vector.Y = Y / InV.Y;
		Vector.Z = Z / InV.Z;
		Vector.W = W / InV.W;
	}

	return Vector;
}

float Vector4::operator|(const Vector4& InV) const
{
	return (X * InV.X) + (Y * InV.Y) + (Z * InV.Z) + (W * InV.W);
}

inline float Vector4::DotProduct3(const Vector4& A, const Vector4& B)
{
	return (A.X * B.X) + (A.Y * B.Y) + (A.Z * B.Z);
}

float Vector4::DotProduct4(const Vector4& A, const Vector4& B)
{
	return A | B;
}

Vector4 Vector4::operator^(const Vector4& InV) const
{
	return Vector4(Y*InV.Z - Z*InV.Y, Z*InV.X - X*InV.Z, X*InV.Y - Y*InV.X, 0.0f);
}

Vector4 Vector4::CrossProduct(const Vector4& A, const Vector4& B)
{
	return A ^ B;
}

float Vector4::Size3() const
{
	float SquareSum = (X*X) + (Y*Y) + (Z*Z);
	return std::sqrtf(SquareSum);
}

float Vector4::Size4() const
{
	float SquareSum = (X*X) + (Y*Y) + (Z*Z) + (W*W);
	return std::sqrtf(SquareSum);
}

float Vector4::SizeSquared3() const
{
	return (X*X) + (Y*Y) + (Z*Z);
}

float Vector4::SizeSquared4() const
{
	return (X*X) + (Y*Y) + (Z*Z) + (W*W);
}

void Vector4::Normalize3()
{
	if (!IsZero3())
	{
		float SizeInverse = 1.0f / Size3();
		X *= SizeInverse;
		Y *= SizeInverse;
		Z *= SizeInverse;
	}
}

void Vector4::Normalize4()
{
	if (!IsZero4())
	{
		float SizeInverse = 1.0f / Size4();
		X *= SizeInverse;
		Y *= SizeInverse;
		Z *= SizeInverse;
		W *= SizeInverse;
	}
}

bool Vector4::IsZero3() const
{
	return (X == 0.0f) && (Y == 0.0f) && (Z == 0.0f);
}

bool Vector4::IsZero4() const
{
	return (X == 0.0f) && (Y == 0.0f) && (Z == 0.0f) && (W == 0.0f);
}

std::ostream& operator<<(std::ostream& Os, const Vector4& InV)
{
	Os << "(" << InV.X << ", " << InV.Y << ", " << InV.Z << ", " << InV.W << ")";
	return Os;
}

std::string Vector4::ToString() const
{
	return '(' + std::to_string(X) + ", " + std::to_string(Y) + "," + std::to_string(Z) + ", " + std::to_string(W) + ")";
}