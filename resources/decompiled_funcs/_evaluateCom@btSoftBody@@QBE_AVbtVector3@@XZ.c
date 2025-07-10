btVector3 *__userpurge btSoftBody::evaluateCom@<eax>(btSoftBody *this@<ecx>, int a2@<eax>, btVector3 *result)
{
  bool v3; // zf
  float v4; // xmm1_4
  btVector3 *v5; // esi
  int v6; // edi
  int v7; // ebx
  float *v8; // edx
  float *v9; // ecx
  unsigned int v10; // esi
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm5_4
  float v26; // xmm3_4
  float v27; // xmm6_4
  __int128 v28; // xmm4
  float v29; // xmm5_4
  float v30; // xmm6_4
  float *v31; // edx
  float *v32; // ecx
  int v33; // edi
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm1_4
  __int128 v37; // xmm0

  v3 = *(_BYTE *)(a2 + 481) == 0;
  v4 = 0.0;
  v5 = result;
  result->mVec128.m128_u64[0] = 0;
  result->mVec128.m128_u64[1] = 0;
  if ( !v3 )
  {
    v6 = *(_DWORD *)(a2 + 720);
    v7 = 0;
    if ( v6 >= 4 )
    {
      v8 = (float *)(*(_DWORD *)(a2 + 520) + 8);
      v9 = (float *)(*(_DWORD *)(a2 + 728) + 24);
      v10 = ((unsigned int)(v6 - 4) >> 2) + 1;
      v11 = 0.0;
      v12 = 0.0;
      v7 = 4 * v10;
      do
      {
        v13 = *(v8 - 2);
        v14 = v4 + (float)(*(v9 - 2) * v13);
        v15 = v11 + (float)(*(v9 - 1) * v13);
        v16 = v12 + (float)(v13 * *v9);
        v17 = *(v8 - 1);
        v18 = v9[26] * v17;
        v19 = v9[27] * v17;
        v20 = v9[28] * v17;
        v21 = v8[1];
        v22 = (float)(v14 + v18) + (float)(v9[54] * *v8);
        v23 = v9[82];
        v24 = (float)(v15 + v19) + (float)(v9[55] * *v8);
        v25 = v9[83];
        v26 = (float)(v16 + v20) + (float)(v9[56] * *v8);
        v27 = v9[84];
        v8 += 4;
        v9 += 112;
        --v10;
        v4 = v22 + (float)(v23 * v21);
        v11 = v24 + (float)(v25 * v21);
        v12 = v26 + (float)(v27 * v21);
      }
      while ( v10 );
      result->mVec128.m128_f32[0] = v4;
      result->mVec128.m128_f32[1] = v11;
      result->mVec128.m128_f32[2] = v12;
      v5 = result;
    }
    if ( v7 < v6 )
    {
      v28 = v5->mVec128.m128_u32[0];
      v29 = v5->mVec128.m128_f32[1];
      v30 = v5->mVec128.m128_f32[2];
      v31 = (float *)(*(_DWORD *)(a2 + 520) + 4 * v7);
      v32 = (float *)(*(_DWORD *)(a2 + 728) + 112 * v7 + 24);
      v33 = v6 - v7;
      do
      {
        v34 = *(v32 - 1) * *v31;
        v35 = *v32 * *v31;
        v36 = *(v32 - 2) * *v31;
        v37 = v28;
        ++v31;
        v32 += 28;
        --v33;
        *(float *)&v37 = *(float *)&v28 + v36;
        v28 = v37;
        v29 = v29 + v34;
        v30 = v30 + v35;
      }
      while ( v33 );
      v5->mVec128.m128_i32[0] = v37;
      v5->mVec128.m128_f32[1] = v29;
      v5->mVec128.m128_f32[2] = v30;
    }
  }
  return v5;
}
