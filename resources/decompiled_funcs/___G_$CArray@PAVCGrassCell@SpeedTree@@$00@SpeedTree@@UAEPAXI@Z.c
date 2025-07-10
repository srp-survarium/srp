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
