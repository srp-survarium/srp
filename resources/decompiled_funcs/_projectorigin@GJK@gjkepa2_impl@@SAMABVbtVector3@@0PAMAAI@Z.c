float __usercall gjkepa2_impl::GJK::projectorigin@<xmm0>(
        const btVector3 *b@<eax>,
        float *w@<edx>,
        unsigned int *m@<esi>,
        const btVector3 *a)
{
  float v4; // xmm4_4
  float v5; // xmm6_4
  float v6; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  const vostok::math::float4x4 *v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm7_4

  v4 = a->mVec128.m128_f32[0];
  v5 = a->mVec128.m128_f32[2];
  v6 = a->mVec128.m128_f32[1];
  v7 = b->mVec128.m128_f32[0] - a->mVec128.m128_f32[0];
  v8 = b->mVec128.m128_f32[2] - v5;
  v9 = b->mVec128.m128_f32[1] - v6;
  if ( (float)((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)) <= 0.0 )
    return -1.0;
  v10 = -(float)((float)((float)((float)(v5 * v8) + (float)(v4 * v7)) + (float)(v6 * v9))
               / (float)((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)));
  v11 = clear_value;
  if ( v10 < *(float *)&clear_value )
  {
    if ( v10 > 0.0 )
    {
      v20 = *(float *)&clear_value - v10;
      w[1] = v10;
      *w = v20;
      *m = 3;
      return (float)((float)((float)(v5 + (float)(v8 * v10)) * (float)(v5 + (float)(v8 * v10)))
                   + (float)((float)(v4 + (float)(v7 * v10)) * (float)(v4 + (float)(v7 * v10))))
           + (float)((float)(v6 + (float)(v9 * v10)) * (float)(v6 + (float)(v9 * v10)));
    }
    else
    {
      v18 = a->mVec128.m128_f32[1];
      v19 = a->mVec128.m128_f32[2];
      *(_DWORD *)w = clear_value;
      w[1] = 0.0;
      *m = 1;
      return (float)((float)(v18 * v18) + (float)(v19 * v19)) + (float)(v4 * v4);
    }
  }
  else
  {
    v12 = b->mVec128.m128_f32[1];
    v13 = b->mVec128.m128_f32[2];
    *w = 0.0;
    v14 = v12 * v12;
    v15 = v13 * v13;
    v16 = b->mVec128.m128_f32[0];
    *((_DWORD *)w + 1) = v11;
    *m = 2;
    return (float)(v14 + v15) + (float)(v16 * v16);
  }
}
