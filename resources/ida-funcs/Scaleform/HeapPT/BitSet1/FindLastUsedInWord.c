int __cdecl Scaleform::HeapPT::BitSet1::FindLastUsedInWord(unsigned int bits)
{
  if ( (unsigned __int16)bits == 0xFFFF )
  {
    if ( (bits & 0xFFFFFF) == 0xFFFFFF )
      return Scaleform::HeapPT::BitSet1::LastUsedBlock[HIBYTE(bits)] + 24;
    else
      return Scaleform::HeapPT::BitSet1::LastUsedBlock[BYTE2(bits)] + 16;
  }
  else if ( (unsigned __int8)bits == 255 )
  {
    return Scaleform::HeapPT::BitSet1::LastUsedBlock[BYTE1(bits)] + 8;
  }
  else
  {
    return Scaleform::HeapPT::BitSet1::LastUsedBlock[(unsigned __int8)bits];
  }
}
