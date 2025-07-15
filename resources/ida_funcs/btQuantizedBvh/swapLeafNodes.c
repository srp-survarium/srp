void __userpurge btQuantizedBvh::swapLeafNodes(int i@<ecx>, unsigned int splitIndex@<eax>, btQuantizedBvh *this)
{
  btQuantizedBvhNode *m_data; // esi
  int v4; // ecx
  __int64 v5; // xmm0_8
  __int64 v6; // xmm1_8
  btQuantizedBvhNode *v7; // ecx
  unsigned int v8; // eax
  btQuantizedBvhNode *v9; // ecx
  btOptimizedBvhNode *v10; // ebx
  int v11; // eax
  _BYTE v12[64]; // [esp+50h] [ebp-40h] BYREF

  if ( this->m_useQuantization )
  {
    m_data = this->m_quantizedLeafNodes.m_data;
    v4 = i;
    v5 = *(_QWORD *)m_data[v4].m_quantizedAabbMin;
    v6 = *(_QWORD *)&m_data[v4].m_quantizedAabbMax[1];
    v7 = &m_data[v4];
    v8 = splitIndex;
    *(_QWORD *)v7->m_quantizedAabbMin = *(_QWORD *)m_data[v8].m_quantizedAabbMin;
    *(_QWORD *)&v7->m_quantizedAabbMax[1] = *(_QWORD *)&m_data[v8].m_quantizedAabbMax[1];
    v9 = &this->m_quantizedLeafNodes.m_data[v8];
    *(_QWORD *)v9->m_quantizedAabbMin = v5;
    *(_QWORD *)&v9->m_quantizedAabbMax[1] = v6;
  }
  else
  {
    v10 = this->m_leafNodes.m_data;
    qmemcpy(v12, &v10[i], sizeof(v12));
    v11 = splitIndex << 6;
    qmemcpy(&v10[i], (char *)v10 + v11, sizeof(btOptimizedBvhNode));
    qmemcpy((char *)this->m_leafNodes.m_data + v11, v12, sizeof(btOptimizedBvhNode));
  }
}
