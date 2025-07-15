void __userpurge btPolyhedralConvexAabbCachingShape::getNonvirtualAabb(
        btPolyhedralConvexAabbCachingShape *this@<ecx>,
        float *a2@<eax>,
        unsigned __int64 *a3@<edi>,
        float *a4@<esi>,
        float a5@<xmm7>,
        const struct btTransform *aabbMin,
        struct btVector3 *a7,
        struct btVector3 *a8,
        float a9)
{
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // [esp+14h] [ebp-50h]
  float v19; // [esp+14h] [ebp-50h]
  float v20; // [esp+18h] [ebp-4Ch]
  float _X; // [esp+18h] [ebp-4Ch]
  float v22; // [esp+1Ch] [ebp-48h]
  float v23; // [esp+1Ch] [ebp-48h]
  float v24; // [esp+20h] [ebp-44h]
  float v25; // [esp+24h] [ebp-40h]
  float v26; // [esp+28h] [ebp-3Ch]
  float v27; // [esp+2Ch] [ebp-38h]
  float v28; // [esp+30h] [ebp-34h]
  float v29; // [esp+34h] [ebp-30h]
  float v30; // [esp+38h] [ebp-2Ch]
  float v31; // [esp+3Ch] [ebp-28h]
  float v32; // [esp+40h] [ebp-24h]
  float v33; // [esp+44h] [ebp-20h]
  float v34; // [esp+48h] [ebp-1Ch]
  float v35; // [esp+4Ch] [ebp-18h]
  float v36; // [esp+54h] [ebp-10h]
  unsigned __int64 v37; // [esp+54h] [ebp-10h]
  float v38; // [esp+58h] [ebp-Ch]
  float v39; // [esp+5Ch] [ebp-8h]

  v9 = a2[20];
  v10 = a2[21];
  v11 = a2[22];
  v22 = a2[24];
  v20 = a2[25];
  v18 = a2[26];
  v36 = (float)((float)(v22 - v9) * 0.5) + a5;
  v38 = (float)((float)(v20 - v10) * 0.5) + a5;
  v39 = (float)((float)(v18 - v11) * 0.5) + a5;
  v33 = (float)(v9 + v22) * 0.5;
  v34 = (float)(v10 + v20) * 0.5;
  v35 = (float)(v11 + v18) * 0.5;
  v30 = fabsf(a4[10]);
  v31 = fabsf(a4[9]);
  v32 = fabsf(a4[8]);
  v27 = fabsf(a4[6]);
  v28 = fabsf(a4[5]);
  v29 = fabsf(a4[4]);
  _X = a4[2];
  v24 = fabsf(_X);
  v19 = a4[1];
  v25 = fabsf(v19);
  v23 = *a4;
  v26 = fabsf(*a4);
  v12 = (float)((float)((float)(a4[6] * v35) + (float)(a4[5] * v34)) + (float)(a4[4] * v33)) + a4[13];
  v13 = (float)((float)((float)(a4[10] * v35) + (float)(a4[9] * v34)) + (float)(a4[8] * v33)) + a4[14];
  v14 = (float)((float)(v39 * v24) + (float)(v38 * v25)) + (float)(v26 * v36);
  v15 = (float)((float)(v39 * v30) + (float)(v38 * v31)) + (float)(v36 * v32);
  v16 = (float)((float)((float)(v19 * v34) + (float)(_X * v35)) + (float)(v23 * v33)) + a4[12];
  v17 = (float)((float)(v39 * v27) + (float)(v38 * v28)) + (float)(v29 * v36);
  *(float *)&v37 = v16 - v14;
  *((float *)&v37 + 1) = v12 - v17;
  aabbMin->m_basis.m_el[0].mVec128.m128_u64[0] = v37;
  aabbMin->m_basis.m_el[0].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v13 - v15);
  *(float *)&v37 = v14 + v16;
  *((float *)&v37 + 1) = v17 + v12;
  *a3 = v37;
  a3[1] = COERCE_UNSIGNED_INT(v15 + v13);
}
