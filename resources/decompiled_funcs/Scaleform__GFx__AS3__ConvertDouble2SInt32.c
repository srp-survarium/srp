unsigned int __cdecl Scaleform::GFx::AS3::ConvertDouble2SInt32(long double n)
{
  double v1; // st7
  double v2; // st7
  int v3; // eax

  if ( (HIDWORD(n) & 0x7FF00000) == 0x7FF00000
    || Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(n)
    || Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(n) )
  {
    return 0;
  }
  v1 = n;
  if ( n < 0.0 )
    v1 = -n;
  v2 = floor(v1);
  if ( v2 > 4294967295.0 )
    v2 = fmod(v2, 4294967296.0);
  if ( v2 < 2147483648.0 )
  {
    if ( n < 0.0 )
      return (int)-v2;
    return (int)v2;
  }
  else
  {
    v3 = (int)(v2 - 2147483648.0);
    if ( n >= 0.0 )
      return v3 + 0x80000000;
    else
      return 0x80000000 - v3;
  }
}
