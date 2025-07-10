int __cdecl jpeg_idct_float(int a1, int a2, __int16 *a3, int a4, int a5)
{
  double v5; // st6
  double v7; // st5
  float *v8; // edx
  int v9; // ebx
  float *v10; // eax
  int v11; // edi
  __int16 v12; // si
  double v13; // st5
  double v14; // st5
  double v15; // st5
  double v16; // st4
  int v17; // ebp
  float *v18; // esi
  _BYTE *v19; // edi
  double v20; // st4
  double v21; // st3
  int result; // eax
  float v23; // [esp+10h] [ebp-128h]
  float v24; // [esp+10h] [ebp-128h]
  float v25; // [esp+10h] [ebp-128h]
  float v26; // [esp+10h] [ebp-128h]
  float v27; // [esp+10h] [ebp-128h]
  float v28; // [esp+10h] [ebp-128h]
  float v29; // [esp+10h] [ebp-128h]
  float v30; // [esp+10h] [ebp-128h]
  float v31; // [esp+10h] [ebp-128h]
  float v32; // [esp+14h] [ebp-124h]
  float v33; // [esp+14h] [ebp-124h]
  float v34; // [esp+14h] [ebp-124h]
  float v35; // [esp+14h] [ebp-124h]
  float v36; // [esp+14h] [ebp-124h]
  float v37; // [esp+14h] [ebp-124h]
  float v38; // [esp+14h] [ebp-124h]
  float v39; // [esp+18h] [ebp-120h]
  float v40; // [esp+18h] [ebp-120h]
  float v41; // [esp+18h] [ebp-120h]
  float v42; // [esp+18h] [ebp-120h]
  float v43; // [esp+18h] [ebp-120h]
  float v44; // [esp+18h] [ebp-120h]
  float v45; // [esp+1Ch] [ebp-11Ch]
  float v46; // [esp+1Ch] [ebp-11Ch]
  float v47; // [esp+1Ch] [ebp-11Ch]
  float v48; // [esp+1Ch] [ebp-11Ch]
  float v49; // [esp+1Ch] [ebp-11Ch]
  float v50; // [esp+1Ch] [ebp-11Ch]
  float v51; // [esp+20h] [ebp-118h]
  float v52; // [esp+20h] [ebp-118h]
  float v53; // [esp+20h] [ebp-118h]
  float v54; // [esp+20h] [ebp-118h]
  float v55; // [esp+20h] [ebp-118h]
  float v56; // [esp+24h] [ebp-114h]
  float v57; // [esp+24h] [ebp-114h]
  float v58; // [esp+24h] [ebp-114h]
  float v59; // [esp+24h] [ebp-114h]
  float v60; // [esp+24h] [ebp-114h]
  float v61; // [esp+28h] [ebp-110h]
  float v62; // [esp+28h] [ebp-110h]
  float v63; // [esp+28h] [ebp-110h]
  float v64; // [esp+2Ch] [ebp-10Ch]
  float v65; // [esp+2Ch] [ebp-10Ch]
  float v66; // [esp+2Ch] [ebp-10Ch]
  float v67; // [esp+30h] [ebp-108h]
  float v68; // [esp+30h] [ebp-108h]
  float v69; // [esp+30h] [ebp-108h]
  float v70; // [esp+34h] [ebp-104h]
  float v71; // [esp+34h] [ebp-104h]
  float v72; // [esp+34h] [ebp-104h]
  char v73; // [esp+38h] [ebp-100h] BYREF
  char v74; // [esp+40h] [ebp-F8h] BYREF

  v5 = 1.847759008407593;
  v7 = 1.08239221572876;
  v8 = *(float **)(a2 + 84);
  v9 = *(_DWORD *)(a1 + 292);
  v10 = (float *)&v73;
  v11 = 8;
  do
  {
    v12 = a3[8];
    if ( v12 || a3[16] || a3[24] || a3[32] || a3[40] || a3[48] || a3[56] )
    {
      v61 = (double)*a3 * *v8;
      v64 = (double)a3[16] * v8[16];
      v56 = (double)a3[32] * v8[32];
      v67 = (double)a3[48] * v8[48];
      v13 = v56;
      v57 = v56 + v61;
      v32 = v61 - v13;
      v45 = v67 + v64;
      v14 = v45;
      v46 = (v64 - v67) * 1.414213538169861 - v45;
      v62 = v14 + v57;
      v68 = v57 - v14;
      v65 = v46 + v32;
      v58 = v32 - v46;
      v39 = v8[8] * (double)v12;
      v33 = (double)a3[24] * v8[24];
      v51 = (double)a3[40] * v8[40];
      v70 = (double)a3[56] * v8[56];
      v15 = v51;
      v52 = v51 + v33;
      v24 = v15 - v33;
      v34 = v70 + v39;
      v47 = v39 - v70;
      v16 = v52;
      v71 = v34 + v52;
      v40 = v5 * (v47 + v24);
      v25 = v40 - v24 * 2.613126039505005;
      v53 = v25 - v71;
      v26 = (v34 - v16) * 1.414213538169861;
      v35 = v26 - v53;
      v27 = v40 - v47 * 1.08239221572876;
      v41 = v27 - v35;
      *v10 = v71 + v62;
      v10[56] = v62 - v71;
      v10[8] = v53 + v65;
      v10[48] = v65 - v53;
      v10[16] = v35 + v58;
      v10[40] = v58 - v35;
      v10[24] = v41 + v68;
      v10[32] = v68 - v41;
      v7 = 1.08239221572876;
      v5 = 1.847759008407593;
    }
    else
    {
      v23 = (double)*a3 * *v8;
      *v10 = v23;
      v10[8] = v23;
      v10[16] = v23;
      v10[24] = v23;
      v10[32] = v23;
      v10[40] = v23;
      v10[48] = v23;
      v10[56] = v23;
    }
    --v11;
    ++a3;
    ++v8;
    ++v10;
  }
  while ( v11 > 0 );
  v17 = 0;
  v18 = (float *)&v74;
  do
  {
    v19 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * v17));
    v42 = *(v18 - 2) + 128.5;
    v59 = v18[2] + v42;
    v36 = v42 - v18[2];
    v48 = v18[4] + *v18;
    v20 = v48;
    v49 = (*v18 - v18[4]) * 1.414213538169861 - v48;
    v63 = v20 + v59;
    v69 = v59 - v20;
    v66 = v49 + v36;
    v60 = v36 - v49;
    v54 = v18[3] + v18[1];
    v28 = v18[3] - v18[1];
    v37 = v18[5] + *(v18 - 1);
    v50 = *(v18 - 1) - v18[5];
    v21 = v54;
    v72 = v37 + v54;
    v43 = (v50 + v28) * v5;
    v29 = v43 - v28 * 2.613126039505005;
    v55 = v29 - v72;
    v30 = (v37 - v21) * 1.414213538169861;
    v38 = v30 - v55;
    v31 = v43 - v50 * v7;
    v44 = v31 - v38;
    *v19 = *(_BYTE *)(((int)(v72 + v63) & 0x3FF) + v9);
    v19[7] = *(_BYTE *)(((int)(v63 - v72) & 0x3FF) + v9);
    v19[1] = *(_BYTE *)(((int)(v55 + v66) & 0x3FF) + v9);
    v19[6] = *(_BYTE *)(((int)(v66 - v55) & 0x3FF) + v9);
    v19[2] = *(_BYTE *)(((int)(v38 + v60) & 0x3FF) + v9);
    v19[5] = *(_BYTE *)(((int)(v60 - v38) & 0x3FF) + v9);
    v19[3] = *(_BYTE *)(((int)(v44 + v69) & 0x3FF) + v9);
    result = (int)(v69 - v44) & 0x3FF;
    ++v17;
    v18 += 8;
    v19[4] = *(_BYTE *)(result + v9);
  }
  while ( v17 < 8 );
  return result;
}
