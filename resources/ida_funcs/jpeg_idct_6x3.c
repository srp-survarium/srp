char __cdecl jpeg_idct_6x3(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // edx
  int v6; // eax
  __int16 *v7; // esi
  int *v8; // ecx
  int v9; // edi
  int v10; // ebp
  int v11; // ebx
  int v12; // edi
  int v13; // ebp
  int v14; // ebx
  int v15; // edi
  int v16; // ebp
  int v17; // edi
  int v18; // ebx
  int v19; // edi
  int v20; // ebp
  int v21; // ebx
  int v22; // edi
  int v23; // ebp
  int v24; // edi
  int v25; // ebx
  int v26; // edx
  int v27; // ebp
  int v28; // esi
  int v29; // edi
  int v30; // ebp
  _BYTE *v31; // ecx
  int v32; // edx
  int v33; // esi
  _BYTE *v34; // ecx
  int v35; // edx
  int v36; // ebp
  int v37; // esi
  int v38; // edi
  int v39; // ebp
  int v40; // edx
  int v41; // esi
  int v42; // edx
  int v43; // ebp
  int v44; // esi
  int v45; // edi
  int v46; // ebp
  _BYTE *v47; // ecx
  int v48; // edx
  char result; // al
  int v50; // [esp+10h] [ebp-48h]
  int v51; // [esp+14h] [ebp-44h]
  int v52; // [esp+18h] [ebp-40h]
  int v53; // [esp+1Ch] [ebp-3Ch]
  int v54; // [esp+20h] [ebp-38h]
  int v55; // [esp+24h] [ebp-34h]
  int v56; // [esp+28h] [ebp-30h] BYREF
  int v57; // [esp+2Ch] [ebp-2Ch]
  int v58; // [esp+30h] [ebp-28h]
  int v59; // [esp+34h] [ebp-24h]
  int v60; // [esp+38h] [ebp-20h]
  int v61; // [esp+3Ch] [ebp-1Ch]
  int v62; // [esp+40h] [ebp-18h]
  int v63; // [esp+44h] [ebp-14h]
  int v64; // [esp+48h] [ebp-10h]
  int v65; // [esp+4Ch] [ebp-Ch]
  int v66; // [esp+50h] [ebp-8h]
  int v67; // [esp+54h] [ebp-4h]
  int v68; // [esp+5Ch] [ebp+4h]
  int v69; // [esp+5Ch] [ebp+4h]
  int v70; // [esp+5Ch] [ebp+4h]
  int v71; // [esp+5Ch] [ebp+4h]
  int v72; // [esp+5Ch] [ebp+4h]
  int v73; // [esp+5Ch] [ebp+4h]
  int v74; // [esp+5Ch] [ebp+4h]
  int v75; // [esp+5Ch] [ebp+4h]
  int v76; // [esp+60h] [ebp+8h]
  int v77; // [esp+60h] [ebp+8h]
  int v78; // [esp+60h] [ebp+8h]
  int v79; // [esp+60h] [ebp+8h]

  v5 = *(_DWORD **)(a2 + 84);
  v6 = *(_DWORD *)(a1 + 292) + 128;
  v7 = (__int16 *)(a3 + 16);
  v8 = &v56;
  v76 = 2;
  do
  {
    v9 = ((*v5 * *(v7 - 8)) << 13) + 1024;
    v10 = 5793 * v5[16] * v7[8] + v9;
    v11 = 10033 * v5[8] * *v7;
    v68 = v9 - 11586 * v5[16] * v7[8];
    v12 = (v11 + v10) >> 11;
    v13 = v10 - v11;
    v14 = v5[17] * v7[9];
    *(v8 - 6) = v12;
    v14 *= 5793;
    *v8 = v68 >> 11;
    v15 = ((v5[1] * *(v7 - 7)) << 13) + 1024;
    v8[6] = v13 >> 11;
    v16 = v14 + v15;
    v17 = v15 - 2 * v14;
    v18 = 10033 * v5[9] * v7[1];
    v69 = v17;
    v19 = (v18 + v16) >> 11;
    v20 = v16 - v18;
    v21 = v5[18] * v7[10];
    *(v8 - 5) = v19;
    v21 *= 5793;
    v8[1] = v69 >> 11;
    v22 = ((v5[2] * *(v7 - 6)) << 13) + 1024;
    v8[7] = v20 >> 11;
    v23 = v21 + v22;
    v24 = v22 - 2 * v21;
    v25 = 10033 * v5[10] * v7[2];
    *(v8 - 4) = (v25 + v23) >> 11;
    v8[8] = (v23 - v25) >> 11;
    v8[2] = v24 >> 11;
    v7 += 3;
    v5 += 3;
    v8 += 3;
    --v76;
  }
  while ( v76 );
  v26 = (v50 + 16) << 13;
  v27 = 5793 * v54 + v26;
  v28 = v26 - 11586 * v54;
  v29 = 10033 * v52 + v27;
  v30 = v27 - 10033 * v52;
  v70 = 2998 * (v51 + v55);
  v31 = (_BYTE *)(a5 + *a4);
  v77 = v70 + ((v51 + v53) << 13);
  v71 = v70 + ((v55 - v53) << 13);
  v32 = (v51 - v55 - v53) << 13;
  *v31 = *(_BYTE *)((((v29 + v77) >> 18) & 0x3FF) + v6);
  v31[5] = *(_BYTE *)((((v29 - v77) >> 18) & 0x3FF) + v6);
  v31[1] = *(_BYTE *)((((v28 + v32) >> 18) & 0x3FF) + v6);
  v31[4] = *(_BYTE *)((((v28 - v32) >> 18) & 0x3FF) + v6);
  v33 = v60;
  v31[2] = *(_BYTE *)((((v71 + v30) >> 18) & 0x3FF) + v6);
  v33 *= 5793;
  v31[3] = *(_BYTE *)(v6 + (((v30 - v71) >> 18) & 0x3FF));
  v34 = (_BYTE *)(a5 + a4[1]);
  v35 = (v56 + 16) << 13;
  v36 = v33 + v35;
  v37 = v35 - 2 * v33;
  v38 = 10033 * v58 + v36;
  v39 = v36 - 10033 * v58;
  v72 = 2998 * (v57 + v61);
  v78 = v72 + ((v57 + v59) << 13);
  v73 = v72 + ((v61 - v59) << 13);
  v40 = (v57 - v61 - v59) << 13;
  *v34 = *(_BYTE *)((((v38 + v78) >> 18) & 0x3FF) + v6);
  v34[5] = *(_BYTE *)((((v38 - v78) >> 18) & 0x3FF) + v6);
  v34[1] = *(_BYTE *)((((v37 + v40) >> 18) & 0x3FF) + v6);
  v34[4] = *(_BYTE *)((((v37 - v40) >> 18) & 0x3FF) + v6);
  v34[2] = *(_BYTE *)((((v73 + v39) >> 18) & 0x3FF) + v6);
  v41 = 5793 * v66;
  v34[3] = *(_BYTE *)(v6 + (((v39 - v73) >> 18) & 0x3FF));
  v42 = (v62 + 16) << 13;
  v43 = v41 + v42;
  v44 = v42 - 2 * v41;
  v45 = 10033 * v64 + v43;
  v46 = v43 - 10033 * v64;
  v47 = (_BYTE *)(a5 + a4[2]);
  v74 = 2998 * (v63 + v67);
  v79 = v74 + ((v63 + v65) << 13);
  v75 = v74 + ((v67 - v65) << 13);
  v48 = v63 - v67 - v65;
  *v47 = *(_BYTE *)((((v45 + v79) >> 18) & 0x3FF) + v6);
  v48 <<= 13;
  v47[5] = *(_BYTE *)((((v45 - v79) >> 18) & 0x3FF) + v6);
  v47[1] = *(_BYTE *)((((v44 + v48) >> 18) & 0x3FF) + v6);
  v47[4] = *(_BYTE *)((((v44 - v48) >> 18) & 0x3FF) + v6);
  v47[2] = *(_BYTE *)((((v75 + v46) >> 18) & 0x3FF) + v6);
  result = *(_BYTE *)(v6 + (((v46 - v75) >> 18) & 0x3FF));
  v47[3] = result;
  return result;
}
