#include "stdafx.h"
#include "MathUtils.h"
#include "Vector.h"
#include "Matrix4x4.h"

Matrix4x4 Matrix4x4::Identity(
	Vector4(1.0f, 0.0f, 0.0f, 0.0f),
	Vector4(0.0f, 1.0f, 0.0f, 0.0f),
	Vector4(0.0f, 0.0f, 1.0f, 0.0f),
	Vector4(0.0f, 0.0f, 0.0f, 1.0f)
	);

Matrix4x4::Matrix4x4(float InF) :
	M11(InF), M12(InF), M13(InF), M14(InF),
	M21(InF), M22(InF), M23(InF), M24(InF),
	M31(InF), M32(InF), M33(InF), M34(InF),
	M41(InF), M42(InF), M43(InF), M44(InF)
{
}

Matrix4x4::Matrix4x4(float InM11, float InM12, float InM13, float InM14, float InM21, float InM22, float InM23, float InM24, float InM31, float InM32, float InM33, float InM34, float InM41, float InM42, float InM43, float InM44) :
	M11(InM11), M12(InM12), M13(InM13), M14(InM14),
	M21(InM21), M22(InM22), M23(InM23), M24(InM24),
	M31(InM31), M32(InM32), M33(InM33), M34(InM34),
	M41(InM41), M42(InM42), M43(InM43), M44(InM44)
{

}

Matrix4x4::Matrix4x4(const Vector4& InColumn1, const Vector4& InColumn2, const Vector4& InColumn3, const Vector4& InColumn4) :
	M11(InColumn1.X), M12(InColumn2.X), M13(InColumn3.X), M14(InColumn4.X),
	M21(InColumn1.Y), M22(InColumn2.Y), M23(InColumn3.Y), M24(InColumn4.Y),
	M31(InColumn1.Z), M32(InColumn2.Z), M33(InColumn3.Z), M34(InColumn4.Z),
	M41(InColumn1.W), M42(InColumn2.W), M43(InColumn3.W), M44(InColumn4.W)
{

}

Matrix4x4::Matrix4x4(const Matrix4x4& InM) :
	M11(InM.M11), M12(InM.M12), M13(InM.M13), M14(InM.M14),
	M21(InM.M21), M22(InM.M22), M23(InM.M23), M24(InM.M24),
	M31(InM.M31), M32(InM.M32), M33(InM.M33), M34(InM.M34),
	M41(InM.M41), M42(InM.M42), M43(InM.M43), M44(InM.M44)
{

}

Matrix4x4& Matrix4x4::operator=(float Bias)
{
	M11 = M12 = M13 = M14 = Bias;
	M21 = M22 = M23 = M24 = Bias;
	M31 = M32 = M33 = M34 = Bias;
	M41 = M42 = M43 = M44 = Bias;

	return *this;
}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& InM)
{
	M11 = InM.M11; M12 = InM.M12; M13 = InM.M13; M14 = InM.M14;
	M21 = InM.M21; M22 = InM.M22; M23 = InM.M23; M24 = InM.M24;
	M31 = InM.M31; M32 = InM.M32; M33 = InM.M33; M34 = InM.M34;
	M41 = InM.M41; M42 = InM.M42; M43 = InM.M43; M44 = InM.M44;

	return *this;
}

Matrix4x4 Matrix4x4::operator+(float Bias) const
{
	Matrix4x4 Mat(*this);
	Mat.M11 += Bias; Mat.M12 += Bias; Mat.M13 += Bias; Mat.M14 += Bias;
	Mat.M21 += Bias; Mat.M22 += Bias; Mat.M23 += Bias; Mat.M24 += Bias;
	Mat.M31 += Bias; Mat.M32 += Bias; Mat.M33 += Bias; Mat.M34 += Bias;
	Mat.M41 += Bias; Mat.M42 += Bias; Mat.M43 += Bias; Mat.M44 += Bias;

	return Mat;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& InM) const
{
	Matrix4x4 Mat(*this);
	Mat.M11 += InM.M11; Mat.M12 += InM.M12; Mat.M13 += InM.M13; Mat.M14 += InM.M14;
	Mat.M21 += InM.M21; Mat.M22 += InM.M22; Mat.M23 += InM.M23; Mat.M24 += InM.M24;
	Mat.M31 += InM.M31; Mat.M32 += InM.M32; Mat.M33 += InM.M33; Mat.M34 += InM.M34;
	Mat.M41 += InM.M41; Mat.M42 += InM.M42; Mat.M43 += InM.M43; Mat.M44 += InM.M44;

	return Mat;
}

