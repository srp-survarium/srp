void __cdecl bark_noise_hybridmp(int n, int *b, const float *f, float *noise, const float offset, const int fixed)
{
  void *v6; // esp
  void *v7; // esp
  void *v8; // esp
  void *v9; // esp
  void *v10; // esp
  float v12; // xmm2_4
  float v13; // xmm6_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float *v16; // edx
  float v17; // xmm7_4
  float v18; // xmm3_4
  float *v19; // eax
  float v20; // xmm5_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm5_4
  float v26; // xmm4_4
  int v27; // ecx
  bool v28; // zf
  int v29; // ecx
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  float v33; // xmm5_4
  float v34; // xmm6_4
  float v35; // xmm7_4
  float v36; // xmm5_4
  int v37; // eax
  int v38; // eax
  int v39; // ecx
  float v40; // xmm5_4
  float v41; // xmm7_4
  float v42; // xmm5_4
  float v43; // eax
  int v44; // ecx
  int v45; // eax
  float v46; // xmm3_4
  float v47; // xmm5_4
  int v48; // eax
  int v49; // edx
  int v50; // eax
  float v51; // xmm0_4
  float v52; // xmm6_4
  float v53; // xmm1_4
  float v54; // xmm3_4
  float *v55; // eax
  float v56; // xmm0_4
  float v57; // xmm5_4
  bool v58; // sf
  int v59; // ecx
  int v60; // edx
  float v61; // xmm5_4
  float v62; // xmm7_4
  float *v63; // eax
  float v64; // xmm0_4
  float v65; // xmm5_4
  int v66; // ecx
  float v67; // xmm3_4
  float *v68; // eax
  float v69; // xmm0_4
  int v70; // [esp+0h] [ebp-48h] BYREF
  int v71; // [esp+4h] [ebp-44h] BYREF
  int v72; // [esp+Ch] [ebp-3Ch]
  int v73; // [esp+10h] [ebp-38h]
  float v74; // [esp+14h] [ebp-34h]
  int v75; // [esp+18h] [ebp-30h]
  float v76; // [esp+1Ch] [ebp-2Ch]
  float v77; // [esp+20h] [ebp-28h]
  float v78; // [esp+24h] [ebp-24h]
  int v79; // [esp+28h] [ebp-20h]
  int v80; // [esp+2Ch] [ebp-1Ch]
  int v81; // [esp+30h] [ebp-18h]
  float *v82; // [esp+38h] [ebp-10h]
  float v83; // [esp+3Ch] [ebp-Ch]
  float v84; // [esp+40h] [ebp-8h]
  float v85; // [esp+44h] [ebp-4h]
  int v86; // [esp+54h] [ebp+Ch]
  int v87; // [esp+54h] [ebp+Ch]
  float v88; // [esp+58h] [ebp+10h]
  float v89; // [esp+58h] [ebp+10h]
  float v90; // [esp+58h] [ebp+10h]
  int v91; // [esp+64h] [ebp+1Ch]

  v6 = alloca(4 * n);
  v7 = alloca(4 * n);
  v8 = alloca(4 * n);
  v9 = alloca(4 * n);
  v82 = (float *)&v70;
  v10 = alloca(4 * n);
  v12 = s_bm_current_air_resistance;
  v13 = *f + offset;
  v14 = 0.0;
  v15 = 0.0;
  *(float *)&v72 = 0.0;
  v84 = s_bm_current_air_resistance;
  v76 = 0.0;
  v78 = 0.0;
  if ( s_bm_current_air_resistance > v13 )
    v13 = s_bm_current_air_resistance;
  v16 = v82;
  v17 = (float)(v13 * v13) * 0.5;
  v18 = v17;
  v77 = v17 * v13;
  *v82 = v17 * v13;
  v70 = 0;
  v88 = v12;
  if ( n > 1 )
  {
    LODWORD(v83) = (char *)f - (char *)&v70;
    v73 = 0;
    v81 = 0;
    v80 = 0;
    v79 = (char *)v16 - (char *)&v70;
    v19 = (float *)&v71;
    v75 = n - 1;
    do
    {
      v20 = *(float *)((char *)v19 + LODWORD(v83)) + offset;
      v85 = v20;
      if ( v12 > v20 )
      {
        v20 = v12;
        v85 = v12;
      }
      v21 = v20 * v20;
      v17 = v21 + v17;
      v22 = (float)((float)(v88 * v21) * v85) + v76;
      v23 = (float)(v88 * v21) + v18;
      v24 = (float)((float)(v88 * v88) * v21) + v78;
      v25 = (float)(v21 * v85) + v77;
      v74 = v23;
      v26 = v24;
      v18 = v74;
      *(float *)((char *)v19 + v81) = v74;
      *(float *)((char *)v19 + v80) = v26;
      *(float *)((char *)v19 + v79) = v25;
      v27 = v73;
      v78 = v26;
      *v19 = v17;
      *(float *)((char *)v19++ + v27) = v22;
      v28 = v75-- == 1;
      v77 = v25;
      v76 = v22;
      v88 = v88 + v12;
    }
    while ( !v28 );
    v14 = *(float *)&v72;
  }
  v29 = *b;
  v85 = 0.0;
  v30 = v29 >> 16;
  v89 = 0.0;
  if ( v29 >> 16 < 0 )
  {
    v75 = 0;
    while ( 1 )
    {
      v31 = -4 * v30;
      v32 = 4 * (unsigned __int16)v29;
      v33 = v16[v31 / 4u] + v16[v32 / 4u];
      v34 = *(float *)((char *)&v70 + v32) - *(float *)((char *)&v70 + v31);
      v83 = *(float *)((char *)&v70 + v31) + *(float *)((char *)&v70 + v32);
      v35 = *(float *)((char *)&v70 + v32) - *(float *)((char *)&v70 + v31);
      v14 = (float)(v35 * v83) - (float)(v33 * v34);
      v15 = (float)(v33 * v83) - (float)(v35 * v34);
      v36 = (float)((float)(v89 * v14) + v15) / (float)((float)(v83 * v83) - (float)(v34 * v34));
      v84 = (float)(v83 * v83) - (float)(v34 * v34);
      if ( v36 < 0.0 )
        v36 = 0.0;
      ++LODWORD(v85);
      *(float *)((char *)noise + v75) = v36 - offset;
      v29 = b[LODWORD(v85)];
      v75 = 4 * LODWORD(v85);
      v30 = v29 >> 16;
      v89 = v89 + v12;
      if ( v29 >> 16 >= 0 )
        break;
      v16 = v82;
    }
  }
  v37 = b[LODWORD(v85)];
  while ( 1 )
  {
    v44 = v37 >> 16;
    if ( (unsigned __int16)v37 >= n )
      break;
    v38 = 4 * (unsigned __int16)v37;
    v39 = 4 * v44;
    v40 = v82[v38 / 4u] - v82[v39 / 4u];
    v83 = *(float *)((char *)&v70 + v38) - *(float *)((char *)&v70 + v39);
    v41 = *(float *)((char *)&v70 + v38) - *(float *)((char *)&v70 + v39);
    v14 = (float)(v41 * v83) - (float)(v40 * v83);
    v15 = (float)(v40 * v83) - (float)(v41 * v83);
    v42 = (float)((float)(v89 * v14) + v15) / (float)((float)(v83 * v83) - (float)(v83 * v83));
    v84 = (float)(v83 * v83) - (float)(v83 * v83);
    if ( v42 < 0.0 )
      v42 = 0.0;
    v43 = v85;
    noise[LODWORD(v85)] = v42 - offset;
    LODWORD(v85) = LODWORD(v43) + 1;
    v37 = b[LODWORD(v43) + 1];
    v89 = v89 + v12;
  }
  v45 = LODWORD(v85);
  if ( SLODWORD(v85) < n )
  {
    v46 = v12 / v84;
    do
    {
      v47 = (float)((float)(v89 * v14) + v15) * v46;
      if ( v47 < 0.0 )
        v47 = 0.0;
      noise[v45++] = v47 - offset;
      v89 = v89 + v12;
    }
    while ( v45 < n );
  }
  if ( fixed > 0 )
  {
    v85 = 0.0;
    v48 = fixed / 2;
    v90 = 0.0;
    LODWORD(v76) = fixed / 2;
    v72 = fixed / 2 - fixed;
    if ( v72 < 0 )
    {
      v49 = 4 * v48;
      v75 = v48 - fixed;
      v86 = 4 * LODWORD(v76);
      v72 *= -4;
      v79 = 4 * (fixed - LODWORD(v76));
      v50 = v72;
      do
      {
        v51 = *(float *)((char *)&v70 + v50) + *(float *)((char *)&v70 + v49);
        v52 = *(float *)((char *)&v70 + v49) - *(float *)((char *)&v70 + v50);
        v53 = *(float *)((char *)v82 + v50) + *(float *)((char *)v82 + v49);
        v14 = (float)(v52 * v51) - (float)(v53 * v52);
        v54 = (float)(v51 * v51) - (float)(v52 * v52);
        v15 = (float)(v53 * v51) - (float)(v52 * v52);
        v55 = &noise[LODWORD(v85)];
        v56 = *v55;
        v57 = (float)((float)((float)(v90 * v14) + v15) / v54) - offset;
        v84 = v54;
        if ( v56 > v57 )
          *v55 = v57;
        v79 -= 4;
        v86 += 4;
        ++LODWORD(v85);
        v58 = ++v75 < 0;
        v49 = v86;
        v50 = v79;
        v90 = v90 + v12;
      }
      while ( v58 );
      v48 = LODWORD(v76);
    }
    v59 = v48 + LODWORD(v85);
    if ( v48 + LODWORD(v85) < n )
    {
      v75 = 4 * (v48 + LODWORD(v85) - fixed);
      v79 = v48 + LODWORD(v85);
      v60 = 4 * v59;
      v87 = 4 * v59;
      v91 = 4 * (LODWORD(v85) + v48 - fixed);
      do
      {
        v61 = *(float *)((char *)v82 + v60) - *(float *)((char *)v82 + v75);
        v62 = *(float *)((char *)&v70 + v60) - *(float *)((char *)&v70 + v75);
        v15 = (float)(v61 * v62) - (float)(v62 * v62);
        v14 = (float)(v62 * v62) - (float)(v61 * v62);
        v63 = &noise[LODWORD(v85)];
        v64 = *v63;
        v65 = (float)((float)((float)(v90 * v14) + v15) / (float)((float)(v62 * v62) - (float)(v62 * v62))) - offset;
        v84 = (float)(v62 * v62) - (float)(v62 * v62);
        if ( v64 > v65 )
          *v63 = v65;
        v91 += 4;
        v87 += 4;
        ++LODWORD(v85);
        ++v79;
        v60 = v87;
        v75 = v91;
        v90 = v90 + v12;
      }
      while ( v79 < n );
    }
    v66 = LODWORD(v85);
    if ( SLODWORD(v85) < n )
    {
      v67 = v12 / v84;
      do
      {
        v68 = &noise[v66];
        v69 = (float)((float)((float)(v90 * v14) + v15) * v67) - offset;
        if ( *v68 > v69 )
          *v68 = v69;
        ++v66;
        v90 = v90 + v12;
      }
      while ( v66 < n );
    }
  }
}
