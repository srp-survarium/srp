void __usercall ProjectOrigin_0(
        const btVector3 *a@<edi>,
        float *sqd@<eax>,
        const btVector3 *b,
        const btVector3 *c,
        btVector3 *prj)
{
  float v5; // xmm3_4
  float v6; // xmm7_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm7_4
  long double v15; // st7
  float v16; // xmm7_4
  float v17; // xmm0_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  unsigned int v20; // xmm0_4
  float v21; // xmm4_4
  float v22; // xmm0_4
  const btVector3 *v23; // eax
  btVector3 *v24; // edx
  btVector3 *v25; // edx
  float v26; // [esp+78h] [ebp-48h]
  float v27; // [esp+78h] [ebp-48h]
  float _X; // [esp+7Ch] [ebp-44h]
  float v29; // [esp+7Ch] [ebp-44h]
  float v30; // [esp+80h] [ebp-40h]
  float v31; // [esp+84h] [ebp-3Ch]
  float v32; // [esp+84h] [ebp-3Ch]
  float v33; // [esp+88h] [ebp-38h]
  float v34; // [esp+88h] [ebp-38h]
  float v35; // [esp+8Ch] [ebp-34h]
  float v36; // [esp+8Ch] [ebp-34h]
  float v37; // [esp+90h] [ebp-30h]
  float v38; // [esp+90h] [ebp-30h]
  float v39; // [esp+94h] [ebp-2Ch]
  float v40; // [esp+94h] [ebp-2Ch]
  float v41; // [esp+98h] [ebp-28h]
  float v42; // [esp+9Ch] [ebp-24h]
  float v43; // [esp+A4h] [ebp-1Ch]
  float v44; // [esp+A8h] [ebp-18h]
  unsigned __int64 v45; // [esp+B8h] [ebp-8h]

  v5 = a->mVec128.m128_f32[1];
  v6 = a->mVec128.m128_f32[2];
  v30 = b->mVec128.m128_f32[0];
  v26 = a->mVec128.m128_f32[0];
  v35 = c->mVec128.m128_f32[0];
  v8 = c->mVec128.m128_f32[0] - a->mVec128.m128_f32[0];
  v33 = b->mVec128.m128_f32[2];
  v9 = v33 - v6;
  v31 = b->mVec128.m128_f32[1];
  v10 = v31 - v5;
  v37 = c->mVec128.m128_f32[1];
  v11 = v37 - v5;
  v39 = c->mVec128.m128_f32[2];
  v12 = v39 - v6;
  v13 = (float)((float)(v31 - v5) * (float)(v39 - v6)) - (float)((float)(v33 - v6) * (float)(v37 - v5));
  v14 = b->mVec128.m128_f32[0] - a->mVec128.m128_f32[0];
  v44 = (float)(v14 * v11) - (float)(v10 * v8);
  v43 = (float)(v9 * v8) - (float)(v14 * v12);
  _X = (float)((float)(v44 * v44) + (float)(v43 * v43)) + (float)(v13 * v13);
  if ( _X > 0.00000011920929 )
  {
    v15 = sqrtf(_X);
    v16 = a->mVec128.m128_f32[2];
    v29 = 1.0 / v15;
    v17 = (float)((float)(v16 * (float)(v44 * v29)) + (float)(a->mVec128.m128_f32[1] * (float)(v43 * v29)))
        + (float)(v26 * (float)(v13 * v29));
    v42 = v17 * v17;
    if ( *sqd > (float)(v17 * v17) )
    {
      v18 = (float)(v13 * v29) * v17;
      v19 = (float)(v43 * v29) * v17;
      *(float *)&v20 = (float)(v44 * v29) * v17;
      v34 = v33 - *(float *)&v20;
      v27 = v26 - v18;
      v45 = v20;
      v21 = a->mVec128.m128_f32[1] - v19;
      v41 = v16 - *(float *)&v20;
      v22 = (float)((float)(v21 * v34) - (float)((float)(v16 - *(float *)&v20) * (float)(v31 - v19))) * v13;
      v32 = v31 - v19;
      if ( (float)((float)((float)((float)((float)(v32 * v27) - (float)(v21 * (float)(v30 - v18))) * v44)
                         + (float)((float)((float)(v41 * (float)(v30 - v18)) - (float)(v34 * v27)) * v43))
                 + v22) <= 0.0
        || (v36 = v35 - v18,
            v38 = v37 - v19,
            v40 = v39 - *(float *)&v45,
            (float)((float)((float)((float)((float)(v38 * (float)(v30 - v18)) - (float)(v32 * v36)) * v44)
                          + (float)((float)((float)(v34 * v36) - (float)(v40 * (float)(v30 - v18))) * v43))
                  + (float)((float)((float)(v32 * v40) - (float)(v34 * v38)) * v13)) <= 0.0)
        || (float)((float)((float)((float)((float)(v21 * v36) - (float)(v38 * v27)) * v44)
                         + (float)((float)((float)(v40 * v27) - (float)(v41 * v36)) * v43))
                 + (float)((float)((float)(v38 * v41) - (float)(v40 * v21)) * v13)) <= 0.0 )
      {
        ProjectOrigin(b, prj, sqd, a);
        ProjectOrigin(c, v24, sqd, v23);
        ProjectOrigin(a, v25, sqd, c);
      }
      else
      {
        prj->mVec128.m128_u64[0] = __PAIR64__(LODWORD(v19), LODWORD(v18));
        prj->mVec128.m128_u64[1] = v45;
        *sqd = v42;
      }
    }
  }
}
