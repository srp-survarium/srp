void __cdecl Scaleform::Heap::BitSet2::MarkBusy(unsigned int *buf, unsigned int start, unsigned int num)
{
  unsigned int v3; // esi
  unsigned int v4; // edx
  unsigned int *v5; // eax

  v3 = num;
  switch ( num )
  {
    case 0u:
    case 1u:
      buf[start >> 4] = (1 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
      return;
    case 2u:
      v4 = start;
      v5 = buf;
      buf[start >> 4] = (2 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
      goto LABEL_8;
    case 3u:
    case 4u:
    case 5u:
      v4 = start;
      v5 = buf;
      buf[start >> 4] = (3 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
      buf[(start + 1) >> 4] = ((num - 3) << ((2 * (start + 1)) & 0x1E))
                            | buf[(start + 1) >> 4] & ~(3 << ((2 * (start + 1)) & 0x1E));
      goto LABEL_8;
    default:
      v4 = start;
      v5 = buf;
      buf[start >> 4] = (3 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
      buf[(start + 1) >> 4] = (3 << ((2 * (start + 1)) & 0x1E))
                            | buf[(start + 1) >> 4] & ~(3 << ((2 * (start + 1)) & 0x1E));
      if ( num >= 0x26 )
      {
        buf[(start + 2) >> 4] = (3 << ((2 * (start + 2)) & 0x1E))
                              | buf[(start + 2) >> 4] & ~(3 << ((2 * (start + 2)) & 0x1E));
        buf[(2 * start + 37) >> 5] = num;
      }
      else
      {
        buf[(start + 2) >> 4] = ((num - 6) >> 4 << ((2 * (start + 2)) & 0x1E))
                              | buf[(start + 2) >> 4] & ~(3 << ((2 * (start + 2)) & 0x1E));
        buf[(start + 3) >> 4] = buf[(start + 3) >> 4] & ~(3 << ((2 * (start + 3)) & 0x1E))
                              | ((((num - 6) >> 2) & 3) << ((2 * (start + 3)) & 0x1E));
        v3 = num;
        buf[(start + 4) >> 4] = (((num - 6) & 3) << ((2 * (start + 4)) & 0x1E))
                              | buf[(start + 4) >> 4] & ~(3 << ((2 * (start + 4)) & 0x1E));
      }
LABEL_8:
      v5[(v4 + v3 - 1) >> 4] = (1 << ((2 * (v4 + v3 - 1)) & 0x1E))
                             | v5[(v4 + v3 - 1) >> 4] & ~(3 << ((2 * (v4 + v3 - 1)) & 0x1E));
      return;
  }
}
