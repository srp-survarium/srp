int __cdecl Scaleform::Alg::LowerBit(unsigned int val)
{
  if ( (_WORD)val )
  {
    if ( (_BYTE)val )
      return Scaleform::Alg::LowerBitTable[(unsigned __int8)val];
    else
      return Scaleform::Alg::LowerBitTable[BYTE1(val)] + 8;
  }
  else if ( ((unsigned int)&vostok::memory::s_CRT_arena[5508664] & val) != 0 )
  {
    return Scaleform::Alg::LowerBitTable[BYTE2(val)] + 16;
  }
  else
  {
    return Scaleform::Alg::LowerBitTable[HIBYTE(val)] + 24;
  }
}
