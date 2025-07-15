int __usercall _x86_Camellia_decrypt@<eax>(
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
        _DWORD *a11)
{
  int v11; // eax
  int v12; // ebx
  int v13; // esi
  int v14; // ebx
  int v15; // edx
  int v16; // ecx
  int v17; // esi
  int v18; // edx
  int v19; // ebx
  int v20; // eax
  int v21; // esi
  int v22; // ebx
  int v23; // edx
  int v24; // ecx
  int v25; // esi
  int v26; // edx
  int v27; // ebx
  int v28; // eax
  int v29; // esi
  int v30; // ebx
  int v31; // edx
  int v32; // ecx
  int v33; // esi
  int v34; // edx
  int v35; // ebx
  int v36; // eax
  int v37; // esi
  int v38; // ebx
  int v39; // eax
  int v41; // [esp+4h] [ebp+4h]
  int v42; // [esp+4h] [ebp+4h]
  int v43; // [esp+4h] [ebp+4h]
  int v44; // [esp+8h] [ebp+8h]
  int v45; // [esp+8h] [ebp+8h]
  int v46; // [esp+8h] [ebp+8h]
  int v47; // [esp+Ch] [ebp+Ch]
  int v48; // [esp+Ch] [ebp+Ch]
  int v49; // [esp+Ch] [ebp+Ch]
  int v50; // [esp+Ch] [ebp+Ch]
  int i; // [esp+10h] [ebp+10h]
  int v52; // [esp+10h] [ebp+10h]
  int v53; // [esp+10h] [ebp+10h]
  int v54; // [esp+10h] [ebp+10h]

  v11 = *a6 ^ a1;
  v12 = a6[1] ^ a4;
  v13 = *(a6 - 2);
  v41 = v11;
  v44 = v12;
  v47 = a6[2] ^ a3;
  for ( i = a6[3] ^ a2; ; i = __ROL4__(*a6 & v47, 1) ^ v54 )
  {
    v14 = *(a6 - 1) ^ v12;
    v15 = *(_DWORD *)(a5 + 8 * (unsigned __int8)((v13 ^ (unsigned int)v11) >> 16) + 2048)
        ^ *(_DWORD *)(a5 + 8 * ((v13 ^ (unsigned int)v11) >> 24))
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)(v13 ^ v11) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)((unsigned __int16)(v13 ^ v11) >> 8) + 2052);
    v16 = *(_DWORD *)(a5 + 8 * BYTE2(v14) + 2052)
        ^ *(_DWORD *)(a5 + 8 * HIBYTE(v14) + 2048)
        ^ v15
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v14) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v14);
    v17 = *(a6 - 4);
    v52 = v16 ^ i ^ __ROR4__(v15, 8);
    v48 = v47 ^ v16;
    v18 = *(a6 - 3) ^ v52;
    v19 = *(_DWORD *)(a5 + 8 * (unsigned __int8)((v17 ^ (unsigned int)v48) >> 16) + 2048)
        ^ *(_DWORD *)(a5 + 8 * ((v17 ^ (unsigned int)v48) >> 24))
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)(v17 ^ v48) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)((unsigned __int16)(v17 ^ v48) >> 8) + 2052);
    v20 = *(_DWORD *)(a5 + 8 * BYTE2(v18) + 2052)
        ^ *(_DWORD *)(a5 + 8 * HIBYTE(v18) + 2048)
        ^ v19
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v18) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v18);
    v21 = *(a6 - 6);
    v45 = v20 ^ v44 ^ __ROR4__(v19, 8);
    v42 = v41 ^ v20;
    v22 = *(a6 - 5) ^ v45;
    v23 = *(_DWORD *)(a5 + 8 * (unsigned __int8)((v21 ^ (unsigned int)v42) >> 16) + 2048)
        ^ *(_DWORD *)(a5 + 8 * ((v21 ^ (unsigned int)v42) >> 24))
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)(v21 ^ v42) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)((unsigned __int16)(v21 ^ v42) >> 8) + 2052);
    v24 = *(_DWORD *)(a5 + 8 * BYTE2(v22) + 2052)
        ^ *(_DWORD *)(a5 + 8 * HIBYTE(v22) + 2048)
        ^ v23
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v22) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v22);
    v25 = *(a6 - 8);
    v53 = v24 ^ v52 ^ __ROR4__(v23, 8);
    v49 = v48 ^ v24;
    v26 = *(a6 - 7) ^ v53;
    v27 = *(_DWORD *)(a5 + 8 * (unsigned __int8)((v25 ^ (unsigned int)v49) >> 16) + 2048)
        ^ *(_DWORD *)(a5 + 8 * ((v25 ^ (unsigned int)v49) >> 24))
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)(v25 ^ v49) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)((unsigned __int16)(v25 ^ v49) >> 8) + 2052);
    v28 = *(_DWORD *)(a5 + 8 * BYTE2(v26) + 2052)
        ^ *(_DWORD *)(a5 + 8 * HIBYTE(v26) + 2048)
        ^ v27
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v26) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v26);
    v29 = *(a6 - 10);
    v46 = v28 ^ v45 ^ __ROR4__(v27, 8);
    v43 = v42 ^ v28;
    v30 = *(a6 - 9) ^ v46;
    v31 = *(_DWORD *)(a5 + 8 * (unsigned __int8)((v29 ^ (unsigned int)v43) >> 16) + 2048)
        ^ *(_DWORD *)(a5 + 8 * ((v29 ^ (unsigned int)v43) >> 24))
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)(v29 ^ v43) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)((unsigned __int16)(v29 ^ v43) >> 8) + 2052);
    v32 = *(_DWORD *)(a5 + 8 * BYTE2(v30) + 2052)
        ^ *(_DWORD *)(a5 + 8 * HIBYTE(v30) + 2048)
        ^ v31
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v30) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v30);
    v33 = *(a6 - 12);
    v54 = v32 ^ v53 ^ __ROR4__(v31, 8);
    v50 = v49 ^ v32;
    v34 = *(a6 - 11) ^ v54;
    v35 = *(_DWORD *)(a5 + 8 * (unsigned __int8)((v33 ^ (unsigned int)v50) >> 16) + 2048)
        ^ *(_DWORD *)(a5 + 8 * ((v33 ^ (unsigned int)v50) >> 24))
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)(v33 ^ v50) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)((unsigned __int16)(v33 ^ v50) >> 8) + 2052);
    v36 = *(_DWORD *)(a5 + 8 * BYTE2(v34) + 2052)
        ^ *(_DWORD *)(a5 + 8 * HIBYTE(v34) + 2048)
        ^ v35
        ^ *(_DWORD *)(a5 + 8 * BYTE1(v34) + 4)
        ^ *(_DWORD *)(a5 + 8 * (unsigned __int8)v34);
    v37 = *(a6 - 14);
    v38 = v36 ^ v46 ^ __ROR4__(v35, 8);
    v39 = v43 ^ v36;
    a6 -= 16;
    if ( a6 == a11 )
      break;
    v12 = __ROL4__(v39 & v37, 1) ^ v38;
    v44 = v12;
    v47 = v50 ^ (a6[1] | v54);
    v11 = (v12 | a6[3]) ^ v39;
    v41 = v11;
    v13 = *(a6 - 2);
  }
  return *a6 ^ v50;
}
