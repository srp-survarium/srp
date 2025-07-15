btVector3 *__usercall BaryCoord@<eax>(
        const btVector3 *a@<edi>,
        const btVector3 *b@<esi>,
        const btVector3 *c@<edx>,
        const btVector3 *p@<ecx>,
        btVector3 *a5)
{
  btVector3 *result; // eax
  float v6; // xmm7_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm7_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // [esp+0h] [ebp-40h]
  float v28; // [esp+4h] [ebp-3Ch]
  float v29; // [esp+8h] [ebp-38h]
  float v30; // [esp+Ch] [ebp-34h]
  float v31; // [esp+10h] [ebp-30h]
  float v32; // [esp+14h] [ebp-2Ch]
  float v33; // [esp+28h] [ebp-18h]
  float v34; // [esp+30h] [ebp-10h]

  result = a5;
  v6 = p->mVec128.m128_f32[1];
  v7 = b->mVec128.m128_f32[1];
  v8 = a->mVec128.m128_f32[0] - p->mVec128.m128_f32[0];
  v27 = a->mVec128.m128_f32[1];
  v32 = v27 - v6;
  v33 = b->mVec128.m128_f32[2] - p->mVec128.m128_f32[2];
  v28 = a->mVec128.m128_f32[2];
  v9 = v7 - v6;
  v10 = v28 - p->mVec128.m128_f32[2];
  v34 = (float)(v33 * (float)(v27 - v6)) - (float)((float)(v7 - v6) * v10);
  v11 = p->mVec128.m128_f32[2];
  v31 = fsqrt(
          (float)((float)((float)((float)(v9 * v8)
                                - (float)((float)(b->mVec128.m128_f32[0] - p->mVec128.m128_f32[0]) * v32))
                        * (float)((float)(v9 * v8)
                                - (float)((float)(b->mVec128.m128_f32[0] - p->mVec128.m128_f32[0]) * v32)))
                + (float)((float)((float)(v10 * (float)(b->mVec128.m128_f32[0] - p->mVec128.m128_f32[0]))
                                - (float)(v8 * v33))
                        * (float)((float)(v10 * (float)(b->mVec128.m128_f32[0] - p->mVec128.m128_f32[0]))
                                - (float)(v8 * v33))))
        + (float)(v34 * v34));
  v12 = c->mVec128.m128_f32[0] - p->mVec128.m128_f32[0];
  v29 = c->mVec128.m128_f32[1];
  v13 = v29 - p->mVec128.m128_f32[1];
  v30 = c->mVec128.m128_f32[2];
  v14 = b->mVec128.m128_f32[2] - v11;
  v15 = v7 - p->mVec128.m128_f32[1];
  v16 = v11;
  v17 = (float)((float)((float)((float)(v13 * (float)(b->mVec128.m128_f32[0] - p->mVec128.m128_f32[0]))
                              - (float)(v15 * v12))
                      * (float)((float)(v13 * (float)(b->mVec128.m128_f32[0] - p->mVec128.m128_f32[0]))
                              - (float)(v15 * v12)))
              + (float)((float)((float)(v14 * v12)
                              - (float)((float)(v30 - v11) * (float)(b->mVec128.m128_f32[0] - p->mVec128.m128_f32[0])))
                      * (float)((float)(v14 * v12)
                              - (float)((float)(v30 - v11) * (float)(b->mVec128.m128_f32[0] - p->mVec128.m128_f32[0])))))
      + (float)((float)((float)(v15 * (float)(v30 - v11)) - (float)(v14 * v13))
              * (float)((float)(v15 * (float)(v30 - v11)) - (float)(v14 * v13)));
  v18 = v28 - v11;
  v19 = fsqrt(v17);
  v20 = p->mVec128.m128_f32[1];
  v21 = v27 - v20;
  v22 = v29 - v20;
  v23 = v30 - v16;
  v24 = (float)(v22 * (float)(v28 - v16)) - (float)((float)(v30 - v16) * v21);
  v25 = fsqrt(
          (float)((float)((float)((float)(v21 * v12) - (float)(v22 * v8))
                        * (float)((float)(v21 * v12) - (float)(v22 * v8)))
                + (float)((float)((float)(v23 * v8) - (float)(v18 * v12))
                        * (float)((float)(v23 * v8) - (float)(v18 * v12))))
        + (float)(v24 * v24));
  v26 = s_bm_current_air_resistance / (float)((float)(v25 + v19) + v31);
  a5->mVec128.m128_f32[0] = v26 * v19;
  a5->mVec128.m128_f32[2] = v26 * v31;
  a5->mVec128.m128_f32[1] = v26 * v25;
  a5->mVec128.m128_i32[3] = 0;
  return result;
}
