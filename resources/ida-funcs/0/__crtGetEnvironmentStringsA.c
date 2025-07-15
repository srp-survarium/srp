char *__cdecl __crtGetEnvironmentStringsA()
{
  int v0; // eax
  char *v1; // ebx
  wchar_t *EnvironmentStringsW; // edi
  wchar_t *i; // eax
  unsigned int v5; // eax
  char *v6; // eax
  LPCH EnvironmentStrings; // eax
  __m128i *v8; // esi
  void *v9; // eax
  void *v10; // edi
  int cchWideChar; // [esp+Ch] [ebp-Ch]
  int cbMultiByte; // [esp+10h] [ebp-8h]
  unsigned int cbMultiBytea; // [esp+10h] [ebp-8h]
  char *pointer; // [esp+14h] [ebp-4h]

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
    cchWideChar = i - EnvironmentStringsW + 1;
    v5 = WideCharToMultiByte(0, 0, EnvironmentStringsW, cchWideChar, 0, 0, 0, 0);
    cbMultiByte = v5;
    if ( v5 )
    {
      v6 = (char *)_malloc_crt(v5);
      pointer = v6;
      if ( v6 )
      {
        if ( !WideCharToMultiByte(0, 0, EnvironmentStringsW, cchWideChar, v6, cbMultiByte, 0, 0) )
        {
          free(pointer);
          pointer = 0;
        }
        v1 = pointer;
      }
    }
    FreeEnvironmentStringsW(EnvironmentStringsW);
    return v1;
  }
  if ( v0 != 2 && v0 )
    return 0;
  EnvironmentStrings = GetEnvironmentStrings();
  v8 = (__m128i *)EnvironmentStrings;
  if ( !EnvironmentStrings )
    return 0;
  for ( ; *EnvironmentStrings; ++EnvironmentStrings )
  {
    do
      ++EnvironmentStrings;
    while ( *EnvironmentStrings );
  }
  cbMultiBytea = EnvironmentStrings - (LPCH)v8 + 1;
  v9 = _malloc_crt(cbMultiBytea);
  v10 = v9;
  if ( !v9 )
  {
    FreeEnvironmentStringsA(v8->m128i_i8);
    return 0;
  }
  memcpy((int)v9, v8, cbMultiBytea);
  FreeEnvironmentStringsA(v8->m128i_i8);
  return (char *)v10;
}
