int __cdecl Camellia_Ekeygen(int a1, unsigned int *a2, int *a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // ecx
  int v6; // edx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned __int32 v11; // eax
  unsigned __int32 v12; // ebx
  unsigned __int32 v13; // ecx
  unsigned __int32 v14; // edx
  int *v15; // ebp
  int v16; // esi
  int v17; // ebx
  int v18; // edx
  int v19; // ecx
  int v20; // esi
  int v21; // edx
  int v22; // ebx
  int v23; // eax
  int v24; // esi
  int v25; // ebx
  int v26; // edx
  int v27; // ecx
  int v28; // esi
  int v29; // edx
  int v30; // ebx
  int v31; // eax
  int v32; // eax
  __int64 v33; // rcx
  unsigned int v34; // ebp
  int v35; // eax
  __int64 v36; // rcx
  int v37; // edx
  unsigned int v38; // ebp
  int v39; // eax
  int v40; // edx
  unsigned int v41; // ebp
  int v42; // eax
  int v43; // edx
  unsigned int v44; // ebp
  __int64 v45; // rax
  unsigned int v46; // ebp
  unsigned int v47; // ebp
  unsigned __int64 v48; // kr00_8
  unsigned int v49; // esi
  unsigned int v50; // ebp
  unsigned int v51; // ebp
  unsigned int v52; // ebp
  unsigned int v53; // ebp
  int v55; // esi
  int v56; // ebx
  int v57; // edx
  int v58; // ecx
  int v59; // esi
  int v60; // edx
  int v61; // ebx
  int v62; // eax
  __int64 v63; // rcx
  int v64; // eax
  int v65; // edx
  unsigned int v66; // ebp
  __int64 v67; // rax
  unsigned int v68; // ebp
  unsigned __int64 v69; // kr08_8
  unsigned int v70; // esi
  unsigned int v71; // ebp
  unsigned int v72; // ebp
  unsigned __int64 v73; // kr10_8
  unsigned int v74; // esi
  unsigned int v75; // ebp
  unsigned __int64 v76; // kr18_8
  unsigned int v77; // esi
  unsigned int v78; // ebp
  int v79; // [esp+0h] [ebp-20h]
  int v80; // [esp+0h] [ebp-20h]
  int v81; // [esp+0h] [ebp-20h]
  unsigned int v82; // [esp+0h] [ebp-20h]
  int v83; // [esp+4h] [ebp-1Ch]
  int v84; // [esp+4h] [ebp-1Ch]
  int v85; // [esp+4h] [ebp-1Ch]
  int v86; // [esp+8h] [ebp-18h]
  int v87; // [esp+8h] [ebp-18h]
  int v88; // [esp+8h] [ebp-18h]
  int v89; // [esp+8h] [ebp-18h]
  int v90; // [esp+Ch] [ebp-14h]
  int v91; // [esp+Ch] [ebp-14h]
  int v92; // [esp+Ch] [ebp-14h]
  int v93; // [esp+Ch] [ebp-14h]

  v3 = _byteswap_ulong(*a2);
  v4 = _byteswap_ulong(a2[1]);
  v5 = _byteswap_ulong(a2[2]);
  v6 = _byteswap_ulong(a2[3]);
  *a3 = v3;
  a3[1] = v4;
  a3[2] = v5;
  a3[3] = v6;
  if ( a1 != 128 )
  {
    v7 = a2[4];
    v8 = a2[5];
    if ( a1 == 192 )
    {
      v9 = ~v7;
      v10 = ~v8;
    }
    else
    {
      v9 = a2[6];
      v10 = a2[7];
    }
    v11 = _byteswap_ulong(v7);
    v12 = _byteswap_ulong(v8);
    v13 = _byteswap_ulong(v9);
    v14 = _byteswap_ulong(v10);
    a3[8] = v11;
    a3[9] = v12;
    a3[10] = v13;
    a3[11] = v14;
    v3 = *a3 ^ v11;
    v4 = a3[1] ^ v12;
    v5 = a3[2] ^ v13;
    v6 = a3[3] ^ v14;
  }
  v15 = _LCamellia_SBOX;
  v16 = _LCamellia_SBOX[-16];
  v79 = v3;
  v83 = v4;
  v86 = v5;
  v90 = v6;
  v17 = _LCamellia_SBOX[-15] ^ v4;
  v18 = *(int *)((char *)&v15[2 * (unsigned __int8)((v16 ^ (unsigned int)v3) >> 16)] + (_DWORD)&loc_7C2B1C - 8135452)
      ^ v15[2 * ((v16 ^ (unsigned int)v3) >> 24)]
      ^ v15[2 * (unsigned __int8)(v16 ^ v3) + 1]
      ^ *(int *)((char *)&v15[2 * (unsigned __int8)((unsigned __int16)(v16 ^ v3) >> 8)] + (_DWORD)&loc_7C2B1F - 8135451);
  v19 = *(int *)((char *)&v15[2 * BYTE2(v17)] + (_DWORD)&loc_7C2B1F - 8135451)
      ^ *(int *)((char *)&v15[2 * HIBYTE(v17)] + (_DWORD)&loc_7C2B1C - 8135452)
      ^ v18
      ^ v15[2 * BYTE1(v17) + 1]
      ^ v15[2 * (unsigned __int8)v17];
  v20 = _LCamellia_SBOX[-14];
  v91 = v19 ^ v90 ^ __ROR4__(v18, 8);
  v87 = v86 ^ v19;
  v21 = _LCamellia_SBOX[-13] ^ v91;
  v22 = *(int *)((char *)&v15[2 * (unsigned __int8)((v20 ^ (unsigned int)v87) >> 16)] + (_DWORD)&loc_7C2B1C - 8135452)
      ^ v15[2 * ((v20 ^ (unsigned int)v87) >> 24)]
      ^ v15[2 * (unsigned __int8)(v20 ^ v87) + 1]
      ^ *(int *)((char *)&v15[2 * (unsigned __int8)((unsigned __int16)(v20 ^ v87) >> 8)] + (_DWORD)&loc_7C2B1F - 8135451);
  v23 = *(int *)((char *)&v15[2 * BYTE2(v21)] + (_DWORD)&loc_7C2B1F - 8135451)
      ^ *(int *)((char *)&v15[2 * HIBYTE(v21)] + (_DWORD)&loc_7C2B1C - 8135452)
      ^ v22
      ^ v15[2 * BYTE1(v21) + 1]
      ^ v15[2 * (unsigned __int8)v21];
  v24 = _LCamellia_SBOX[-12];
  v80 = *a3 ^ v79 ^ v23;
  v84 = a3[1] ^ v23 ^ v83 ^ __ROR4__(v22, 8);
  v25 = _LCamellia_SBOX[-11] ^ v84;
  v26 = *(int *)((char *)&v15[2 * (unsigned __int8)((v24 ^ (unsigned int)v80) >> 16)] + (_DWORD)&loc_7C2B1C - 8135452)
      ^ v15[2 * ((v24 ^ (unsigned int)v80) >> 24)]
      ^ v15[2 * (unsigned __int8)(v24 ^ v80) + 1]
      ^ *(int *)((char *)&v15[2 * (unsigned __int8)((unsigned __int16)(v24 ^ v80) >> 8)] + (_DWORD)&loc_7C2B1F - 8135451);
  v27 = *(int *)((char *)&v15[2 * BYTE2(v25)] + (_DWORD)&loc_7C2B1F - 8135451)
      ^ *(int *)((char *)&v15[2 * HIBYTE(v25)] + (_DWORD)&loc_7C2B1C - 8135452)
      ^ v26
      ^ v15[2 * BYTE1(v25) + 1]
      ^ v15[2 * (unsigned __int8)v25];
  v28 = _LCamellia_SBOX[-10];
  v92 = v27 ^ a3[3] ^ v91 ^ __ROR4__(v26, 8);
  v88 = a3[2] ^ v87 ^ v27;
  v29 = _LCamellia_SBOX[-9] ^ v92;
  v30 = *(int *)((char *)&v15[2 * (unsigned __int8)((v28 ^ (unsigned int)v88) >> 16)] + (_DWORD)&loc_7C2B1C - 8135452)
      ^ v15[2 * ((v28 ^ (unsigned int)v88) >> 24)]
      ^ v15[2 * (unsigned __int8)(v28 ^ v88) + 1]
      ^ *(int *)((char *)&v15[2 * (unsigned __int8)((unsigned __int16)(v28 ^ v88) >> 8)] + (_DWORD)&loc_7C2B1F - 8135451);
  v31 = *(int *)((char *)&v15[2 * BYTE2(v29)] + (_DWORD)&loc_7C2B1F - 8135451)
      ^ *(int *)((char *)&v15[2 * HIBYTE(v29)] + (_DWORD)&loc_7C2B1C - 8135452)
      ^ v30
      ^ v15[2 * BYTE1(v29) + 1]
      ^ v15[2 * (unsigned __int8)v29];
  HIDWORD(v33) = v31 ^ v84 ^ __ROR4__(v30, 8);
  v32 = v80 ^ v31;
  LODWORD(v33) = v88;
  if ( a1 == 128 )
  {
    a3[4] = v32;
    a3[5] = HIDWORD(v33);
    a3[6] = v88;
    a3[7] = v92;
    v34 = v32;
    v35 = (HIDWORD(v33) >> 17) | (v32 << 15);
    a3[12] = v35;
    HIDWORD(v36) = v33 >> 17;
    a3[13] = HIDWORD(v36);
    LODWORD(v36) = __SPAIR64__(v88, v92) >> 17;
    v37 = (v34 >> 17) | (v92 << 15);
    a3[14] = v36;
    a3[15] = v37;
    v38 = v35;
    v39 = (HIDWORD(v36) >> 17) | (v35 << 15);
    a3[16] = v39;
    HIDWORD(v36) = v36 >> 17;
    a3[17] = HIDWORD(v36);
    LODWORD(v36) = __SPAIR64__(__PAIR64__(v88, v92) >> 17, v37) >> 17;
    v40 = (v38 >> 17) | (v37 << 15);
    a3[18] = v36;
    a3[19] = v40;
    v41 = v39;
    v42 = (HIDWORD(v36) >> 17) | (v39 << 15);
    a3[24] = v42;
    HIDWORD(v36) = v36 >> 17;
    a3[25] = HIDWORD(v36);
    LODWORD(v36) = __SPAIR64__(v36, v40) >> 17;
    v43 = (v41 >> 17) | (v40 << 15);
    v44 = v42;
    LODWORD(v45) = (HIDWORD(v36) >> 17) | (v42 << 15);
    a3[28] = v45;
    HIDWORD(v36) = v36 >> 17;
    a3[29] = HIDWORD(v36);
    LODWORD(v36) = __SPAIR64__(v36, v43) >> 17;
    HIDWORD(v45) = (v44 >> 17) | (v43 << 15);
    a3[30] = v36;
    a3[31] = HIDWORD(v45);
    v46 = HIDWORD(v36);
    HIDWORD(v36) = v36 >> 30;
    a3[40] = HIDWORD(v36);
    LODWORD(v36) = __SPAIR64__(v36, HIDWORD(v45)) >> 30;
    a3[41] = v36;
    HIDWORD(v45) = v45 >> 30;
    LODWORD(v45) = (v46 >> 30) | (4 * v45);
    a3[42] = HIDWORD(v45);
    a3[43] = v45;
    a3[48] = v36 >> 15;
    a3[49] = __SPAIR64__(v36, HIDWORD(v45)) >> 15;
    a3[50] = v45 >> 15;
    a3[51] = (HIDWORD(v36) >> 15) | ((_DWORD)v45 << 17);
    LODWORD(v45) = a3[3];
    v47 = *a3;
    v48 = (unsigned __int64)(unsigned int)a3[1] << 15;
    HIDWORD(v36) = HIDWORD(v48) | (*a3 << 15);
    v49 = a3[2];
    a3[8] = HIDWORD(v36);
    LODWORD(v36) = (v49 >> 17) | v48;
    a3[9] = v36;
    HIDWORD(v45) = ((unsigned int)v45 >> 17) | (v49 << 15);
    LODWORD(v45) = (v47 >> 17) | ((_DWORD)v45 << 15);
    a3[10] = HIDWORD(v45);
    a3[11] = v45;
    v50 = HIDWORD(v36);
    HIDWORD(v36) = v36 >> 2;
    a3[20] = HIDWORD(v36);
    LODWORD(v36) = __SPAIR64__(v36, HIDWORD(v45)) >> 2;
    a3[21] = v36;
    HIDWORD(v45) = v45 >> 2;
    LODWORD(v45) = (v50 >> 2) | ((_DWORD)v45 << 30);
    a3[22] = HIDWORD(v45);
    a3[23] = v45;
    v51 = HIDWORD(v36);
    HIDWORD(v36) = v36 >> 17;
    LODWORD(v36) = __SPAIR64__(v36, HIDWORD(v45)) >> 17;
    HIDWORD(v45) = v45 >> 17;
    LODWORD(v45) = (v51 >> 17) | ((_DWORD)v45 << 15);
    a3[26] = HIDWORD(v45);
    a3[27] = v45;
    v52 = HIDWORD(v36);
    HIDWORD(v36) = v36 >> 15;
    a3[32] = HIDWORD(v36);
    LODWORD(v36) = __SPAIR64__(v36, HIDWORD(v45)) >> 15;
    a3[33] = v36;
    HIDWORD(v45) = v45 >> 15;
    LODWORD(v45) = (v52 >> 15) | ((_DWORD)v45 << 17);
    a3[34] = HIDWORD(v45);
    a3[35] = v45;
    v53 = HIDWORD(v36);
    HIDWORD(v36) = v36 >> 15;
    a3[36] = HIDWORD(v36);
    LODWORD(v36) = __SPAIR64__(v36, HIDWORD(v45)) >> 15;
    a3[37] = v36;
    HIDWORD(v45) = v45 >> 15;
    LODWORD(v45) = (v53 >> 15) | ((_DWORD)v45 << 17);
    a3[38] = HIDWORD(v45);
    a3[39] = v45;
    a3[44] = v36 >> 15;
    a3[45] = __SPAIR64__(v36, HIDWORD(v45)) >> 15;
    a3[46] = v45 >> 15;
    a3[47] = (HIDWORD(v36) >> 15) | ((_DWORD)v45 << 17);
    return 3;
  }
  else
  {
    a3[12] = v32;
    a3[13] = HIDWORD(v33);
    a3[14] = v88;
    a3[15] = v92;
    v55 = _LCamellia_SBOX[-8];
    v81 = a3[8] ^ v32;
    v85 = a3[9] ^ HIDWORD(v33);
    v56 = _LCamellia_SBOX[-7] ^ v85;
    v57 = *(int *)((char *)&_LCamellia_SBOX[2 * (unsigned __int8)((v55 ^ (unsigned int)v81) >> 16)]
                 + (_DWORD)&loc_7C2B1C
                 - 8135452)
        ^ _LCamellia_SBOX[2 * ((v55 ^ (unsigned int)v81) >> 24)]
        ^ _LCamellia_SBOX[2 * (unsigned __int8)(v55 ^ v81) + 1]
        ^ *(int *)((char *)&_LCamellia_SBOX[2 * (unsigned __int8)((unsigned __int16)(v55 ^ v81) >> 8)]
                 + (_DWORD)&loc_7C2B1F
                 - 8135451);
    v58 = *(int *)((char *)&_LCamellia_SBOX[2 * BYTE2(v56)] + (_DWORD)&loc_7C2B1F - 8135451)
        ^ *(int *)((char *)&_LCamellia_SBOX[2 * HIBYTE(v56)] + (_DWORD)&loc_7C2B1C - 8135452)
        ^ v57
        ^ _LCamellia_SBOX[2 * BYTE1(v56) + 1]
        ^ _LCamellia_SBOX[2 * (unsigned __int8)v56];
    v59 = _LCamellia_SBOX[-6];
    v93 = v58 ^ a3[11] ^ v92 ^ __ROR4__(v57, 8);
    v89 = a3[10] ^ v88 ^ v58;
    v60 = _LCamellia_SBOX[-5] ^ v93;
    v61 = *(int *)((char *)&_LCamellia_SBOX[2 * (unsigned __int8)((v59 ^ (unsigned int)v89) >> 16)]
                 + (_DWORD)&loc_7C2B1C
                 - 8135452)
        ^ _LCamellia_SBOX[2 * ((v59 ^ (unsigned int)v89) >> 24)]
        ^ _LCamellia_SBOX[2 * (unsigned __int8)(v59 ^ v89) + 1]
        ^ *(int *)((char *)&_LCamellia_SBOX[2 * (unsigned __int8)((unsigned __int16)(v59 ^ v89) >> 8)]
                 + (_DWORD)&loc_7C2B1F
                 - 8135451);
    v62 = *(int *)((char *)&_LCamellia_SBOX[2 * BYTE2(v60)] + (_DWORD)&loc_7C2B1F - 8135451)
        ^ *(int *)((char *)&_LCamellia_SBOX[2 * HIBYTE(v60)] + (_DWORD)&loc_7C2B1C - 8135452)
        ^ v61
        ^ _LCamellia_SBOX[2 * BYTE1(v60) + 1]
        ^ _LCamellia_SBOX[2 * (unsigned __int8)v60];
    HIDWORD(v63) = v62 ^ v85 ^ __ROR4__(v61, 8);
    v82 = v81 ^ v62;
    LODWORD(v63) = v89;
    a3[4] = v82;
    a3[5] = HIDWORD(v63);
    a3[6] = v89;
    a3[7] = v93;
    v64 = (HIDWORD(v63) >> 2) | (v82 << 30);
    a3[20] = v64;
    HIDWORD(v63) = v63 >> 2;
    a3[21] = HIDWORD(v63);
    LODWORD(v63) = __SPAIR64__(v89, v93) >> 2;
    v65 = (v82 >> 2) | (v93 << 30);
    a3[22] = v63;
    a3[23] = v65;
    v66 = v64;
    LODWORD(v67) = (HIDWORD(v63) >> 2) | (v64 << 30);
    a3[40] = v67;
    HIDWORD(v63) = v63 >> 2;
    a3[41] = HIDWORD(v63);
    LODWORD(v63) = (__int64)((__PAIR64__(v89, v93) << 30) | (v82 >> 2)) >> 2;
    HIDWORD(v67) = (v66 >> 2) | (v65 << 30);
    a3[42] = v63;
    a3[43] = HIDWORD(v67);
    a3[64] = v63 >> 13;
    a3[65] = __SPAIR64__(((__PAIR64__(v89, v93) << 30) | (v82 >> 2)) >> 2, HIDWORD(v67)) >> 13;
    a3[66] = v67 >> 13;
    a3[67] = (HIDWORD(v63) >> 13) | ((_DWORD)v67 << 19);
    LODWORD(v67) = a3[11];
    v68 = a3[8];
    v69 = (unsigned __int64)(unsigned int)a3[9] << 15;
    HIDWORD(v63) = HIDWORD(v69) | (v68 << 15);
    v70 = a3[10];
    a3[8] = HIDWORD(v63);
    LODWORD(v63) = (v70 >> 17) | v69;
    a3[9] = v63;
    HIDWORD(v67) = ((unsigned int)v67 >> 17) | (v70 << 15);
    LODWORD(v67) = (v68 >> 17) | ((_DWORD)v67 << 15);
    a3[10] = HIDWORD(v67);
    a3[11] = v67;
    HIDWORD(v63) = v63 >> 17;
    a3[16] = HIDWORD(v63);
    LODWORD(v63) = __SPAIR64__(v63, HIDWORD(v67)) >> 17;
    a3[17] = v63;
    HIDWORD(v67) = v67 >> 17;
    LODWORD(v67) = ((HIDWORD(v69) | (v68 << 15)) >> 17) | ((_DWORD)v67 << 15);
    a3[18] = HIDWORD(v67);
    a3[19] = v67;
    v71 = HIDWORD(v63);
    HIDWORD(v63) = v63 >> 2;
    a3[36] = HIDWORD(v63);
    LODWORD(v63) = __SPAIR64__(v63, HIDWORD(v67)) >> 2;
    a3[37] = v63;
    HIDWORD(v67) = v67 >> 2;
    LODWORD(v67) = (v71 >> 2) | ((_DWORD)v67 << 30);
    a3[38] = HIDWORD(v67);
    a3[39] = v67;
    a3[52] = __SPAIR64__(v63, HIDWORD(v67)) >> 30;
    a3[53] = v67 >> 30;
    a3[54] = (HIDWORD(v63) >> 30) | (4 * v67);
    a3[55] = v63 >> 30;
    HIDWORD(v63) = a3[15];
    v72 = a3[12];
    v73 = (unsigned __int64)(unsigned int)a3[13] << 15;
    LODWORD(v63) = HIDWORD(v73) | (v72 << 15);
    v74 = a3[14];
    a3[12] = v63;
    HIDWORD(v67) = (v74 >> 17) | v73;
    a3[13] = HIDWORD(v67);
    LODWORD(v67) = (HIDWORD(v63) >> 17) | (v74 << 15);
    HIDWORD(v63) = (v72 >> 17) | (HIDWORD(v63) << 15);
    a3[14] = v67;
    a3[15] = HIDWORD(v63);
    LODWORD(v63) = __SPAIR64__(v63, HIDWORD(v67)) >> 2;
    a3[28] = v63;
    HIDWORD(v67) = v67 >> 2;
    a3[29] = HIDWORD(v67);
    LODWORD(v67) = (HIDWORD(v63) >> 2) | ((_DWORD)v67 << 30);
    HIDWORD(v63) = ((HIDWORD(v73) | (v72 << 15)) >> 2) | (HIDWORD(v63) << 30);
    a3[30] = v67;
    a3[31] = HIDWORD(v63);
    a3[48] = HIDWORD(v67);
    a3[49] = v67;
    a3[50] = HIDWORD(v63);
    a3[51] = v63;
    a3[56] = v67 >> 15;
    a3[57] = (HIDWORD(v63) >> 15) | ((_DWORD)v67 << 17);
    a3[58] = v63 >> 15;
    a3[59] = __SPAIR64__(v63, HIDWORD(v67)) >> 15;
    HIDWORD(v67) = *a3;
    v75 = a3[1];
    v76 = (unsigned __int64)(unsigned int)a3[2] << 13;
    LODWORD(v67) = HIDWORD(v76) | (v75 << 13);
    v77 = a3[3];
    a3[24] = v67;
    HIDWORD(v63) = (v77 >> 19) | v76;
    a3[25] = HIDWORD(v63);
    LODWORD(v63) = (HIDWORD(v67) >> 19) | (v77 << 13);
    HIDWORD(v67) = (v75 >> 19) | (HIDWORD(v67) << 13);
    a3[26] = v63;
    a3[27] = HIDWORD(v67);
    LODWORD(v67) = (HIDWORD(v63) >> 17) | ((_DWORD)v67 << 15);
    a3[32] = v67;
    HIDWORD(v63) = v63 >> 17;
    a3[33] = HIDWORD(v63);
    LODWORD(v63) = __SPAIR64__(v63, HIDWORD(v67)) >> 17;
    HIDWORD(v67) = ((HIDWORD(v76) | (v75 << 13)) >> 17) | (HIDWORD(v67) << 15);
    a3[34] = v63;
    a3[35] = HIDWORD(v67);
    v78 = v67;
    LODWORD(v67) = (HIDWORD(v63) >> 15) | ((_DWORD)v67 << 17);
    a3[44] = v67;
    HIDWORD(v63) = v63 >> 15;
    a3[45] = HIDWORD(v63);
    LODWORD(v63) = __SPAIR64__(v63, HIDWORD(v67)) >> 15;
    HIDWORD(v67) = (v78 >> 15) | (HIDWORD(v67) << 17);
    a3[46] = v63;
    a3[47] = HIDWORD(v67);
    a3[60] = v63 >> 30;
    a3[61] = __SPAIR64__(v63, HIDWORD(v67)) >> 30;
    a3[62] = v67 >> 30;
    a3[63] = (HIDWORD(v63) >> 30) | (4 * v67);
    return 4;
  }
}
