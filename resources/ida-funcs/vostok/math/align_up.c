unsigned int __cdecl vostok::math::align_up<unsigned long>(unsigned int align_on)
{
  unsigned int value; // ecx

  if ( value % align_on )
    return align_on + value - value % align_on;
  return value;
}


unsigned __int64 __cdecl vostok::math::align_up<unsigned __int64>(unsigned __int64 value, unsigned __int64 align_on)
{
  unsigned __int64 v2; // rdi

  v2 = value;
  if ( value % align_on )
    return align_on + value - value % align_on;
  return v2;
}
