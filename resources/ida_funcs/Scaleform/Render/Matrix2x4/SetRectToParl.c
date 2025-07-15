Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::SetRectToParl(
        Scaleform::Render::Matrix2x4<float> *this,
        float x1,
        float y1,
        float x2,
        float y2,
        const float *parl)
{
  float src[6]; // [esp+0h] [ebp-18h] BYREF

  src[0] = x1;
  src[1] = y1;
  src[2] = x2;
  src[4] = x2;
  src[3] = y1;
  src[5] = y2;
  return Scaleform::Render::Matrix2x4<float>::SetParlToParl(this, src, parl);
}
