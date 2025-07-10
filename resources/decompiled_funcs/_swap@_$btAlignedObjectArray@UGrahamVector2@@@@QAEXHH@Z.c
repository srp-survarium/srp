void __usercall btAlignedObjectArray<GrahamVector2>::swap(
        btAlignedObjectArray<GrahamVector2> *this@<esi>,
        int index0@<eax>,
        unsigned int index1@<edx>)
{
  GrahamVector2 *m_data; // ecx
  int v4; // eax
  unsigned __int64 v5; // xmm0_8
  unsigned __int64 v6; // xmm1_8
  __int64 v7; // xmm2_8
  __int64 v8; // xmm3_8
  __m128 *p_mVec128; // eax
  unsigned int v10; // edx
  GrahamVector2 *v11; // eax

  m_data = this->m_data;
  v4 = index0;
  v5 = m_data[v4].mVec128.m128_u64[0];
  v6 = m_data[v4].mVec128.m128_u64[1];
  v7 = *(_QWORD *)&m_data[v4].m_angle;
  v8 = *(_QWORD *)(&m_data[v4].m_orgIndex + 1);
  p_mVec128 = &m_data[v4].mVec128;
  v10 = index1;
  p_mVec128->m128_u64[0] = m_data[v10].mVec128.m128_u64[0];
  p_mVec128->m128_u64[1] = m_data[v10].mVec128.m128_u64[1];
  p_mVec128[1].m128_u64[0] = *(_QWORD *)&m_data[v10].m_angle;
  p_mVec128[1].m128_u64[1] = *(_QWORD *)(&m_data[v10].m_orgIndex + 1);
  v11 = &this->m_data[v10];
  v11->mVec128.m128_u64[0] = v5;
  v11->mVec128.m128_u64[1] = v6;
  *(_QWORD *)&v11->m_angle = v7;
  *(_QWORD *)(&v11->m_orgIndex + 1) = v8;
}
