_DWORD *__cdecl sub_374FC0(_DWORD *opaque, unsigned int a2)
{
  unsigned int v2; // ebp
  _DWORD *v3; // esi
  int i; // edi
  void (__cdecl *v5)(_DWORD *, int); // edx
  int v6; // edi
  void (__cdecl *v7)(_DWORD *, int); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  int v10; // ebp
  _DWORD *result; // eax
  _DWORD *v12; // edi
  int v13; // ebp

  v2 = a2;
  v3 = (_DWORD *)opaque[1];
  if ( a2 >= 2 )
  {
    *(_DWORD *)(*opaque + 20) = 15;
    *(_DWORD *)(*opaque + 24) = a2;
    (*(void (__cdecl **)(_DWORD *))*opaque)(opaque);
  }
  if ( a2 == 1 )
  {
    for ( i = v3[17]; i; i = *(_DWORD *)(i + 36) )
    {
      if ( *(_BYTE *)(i + 34) )
      {
        v5 = *(void (__cdecl **)(_DWORD *, int))(i + 48);
        *(_BYTE *)(i + 34) = 0;
        v5(opaque, i + 40);
      }
    }
    v6 = v3[18];
    for ( v3[17] = 0; v6; v6 = *(_DWORD *)(v6 + 36) )
    {
      if ( *(_BYTE *)(v6 + 34) )
      {
        v7 = *(void (__cdecl **)(_DWORD *, int))(v6 + 48);
        *(_BYTE *)(v6 + 34) = 0;
        v7(opaque, v6 + 40);
      }
    }
    v3[18] = 0;
  }
  v8 = (_DWORD *)v3[a2 + 15];
  v3[a2 + 15] = 0;
  if ( v8 )
  {
    do
    {
      v9 = (_DWORD *)*v8;
      v10 = v8[2] + v8[1] + 16;
      jpeg_free_small(opaque, v8);
      v3[19] -= v10;
      v8 = v9;
    }
    while ( v9 );
    v2 = a2;
  }
  result = (_DWORD *)v3[v2 + 13];
  v3[v2 + 13] = 0;
  if ( result )
  {
    do
    {
      v12 = (_DWORD *)*result;
      v13 = result[2] + result[1] + 16;
      jpeg_free_small(opaque, result);
      v3[19] -= v13;
      result = v12;
    }
    while ( v12 );
  }
  return result;
}
