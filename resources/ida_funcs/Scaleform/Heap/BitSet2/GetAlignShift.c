unsigned int __cdecl Scaleform::Heap::BitSet2::GetAlignShift(
        const unsigned int *buf,
        unsigned int start,
        unsigned int num)
{
  if ( num >= 8 )
    return (buf[(start + num - 1) >> 4] >> ((2 * (start + num - 1)) & 0x1E) >> 1) & 1
         | (2
          * ((buf[(start + num - 2) >> 4] >> ((2 * (start + num - 2)) & 0x1E)) & 3
           | (4 * ((buf[(start + num - 3) >> 4] >> ((2 * (start + num - 3)) & 0x1E)) & 3))));
  else
    return ((buf[(start + num - 1) >> 4] >> ((2 * (start + num - 1)) & 0x1E)) & 3) - 1;
}
