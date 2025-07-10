_BYTE *__cdecl jpeg_idct_islow(int a1, int a2, __int16 *a3, int a4, int a5)
{
  _DWORD *v5; // ebx
  __int16 *v6; // esi
  int v7; // ebp
  int *v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // edx
  int v12; // ebp
  int v13; // edi
  int v14; // edx
  int v15; // ecx
  int v16; // ebp
  int v17; // ecx
  int v18; // edx
  int v19; // ebp
  int v20; // edx
  int v21; // edi
  int v22; // ecx
  int v23; // esi
  int v24; // ebp
  int v25; // ebx
  int v26; // edi
  int v27; // ecx
  int v28; // ebx
  int v29; // esi
  int v30; // edi
  int v31; // edx
  int v32; // esi
  _DWORD *v33; // ecx
  _BYTE *result; // eax
  char v35; // dl
  int v36; // esi
  int v37; // edi
  int v38; // ebx
  int v39; // edx
  int v40; // ebp
  int v41; // edi
  int v42; // edx
  int v43; // esi
  int v44; // edx
  int v45; // ebx
  int v46; // esi
  int v47; // edx
  int v48; // edi
  int v49; // esi
  int v50; // edx
  int v51; // ebp
  int v52; // ebx
  int v53; // edx
  int v54; // ebp
  int v55; // ebx
  int v56; // edx
  int v57; // esi
  int v58; // edi
  int v59; // [esp+Ch] [ebp-12Ch]
  int v60; // [esp+Ch] [ebp-12Ch]
  int v61; // [esp+Ch] [ebp-12Ch]
  _DWORD *v62; // [esp+10h] [ebp-128h]
  __int16 v63; // [esp+14h] [ebp-124h]
  int v64; // [esp+14h] [ebp-124h]
  int v65; // [esp+14h] [ebp-124h]
  int i; // [esp+18h] [ebp-120h]
  int v67; // [esp+18h] [ebp-120h]
  int v68; // [esp+1Ch] [ebp-11Ch]
  int v69; // [esp+20h] [ebp-118h]
  int v70; // [esp+20h] [ebp-118h]
  int v71; // [esp+24h] [ebp-114h]
  int v72; // [esp+24h] [ebp-114h]
  int v73; // [esp+28h] [ebp-110h]
  int v74; // [esp+28h] [ebp-110h]
  int v75; // [esp+2Ch] [ebp-10Ch]
  int v76; // [esp+2Ch] [ebp-10Ch]
  __int16 *v77; // [esp+30h] [ebp-108h]
  int v78; // [esp+34h] [ebp-104h]
  _BYTE v79[256]; // [esp+38h] [ebp-100h] BYREF

  v5 = *(_DWORD **)(a2 + 84);
  v6 = a3;
  v7 = *(_DWORD *)(a1 + 292) + 128;
  v78 = v7;
  v77 = a3;
  v62 = v5;
  v8 = (int *)v79;
  for ( i = 8; i > 0; --i )
  {
    v63 = v6[8];
    if ( v63 || v6[16] || v6[24] || v6[32] || v6[40] || v6[48] || v6[56] )
    {
      v10 = v5[16] * v6[16];
      v11 = v5[48] * v6[48];
      v12 = 4433 * (v11 + v10);
      v13 = v12 + 6270 * v10;
      v59 = v12 - 15137 * v11;
      v14 = (v5[32] * v6[32]) << 13;
      v15 = ((*v5 * *v6) << 13) + 1024;
      v16 = v14 + v15;
      v17 = v15 - v14;
      v18 = v13 + v16;
      v19 = v16 - v13;
      v69 = v18;
      v20 = v5[40] * v6[40];
      v75 = v17 + v59;
      v21 = v5[8] * v63;
      v71 = v17 - v59;
      v22 = v5[56] * v6[56];
      v23 = v5[24] * v6[24];
      v73 = v19;
      v64 = 9633 * (v22 + v23 + v20 + v21) - 16069 * (v22 + v23);
      v24 = 9633 * (v22 + v23 + v20 + v21) - 3196 * (v20 + v21);
      v25 = -7373 * (v22 + v21);
      v26 = v25 + 12299 * v21;
      v27 = v64 + v25 + 2446 * v22;
      v28 = -20995 * (v20 + v23);
      v29 = v64 + v28 + 25172 * v23;
      v30 = v24 + v26;
      v31 = v24 + v28 + 16819 * v20;
      v8[56] = (v69 - v30) >> 11;
      *v8 = (v69 + v30) >> 11;
      v8[8] = (v75 + v29) >> 11;
      v8[48] = (v75 - v29) >> 11;
      v5 = v62;
      v7 = v78;
      v8[40] = (v71 - v31) >> 11;
      v8[24] = (v73 + v27) >> 11;
      v6 = v77;
      v8[16] = (v71 + v31) >> 11;
      v8[32] = (v73 - v27) >> 11;
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
    v62 = v5;
    v77 = v6;
  }
  v32 = 0;
  v33 = v79;
  v67 = 0;
  do
  {
    result = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * v32));
    if ( v33[1] || v33[2] || v33[3] || v33[4] || v33[5] || v33[6] || v33[7] )
    {
      v36 = v33[2];
      v37 = v33[6];
      v38 = v33[4];
      v39 = 4433 * (v37 + v36);
      v40 = v39 + 6270 * v36;
      v41 = v39 - 15137 * v37;
      v42 = *v33 + 16;
      v43 = v38 + v42;
      v44 = v42 - v38;
      v43 <<= 13;
      v70 = v43 + v40;
      v45 = v33[1];
      v74 = v43 - v40;
      v44 <<= 13;
      v46 = v44 + v41;
      v47 = v44 - v41;
      v48 = v33[3];
      v76 = v46;
      v49 = v33[5];
      v72 = v47;
      v50 = v33[7];
      v68 = 9633 * (v50 + v48 + v49 + v45);
      v65 = v68 - 16069 * (v50 + v48);
      v60 = v68 - 3196 * (v49 + v45);
      v51 = -7373 * (v50 + v45);
      v52 = v51 + 12299 * v45;
      v53 = v51 + 2446 * v50;
      v54 = v60;
      v61 = v60 + v52;
      v55 = -20995 * (v49 + v48);
      v56 = v65 + v53;
      v57 = v54 + v55 + 16819 * v49;
      v7 = v78;
      v58 = v65 + v55 + 25172 * v48;
      *result = *(_BYTE *)((((v70 + v61) >> 18) & 0x3FF) + v78);
      result[7] = *(_BYTE *)((((v70 - v61) >> 18) & 0x3FF) + v78);
      result[1] = *(_BYTE *)((((v76 + v58) >> 18) & 0x3FF) + v78);
      result[6] = *(_BYTE *)((((v76 - v58) >> 18) & 0x3FF) + v78);
      result[2] = *(_BYTE *)((((v72 + v57) >> 18) & 0x3FF) + v78);
      result[5] = *(_BYTE *)((((v72 - v57) >> 18) & 0x3FF) + v78);
      result[3] = *(_BYTE *)((((v74 + v56) >> 18) & 0x3FF) + v78);
      v35 = *(_BYTE *)((((v74 - v56) >> 18) & 0x3FF) + v78);
      v32 = v67;
    }
    else
    {
      v35 = *(_BYTE *)((((*v33 + 16) >> 5) & 0x3FF) + v7);
      *result = v35;
      result[1] = v35;
      result[2] = v35;
      result[3] = v35;
      result[5] = v35;
      result[6] = v35;
      result[7] = v35;
    }
    ++v32;
    v33 += 8;
    result[4] = v35;
    v67 = v32;
  }
  while ( v32 < 8 );
  return result;
}
