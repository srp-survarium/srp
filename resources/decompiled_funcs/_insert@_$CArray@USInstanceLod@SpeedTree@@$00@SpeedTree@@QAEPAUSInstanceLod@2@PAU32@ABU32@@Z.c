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
