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
