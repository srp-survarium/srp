int __cdecl jpeg_idct_16x8(int a1, int a2, __int16 *a3, int a4, int a5)
{
  _DWORD *v5; // ebx
  __int16 *v6; // edi
  int v7; // ecx
  int *v8; // eax
  int v9; // edx
  int v10; // edx
  int v11; // esi
  int v12; // ebp
  int v13; // esi
  int v14; // edx
  int v15; // ebp
  int v16; // edx
  int v17; // esi
  int v18; // edx
  int v19; // edi
  int v20; // ebp
  int v21; // edx
  int v22; // ebx
  int v23; // edi
  int v24; // esi
  int v25; // ebp
  int result; // eax
  _DWORD *v27; // ebp
  int v28; // edi
  int v29; // esi
  int v30; // edx
  int v31; // ebx
  int v32; // esi
  int v33; // edi
  int v34; // edx
  int v35; // edi
  int v36; // ebx
  int v37; // edx
  int v38; // edi
  int v39; // esi
  int v40; // edx
  int v41; // edi
  int v42; // esi
  _BYTE *v43; // eax
  _BYTE *v44; // ebp
  int v45; // edi
  int v46; // edi
  int v47; // edx
  int v48; // ebx
  int v49; // edx
  int v50; // esi
  int v51; // edx
  bool v52; // cc
  _DWORD *v53; // [esp+10h] [ebp-150h]
  int v54; // [esp+10h] [ebp-150h]
  int v55; // [esp+10h] [ebp-150h]
  int v56; // [esp+10h] [ebp-150h]
  int v57; // [esp+14h] [ebp-14Ch]
  int v58; // [esp+14h] [ebp-14Ch]
  int v59; // [esp+14h] [ebp-14Ch]
  int v60; // [esp+14h] [ebp-14Ch]
  int v61; // [esp+14h] [ebp-14Ch]
  int v62; // [esp+18h] [ebp-148h]
  _BYTE *v63; // [esp+18h] [ebp-148h]
  int v64; // [esp+18h] [ebp-148h]
  int v65; // [esp+1Ch] [ebp-144h]
  int v66; // [esp+1Ch] [ebp-144h]
  int v67; // [esp+1Ch] [ebp-144h]
  int v68; // [esp+1Ch] [ebp-144h]
  int v69; // [esp+1Ch] [ebp-144h]
  int v70; // [esp+20h] [ebp-140h]
  int v71; // [esp+20h] [ebp-140h]
  int v72; // [esp+20h] [ebp-140h]
  int v73; // [esp+20h] [ebp-140h]
  int v74; // [esp+24h] [ebp-13Ch]
  __int16 *v75; // [esp+28h] [ebp-138h]
  int v76; // [esp+28h] [ebp-138h]
  int v77; // [esp+28h] [ebp-138h]
  int v78; // [esp+2Ch] [ebp-134h]
  int v79; // [esp+2Ch] [ebp-134h]
  int v80; // [esp+2Ch] [ebp-134h]
  int v81; // [esp+2Ch] [ebp-134h]
  __int16 v82; // [esp+30h] [ebp-130h]
  int v83; // [esp+30h] [ebp-130h]
  int v84; // [esp+30h] [ebp-130h]
  int v85; // [esp+34h] [ebp-12Ch]
  int v86; // [esp+34h] [ebp-12Ch]
  int v87; // [esp+38h] [ebp-128h]
  int v88; // [esp+38h] [ebp-128h]
  int v89; // [esp+38h] [ebp-128h]
  int i; // [esp+3Ch] [ebp-124h]
  int v91; // [esp+3Ch] [ebp-124h]
  int v92; // [esp+40h] [ebp-120h]
  int v93; // [esp+44h] [ebp-11Ch]
  int v94; // [esp+48h] [ebp-118h]
  int v95; // [esp+4Ch] [ebp-114h]
  int v96; // [esp+50h] [ebp-110h]
  int v97; // [esp+54h] [ebp-10Ch]
  int v98; // [esp+58h] [ebp-108h]
  int v99; // [esp+5Ch] [ebp-104h]
  char v100; // [esp+60h] [ebp-100h] BYREF
  _BYTE v101[248]; // [esp+68h] [ebp-F8h] BYREF

  v5 = *(_DWORD **)(a2 + 84);
  v6 = a3;
  v7 = *(_DWORD *)(a1 + 292) + 128;
  v75 = a3;
  v53 = v5;
  v8 = (int *)&v100;
  for ( i = 8; i > 0; --i )
  {
    v82 = v6[8];
    if ( v82 || v6[16] || v6[24] || v6[32] || v6[40] || v6[48] || v6[56] )
    {
      v10 = v5[16] * v6[16];
      v11 = v5[48] * v6[48];
      v12 = 4433 * (v11 + v10);
      v70 = v12 + 6270 * v10;
      v57 = v12 - 15137 * v11;
      v13 = (v5[32] * v6[32]) << 13;
      v14 = ((*v5 * *v6) << 13) + 1024;
      v15 = v13 + v14;
      v16 = v14 - v13;
      v78 = v15 + v70;
      v87 = v15 - v70;
      v85 = v16 + v57;
      v17 = v5[40] * v6[40];
      v65 = v16 - v57;
      v18 = v5[56] * v6[56];
      v19 = v5[24] * v6[24];
      v58 = v5[8] * v82;
      v83 = 9633 * (v18 + v19 + v17 + v58) - 16069 * (v18 + v19);
      v62 = 9633 * (v18 + v19 + v17 + v58) - 3196 * (v17 + v58);
      v20 = -7373 * (v18 + v58);
      v21 = v83 + v20 + 2446 * v18;
      v59 = v62 + v20 + 12299 * v58;
      v22 = -20995 * (v17 + v19);
      v23 = v83 + v22 + 25172 * v19;
      v24 = v62 + v22 + 16819 * v17;
      *v8 = (v78 + v59) >> 11;
      v8[56] = (v78 - v59) >> 11;
      v25 = v85 + v23;
      v8[48] = (v85 - v23) >> 11;
      v8[40] = (v65 - v24) >> 11;
      v8[16] = (v65 + v24) >> 11;
      v5 = v53;
      v8[24] = (v87 + v21) >> 11;
      v6 = v75;
      v8[8] = v25 >> 11;
      v8[32] = (v87 - v21) >> 11;
    }
    else
    {
      v9 = 4 * *v5 * *v6;
      *v8 = v9;
      v8[8] = v9;
      v8[16] = v9;
      v8[24] = v9;
      v8[32] = v9;
      v8[40] = v9;
      v8[48] = v9;
      v8[56] = v9;
    }
    ++v6;
    ++v5;
    ++v8;
    v53 = v5;
    v75 = v6;
  }
  result = 0;
  v27 = v101;
  v91 = 0;
  v63 = v101;
  do
  {
    v28 = v27[2];
    v29 = 4433 * v28;
    v28 *= 10703;
    v30 = (*(v27 - 2) + 16) << 13;
    v31 = v29;
    v79 = v28 + v30;
    v32 = v30 - v28;
    v84 = v27[4];
    v66 = v30 + v31;
    v88 = v30 - v31;
    v33 = 11363 * (*v27 - v84);
    v34 = 2260 * (*v27 - v84);
    v76 = v33 + 20995 * v84;
    v35 = v33 - 4926 * *v27;
    v99 = v79 + v76;
    v98 = v79 - v76;
    v97 = v66 + v34 + 7373 * *v27;
    v96 = v66 - (v34 + 7373 * *v27);
    v94 = v88 - v35;
    v36 = v27[3];
    v95 = v88 + v35;
    v37 = v34 - 4176 * v84;
    v38 = v32 + v37;
    v39 = v32 - v37;
    v40 = v27[1];
    v92 = v38;
    v41 = *(v27 - 1);
    v93 = v39;
    v42 = v27[5];
    v54 = 11086 * (v41 + v40);
    v43 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v71 = 10217 * (v41 + v36);
    v60 = 8956 * (v42 + v41);
    v80 = 7350 * (v41 - v42);
    v67 = 3363 * (v41 - v40);
    v86 = 5461 * (v41 + v36);
    v44 = v63;
    v77 = v71 + v60 + v54 - 18730 * v41;
    v64 = *((_DWORD *)v63 + 3);
    v89 = v80 + v86 + v67 - 15038 * v41;
    v45 = 1136 * (v40 + v64);
    v55 = v45 + 589 * v40 + v54;
    v72 = v45 - 9222 * v64 + v71;
    v74 = 11529 * (v64 - v40);
    v68 = v74 + 16154 * v40 + v67;
    v46 = v42 + v40;
    v47 = -10217 * (v42 + v40);
    v69 = v47 + v68;
    v46 *= -5461;
    v56 = v46 + v55;
    v81 = v47 + 25733 * v42 + v80;
    v48 = 8728 * v42;
    v49 = -11086 * (v42 + v64);
    v73 = v49 + v72;
    v50 = 3363 * (v42 - v64);
    v61 = v49 + v46 + v48 + v60;
    v51 = v50 + v74 - 6278 * v64 + v86;
    *v43 = *(_BYTE *)((((v99 + v77) >> 18) & 0x3FF) + v7);
    v43[15] = *(_BYTE *)((((v99 - v77) >> 18) & 0x3FF) + v7);
    v43[1] = *(_BYTE *)((((v97 + v56) >> 18) & 0x3FF) + v7);
    v43[14] = *(_BYTE *)((((v97 - v56) >> 18) & 0x3FF) + v7);
    v43[2] = *(_BYTE *)((((v95 + v73) >> 18) & 0x3FF) + v7);
    v43[13] = *(_BYTE *)((((v95 - v73) >> 18) & 0x3FF) + v7);
    v43[3] = *(_BYTE *)((((v92 + v61) >> 18) & 0x3FF) + v7);
    v43[12] = *(_BYTE *)((((v92 - v61) >> 18) & 0x3FF) + v7);
    v43[4] = *(_BYTE *)((((v93 + v50 + v81) >> 18) & 0x3FF) + v7);
    v43[11] = *(_BYTE *)((((v93 - (v50 + v81)) >> 18) & 0x3FF) + v7);
    v43[5] = *(_BYTE *)((((v94 + v51) >> 18) & 0x3FF) + v7);
    v43[10] = *(_BYTE *)((((v94 - v51) >> 18) & 0x3FF) + v7);
    v43[6] = *(_BYTE *)((((v96 + v69) >> 18) & 0x3FF) + v7);
    v43[9] = *(_BYTE *)((((v96 - v69) >> 18) & 0x3FF) + v7);
    v43[7] = *(_BYTE *)((((v98 + v89) >> 18) & 0x3FF) + v7);
    v43[8] = *(_BYTE *)((((v98 - v89) >> 18) & 0x3FF) + v7);
    result = v91 + 1;
    v27 = v44 + 32;
    v52 = v91 + 1 < 8;
    v63 = v27;
    ++v91;
  }
  while ( v52 );
  return result;
}
