#pragma once

MS_ALIGN(16) class Matrix4x4
{
public:
	//M[ROW INDEX][COLUMN INDEX]
	float M[4][4];

public:
	DEFINE_ALIGNED_NEW_DELETE
	Matrix4x4(float InF);
	Matrix4x4(
		float InM11 = 0.0f, float InM12 = 0.0f, float InM13 = 0.0f, float InM14 = 0.0f,
		float InM21 = 0.0f, float InM22 = 0.0f, float InM23 = 0.0f, float InM24 = 0.0f,
		float InM31 = 0.0f, float InM32 = 0.0f, float InM33 = 0.0f, float InM34 = 0.0f,
		float InM41 = 0.0f, float InM42 = 0.0f, float InM43 = 0.0f, float InM44 = 0.0f);
	Matrix4x4(const Matrix4x4& InM);

	Matrix4x4& operator=(float Bias);
	Matrix4x4& operator=(const Matrix4x4& InM);

	Matrix4x4 operator+(float Bias) const;
	Matrix4x4 operator+(const Matrix4x4& InM) const;

	Matrix4x4 operator-(float Bias) const;
	Matrix4x4 operator-(const Matrix4x4& InM) const;

	Matrix4x4 operator*(float Scale) const;
	Vector4 operator*(const Vector4& InV) const;
	Matrix4x4 operator*(const Matrix4x4& InM) const;

	Matrix4x4 operator/(float Scale) const;

	static Matrix4x4 CreateTransition(float X, float Y, float Z);
	static Matrix4x4 CreateTransition(const Vector3& InV);
	static Matrix4x4 CreateRotationX(float Angle);
	static Matrix4x4 CreateRotationY(float Angle);
	static Matrix4x4 CreateRotationZ(float Angle);
	static Matrix4x4 CreateRotation(float XAngle, float YAngle, float ZAngle);
	static Matrix4x4 CreateScale(float Scale);
	static Matrix4x4 CreateScale(float X, float Y, float Z);
	static Matrix4x4 CreateScale(const Vector3& InV);

	//@TODO: Add CreateShear

	static Matrix4x4 CreateScreenSpace(float HalfWidth, float HalfHeight);
	static Matrix4x4 CreatePerspectiveProj(float Fov, float AspecRatio, float ZNear, float ZFar);
	//@TODO: Add CreateOrthogonalProj
	//@TODO: Add CreateLookAt

	friend std::ostream& operator<<(std::ostream& Os, const Matrix4x4& InM);
	std::string ToString() const;

public:
	static Matrix4x4 Identity;
};