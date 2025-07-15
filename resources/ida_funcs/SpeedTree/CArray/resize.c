char __thiscall SpeedTree::CArray<SpeedTree::CGrassCell *,1>::resize(_DWORD *this, int a2)
{
  if ( (unsigned __int8)SpeedTree::CArray<void *,1>::reserve(a2) )
  {
    this[2] = a2;
    return 1;
  }
  else
  {
    this[2] = this[3];
    return 0;
  }
}


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
