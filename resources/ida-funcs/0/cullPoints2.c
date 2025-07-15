void __usercall cullPoints2(float *p@<eax>, int n, int m, int i0, int *iret)
{
  int v5; // ecx
  float v7; // xmm1_4
  int v8; // edx
  float v9; // xmm7_4
  float *v10; // eax
  float v11; // xmm4_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm5_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  int v18; // edi
  float v19; // xmm0_4
  int v20; // esi
  int *v21; // ebx
  float v22; // xmm6_4
  float v23; // xmm1_4
  float v24; // xmm5_4
  int v25; // edx
  float v26; // xmm0_4
  int v27; // edx
  long double v28; // [esp+0h] [ebp-60h]
  long double v29; // [esp+8h] [ebp-58h]
  float v30; // [esp+18h] [ebp-48h]
  float v31; // [esp+1Ch] [ebp-44h]
  float v32; // [esp+1Ch] [ebp-44h]
  _DWORD v33[16]; // [esp+20h] [ebp-40h] BYREF

  v5 = n;
  if ( n == 1 )
  {
    v7 = p[1];
  }
  else if ( n == 2 )
  {
    v7 = (float)(p[3] + p[1]) * 0.5;
  }
  else
  {
    v8 = n - 1;
    v9 = 0.0;
    v30 = 0.0;
    v31 = 0.0;
    if ( n - 1 > 0 )
    {
      v10 = p + 3;
      do
      {
        v11 = *(v10 - 1);
        v12 = (float)(*(v10 - 3) * *v10) - (float)(*(v10 - 2) * v11);
        v13 = (float)((float)(*(v10 - 3) + v11) * v12) + v30;
        v14 = (float)((float)(*(v10 - 2) + *v10) * v12) + v31;
        v10 += 2;
        --v8;
        v9 = v12 + v9;
        v30 = v13;
        v31 = v14;
      }
      while ( v8 );
    }
    v15 = p[1];
    v16 = (float)(p[2 * n - 2] * v15) - (float)(p[2 * n - 1] * *p);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v16 + v9) & _mask__AbsFloat_) <= 0.00000011920929 )
      v17 = FLOAT_9_9999998e17;
    else
      v17 = s_bm_current_air_resistance / (float)((float)(v16 + v9) * 3.0);
    v7 = (float)((float)((float)(p[2 * n - 1] + v15) * v16) + v31) * v17;
  }
  v18 = 0;
  v32 = v7;
  if ( n > 0 )
  {
    while ( 1 )
    {
      v19 = p[2 * v18 + 1];
      __libm_sse2_atan2(v28, v29);
      *(float *)&v33[v18++ + 8] = v19 - v7;
      if ( v18 >= n )
        break;
      v7 = v32;
    }
    memset32(v33, 1, n);
    v5 = n;
  }
  *iret = i0;
  v20 = 1;
  v21 = iret + 1;
  v33[i0] = 0;
  if ( m > 1 )
  {
    v22 = *(float *)&v33[i0 + 8];
    do
    {
      v23 = (float)((float)v20 * (float)(6.2831855 / (float)m)) + v22;
      if ( v23 > 3.1415927 )
        v23 = v23 - 6.2831855;
      v24 = FLOAT_1_0e9;
      v25 = 0;
      for ( *v21 = i0; v25 < v5; ++v25 )
      {
        if ( v33[v25] )
        {
          LODWORD(v26) = COERCE_UNSIGNED_INT(*(float *)&v33[v25 + 8] - v23) & _mask__AbsFloat_;
          if ( v26 > 3.1415927 )
            v26 = 6.2831855 - v26;
          if ( v24 > v26 )
          {
            v24 = v26;
            *v21 = v25;
          }
        }
      }
      v27 = *v21++;
      ++v20;
      v33[v27] = 0;
    }
    while ( v20 < m );
  }
}
