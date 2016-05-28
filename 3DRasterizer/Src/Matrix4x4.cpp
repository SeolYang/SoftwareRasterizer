#include "stdafx.h"
#include "MathUtils.h"
#include "Vector.h"
#include "Matrix4x4.h"

Matrix4x4 Matrix4x4::Identity(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f);

Matrix4x4::Matrix4x4(float InF) :
	Matrix4x4(
		InF, InF, InF, InF,
		InF, InF, InF, InF,
		InF, InF, InF, InF,
		InF, InF, InF, InF)
{

}

Matrix4x4::Matrix4x4(float InM11, float InM12, float InM13, float InM14, float InM21, float InM22, float InM23, float InM24, float InM31, float InM32, float InM33, float InM34, float InM41, float InM42, float InM43, float InM44)
{
	M[0][0] = InM11; M[0][1] = InM12; M[0][2] = InM13; M[0][3] = InM14;
	M[1][0] = InM21; M[1][1] = InM22; M[1][2] = InM23; M[1][3] = InM24;
	M[2][0] = InM31; M[2][1] = InM32; M[2][2] = InM33; M[2][3] = InM34;
	M[3][0] = InM41; M[3][1] = InM42; M[3][2] = InM43; M[3][3] = InM44;
}

Matrix4x4::Matrix4x4(const Matrix4x4& InM) :
	Matrix4x4(
		InM.M[0][0], InM.M[0][1], InM.M[0][2], InM.M[0][3],
		InM.M[1][0], InM.M[1][1], InM.M[1][2], InM.M[1][3],
		InM.M[2][0], InM.M[2][1], InM.M[2][2], InM.M[2][3],
		InM.M[3][0], InM.M[3][1], InM.M[3][2], InM.M[3][3])
{

}

Matrix4x4& Matrix4x4::operator=(float Bias)
{
	M[0][0] = M[0][1] = M[0][2] = M[0][3] = Bias;
	M[1][0] = M[1][1] = M[1][2] = M[1][3] = Bias;
	M[2][0] = M[2][1] = M[2][2] = M[2][3] = Bias;
	M[3][0] = M[3][1] = M[3][2] = M[3][3] = Bias;

	return *this;
}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& InM)
{
	M[0][0] = InM.M[0][0]; M[0][1] = InM.M[0][1]; M[0][2] = InM.M[0][2]; M[0][3] = InM.M[0][3];
	M[1][0] = InM.M[1][0]; M[1][1] = InM.M[1][1]; M[1][2] = InM.M[1][2]; M[1][3] = InM.M[1][3];
	M[2][0] = InM.M[2][0]; M[2][1] = InM.M[2][1]; M[2][2] = InM.M[2][2]; M[2][3] = InM.M[2][3];
	M[3][0] = InM.M[3][0]; M[3][1] = InM.M[3][1]; M[3][2] = InM.M[3][2]; M[3][3] = InM.M[3][3];

	return *this;
}

Matrix4x4 Matrix4x4::operator+(float Bias) const
{
	Matrix4x4 Mat(*this);
	Mat.M[0][0] += Bias; Mat.M[0][1] += Bias; Mat.M[0][2] += Bias; Mat.M[0][3] += Bias;
	Mat.M[1][0] += Bias; Mat.M[1][1] += Bias; Mat.M[1][2] += Bias; Mat.M[1][3] += Bias;
	Mat.M[2][0] += Bias; Mat.M[2][1] += Bias; Mat.M[2][2] += Bias; Mat.M[2][3] += Bias;
	Mat.M[3][0] += Bias; Mat.M[3][1] += Bias; Mat.M[3][2] += Bias; Mat.M[3][3] += Bias;

	return Mat;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& InM) const
{
	Matrix4x4 Mat(*this);
	Mat.M[0][0] += InM.M[0][0]; Mat.M[0][1] += InM.M[0][1]; Mat.M[0][2] += InM.M[0][2]; Mat.M[0][3] += InM.M[0][3];
	Mat.M[1][0] += InM.M[1][0]; Mat.M[1][1] += InM.M[1][1]; Mat.M[1][2] += InM.M[1][2]; Mat.M[1][3] += InM.M[1][3];
	Mat.M[2][0] += InM.M[2][0]; Mat.M[2][1] += InM.M[2][1]; Mat.M[2][2] += InM.M[2][2]; Mat.M[2][3] += InM.M[2][3];
	Mat.M[3][0] += InM.M[3][0]; Mat.M[3][1] += InM.M[3][1]; Mat.M[3][2] += InM.M[3][2]; Mat.M[3][3] += InM.M[3][3];

	return Mat;
}

