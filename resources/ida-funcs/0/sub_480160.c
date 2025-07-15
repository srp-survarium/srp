void __usercall sub_480160(int a1@<ebx>)
{
  int v1; // eax
  int v2; // esi
  int i; // eax
  int v4; // esi

  v1 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 1408);
  v2 = v1 + 256;
  *(_DWORD *)(a1 + 292) = v1 + 256;
  memset(v1, 0, 256);
  for ( i = 0; i <= 255; ++i )
    *(_BYTE *)(i + v2) = i;
  v4 = v2 + 128;
  memset(v4 + 128, 255, 384);
  memset(v4 + 512, 0, 384);
  qmemcpy((void *)(v4 + 896), *(const void **)(a1 + 292), 0x80u);
}
