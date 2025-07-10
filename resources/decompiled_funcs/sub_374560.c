int __cdecl sub_374560(int a1)
{
  int v1; // eax
  int result; // eax

  v1 = *(_DWORD *)(a1 + 416);
  *(_DWORD *)v1 = sub_374470;
  *(_BYTE *)(v1 + 16) = 0;
  *(_BYTE *)(v1 + 17) = 0;
  *(_DWORD *)(v1 + 20) = 1;
  (*(void (__cdecl **)(int))(*(_DWORD *)a1 + 16))(a1);
  result = (**(int (__cdecl ***)(int))(a1 + 420))(a1);
  *(_DWORD *)(a1 + 140) = 0;
  return result;
}
