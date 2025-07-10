void __thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::Deallocate(
        SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1> *this,
        void **pData)
{
  char *v3; // eax
  bool v4; // zf
  SpeedTree::CArray<SpeedTree::SInstanceLod,1> *v5; // esi

  if ( *pData )
    v3 = (char *)*pData + (unsigned int)this->m_cPool.m_pData;
  else
    v3 = 0;
  v4 = v3[20] == 0;
  v5 = (SpeedTree::CArray<SpeedTree::SInstanceLod,1> *)(v3 + 4);
  *((_DWORD *)v3 + 1) = &SpeedTree::CArray<SpeedTree::SInstanceLod,1>::`vftable';
  if ( !v4 )
  {
    SpeedTree::CArray<SpeedTree::SInstanceLod,1>::clear((SpeedTree::CArray<SpeedTree::SInstanceLod,1> *)(v3 + 4));
    if ( v5->m_bExternalMemory )
    {
      v5->m_uiDataSize = 0;
      v5->m_pData = 0;
    }
    v5->m_bExternalMemory = 0;
  }
  SpeedTree::CArray<SpeedTree::SInstanceLod,1>::clear(v5);
  this->m_cPool.m_pFreeLocations[this->m_cPool.m_uiCurrent++] = (unsigned int)*pData;
  *pData = 0;
}