Matrix4x4 Matrix4x4::operator-(float Bias) const
{
	Matrix4x4 Mat(*this);
	Mat.M11 -= Bias; Mat.M12 -= Bias; Mat.M13 -= Bias; Mat.M14 -= Bias;
	Mat.M21 -= Bias; Mat.M22 -= Bias; Mat.M23 -= Bias; Mat.M24 -= Bias;
	Mat.M31 -= Bias; Mat.M32 -= Bias; Mat.M33 -= Bias; Mat.M34 -= Bias;
	Mat.M41 -= Bias; Mat.M42 -= Bias; Mat.M43 -= Bias; Mat.M44 -= Bias;

	return Mat;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& InM) const
{
	Matrix4x4 Mat(*this);
	Mat.M11 -= InM.M11; Mat.M12 -= InM.M12; Mat.M13 -= InM.M13; Mat.M14 -= InM.M14;
	Mat.M21 -= InM.M21; Mat.M22 -= InM.M22; Mat.M23 -= InM.M23; Mat.M24 -= InM.M24;
	Mat.M31 -= InM.M31; Mat.M32 -= InM.M32; Mat.M33 -= InM.M33; Mat.M34 -= InM.M34;
	Mat.M41 -= InM.M41; Mat.M42 -= InM.M42; Mat.M43 -= InM.M43; Mat.M44 -= InM.M44;

	return Mat;
}

Matrix4x4 Matrix4x4::operator*(float Scale) const
{
	Matrix4x4 Mat(*this);
	Mat.M11 *= Scale; Mat.M12 *= Scale; Mat.M13 *= Scale; Mat.M14 *= Scale;
	Mat.M21 *= Scale; Mat.M22 *= Scale; Mat.M23 *= Scale; Mat.M24 *= Scale;
	Mat.M31 *= Scale; Mat.M32 *= Scale; Mat.M33 *= Scale; Mat.M34 *= Scale;
	Mat.M41 *= Scale; Mat.M42 *= Scale; Mat.M43 *= Scale; Mat.M44 *= Scale;

	return Mat;
}

