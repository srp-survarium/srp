int __cdecl sub_52C240(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // [esp+0h] [ebp-Ch] BYREF
  _DWORD *v6; // [esp+4h] [ebp-8h]
  _DWORD *v7; // [esp+8h] [ebp-4h]

  if ( *(_BYTE *)(a2 + 72) )
    return (*(int (__cdecl **)(_DWORD, int, int))(a1 + 80))(*(_DWORD *)(a1 + 4), a3, a4 - a3);
  if ( a2 == *(_DWORD *)(a1 + 144) )
  {
    v6 = (_DWORD *)(a1 + 288);
    v7 = (_DWORD *)(a1 + 292);
  }
  else
  {
    v6 = *(_DWORD **)(a1 + 300);
    v7 = (_DWORD *)(*(_DWORD *)(a1 + 300) + 4);
  }
  do
  {
    v5 = *(_DWORD *)(a1 + 44);
    (*(void (__cdecl **)(int, int *, int, int *, _DWORD))(a2 + 60))(a2, &a3, a4, &v5, *(_DWORD *)(a1 + 48));
    *v7 = a3;
    (*(void (__cdecl **)(_DWORD, _DWORD, int))(a1 + 80))(
      *(_DWORD *)(a1 + 4),
      *(_DWORD *)(a1 + 44),
      v5 - *(_DWORD *)(a1 + 44));
    result = (int)v6;
    *v6 = a3;
  }
  while ( a3 != a4 );
  return result;
}
