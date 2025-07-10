int __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::insert(
        SpeedTree::CArray<SpeedTree::CCore *,1> *this,
        int a2,
        SpeedTree::CCore **a3)
{
  unsigned __int8 dst[4]; // [esp+48h] [ebp-8h] BYREF
  int v6; // [esp+4Ch] [ebp-4h]

  v6 = (signed int)(a2 - (unsigned int)this->m_pData) >> 2;
  if ( !SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::push_back(this, a3) )
    return 0;
  if ( this->m_uiSize > 1 )
  {
    memmove(dst, (unsigned __int8 *)&this->m_pData[this->m_uiSize - 1], 4u);
    memmove(
      (unsigned __int8 *)&this->m_pData[v6 + 1],
      (unsigned __int8 *)&this->m_pData[v6],
      4 * (this->m_uiSize - v6) - 4);
    memmove((unsigned __int8 *)&this->m_pData[v6], dst, 4u);
  }
  return (int)&this->m_pData[v6];
}
