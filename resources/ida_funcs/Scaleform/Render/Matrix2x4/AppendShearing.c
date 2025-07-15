Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::AppendShearing(
        Scaleform::Render::Matrix2x4<float> *this,
        float sh,
        float sv)
{
  float v4; // [esp+Ch] [ebp-24h]
  float v5; // [esp+Ch] [ebp-24h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+10h] [ebp-20h] BYREF

  m.M[0][0] = 1.0;
  v4 = tan(sv);
  m.M[0][1] = v4;
  m.M[0][2] = 0.0;
  m.M[0][3] = 0.0;
  v5 = tan(sh);
  m.M[1][0] = v5;
  m.M[1][1] = 1.0;
  m.M[1][2] = 0.0;
  m.M[1][3] = 0.0;
  return Scaleform::Render::Matrix2x4<float>::Append(this, &m);
}