Matrix4x4 Matrix4x4::operator-(float Bias) const
{
	Matrix4x4 Mat(*this);
	Mat.M[0][0] -= Bias; Mat.M[0][1] -= Bias; Mat.M[0][2] -= Bias; Mat.M[0][3] -= Bias;
	Mat.M[1][0] -= Bias; Mat.M[1][1] -= Bias; Mat.M[1][2] -= Bias; Mat.M[1][3] -= Bias;
	Mat.M[2][0] -= Bias; Mat.M[2][1] -= Bias; Mat.M[2][2] -= Bias; Mat.M[2][3] -= Bias;
	Mat.M[3][0] -= Bias; Mat.M[3][1] -= Bias; Mat.M[3][2] -= Bias; Mat.M[3][3] -= Bias;

	return Mat;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& InM) const
{
	Matrix4x4 Mat(*this);
	Mat.M[0][0] -= InM.M[0][0]; Mat.M[0][1] -= InM.M[0][1]; Mat.M[0][2] -= InM.M[0][2]; Mat.M[0][3] -= InM.M[0][3];
	Mat.M[1][0] -= InM.M[1][0]; Mat.M[1][1] -= InM.M[1][1]; Mat.M[1][2] -= InM.M[1][2]; Mat.M[1][3] -= InM.M[1][3];
	Mat.M[2][0] -= InM.M[2][0]; Mat.M[2][1] -= InM.M[2][1]; Mat.M[2][2] -= InM.M[2][2]; Mat.M[2][3] -= InM.M[2][3];
	Mat.M[3][0] -= InM.M[3][0]; Mat.M[3][1] -= InM.M[3][1]; Mat.M[3][2] -= InM.M[3][2]; Mat.M[3][3] -= InM.M[3][3];

	return Mat;
}

Matrix4x4 Matrix4x4::operator*(float Scale) const
{
	Matrix4x4 Mat(*this);
	Mat.M[0][0] *= Scale; Mat.M[0][1] *= Scale; Mat.M[0][2] *= Scale; Mat.M[0][3] *= Scale;
	Mat.M[1][0] *= Scale; Mat.M[1][1] *= Scale; Mat.M[1][2] *= Scale; Mat.M[1][3] *= Scale;
	Mat.M[2][0] *= Scale; Mat.M[2][1] *= Scale; Mat.M[2][2] *= Scale; Mat.M[2][3] *= Scale;
	Mat.M[3][0] *= Scale; Mat.M[3][1] *= Scale; Mat.M[3][2] *= Scale; Mat.M[3][3] *= Scale;

	return Mat;
}

