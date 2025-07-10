unsigned __int8 *__cdecl __crtGetEnvironmentStringsA()
{
  int v0; // eax
  char *v1; // ebx
  wchar_t *EnvironmentStringsW; // edi
  wchar_t *i; // eax
  unsigned int v5; // eax
  char *v6; // eax
  LPCH EnvironmentStrings; // eax
  char *v8; // esi
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // edi
  int nSizeW; // [esp+Ch] [ebp-Ch]
  int nSizeA; // [esp+10h] [ebp-8h]
  unsigned int nSizeAa; // [esp+10h] [ebp-8h]
  char *aEnv; // [esp+14h] [ebp-4h]

  v0 = f_use;
  v1 = 0;
  EnvironmentStringsW = 0;
  if ( !f_use )
  {
    EnvironmentStringsW = GetEnvironmentStringsW();
    if ( EnvironmentStringsW )
    {
      f_use = 1;
      goto LABEL_8;
    }
    if ( GetLastError() == 120 )
    {
      v0 = 2;
      f_use = 2;
    }
    else
    {
      v0 = f_use;
    }
  }
  if ( v0 == 1 )
  {
LABEL_8:
    if ( !EnvironmentStringsW )
    {
      EnvironmentStringsW = GetEnvironmentStringsW();
      if ( !EnvironmentStringsW )
        return 0;
    }
    for ( i = EnvironmentStringsW; *i; ++i )
    {
      do
        ++i;
      while ( *i );
    }
    nSizeW = i - EnvironmentStringsW + 1;
    v5 = WideCharToMultiByte(0, 0, EnvironmentStringsW, nSizeW, 0, 0, 0, 0);
    nSizeA = v5;
    if ( v5 )
    {
      v6 = (char *)_malloc_crt(v5);
      aEnv = v6;
      if ( v6 )
      {
        if ( !WideCharToMultiByte(0, 0, EnvironmentStringsW, nSizeW, v6, nSizeA, 0, 0) )
        {
          free(aEnv);
          aEnv = 0;
        }
        v1 = aEnv;
      }
    }
    FreeEnvironmentStringsW(EnvironmentStringsW);
    return (unsigned __int8 *)v1;
  }
  if ( v0 != 2 && v0 )
    return 0;
  EnvironmentStrings = GetEnvironmentStrings();
  v8 = EnvironmentStrings;
  if ( !EnvironmentStrings )
    return 0;
  for ( ; *EnvironmentStrings; ++EnvironmentStrings )
  {
    do
      ++EnvironmentStrings;
    while ( *EnvironmentStrings );
  }
  nSizeAa = EnvironmentStrings - v8 + 1;
  v9 = (unsigned __int8 *)_malloc_crt(nSizeAa);
  v10 = v9;
  if ( !v9 )
  {
    FreeEnvironmentStringsA(v8);
    return 0;
  }
  memcpy(v9, (unsigned __int8 *)v8, nSizeAa);
  FreeEnvironmentStringsA(v8);
  return v10;
}
