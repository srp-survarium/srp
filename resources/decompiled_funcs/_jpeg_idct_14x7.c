int __cdecl jpeg_idct_14x7(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // edx
  int v6; // ecx
  __int16 *v7; // ebx
  int v8; // esi
  int v9; // edi
  int v10; // eax
  int v11; // edx
  int v12; // esi
  int v13; // eax
  int v14; // edx
  int v15; // ebp
  int v16; // eax
  int v17; // esi
  int v18; // edi
  int v19; // ebp
  int v20; // ebx
  int v21; // ebp
  int v22; // ebx
  bool v23; // zf
  int result; // eax
  _DWORD *v25; // ebp
  int v26; // edx
  int v27; // ebx
  int v28; // esi
  int v29; // edi
  int v30; // esi
  int v31; // edx
  int v32; // edx
  _BYTE *v33; // eax
  int v34; // edi
  int v35; // ebp
  int v36; // edx
  int v37; // ebx
  int v38; // ebx
  bool v39; // cc
  int v40; // [esp+10h] [ebp-124h]
  int v41; // [esp+10h] [ebp-124h]
  int v42; // [esp+10h] [ebp-124h]
  int v43; // [esp+10h] [ebp-124h]
  int v44; // [esp+10h] [ebp-124h]
  int v45; // [esp+14h] [ebp-120h]
  int v46; // [esp+14h] [ebp-120h]
  int v47; // [esp+14h] [ebp-120h]
  int v48; // [esp+14h] [ebp-120h]
  int v49; // [esp+18h] [ebp-11Ch]
  int v50; // [esp+18h] [ebp-11Ch]
  int v51; // [esp+18h] [ebp-11Ch]
  int v52; // [esp+1Ch] [ebp-118h]
  int v53; // [esp+1Ch] [ebp-118h]
  int v54; // [esp+1Ch] [ebp-118h]
  int v55; // [esp+1Ch] [ebp-118h]
  int v56; // [esp+1Ch] [ebp-118h]
  int *v57; // [esp+20h] [ebp-114h]
  int v58; // [esp+20h] [ebp-114h]
  int v59; // [esp+20h] [ebp-114h]
  int v60; // [esp+24h] [ebp-110h]
  _BYTE *v61; // [esp+24h] [ebp-110h]
  int v62; // [esp+28h] [ebp-10Ch]
  int v63; // [esp+28h] [ebp-10Ch]
  int v64; // [esp+28h] [ebp-10Ch]
  _DWORD *v65; // [esp+2Ch] [ebp-108h]
  int v66; // [esp+2Ch] [ebp-108h]
  int v67; // [esp+30h] [ebp-104h]
  int v68; // [esp+30h] [ebp-104h]
  int v69; // [esp+34h] [ebp-100h]
  int v70; // [esp+34h] [ebp-100h]
  int v71; // [esp+38h] [ebp-FCh]
  int v72; // [esp+3Ch] [ebp-F8h]
  int v73; // [esp+40h] [ebp-F4h]
  int v74; // [esp+44h] [ebp-F0h]
  int v75; // [esp+4Ch] [ebp-E8h]
  int v76; // [esp+50h] [ebp-E4h]
  _BYTE v77[24]; // [esp+5Ch] [ebp-D8h] BYREF
  char v78; // [esp+74h] [ebp-C0h] BYREF

  v5 = *(_DWORD **)(a2 + 84);
  v6 = *(_DWORD *)(a1 + 292) + 128;
  v7 = (__int16 *)(a3 + 64);
  v65 = v5;
  v60 = a3 + 64;
  v57 = (int *)&v78;
  v52 = 8;
  do
  {
    v8 = v5[16] * *(v7 - 16);
    v9 = v5[32] * *v7;
    v10 = *v5 * *(v7 - 32);
    v67 = v5[48] * v7[16];
    v11 = 7223 * (v9 - v67);
    v45 = v8;
    v12 = 2578 * (v8 - v9);
    v13 = (v10 << 13) + 1024;
    v69 = v13 + v11 + v12 - 15083 * v9;
    v14 = v13 + 10438 * (v45 + v67) - 637 * v67 + v11;
    v15 = v13 + 10438 * (v45 + v67) - 20239 * v45;
    v16 = 11585 * (v9 - (v45 + v67)) + v13;
    v17 = v15 + v12;
    v40 = v65[24] * *(__int16 *)(v60 - 16);
    v18 = v65[40] * *(__int16 *)(v60 + 16);
    v46 = v65[8] * *(__int16 *)(v60 - 48);
    v19 = 7663 * (v46 + v40);
    v20 = 1395 * (v46 - v40);
    v62 = v19 - v20;
    v21 = -11295 * (v18 + v40) + v20 + v19;
    v22 = 5027 * (v18 + v46);
    v41 = v22 + 15326 * v18 - 11295 * (v18 + v40);
    *(v57 - 8) = (v14 + v22 + v62) >> 11;
    v57[40] = (v14 - (v22 + v62)) >> 11;
    v57[32] = (v69 - v21) >> 11;
    v57[8] = (v41 + v17) >> 11;
    *v57 = (v21 + v69) >> 11;
    v57[24] = (v17 - v41) >> 11;
    v57[16] = v16 >> 11;
    v7 = (__int16 *)(v60 + 2);
    v5 = v65 + 1;
    v23 = v52-- == 1;
    v60 += 2;
    ++v65;
    ++v57;
  }
  while ( !v23 );
  result = 0;
  v25 = v77;
  v71 = 0;
  v61 = v77;
  do
  {
    v26 = (*(v25 - 2) + 16) << 13;
    v27 = v25[2];
    v28 = 7223 * v27;
    v27 *= 2578;
    v63 = v26 + 10438 * v25[2];
    v49 = v27 + v26;
    v29 = v26 - v28;
    v30 = v26 + 2 * v28 - 2 * v27 - 20876 * v25[2];
    v42 = v25[4];
    v31 = 9058 * (*v25 + v42);
    v53 = v31 + 2237 * *v25;
    v58 = v31 - 14084 * v42;
    v47 = 5027 * *v25 - 11295 * v42;
    v76 = v53 + v63;
    v75 = v63 - v53;
    v70 = v49 + v58;
    v74 = v49 - v58;
    v72 = v47 + v29;
    v32 = *(v25 - 1);
    v59 = v32 + v25[3];
    v33 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v73 = v29 - v47;
    v34 = v25[1];
    v50 = 10935 * (v34 + v32);
    v43 = 9810 * v59;
    v66 = v25[5] << 13;
    v35 = 8693 * v32;
    v64 = v50 + 9810 * v59 + v66 - 9232 * v32;
    v36 = v32 - v34;
    v59 *= 6164;
    v68 = 3826 * v36 - v66 + v59 - v35;
    v54 = -v66 - 1297 * (*((_DWORD *)v61 + 3) + v34);
    v51 = v54 - 3474 * v34 + v50;
    v44 = v54 - 19447 * *((_DWORD *)v61 + 3) + v43;
    v37 = *((_DWORD *)v61 + 3);
    v55 = 11512 * (v37 - v34);
    v48 = v55 + 5529 * v34 + 3826 * v36 - v66;
    v38 = v66 + v55 - 13850 * v37 + v59;
    v56 = v66 + ((v36 - *((_DWORD *)v61 + 3)) << 13);
    *v33 = *(_BYTE *)((((v76 + v64) >> 18) & 0x3FF) + v6);
    v33[13] = *(_BYTE *)((((v76 - v64) >> 18) & 0x3FF) + v6);
    v33[1] = *(_BYTE *)((((v70 + v51) >> 18) & 0x3FF) + v6);
    v33[12] = *(_BYTE *)((((v70 - v51) >> 18) & 0x3FF) + v6);
    v33[2] = *(_BYTE *)((((v72 + v44) >> 18) & 0x3FF) + v6);
    v33[11] = *(_BYTE *)((((v72 - v44) >> 18) & 0x3FF) + v6);
    v33[3] = *(_BYTE *)((((v30 + v56) >> 18) & 0x3FF) + v6);
    v33[10] = *(_BYTE *)((((v30 - v56) >> 18) & 0x3FF) + v6);
    v33[4] = *(_BYTE *)((((v73 + v38) >> 18) & 0x3FF) + v6);
    v33[9] = *(_BYTE *)((((v73 - v38) >> 18) & 0x3FF) + v6);
    v33[5] = *(_BYTE *)((((v74 + v48) >> 18) & 0x3FF) + v6);
    v33[8] = *(_BYTE *)((((v74 - v48) >> 18) & 0x3FF) + v6);
    v33[6] = *(_BYTE *)((((v68 + v75) >> 18) & 0x3FF) + v6);
    v33[7] = *(_BYTE *)((((v75 - v68) >> 18) & 0x3FF) + v6);
    result = v71 + 1;
    v25 = v61 + 32;
    v39 = v71 + 1 < 7;
    v61 += 32;
    ++v71;
  }
  while ( v39 );
  return result;
}