Vector4 Matrix4x4::operator*(const Vector4& InV) const
{
	Vector4 Vector;
	Vector.X = (M[0][0] * InV.X) + (M[0][1] * InV.Y) + (M[0][2] * InV.Z) + (M[0][3] * InV.W);
	Vector.Y = (M[1][0] * InV.X) + (M[1][1] * InV.Y) + (M[1][2] * InV.Z) + (M[1][3] * InV.W);
	Vector.Z = (M[2][0] * InV.X) + (M[2][1] * InV.Y) + (M[2][2] * InV.Z) + (M[2][3] * InV.W);
	Vector.W = (M[3][0] * InV.X) + (M[3][1] * InV.Y) + (M[3][2] * InV.Z) + (M[3][3] * InV.W);

	return Vector;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& InM) const
{
	Matrix4x4 Mat;
	Mat.M[0][0] = (M[0][0] * InM.M[0][0]) + (M[0][1] * InM.M[1][0]) + (M[0][2] * InM.M[2][0]) + (M[0][3] * InM.M[3][0]);
	Mat.M[0][1] = (M[0][0] * InM.M[0][1]) + (M[0][1] * InM.M[1][1]) + (M[0][2] * InM.M[2][1]) + (M[0][3] * InM.M[3][1]);
	Mat.M[0][2] = (M[0][0] * InM.M[0][2]) + (M[0][1] * InM.M[1][2]) + (M[0][2] * InM.M[2][2]) + (M[0][3] * InM.M[3][2]);
	Mat.M[0][3] = (M[0][0] * InM.M[0][3]) + (M[0][1] * InM.M[1][3]) + (M[0][2] * InM.M[2][3]) + (M[0][3] * InM.M[3][3]);

	Mat.M[1][0] = (M[1][0] * InM.M[0][0]) + (M[1][1] * InM.M[1][0]) + (M[1][2] * InM.M[2][0]) + (M[1][3] * InM.M[3][0]);
	Mat.M[1][1] = (M[1][0] * InM.M[0][1]) + (M[1][1] * InM.M[1][1]) + (M[1][2] * InM.M[2][1]) + (M[1][3] * InM.M[3][1]);
	Mat.M[1][2] = (M[1][0] * InM.M[0][2]) + (M[1][1] * InM.M[1][2]) + (M[1][2] * InM.M[2][2]) + (M[1][3] * InM.M[3][2]);
	Mat.M[1][3] = (M[1][0] * InM.M[0][3]) + (M[1][1] * InM.M[1][3]) + (M[1][2] * InM.M[2][3]) + (M[1][3] * InM.M[3][3]);

	Mat.M[2][0] = (M[2][0] * InM.M[0][0]) + (M[2][1] * InM.M[1][0]) + (M[2][2] * InM.M[2][0]) + (M[2][3] * InM.M[3][0]);
	Mat.M[2][1] = (M[2][0] * InM.M[0][1]) + (M[2][1] * InM.M[1][1]) + (M[2][2] * InM.M[2][1]) + (M[2][3] * InM.M[3][1]);
	Mat.M[2][2] = (M[2][0] * InM.M[0][2]) + (M[2][1] * InM.M[1][2]) + (M[2][2] * InM.M[2][2]) + (M[2][3] * InM.M[3][2]);
	Mat.M[2][3] = (M[2][0] * InM.M[0][3]) + (M[2][1] * InM.M[1][3]) + (M[2][2] * InM.M[2][3]) + (M[2][3] * InM.M[3][3]);

	Mat.M[3][0] = (M[3][0] * InM.M[0][0]) + (M[3][1] * InM.M[1][0]) + (M[3][2] * InM.M[2][0]) + (M[3][3] * InM.M[3][0]);
	Mat.M[3][1] = (M[3][0] * InM.M[0][1]) + (M[3][1] * InM.M[1][1]) + (M[3][2] * InM.M[2][1]) + (M[3][3] * InM.M[3][1]);
	Mat.M[3][2] = (M[3][0] * InM.M[0][2]) + (M[3][1] * InM.M[1][2]) + (M[3][2] * InM.M[2][2]) + (M[3][3] * InM.M[3][2]);
	Mat.M[3][3] = (M[3][0] * InM.M[0][3]) + (M[3][1] * InM.M[1][3]) + (M[3][2] * InM.M[2][3]) + (M[3][3] * InM.M[3][3]);

	return Mat;
}

