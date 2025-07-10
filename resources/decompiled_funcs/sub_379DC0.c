int __cdecl sub_379DC0(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7)
{
  _DWORD *v7; // ebx
  unsigned int v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // ecx
  int result; // eax

  v7 = a6;
  v8 = a7 - *a6;
  v9 = a1;
  v10 = *(_DWORD *)(a1 + 412);
  if ( v8 > *(_DWORD *)(v10 + 16) )
    v8 = *(_DWORD *)(v10 + 16);
  v11 = *(_DWORD *)(a1 + 432);
  a1 = 0;
  (*(void (__cdecl **)(int, int, int, int, _DWORD, int *, unsigned int))(v11 + 4))(
    v9,
    a2,
    a3,
    a4,
    *(_DWORD *)(v10 + 12),
    &a1,
    v8);
  result = (*(int (__cdecl **)(int, _DWORD, int, int))(*(_DWORD *)(v9 + 440) + 4))(
             v9,
             *(_DWORD *)(v10 + 12),
             a5 + 4 * *v7,
             a1);
  *v7 += a1;
  return result;
}
