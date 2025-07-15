Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::AppendRotation(
        Scaleform::Render::Matrix2x4<float> *this,
        float radians)
{
  float v3; // [esp+4h] [ebp-28h]
  float v4; // [esp+4h] [ebp-28h]
  float v5; // [esp+8h] [ebp-24h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+Ch] [ebp-20h] BYREF

  v3 = cos(radians);
  v5 = v3;
  v4 = sin(radians);
  m.M[0][0] = v5;
  m.M[0][1] = -v4;
  m.M[0][2] = 0.0;
  m.M[0][3] = 0.0;
  m.M[1][2] = 0.0;
  m.M[1][3] = 0.0;
  m.M[1][0] = v4;
  m.M[1][1] = v5;
  return Scaleform::Render::Matrix2x4<float>::Append(this, &m);
}


Scaleform::Render::Matrix2x4<double> *__thiscall Scaleform::Render::Matrix2x4<double>::AppendRotation(
        Scaleform::Render::Matrix2x4<double> *this,
        long double radians)
{
  long double v2; // st7
  Scaleform::Render::Matrix2x4<double> m; // [esp+8h] [ebp-40h] BYREF

  v2 = sin(radians);
  m.M[0][0] = cos(radians);
  m.M[0][1] = -v2;
  m.M[0][2] = 0.0;
  m.M[0][3] = 0.0;
  m.M[1][2] = 0.0;
  m.M[1][3] = 0.0;
  m.M[1][0] = v2;
  m.M[1][1] = m.M[0][0];
  return Scaleform::Render::Matrix2x4<double>::Append_NonOpt(this, &m);
}
