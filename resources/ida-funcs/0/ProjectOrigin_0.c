void __usercall ProjectOrigin_0(
        const btVector3 *b@<eax>,
        float *sqd@<edx>,
        const btVector3 *a,
        const btVector3 *c,
        btVector3 *prj)
{
  float v5; // xmm5_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm7_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm6_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm7_4
  const btVector3 *v21; // eax
  float *v22; // edx
  float *v23; // edx
  float v24; // [esp+Ch] [ebp-58h]
  float v25; // [esp+Ch] [ebp-58h]
  float v26; // [esp+10h] [ebp-54h]
  __int64 v27; // [esp+14h] [ebp-50h]
  float v29; // [esp+1Ch] [ebp-48h]
  __int64 v30; // [esp+20h] [ebp-44h]
  float v32; // [esp+28h] [ebp-3Ch]
  float v33; // [esp+30h] [ebp-34h]
  float v34; // [esp+34h] [ebp-30h]
  float v35; // [esp+38h] [ebp-2Ch]
  float v36; // [esp+3Ch] [ebp-28h]
  float v37; // [esp+48h] [ebp-1Ch]
  float v38; // [esp+4Ch] [ebp-18h]

  v5 = b->mVec128.m128_f32[1];
  v6 = a->mVec128.m128_f32[0];
  v7 = a->mVec128.m128_f32[1];
  v8 = a->mVec128.m128_f32[2];
  v30 = *(__int64 *)((char *)c->mVec128.m128_i64 + 4);
  v38 = *((float *)&v30 + 1) - v8;
  v37 = *(float *)&v30 - v7;
  v9 = v5 - v7;
  v10 = b->mVec128.m128_f32[2] - v8;
  v11 = (float)(v9 * (float)(*((float *)&v30 + 1) - v8)) - (float)(v10 * v37);
  v12 = (float)(v10 * (float)(c->mVec128.m128_f32[0] - v6)) - (float)((float)(b->mVec128.m128_f32[0] - v6) * v38);
  v13 = (float)((float)(b->mVec128.m128_f32[0] - v6) * v37) - (float)(v9 * (float)(c->mVec128.m128_f32[0] - v6));
  v14 = (float)((float)(v13 * v13) + (float)(v12 * v12)) + (float)(v11 * v11);
  v34 = v11;
  v35 = v12;
  v36 = v13;
  if ( v14 > 0.00000011920929 )
  {
    v15 = s_bm_current_air_resistance / fsqrt(v14);
    v16 = v12 * v15;
    v17 = v13 * v15;
    v27 = *(__int64 *)((char *)a->mVec128.m128_i64 + 4);
    v24 = (float)((float)(*((float *)&v27 + 1) * v17) + (float)(*(float *)&v27 * v16))
        + (float)(v6 * (float)(v11 * v15));
    v33 = v24 * v24;
    if ( *sqd > (float)(v24 * v24) )
    {
      v18 = v16 * v24;
      v19 = v17 * v24;
      v20 = (float)(v11 * v15) * v24;
      v25 = b->mVec128.m128_f32[0] - v20;
      v26 = v6 - v20;
      *(float *)&v27 = *(float *)&v27 - v18;
      v32 = v5 - v18;
      *((float *)&v27 + 1) = *((float *)&v27 + 1) - v19;
      if ( (float)((float)((float)((float)((float)(v32 * v26) - (float)(*(float *)&v27 * v25)) * v36)
                         + (float)((float)((float)(*((float *)&v27 + 1) * v25)
                                         - (float)((float)(b->mVec128.m128_f32[2] - v19) * v26))
                                 * v35))
                 + (float)((float)((float)(*(float *)&v27 * (float)(b->mVec128.m128_f32[2] - v19))
                                 - (float)(*((float *)&v27 + 1) * v32))
                         * v34)) <= 0.0
        || (v29 = c->mVec128.m128_f32[0] - v20,
            *(float *)&v30 = *(float *)&v30 - v18,
            *((float *)&v30 + 1) = *((float *)&v30 + 1) - v19,
            (float)((float)((float)((float)((float)(*(float *)&v30 * v25) - (float)(v32 * v29)) * v36)
                          + (float)((float)((float)((float)(b->mVec128.m128_f32[2] - v19) * v29)
                                          - (float)(*((float *)&v30 + 1) * v25))
                                  * v35))
                  + (float)((float)((float)(v32 * *((float *)&v30 + 1))
                                  - (float)((float)(b->mVec128.m128_f32[2] - v19) * *(float *)&v30))
                          * v34)) <= 0.0)
        || (float)((float)((float)((float)((float)(*(float *)&v27 * v29) - (float)(*(float *)&v30 * v26)) * v36)
                         + (float)((float)((float)(*((float *)&v30 + 1) * v26) - (float)(*((float *)&v27 + 1) * v29))
                                 * v35))
                 + (float)((float)((float)(*(float *)&v30 * *((float *)&v27 + 1))
                                 - (float)(*((float *)&v30 + 1) * *(float *)&v27))
                         * v34)) <= 0.0 )
      {
        ProjectOrigin(b, sqd, a, prj);
        ProjectOrigin(c, v22, v21, prj);
        ProjectOrigin(a, v23, c, prj);
      }
      else
      {
        prj->mVec128.m128_f32[0] = v20;
        prj->mVec128.m128_f32[1] = v18;
        prj->mVec128.m128_u64[1] = LODWORD(v19);
        *sqd = v33;
      }
    }
  }
}
