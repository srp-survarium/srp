int __cdecl Scaleform::HeapPT::BitSet1::FindFreeSize(const unsigned int *buf, unsigned int start)
{
  unsigned int v2; // ecx
  unsigned int v3; // esi
  unsigned int v4; // edx
  unsigned int v6; // eax
  unsigned int i; // esi

  v2 = start & 0x1F;
  v3 = Scaleform::HeapPT::BitSet1::HeadFreeTable[v2];
  v4 = v3 | buf[start >> 5];
  if ( v4 != v3 )
    return Scaleform::HeapPT::BitSet1::FindLastFreeInWord(v4 >> v2);
  v6 = (start >> 5) + 1;
  for ( i = 32 - v2; !buf[v6]; i += 32 )
    ++v6;
  return i + Scaleform::HeapPT::BitSet1::FindLastFreeInWord(buf[v6]);
}
