int __cdecl jpeg_idct_14x14(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // ecx
  __int16 *v6; // ebp
  _DWORD *v7; // ebx
  int *v8; // eax
  int v9; // esi
  int v10; // edx
  int v11; // esi
  int v12; // edi
  int v13; // edx
  int v14; // esi
  int v15; // edx
  int v16; // edx
  int v17; // ebx
  int v18; // edx
  int v19; // ebp
  int v20; // ebx
  int v21; // edx
  bool v22; // zf
  int result; // eax
  _DWORD *v24; // ebp
  int v25; // edx
  int v26; // ebx
  int v27; // esi
  int v28; // edi
  int v29; // esi
  int v30; // edx
  int v31; // ebx
  int v32; // edx
  int v33; // edi
  _BYTE *v34; // eax
  int v35; // ebx
  int v36; // edx
  int v37; // ebx
  int v38; // ebx
  bool v39; // cc
  int v40; // [esp+Ch] [ebp-208h]
  int v41; // [esp+Ch] [ebp-208h]
  int v42; // [esp+Ch] [ebp-208h]
  int v43; // [esp+Ch] [ebp-208h]
  int v44; // [esp+Ch] [ebp-208h]
  int v45; // [esp+10h] [ebp-204h]
  int v46; // [esp+10h] [ebp-204h]
  int v47; // [esp+10h] [ebp-204h]
  int v48; // [esp+10h] [ebp-204h]
  int v49; // [esp+10h] [ebp-204h]
  int v50; // [esp+10h] [ebp-204h]
  int v51; // [esp+10h] [ebp-204h]
  int v52; // [esp+14h] [ebp-200h]
  int v53; // [esp+14h] [ebp-200h]
  int v54; // [esp+14h] [ebp-200h]
  int v55; // [esp+14h] [ebp-200h]
  int v56; // [esp+14h] [ebp-200h]
  int v57; // [esp+14h] [ebp-200h]
  int v58; // [esp+18h] [ebp-1FCh]
  int v59; // [esp+18h] [ebp-1FCh]
  int v60; // [esp+18h] [ebp-1FCh]
  int v61; // [esp+1Ch] [ebp-1F8h]
  int v62; // [esp+1Ch] [ebp-1F8h]
  int v63; // [esp+1Ch] [ebp-1F8h]
  int v64; // [esp+1Ch] [ebp-1F8h]
  int v65; // [esp+20h] [ebp-1F4h]
  _BYTE *v66; // [esp+20h] [ebp-1F4h]
  int v67; // [esp+24h] [ebp-1F0h]
  int v68; // [esp+24h] [ebp-1F0h]
  int v69; // [esp+24h] [ebp-1F0h]
  int v70; // [esp+24h] [ebp-1F0h]
  int v71; // [esp+28h] [ebp-1ECh]
  int v72; // [esp+28h] [ebp-1ECh]
  int v73; // [esp+28h] [ebp-1ECh]
  int v74; // [esp+28h] [ebp-1ECh]
  int v75; // [esp+2Ch] [ebp-1E8h]
  int v76; // [esp+2Ch] [ebp-1E8h]
  int v77; // [esp+2Ch] [ebp-1E8h]
  int v78; // [esp+30h] [ebp-1E4h]
  int v79; // [esp+30h] [ebp-1E4h]
  _DWORD *v80; // [esp+34h] [ebp-1E0h]
  int v81; // [esp+38h] [ebp-1DCh]
  int v82; // [esp+3Ch] [ebp-1D8h]
  int v83; // [esp+3Ch] [ebp-1D8h]
  int v84; // [esp+40h] [ebp-1D4h]
  int v85; // [esp+40h] [ebp-1D4h]
  int v86; // [esp+44h] [ebp-1D0h]
  int v87; // [esp+44h] [ebp-1D0h]
  int v88; // [esp+48h] [ebp-1CCh]
  int v89; // [esp+48h] [ebp-1CCh]
  int v90; // [esp+4Ch] [ebp-1C8h]
  int v91; // [esp+4Ch] [ebp-1C8h]
  int v92; // [esp+50h] [ebp-1C4h]
  int v93; // [esp+50h] [ebp-1C4h]
  _BYTE v94[24]; // [esp+5Ch] [ebp-1B8h] BYREF
  char v95; // [esp+74h] [ebp-1A0h] BYREF

  v5 = *(_DWORD *)(a1 + 292) + 128;
  v6 = (__int16 *)(a3 + 32);
  v7 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 64);
  v8 = (int *)&v95;
  v81 = a3 + 32;
  v80 = v7;
  v78 = 8;
  do
  {
    v9 = v7[16] * v6[16];
    v10 = ((*(v7 - 16) * *(v6 - 16)) << 13) + 1024;
    v71 = v10 + 10438 * v9;
    v52 = v10 + 2578 * v9;
    v67 = v10 - 7223 * v9;
    v11 = *v7 * *v6;
    v12 = v10 - 11586 * v7[16] * v6[16];
    v40 = v7[32] * v6[32];
    v13 = 9058 * (v11 + v40);
    v45 = v13 + 2237 * v11;
    v61 = v13 - 14084 * v40;
    v41 = 5027 * v11 - 11295 * v40;
    v86 = v45 + v71;
    v82 = v71 - v45;
    v90 = v52 + v61;
    v88 = v52 - v61;
    v84 = v67 + v41;
    v14 = v7[8] * v6[8];
    v92 = v67 - v41;
    v15 = *(v7 - 8) * *(v6 - 8);
    v12 >>= 11;
    v65 = v7[24] * v6[24];
    v58 = v7[40] * *(__int16 *)(v81 + 80);
    v53 = 10935 * (v14 + v15);
    v68 = 9810 * (v15 + v65);
    v46 = v58 << 13;
    v72 = v53 + v68 + (v58 << 13) - 9232 * v15;
    v62 = 6164 * (v15 + v65);
    v75 = v62 - 8693 * v15;
    v16 = v15 - v14;
    v17 = 3826 * v16 - (v58 << 13);
    v18 = v58 + v16;
    v76 = v17 + v75;
    v59 = -8192 * v58 - 1297 * (v65 + v14);
    v54 = v59 - 3474 * v14 + v53;
    v19 = 11512 * (v65 - v14) + v46 - 13850 * v65 + v62;
    v47 = 4 * (v18 - v65);
    v20 = 11512 * (v65 - v14) + 5529 * v14 + v17;
    *(v8 - 8) = (v86 + v72) >> 11;
    v8[96] = (v86 - v72) >> 11;
    *v8 = (v90 + v54) >> 11;
    v21 = v59 - 19447 * v65 + v68;
    v8[88] = (v90 - v54) >> 11;
    v8[8] = (v84 + v21) >> 11;
    v8[80] = (v84 - v21) >> 11;
    v8[16] = v47 + v12;
    v8[64] = (v92 - v19) >> 11;
    v8[24] = (v92 + v19) >> 11;
    v8[56] = (v88 - v20) >> 11;
    v8[32] = (v88 + v20) >> 11;
    v8[72] = v12 - v47;
    v8[40] = (v76 + v82) >> 11;
    v8[48] = (v82 - v76) >> 11;
    v6 = (__int16 *)(v81 + 2);
    v7 = v80 + 1;
    ++v8;
    v22 = v78-- == 1;
    v81 += 2;
    ++v80;
  }
  while ( !v22 );
  result = 0;
  v24 = v94;
  v79 = 0;
  v66 = v94;
  do
  {
    v25 = (*(v24 - 2) + 16) << 13;
    v26 = v24[2];
    v27 = 7223 * v26;
    v26 *= 2578;
    v73 = v25 + 10438 * v24[2];
    v55 = v26 + v25;
    v28 = v25 - v27;
    v29 = v25 + 2 * v27 - 2 * v26 - 20876 * v24[2];
    v42 = v24[4];
    v30 = 9058 * (*v24 + v42);
    v48 = v30 + 2237 * *v24;
    v63 = v30 - 14084 * v42;
    v43 = 5027 * *v24 - 11295 * v42;
    v87 = v48 + v73;
    v83 = v73 - v48;
    v91 = v55 + v63;
    v89 = v55 - v63;
    v85 = v43 + v28;
    v31 = v24[3];
    v32 = *(v24 - 1);
    v93 = v28 - v43;
    v33 = v24[1];
    v60 = v24[5] << 13;
    v34 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v56 = 10935 * (v33 + v32);
    v69 = 9810 * (v32 + v31);
    v74 = v60 + v56 + v69 - 9232 * v32;
    v35 = 6164 * (v32 + v31);
    v36 = v32 - v33;
    v64 = v35;
    v77 = 3826 * v36 - v60 + v35 - 8693 * *(v24 - 1);
    v49 = -8192 * v24[5] - 1297 * (*((_DWORD *)v66 + 3) + v33);
    v57 = v49 - 3474 * v33 + v56;
    v70 = v49 - 19447 * *((_DWORD *)v66 + 3) + v69;
    v37 = *((_DWORD *)v66 + 3);
    v50 = 11512 * (v37 - v33);
    v44 = v50 + 5529 * v33 + 3826 * v36 - v60;
    v38 = v60 + v50 - 13850 * v37 + v64;
    v51 = v60 + ((v36 - *((_DWORD *)v66 + 3)) << 13);
    *v34 = *(_BYTE *)((((v87 + v74) >> 18) & 0x3FF) + v5);
    v34[13] = *(_BYTE *)((((v87 - v74) >> 18) & 0x3FF) + v5);
    v34[1] = *(_BYTE *)((((v91 + v57) >> 18) & 0x3FF) + v5);
    v34[12] = *(_BYTE *)((((v91 - v57) >> 18) & 0x3FF) + v5);
    v34[2] = *(_BYTE *)((((v85 + v70) >> 18) & 0x3FF) + v5);
    v34[11] = *(_BYTE *)((((v85 - v70) >> 18) & 0x3FF) + v5);
    v34[3] = *(_BYTE *)((((v29 + v51) >> 18) & 0x3FF) + v5);
    v34[10] = *(_BYTE *)((((v29 - v51) >> 18) & 0x3FF) + v5);
    v34[4] = *(_BYTE *)((((v93 + v38) >> 18) & 0x3FF) + v5);
    v34[9] = *(_BYTE *)((((v93 - v38) >> 18) & 0x3FF) + v5);
    v34[5] = *(_BYTE *)((((v89 + v44) >> 18) & 0x3FF) + v5);
    v34[8] = *(_BYTE *)((((v89 - v44) >> 18) & 0x3FF) + v5);
    v34[6] = *(_BYTE *)((((v77 + v83) >> 18) & 0x3FF) + v5);
    v34[7] = *(_BYTE *)((((v83 - v77) >> 18) & 0x3FF) + v5);
    result = v79 + 1;
    v24 = v66 + 32;
    v39 = v79 + 1 < 14;
    v66 += 32;
    ++v79;
  }
  while ( v39 );
  return result;
}
