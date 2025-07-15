void __cdecl btSoftBody::PSolve_Links(btSoftBody *psb, float kst)
{
  int v2; // edi
  int m_size; // ebx
  btSoftBody::Link *v4; // edx
  float m_c0; // xmm6_4
  float *v6; // ecx
  float *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4

  if ( psb->m_links.m_size > 0 )
  {
    v2 = 0;
    m_size = psb->m_links.m_size;
    do
    {
      v4 = &psb->m_links.m_data[v2];
      m_c0 = v4->m_c0;
      if ( m_c0 > 0.0 )
      {
        v6 = (float *)v4->m_n[1];
        v7 = (float *)v4->m_n[0];
        v8 = v6[4] - v7[4];
        v9 = v6[6] - v7[6];
        v10 = v6[5] - v7[5];
        v11 = (float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v10 * v10);
        if ( (float)(v4->m_c1 + v11) > 0.00000011920929 )
        {
          v12 = (float)((float)(v4->m_c1 - v11) / (float)((float)(v4->m_c1 + v11) * m_c0)) * kst;
          v13 = v7[24] * v12;
          v7[4] = v7[4] - (float)(v8 * v13);
          v7[5] = v7[5] - (float)(v10 * v13);
          v7[6] = v7[6] - (float)(v9 * v13);
          v14 = v6[24] * v12;
          v15 = (float)(v8 * v14) + v6[4];
          v6[5] = v6[5] + (float)(v10 * v14);
          v16 = v6[6] + (float)(v9 * v14);
          v6[4] = v15;
          v6[6] = v16;
        }
      }
      ++v2;
      --m_size;
    }
    while ( m_size );
  }
}
