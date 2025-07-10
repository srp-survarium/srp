int __cdecl sub_528670(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // [esp+0h] [ebp-8h] BYREF
  int v6; // [esp+4h] [ebp-4h]

  v5 = a2;
  v6 = (**(int (__cdecl ***)(_DWORD, int, int, int *))(a1 + 144))(*(_DWORD *)(a1 + 144), a2, a3, &v5);
  return sub_5286F0(a1, *(_DWORD *)(a1 + 144), a2, a3, v6, v5, a4, *(_BYTE *)(a1 + 484) == 0);
}
