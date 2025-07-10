int __cdecl jpeg_idct_8x4(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // ecx
  __int16 *v6; // edx
  int *v7; // eax
  int v8; // esi
  int v9; // edi
  int v10; // ebx
  int v11; // esi
  int v12; // edi
  int v13; // ebp
  int v14; // esi
  int v15; // edi
  int v16; // esi
  int v17; // ebp
  int v18; // ebx
  int v19; // edi
  int v20; // esi
  int v21; // edi
  int v22; // ebx
  int v23; // esi
  int v24; // edi
  int v25; // ebp
  int v26; // esi
  int v27; // edi
  int v28; // esi
  int v29; // ebp
  int v30; // ebx
  int v31; // edi
  int v32; // esi
  int v33; // edi
  int v34; // ebx
  int v35; // esi
  int v36; // edi
  int v37; // ebp
  int v38; // esi
  int v39; // edi
  int v40; // esi
  int v41; // ebp
  int v42; // ebx
  int v43; // edi
  int v44; // esi
  int v45; // edi
  int v46; // ebx
  int v47; // esi
  int v48; // edi
  int v49; // ebp
  int v50; // esi
  int v51; // edi
  int v52; // esi
  int result; // eax
  char *v54; // ecx
  int v55; // esi
  int v56; // ebp
  int v57; // edx
  int v58; // edi
  int v59; // ebx
  int v60; // edx
  int v61; // esi
  int v62; // edx
  int v63; // ebp
  int v64; // esi
  int v65; // edx
  int v66; // edi
  int v67; // esi
  int v68; // edx
  _BYTE *v69; // eax
  int v70; // ebx
  int v71; // edx
  int v72; // edi
  int v73; // [esp+10h] [ebp-A8h]
  int v74; // [esp+10h] [ebp-A8h]
  int v75; // [esp+10h] [ebp-A8h]
  int v76; // [esp+14h] [ebp-A4h]
  int v77; // [esp+14h] [ebp-A4h]
  int v78; // [esp+14h] [ebp-A4h]
  int v79; // [esp+14h] [ebp-A4h]
  int v80; // [esp+14h] [ebp-A4h]
  int v81; // [esp+18h] [ebp-A0h]
  int v82; // [esp+1Ch] [ebp-9Ch]
  int v83; // [esp+20h] [ebp-98h]
  int v84; // [esp+24h] [ebp-94h]
  int v85; // [esp+28h] [ebp-90h]
  int v86; // [esp+2Ch] [ebp-8Ch]
  int v87; // [esp+30h] [ebp-88h]
  int v88; // [esp+34h] [ebp-84h]
  char v89; // [esp+50h] [ebp-68h] BYREF
  char v90; // [esp+58h] [ebp-60h] BYREF

  v5 = *(_DWORD **)(a2 + 84);
  v85 = *(_DWORD *)(a1 + 292) + 128;
  v6 = (__int16 *)(a3 + 16);
  v7 = (int *)&v90;
  v73 = 2;
  do
  {
    v8 = *v5 * *(v6 - 8);
    v9 = v5[16] * v6[8];
    v10 = v9 + v8;
    v11 = v8 - v9;
    v12 = v5[8] * *v6;
    v13 = v5[24] * v6[16];
    v76 = 4 * v11;
    v14 = 4433 * (v12 + v13) + 1024;
    v15 = (v14 + 6270 * v12) >> 11;
    v16 = (v14 - 15137 * v13) >> 11;
    v10 *= 4;
    v17 = v10 + v15;
    v7[16] = v10 - v15;
    v18 = v76 + v16;
    v19 = v76 - v16;
    v20 = v5[1] * *(v6 - 7);
    v7[8] = v19;
    v21 = v5[17] * v6[9];
    *v7 = v18;
    v22 = v21 + v20;
    v23 = v20 - v21;
    v24 = v5[9] * v6[1];
    *(v7 - 8) = v17;
    v25 = v5[25] * v6[17];
    v77 = 4 * v23;
    v26 = 4433 * (v24 + v25) + 1024;
    v27 = (v26 + 6270 * v24) >> 11;
    v28 = v26 - 15137 * v25;
    v22 *= 4;
    v29 = v22 + v27;
    v28 >>= 11;
    v7[17] = v22 - v27;
    v30 = v77 + v28;
    v31 = v77 - v28;
    v32 = v5[2] * *(v6 - 6);
    v7[9] = v31;
    v33 = v5[18] * v6[10];
    v7[1] = v30;
    v34 = v33 + v32;
    v35 = v32 - v33;
    v36 = v5[10] * v6[2];
    *(v7 - 7) = v29;
    v34 *= 4;
    v37 = v5[26] * v6[18];
    v78 = 4 * v35;
    v38 = 4433 * (v36 + v37) + 1024;
    v39 = v38 + 6270 * v36;
    v40 = v38 - 15137 * v37;
    v39 >>= 11;
    v41 = v34 + v39;
    v40 >>= 11;
    v7[18] = v34 - v39;
    v42 = v78 + v40;
    v43 = v78 - v40;
    v44 = v5[3] * *(v6 - 5);
    v7[10] = v43;
    v45 = v5[19] * v6[11];
    v7[2] = v42;
    v46 = v45 + v44;
    v47 = v44 - v45;
    v48 = v5[11] * v6[3];
    *(v7 - 6) = v41;
    v49 = v5[27] * v6[19];
    v79 = 4 * v47;
    v50 = 4433 * (v48 + v49) + 1024;
    v51 = (v50 + 6270 * v48) >> 11;
    v46 *= 4;
    v52 = (v50 - 15137 * v49) >> 11;
    v7[19] = v46 - v51;
    *(v7 - 5) = v46 + v51;
    v7[3] = v79 + v52;
    v7[11] = v79 - v52;
    v6 += 4;
    v5 += 4;
    v7 += 4;
    --v73;
  }
  while ( v73 );
  result = 0;
  v83 = 0;
  v54 = &v89;
  do
  {
    v55 = *((_DWORD *)v54 - 4);
    v56 = *((_DWORD *)v54 - 2);
    v57 = 4433 * (*(_DWORD *)v54 + v55);
    v58 = v57 - 15137 * *(_DWORD *)v54;
    v59 = v57 + 6270 * v55;
    v60 = *((_DWORD *)v54 - 6) + 16;
    v61 = v60 + v56;
    v62 = v60 - v56;
    v61 <<= 13;
    v88 = v59 + v61;
    v63 = *((_DWORD *)v54 - 5);
    v87 = v61 - v59;
    v62 <<= 13;
    v64 = v62 + v58;
    v65 = v62 - v58;
    v66 = *((_DWORD *)v54 - 3);
    v86 = v64;
    v67 = *((_DWORD *)v54 - 1);
    v80 = v65;
    v68 = *((_DWORD *)v54 + 1);
    v84 = 9633 * (v66 + v68 + v67 + v63) - 16069 * (v66 + v68);
    v74 = 9633 * (v66 + v68 + v67 + v63) - 3196 * (v67 + v63);
    v69 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v82 = -7373 * (v63 + v68);
    v81 = v74 + v82 + 12299 * v63;
    v70 = -20995 * (v67 + v66);
    v71 = v84 + v82 + 2446 * v68;
    v72 = v84 + v70 + 25172 * v66;
    v75 = v74 + v70 + 16819 * v67;
    *v69 = *(_BYTE *)((((v88 + v81) >> 18) & 0x3FF) + v85);
    v69[7] = *(_BYTE *)((((v88 - v81) >> 18) & 0x3FF) + v85);
    v69[1] = *(_BYTE *)((((v86 + v72) >> 18) & 0x3FF) + v85);
    v69[6] = *(_BYTE *)((((v86 - v72) >> 18) & 0x3FF) + v85);
    v69[2] = *(_BYTE *)((((v80 + v75) >> 18) & 0x3FF) + v85);
    v69[5] = *(_BYTE *)((((v80 - v75) >> 18) & 0x3FF) + v85);
    v69[3] = *(_BYTE *)((((v87 + v71) >> 18) & 0x3FF) + v85);
    v69[4] = *(_BYTE *)((((v87 - v71) >> 18) & 0x3FF) + v85);
    result = v83 + 1;
    v54 += 32;
    ++v83;
  }
  while ( v83 < 4 );
  return result;
}
