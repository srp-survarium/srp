SpeedTree::CArray<void *,1> *__thiscall SpeedTree::CArray<void *,1>::`vector deleting destructor'(
        SpeedTree::CArray<void *,1> *this,
        char a2)
{
  bool v3; // zf

  v3 = !this->m_bExternalMemory;
  this->__vftable = (SpeedTree::CArray<void *,1>_vtbl *)&SpeedTree::CArray<void *,1>::`vftable';
  if ( !v3 )
  {
    SpeedTree::CArray<void *,1>::clear(this);
    if ( this->m_bExternalMemory )
    {
      this->m_uiDataSize = 0;
      this->m_pData = 0;
    }
    this->m_bExternalMemory = 0;
  }
  SpeedTree::CArray<void *,1>::clear(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


bool *__thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::`vector deleting destructor'(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this,
        char a2)
{
  if ( (a2 & 2) != 0 )
  {
    `vector destructor iterator'(
      (char *)this,
      0x14u,
      *(_DWORD *)&this[-1].m_bExternalMemory,
      (void (__thiscall *)(void *))SpeedTree::CArray<SpeedTree::CInstance,1>::~CArray<SpeedTree::CInstance,1>);
    if ( (a2 & 1) != 0 )
      operator delete[](&this[-1].m_bExternalMemory);
    return &this[-1].m_bExternalMemory;
  }
  else
  {
    SpeedTree::CArray<SpeedTree::CInstance,1>::~CArray<SpeedTree::CInstance,1>(this);
    if ( (a2 & 1) != 0 )
      operator delete(this);
    return (bool *)this;
  }
}
