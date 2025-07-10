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
