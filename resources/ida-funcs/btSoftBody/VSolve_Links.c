void __cdecl btSoftBody::VSolve_Links(btSoftBody *psb, float kst)
{
  int m_size; // eax
  int v3; // ecx
  int v4; // edi
  btSoftBody::Link *m_data; // eax
  float *v6; // edx
  float *v7; // ecx
  float v8; // xmm6_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  btSoftBody::Link *v18; // ecx
  float *v19; // edx
  float v20; // xmm0_4
  float *v21; // eax
  float *v22; // ecx
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  btSoftBody::Link *v30; // edx
  float *v31; // ecx
  float v32; // xmm0_4
  float v33; // xmm6_4
  int v34; // eax
  float *v35; // edx
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm5_4
  float v39; // xmm1_4
  float v40; // xmm4_4
  float v41; // xmm5_4
  btSoftBody::Link *v42; // eax
  float *v43; // edx
  float *v44; // ecx
  float v45; // xmm0_4
  float v46; // xmm6_4
  float *v47; // eax
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm5_4
  float v51; // xmm1_4
  float v52; // xmm4_4
  float v53; // xmm5_4
  bool v54; // zf
  int v55; // edi
  int v56; // ebx
  btSoftBody::Link *v57; // eax
  float *v58; // edx
  float *v59; // ecx
  float v60; // xmm0_4
  float v61; // xmm6_4
  float *v62; // eax
  float v63; // xmm0_4
  float v64; // xmm1_4
  float v65; // xmm5_4
  float v66; // xmm1_4
  float v67; // xmm4_4
  float v68; // xmm5_4
  float v69; // xmm1_4
  float v70; // xmm0_4
  unsigned int v71; // [esp+14h] [ebp-Ch]
  int v72; // [esp+18h] [ebp-8h]
  int v73; // [esp+1Ch] [ebp-4h]

  m_size = psb->m_links.m_size;
  v3 = 0;
  v72 = m_size;
  if ( m_size >= 4 )
  {
    v71 = ((unsigned int)(m_size - 4) >> 2) + 1;
    v4 = 0;
    v73 = 4 * v71;
    do
    {
      m_data = psb->m_links.m_data;
      v6 = (float *)m_data[v4].m_n[0];
      v7 = (float *)m_data[v4].m_n[1];
      v8 = m_data[v4].m_c3.mVec128.m128_f32[2];
      v9 = m_data[v4].m_c3.mVec128.m128_f32[1];
      v10 = (float)((float)((float)(v8 * (float)(v6[14] - v7[14])) + (float)(v9 * (float)(v6[13] - v7[13])))
                  + (float)(m_data[v4].m_c3.mVec128.m128_f32[0] * (float)(v6[12] - v7[12])))
          * m_data[v4].m_c2;
      v11 = m_data[v4].m_c3.mVec128.m128_f32[0];
      v12 = (float *)&m_data[v4];
      v13 = -(float)(v10 * kst);
      v14 = v6[24] * v13;
      v6[12] = v6[12] + (float)(v11 * v14);
      v6[13] = v6[13] + (float)(v9 * v14);
      v6[14] = v6[14] + (float)(v8 * v14);
      v15 = v7[24] * v13;
      v16 = v12[13] * v15;
      v17 = v12[14] * v15;
      v7[12] = v7[12] - (float)(v12[12] * v15);
      v7[13] = v7[13] - v16;
      v7[14] = v7[14] - v17;
      v18 = psb->m_links.m_data;
      v19 = (float *)v18[v4 + 1].m_n[0];
      v20 = v18[v4 + 1].m_c3.mVec128.m128_f32[2];
      v21 = (float *)&v18[v4 + 1];
      v22 = (float *)v18[v4 + 1].m_n[1];
      v23 = -(float)((float)((float)((float)((float)(v20 * (float)(v19[14] - v22[14]))
                                           + (float)(v21[13] * (float)(v19[13] - v22[13])))
                                   + (float)(v21[12] * (float)(v19[12] - v22[12])))
                           * v21[8])
                   * kst);
      v24 = v19[24] * v23;
      v25 = v21[13] * v24;
      v26 = v21[14] * v24;
      v19[12] = v19[12] + (float)(v21[12] * v24);
      v19[13] = v19[13] + v25;
      v19[14] = v19[14] + v26;
      v27 = v22[24] * v23;
      v28 = v21[13] * v27;
      v29 = v21[14] * v27;
      v22[12] = v22[12] - (float)(v21[12] * v27);
      v22[13] = v22[13] - v28;
      v22[14] = v22[14] - v29;
      v30 = psb->m_links.m_data;
      v31 = (float *)v30[v4 + 2].m_n[1];
      v32 = v30[v4 + 2].m_c3.mVec128.m128_f32[2];
      v33 = v32;
      v34 = (int)&v30[v4 + 2];
      v35 = *(float **)(v34 + 8);
      v36 = -(float)((float)((float)((float)((float)(v32 * (float)(v35[14] - v31[14]))
                                           + (float)(*(float *)(v34 + 52) * (float)(v35[13] - v31[13])))
                                   + (float)(*(float *)(v34 + 48) * (float)(v35[12] - v31[12])))
                           * *(float *)(v34 + 32))
                   * kst);
      v37 = v35[24] * v36;
      v38 = *(float *)(v34 + 52) * v37;
      v35[12] = v35[12] + (float)(*(float *)(v34 + 48) * v37);
      v35[13] = v35[13] + v38;
      v35[14] = v35[14] + (float)(v33 * v37);
      v39 = v31[24] * v36;
      v40 = *(float *)(v34 + 52) * v39;
      v41 = *(float *)(v34 + 56) * v39;
      v31[12] = v31[12] - (float)(*(float *)(v34 + 48) * v39);
      v31[13] = v31[13] - v40;
      v31[14] = v31[14] - v41;
      v42 = psb->m_links.m_data;
      v43 = (float *)v42[v4 + 3].m_n[0];
      v44 = (float *)v42[v4 + 3].m_n[1];
      v45 = v42[v4 + 3].m_c3.mVec128.m128_f32[2];
      v46 = v45;
      v47 = (float *)&v42[v4 + 3];
      v48 = -(float)((float)((float)((float)((float)(v45 * (float)(v43[14] - v44[14]))
                                           + (float)(v47[13] * (float)(v43[13] - v44[13])))
                                   + (float)(v47[12] * (float)(v43[12] - v44[12])))
                           * v47[8])
                   * kst);
      v49 = v43[24] * v48;
      v50 = v47[13] * v49;
      v43[12] = v43[12] + (float)(v47[12] * v49);
      v43[13] = v43[13] + v50;
      v43[14] = v43[14] + (float)(v46 * v49);
      v51 = v44[24] * v48;
      v52 = v47[13] * v51;
      v53 = v47[14] * v51;
      v44[12] = v44[12] - (float)(v47[12] * v51);
      v44[13] = v44[13] - v52;
      v4 += 4;
      v54 = v71-- == 1;
      v44[14] = v44[14] - v53;
    }
    while ( !v54 );
    m_size = v72;
    v3 = v73;
  }
  if ( v3 < m_size )
  {
    v55 = v3 << 6;
    v56 = m_size - v3;
    do
    {
      v57 = psb->m_links.m_data;
      v58 = *(float **)((char *)v57->m_n + v55);
      v59 = *(float **)((char *)&v57->m_n[1] + v55);
      v60 = *(float *)((char *)&v57->m_c3.mVec128.m128_f32[2] + v55);
      v61 = v60;
      v62 = (float *)((char *)v57 + v55);
      v63 = -(float)((float)((float)((float)((float)(v60 * (float)(v58[14] - v59[14]))
                                           + (float)(v62[13] * (float)(v58[13] - v59[13])))
                                   + (float)(v62[12] * (float)(v58[12] - v59[12])))
                           * v62[8])
                   * kst);
      v64 = v58[24] * v63;
      v65 = v62[13] * v64;
      v58[12] = v58[12] + (float)(v62[12] * v64);
      v58[13] = v58[13] + v65;
      v58[14] = v58[14] + (float)(v61 * v64);
      v66 = v59[24] * v63;
      v67 = v62[13] * v66;
      v68 = v62[14] * v66;
      v69 = v59[12] - (float)(v62[12] * v66);
      v59[13] = v59[13] - v67;
      v55 += 64;
      --v56;
      v70 = v59[14] - v68;
      v59[12] = v69;
      v59[14] = v70;
    }
    while ( v56 );
  }
}
