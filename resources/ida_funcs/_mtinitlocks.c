int __cdecl _mtinitlocks()
{
  int v0; // esi
  _RTL_CRITICAL_SECTION *v1; // edi
  LPCRITICAL_SECTION *v2; // eax

  v0 = 0;
  v1 = lclcritsects;
  while ( 1 )
  {
    if ( *(&locktable + 2 * v0 + 1) == (LPCRITICAL_SECTION)1 )
    {
      v2 = &locktable + 2 * v0;
      *v2 = v1++;
      if ( !__crtInitCritSecAndSpinCount(*v2, 0xFA0u) )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  *(&locktable + 2 * v0) = 0;
  return 0;
}
