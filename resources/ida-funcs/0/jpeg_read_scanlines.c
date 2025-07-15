_DWORD *__cdecl jpeg_read_scanlines(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // esi
  unsigned int v4; // ecx
  _DWORD *result; // eax
  int v6; // eax
  int v7; // eax

  v3 = a1;
  if ( a1[5] != 205 )
  {
    *(_DWORD *)(*a1 + 20) = 21;
    *(_DWORD *)(*v3 + 24) = v3[5];
    (*(void (__cdecl **)(_DWORD *))*v3)(v3);
  }
  v4 = v3[30];
  if ( v4 < v3[24] )
  {
    v6 = v3[2];
    if ( v6 )
    {
      *(_DWORD *)(v6 + 4) = v4;
      *(_DWORD *)(v3[2] + 8) = v3[24];
      (*(void (__cdecl **)(_DWORD *))v3[2])(v3);
    }
    v7 = v3[101];
    a1 = 0;
    (*(void (__cdecl **)(_DWORD *, int, _DWORD **, int))(v7 + 4))(v3, a2, &a1, a3);
    result = a1;
    v3[30] += a1;
  }
  else
  {
    *(_DWORD *)(*v3 + 20) = 126;
    (*(void (__cdecl **)(_DWORD *, int))(*v3 + 4))(v3, -1);
    return 0;
  }
  return result;
}
