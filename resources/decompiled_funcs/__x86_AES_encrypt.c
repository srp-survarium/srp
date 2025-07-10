unsigned int __usercall _x86_AES_encrypt@<eax>(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        int a4@<ebx>,
        int a5@<ebp>,
        _DWORD *a6@<edi>)
{
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // edx
  int v10; // esi
  unsigned int v11; // ebx
  int v12; // esi
  int v13; // edx
  int v16; // [esp+4h] [ebp+4h]
  int v18; // [esp+8h] [ebp+8h]
  _DWORD *v22; // [esp+14h] [ebp+14h]

  v22 = a6;
  v6 = *a6 ^ a1;
  v7 = a6[1] ^ a4;
  v8 = a6[2] ^ a3;
  v9 = a6[3] ^ a2;
  do
  {
    v16 = *(_DWORD *)(a5 + 8 * HIBYTE(v9) + 1)
        ^ *(_DWORD *)(a5 + 8 * BYTE2(v8) + 2)
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v7) + 3)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v6);
    v10 = (unsigned __int8)v7;
    v11 = HIWORD(v7);
    v18 = *(_DWORD *)(a5 + 8 * HIBYTE(v6) + 1)
        ^ *(_DWORD *)(a5 + 8 * BYTE2(v9) + 2)
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v8) + 3)
        ^ *(_DWORD *)(a5 + 8 * v10);
    v12 = *(_DWORD *)(a5 + 8 * BYTE1(v11) + 1)
        ^ *(_DWORD *)(a5 + 8 * BYTE2(v6) + 2)
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v9) + 3)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v8);
    v13 = *(_DWORD *)(a5 + 8 * HIBYTE(v8) + 1)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v11 + 2)
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v6) + 3)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v9);
    v6 = v22[4] ^ v16;
    v7 = v22[5] ^ v18;
    v8 = v22[6] ^ v12;
    v9 = v22[7] ^ v13;
    v22 += 4;
  }
  while ( v22 < &a6[4 * a6[60] - 4] );
  return v22[4]
       ^ *(_DWORD *)(a5 + 8 * HIBYTE(v9) + 2)
       & 0xFF000000
       ^ (unsigned int)&vostok::memory::s_CRT_arena[5508664]
       & *(_DWORD *)(a5 + 8 * BYTE2(v8))
       ^ *(_DWORD *)(a5 + 8 * BYTE1(v7))
       & 0xFF00
       ^ (unsigned __int8)*(_DWORD *)(a5 + 8 * (unsigned __int8)v6 + 2);
}
