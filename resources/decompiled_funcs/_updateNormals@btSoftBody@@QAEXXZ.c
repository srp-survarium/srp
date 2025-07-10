void __thiscall btSoftBody::updateNormals(btSoftBody *this, btSoftBody *thisa)
{
  _DWORD *v2; // esi
  int m_size; // edx
  int v4; // ecx
  __m128 *p_mVec128; // eax
  int v6; // ebx
  int v7; // edi
  float *v8; // eax
  float *v9; // esi
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm5_4
  int v13; // edi
  float *v14; // eax
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm6_4
  float *v18; // eax
  float v19; // xmm3_4
  float *v20; // edi
  float v21; // xmm3_4
  bool v22; // zf
  float v23; // xmm0_4
  int v24; // ebx
  int v25; // ecx
  float *v26; // edi
  long double v27; // st7
  float v28; // xmm0_4
  int v29; // [esp+70h] [ebp-28h]
  int v30; // [esp+70h] [ebp-28h]
  float v31; // [esp+74h] [ebp-24h]
  float v32; // [esp+74h] [ebp-24h]
  float v33; // [esp+78h] [ebp-20h]
  float v34; // [esp+7Ch] [ebp-1Ch]
  float v35; // [esp+80h] [ebp-18h]
  __int64 v36; // [esp+88h] [ebp-10h]
  __int64 v37; // [esp+90h] [ebp-8h]

  v2 = &thisa->__vftable;
  m_size = thisa->m_nodes.m_size;
  if ( m_size > 0 )
  {
    v4 = 0;
    do
    {
      p_mVec128 = &thisa->m_nodes.m_data[v4++].m_n.mVec128;
      --m_size;
      p_mVec128->m128_u64[0] = 0;
      p_mVec128->m128_u64[1] = 0;
    }
    while ( m_size );
  }
  if ( thisa->m_faces.m_size > 0 )
  {
    HIDWORD(v37) = 0;
    v6 = 0;
    v29 = thisa->m_faces.m_size;
    do
    {
      v7 = v2[192];
      v8 = *(float **)(v7 + v6 + 16);
      v9 = *(float **)(v7 + v6 + 8);
      v10 = v8[5] - v9[5];
      v11 = v8[6] - v9[6];
      v12 = v8[4] - v9[4];
      v13 = v6 + v7;
      v14 = *(float **)(v13 + 12);
      v15 = v14[5] - v9[5];
      v16 = v14[6] - v9[6];
      v17 = v14[4] - v9[4];
      v35 = (float)(v10 * v17) - (float)(v15 * v12);
      v34 = (float)(v16 * v12) - (float)(v11 * v17);
      v33 = (float)(v15 * v11) - (float)(v16 * v10);
      v31 = 1.0 / sqrtf((float)((float)(v35 * v35) + (float)(v34 * v34)) + (float)(v33 * v33));
      *(float *)&v36 = v33 * v31;
      *((float *)&v36 + 1) = v34 * v31;
      *(_QWORD *)(v13 + 32) = v36;
      *(float *)&v37 = v35 * v31;
      *(_QWORD *)(v13 + 40) = v37;
      v9[20] = v9[20] + v33;
      v9[21] = v9[21] + v34;
      v9[22] = v9[22] + v35;
      v18 = *(float **)(v13 + 12);
      v19 = v18[20];
      v18 += 20;
      *v18 = v19 + v33;
      v2 = &thisa->__vftable;
      v18[1] = v18[1] + v34;
      v18[2] = v18[2] + v35;
      v20 = *(float **)(v13 + 16);
      v21 = v20[20];
      v20 += 20;
      v20[1] = v20[1] + v34;
      v6 += 64;
      v22 = v29-- == 1;
      v23 = v20[2] + v35;
      *v20 = v21 + v33;
      v20[2] = v23;
    }
    while ( !v22 );
  }
  if ( (int)v2[180] > 0 )
  {
    v24 = 0;
    v30 = v2[180];
    do
    {
      v25 = v2[182];
      v26 = (float *)(v24 + v25 + 80);
      v27 = sqrtf(
              (float)((float)(*v26 * *v26) + (float)(*(float *)(v24 + v25 + 84) * *(float *)(v24 + v25 + 84)))
            + (float)(*(float *)(v24 + v25 + 88) * *(float *)(v24 + v25 + 88)));
      v32 = v27;
      if ( v27 > 0.00000011920929 )
      {
        v28 = *(float *)&clear_value / v32;
        *v26 = *v26 * (float)(*(float *)&clear_value / v32);
        v26[1] = v26[1] * v28;
        v26[2] = v26[2] * v28;
      }
      v24 += 112;
      --v30;
    }
    while ( v30 );
  }
}
