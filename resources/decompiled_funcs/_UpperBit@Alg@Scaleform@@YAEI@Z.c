int __cdecl Scaleform::Alg::UpperBit(unsigned int val)
{
  if ( (val & 0xFFFF0000) != 0 )
  {
    if ( (val & 0xFF000000) != 0 )
      return Scaleform::Alg::UpperBitTable[HIBYTE(val)] + 24;
    else
      return Scaleform::Alg::UpperBitTable[BYTE2(val)] + 16;
  }
  else if ( (val & 0xFF00) != 0 )
  {
    return Scaleform::Alg::UpperBitTable[BYTE1(val)] + 8;
  }
  else
  {
    return Scaleform::Alg::UpperBitTable[(unsigned __int8)val];
  }
}
