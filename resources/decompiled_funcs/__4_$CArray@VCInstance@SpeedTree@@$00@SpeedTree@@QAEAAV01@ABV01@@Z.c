SpeedTree::CArray<SpeedTree::CInstance,1> *__usercall SpeedTree::CArray<SpeedTree::CInstance,1>::operator=@<eax>(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this@<esi>,
        const SpeedTree::CArray<SpeedTree::CInstance,1> *cRight@<eax>)
{
  unsigned int m_uiSize; // eax
  unsigned int m_uiDataSize; // ecx
  SpeedTree::CInstance *v5; // ebx
  SpeedTree::CInstance *m_pData; // eax
  SpeedTree::CInstance *v7; // ecx
  unsigned int v8; // edx
  SpeedTree::CInstance *pRawBlock; // [esp+8h] [ebp-4h] BYREF

  m_uiSize = cRight->m_uiSize;
  if ( this->m_bExternalMemory )
  {
    m_uiDataSize = this->m_uiDataSize;
    this->m_uiSize = m_uiSize;
    if ( m_uiSize > m_uiDataSize )
      this->m_uiSize = m_uiDataSize;
  }
  else
  {
    if ( m_uiSize > this->m_uiDataSize )
    {
      v5 = SpeedTree::st_new_array<SpeedTree::CInstance>(m_uiSize);
      pRawBlock = this->m_pData;
      SpeedTree::st_delete_array<SpeedTree::CInstance>(&pRawBlock);
      this->m_pData = v5;
      this->m_uiDataSize = cRight->m_uiSize;
    }
    this->m_uiSize = cRight->m_uiSize;
  }
  if ( this->m_uiSize )
  {
    m_pData = this->m_pData;
    v7 = cRight->m_pData;
    v8 = 0;
    do
    {
      *(_QWORD *)&m_pData->m_vPos.x = *(_QWORD *)&v7->m_vPos.x;
      *(_QWORD *)&m_pData->m_vPos.z = *(_QWORD *)&v7->m_vPos.z;
      *(_QWORD *)&m_pData->m_vGeometricCenter.x = *(_QWORD *)&v7->m_vGeometricCenter.x;
      *(_QWORD *)&m_pData->m_vGeometricCenter.z = *(_QWORD *)&v7->m_vGeometricCenter.z;
      *(_DWORD *)m_pData->m_anRotationVector = *(_DWORD *)v7->m_anRotationVector;
      ++v8;
      ++m_pData;
      ++v7;
    }
    while ( v8 < this->m_uiSize );
  }
  return this;
}
