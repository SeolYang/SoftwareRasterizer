#pragma once

class Vector2;
class Vector3;

/*
* This class is representing 4D homogeneous coordinates.
*/
MS_ALIGN(16) class Vector4
{
public:
	float X;

	float Y;

	float Z;

	float W;

public:
	DEFINE_ALIGNED_NEW_DELETE
	Vector4(float InF);
	Vector4(float InX = 0.0f, float InY = 0.0f , float InZ = 0.0f, float InW = 1.0f);
	Vector4(const Vector2& InV1, const  Vector2& InV2);
	Vector4(const Vector3& InV, float InF = 0.0f);
	Vector4(const Vector4& InV);

	float& operator[](int ElementIndex);
	float operator[](int ElementIndex) const;

	Vector4& operator=(float InF);
	Vector4& operator=(const Vector4& InV);

	Vector4 operator-() const;

	bool operator==(const Vector4& InV) const;
	bool operator!=(const Vector4& InV) const;

	Vector4 operator+(float Bias) const;
	Vector4 operator+(const Vector4& InV) const;

	Vector4 operator-(float Bias) const;
	Vector4 operator-(const Vector4& InV) const;

	Vector4 operator*(float Scale) const;
	Vector4 operator*(const Vector4& InV) const;

	Vector4 operator/(float Scale) const;
	Vector4 operator/(const Vector4& InV) const;

	float operator|(const Vector4& InV) const;
	static float DotProduct3(const Vector4& A, const Vector4& B);
	static float DotProduct4(const Vector4& A, const Vector4& B);

	Vector4 operator^(const Vector4& InV) const;
	static Vector4 CrossProduct(const Vector4& A, const Vector4& B);

	float Size3() const;
	float Size4() const;

	float SizeSquared3() const;
	float SizeSquared4() const;

	void Normalize3();
	void Normalize4();

	bool IsZero3() const;
	bool IsZero4() const;

	friend std::ostream& operator<<(std::ostream& Os, const Vector4& InV);
	std::string ToString() const;

	Vector2 ToVector2() const;
	Vector3 ToVector3() const;

public:
	static Vector4 Right;
	static Vector4 Up;
	static Vector4 Forward;
	static Vector4 Zero;
	static Vector4 One;
	static Vector4 Point;
	static Vector4 Vector;

};