int __cdecl sub_5402D0(int a1, int a2)
{
  int v3; // [esp+0h] [ebp-8h]

  v3 = (*(int (__cdecl **)(_DWORD, int))(a1 + 368))(*(_DWORD *)(a1 + 372), a2);
  if ( (v3 & 0xFFFF0000) != 0 )
    return 0;
  else
    return dword_88A300[8 * (unsigned __int8)byte_88A800[v3 >> 8] + ((int)(unsigned __int8)v3 >> 5)]
         & (1 << (v3 & 0x1F));
}
