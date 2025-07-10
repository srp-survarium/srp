int __usercall _x86_AES_decrypt@<eax>(
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
  int v11; // edx
  int v14; // [esp+4h] [ebp+4h]
  int v16; // [esp+8h] [ebp+8h]
  _DWORD *v20; // [esp+14h] [ebp+14h]

  v20 = a6;
  v6 = *a6 ^ a1;
  v7 = a6[1] ^ a4;
  v8 = a6[2] ^ a3;
  v9 = a6[3] ^ a2;
  do
  {
    v14 = *(_DWORD *)(a5 + 8 * HIBYTE(v7) + 1)
        ^ *(_DWORD *)(a5 + 8 * BYTE2(v8) + 2)
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v9) + 3)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v6);
    v16 = *(_DWORD *)(a5 + 8 * HIBYTE(v8) + 1)
        ^ *(_DWORD *)(a5 + 8 * BYTE2(v9) + 2)
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v6) + 3)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v7);
    v10 = *(_DWORD *)(a5 + 8 * HIBYTE(v9) + 1)
        ^ *(_DWORD *)(a5 + 8 * BYTE2(v6) + 2)
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v7) + 3)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v8);
    v11 = *(_DWORD *)(a5 + 8 * HIBYTE(v6) + 1)
        ^ *(_DWORD *)(a5 + 8 * BYTE2(v7) + 2)
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v8) + 3)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v9);
    v6 = v20[4] ^ v14;
    v7 = v20[5] ^ v16;
    v8 = v20[6] ^ v10;
    v9 = v20[7] ^ v11;
    v20 += 4;
  }
  while ( v20 < &a6[4 * a6[60] - 4] );
  return v20[4]
       ^ (*(unsigned __int8 *)(a5 + 2048 + HIBYTE(v7)) << 24)
       ^ (*(unsigned __int8 *)(a5 + 2048 + BYTE2(v8)) << 16)
       ^ (*(unsigned __int8 *)(a5 + 2048 + BYTE1(v9)) << 8)
       ^ *(unsigned __int8 *)(a5 + 2048 + (unsigned __int8)v6);
}
