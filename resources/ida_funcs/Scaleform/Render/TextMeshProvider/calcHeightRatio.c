double __cdecl Scaleform::Render::TextMeshProvider::calcHeightRatio(
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        Scaleform::Render::Matrix4x4<float> *m4,
        const Scaleform::Render::Viewport *vp)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // ecx
  float *v4; // eax
  float sx; // [esp+138h] [ebp-8Ch]
  float sxa; // [esp+138h] [ebp-8Ch]
  float sy; // [esp+13Ch] [ebp-88h]
  float sya; // [esp+13Ch] [ebp-88h]
  float y; // [esp+140h] [ebp-84h]
  float MaxScale; // [esp+150h] [ebp-74h]
  float v12; // [esp+150h] [ebp-74h]
  float v13; // [esp+150h] [ebp-74h]
  float v14; // [esp+150h] [ebp-74h]
  float x2; // [esp+150h] [ebp-74h]
  float v16; // [esp+150h] [ebp-74h]
  Scaleform::Render::Rect<float> v17; // [esp+154h] [ebp-70h] BYREF
  float src[6]; // [esp+16Ch] [ebp-58h] BYREF
  Scaleform::Render::Matrix2x4<float> v19; // [esp+184h] [ebp-40h] BYREF
  __m128 dest[2]; // [esp+1A4h] [ebp-20h] BYREF

  pHandle = m->pHandle;
  v4 = (float *)(&m->pHandle->pHeader[1].RefCount
               + 4 * (unsigned __int8)byte_9B2B74[5 * (m->pHandle->pHeader->Format & 0xF)]);
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
    v17.x1 = 0.0;
    v17.y1 = 0.0;
    v17.x2 = 1.0;
    v17.y2 = 1.0;
    sy = (float)vp->Height;
    sx = (float)vp->Width;
    Scaleform::Render::Matrix4x4<float>::TransformHomogeneousAndScaleCorners(m4, (__m128 *)&v17, sx, sy, dest);
    src[0] = 0.0;
    src[1] = 0.0;
    src[2] = 1.0;
    src[4] = 1.0;
    src[5] = 1.0;
    src[3] = 0.0;
    Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v19, src, dest[0].m128_f32);
    MaxScale = Scaleform::Render::Matrix2x4<float>::GetMaxScale(&v19);
    if ( MaxScale < 0.0000099999997 )
      return (float)0.0000099999997;
    return MaxScale;
  }
  else
  {
    v12 = v19.M[1][0] * 0.0 + v19.M[1][1];
    y = v12;
    v13 = v19.M[0][0] * 0.0 + v19.M[0][1];
    sya = v13;
    v14 = v19.M[1][0] + v19.M[1][1] * 0.0;
    sxa = v14;
    x2 = v19.M[0][0] + v19.M[0][1] * 0.0;
    v16 = fabs(Scaleform::Render::Math2D::LinePointDistance(0.0, 0.0, x2, sxa, sya, y));
    if ( v16 < 0.0000000099999999 )
      return (float)0.0000000099999999;
    return v16;
  }
}
