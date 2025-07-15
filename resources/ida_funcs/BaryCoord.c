btVector3 *__usercall BaryCoord@<eax>(
        const btVector3 *a@<ecx>,
        const btVector3 *b@<eax>,
        const btVector3 *p@<esi>,
        int a4@<edi>,
        const btVector3 *c)
{
  float v5; // xmm3_4
  float v6; // xmm7_4
  float v7; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm7_4
  float v10; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v24; // [esp+1Ch] [ebp-30h]
  float v25; // [esp+1Ch] [ebp-30h]
  float v26; // [esp+20h] [ebp-2Ch]
  float v27; // [esp+24h] [ebp-28h]
  float v28; // [esp+28h] [ebp-24h]
  float v29; // [esp+2Ch] [ebp-20h]
  float v30; // [esp+30h] [ebp-1Ch]
  float v31; // [esp+34h] [ebp-18h]
  float v32; // [esp+38h] [ebp-14h]
  float v33; // [esp+3Ch] [ebp-10h]
  float v34; // [esp+40h] [ebp-Ch]
  float v35; // [esp+44h] [ebp-8h]
  float v36; // [esp+48h] [ebp-4h]

  v5 = p->mVec128.m128_f32[1];
  v6 = p->mVec128.m128_f32[2];
  v7 = b->mVec128.m128_f32[0] - p->mVec128.m128_f32[0];
  v24 = p->mVec128.m128_f32[0];
  v28 = b->mVec128.m128_f32[2];
  v8 = v28 - v6;
  v31 = a->mVec128.m128_f32[2];
  v9 = v31 - v6;
  v27 = b->mVec128.m128_f32[1];
  v10 = v27 - v5;
  v29 = a->mVec128.m128_f32[0] - p->mVec128.m128_f32[0];
  v30 = a->mVec128.m128_f32[1];
  v26 = v7;
  v34 = sqrtf(
          (float)((float)((float)((float)(v29 * v10) - (float)(v7 * (float)(v30 - v5)))
                        * (float)((float)(v29 * v10) - (float)(v7 * (float)(v30 - v5))))
                + (float)((float)((float)(v9 * v7) - (float)(v8 * v29)) * (float)((float)(v9 * v7) - (float)(v8 * v29))))
        + (float)((float)((float)(v8 * (float)(v30 - v5)) - (float)(v9 * v10))
                * (float)((float)(v8 * (float)(v30 - v5)) - (float)(v9 * v10))));
  v11 = p->mVec128.m128_f32[1];
  v12 = p->mVec128.m128_f32[2];
  v25 = c->mVec128.m128_f32[0] - v24;
  v32 = c->mVec128.m128_f32[1];
  v13 = v32 - v11;
  v14 = v27 - v11;
  v33 = c->mVec128.m128_f32[2];
  v35 = sqrtf(
          (float)((float)((float)((float)(v13 * v26) - (float)(v14 * v25))
                        * (float)((float)(v13 * v26) - (float)(v14 * v25)))
                + (float)((float)((float)((float)(v28 - v12) * v25) - (float)((float)(v33 - v12) * v26))
                        * (float)((float)((float)(v28 - v12) * v25) - (float)((float)(v33 - v12) * v26))))
        + (float)((float)((float)(v14 * (float)(v33 - v12)) - (float)((float)(v28 - v12) * v13))
                * (float)((float)(v14 * (float)(v33 - v12)) - (float)((float)(v28 - v12) * v13))));
  v15 = p->mVec128.m128_f32[1];
  v16 = p->mVec128.m128_f32[2];
  v17 = v30 - v15;
  v18 = v31 - v16;
  v19 = v32 - v15;
  v20 = v33 - v16;
  v21 = (float)(v19 * (float)(v31 - v16)) - (float)((float)(v33 - v16) * v17);
  v36 = sqrtf(
          (float)((float)((float)((float)(v17 * v25) - (float)(v19 * v29))
                        * (float)((float)(v17 * v25) - (float)(v19 * v29)))
                + (float)((float)((float)(v20 * v29) - (float)(v18 * v25))
                        * (float)((float)(v20 * v29) - (float)(v18 * v25))))
        + (float)(v21 * v21));
  v22 = *(float *)&clear_value / (float)((float)(v36 + v35) + v34);
  *(float *)(a4 + 8) = v22 * v34;
  *(float *)a4 = v22 * v35;
  *(float *)(a4 + 4) = v22 * v36;
  *(_DWORD *)(a4 + 12) = 0;
  return (btVector3 *)a4;
}
