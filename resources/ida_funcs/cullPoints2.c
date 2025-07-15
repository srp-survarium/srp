void __usercall cullPoints2(float *p@<eax>, int n, int m, int i0, int *iret)
{
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  int v14; // edx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  unsigned int v20; // ecx
  float *v21; // eax
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm7_4
  float v28; // xmm6_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  int v32; // esi
  int v33; // esi
  int v34; // eax
  int v35; // ecx
  int v36; // edi
  int *v37; // ebp
  float v38; // xmm1_4
  float v39; // xmm0_4
  long double v40; // st7
  float v41; // xmm0_4
  int v42; // edx
  float a; // [esp+1Ch] [ebp-60h]
  float q; // [esp+20h] [ebp-5Ch]
  float qa; // [esp+20h] [ebp-5Ch]
  float v46; // [esp+24h] [ebp-58h]
  float v47; // [esp+24h] [ebp-58h]
  float v48; // [esp+28h] [ebp-54h]
  float v49; // [esp+2Ch] [ebp-50h]
  float v50; // [esp+2Ch] [ebp-50h]
  float v51; // [esp+30h] [ebp-4Ch]
  float v52; // [esp+34h] [ebp-48h]
  float v53; // [esp+34h] [ebp-48h]
  int avail[8]; // [esp+38h] [ebp-44h] BYREF
  float A[9]; // [esp+58h] [ebp-24h]
  float maxdiff; // [esp+80h] [ebp+4h]
  float maxdiffa; // [esp+80h] [ebp+4h]
  float maxdiffb; // [esp+80h] [ebp+4h]
  float diff; // [esp+8Ch] [ebp+10h]
  float diffa; // [esp+8Ch] [ebp+10h]

  if ( n == 1 )
  {
    v8 = *p;
    v9 = p[1];
  }
  else
  {
    if ( n == 2 )
    {
      v10 = p[2] + *p;
      v11 = FLOAT_0_5;
      v12 = p[3] + p[1];
    }
    else
    {
      v13 = 0.0;
      v14 = 0;
      v15 = 0.0;
      v16 = 0.0;
      v17 = 0.0;
      q = 0.0;
      v46 = 0.0;
      v18 = 0.0;
      v48 = 0.0;
      v19 = 0.0;
      if ( n - 1 >= 2 )
      {
        v20 = ((unsigned int)(n - 3) >> 1) + 1;
        v21 = p + 2;
        v14 = 2 * v20;
        do
        {
          v22 = (float)(*(v21 - 2) * v21[1]) - (float)(*(v21 - 1) * *v21);
          v23 = v21[3];
          v48 = (float)((float)(*(v21 - 2) + *v21) * v22) + v48;
          v24 = v21[2];
          q = q + v22;
          v46 = (float)((float)(*(v21 - 1) + v21[1]) * v22) + v46;
          v25 = v21[1];
          v26 = (float)(v23 * *v21) - (float)(v25 * v24);
          v27 = *v21;
          v21 += 4;
          --v20;
          v13 = v13 + v26;
          v19 = (float)((float)(v24 + v27) * v26) + v19;
          v18 = (float)((float)(v25 + v23) * v26) + v18;
        }
        while ( v20 );
        v16 = 0.0;
        v17 = 0.0;
        v15 = 0.0;
      }
      if ( v14 < n - 1 )
      {
        v28 = p[2 * v14];
        v29 = p[2 * v14 + 1];
        v30 = p[2 * v14 + 2];
        v49 = p[2 * v14 + 3];
        v15 = (float)(v28 * v49) - (float)(v29 * v30);
        v16 = (float)(v30 + v28) * v15;
        v17 = (float)(v29 + v49) * v15;
      }
      v31 = (float)(v13 + q) + v15;
      v50 = p[2 * n - 2];
      v52 = p[1];
      qa = (float)(v50 * v52) - (float)(p[2 * n - 1] * *p);
      maxdiff = (float)(v18 + v46) + v17;
      v51 = p[2 * n - 1];
      v47 = *p;
      if ( fabsf(qa + v31) <= 0.00000011920929 )
        v11 = 9.9999998e17;
      else
        v11 = *(float *)&clear_value / (float)((float)(qa + v31) * 3.0);
      v10 = (float)((float)(v50 + v47) * qa) + (float)((float)(v19 + v48) + v16);
      v12 = (float)((float)(v51 + v52) * qa) + maxdiff;
    }
    v9 = v12 * v11;
    v8 = v10 * v11;
  }
  v32 = 0;
  diff = v8;
  maxdiffa = v9;
  if ( n > 0 )
  {
    while ( 1 )
    {
      A[v32] = atan2f(p[2 * v32 + 1] - v9, p[2 * v32] - v8);
      if ( ++v32 >= n )
        break;
      v8 = diff;
      v9 = maxdiffa;
    }
  }
  v33 = 0;
  if ( n > 0 )
    memset32(avail, 1, n);
  v34 = i0;
  v35 = m;
  *iret = i0;
  v36 = 1;
  v37 = iret + 1;
  avail[i0] = 0;
  if ( m > 1 )
  {
    v38 = 6.2831855 / (float)m;
    v53 = A[i0];
    do
    {
      v39 = (float)((float)v36 * v38) + v53;
      a = v39;
      if ( v39 > 3.1415927 )
      {
        v39 = v39 - 6.2831855;
        a = v39;
      }
      maxdiffb = 1000000000.0;
      *v37 = v34;
      if ( n > 0 )
      {
        do
        {
          if ( avail[v33] )
          {
            v40 = fabsf(A[v33] - v39);
            if ( v40 <= 3.1415927 )
            {
              v41 = v40;
            }
            else
            {
              diffa = v40;
              v41 = 6.2831855 - diffa;
            }
            if ( maxdiffb > v41 )
            {
              maxdiffb = v41;
              *v37 = v33;
            }
            v39 = a;
          }
          ++v33;
        }
        while ( v33 < n );
        v38 = 6.2831855 / (float)m;
        v35 = m;
        v34 = i0;
      }
      v42 = *v37;
      v33 = 0;
      ++v36;
      ++v37;
      avail[v42] = 0;
    }
    while ( v36 < v35 );
  }
}
