char __thiscall SpeedTree::CArray<SpeedTree::CTreeCell *,1>::resize(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        unsigned int uiSize)
{
  if ( SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(this, uiSize) )
  {
    this->m_uiSize = uiSize;
    return 1;
  }
  else
  {
    this->m_uiSize = this->m_uiDataSize;
    return 0;
  }
}
