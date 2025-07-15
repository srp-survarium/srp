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


int __thiscall SpeedTree::CArray<SpeedTree::SInstanceLod,1>::insert(_DWORD *this, int a2, const void *a3)
{
  unsigned __int8 dst[32]; // [esp+64h] [ebp-28h] BYREF
  int v6; // [esp+88h] [ebp-4h]

  v6 = (a2 - this[1]) >> 5;
  if ( !SpeedTree::CArray<SpeedTree::SInstanceLod,1>::push_back((int)this, a3) )
    return 0;
  if ( this[2] > 1u )
  {
    memmove(dst, (unsigned __int8 *)(this[1] + 32 * this[2] - 32), 0x20u);
    memmove(
      (unsigned __int8 *)(this[1] + 32 * v6 + 32),
      (unsigned __int8 *)(this[1] + 32 * v6),
      32 * (this[2] - v6 - 1));
    memmove((unsigned __int8 *)(this[1] + 32 * v6), dst, 0x20u);
  }
  return this[1] + 32 * v6;
}


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
