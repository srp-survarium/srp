char __thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::push_back(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this,
        const SpeedTree::CInstance *tNew)
{
  unsigned int m_uiSize; // eax
  unsigned int m_uiDataSize; // eax
  unsigned int v6; // edx
  SpeedTree::CInstance *m_pData; // eax
  SpeedTree::CInstance *v8; // eax

  if ( this->m_bExternalMemory )
  {
    m_uiSize = this->m_uiSize;
    if ( m_uiSize >= this->m_uiDataSize )
    {
      return 0;
    }
    else
    {
      this->m_pData[m_uiSize] = *tNew;
      ++this->m_uiSize;
      return 1;
    }
  }
  else
  {
    m_uiDataSize = this->m_uiDataSize;
    if ( this->m_uiSize == m_uiDataSize )
    {
      if ( m_uiDataSize < 8 )
        this->m_uiDataSize = 8;
      SpeedTree::CArray<SpeedTree::CInstance,1>::reserve(this, (SpeedTree::CInstance *)(2 * this->m_uiDataSize + 1));
    }
    v6 = this->m_uiSize;
    m_pData = this->m_pData;
    *(_QWORD *)&m_pData[v6].m_vPos.x = *(_QWORD *)&tNew->m_vPos.x;
    v8 = &m_pData[v6];
    *(_QWORD *)&v8->m_vPos.z = *(_QWORD *)&tNew->m_vPos.z;
    *(_QWORD *)&v8->m_vGeometricCenter.x = *(_QWORD *)&tNew->m_vGeometricCenter.x;
    *(_QWORD *)&v8->m_vGeometricCenter.z = *(_QWORD *)&tNew->m_vGeometricCenter.z;
    *(_DWORD *)v8->m_anRotationVector = *(_DWORD *)tNew->m_anRotationVector;
    ++this->m_uiSize;
    return 1;
  }
}
