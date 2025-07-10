void __thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::SetExternalMemory(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this,
        unsigned __int8 *pMemory,
        unsigned int uiSize)
{
  int v4; // ebx
  unsigned int v5; // edi
  int v6; // ebp
  unsigned int v7; // edi
  SpeedTree::CInstance *v8; // ecx
  SpeedTree::CInstance *pRawBlock; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  if ( !this->m_bExternalMemory )
  {
    pRawBlock = this->m_pData;
    SpeedTree::st_delete_array<SpeedTree::CInstance>(&pRawBlock);
    this->m_pData = 0;
    this->m_uiDataSize = 0;
  }
  this->m_uiSize = 0;
  if ( this->m_bExternalMemory )
  {
    v5 = 0;
    if ( this->m_uiDataSize )
    {
      v6 = 0;
      do
      {
        SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&this->m_pData[v6]);
        ++v5;
        ++v6;
      }
      while ( v5 < this->m_uiDataSize );
    }
    this->m_uiDataSize = 0;
    this->m_pData = 0;
  }
  if ( pMemory )
  {
    v7 = 0;
    this->m_uiDataSize = uiSize / 0x24;
    for ( this->m_pData = (SpeedTree::CInstance *)pMemory; v7 < this->m_uiDataSize; ++v4 )
    {
      v8 = &this->m_pData[v4];
      if ( v8 )
        SpeedTree::CInstance::CInstance(v8);
      ++v7;
    }
    this->m_bExternalMemory = 1;
  }
  else
  {
    this->m_bExternalMemory = 0;
  }
}
