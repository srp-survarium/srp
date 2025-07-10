Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::PrependScaling(
        Scaleform::Render::Matrix2x4<float> *this,
        float scale)
{
  Scaleform::Render::Matrix2x4<float> m; // [esp+0h] [ebp-20h] BYREF

  m.M[0][0] = scale;
  m.M[0][1] = 0.0;
  m.M[0][2] = 0.0;
  m.M[0][3] = 0.0;
  m.M[1][0] = 0.0;
  m.M[1][2] = 0.0;
  m.M[1][3] = 0.0;
  m.M[1][1] = scale;
  return Scaleform::Render::Matrix2x4<float>::Prepend(this, &m);
}
