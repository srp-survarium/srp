float __usercall btSoftBody::RayFromToCaster::rayFromToTriangle@<xmm0>(
        const btVector3 *rayFrom@<edi>,
        const btVector3 *rayNormalizedDirection@<esi>,
        const btVector3 *b@<edx>,
        const btVector3 *c@<ecx>,
        const btVector3 *rayTo,
        const btVector3 *a)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm5_4
  float v9; // xmm3_4
  float v10; // xmm7_4
  float v11; // xmm2_4
  float result; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // [esp+8h] [ebp-58h]
  float v16; // [esp+8h] [ebp-58h]
  float v17; // [esp+10h] [ebp-50h]
  float v18; // [esp+10h] [ebp-50h]
  float v19; // [esp+10h] [ebp-50h]
  float v20; // [esp+14h] [ebp-4Ch]
  float v21; // [esp+1Ch] [ebp-44h]
  float v22; // [esp+1Ch] [ebp-44h]
  float v23; // [esp+20h] [ebp-40h]
  float v24; // [esp+20h] [ebp-40h]
  unsigned __int64 v25; // [esp+24h] [ebp-3Ch]
  float v26; // [esp+2Ch] [ebp-34h]
  float v27; // [esp+2Ch] [ebp-34h]
  float v28; // [esp+30h] [ebp-30h]
  float v29; // [esp+38h] [ebp-28h]
  float v30; // [esp+40h] [ebp-20h]
  float v31; // [esp+44h] [ebp-1Ch]
  float v32; // [esp+48h] [ebp-18h]

  v6 = rayTo->mVec128.m128_f32[0];
  v7 = rayTo->mVec128.m128_f32[1];
  v8 = b->mVec128.m128_f32[1];
  v25 = c->mVec128.m128_u64[0];
  v17 = rayTo->mVec128.m128_f32[2];
  v26 = c->mVec128.m128_f32[2];
  v23 = b->mVec128.m128_f32[2];
  v28 = (float)((float)(v8 - v7) * (float)(v26 - v17))
      - (float)((float)(v23 - v17) * (float)(c->mVec128.m128_f32[1] - v7));
  v9 = rayNormalizedDirection->mVec128.m128_f32[1];
  v29 = (float)((float)(b->mVec128.m128_f32[0] - v6) * (float)(c->mVec128.m128_f32[1] - v7))
      - (float)((float)(v8 - v7) * (float)(c->mVec128.m128_f32[0] - v6));
  v10 = (float)((float)(v23 - v17) * (float)(c->mVec128.m128_f32[0] - v6))
      - (float)((float)(b->mVec128.m128_f32[0] - v6) * (float)(v26 - v17));
  v11 = rayNormalizedDirection->mVec128.m128_f32[2];
  v20 = (float)((float)(v17 * v29) + (float)(rayTo->mVec128.m128_f32[1] * v10))
      + (float)(rayTo->mVec128.m128_f32[0] * v28);
  v15 = (float)(v9 * v10) + (float)(v11 * v29);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v15 + (float)(rayNormalizedDirection->mVec128.m128_f32[0] * v28)) & _mask__AbsFloat_) < 0.00000011920929 )
    return FLOAT_N1_0;
  v18 = rayFrom->mVec128.m128_f32[2];
  v21 = rayFrom->mVec128.m128_f32[1];
  result = (float)((float)((float)((float)(v21 * v10) + (float)(v18 * v29)) + (float)(rayFrom->mVec128.m128_f32[0] * v28))
                 - v20)
         * (float)(-1.0 / (float)(v15 + (float)(rayNormalizedDirection->mVec128.m128_f32[0] * v28)));
  if ( result <= 0.0000011920929 )
    return FLOAT_N1_0;
  if ( *(float *)&a <= result )
    return FLOAT_N1_0;
  v30 = rayFrom->mVec128.m128_f32[0] + (float)(rayNormalizedDirection->mVec128.m128_f32[0] * result);
  v31 = v21 + (float)(v9 * result);
  v32 = v18 + (float)(v11 * result);
  v16 = b->mVec128.m128_f32[0] - v30;
  v13 = rayTo->mVec128.m128_f32[1] - v31;
  v24 = v23 - v32;
  v22 = v8 - v31;
  v14 = rayTo->mVec128.m128_f32[2] - v32;
  v19 = v6 - v30;
  if ( (float)((float)((float)((float)((float)(v22 * v19) - (float)(v13 * v16)) * v29)
                     + (float)((float)((float)(v14 * v16) - (float)(v24 * v19)) * v10))
             + (float)((float)((float)(v13 * v24) - (float)(v14 * v22)) * v28)) <= -0.0000011920929 )
    return FLOAT_N1_0;
  *((float *)&v25 + 1) = *((float *)&v25 + 1) - v31;
  v27 = v26 - v32;
  if ( (float)((float)((float)((float)((float)(*((float *)&v25 + 1) * v16) - (float)(v22 * (float)(*(float *)&v25 - v30)))
                             * v29)
                     + (float)((float)((float)(v24 * (float)(*(float *)&v25 - v30)) - (float)(v27 * v16)) * v10))
             + (float)((float)((float)(v22 * v27) - (float)(v24 * *((float *)&v25 + 1))) * v28)) <= -0.0000011920929
    || (float)((float)((float)((float)((float)(v13 * (float)(*(float *)&v25 - v30)) - (float)(*((float *)&v25 + 1) * v19))
                             * v29)
                     + (float)((float)((float)(v27 * v19) - (float)(v14 * (float)(*(float *)&v25 - v30))) * v10))
             + (float)((float)((float)(*((float *)&v25 + 1) * v14) - (float)(v27 * v13)) * v28)) <= -0.0000011920929 )
  {
    return FLOAT_N1_0;
  }
  return result;
}
