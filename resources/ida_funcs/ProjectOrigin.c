void __usercall ProjectOrigin(const btVector3 *b@<eax>, btVector3 *prj@<edx>, float *sqd@<esi>, const btVector3 *a)
{
  float v4; // xmm4_4
  float v5; // xmm6_4
  float v6; // xmm5_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  const vostok::math::float4x4 *v11; // xmm7_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm0_4

  v4 = a->mVec128.m128_f32[0];
  v5 = a->mVec128.m128_f32[2];
  v6 = a->mVec128.m128_f32[1];
  v7 = b->mVec128.m128_f32[0] - a->mVec128.m128_f32[0];
  v8 = b->mVec128.m128_f32[2] - v5;
  v9 = b->mVec128.m128_f32[1] - v6;
  if ( (float)((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)) > 0.00000011920929 )
  {
    v10 = -(float)((float)((float)((float)(v5 * v8) + (float)(v4 * v7)) + (float)(v6 * v9))
                 / (float)((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)));
    *(float *)&v11 = 0.0;
    if ( v10 < 0.0 || (v11 = clear_value, v10 > *(float *)&clear_value) )
      v10 = *(float *)&v11;
    v12 = v4 + (float)(v7 * v10);
    v13 = v6 + (float)(v9 * v10);
    v14 = v5 + (float)(v8 * v10);
    v15 = (float)((float)(v14 * v14) + (float)(v12 * v12)) + (float)(v13 * v13);
    if ( *sqd > v15 )
    {
      prj->mVec128.m128_u64[0] = __PAIR64__(LODWORD(v13), LODWORD(v12));
      prj->mVec128.m128_u64[1] = LODWORD(v14);
      *sqd = v15;
    }
  }
}
