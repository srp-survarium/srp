int __thiscall SpeedTree::CArray<char,1>::~CArray<char,1>(_BYTE *this)
{
  *(_DWORD *)this = &SpeedTree::CArray<char,1>::`vftable';
  if ( this[16] )
    SpeedTree::CArray<char,1>::SetExternalMemory(0, 0);
  return SpeedTree::CArray<char,1>::clear(this);
}


int __thiscall SpeedTree::CArray<int,1>::~CArray<int,1>(_BYTE *this)
{
  *(_DWORD *)this = &SpeedTree::CArray<float,1>::`vftable';
  if ( this[16] )
    SpeedTree::CArray<float,1>::SetExternalMemory(0, 0);
  return SpeedTree::CArray<int,1>::clear(this);
}


void __thiscall SpeedTree::CArray<SpeedTree::CCore *,1>::~CArray<SpeedTree::CCore *,1>(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this)
{
  bool v2; // zf

  v2 = !this->m_bExternalMemory;
  this->__vftable = (SpeedTree::CArray<SpeedTree::CCore *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CCore *,1>::`vftable';
  if ( !v2 )
  {
    SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear(this);
    if ( this->m_bExternalMemory )
    {
      this->m_uiDataSize = 0;
      this->m_pData = 0;
    }
    this->m_bExternalMemory = 0;
  }
  SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear(this);
}


void __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::~CArray<SpeedTree::CTreeCell const *,1>(
        SpeedTree::CArray<SpeedTree::CTreeCell const *,1> *this)
{
  bool v2; // zf

  v2 = !this->m_bExternalMemory;
  this->__vftable = (SpeedTree::CArray<SpeedTree::CTreeCell const *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::`vftable';
  if ( !v2 )
  {
    SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear((SpeedTree::CArray<SpeedTree::CCore *,1> *)this);
    if ( this->m_bExternalMemory )
    {
      this->m_uiDataSize = 0;
      this->m_pData = 0;
    }
    this->m_bExternalMemory = 0;
  }
  SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::clear((SpeedTree::CArray<SpeedTree::CCore *,1> *)this);
}


void __thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::~CArray<SpeedTree::CInstance,1>(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this)
{
  SpeedTree::CInstance *pRawBlock; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (SpeedTree::CArray<SpeedTree::CInstance,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CInstance,1>::`vftable';
  if ( !this->m_bExternalMemory
    || (SpeedTree::CArray<SpeedTree::CInstance,1>::SetExternalMemory(this, 0, 0), !this->m_bExternalMemory) )
  {
    pRawBlock = this->m_pData;
    SpeedTree::st_delete_array<SpeedTree::CInstance>(&pRawBlock);
    this->m_pData = 0;
    this->m_uiDataSize = 0;
  }
  this->m_uiSize = 0;
}
