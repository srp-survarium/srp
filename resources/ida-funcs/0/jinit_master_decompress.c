int __cdecl jinit_master_decompress(int a1)
{
  int v1; // eax

  v1 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 28);
  *(_DWORD *)(a1 + 400) = v1;
  *(_DWORD *)v1 = sub_4803B0;
  *(_DWORD *)(v1 + 4) = sub_480510;
  *(_BYTE *)(v1 + 8) = 0;
  return sub_4801F0(a1);
}
