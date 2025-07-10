void __cdecl btSoftBody::PSolve_Links(btSoftBody *psb, float kst)
{
  float v2; // xmm7_4
  int m_size; // ebx
  int v4; // eax
  int v5; // edi
  unsigned int v6; // ebx
  btSoftBody::Link *m_data; // edx
  float m_c0; // xmm0_4
  btSoftBody::Link *v9; // edx
  float *v10; // ecx
  float *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm3_4
  btSoftBody::Link *v20; // edx
  float v21; // xmm0_4
  int v22; // edx
  float *v23; // ecx
  float *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm4_4
  float v30; // xmm4_4
  float v31; // xmm3_4
  float v32; // xmm3_4
  btSoftBody::Link *v33; // ecx
  int v34; // esi
  int v35; // edx
  float *v36; // ecx
  float *v37; // eax
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm5_4
  float v42; // xmm4_4
  float v43; // xmm4_4
  float v44; // xmm3_4
  float v45; // xmm3_4
  btSoftBody::Link *v46; // edx
  float v47; // xmm0_4
  char *v48; // edx
  float *v49; // ecx
  float *v50; // eax
  float v51; // xmm0_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm5_4
  float v55; // xmm4_4
  float v56; // xmm4_4
  float v57; // xmm3_4
  float v58; // xmm3_4
  int v59; // esi
  int v60; // edi
  btSoftBody::Link *v61; // edx
  float v62; // xmm6_4
  char *v63; // edx
  float *v64; // ecx
  float *v65; // eax
  float v66; // xmm2_4
  float v67; // xmm4_4
  float v68; // xmm3_4
  float v69; // xmm5_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm1_4
  float v73; // xmm3_4
  float v74; // xmm4_4
  float v75; // [esp+1Ch] [ebp-10h]
  float v76; // [esp+1Ch] [ebp-10h]
  float v77; // [esp+1Ch] [ebp-10h]
  float v78; // [esp+1Ch] [ebp-10h]
  int v79; // [esp+24h] [ebp-8h]
  int v80; // [esp+28h] [ebp-4h]

  v2 = kst;
  m_size = psb->m_links.m_size;
  v4 = 0;
  v80 = m_size;
  if ( m_size >= 4 )
  {
    v5 = 0;
    v6 = ((unsigned int)(m_size - 4) >> 2) + 1;
    v79 = 4 * v6;
    do
    {
      m_data = psb->m_links.m_data;
      m_c0 = m_data[v5].m_c0;
      v9 = &m_data[v5];
      v75 = m_c0;
      if ( m_c0 > 0.0 )
      {
        v10 = (float *)v9->m_n[1];
        v11 = (float *)v9->m_n[0];
        v12 = v10[4] - v11[4];
        v13 = v10[6] - v11[6];
        v14 = v10[5] - v11[5];
        v15 = (float)((float)(v13 * v13) + (float)(v12 * v12)) + (float)(v14 * v14);
        v16 = v9->m_c1 + v15;
        if ( v16 > 0.00000011920929 )
        {
          v17 = (float)((float)(v9->m_c1 - v15) / (float)(v16 * v75)) * kst;
          v18 = v11[24] * v17;
          v11[4] = v11[4] - (float)(v12 * v18);
          v11[5] = v11[5] - (float)(v14 * v18);
          v11[6] = v11[6] - (float)(v13 * v18);
          v19 = v10[24] * v17;
          v10[4] = (float)(v12 * v19) + v10[4];
          v10[5] = (float)(v14 * v19) + v10[5];
          v10[6] = (float)(v13 * v19) + v10[6];
        }
      }
      v20 = psb->m_links.m_data;
      v21 = v20[v5 + 1].m_c0;
      v22 = (int)&v20[v5 + 1];
      v76 = v21;
      if ( v21 > 0.0 )
      {
        v23 = *(float **)(v22 + 12);
        v24 = *(float **)(v22 + 8);
        v25 = v23[4] - v24[4];
        v26 = v23[6] - v24[6];
        v27 = v23[5] - v24[5];
        v28 = (float)((float)(v26 * v26) + (float)(v25 * v25)) + (float)(v27 * v27);
        v29 = *(float *)(v22 + 28) + v28;
        if ( v29 > 0.00000011920929 )
        {
          v30 = (float)((float)(*(float *)(v22 + 28) - v28) / (float)(v29 * v76)) * kst;
          v31 = v24[24] * v30;
          v24[4] = v24[4] - (float)(v25 * v31);
          v24[5] = v24[5] - (float)(v27 * v31);
          v24[6] = v24[6] - (float)(v26 * v31);
          v32 = v23[24] * v30;
          v23[4] = (float)(v25 * v32) + v23[4];
          v23[5] = (float)(v27 * v32) + v23[5];
          v23[6] = (float)(v26 * v32) + v23[6];
        }
      }
      v33 = psb->m_links.m_data;
      v34 = v5 * 64 + 192;
      v35 = (int)&v33[v5 + 2];
      v77 = v33[v5 + 2].m_c0;
      if ( v77 > 0.0 )
      {
        v36 = *(float **)(v35 + 12);
        v37 = *(float **)(v35 + 8);
        v38 = v36[4] - v37[4];
        v39 = v36[6] - v37[6];
        v40 = v36[5] - v37[5];
        v41 = (float)((float)(v39 * v39) + (float)(v38 * v38)) + (float)(v40 * v40);
        v42 = *(float *)(v35 + 28) + v41;
        if ( v42 > 0.00000011920929 )
        {
          v43 = (float)((float)(*(float *)(v35 + 28) - v41) / (float)(v42 * v77)) * kst;
          v44 = v37[24] * v43;
          v37[4] = v37[4] - (float)(v38 * v44);
          v37[5] = v37[5] - (float)(v40 * v44);
          v37[6] = v37[6] - (float)(v39 * v44);
          v45 = v36[24] * v43;
          v36[4] = (float)(v38 * v45) + v36[4];
          v36[5] = (float)(v40 * v45) + v36[5];
          v36[6] = (float)(v39 * v45) + v36[6];
        }
      }
      v46 = psb->m_links.m_data;
      v47 = *(float *)((char *)&v46->m_c0 + v34);
      v48 = (char *)v46 + v34;
      v78 = v47;
      if ( v47 > 0.0 )
      {
        v49 = (float *)*((_DWORD *)v48 + 3);
        v50 = (float *)*((_DWORD *)v48 + 2);
        v51 = v49[4] - v50[4];
        v52 = v49[6] - v50[6];
        v53 = v49[5] - v50[5];
        v54 = (float)((float)(v52 * v52) + (float)(v51 * v51)) + (float)(v53 * v53);
        v55 = *((float *)v48 + 7) + v54;
        if ( v55 > 0.00000011920929 )
        {
          v56 = (float)((float)(*((float *)v48 + 7) - v54) / (float)(v55 * v78)) * kst;
          v57 = v50[24] * v56;
          v50[4] = v50[4] - (float)(v51 * v57);
          v50[5] = v50[5] - (float)(v53 * v57);
          v50[6] = v50[6] - (float)(v52 * v57);
          v58 = v49[24] * v56;
          v49[4] = (float)(v51 * v58) + v49[4];
          v49[5] = (float)(v53 * v58) + v49[5];
          v49[6] = (float)(v52 * v58) + v49[6];
        }
      }
      v5 += 4;
      --v6;
    }
    while ( v6 );
    v4 = v79;
    m_size = v80;
  }
  if ( v4 < m_size )
  {
    v59 = v4 << 6;
    v60 = m_size - v4;
    do
    {
      v61 = psb->m_links.m_data;
      v62 = *(float *)((char *)&v61->m_c0 + v59);
      v63 = (char *)v61 + v59;
      if ( v62 > 0.0 )
      {
        v64 = (float *)*((_DWORD *)v63 + 3);
        v65 = (float *)*((_DWORD *)v63 + 2);
        v66 = v64[4] - v65[4];
        v67 = v64[6] - v65[6];
        v68 = v64[5] - v65[5];
        v69 = (float)((float)(v67 * v67) + (float)(v66 * v66)) + (float)(v68 * v68);
        if ( (float)(*((float *)v63 + 7) + v69) > 0.00000011920929 )
        {
          v70 = (float)((float)(*((float *)v63 + 7) - v69) / (float)((float)(*((float *)v63 + 7) + v69) * v62)) * v2;
          v71 = v65[24] * v70;
          v65[4] = v65[4] - (float)(v66 * v71);
          v65[5] = v65[5] - (float)(v68 * v71);
          v2 = kst;
          v65[6] = v65[6] - (float)(v67 * v71);
          v72 = v64[24] * v70;
          v73 = (float)(v68 * v72) + v64[5];
          v74 = (float)(v67 * v72) + v64[6];
          v64[4] = (float)(v66 * v72) + v64[4];
          v64[5] = v73;
          v64[6] = v74;
        }
      }
      v59 += 64;
      --v60;
    }
    while ( v60 );
  }
}
