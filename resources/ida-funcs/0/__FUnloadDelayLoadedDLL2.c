int __usercall __FUnloadDelayLoadedDLL2@<eax>(const char *szDll@<eax>)
{
  HLOCAL *v1; // ebp
  _DWORD *v4; // eax
  int v5; // esi
  int v6; // ecx
  char *v7; // eax
  HMODULE *v8; // esi
  int v9; // edi
  _BYTE *v10; // ecx
  HMODULE v11; // ebx
  _DWORD *i; // edx
  int v13; // edx
  int v14; // edi
  bool v15; // zf
  HLOCAL *v16; // eax
  _DWORD *v17; // ecx

  v1 = (HLOCAL *)__puiHead;
  if ( !__puiHead )
    return 0;
  while ( _stricmp((const char *)&_sbh_sizeHeaderList + *((_DWORD *)v1[1] + 1), szDll) )
  {
    v1 = (HLOCAL *)*v1;
    if ( !v1 )
      return 0;
  }
  v4 = v1[1];
  if ( !v4[6] )
    return 0;
  v5 = v4[2];
  v6 = v4[6];
  v7 = (char *)&_sbh_sizeHeaderList + v4[3];
  v8 = (HMODULE *)((char *)&_sbh_sizeHeaderList + v5);
  v9 = 0;
  v10 = (char *)&_sbh_sizeHeaderList + v6;
  v11 = *v8;
  for ( i = v7; *i; ++v9 )
    ++i;
  v13 = 4 * v9;
  if ( 4 * v9 )
  {
    v14 = v7 - v10;
    do
    {
      --v13;
      v10[v14] = *v10;
      ++v10;
    }
    while ( v13 );
  }
  FreeLibrary(v11);
  v15 = __puiHead == 0;
  *v8 = 0;
  v16 = &__puiHead;
  if ( !v15 )
  {
    do
    {
      v17 = *v16;
      if ( *v16 == v1 )
        goto LABEL_15;
      v16 = (HLOCAL *)*v16;
    }
    while ( *v17 );
  }
  if ( *v16 == v1 )
LABEL_15:
    *v16 = *v1;
  LocalFree(v1);
  return 1;
}
