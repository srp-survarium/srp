int __cdecl sub_4861A0(int *a1, int a2, unsigned int *a3, unsigned int a4)
{
  int v4; // esi
  int result; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ecx

  v4 = a1[101];
  if ( !*(_BYTE *)(v4 + 48) )
  {
    result = (*(int (__cdecl **)(int *, _DWORD))(a1[102] + 12))(a1, *(_DWORD *)(v4 + 4 * *(_DWORD *)(v4 + 64) + 56));
    if ( !result )
      return result;
    ++*(_DWORD *)(v4 + 76);
    *(_BYTE *)(v4 + 48) = 1;
  }
  v6 = *(_DWORD *)(v4 + 68);
  if ( !v6 )
  {
LABEL_9:
    v8 = *(_DWORD *)(v4 + 76);
    *(_DWORD *)(v4 + 52) = 0;
    *(_DWORD *)(v4 + 72) = a1[71] - 1;
    if ( v8 == a1[72] )
      sub_486090(a1);
    *(_DWORD *)(v4 + 68) = 1;
    goto LABEL_12;
  }
  v7 = v6 - 1;
  if ( v7 )
  {
    result = v7 - 1;
    if ( result )
      return result;
    result = (*(int (__cdecl **)(int *, _DWORD, int, _DWORD, int, unsigned int *, unsigned int))(a1[103] + 4))(
               a1,
               *(_DWORD *)(v4 + 4 * *(_DWORD *)(v4 + 64) + 56),
               v4 + 52,
               *(_DWORD *)(v4 + 72),
               a2,
               a3,
               a4);
    if ( *(_DWORD *)(v4 + 52) < *(_DWORD *)(v4 + 72) )
      return result;
    *(_DWORD *)(v4 + 68) = 0;
    if ( *a3 >= a4 )
      return result;
    goto LABEL_9;
  }
LABEL_12:
  result = (*(int (__cdecl **)(int *, _DWORD, int, _DWORD, int, unsigned int *, unsigned int))(a1[103] + 4))(
             a1,
             *(_DWORD *)(v4 + 4 * *(_DWORD *)(v4 + 64) + 56),
             v4 + 52,
             *(_DWORD *)(v4 + 72),
             a2,
             a3,
             a4);
  if ( *(_DWORD *)(v4 + 52) >= *(_DWORD *)(v4 + 72) )
  {
    if ( *(_DWORD *)(v4 + 76) == 1 )
      sub_485FB0(a1);
    *(_DWORD *)(v4 + 64) ^= 1u;
    *(_BYTE *)(v4 + 48) = 0;
    result = a1[71] + 1;
    *(_DWORD *)(v4 + 52) = result;
    *(_DWORD *)(v4 + 72) = a1[71] + 2;
    *(_DWORD *)(v4 + 68) = 2;
  }
  return result;
}
