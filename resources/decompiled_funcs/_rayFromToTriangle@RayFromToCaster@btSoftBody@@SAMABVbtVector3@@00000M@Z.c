float __usercall btSoftBody::RayFromToCaster::rayFromToTriangle@<xmm0>(
        const btVector3 *rayFrom@<edi>,
        const btVector3 *a@<esi>,
        const btVector3 *b@<ecx>,
        const btVector3 *c@<eax>,
        const btVector3 *rayTo,
        const btVector3 *rayNormalizedDirection)
{
  float v6; // xmm4_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm6_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float result; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm6_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  float v20; // xmm1_4
  float v21; // xmm4_4
  float _X; // [esp+C8h] [ebp-50h]
  float v23; // [esp+C8h] [ebp-50h]
  float v24; // [esp+CCh] [ebp-4Ch]
  float v25; // [esp+D0h] [ebp-48h]
  float v26; // [esp+D0h] [ebp-48h]
  float v27; // [esp+D4h] [ebp-44h]
  float v28; // [esp+D8h] [ebp-40h]
  float v29; // [esp+DCh] [ebp-3Ch]
  float v30; // [esp+E0h] [ebp-38h]
  float v31; // [esp+E4h] [ebp-34h]
  float v32; // [esp+E4h] [ebp-34h]
  float v33; // [esp+E8h] [ebp-30h]
  float v34; // [esp+E8h] [ebp-30h]
  float v35; // [esp+ECh] [ebp-2Ch]
  float v36; // [esp+F0h] [ebp-28h]
  float v37; // [esp+F0h] [ebp-28h]
  float v38; // [esp+F4h] [ebp-24h]
  float v39; // [esp+F4h] [ebp-24h]
  float v40; // [esp+100h] [ebp-18h]
  float v41; // [esp+108h] [ebp-10h]
  float v42; // [esp+10Ch] [ebp-Ch]

  v6 = a->mVec128.m128_f32[1];
  v35 = c->mVec128.m128_f32[0];
  v41 = c->mVec128.m128_f32[0] - a->mVec128.m128_f32[0];
  v7 = a->mVec128.m128_f32[2];
  v30 = b->mVec128.m128_f32[0];
  v8 = b->mVec128.m128_f32[0] - a->mVec128.m128_f32[0];
  v31 = b->mVec128.m128_f32[1];
  v24 = a->mVec128.m128_f32[0];
  v38 = c->mVec128.m128_f32[2];
  v33 = b->mVec128.m128_f32[2];
  v36 = c->mVec128.m128_f32[1];
  v9 = v8 * (float)(v38 - v7);
  v10 = (float)(v8 * (float)(v36 - v6)) - (float)((float)(v31 - v6) * v41);
  v11 = (float)((float)(v33 - v7) * v41) - v9;
  v12 = (float)((float)(v31 - v6) * (float)(v38 - v7)) - (float)((float)(v33 - v7) * (float)(v36 - v6));
  v25 = (float)((float)(v7 * v10) + (float)(v6 * v11)) + (float)(a->mVec128.m128_f32[0] * v12);
  v28 = rayTo->mVec128.m128_f32[1];
  v40 = v10;
  v29 = rayTo->mVec128.m128_f32[2];
  _X = (float)((float)(v28 * v11) + (float)(v29 * v10)) + (float)(rayTo->mVec128.m128_f32[0] * v12);
  v27 = rayTo->mVec128.m128_f32[0];
  if ( fabsf(_X) < 0.00000011920929 )
    return -1.0;
  result = (float)((float)((float)((float)(rayFrom->mVec128.m128_f32[1] * v11)
                                 + (float)(rayFrom->mVec128.m128_f32[2] * v10))
                         + (float)(rayFrom->mVec128.m128_f32[0] * v12))
                 - v25)
         * (float)(-1.0 / _X);
  if ( result <= 0.0000011920929 )
    return -1.0;
  if ( *(float *)&rayNormalizedDirection <= result )
    return -1.0;
  v14 = rayFrom->mVec128.m128_f32[0] + (float)(v27 * result);
  v23 = v30 - v14;
  v15 = v24 - v14;
  v16 = rayFrom->mVec128.m128_f32[2] + (float)(v29 * result);
  v17 = a->mVec128.m128_f32[2] - v16;
  v18 = v33 - v16;
  v26 = v15;
  v42 = rayFrom->mVec128.m128_f32[1] + (float)(v28 * result);
  v19 = a->mVec128.m128_f32[1] - v42;
  v20 = (float)((float)(v19 * (float)(v33 - v16)) - (float)(v17 * (float)(v31 - v42))) * v12;
  v32 = v31 - v42;
  v34 = v18;
  if ( (float)((float)((float)((float)((float)(v32 * v26) - (float)(v19 * v23)) * v40)
                     + (float)((float)((float)(v17 * v23) - (float)(v18 * v26)) * v11))
             + v20) <= -0.0000011920929 )
    return -1.0;
  v37 = v36 - v42;
  v39 = v38 - (float)(rayFrom->mVec128.m128_f32[2] + (float)(v29 * result));
  v21 = v35 - (float)(rayFrom->mVec128.m128_f32[0] + (float)(v27 * result));
  if ( (float)((float)((float)((float)((float)(v37 * v23) - (float)(v32 * v21)) * v40)
                     + (float)((float)((float)(v34 * v21) - (float)(v39 * v23)) * v11))
             + (float)((float)((float)(v32 * v39) - (float)(v34 * v37)) * v12)) <= -0.0000011920929
    || (float)((float)((float)((float)((float)(v19 * v21) - (float)(v37 * v26)) * v40)
                     + (float)((float)((float)(v39 * v26) - (float)(v17 * v21)) * v11))
             + (float)((float)((float)(v37 * v17) - (float)(v39 * v19)) * v12)) <= -0.0000011920929 )
  {
    return -1.0;
  }
  return result;
}
