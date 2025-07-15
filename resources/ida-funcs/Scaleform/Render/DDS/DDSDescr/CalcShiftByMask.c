unsigned __int8 __cdecl Scaleform::Render::DDS::DDSDescr::CalcShiftByMask(unsigned int mask)
{
  unsigned int v1; // ecx
  unsigned __int8 result; // al

  v1 = mask;
  result = 0;
  if ( !mask )
    return 0;
  if ( (mask & 0xFFFFFF) != 0 )
  {
    if ( (_WORD)mask )
    {
      if ( !(_BYTE)mask )
      {
        v1 = mask >> 8;
        result = 8;
      }
    }
    else
    {
      v1 = HIWORD(mask);
      result = 16;
    }
  }
  else
  {
    v1 = HIBYTE(mask);
    result = 24;
  }
  for ( ; (v1 & 1) == 0; ++result )
    v1 >>= 1;
  return result;
}