Matrix4x4 Matrix4x4::operator/(float Scale) const
{
	Matrix4x4 Mat(*this);
	Mat.M[0][0] /= Scale; Mat.M[0][1] /= Scale; Mat.M[0][2] /= Scale; Mat.M[0][3] /= Scale;
	Mat.M[1][0] /= Scale; Mat.M[1][1] /= Scale; Mat.M[1][2] /= Scale; Mat.M[1][3] /= Scale;
	Mat.M[2][0] /= Scale; Mat.M[2][1] /= Scale; Mat.M[2][2] /= Scale; Mat.M[2][3] /= Scale;
	Mat.M[3][0] /= Scale; Mat.M[3][1] /= Scale; Mat.M[3][2] /= Scale; Mat.M[3][3] /= Scale;

	return Mat;
}

Matrix4x4 Matrix4x4::CreateTransition(float X, float Y, float Z)
{
	return Matrix4x4(
		1.0f, 0.0f, 0.0f, X,
		0.0f, 1.0f, 0.0f, Y,
		0.0f, 0.0f, 1.0f, Z,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateTransition(const Vector3& InV)
{
	return Matrix4x4(
		1.0f, 0.0f, 0.0f, InV.X,
		0.0f, 1.0f, 0.0f, InV.Y,
		0.0f, 0.0f, 1.0f, InV.Z,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateRotationX(float Angle)
{
	float Sin = DEGREE_SIN(Angle);
	float Cos = DEGREE_COS(Angle);

	return Matrix4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, Cos, -Sin, 0.0f,
		0.0f, Sin, Cos, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateRotationY(float Angle)
{
	float Sin = DEGREE_SIN(Angle);
	float Cos = DEGREE_COS(Angle);

	return Matrix4x4(
		Cos, 0.0f, -Sin, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		Sin, 0.0f, Cos, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateRotationZ(float Angle)
{
	float Sin = DEGREE_SIN(Angle);
	float Cos = DEGREE_COS(Angle);

	return Matrix4x4(
		Cos, -Sin, 0.0f, 0.0f,
		Sin, Cos, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateRotation(float XAngle, float YAngle, float ZAngle)
{
	Matrix4x4 RotX;
	Matrix4x4 RotY;
	Matrix4x4 RotZ;

	float Cos = DEGREE_COS(XAngle);
	float Sin = DEGREE_SIN(XAngle);
	RotX.M[0][0] = 1.0f;	RotX.M[0][1] = 0.0f;	RotX.M[0][2] = 0.0f;	RotX.M[0][3] = 0.0f;
	RotX.M[1][0] = 0.0f;	RotX.M[1][1] = Cos;		RotX.M[1][2] = -Sin;	RotX.M[1][3] = 0.0f;
	RotX.M[2][0] = 0.0f;	RotX.M[2][1] = Sin;		RotX.M[2][2] = Cos;		RotX.M[2][3] = 0.0f;
	RotX.M[3][0] = 0.0f;	RotX.M[3][1] = 0.0f;	RotX.M[3][2] = 0.0f;	RotX.M[3][3] = 1.0f;

	Cos = DEGREE_COS(YAngle);
	Sin = DEGREE_SIN(YAngle);
	RotY.M[0][0] = Cos;		RotY.M[0][1] = 0.0f;	RotY.M[0][2] = -Sin;	RotY.M[0][3] = 0.0f;
	RotY.M[1][0] = 0.0f;	RotY.M[1][1] = 1.0f;	RotY.M[1][2] = -0.0f;	RotY.M[1][3] = 0.0f;
	RotY.M[2][0] = Sin;		RotY.M[2][1] = 0.0f;	RotY.M[2][2] = Cos;		RotY.M[2][3] = 0.0f;
	RotY.M[3][0] = 0.0f;	RotY.M[3][1] = 0.0f;	RotY.M[3][2] = 0.0f;	RotY.M[3][3] = 1.0f;

	Cos = DEGREE_COS(ZAngle);
	Sin = DEGREE_SIN(ZAngle);
	RotZ.M[0][0] = Cos;		RotZ.M[0][1] = -Sin;	RotZ.M[0][2] = 0.0f;	RotZ.M[0][3] = 0.0f;
	RotZ.M[1][0] = Sin;		RotZ.M[1][1] = Cos;		RotZ.M[1][2] = 0.0f;	RotZ.M[1][3] = 0.0f;
	RotZ.M[2][0] = 0.0f;	RotZ.M[2][1] = 0.0f;	RotZ.M[2][2] = 1.0f;	RotZ.M[2][3] = 0.0f;
	RotZ.M[3][0] = 0.0f;	RotZ.M[3][1] = 0.0f;	RotZ.M[3][2] = 0.0f;	RotZ.M[3][3] = 1.0f;

	return (RotZ * (RotY * RotX));
}

Matrix4x4 Matrix4x4::CreateScale(float Scale)
{
	return Matrix4x4(
		Scale, 0.0f, 0.0f, 0.0f,
		0.0f, Scale, 0.0f, 0.0f,
		0.0f, 0.0f, Scale, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateScale(float X, float Y, float Z)
{
	return Matrix4x4(
		X, 0.0f, 0.0f, 0.0f,
		0.0f, Y, 0.0f, 0.0f,
		0.0f, 0.0f, Z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateScale(const Vector3& InV)
{
	return Matrix4x4(
		InV.X, 0.0f, 0.0f, 0.0f,
		0.0f, InV.Y, 0.0f, 0.0f,
		0.0f, 0.0f, InV.Z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreateScreenSpace(float HalfWidth, float HalfHeight)
{
	return Matrix4x4(
		HalfWidth, 0.0f, 0.0f, HalfWidth,
		0.0f, -HalfHeight, 0.0f, HalfHeight,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::CreatePerspectiveProj(float FOV, float AspectRatio, float ZMin, float ZMax)
{
	float TanOfHalfFOV = DEGREE_TAN(FOV * 0.5);
	float FocalLength = 1.0f / TanOfHalfFOV;
	float ZRange = (ZMin - ZMax);
	return Matrix4x4(
		FocalLength / AspectRatio, 0.0f, 0.0f, 0.0f,
		0.0f, FocalLength, 0.0f, 0.0f,
		0.0f, 0.0f, (-ZMin -ZMax) / ZRange, (2.0f * ZMin * ZMax) / ZRange,
		0.0f, 0.0f, 1.0f, 0.0f);
}

std::ostream& operator<<(std::ostream& Os, const Matrix4x4& InM)
{
	Os << InM.M[0][0] << '	' << InM.M[0][1] << '	' << InM.M[0][2] << '	' << InM.M[0][3] << std::endl;
	Os << InM.M[1][0] << '	' << InM.M[1][1] << '	' << InM.M[1][2] << '	' << InM.M[1][3] << std::endl;
	Os << InM.M[2][0] << '	' << InM.M[2][1] << '	' << InM.M[2][2] << '	' << InM.M[2][3] << std::endl;
	Os << InM.M[3][0] << '	' << InM.M[3][1] << '	' << InM.M[3][2] << '	' << InM.M[3][3] << std::endl;

	return Os;
}

std::string Matrix4x4::ToString() const
{
	using namespace std;
	string Result = 
		to_string(M[0][0]) + "	" + to_string(M[0][1]) + "	" + to_string(M[0][2]) + "	" + to_string(M[0][3]) + "\n"
		+ to_string(M[1][0]) + "	" + to_string(M[1][1]) + "	" + to_string(M[1][2]) + "	" + to_string(M[1][3]) + "\n"
		+ to_string(M[2][0]) + "	" + to_string(M[2][1]) + "	" + to_string(M[2][2]) + "	" + to_string(M[2][3]) + "\n"
		+ to_string(M[3][0]) + "	" + to_string(M[3][1]) + "	" + to_string(M[3][2]) + "	" + to_string(M[3][3]) + "\n";

	return Result;
}