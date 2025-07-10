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
