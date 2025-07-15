int __cdecl sub_3749E0(_DWORD *a1, unsigned int a2, char a3, int a4, int a5, int a6)
{
  int v6; // edi
  int result; // eax

  v6 = a1[1];
  if ( a2 != 1 )
  {
    *(_DWORD *)(*a1 + 20) = 15;
    *(_DWORD *)(*a1 + 24) = a2;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  result = sub_374640(a1, a2, 0x78u);
  *(_DWORD *)(result + 4) = a5;
  *(_DWORD *)(result + 8) = a4;
  *(_DWORD *)result = 0;
  *(_DWORD *)(result + 12) = a6;
  *(_BYTE *)(result + 32) = a3;
  *(_BYTE *)(result + 34) = 0;
  *(_DWORD *)(result + 36) = *(_DWORD *)(v6 + 72);
  *(_DWORD *)(v6 + 72) = result;
  return result;
}
