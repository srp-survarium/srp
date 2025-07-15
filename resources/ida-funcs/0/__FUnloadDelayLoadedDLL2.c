int __stdcall __FUnloadDelayLoadedDLL2(char *szDll)
{
  _DWORD *v1; // ebx
  int v2; // edi
  _DWORD *v3; // eax
  HMODULE *v4; // edi
  int v5; // ecx
  char *v6; // eax
  _BYTE *v7; // ecx
  int v8; // esi
  _DWORD *i; // edx
  int v10; // esi
  HLOCAL *v11; // eax
  _DWORD *v12; // ecx
  HMODULE hLibModule; // [esp+8h] [ebp-4h]
  char *src; // [esp+14h] [ebp+8h]

  v1 = __puiHead;
  v2 = 0;
  if ( __puiHead )
  {
    do
    {
      if ( !_stricmp((char *)&_sbh_sizeHeaderList + *(_DWORD *)(v1[1] + 4), szDll) )
        break;
      v1 = (_DWORD *)*v1;
    }
    while ( v1 );
    if ( v1 )
    {
      v3 = (_DWORD *)v1[1];
      if ( v3[6] )
      {
        v4 = (HMODULE *)((char *)&_sbh_sizeHeaderList + v3[2]);
        hLibModule = *v4;
        v5 = v3[6];
        v6 = (char *)&_sbh_sizeHeaderList + v3[3];
        v7 = (char *)&_sbh_sizeHeaderList + v5;
        v8 = 0;
        for ( i = v6; *i; ++v8 )
          ++i;
        src = (char *)(4 * v8);
        if ( 4 * v8 )
        {
          v10 = v6 - v7;
          do
          {
            --src;
            v7[v10] = *v7;
            ++v7;
          }
          while ( src );
        }
        FreeLibrary(hLibModule);
        *v4 = 0;
        v11 = &__puiHead;
        if ( __puiHead )
        {
          while ( 1 )
          {
            v12 = *v11;
            if ( *v11 == v1 )
              break;
            v11 = (HLOCAL *)*v11;
            if ( !*v12 )
              goto LABEL_14;
          }
        }
        else
        {
LABEL_14:
          if ( *v11 != v1 )
          {
LABEL_16:
            LocalFree(v1);
            return 1;
          }
        }
        *v11 = (HLOCAL)*v1;
        goto LABEL_16;
      }
    }
  }
  return v2;
}
