void __cdecl btSoftBody::VSolve_Links(btSoftBody *psb, float kst)
{
  int v2; // edi
  int m_size; // ebx
  btSoftBody::Link *v4; // eax
  float *v5; // edx
  float *v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm0_4

  if ( psb->m_links.m_size > 0 )
  {
    v2 = 0;
    m_size = psb->m_links.m_size;
    do
    {
      v4 = &psb->m_links.m_data[v2];
      v5 = (float *)v4->m_n[0];
      v6 = (float *)v4->m_n[1];
      LODWORD(v7) = COERCE_UNSIGNED_INT(
                      (float)((float)((float)((float)(v4->m_c3.mVec128.m128_f32[2] * (float)(v5[14] - v6[14]))
                                            + (float)(v4->m_c3.mVec128.m128_f32[1] * (float)(v5[13] - v6[13])))
                                    + (float)(v4->m_c3.mVec128.m128_f32[0] * (float)(v5[12] - v6[12])))
                            * v4->m_c2)
                    * kst)
                  ^ _mask__NegFloat_;
      v8 = v5[24] * v7;
      v9 = v4->m_c3.mVec128.m128_f32[1] * v8;
      v10 = v4->m_c3.mVec128.m128_f32[2] * v8;
      v5[12] = v5[12] + (float)(v4->m_c3.mVec128.m128_f32[0] * v8);
      v5[13] = v5[13] + v9;
      v5[14] = v5[14] + v10;
      v11 = v6[24] * v7;
      v12 = v4->m_c3.mVec128.m128_f32[1] * v11;
      v13 = v4->m_c3.mVec128.m128_f32[2] * v11;
      v14 = v6[12] - (float)(v4->m_c3.mVec128.m128_f32[0] * v11);
      v6[13] = v6[13] - v12;
      ++v2;
      --m_size;
      v15 = v6[14] - v13;
      v6[12] = v14;
      v6[14] = v15;
    }
    while ( m_size );
  }
}
