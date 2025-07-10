int __cdecl jpeg_idct_11x11(int a1, int a2, int a3, int a4, int a5)
{
  __int16 *v5; // edx
  _DWORD *v6; // esi
  int *v7; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // ebx
  int v11; // edx
  int v12; // ebx
  int v13; // esi
  int v14; // edi
  int v15; // ebp
  int v16; // edi
  int v17; // edx
  int v18; // esi
  int v19; // edi
  int v20; // ecx
  int v21; // ebx
  int v22; // ebx
  int v23; // ecx
  int v24; // ebx
  bool v25; // zf
  int result; // eax
  int *v27; // ecx
  int v28; // ebp
  int v29; // edi
  int v30; // ebx
  int v31; // ecx
  int v32; // ebx
  int v33; // esi
  int v34; // edi
  int v35; // edx
  int v36; // edi
  int v37; // ebp
  int v38; // ecx
  int v39; // esi
  int v40; // edi
  _BYTE *v41; // eax
  int v42; // edx
  int v43; // edx
  int v44; // esi
  bool v45; // cc
  int v46; // [esp+10h] [ebp-19Ch]
  int v47; // [esp+10h] [ebp-19Ch]
  int v48; // [esp+10h] [ebp-19Ch]
  int v49; // [esp+10h] [ebp-19Ch]
  int v50; // [esp+14h] [ebp-198h]
  int v51; // [esp+14h] [ebp-198h]
  int v52; // [esp+14h] [ebp-198h]
  int v53; // [esp+14h] [ebp-198h]
  int v54; // [esp+14h] [ebp-198h]
  int v55; // [esp+18h] [ebp-194h]
  int v56; // [esp+18h] [ebp-194h]
  int v57; // [esp+18h] [ebp-194h]
  int v58; // [esp+18h] [ebp-194h]
  int v59; // [esp+1Ch] [ebp-190h]
  int v60; // [esp+1Ch] [ebp-190h]
  int v61; // [esp+1Ch] [ebp-190h]
  int v62; // [esp+1Ch] [ebp-190h]
  __int16 *v63; // [esp+20h] [ebp-18Ch]
  int v64; // [esp+20h] [ebp-18Ch]
  int v65; // [esp+20h] [ebp-18Ch]
  int v66; // [esp+24h] [ebp-188h]
  int v67; // [esp+24h] [ebp-188h]
  int v68; // [esp+28h] [ebp-184h]
  int v69; // [esp+28h] [ebp-184h]
  int v70; // [esp+28h] [ebp-184h]
  int v71; // [esp+28h] [ebp-184h]
  int v72; // [esp+2Ch] [ebp-180h]
  int v73; // [esp+2Ch] [ebp-180h]
  int v74; // [esp+30h] [ebp-17Ch]
  int v75; // [esp+30h] [ebp-17Ch]
  int v76; // [esp+34h] [ebp-178h]
  int v77; // [esp+34h] [ebp-178h]
  int v78; // [esp+34h] [ebp-178h]
  int v79; // [esp+34h] [ebp-178h]
  _DWORD *v80; // [esp+38h] [ebp-174h]
  _BYTE *v81; // [esp+38h] [ebp-174h]
  int v82; // [esp+3Ch] [ebp-170h]
  int v83; // [esp+3Ch] [ebp-170h]
  int v84; // [esp+40h] [ebp-16Ch]
  int v85; // [esp+40h] [ebp-16Ch]
  int v86; // [esp+44h] [ebp-168h]
  int v87; // [esp+48h] [ebp-164h]
  _BYTE v88[16]; // [esp+5Ch] [ebp-150h] BYREF
  char v89; // [esp+6Ch] [ebp-140h] BYREF

  v5 = (__int16 *)(a3 + 64);
  v6 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 128);
  v87 = *(_DWORD *)(a1 + 292) + 128;
  v7 = (int *)&v89;
  v63 = (__int16 *)(a3 + 64);
  v80 = v6;
  v82 = 8;
  do
  {
    v8 = *v6 * *v5;
    v9 = *(v6 - 16) * *(v5 - 16);
    v10 = *(v6 - 32) * *(v5 - 32);
    v55 = v6[16] * v5[16];
    v11 = 20862 * (v8 - v55);
    v12 = (v10 << 13) + 1024;
    v46 = v9;
    v13 = v8 - v9;
    v14 = v9 + v55;
    v13 *= 3529;
    v59 = v14 - v8;
    v15 = v12 + 11116 * (v14 - v8);
    v86 = v11 + v13 + v15 - 14924 * v8;
    v16 = v15 - 9467 * v14;
    v17 = v15 + 17333 * v55 + v11;
    v18 = v15 - 12399 * v46 + v13;
    v84 = v16 - 6461 * v55;
    v19 = 15929 * v8 - 11395 * v46 + v16;
    v72 = v12 - 11585 * v59;
    v47 = *(v80 - 24) * *(v63 - 24);
    v20 = *(v80 - 8) * *(v63 - 8);
    v56 = v80[8] * v63[8];
    v60 = v80[24] * v63[24];
    v66 = 3264 * (v56 + v20 + v47 + v60);
    v50 = 7274 * (v20 + v47);
    v68 = 5492 * (v56 + v47);
    v76 = v66 + 3000 * (v47 + v60);
    v74 = v50 + v68 + v76 - 7562 * v47;
    v21 = v66 - 9527 * (v56 + v20);
    v51 = v21 + 16984 * v20 + v50;
    v69 = v21 - 9766 * v56 + v68;
    v22 = -14731 * (v20 + v60);
    v77 = v22 + 17223 * v60 + v76;
    v23 = v66 + 8203 * v56 + -12019 * v20 - 13802 * v60;
    v24 = v22 + v51;
    v7[72] = (v17 - v74) >> 11;
    *(v7 - 8) = (v17 + v74) >> 11;
    v7[64] = (v86 - v24) >> 11;
    *v7 = (v24 + v86) >> 11;
    v7[56] = (v84 - v69) >> 11;
    v7[8] = (v69 + v84) >> 11;
    v7[16] = (v77 + v18) >> 11;
    v7[48] = (v18 - v77) >> 11;
    v7[24] = (v23 + v19) >> 11;
    v7[40] = (v19 - v23) >> 11;
    v7[32] = v72 >> 11;
    v5 = v63 + 1;
    v6 = v80 + 1;
    ++v7;
    v25 = v82-- == 1;
    ++v63;
    ++v80;
  }
  while ( !v25 );
  result = 0;
  v27 = (int *)v88;
  v83 = 0;
  v81 = v88;
  do
  {
    v28 = *v27;
    v29 = *(v27 - 2);
    v30 = *(v27 - 4);
    v57 = v27[2];
    v31 = 20862 * (*v27 - v57);
    v32 = (v30 + 16) << 13;
    v48 = v29;
    v33 = v28 - v29;
    v34 = v29 + v57;
    v33 *= 3529;
    v61 = v34 - v28;
    v35 = v32 + 11116 * (v34 - v28);
    v64 = v28;
    v36 = v35 - 9467 * v34;
    v37 = v31 + v33 + v35 - 14924 * v28;
    v38 = v35 + 17333 * v57 + v31;
    v39 = v35 - 12399 * v48 + v33;
    v85 = v36 - 6461 * v57;
    v40 = 15929 * v64 - 11395 * v48 + v36;
    v73 = v32 - 11585 * v61;
    v49 = *((_DWORD *)v81 - 3);
    v41 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v65 = *((_DWORD *)v81 - 1);
    v62 = *((_DWORD *)v81 + 3);
    v58 = *((_DWORD *)v81 + 1);
    v67 = 3264 * (v58 + v62 + v49 + v65);
    v52 = 7274 * (v49 + v65);
    v70 = 5492 * (v58 + v49);
    v78 = v67 + 3000 * (v49 + v62);
    v75 = v52 + v70 + v78 - 7562 * v49;
    v42 = v67 - 9527 * (v58 + v65);
    v53 = v42 + 16984 * v65 + v52;
    v71 = v42 - 9766 * v58 + v70;
    v43 = -14731 * (v65 + v62);
    v54 = v43 + v53;
    v79 = v43 + 17223 * v62 + v78;
    *v41 = *(_BYTE *)((((v38 + v75) >> 18) & 0x3FF) + v87);
    v41[10] = *(_BYTE *)((((v38 - v75) >> 18) & 0x3FF) + v87);
    v41[1] = *(_BYTE *)((((v54 + v37) >> 18) & 0x3FF) + v87);
    v41[9] = *(_BYTE *)(v87 + (((v37 - v54) >> 18) & 0x3FF));
    v41[2] = *(_BYTE *)((((v71 + v85) >> 18) & 0x3FF) + v87);
    v41[8] = *(_BYTE *)(v87 + (((v85 - v71) >> 18) & 0x3FF));
    v41[3] = *(_BYTE *)((((v39 + v79) >> 18) & 0x3FF) + v87);
    LOBYTE(v38) = *(_BYTE *)((((v39 - v79) >> 18) & 0x3FF) + v87);
    v44 = -12019 * v65 - 13802 * v62 + v67 + 8203 * v58;
    v41[7] = v38;
    v41[4] = *(_BYTE *)((((v44 + v40) >> 18) & 0x3FF) + v87);
    v41[6] = *(_BYTE *)((((v40 - v44) >> 18) & 0x3FF) + v87);
    v41[5] = *(_BYTE *)(((v73 >> 18) & 0x3FF) + v87);
    result = v83 + 1;
    v27 = (int *)(v81 + 32);
    v45 = v83 + 1 < 11;
    v81 += 32;
    ++v83;
  }
  while ( v45 );
  return result;
}
