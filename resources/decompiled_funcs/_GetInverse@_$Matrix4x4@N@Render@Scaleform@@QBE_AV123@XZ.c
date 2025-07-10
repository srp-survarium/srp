Scaleform::Render::Matrix4x4<double> *__thiscall Scaleform::Render::Matrix4x4<double>::GetInverse(
        Scaleform::Render::Matrix4x4<double> *this,
        Scaleform::Render::Matrix4x4<double> *result)
{
  long double st7_1; // st7
  long double st6_1; // st6
  long double st5_1; // st5
  long double v6; // st4
  long double v7; // st3
  long double v8; // st2
  long double v10; // st2
  long double v11; // rt2
  double v12; // st2
  double v3; // [esp+B0h] [ebp-150h]
  double v3a; // [esp+B0h] [ebp-150h]
  double v4; // [esp+B8h] [ebp-148h]
  double v4a; // [esp+B8h] [ebp-148h]
  double v1; // [esp+C0h] [ebp-140h]
  long double v1a; // [esp+C0h] [ebp-140h]
  double m11; // [esp+C8h] [ebp-138h]
  double m12; // [esp+D0h] [ebp-130h]
  double v2; // [esp+D8h] [ebp-128h]
  long double v2a; // [esp+D8h] [ebp-128h]
  double v0; // [esp+E0h] [ebp-120h]
  long double v0a; // [esp+E0h] [ebp-120h]
  long double v0b; // [esp+E0h] [ebp-120h]
  double m31; // [esp+E8h] [ebp-118h]
  double m33; // [esp+F0h] [ebp-110h]
  long double m33a; // [esp+F0h] [ebp-110h]
  double d02; // [esp+F8h] [ebp-108h]
  double m32; // [esp+100h] [ebp-100h]
  long double m32a; // [esp+100h] [ebp-100h]
  double m13; // [esp+108h] [ebp-F8h]
  double m22; // [esp+110h] [ebp-F0h]
  double m21; // [esp+120h] [ebp-E0h]
  double m23; // [esp+128h] [ebp-D8h]
  double m20; // [esp+130h] [ebp-D0h]
  double v5; // [esp+138h] [ebp-C8h]
  double t00; // [esp+140h] [ebp-C0h]
  double t10; // [esp+148h] [ebp-B8h]
  double t20; // [esp+150h] [ebp-B0h]
  double t30; // [esp+158h] [ebp-A8h]
  long double d11; // [esp+160h] [ebp-A0h]
  long double d31; // [esp+168h] [ebp-98h]
  long double d01; // [esp+170h] [ebp-90h]
  long double d21; // [esp+178h] [ebp-88h]
  Scaleform::Render::Matrix4x4<double> tmp; // [esp+180h] [ebp-80h] BYREF

  st7_1 = this->M[0][0];
  st6_1 = this->M[0][1];
  st5_1 = this->M[0][2];
  v6 = this->M[0][3];
  v7 = this->M[1][0];
  m11 = this->M[1][1];
  m12 = this->M[1][2];
  m13 = this->M[1][3];
  m20 = this->M[2][0];
  m21 = this->M[2][1];
  m22 = this->M[2][2];
  m23 = this->M[2][3];
  d02 = this->M[3][0];
  m31 = this->M[3][1];
  m32 = this->M[3][2];
  m33 = this->M[3][3];
  v0 = m20 * m31 - m21 * d02;
  v1 = m32 * m20 - d02 * m22;
  v2 = m33 * m20 - d02 * m23;
  v3 = m32 * m21 - m31 * m22;
  v4 = m33 * m21 - m31 * m23;
  v5 = m33 * m22 - m23 * m32;
  t00 = v5 * m11 - v4 * m12 + v3 * m13;
  t10 = -(v5 * v7 - v2 * m12 + v1 * m13);
  t20 = v4 * v7 - v2 * m11 + v0 * m13;
  t30 = -(v3 * v7 - v1 * m11 + v0 * m12);
  v8 = t10 * st6_1 + t00 * st7_1 + t20 * st5_1 + t30 * v6;
  if ( 0.0 == v8 )
  {
    memset((int)&tmp, 0, sizeof(tmp));
    tmp.M[0][0] = 1.0;
    tmp.M[1][1] = 1.0;
    tmp.M[2][2] = 1.0;
    tmp.M[3][3] = 1.0;
    tmp.M[0][3] = -this->M[0][3];
    tmp.M[1][3] = -this->M[1][3];
    tmp.M[2][3] = -this->M[2][3];
    memcpy((unsigned __int8 *)result, (unsigned __int8 *)&tmp, sizeof(Scaleform::Render::Matrix4x4<double>));
  }
  else
  {
    v10 = 1.0 / v8;
    d01 = -((v5 * st6_1 - v4 * st5_1 + v3 * v6) * v10);
    d11 = (v5 * st7_1 - v2 * st5_1 + v1 * v6) * v10;
    d21 = -((v4 * st7_1 - v2 * st6_1 + v0 * v6) * v10);
    d31 = (v3 * st7_1 - v1 * st6_1 + v0 * st5_1) * v10;
    v11 = v10;
    v0a = v7 * m31 - d02 * m11;
    v1a = m32 * v7 - d02 * m12;
    v2a = m33 * v7 - d02 * m13;
    v3a = m32 * m11 - m31 * m12;
    v4a = m33 * m11 - m31 * m13;
    v12 = m33 * m12 - m13 * m32;
    m33a = (v4a * st7_1 - v2a * st6_1 + v0a * v6) * v11;
    m32a = -((v3a * st7_1 - v1a * st6_1 + v0a * st5_1) * v11);
    v0b = m21 * v7 - m20 * m11;
    Scaleform::Render::Matrix4x4<double>::Matrix4x4<double>(
      result,
      v11 * t00,
      d01,
      (v12 * st6_1 - v4a * st5_1 + v3a * v6) * v11,
      -((v6 * (m22 * m11 - m21 * m12) + st6_1 * (m23 * m12 - m13 * m22) - st5_1 * (m23 * m11 - m21 * m13)) * v11),
      t10 * v11,
      d11,
      -((v12 * st7_1 - v2a * st5_1 + v1a * v6) * v11),
      (st7_1 * (m23 * m12 - m13 * m22) - (m23 * v7 - m20 * m13) * st5_1 + (m22 * v7 - m20 * m12) * v6) * v11,
      t20 * v11,
      d21,
      m33a,
      -(((m23 * m11 - m21 * m13) * st7_1 - (m23 * v7 - m20 * m13) * st6_1 + v0b * v6) * v11),
      v11 * t30,
      d31,
      m32a,
      ((m22 * m11 - m21 * m12) * st7_1 - (m22 * v7 - m20 * m12) * st6_1 + v0b * st5_1) * v11);
  }
  return result;
}
