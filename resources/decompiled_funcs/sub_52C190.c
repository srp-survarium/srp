int __cdecl sub_52C190(int a1, int a2, int a3, int a4)
{
  _BYTE *v5; // [esp+0h] [ebp-4h]

  if ( *(_DWORD *)(a1 + 68) )
  {
    v5 = (_BYTE *)sub_52DE00(a1 + 416, a2, a3 + 4 * *(_DWORD *)(a2 + 68), a4 - 3 * *(_DWORD *)(a2 + 68));
    if ( v5 )
    {
      sub_52C0F0(v5);
      (*(void (__cdecl **)(_DWORD, _BYTE *))(a1 + 68))(*(_DWORD *)(a1 + 4), v5);
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
    if ( *(_DWORD *)(a1 + 80) )
      sub_52C240(a1, a2, a3, a4);
    return 1;
  }
}
