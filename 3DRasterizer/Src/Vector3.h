#pragma once

/*
* This class is representing 3D Vector.
*/
MS_ALIGN(16) class Vector3
{
public:
	float X;

	float Y;

	float Z;

public:
	Vector3(float InF);
	Vector3(float InX = 0.0f, float InY = 0.0f, float InZ = 0.0f);
	Vector3(const Vector2& InV, float InF = 0.0f);
	Vector3(const Vector3& InV);

	float& operator[](int ElementIndex);
	float operator[](int ElementIndex) const;

	Vector3& operator=(float InF);
	Vector3& operator=(const Vector3& InV);

	Vector3 operator-() const;

	bool operator==(const Vector3& InV) const;
	bool operator!=(const Vector3& InV) const;

	Vector3 operator+(float Bias) const;
	Vector3 operator+(const Vector3& InV) const;

	Vector3 operator-(float Bias) const;
	Vector3 operator-(const Vector3& InV) const;

	Vector3 operator*(float Scale) const;
	Vector3 operator*(const Vector3& InV) const;

	Vector3 operator/(float Scale) const;
	Vector3 operator/(const Vector3& InV) const;

	float operator|(const Vector3& InV) const;
	static float DotProduct(const Vector3& A, const Vector3& B);

	Vector3 operator^(const Vector3& InV) const;
	static Vector3 CrossProduct(const Vector3& A, const Vector3& B);

	float Size() const;

	float SizeSquared() const;

	void Normalize();

	static float AngleBetween(const Vector3& A, const Vector3& B);

	bool IsZero() const;

	friend std::ostream& operator<<(std::ostream& Os, const Vector3& InV);
	std::string ToString() const;

	Vector2 ToVector2() const;
	Vector4 ToVector4(bool bIsPoint = false) const;

public:
	static Vector3 Zero;
	static Vector3 One;
	static Vector3 Right;
	static Vector3 Up;
	static Vector3 Forward;

};