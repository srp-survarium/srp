int __cdecl sub_647530(int a1, int a2, int a3, int a4)
{
  _BYTE *v5; // [esp+0h] [ebp-4h]

  if ( *(_DWORD *)(a1 + 68) )
  {
    v5 = (_BYTE *)sub_6491A0(a1 + 416, a2, a3 + 4 * *(_DWORD *)(a2 + 68), a4 - 3 * *(_DWORD *)(a2 + 68));
    if ( v5 )
    {
      sub_647490(v5);
      (*(void (__cdecl **)(_DWORD, _BYTE *))(a1 + 68))(*(_DWORD *)(a1 + 4), v5);
      sub_648F20(a1 + 416);
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
      sub_6475E0(a1, a2, a3, a4);
    return 1;
  }
}
