unsigned __int8 *__thiscall SpeedTree::CArray<SpeedTree::CCore *,1>::erase(_DWORD *this, unsigned __int8 *src)
{
  unsigned __int8 dst[4]; // [esp+4h] [ebp-4h] BYREF

  if ( src == (unsigned __int8 *)(this[1] + 4 * this[2] - 4) )
  {
    --this[2];
  }
  else
  {
    memmove(dst, src, 4u);
    memmove(src, src + 4, 4 * (this[2] - ((int)&src[-this[1]] >> 2)) - 4);
    --this[2];
    memmove((unsigned __int8 *)(this[1] + 4 * this[2]), dst, 4u);
  }
  return src;
}
