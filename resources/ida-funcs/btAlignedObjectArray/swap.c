void __usercall btAlignedObjectArray<btBroadphasePair>::swap(
        btAlignedObjectArray<btBroadphasePair> *this@<esi>,
        int index0@<eax>,
        unsigned int index1@<edx>)
{
  btBroadphasePair *m_data; // ecx
  int v4; // eax
  unsigned int v5; // edx
  btBroadphasePair *v6; // eax
  __int64 v7; // [esp+20h] [ebp-10h]
  __int64 v8; // [esp+28h] [ebp-8h]

  m_data = this->m_data;
  v4 = index0;
  v7 = *(_QWORD *)&m_data[v4].m_pProxy0;
  v8 = *(_QWORD *)&m_data[v4].m_algorithm;
  v5 = index1;
  *(_QWORD *)&m_data[v4].m_pProxy0 = *(_QWORD *)&m_data[v5].m_pProxy0;
  *(_QWORD *)&m_data[v4].m_algorithm = *(_QWORD *)&m_data[v5].m_algorithm;
  v6 = &this->m_data[v5];
  *(_QWORD *)&v6->m_pProxy0 = v7;
  *(_QWORD *)&v6->m_algorithm = v8;
}


void __userpurge btAlignedObjectArray<btCompoundShapeChild>::swap(
        int index0@<eax>,
        int index1@<ecx>,
        btAlignedObjectArray<btCompoundShapeChild> *this)
{
  const btCompoundShapeChild *v4; // [esp+50h] [ebp-60h]
  const btCompoundShapeChild *v5; // [esp+50h] [ebp-60h]
  const btCompoundShapeChild *v6; // [esp+50h] [ebp-60h]
  btCompoundShapeChild v7; // [esp+60h] [ebp-50h] BYREF

  btCompoundShapeChild::btCompoundShapeChild(&this->m_data[index0], v4);
  btCompoundShapeChild::btCompoundShapeChild(&this->m_data[index1], v5);
  btCompoundShapeChild::btCompoundShapeChild(&v7, v6);
}


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
