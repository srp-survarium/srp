int __cdecl jpeg_idct_12x12(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // ebp
  int v6; // ecx
  int *v7; // eax
  __int16 *v8; // ebx
  int v9; // esi
  int v10; // edx
  int v11; // edi
  int v12; // esi
  int v13; // edx
  int v14; // edi
  int v15; // esi
  int v16; // ebp
  int v17; // edx
  int v18; // edi
  int v19; // ebp
  int v20; // esi
  int v21; // ebp
  int v22; // edx
  int v23; // esi
  int v24; // edx
  bool v25; // zf
  int result; // eax
  char *v27; // edi
  int v28; // esi
  int v29; // edx
  int v30; // ebx
  _BYTE *v31; // eax
  int v32; // esi
  int v33; // ebx
  int v34; // esi
  int v35; // ebp
  int v36; // ebx
  int v37; // ebp
  int v38; // edx
  int v39; // ebp
  int v40; // edx
  int v41; // ebx
  int v42; // esi
  int v43; // edx
  int v44; // ebp
  int v45; // esi
  int v46; // [esp+10h] [ebp-1C0h]
  int v47; // [esp+10h] [ebp-1C0h]
  int v48; // [esp+10h] [ebp-1C0h]
  int v49; // [esp+10h] [ebp-1C0h]
  int v50; // [esp+10h] [ebp-1C0h]
  int v51; // [esp+10h] [ebp-1C0h]
  int v52; // [esp+14h] [ebp-1BCh]
  int v53; // [esp+14h] [ebp-1BCh]
  int v54; // [esp+14h] [ebp-1BCh]
  int v55; // [esp+14h] [ebp-1BCh]
  int v56; // [esp+18h] [ebp-1B8h]
  int v57; // [esp+18h] [ebp-1B8h]
  int v58; // [esp+18h] [ebp-1B8h]
  int v59; // [esp+18h] [ebp-1B8h]
  int v60; // [esp+1Ch] [ebp-1B4h]
  int v61; // [esp+1Ch] [ebp-1B4h]
  int v62; // [esp+20h] [ebp-1B0h]
  int v63; // [esp+20h] [ebp-1B0h]
  int v64; // [esp+20h] [ebp-1B0h]
  int v65; // [esp+24h] [ebp-1ACh]
  int v66; // [esp+28h] [ebp-1A8h]
  int v67; // [esp+2Ch] [ebp-1A4h]
  int v68; // [esp+30h] [ebp-1A0h]
  int v69; // [esp+30h] [ebp-1A0h]
  int v70; // [esp+34h] [ebp-19Ch]
  int v71; // [esp+34h] [ebp-19Ch]
  int v72; // [esp+38h] [ebp-198h]
  int v73; // [esp+38h] [ebp-198h]
  int v74; // [esp+3Ch] [ebp-194h]
  int v75; // [esp+3Ch] [ebp-194h]
  int v76; // [esp+40h] [ebp-190h]
  int v77; // [esp+40h] [ebp-190h]
  int v78; // [esp+44h] [ebp-18Ch]
  int v79; // [esp+44h] [ebp-18Ch]
  int v80; // [esp+48h] [ebp-188h]
  int v81; // [esp+48h] [ebp-188h]
  _DWORD *v82; // [esp+4Ch] [ebp-184h]
  char v83; // [esp+58h] [ebp-178h] BYREF
  char v84; // [esp+70h] [ebp-160h] BYREF

  v5 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 64);
  v6 = *(_DWORD *)(a1 + 292) + 128;
  v7 = (int *)&v84;
  v8 = (__int16 *)(a3 + 32);
  v82 = v5;
  v68 = 8;
  do
  {
    v9 = 10033 * v5[16] * v8[16];
    v10 = ((*(v5 - 16) * *(v8 - 16)) << 13) + 1024;
    v52 = v9 + v10;
    v60 = v10 - v9;
    v11 = *v5 * *v8;
    v12 = (v5[32] * v8[32]) << 13;
    v46 = (v11 << 13) - v12;
    v78 = v10 + v46;
    v80 = v10 - v46;
    v70 = v52 + v12 + 11190 * v11;
    v72 = v52 - (v12 + 11190 * v11);
    v13 = 11190 * v11 - v12 - (v11 << 13);
    v65 = v5[24] * v8[24];
    v74 = v13 + v60;
    v14 = v5[8] * v8[8];
    v76 = v60 - v13;
    v15 = *(v5 - 8) * *(v8 - 8);
    v61 = 10703 * v14;
    v56 = -4433 * v14;
    v67 = v5[40] * v8[40];
    v62 = 7053 * (v67 + v15 + v65);
    v16 = v62 + 2139 * (v15 + v65);
    v53 = 10703 * v14 + v16 + 2295 * v15;
    v17 = -4433 * v14 + -8565 * (v65 + v67) - 12112 * v65;
    v18 = v14 - v65;
    v47 = v17 + v16;
    v19 = -5540 * v15;
    v20 = v15 - v67;
    ++v8;
    v21 = v56 + v19 - 16244 * v67 + v62;
    v22 = 4433 * (v18 + v20);
    v23 = v22 + 6270 * v20;
    v57 = v22 - 15137 * v18;
    v7[80] = (v70 - v53) >> 11;
    *(v7 - 8) = (v70 + v53) >> 11;
    *v7 = (v78 + v23) >> 11;
    v7[72] = (v78 - v23) >> 11;
    v24 = v62 + 12998 * v67 - v61 - 8565 * (v65 + v67);
    v7[64] = (v74 - v47) >> 11;
    v7[8] = (v74 + v47) >> 11;
    v7[56] = (v76 - v24) >> 11;
    v7[16] = (v24 + v76) >> 11;
    v7[48] = (v80 - v57) >> 11;
    v7[24] = (v57 + v80) >> 11;
    v7[32] = (v72 + v21) >> 11;
    v7[40] = (v72 - v21) >> 11;
    v5 = v82 + 1;
    ++v7;
    v25 = v68-- == 1;
    ++v82;
  }
  while ( !v25 );
  result = 0;
  v69 = 0;
  v27 = &v83;
  do
  {
    v28 = 10033 * *((_DWORD *)v27 + 2);
    v29 = (*((_DWORD *)v27 - 2) + 16) << 13;
    v54 = v28 + v29;
    v30 = v29 - v28;
    v63 = *((_DWORD *)v27 + 4) << 13;
    v31 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v48 = (*(_DWORD *)v27 << 13) - v63;
    v79 = v29 + v48;
    v81 = v29 - v48;
    v49 = v63 + 11190 * *(_DWORD *)v27;
    v32 = 11190 * *(_DWORD *)v27 - v63 - (*(_DWORD *)v27 << 13);
    v71 = v54 + v49;
    v73 = v54 - v49;
    v75 = v32 + v30;
    v33 = v30 - v32;
    v34 = *((_DWORD *)v27 - 1);
    v35 = *((_DWORD *)v27 + 3);
    v77 = v33;
    v36 = *((_DWORD *)v27 + 1);
    v58 = -4433 * v36;
    v64 = 7053 * (*((_DWORD *)v27 + 5) + v34 + v35);
    v37 = v64 + 2139 * (v34 + v35);
    v38 = 10703 * v36 + v37 + 2295 * v34;
    v50 = v37;
    v39 = *((_DWORD *)v27 + 3);
    v55 = v38;
    v40 = v39 + *((_DWORD *)v27 + 5);
    v51 = -4433 * v36 + -8565 * v40 - 12112 * v39 + v50;
    v66 = v64 + 12998 * *((_DWORD *)v27 + 5) - 10703 * v36 - 8565 * v40;
    v41 = v36 - v39;
    v42 = v34 - *((_DWORD *)v27 + 5);
    v43 = v58 + -5540 * *((_DWORD *)v27 - 1) - 16244 * *((_DWORD *)v27 + 5) + v64;
    v44 = 4433 * (v41 + v42);
    v45 = v44 + 6270 * v42;
    v59 = v44 - 15137 * v41;
    *v31 = *(_BYTE *)((((v71 + v55) >> 18) & 0x3FF) + v6);
    v31[11] = *(_BYTE *)(v6 + (((v71 - v55) >> 18) & 0x3FF));
    v31[1] = *(_BYTE *)((((v45 + v79) >> 18) & 0x3FF) + v6);
    v31[10] = *(_BYTE *)(v6 + (((v79 - v45) >> 18) & 0x3FF));
    v31[2] = *(_BYTE *)((((v75 + v51) >> 18) & 0x3FF) + v6);
    v31[9] = *(_BYTE *)((((v75 - v51) >> 18) & 0x3FF) + v6);
    v31[3] = *(_BYTE *)((((v77 + v66) >> 18) & 0x3FF) + v6);
    v31[8] = *(_BYTE *)((((v77 - v66) >> 18) & 0x3FF) + v6);
    v31[4] = *(_BYTE *)((((v81 + v59) >> 18) & 0x3FF) + v6);
    v31[7] = *(_BYTE *)((((v81 - v59) >> 18) & 0x3FF) + v6);
    v31[5] = *(_BYTE *)((((v43 + v73) >> 18) & 0x3FF) + v6);
    v31[6] = *(_BYTE *)((((v73 - v43) >> 18) & 0x3FF) + v6);
    result = v69 + 1;
    v27 += 32;
    ++v69;
  }
  while ( v69 < 12 );
  return result;
}
