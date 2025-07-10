int __usercall _x86_AES_encrypt_compact@<eax>(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        int a4@<ebx>,
        int a5@<ebp>,
        _DWORD *a6@<edi>,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  unsigned int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // ecx
  unsigned int v16; // edx
  int v17; // esi
  unsigned int v18; // ebx
  int v19; // esi
  int v20; // edx
  int v21; // ebp
  unsigned int v22; // esi
  int v23; // ecx
  int v24; // ebp
  int v25; // ecx
  unsigned int v26; // esi
  int v27; // ebp
  int v28; // edx
  unsigned int v29; // esi
  int v30; // ebp
  int v31; // eax
  unsigned int v32; // esi
  int v33; // ebp
  int v34; // ebx
  int v36; // [esp+4h] [ebp+4h]
  int v37; // [esp+8h] [ebp+8h]
  _DWORD *v38; // [esp+14h] [ebp+14h]

  v38 = a6;
  v13 = *a6 ^ a1;
  v14 = a6[1] ^ a4;
  v15 = a6[2] ^ a3;
  v16 = a6[3] ^ a2;
  do
  {
    v36 = (*(unsigned __int8 *)(a5 + HIBYTE(v16) - 128) << 24)
        ^ (*(unsigned __int8 *)(a5 + BYTE2(v15) - 128) << 16)
        ^ (*(unsigned __int8 *)(a5 + BYTE1(v14) - 128) << 8)
        ^ *(unsigned __int8 *)(a5 + (unsigned __int8)v13 - 128);
    v17 = (unsigned __int8)v14;
    v18 = HIWORD(v14);
    v37 = (*(unsigned __int8 *)(a5 + HIBYTE(v13) - 128) << 24)
        ^ (*(unsigned __int8 *)(a5 + BYTE2(v16) - 128) << 16)
        ^ (*(unsigned __int8 *)(a5 + BYTE1(v15) - 128) << 8)
        ^ *(unsigned __int8 *)(a5 + v17 - 128);
    v19 = (*(unsigned __int8 *)(a5 + BYTE1(v18) - 128) << 24)
        ^ (*(unsigned __int8 *)(a5 + BYTE2(v13) - 128) << 16)
        ^ (*(unsigned __int8 *)(a5 + BYTE1(v16) - 128) << 8)
        ^ *(unsigned __int8 *)(a5 + (unsigned __int8)v15 - 128);
    v20 = (*(unsigned __int8 *)(a5 + HIBYTE(v15) - 128) << 24)
        ^ (*(unsigned __int8 *)(a5 + (unsigned __int8)v18 - 128) << 16)
        ^ (*(unsigned __int8 *)(a5 + BYTE1(v13) - 128) << 8)
        ^ *(unsigned __int8 *)(a5 + (unsigned __int8)v16 - 128);
    v21 = v19;
    v22 = (2 * v19) & 0xFEFEFEFE ^ ((v19 & 0x80808080) - ((v19 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v23 = __ROL4__(v22 ^ v21, 24);
    v24 = __ROR4__(v21, 16);
    v25 = __ROR4__(v24, 8) ^ v24 ^ v22 ^ v23;
    v26 = (2 * v20) & 0xFEFEFEFE ^ ((v20 & 0x80808080) - ((v20 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v27 = __ROR4__(v20, 16);
    v28 = __ROR4__(v27, 8) ^ v27 ^ v26 ^ __ROL4__(v26 ^ v20, 24);
    v29 = (2 * v36) & 0xFEFEFEFE ^ ((v36 & 0x80808080) - ((v36 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v30 = __ROR4__(v36, 16);
    v31 = __ROR4__(v30, 8) ^ v30 ^ v29 ^ __ROL4__(v29 ^ v36, 24);
    v32 = (2 * v37) & 0xFEFEFEFE ^ ((v37 & 0x80808080) - ((v37 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v33 = __ROR4__(v37, 16);
    v34 = __ROR4__(v33, 8) ^ v33 ^ v32 ^ __ROL4__(v32 ^ v37, 24);
    a5 = a13;
    v13 = v38[4] ^ v31;
    v14 = v38[5] ^ v34;
    v15 = v38[6] ^ v25;
    v16 = v38[7] ^ v28;
    v38 += 4;
  }
  while ( v38 < &a6[4 * a6[60] - 4] );
  return v38[4]
       ^ (*(unsigned __int8 *)(a13 + HIBYTE(v16) - 128) << 24)
       ^ (*(unsigned __int8 *)(a13 + BYTE2(v15) - 128) << 16)
       ^ (*(unsigned __int8 *)(a13 + BYTE1(v14) - 128) << 8)
       ^ *(unsigned __int8 *)(a13 + (unsigned __int8)v13 - 128);
}
