double __cdecl Scaleform::Render::TextMeshProvider::calcHeightRatio(
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        Scaleform::Render::Matrix4x4<float> *m4,
        const Scaleform::Render::Viewport *vp)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // ecx
  float *v4; // eax
  float Width; // [esp+Ch] [ebp-8Ch]
  float v7; // [esp+Ch] [ebp-8Ch]
  float Height; // [esp+10h] [ebp-88h]
  float v9; // [esp+10h] [ebp-88h]
  float v10; // [esp+14h] [ebp-84h]
  float MaxScale; // [esp+24h] [ebp-74h]
  float v12; // [esp+24h] [ebp-74h]
  float v13; // [esp+24h] [ebp-74h]
  float v14; // [esp+24h] [ebp-74h]
  float v15; // [esp+24h] [ebp-74h]
  float v16; // [esp+24h] [ebp-74h]
  __m128 v17; // [esp+28h] [ebp-70h] BYREF
  float v18[6]; // [esp+40h] [ebp-58h] BYREF
  Scaleform::Render::Matrix2x4<float> v19; // [esp+58h] [ebp-40h] BYREF
  __m128 v20[2]; // [esp+78h] [ebp-20h] BYREF

  pHandle = m->pHandle;
  v4 = (float *)(&m->pHandle->pHeader[1].RefCount
               + 4 * (unsigned __int8)byte_874214[5 * (m->pHandle->pHeader->Format & 0xF)]);
  v19.M[0][0] = *v4;
  v19.M[0][1] = v4[1];
  v19.M[0][2] = v4[2];
  v19.M[0][3] = v4[3];
  v19.M[1][0] = v4[4];
  v19.M[1][1] = v4[5];
  v19.M[1][2] = v4[6];
  v19.M[1][3] = v4[7];
  if ( (pHandle->pHeader->Format & 0x10) != 0 )
  {
    v17.m128_f32[0] = 0.0;
    v17.m128_f32[1] = 0.0;
    v17.m128_f32[2] = 1.0;
    v17.m128_f32[3] = 1.0;
    Height = (float)vp->Height;
    Width = (float)vp->Width;
    Scaleform::Render::Matrix4x4<float>::TransformHomogeneousAndScaleCorners(m4, &v17, Width, Height, v20);
    v18[0] = 0.0;
    v18[1] = 0.0;
    v18[2] = 1.0;
    v18[4] = 1.0;
    v18[5] = 1.0;
    v18[3] = 0.0;
    Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v19, v18, v20[0].m128_f32);
    MaxScale = Scaleform::Render::Matrix2x4<float>::GetMaxScale(&v19);
    if ( MaxScale < 0.0000099999997 )
      return (float)0.0000099999997;
    return MaxScale;
  }
  else
  {
    v12 = v19.M[1][0] * 0.0 + v19.M[1][1];
    v10 = v12;
    v13 = v19.M[0][0] * 0.0 + v19.M[0][1];
    v9 = v13;
    v14 = v19.M[1][0] + v19.M[1][1] * 0.0;
    v7 = v14;
    v15 = v19.M[0][0] + v19.M[0][1] * 0.0;
    v16 = fabs(Scaleform::Render::Math2D::LinePointDistance(0.0, 0.0, v15, v7, v9, v10));
    if ( v16 < 0.0000000099999999 )
      return (float)0.0000000099999999;
    return v16;
  }
}
