void __cdecl Camellia_encrypt(const unsigned __int8 *a1, unsigned __int8 *a2, _DWORD *a3)
{
  int v3; // eax
  void *v4; // esp
  unsigned int v5; // ebx
  __int64 v6; // rax
  unsigned int v7; // ecx
  _DWORD v8[5]; // [esp+0h] [ebp-2Ch] BYREF
  char *v9; // [esp+14h] [ebp-18h]
  int *v10; // [esp+18h] [ebp-14h]
  int v11; // [esp+1Ch] [ebp-10h] BYREF

  v3 = a3[68];
  v4 = alloca(((char *)v8 - ((char *)a3 - 127)) & 0x3C0);
  v10 = &v11;
  v9 = (char *)&a3[16 * v3];
  v8[0] = 6769055;
  v5 = _byteswap_ulong(*((_DWORD *)a1 + 1));
  v6 = _x86_Camellia_encrypt(v8[1], v8[2], v8[3], v8[4], v9);
  *(_DWORD *)a2 = _byteswap_ulong(v6);
  *((_DWORD *)a2 + 1) = _byteswap_ulong(v5);
  *((_DWORD *)a2 + 2) = _byteswap_ulong(v7);
  *((_DWORD *)a2 + 3) = _byteswap_ulong(HIDWORD(v6));
}
