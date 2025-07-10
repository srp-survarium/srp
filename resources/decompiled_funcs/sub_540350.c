BOOL __cdecl sub_540350(int a1, int a2)
{
  int v4; // [esp+4h] [ebp-8h]

  v4 = (*(int (__cdecl **)(_DWORD, int))(a1 + 368))(*(_DWORD *)(a1 + 372), a2);
  return (v4 & 0xFFFF0000) != 0 || sub_53FD00(v4) < 0;
}
