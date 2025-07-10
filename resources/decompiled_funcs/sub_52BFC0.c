int __cdecl sub_52BFC0(int a1, int a2, int a3, int a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // [esp-4h] [ebp-10h]
  int v8; // [esp+0h] [ebp-Ch]
  int v9; // [esp+4h] [ebp-8h]
  int v10; // [esp+8h] [ebp-4h]
  int v11; // [esp+1Ch] [ebp+10h]

  if ( *(_DWORD *)(a1 + 64) )
  {
    v11 = a3 + 2 * *(_DWORD *)(a2 + 68);
    v5 = (*(int (__cdecl **)(int, int))(a2 + 32))(a2, v11);
    v10 = v11 + v5;
    v9 = sub_52DE00(a1 + 416, a2, v11, v11 + v5);
    if ( v9 )
    {
      *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
      v7 = a4 - 2 * *(_DWORD *)(a2 + 68);
      v6 = (*(int (__cdecl **)(int, int))(a2 + 36))(a2, v10);
      v8 = sub_52DE00(a1 + 416, a2, v6, v7);
      if ( v8 )
      {
        sub_52C0F0(v8);
        (*(void (__cdecl **)(_DWORD, int, int))(a1 + 64))(*(_DWORD *)(a1 + 4), v9, v8);
        sub_52DB80(a1 + 416);
        return 1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if ( *(_DWORD *)(a1 + 80) )
      sub_52C240(a1, a2, a3, a4);
    return 1;
  }
}
