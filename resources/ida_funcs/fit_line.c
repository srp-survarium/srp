int __cdecl fit_line(lsfit_acc *a, int fits, int *y0, int *y1)
{
  vorbis_info_floor1 *info; // ecx
  double v5; // st7
  lsfit_acc *v6; // eax
  double v7; // st6
  double v9; // st5
  double v10; // st4
  double v11; // st3
  double v12; // st2
  int v13; // edx
  double v14; // st1
  int v15; // edi
  int v16; // ebp
  bool v17; // cc
  int *p_xb; // eax
  unsigned int v19; // esi
  int v20; // edx
  double v21; // st2
  double v22; // st6
  double v23; // st5
  double v24; // st4
  double v25; // st3
  double v26; // st2
  double v27; // st6
  double v28; // st5
  double v29; // st4
  double v30; // st3
  double v31; // st2
  double v32; // st2
  double v33; // st6
  double v34; // st1
  int v35; // edi
  int v36; // edx
  double v37; // st4
  double v38; // st3
  double v39; // st2
  int v40; // eax
  int v41; // ebx
  double v42; // st1
  int v43; // esi
  int v44; // eax
  int x0; // [esp+1Ch] [ebp-20h]
  int v47; // [esp+20h] [ebp-1Ch]
  int v48; // [esp+20h] [ebp-1Ch]
  int v49; // [esp+24h] [ebp-18h]
  int v50; // [esp+24h] [ebp-18h]
  int v51; // [esp+24h] [ebp-18h]
  int v52; // [esp+28h] [ebp-14h]
  int v53; // [esp+28h] [ebp-14h]
  double b; // [esp+30h] [ebp-Ch]
  double ba; // [esp+30h] [ebp-Ch]
  double bb; // [esp+30h] [ebp-Ch]
  double bc; // [esp+30h] [ebp-Ch]
  double bd; // [esp+30h] [ebp-Ch]
  double be; // [esp+30h] [ebp-Ch]
  int x1; // [esp+44h] [ebp+8h]

  v5 = 0.0;
  v6 = a;
  v7 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  v11 = 0.0;
  v12 = 0.0;
  b = 0.0;
  v13 = a[fits - 1].x1;
  v14 = 1.0;
  v15 = a->x0;
  v16 = 0;
  v17 = fits < 4;
  x0 = a->x0;
  x1 = v13;
  if ( !v17 )
  {
    p_xb = &a->xb;
    v19 = ((unsigned int)(fits - 4) >> 2) + 1;
    v16 = 4 * v19;
    do
    {
      v52 = p_xb[5];
      v49 = *(p_xb - 1);
      v20 = p_xb[13];
      v47 = p_xb[19];
      v21 = (double)(v49 + v52) * info->twofitweight / (double)(v49 + 1) + 1.0;
      v22 = v7 + (double)*(p_xb - 6) * v21 + (double)*p_xb;
      v23 = v9 + (double)*(p_xb - 5) * v21 + (double)p_xb[1];
      v24 = v10 + (double)*(p_xb - 4) * v21 + (double)p_xb[2];
      v25 = v11 + (double)*(p_xb - 2) * v21 + (double)p_xb[4];
      ba = v21 * (double)v49 + (double)v52 + b;
      v26 = (double)(v20 + v47) * info->twofitweight / (double)(v20 + 1) + 1.0;
      v27 = v22 + (double)p_xb[8] * v26 + (double)p_xb[14];
      v28 = v23 + (double)p_xb[9] * v26 + (double)p_xb[15];
      v29 = v24 + (double)p_xb[10] * v26 + (double)p_xb[16];
      v30 = v25 + (double)p_xb[12] * v26 + (double)p_xb[18];
      v50 = p_xb[27];
      v31 = v26 * (double)v20 + (double)v47;
      v48 = p_xb[33];
      bb = v31 + ba;
      v32 = (double)(v50 + v48) * info->twofitweight / (double)(v50 + 1) + 1.0;
      v33 = v27 + (double)p_xb[22] * v32 + (double)p_xb[28];
      v34 = (double)p_xb[23] * v32;
      v35 = p_xb[47];
      v36 = p_xb[41];
      p_xb += 56;
      v37 = v29 + (double)*(p_xb - 32) * v32 + (double)*(p_xb - 26);
      v38 = v30 + (double)*(p_xb - 30) * v32 + (double)*(p_xb - 24);
      --v19;
      bc = v32 * (double)v50 + (double)v48 + bb;
      v39 = (double)(v36 + v35) * info->twofitweight / (double)(v36 + 1) + 1.0;
      v7 = v33 + (double)*(p_xb - 20) * v39 + (double)*(p_xb - 14);
      v9 = v28 + v34 + (double)*(p_xb - 27) + (double)*(p_xb - 19) * v39 + (double)*(p_xb - 13);
      v10 = v37 + (double)*(p_xb - 18) * v39 + (double)*(p_xb - 12);
      v11 = v38 + (double)*(p_xb - 16) * v39 + (double)*(p_xb - 10);
      v12 = v39 * (double)v36 + (double)v35 + bc;
      b = v12;
    }
    while ( v19 );
    v15 = a->x0;
    v6 = a;
    v14 = 1.0;
    v5 = 0.0;
    v13 = x1;
  }
  if ( v16 < fits )
  {
    v40 = (int)&v6[v16].xb;
    v41 = fits - v16;
    do
    {
      v51 = *(_DWORD *)(v40 + 20);
      v53 = *(_DWORD *)(v40 - 4);
      v40 += 56;
      --v41;
      bd = (double)(v53 + v51) * info->twofitweight / (double)(v53 + 1) + v14;
      v7 = v7 + bd * (double)*(int *)(v40 - 80) + (double)*(int *)(v40 - 56);
      v9 = v9 + (double)*(int *)(v40 - 76) * bd + (double)*(int *)(v40 - 52);
      v10 = v10 + (double)*(int *)(v40 - 72) * bd + (double)*(int *)(v40 - 48);
      v11 = v11 + (double)*(int *)(v40 - 64) * bd + (double)*(int *)(v40 - 40);
      v12 = v12 + (double)v53 * bd + (double)v51;
    }
    while ( v41 );
    v13 = x1;
    v5 = 0.0;
  }
  if ( *y0 >= 0 )
  {
    v7 = v7 + (double)x0;
    v9 = v9 + (double)*y0;
    v10 = v10 + (double)(v15 * v15);
    v11 = v11 + (double)(v15 * *y0);
    v12 = v12 + v14;
  }
  if ( *y1 >= 0 )
  {
    v7 = v7 + (double)x1;
    v9 = v9 + (double)*y1;
    v10 = v10 + (double)(v13 * v13);
    v11 = v11 + (double)(v13 * *y1);
    v12 = v12 + v14;
  }
  v42 = v12 * v10 - v7 * v7;
  if ( v42 <= v5 )
  {
    *y0 = 0;
    *y1 = 0;
    return 1;
  }
  else
  {
    be = (v11 * v12 - v7 * v9) / v42;
    v43 = (int)floor((v10 * v9 - v11 * v7) / v42 + be * (double)x0 + 0.5);
    *y0 = v43;
    v44 = (int)floor((double)x1 * be + (v10 * v9 - v11 * v7) / v42 + 0.5);
    *y1 = v44;
    if ( v43 > 1023 )
      *y0 = 1023;
    if ( v44 > 1023 )
      *y1 = 1023;
    if ( *y0 < 0 )
      *y0 = 0;
    if ( *y1 < 0 )
      *y1 = 0;
    return 0;
  }
}
