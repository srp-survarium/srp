void __usercall ProjectOrigin(const btVector3 *b@<eax>, float *sqd@<edx>, const btVector3 *a, btVector3 *prj)
{
  float v4; // xmm6_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  float v14; // xmm0_4

  v4 = a->mVec128.m128_f32[2];
  v5 = a->mVec128.m128_f32[0];
  v6 = a->mVec128.m128_f32[1];
  v7 = b->mVec128.m128_f32[0] - a->mVec128.m128_f32[0];
  v8 = b->mVec128.m128_f32[2] - v4;
  v9 = b->mVec128.m128_f32[1] - v6;
  if ( (float)((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)) > 0.00000011920929 )
  {
    LODWORD(v10) = COERCE_UNSIGNED_INT(
                     (float)((float)((float)(v4 * v8) + (float)(v5 * v7)) + (float)(v6 * v9))
                   / (float)((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)))
                 ^ _mask__NegFloat_;
    if ( v10 >= 0.0 )
    {
      if ( v10 > s_bm_current_air_resistance )
        v10 = s_bm_current_air_resistance;
      v4 = a->mVec128.m128_f32[2];
    }
    else
    {
      v10 = 0.0;
    }
    v11 = v5 + (float)(v7 * v10);
    v12 = v6 + (float)(v9 * v10);
    v13 = v4 + (float)(v8 * v10);
    v14 = (float)((float)(v13 * v13) + (float)(v11 * v11)) + (float)(v12 * v12);
    if ( *sqd > v14 )
    {
      prj->mVec128.m128_f32[0] = v11;
      prj->mVec128.m128_f32[1] = v12;
      prj->mVec128.m128_u64[1] = LODWORD(v13);
      *sqd = v14;
    }
  }
}
