int __cdecl jinit_merged_upsampler(int a1)
{
  int v1; // esi
  int v2; // edx

  v1 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 48);
  *(_DWORD *)(a1 + 432) = v1;
  *(_DWORD *)v1 = sub_37AE00;
  *(_BYTE *)(v1 + 8) = 0;
  v2 = *(_DWORD *)(a1 + 92) * *(_DWORD *)(a1 + 100);
  *(_DWORD *)(v1 + 40) = v2;
  if ( *(_DWORD *)(a1 + 276) == 2 )
  {
    *(_DWORD *)(v1 + 4) = sub_37AE20;
    *(_DWORD *)(v1 + 12) = sub_37B070;
    *(_DWORD *)(v1 + 32) = (*(int (__cdecl **)(int, int, int))(*(_DWORD *)(a1 + 4) + 4))(a1, 1, v2);
  }
  else
  {
    *(_DWORD *)(v1 + 32) = 0;
    *(_DWORD *)(v1 + 4) = sub_37AEE0;
    *(_DWORD *)(v1 + 12) = sub_37AF20;
  }
  return sub_37AD30(a1);
}
