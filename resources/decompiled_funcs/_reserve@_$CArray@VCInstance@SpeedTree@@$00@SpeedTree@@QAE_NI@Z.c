bool __thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::reserve(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this,
        SpeedTree::CInstance *uiSize)
{
  unsigned int v4; // ebp
  SpeedTree::CInstance *v5; // eax
  SpeedTree::CInstance *v6; // ebx
  SpeedTree::CInstance *m_pData; // ecx
  unsigned int v8; // edx

  if ( this->m_bExternalMemory )
    return this->m_uiDataSize >= (unsigned int)uiSize;
  v4 = (unsigned int)uiSize;
  if ( (unsigned int)uiSize > this->m_uiDataSize )
  {
    v5 = SpeedTree::st_new_array<SpeedTree::CInstance>((unsigned int)uiSize, "CArray");
    v6 = v5;
    if ( this->m_uiSize )
    {
      m_pData = this->m_pData;
      v8 = 0;
      do
      {
        *(_QWORD *)&v5->m_vPos.x = *(_QWORD *)&m_pData->m_vPos.x;
        *(_QWORD *)&v5->m_vPos.z = *(_QWORD *)&m_pData->m_vPos.z;
        *(_QWORD *)&v5->m_vGeometricCenter.x = *(_QWORD *)&m_pData->m_vGeometricCenter.x;
        *(_QWORD *)&v5->m_vGeometricCenter.z = *(_QWORD *)&m_pData->m_vGeometricCenter.z;
        *(_DWORD *)v5->m_anRotationVector = *(_DWORD *)m_pData->m_anRotationVector;
        ++v8;
        ++v5;
        ++m_pData;
      }
      while ( v8 < this->m_uiSize );
    }
    uiSize = this->m_pData;
    SpeedTree::st_delete_array<SpeedTree::CInstance>(&uiSize);
    this->m_pData = v6;
    this->m_uiDataSize = v4;
  }
  return 1;
}
