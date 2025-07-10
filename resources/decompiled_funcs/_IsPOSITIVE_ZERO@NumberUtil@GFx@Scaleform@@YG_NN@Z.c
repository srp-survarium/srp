char __stdcall Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(long double v)
{
  unsigned int v1; // eax
  const unsigned __int8 *v2; // ecx
  long double *i; // edx

  v1 = 8;
  v2 = GFxPOSITIVE_ZERO_Bytes;
  for ( i = &v; *(_DWORD *)i == *(_DWORD *)v2; i = (long double *)((char *)i + 4) )
  {
    v1 -= 4;
    v2 += 4;
    if ( v1 < 4 )
      return 1;
  }
  return 0;
}
