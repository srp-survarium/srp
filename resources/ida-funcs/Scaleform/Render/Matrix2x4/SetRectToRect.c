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
  float v10[6]; // [esp+0h] [ebp-30h] BYREF
  float v11[6]; // [esp+18h] [ebp-18h] BYREF

  v11[0] = srcX1;
  v11[1] = srcY1;
  v11[2] = srcX2;
  v11[4] = srcX2;
  v11[3] = srcY1;
  v11[5] = srcY2;
  v10[0] = dstX1;
  v10[1] = dstY1;
  v10[2] = dstX2;
  v10[4] = dstX2;
  v10[3] = dstY1;
  v10[5] = dstY2;
  return Scaleform::Render::Matrix2x4<float>::SetParlToParl(this, v11, v10);
}
