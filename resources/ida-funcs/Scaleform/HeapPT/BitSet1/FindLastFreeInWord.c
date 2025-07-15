int __cdecl Scaleform::HeapPT::BitSet1::FindLastFreeInWord(unsigned int bits)
{
  if ( (_WORD)bits )
  {
    if ( (_BYTE)bits )
      return Scaleform::HeapPT::BitSet1::LastFreeBlock[(unsigned __int8)bits];
    else
      return Scaleform::HeapPT::BitSet1::LastFreeBlock[BYTE1(bits)] + 8;
  }
  else if ( ((unsigned int)&vostok::memory::s_CRT_arena[5508664] & bits) != 0 )
  {
    return Scaleform::HeapPT::BitSet1::LastFreeBlock[BYTE2(bits)] + 16;
  }
  else
  {
    return Scaleform::HeapPT::BitSet1::LastFreeBlock[HIBYTE(bits)] + 24;
  }
}
