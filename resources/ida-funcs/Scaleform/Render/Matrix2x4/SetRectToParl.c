Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::SetRectToParl(
        Scaleform::Render::Matrix2x4<float> *this,
        float x1,
        float y1,
        float x2,
        float y2,
        float *parl)
{
  float v7[6]; // [esp+0h] [ebp-18h] BYREF

  v7[0] = x1;
  v7[1] = y1;
  v7[2] = x2;
  v7[4] = x2;
  v7[3] = y1;
  v7[5] = y2;
  return Scaleform::Render::Matrix2x4<float>::SetParlToParl(this, v7, parl);
}
