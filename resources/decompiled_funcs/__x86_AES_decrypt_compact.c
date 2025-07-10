int __usercall _x86_AES_decrypt_compact@<eax>(
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
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  unsigned int v21; // eax
  unsigned int v22; // ebx
  unsigned int v23; // esi
  unsigned int v24; // ebx
  unsigned int v25; // ecx
  unsigned int v26; // esi
  unsigned int v27; // ecx
  unsigned int v28; // edx
  unsigned int v29; // esi
  unsigned int v30; // eax
  unsigned int v31; // ecx
  unsigned int v32; // edx
  unsigned int v33; // esi
  int v35; // [esp+4h] [ebp+4h]
  int v36; // [esp+8h] [ebp+8h]
  unsigned int v37; // [esp+Ch] [ebp+Ch]
  unsigned int v38; // [esp+10h] [ebp+10h]
  _DWORD *v39; // [esp+14h] [ebp+14h]

  v39 = a6;
  v13 = *a6 ^ a1;
  v14 = a6[1] ^ a4;
  v15 = a6[2] ^ a3;
  v16 = a6[3] ^ a2;
  do
  {
    v35 = (*(unsigned __int8 *)(a5 + HIBYTE(v14) - 128) << 24)
        ^ (*(unsigned __int8 *)(a5 + BYTE2(v15) - 128) << 16)
        ^ (*(unsigned __int8 *)(a5 + BYTE1(v16) - 128) << 8)
        ^ *(unsigned __int8 *)(a5 + (unsigned __int8)v13 - 128);
    v36 = (*(unsigned __int8 *)(a5 + HIBYTE(v15) - 128) << 24)
        ^ (*(unsigned __int8 *)(a5 + BYTE2(v16) - 128) << 16)
        ^ (*(unsigned __int8 *)(a5 + BYTE1(v13) - 128) << 8)
        ^ *(unsigned __int8 *)(a5 + (unsigned __int8)v14 - 128);
    v17 = (*(unsigned __int8 *)(a5 + HIBYTE(v16) - 128) << 24)
        ^ (*(unsigned __int8 *)(a5 + BYTE2(v13) - 128) << 16)
        ^ (*(unsigned __int8 *)(a5 + BYTE1(v14) - 128) << 8)
        ^ *(unsigned __int8 *)(a5 + (unsigned __int8)v15 - 128);
    v18 = (*(unsigned __int8 *)(a5 + BYTE1(v15) - 128) << 8) ^ *(unsigned __int8 *)(a5 + (unsigned __int8)v16 - 128);
    v19 = v17;
    v20 = (*(unsigned __int8 *)(a5 + HIBYTE(v13) - 128) << 24)
        ^ (*(unsigned __int8 *)(a5 + BYTE2(v14) - 128) << 16)
        ^ v18;
    v21 = (2 * v17) & 0xFEFEFEFE ^ ((v17 & 0x80808080) - ((v17 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v22 = (2 * v21) & 0xFEFEFEFE ^ ((v21 & 0x80808080) - ((v21 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v23 = ((v22 & 0x80808080) - ((v22 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v37 = __ROL4__(v23 ^ (2 * v22) & 0xFEFEFEFE, 8)
        ^ __ROL4__(v23 ^ (2 * v22) & 0xFEFEFEFE ^ v19 ^ v22, 16)
        ^ __ROL4__(v23 ^ (2 * v22) & 0xFEFEFEFE ^ v19 ^ v21, 24)
        ^ v23
        ^ (2 * v22)
        & 0xFEFEFEFE
        ^ v19
        ^ v22
        ^ v19
        ^ v21
        ^ __ROL4__(v19, 8);
    v24 = (2 * v20) & 0xFEFEFEFE ^ ((v20 & 0x80808080) - ((v20 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v25 = (2 * v24) & 0xFEFEFEFE ^ ((v24 & 0x80808080) - ((v24 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v26 = ((v25 & 0x80808080) - ((v25 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v38 = __ROL4__(v26 ^ (2 * v25) & 0xFEFEFEFE, 8)
        ^ __ROL4__(v26 ^ (2 * v25) & 0xFEFEFEFE ^ v20 ^ v25, 16)
        ^ __ROL4__(v26 ^ (2 * v25) & 0xFEFEFEFE ^ v20 ^ v24, 24)
        ^ v26
        ^ (2 * v25)
        & 0xFEFEFEFE
        ^ v20
        ^ v25
        ^ v20
        ^ v24
        ^ __ROL4__(v20, 8);
    v27 = (2 * v35) & 0xFEFEFEFE ^ ((v35 & 0x80808080) - ((v35 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v28 = (2 * v27) & 0xFEFEFEFE ^ ((v27 & 0x80808080) - ((v27 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v29 = ((v28 & 0x80808080) - ((v28 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v30 = __ROL4__(v29 ^ (2 * v28) & 0xFEFEFEFE, 8)
        ^ __ROL4__(v29 ^ (2 * v28) & 0xFEFEFEFE ^ v35 ^ v28, 16)
        ^ __ROL4__(v29 ^ (2 * v28) & 0xFEFEFEFE ^ v35 ^ v27, 24)
        ^ v29
        ^ (2 * v28)
        & 0xFEFEFEFE
        ^ v35
        ^ v28
        ^ v35
        ^ v27
        ^ __ROL4__(v35, 8);
    v31 = (2 * v36) & 0xFEFEFEFE ^ ((v36 & 0x80808080) - ((v36 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v32 = (2 * v31) & 0xFEFEFEFE ^ ((v31 & 0x80808080) - ((v31 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    v33 = ((v32 & 0x80808080) - ((v32 & 0x80808080) >> 7)) & 0x1B1B1B1B;
    a5 = a13;
    v13 = v39[4] ^ v30;
    v14 = v39[5]
        ^ __ROL4__(v33 ^ (2 * v32) & 0xFEFEFEFE, 8)
        ^ __ROL4__(v33 ^ (2 * v32) & 0xFEFEFEFE ^ v36 ^ v32, 16)
        ^ __ROL4__(v33 ^ (2 * v32) & 0xFEFEFEFE ^ v36 ^ v31, 24)
        ^ v33
        ^ (2 * v32)
        & 0xFEFEFEFE
        ^ v36
        ^ v32
        ^ v36
        ^ v31
        ^ __ROL4__(v36, 8);
    v15 = v39[6] ^ v37;
    v16 = v39[7] ^ v38;
    v39 += 4;
  }
  while ( v39 < &a6[4 * a6[60] - 4] );
  return v39[4]
       ^ (*(unsigned __int8 *)(a13 + HIBYTE(v14) - 128) << 24)
       ^ (*(unsigned __int8 *)(a13 + BYTE2(v15) - 128) << 16)
       ^ (*(unsigned __int8 *)(a13 + BYTE1(v16) - 128) << 8)
       ^ *(unsigned __int8 *)(a13 + (unsigned __int8)v13 - 128);
}
