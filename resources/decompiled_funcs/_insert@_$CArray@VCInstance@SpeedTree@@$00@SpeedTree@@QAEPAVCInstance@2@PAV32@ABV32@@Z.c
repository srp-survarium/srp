SpeedTree::CInstance *__thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::insert(
        SpeedTree::CArray<SpeedTree::CInstance,1> *this,
        int a2,
        const SpeedTree::CInstance *tNew)
{
  unsigned __int8 dst[36]; // [esp+5Ch] [ebp-2Ch] BYREF
  int v6; // [esp+84h] [ebp-4h]

  v6 = (signed int)(a2 - (unsigned int)this->m_pData) / 36;
  if ( !SpeedTree::CArray<SpeedTree::CInstance,1>::push_back(this, tNew) )
    return 0;
  if ( this->m_uiSize > 1 )
  {
    memmove(dst, (unsigned __int8 *)&this->m_pData[this->m_uiSize - 1], 0x24u);
    memmove(
      (unsigned __int8 *)&this->m_pData[v6 + 1],
      (unsigned __int8 *)&this->m_pData[v6],
      36 * (this->m_uiSize - v6 - 1));
    memmove((unsigned __int8 *)&this->m_pData[v6], dst, 0x24u);
  }
  return &this->m_pData[v6];
}
