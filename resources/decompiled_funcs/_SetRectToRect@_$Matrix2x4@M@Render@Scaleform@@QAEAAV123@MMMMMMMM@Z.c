Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::SetRectToRect(
        Scaleform::Render::Matrix2x4<float> *this,
        float srcX1,
        float srcY1,
        float srcX2,
        float srcY2,
        float dstX1,
        float dstY1,
        float dstX2,
        float dstY2)
{
  float dst[6]; // [esp+0h] [ebp-30h] BYREF
  float src[6]; // [esp+18h] [ebp-18h] BYREF

  src[0] = srcX1;
  src[1] = srcY1;
  src[2] = srcX2;
  src[4] = srcX2;
  src[3] = srcY1;
  src[5] = srcY2;
  dst[0] = dstX1;
  dst[1] = dstY1;
  dst[2] = dstX2;
  dst[4] = dstX2;
  dst[3] = dstY1;
  dst[5] = dstY2;
  return Scaleform::Render::Matrix2x4<float>::SetParlToParl(this, src, dst);
}