Vector4 Matrix4x4::operator*(const Vector4& InV) const
{
	Vector4 Vector;
	Vector.X = (M11 * InV.X) + (M12 * InV.Y) + (M13 * InV.Z) + (M14 * InV.W);
	Vector.Y = (M21 * InV.X) + (M22 * InV.Y) + (M23 * InV.Z) + (M24 * InV.W);
	Vector.Z = (M31 * InV.X) + (M32 * InV.Y) + (M33 * InV.Z) + (M34 * InV.W);
	Vector.W = (M41 * InV.X) + (M42 * InV.Y) + (M43 * InV.Z) + (M44 * InV.W);

	return Vector;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& InM) const
{
	Matrix4x4 Mat;
	Mat.M11 = (M11 * InM.M11) + (M12 * InM.M21) + (M13 * InM.M31) + (M14 * InM.M41);
	Mat.M12 = (M11 * InM.M12) + (M12 * InM.M22) + (M13 * InM.M32) + (M14 * InM.M42);
	Mat.M13 = (M11 * InM.M13) + (M12 * InM.M23) + (M13 * InM.M33) + (M14 * InM.M43);
	Mat.M14 = (M11 * InM.M14) + (M12 * InM.M24) + (M13 * InM.M34) + (M14 * InM.M44);

	Mat.M21 = (M21 * InM.M11) + (M22 * InM.M21) + (M23 * InM.M31) + (M24 * InM.M41);
	Mat.M22 = (M21 * InM.M12) + (M22 * InM.M22) + (M23 * InM.M32) + (M24 * InM.M42);
	Mat.M23 = (M21 * InM.M13) + (M22 * InM.M23) + (M23 * InM.M33) + (M24 * InM.M43);
	Mat.M24 = (M21 * InM.M14) + (M22 * InM.M24) + (M23 * InM.M34) + (M24 * InM.M44);

	Mat.M31 = (M31 * InM.M11) + (M32 * InM.M21) + (M33 * InM.M31) + (M34 * InM.M41);
	Mat.M32 = (M31 * InM.M12) + (M32 * InM.M22) + (M33 * InM.M32) + (M34 * InM.M42);
	Mat.M33 = (M31 * InM.M13) + (M32 * InM.M23) + (M33 * InM.M33) + (M34 * InM.M43);
	Mat.M34 = (M31 * InM.M14) + (M32 * InM.M24) + (M33 * InM.M34) + (M34 * InM.M44);

	Mat.M41 = (M41 * InM.M11) + (M42 * InM.M21) + (M43 * InM.M31) + (M44 * InM.M41);
	Mat.M42 = (M41 * InM.M12) + (M42 * InM.M22) + (M43 * InM.M32) + (M44 * InM.M42);
	Mat.M43 = (M41 * InM.M13) + (M42 * InM.M23) + (M43 * InM.M33) + (M44 * InM.M43);
	Mat.M44 = (M41 * InM.M14) + (M42 * InM.M24) + (M43 * InM.M34) + (M44 * InM.M44);

	return Mat;
}

Matrix4x4 Matrix4x4::operator/(float Scale) const
{
	Matrix4x4 Mat(*this);
	Mat.M11 /= Scale; Mat.M12 /= Scale; Mat.M13 /= Scale; Mat.M14 /= Scale;
	Mat.M21 /= Scale; Mat.M22 /= Scale; Mat.M23 /= Scale; Mat.M24 /= Scale;
	Mat.M31 /= Scale; Mat.M32 /= Scale; Mat.M33 /= Scale; Mat.M34 /= Scale;
	Mat.M41 /= Scale; Mat.M42 /= Scale; Mat.M43 /= Scale; Mat.M44 /= Scale;

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
	return Matrix4x4();
}

Matrix4x4 Matrix4x4::CreateRotationY(float Angle)
{
	return Matrix4x4();
}

Matrix4x4 Matrix4x4::CreateRotationZ(float Angle)
{
	return Matrix4x4();
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

std::ostream& operator<<(std::ostream& Os, const Matrix4x4& InM)
{
	Os << InM.M11 << '	' << InM.M12 << '	' << InM.M13 << '	' << InM.M14 << std::endl;
	Os << InM.M21 << '	' << InM.M22 << '	' << InM.M23 << '	' << InM.M24 << std::endl;
	Os << InM.M31 << '	' << InM.M32 << '	' << InM.M33 << '	' << InM.M34 << std::endl;
	Os << InM.M41 << '	' << InM.M42 << '	' << InM.M43 << '	' << InM.M44 << std::endl;

	return Os;
}

std::string Matrix4x4::ToString() const
{
	using namespace std;
	string Result = 
		to_string(M11) + "	" + to_string(M12) + "	" + to_string(M13) + "	" + to_string(M14) + "\n"
		+ to_string(M21) + "	" + to_string(M22) + "	" + to_string(M23) + "	" + to_string(M24) + "\n"
		+ to_string(M31) + "	" + to_string(M32) + "	" + to_string(M33) + "	" + to_string(M34) + "\n"
		+ to_string(M41) + "	" + to_string(M42) + "	" + to_string(M43) + "	" + to_string(M44) + "\n";

	return Result;
}