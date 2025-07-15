int __cdecl jinit_merged_upsampler(int a1)
{
  int v1; // esi
  int v2; // edx

  v1 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 48);
  *(_DWORD *)(a1 + 432) = v1;
  *(_DWORD *)v1 = sub_487AC0;
  *(_BYTE *)(v1 + 8) = 0;
  v2 = *(_DWORD *)(a1 + 92) * *(_DWORD *)(a1 + 100);
  *(_DWORD *)(v1 + 40) = v2;
  if ( *(_DWORD *)(a1 + 276) == 2 )
  {
    *(_DWORD *)(v1 + 4) = sub_487AE0;
    *(_DWORD *)(v1 + 12) = sub_487D30;
    *(_DWORD *)(v1 + 32) = (*(int (__cdecl **)(int, int, int))(*(_DWORD *)(a1 + 4) + 4))(a1, 1, v2);
  }
  else
  {
    *(_DWORD *)(v1 + 32) = 0;
    *(_DWORD *)(v1 + 4) = sub_487BA0;
    *(_DWORD *)(v1 + 12) = sub_487BE0;
  }
  return sub_4879F0(a1);
}
