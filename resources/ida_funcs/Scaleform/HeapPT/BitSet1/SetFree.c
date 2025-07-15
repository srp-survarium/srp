void __cdecl Scaleform::HeapPT::BitSet1::SetFree(unsigned int *buf, unsigned int start, unsigned int num)
{
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // esi
  unsigned int v7; // eax

  v3 = start >> 5;
  v4 = (start + num - 1) >> 5;
  v5 = Scaleform::HeapPT::BitSet1::HeadFreeTable[start & 0x1F];
  v6 = (start + num - 1) & 0x1F;
  if ( v4 <= start >> 5 )
  {
    buf[v3] &= Scaleform::HeapPT::BitSet1::TailFreeTable[v6] | v5;
  }
  else
  {
    buf[v3] &= v5;
    v7 = v3 + 1;
    if ( v7 < v4 )
      memset(&buf[v7], 0, 4 * (v4 - v7));
    buf[v4] &= Scaleform::HeapPT::BitSet1::TailFreeTable[v6];
  }
}
