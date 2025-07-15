_BYTE *__thiscall SpeedTree::CArray<char,1>::`scalar deleting destructor'(_BYTE *this, char a2)
{
  *(_DWORD *)this = &SpeedTree::CArray<char,1>::`vftable';
  if ( this[16] )
    SpeedTree::CArray<char,1>::SetExternalMemory(0, 0);
  SpeedTree::CArray<char,1>::clear(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


_BYTE *__thiscall SpeedTree::CArray<unsigned char,1>::`scalar deleting destructor'(_BYTE *this, char a2)
{
  *(_DWORD *)this = &SpeedTree::CArray<unsigned char,1>::`vftable';
  if ( this[16] )
    SpeedTree::CArray<unsigned char,1>::SetExternalMemory(0, 0);
  SpeedTree::CArray<unsigned char,1>::clear(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


_BYTE *__thiscall SpeedTree::CArray<int,1>::`scalar deleting destructor'(_BYTE *this, char a2)
{
  *(_DWORD *)this = &SpeedTree::CArray<float,1>::`vftable';
  if ( this[16] )
    SpeedTree::CArray<float,1>::SetExternalMemory(0, 0);
  SpeedTree::CArray<int,1>::clear(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


SpeedTree::CArray<SpeedTree::CCore *,1> *__thiscall SpeedTree::CArray<SpeedTree::CCore *,1>::`scalar deleting destructor'(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        char a2)
{
  bool v3; // zf

  v3 = !this->m_bExternalMemory;
  this->__vftable = (SpeedTree::CArray<SpeedTree::CCore *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CCore *,1>::`vftable';
  if ( !v3 )
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
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}


SpeedTree::CArray<SpeedTree::CGrassCell *,1> *__thiscall SpeedTree::CArray<SpeedTree::CGrassCell *,1>::`scalar deleting destructor'(
        SpeedTree::CArray<SpeedTree::CGrassCell *,1> *this,
        char a2)
{
  bool v3; // zf

  v3 = !this->m_bExternalMemory;
  this->__vftable = (SpeedTree::CArray<SpeedTree::CGrassCell *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CGrassCell *,1>::`vftable';
  if ( !v3 )
  {
    SpeedTree::CArray<void *,1>::clear((SpeedTree::CArray<void *,1> *)this, (int)this);
    if ( this->m_bExternalMemory )
    {
      this->m_uiDataSize = 0;
      this->m_pData = 0;
    }
    this->m_bExternalMemory = 0;
  }
  SpeedTree::CArray<void *,1>::clear((SpeedTree::CArray<void *,1> *)this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


SpeedTree::CArray<SpeedTree::CTreeCell *,1> *__thiscall SpeedTree::CArray<SpeedTree::CTreeCell *,1>::`scalar deleting destructor'(
        SpeedTree::CArray<SpeedTree::CTreeCell *,1> *this,
        char a2)
{
  bool v3; // zf

  v3 = !this->m_bExternalMemory;
  this->__vftable = (SpeedTree::CArray<SpeedTree::CTreeCell *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CTreeCell *,1>::`vftable';
  if ( !v3 )
  {
    SpeedTree::CArray<void *,1>::clear((SpeedTree::CArray<void *,1> *)this, (int)this);
    if ( this->m_bExternalMemory )
    {
      this->m_uiDataSize = 0;
      this->m_pData = 0;
    }
    this->m_bExternalMemory = 0;
  }
  SpeedTree::CArray<void *,1>::clear((SpeedTree::CArray<void *,1> *)this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


SpeedTree::CArray<SpeedTree::CTreeCell const *,1> *__thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::`scalar deleting destructor'(
        SpeedTree::CArray<SpeedTree::CTreeCell const *,1> *this,
        char a2)
{
  bool v3; // zf

  v3 = !this->m_bExternalMemory;
  this->__vftable = (SpeedTree::CArray<SpeedTree::CTreeCell const *,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::`vftable';
  if ( !v3 )
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
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


SpeedTree::CArray<SpeedTree::SInstanceLod,1> *__thiscall SpeedTree::CArray<SpeedTree::SInstanceLod,1>::`scalar deleting destructor'(
        SpeedTree::CArray<SpeedTree::SInstanceLod,1> *this,
        char a2)
{
  bool v3; // zf

  v3 = !this->m_bExternalMemory;
  this->__vftable = (SpeedTree::CArray<SpeedTree::SInstanceLod,1>_vtbl *)&SpeedTree::CArray<SpeedTree::SInstanceLod,1>::`vftable';
  if ( !v3 )
  {
    SpeedTree::CArray<SpeedTree::SInstanceLod,1>::clear(this);
    if ( this->m_bExternalMemory )
    {
      this->m_uiDataSize = 0;
      this->m_pData = 0;
    }
    this->m_bExternalMemory = 0;
  }
  SpeedTree::CArray<SpeedTree::SInstanceLod,1>::clear(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *__thiscall SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`scalar deleting destructor'(
        SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1> *this,
        char a2)
{
  SpeedTree::CArray<SpeedTree::CInstance,1> *pRawBlock; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`vftable';
  if ( !this->m_bExternalMemory
    || (SpeedTree::CArray<SpeedTree::CArray<SpeedTree::CInstance,1>,1>::SetExternalMemory(this, (int)this),
        !this->m_bExternalMemory) )
  {
    pRawBlock = this->m_pData;
    SpeedTree::st_delete_array<SpeedTree::CArray<SpeedTree::CInstance,1>>(&pRawBlock);
    this->m_pData = 0;
    this->m_uiDataSize = 0;
  }
  this->m_uiSize = 0;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
