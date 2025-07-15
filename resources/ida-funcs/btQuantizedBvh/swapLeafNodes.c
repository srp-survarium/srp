void __userpurge btQuantizedBvh::swapLeafNodes(btQuantizedBvh *this@<edx>, int i@<eax>, int splitIndex)
{
  btQuantizedBvhNode *m_data; // ecx
  btQuantizedBvhNode *v4; // ebx
  btQuantizedBvhNode *v5; // edi
  btOptimizedBvhNode *v6; // ebx
  int v7; // [esp+10h] [ebp-50h]
  int v8; // [esp+14h] [ebp-4Ch]
  int v9; // [esp+18h] [ebp-48h]
  int m_escapeIndexOrTriangleIndex; // [esp+1Ch] [ebp-44h]
  _BYTE v11[64]; // [esp+20h] [ebp-40h] BYREF

  if ( this->m_useQuantization )
  {
    m_data = this->m_quantizedLeafNodes.m_data;
    v4 = &m_data[i];
    v7 = *(_DWORD *)v4->m_quantizedAabbMin;
    v8 = *(_DWORD *)&v4->m_quantizedAabbMin[2];
    v9 = *(_DWORD *)&v4->m_quantizedAabbMax[1];
    m_escapeIndexOrTriangleIndex = v4->m_escapeIndexOrTriangleIndex;
    *(_DWORD *)v4->m_quantizedAabbMin = *(_DWORD *)m_data[splitIndex].m_quantizedAabbMin;
    *(_DWORD *)&v4->m_quantizedAabbMin[2] = *(_DWORD *)&m_data[splitIndex].m_quantizedAabbMin[2];
    *(_DWORD *)&v4->m_quantizedAabbMax[1] = *(_DWORD *)&m_data[splitIndex].m_quantizedAabbMax[1];
    v4->m_escapeIndexOrTriangleIndex = m_data[splitIndex].m_escapeIndexOrTriangleIndex;
    v5 = &this->m_quantizedLeafNodes.m_data[splitIndex];
    *(_DWORD *)v5->m_quantizedAabbMin = v7;
    v5 = (btQuantizedBvhNode *)((char *)v5 + 4);
    *(_DWORD *)v5->m_quantizedAabbMin = v8;
    v5 = (btQuantizedBvhNode *)((char *)v5 + 4);
    *(_DWORD *)v5->m_quantizedAabbMin = v9;
    *(_DWORD *)&v5->m_quantizedAabbMin[2] = m_escapeIndexOrTriangleIndex;
  }
  else
  {
    v6 = this->m_leafNodes.m_data;
    qmemcpy(v11, &v6[i], sizeof(v11));
    qmemcpy(&v6[i], &v6[splitIndex], sizeof(btOptimizedBvhNode));
    qmemcpy(&this->m_leafNodes.m_data[splitIndex], v11, sizeof(this->m_leafNodes.m_data[splitIndex]));
  }
}
