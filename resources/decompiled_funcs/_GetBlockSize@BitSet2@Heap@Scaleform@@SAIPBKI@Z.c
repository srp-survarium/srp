unsigned int __cdecl Scaleform::Heap::BitSet2::GetBlockSize(const unsigned int *buf, unsigned int start)
{
  unsigned int result; // eax
  unsigned int v3; // eax
  unsigned int v4; // esi

  result = (buf[start >> 4] >> ((2 * start) & 0x1E)) & 3;
  if ( result == 3 )
  {
    v3 = (buf[(start + 1) >> 4] >> ((2 * (start + 1)) & 0x1E)) & 3;
    if ( v3 == 3 )
    {
      v4 = (buf[(start + 2) >> 4] >> ((2 * (start + 2)) & 0x1E)) & 3;
      if ( v4 == 3 )
        return buf[(2 * start + 37) >> 5];
      else
        return ((buf[(start + 4) >> 4] >> ((2 * (start + 4)) & 0x1E)) & 3
              | (4 * ((4 * v4) | (buf[(start + 3) >> 4] >> ((2 * (start + 3)) & 0x1E)) & 3)))
             + 6;
    }
    else
    {
      return v3 + 3;
    }
  }
  return result;
}
