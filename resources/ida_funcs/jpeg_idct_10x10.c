int __cdecl jpeg_idct_10x10(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // esi
  int *v6; // ecx
  __int16 *v7; // edx
  _DWORD *v8; // edi
  int v9; // ebp
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // ebx
  int v14; // ebp
  int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int v19; // ebp
  int v20; // ebx
  int result; // eax
  char *v22; // edi
  int v23; // ebp
  int v24; // ecx
  int v25; // edx
  int v26; // ebx
  int v27; // ecx
  int v28; // edx
  int v29; // edx
  int v30; // ebp
  int v31; // ebx
  int v32; // edx
  int v33; // ebp
  int v34; // ebx
  _BYTE *v35; // eax
  int v36; // ebp
  int v37; // [esp+10h] [ebp-17Ch]
  int v38; // [esp+10h] [ebp-17Ch]
  int v39; // [esp+10h] [ebp-17Ch]
  int v40; // [esp+10h] [ebp-17Ch]
  int v41; // [esp+14h] [ebp-178h]
  int v42; // [esp+14h] [ebp-178h]
  int v43; // [esp+14h] [ebp-178h]
  int v44; // [esp+14h] [ebp-178h]
  int v45; // [esp+18h] [ebp-174h]
  int v46; // [esp+1Ch] [ebp-170h]
  int v47; // [esp+1Ch] [ebp-170h]
  int v48; // [esp+1Ch] [ebp-170h]
  int v49; // [esp+1Ch] [ebp-170h]
  int v50; // [esp+20h] [ebp-16Ch]
  int v51; // [esp+20h] [ebp-16Ch]
  int v52; // [esp+20h] [ebp-16Ch]
  int v53; // [esp+20h] [ebp-16Ch]
  int v54; // [esp+24h] [ebp-168h]
  int v55; // [esp+24h] [ebp-168h]
  int v56; // [esp+24h] [ebp-168h]
  int v57; // [esp+28h] [ebp-164h]
  int v58; // [esp+28h] [ebp-164h]
  int v59; // [esp+2Ch] [ebp-160h]
  int v60; // [esp+2Ch] [ebp-160h]
  int v61; // [esp+34h] [ebp-158h]
  int v62; // [esp+34h] [ebp-158h]
  int v63; // [esp+38h] [ebp-154h]
  int v64; // [esp+38h] [ebp-154h]
  int v65; // [esp+3Ch] [ebp-150h]
  int v66; // [esp+3Ch] [ebp-150h]
  int v67; // [esp+40h] [ebp-14Ch]
  int v68; // [esp+40h] [ebp-14Ch]
  int v69; // [esp+44h] [ebp-148h]
  int v70; // [esp+44h] [ebp-148h]
  int v71; // [esp+48h] [ebp-144h]
  char v72; // [esp+54h] [ebp-138h] BYREF
  char v73; // [esp+6Ch] [ebp-120h] BYREF

  v5 = *(_DWORD *)(a1 + 292) + 128;
  v6 = (int *)&v73;
  v7 = (__int16 *)(a3 + 32);
  v8 = (_DWORD *)(*(_DWORD *)(a2 + 84) + 64);
  v59 = 8;
  do
  {
    v9 = v8[16] * v7[16];
    v10 = ((*(v8 - 16) * *(v7 - 16)) << 13) + 1024;
    v50 = v10 + 9373 * v9;
    v57 = v10 - 3580 * v9;
    v11 = v10 - 11586 * v9;
    v12 = *v8 * *v7;
    v71 = v11 >> 11;
    v13 = v8[32] * v7[32];
    v14 = 6810 * (v12 + v13);
    v15 = v14 + 4209 * v12;
    v37 = v14 - 17828 * v13;
    v67 = v50 - v15;
    v61 = v15 + v50;
    v63 = v37 + v57;
    v16 = v57 - v37;
    v17 = v8[8] * v7[8];
    v54 = v8[24] * v7[24];
    v41 = v8[40] * v7[40];
    v58 = v17 + v41;
    v38 = v17 - v41;
    v65 = v16;
    v18 = *(v8 - 8) * *(v7 - 8);
    v46 = 2531 * (v17 - v41);
    v45 = 7791 * (v17 + v41);
    v19 = v46 + (v54 << 13);
    v51 = v19 + v45 + 11443 * v18;
    v69 = v19 + 1812 * v18 - v45;
    ++v7;
    v42 = (v54 << 13) - ((v17 - v41) << 12) - v46;
    ++v8;
    v47 = 4 * (v18 - v38 - v54);
    v20 = 10323 * v18 - 4815 * v58 - v42;
    v39 = v42 + 5260 * v18 - 4815 * v58;
    v6[64] = (v61 - v51) >> 11;
    *(v6 - 8) = (v61 + v51) >> 11;
    v6[56] = (v63 - v20) >> 11;
    *v6 = (v63 + v20) >> 11;
    v6[48] = v71 - v47;
    v6[8] = v47 + v71;
    v6[40] = (v65 - v39) >> 11;
    v6[16] = (v65 + v39) >> 11;
    v6[24] = (v69 + v67) >> 11;
    v6[32] = (v67 - v69) >> 11;
    ++v6;
    --v59;
  }
  while ( v59 );
  result = 0;
  v60 = 0;
  v22 = &v72;
  do
  {
    v23 = *((_DWORD *)v22 + 2);
    v24 = 3580 * v23;
    v23 *= 9373;
    v25 = (*((_DWORD *)v22 - 2) + 16) << 13;
    v52 = v25 + v23;
    v26 = v25 - v24;
    v27 = v25 + 2 * v24 - 2 * v23;
    v55 = *((_DWORD *)v22 + 4);
    v28 = 6810 * (*(_DWORD *)v22 + v55);
    v48 = v28 + 4209 * *(_DWORD *)v22;
    v62 = v52 + v48;
    v68 = v52 - v48;
    v29 = v28 - 17828 * v55;
    v30 = v29 + v26;
    v66 = v26 - v29;
    v31 = *((_DWORD *)v22 + 1);
    v32 = *((_DWORD *)v22 - 1);
    v64 = v30;
    v56 = *((_DWORD *)v22 + 3) << 13;
    v33 = v31 + *((_DWORD *)v22 + 5);
    v34 = v31 - *((_DWORD *)v22 + 5);
    v43 = v56 + 2531 * v34;
    v35 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * result));
    v53 = v43 + 7791 * v33 + 11443 * v32;
    v70 = v43 + 1812 * v32 - 7791 * v33;
    v44 = v56 - (v34 << 12) - 2531 * v34;
    v49 = ((v32 - v34) << 13) - v56;
    v40 = v44 + 5260 * v32 - 4815 * v33;
    v36 = 10323 * v32 - 4815 * v33 - v44;
    *v35 = *(_BYTE *)((((v62 + v53) >> 18) & 0x3FF) + v5);
    v35[9] = *(_BYTE *)((((v62 - v53) >> 18) & 0x3FF) + v5);
    v35[1] = *(_BYTE *)((((v64 + v36) >> 18) & 0x3FF) + v5);
    v35[8] = *(_BYTE *)((((v64 - v36) >> 18) & 0x3FF) + v5);
    v35[2] = *(_BYTE *)((((v27 + v49) >> 18) & 0x3FF) + v5);
    v35[7] = *(_BYTE *)((((v27 - v49) >> 18) & 0x3FF) + v5);
    v35[3] = *(_BYTE *)((((v66 + v40) >> 18) & 0x3FF) + v5);
    v35[6] = *(_BYTE *)((((v66 - v40) >> 18) & 0x3FF) + v5);
    v35[4] = *(_BYTE *)((((v68 + v70) >> 18) & 0x3FF) + v5);
    v35[5] = *(_BYTE *)((((v68 - v70) >> 18) & 0x3FF) + v5);
    result = v60 + 1;
    v22 += 32;
    ++v60;
  }
  while ( v60 < 10 );
  return result;
}
