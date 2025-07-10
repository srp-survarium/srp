int __cdecl sub_52D4B0(int a1, char a2, int a3)
{
  int v4; // [esp+0h] [ebp-Ch]
  _BYTE v5[8]; // [esp+4h] [ebp-8h] BYREF

  sub_52DAD0(v5, a1 + 20);
  while ( 1 )
  {
    v4 = sub_52DB00(v5);
    if ( !v4 )
      break;
    if ( *(_DWORD *)(v4 + 16) )
      (*(void (__cdecl **)(_DWORD))(a3 + 8))(*(_DWORD *)(v4 + 20));
  }
  sub_52DA30(a1);
  sub_52DA30(a1 + 132);
  sub_52DA30(a1 + 20);
  sub_52DA30(a1 + 40);
  sub_52DA30(a1 + 60);
  sub_52DC00(a1 + 80);
  sub_52DC00(a1 + 104);
  if ( a2 )
  {
    (*(void (__cdecl **)(_DWORD))(a3 + 8))(*(_DWORD *)(a1 + 184));
    (*(void (__cdecl **)(_DWORD))(a3 + 8))(*(_DWORD *)(a1 + 164));
  }
  return (*(int (__cdecl **)(int))(a3 + 8))(a1);
}
