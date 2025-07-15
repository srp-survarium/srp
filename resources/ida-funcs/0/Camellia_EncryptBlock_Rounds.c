unsigned __int32 __cdecl Camellia_EncryptBlock_Rounds(int a1, int a2, int a3, unsigned __int32 *a4)
{
  void *v4; // esp
  unsigned int v5; // ebx
  __int64 v6; // rax
  unsigned __int32 result; // eax
  unsigned int v8; // ecx
  _DWORD v9[5]; // [esp+0h] [ebp-2Ch] BYREF
  int v10; // [esp+14h] [ebp-18h]
  int *v11; // [esp+18h] [ebp-14h]
  int v12; // [esp+1Ch] [ebp-10h] BYREF

  v4 = alloca(((unsigned int)&v9[31] - a3 + 3) & 0x3C0);
  v11 = &v12;
  v10 = a3 + (a1 << 6);
  v9[0] = 6768893;
  v5 = _byteswap_ulong(*(_DWORD *)(a2 + 4));
  v6 = _x86_Camellia_encrypt(v9[1], v9[2], v9[3], v9[4], v10);
  result = _byteswap_ulong(v6);
  *a4 = result;
  a4[1] = _byteswap_ulong(v5);
  a4[2] = _byteswap_ulong(v8);
  a4[3] = _byteswap_ulong(HIDWORD(v6));
  return result;
}
