void __cdecl sub_37AE20(int a1, int a2, _DWORD *a3, int a4, int a5, _DWORD *a6, int a7)
{
  _DWORD *v7; // ebp
  int v8; // esi
  _DWORD *v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  int v12; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  v7 = a3;
  v8 = *(_DWORD *)(a1 + 432);
  if ( *(_BYTE *)(v8 + 36) )
  {
    v9 = a6;
    jcopy_sample_rows(v8 + 32, 0, a5 + 4 * *a6, 0, 1, *(_DWORD *)(v8 + 40));
    v10 = 1;
    *(_BYTE *)(v8 + 36) = 0;
  }
  else
  {
    v10 = 2;
    if ( *(_DWORD *)(v8 + 44) < 2u )
      v10 = *(_DWORD *)(v8 + 44);
    v9 = a6;
    v11 = *a6;
    if ( v10 > a7 - *a6 )
      v10 = a7 - *a6;
    v12 = *(_DWORD *)(a5 + 4 * v11);
    if ( v10 <= 1 )
    {
      v13 = *(_DWORD *)(v8 + 32);
      *(_BYTE *)(v8 + 36) = 1;
    }
    else
    {
      v13 = *(_DWORD *)(a5 + 4 * v11 + 4);
    }
    v7 = a3;
    (*(void (__cdecl **)(int, int, _DWORD, int *))(v8 + 12))(a1, a2, *a3, &v12);
  }
  *v9 += v10;
  *(_DWORD *)(v8 + 44) -= v10;
  if ( !*(_BYTE *)(v8 + 36) )
    ++*v7;
}
