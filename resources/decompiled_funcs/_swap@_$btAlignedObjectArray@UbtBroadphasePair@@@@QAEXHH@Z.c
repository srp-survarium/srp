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
