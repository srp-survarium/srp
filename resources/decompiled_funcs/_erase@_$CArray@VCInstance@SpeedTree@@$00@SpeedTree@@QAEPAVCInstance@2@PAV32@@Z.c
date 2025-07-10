unsigned __int8 *__thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::erase(_DWORD *this, unsigned __int8 *src)
{
  unsigned __int8 dst[36]; // [esp+4h] [ebp-28h] BYREF

  if ( src == (unsigned __int8 *)(this[1] + 36 * this[2] - 36) )
  {
    --this[2];
  }
  else
  {
    memmove(dst, src, 0x24u);
    memmove(src, src + 36, 36 * (this[2] - (int)&src[-this[1]] / 36 - 1));
    --this[2];
    memmove((unsigned __int8 *)(this[1] + 36 * this[2]), dst, 0x24u);
  }
  return src;
}
