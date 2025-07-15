unsigned __int32 __cdecl Camellia_decrypt(int a1, unsigned __int32 *a2, int a3)
{
  void *v3; // esp
  unsigned int v4; // ebx
  __int64 v5; // rax
  unsigned __int32 result; // eax
  unsigned int v7; // ecx
  _DWORD v8[7]; // [esp+0h] [ebp-2Ch] BYREF
  int v9; // [esp+1Ch] [ebp-10h] BYREF

  v3 = alloca(((unsigned int)&v8[31] - a3 + 3) & 0x3C0);
  v8[5] = a3;
  v8[6] = &v9;
  v8[0] = 8134479;
  v4 = _byteswap_ulong(*(_DWORD *)(a1 + 4));
  v5 = _x86_Camellia_decrypt(v8[1], v8[2], v8[3], v8[4], a3);
  result = _byteswap_ulong(v5);
  *a2 = result;
  a2[1] = _byteswap_ulong(v4);
  a2[2] = _byteswap_ulong(v7);
  a2[3] = _byteswap_ulong(HIDWORD(v5));
  return result;
}
