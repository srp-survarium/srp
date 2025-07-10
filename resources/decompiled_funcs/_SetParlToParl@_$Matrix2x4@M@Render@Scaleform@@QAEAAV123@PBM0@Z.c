Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::SetParlToParl(
        Scaleform::Render::Matrix2x4<float> *this,
        const float *src,
        const float *dst)
{
  float v6; // [esp+2Ch] [ebp-34h]
  float v7; // [esp+30h] [ebp-30h]
  float v8; // [esp+34h] [ebp-2Ch]
  float v9; // [esp+38h] [ebp-28h]
  float v10; // [esp+3Ch] [ebp-24h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+40h] [ebp-20h] BYREF

  v6 = src[4] - *src;
  v7 = *src;
  v8 = src[3] - src[1];
  v9 = src[5] - src[1];
  v10 = src[1];
  this->M[0][0] = src[2] - v7;
  this->M[0][1] = v6;
  this->M[0][2] = 0.0;
  this->M[0][3] = v7;
  this->M[1][0] = v8;
  this->M[1][1] = v9;
  this->M[1][2] = 0.0;
  this->M[1][3] = v10;
  m.M[0][0] = dst[2] - *dst;
  m.M[0][1] = dst[4] - *dst;
  m.M[0][2] = 0.0;
  m.M[0][3] = *dst;
  m.M[1][0] = dst[3] - dst[1];
  m.M[1][1] = dst[5] - dst[1];
  m.M[1][2] = 0.0;
  m.M[1][3] = dst[1];
  Scaleform::Render::Matrix2x4<float>::Invert(this);
  Scaleform::Render::Matrix2x4<float>::Append(this, &m);
  return this;
}
