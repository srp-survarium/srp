int __cdecl Scaleform::HeapPT::BitSet1::FindUsedSize(const unsigned int *buf, unsigned int start, unsigned int limit)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  unsigned int v5; // esi
  unsigned int v6; // edx
  unsigned int v8; // esi
  unsigned int i; // ecx

  v3 = start >> 5;
  v4 = start & 0x1F;
  v5 = Scaleform::HeapPT::BitSet1::HeadUsedTable[v4];
  v6 = v5 & buf[start >> 5];
  if ( v6 != v5 )
    return Scaleform::HeapPT::BitSet1::FindLastUsedInWord(v6 >> v4);
  v8 = 32 - v4;
  for ( i = 32 * (v3 + 1); i < limit; v8 += 32 )
  {
    ++v3;
    i += 32;
    if ( buf[v3] != -1 )
      break;
  }
  return v8 + Scaleform::HeapPT::BitSet1::FindLastUsedInWord(buf[v3]);
}
