#pragma once

class Vector3;
class Vector4;

/*
* This class is representing 2D Vector.
*/
MS_ALIGN(16) class Vector2
{
public:
	float X;
	
	float Y;

public:
	Vector2(float InF);
	Vector2(float InX = 0.0f, float InY = 0.0f);
	Vector2(const Vector2& InV);

	float& operator[](int ElementIndex);
	float operator[](int ElementIndex) const;

	Vector2& operator=(float InF);
	Vector2& operator=(const Vector2& InV);

	Vector2 operator-() const;

	bool operator==(const Vector2& InV) const;
	bool operator!=(const Vector2& InV) const;

	Vector2 operator+(float Bias) const;
	Vector2 operator+(const Vector2& InV) const;

	Vector2 operator-(float Bias) const;
	Vector2 operator-(const Vector2& InV) const;

	Vector2 operator*(float Scale) const;
	Vector2 operator*(const Vector2& InV) const;

	Vector2 operator/(float Scale) const;
	Vector2 operator/(const Vector2& InV) const;

	float operator|(const Vector2& InV) const;

	static float DotProduct(const Vector2& A, const Vector2& B);

	float Size() const;
	
	float SizeSquared() const;

	void Normalize();

	/*
	* Return Between A and B Angle to Radains.
	*/
	static float AngleBetween(const Vector2& A, const Vector2& B);

	bool IsZero() const;

	friend std::ostream& operator<<(std::ostream& Os, const Vector2& InV);
	std::string ToString() const;

	Vector3 ToVector3() const;
	Vector4 ToVector4(bool bIsPoint = false) const;

public:
	static Vector2 Zero;
	static Vector2 One;
	static Vector2 Right;
	static Vector2 Up;

};