int __cdecl sub_6465A0(int a1, int a2, int a3, int *a4)
{
  int v5; // [esp+0h] [ebp-20h]
  int v6; // [esp+4h] [ebp-1Ch]
  int v7; // [esp+8h] [ebp-18h]
  int v8; // [esp+Ch] [ebp-14h] BYREF
  int v9; // [esp+10h] [ebp-10h]
  _DWORD *v10; // [esp+14h] [ebp-Ch]
  int v11; // [esp+18h] [ebp-8h]
  int v12; // [esp+1Ch] [ebp-4h]

  v10 = *(_DWORD **)(a1 + 300);
  if ( !v10 )
    return 23;
  v9 = v10[3];
  v11 = *(_DWORD *)(v9 + 12) + *(_DWORD *)(v9 + 4);
  v12 = *(_DWORD *)(v9 + 8) + *(_DWORD *)(v9 + 4);
  if ( *(_BYTE *)(v9 + 33) )
  {
    v6 = (**(int (__cdecl ***)(_DWORD, int, int, int *))(a1 + 228))(*(_DWORD *)(a1 + 228), v11, v12, &v8);
    v7 = sub_643A90(a1, *(_DWORD *)(a1 + 228), v11, v12, v6, v8, &v8, 0);
  }
  else
  {
    v7 = sub_640E60(a1, v10[4], *(_DWORD *)(a1 + 228), v11, v12, &v8, 0);
  }
  if ( v7 )
    return v7;
  if ( v12 == v8 || *(_DWORD *)(a1 + 480) != 3 )
  {
    *(_BYTE *)(v9 + 32) = 0;
    *(_DWORD *)(a1 + 300) = v10[2];
    v10[2] = *(_DWORD *)(a1 + 304);
    *(_DWORD *)(a1 + 304) = v10;
    if ( *(_BYTE *)(v9 + 33) )
    {
      *(_DWORD *)(a1 + 280) = sub_643A10;
      v5 = (**(int (__cdecl ***)(_DWORD, int, int, int *))(a1 + 144))(*(_DWORD *)(a1 + 144), a2, a3, &v8);
      return sub_643A90(a1, *(_DWORD *)(a1 + 144), a2, a3, v5, v8, a4, *(_BYTE *)(a1 + 484) == 0);
    }
    else
    {
      *(_DWORD *)(a1 + 280) = sub_643160;
      return sub_640E60(a1, *(_DWORD *)(a1 + 476) != 0, *(_DWORD *)(a1 + 144), a2, a3, a4, *(_BYTE *)(a1 + 484) == 0);
    }
  }
  else
  {
    *(_DWORD *)(v9 + 12) = v8 - *(_DWORD *)(v9 + 4);
    return 0;
  }
}
