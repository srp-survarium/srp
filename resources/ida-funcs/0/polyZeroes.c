int __cdecl polyZeroes(float *Poly, int deg, float a, int a_closed, float b, int b_closed, float *Roots)
{
  int v7; // ebx
  int v8; // esi
  int v9; // eax
  int v10; // ecx
  float i; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  int result; // eax
  int v15; // ecx
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  BOOL v19; // edx
  float v20; // xmm2_4
  int v21; // eax
  int v22; // xmm1_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  int v25; // edx
  float v26; // xmm0_4
  int v27; // eax
  float v28; // xmm2_4
  int v29; // ecx
  float *v30; // eax
  float v31; // xmm0_4
  float v32; // xmm2_4
  int v33; // eax
  float v34; // xmm3_4
  int v35; // xmm0_4
  int v36; // eax
  float v37; // xmm0_4
  float *v38; // eax
  float v39; // xmm2_4
  float Rootsa[22]; // [esp+24h] [ebp-13Ch] BYREF
  float Polya[22]; // [esp+7Ch] [ebp-E4h] BYREF
  float v42; // [esp+D4h] [ebp-8Ch] BYREF
  float v43[22]; // [esp+D8h] [ebp-88h]
  ag_polynomial v44; // [esp+130h] [ebp-30h] BYREF
  float v45; // [esp+138h] [ebp-28h]
  float v46; // [esp+13Ch] [ebp-24h]
  float v47; // [esp+140h] [ebp-20h]
  float v48; // [esp+144h] [ebp-1Ch]
  int v49; // [esp+148h] [ebp-18h]
  int v50; // [esp+14Ch] [ebp-14h]
  int v51; // [esp+150h] [ebp-10h]
  float j; // [esp+154h] [ebp-Ch]
  float k; // [esp+158h] [ebp-8h]
  float *v54; // [esp+16Ch] [ebp+Ch]

  v7 = deg;
  v8 = 0;
  v9 = deg + 1;
  v10 = 0;
  v46 = 0.0;
  k = 0.0;
  for ( i = 0.0; v10 < v9; i = COERCE_FLOAT(LODWORD(v12) & _mask__AbsFloat_) + i )
    v12 = Poly[v10++];
  v13 = (float)((float)(COERCE_FLOAT(LODWORD(a) & _mask__AbsFloat_) + COERCE_FLOAT(LODWORD(b) & _mask__AbsFloat_))
              * (float)v9)
      * sMachineTolerance;
  v45 = v13;
  if ( v13 >= i )
    return -1;
  v15 = 0;
  if ( v9 > 0 )
  {
    v16 = s_bm_current_air_resistance / i;
    do
    {
      v43[v15 - 1] = *(float *)((char *)&v43[v15 - 1] + (char *)Poly - (char *)&v42) * v16;
      ++v15;
    }
    while ( v15 < v9 );
  }
  while ( v13 > COERCE_FLOAT(LODWORD(v43[v7 - 1]) & _mask__AbsFloat_) )
    --v7;
  result = 0;
  if ( v7 )
  {
    result = 1;
    if ( v7 == 1 )
    {
      LODWORD(v17) = COERCE_UNSIGNED_INT(v42 / v43[0]) ^ _mask__NegFloat_;
      *Roots = v17;
      if ( a_closed )
        v18 = v17 + v13;
      else
        v18 = v17 - v13;
      v19 = v18 > a;
      if ( b_closed )
        v20 = v17 - v13;
      else
        v20 = v17 + v13;
      if ( v19 && b > v20 )
      {
        if ( a_closed && a > v17 )
        {
          *Roots = a;
        }
        else if ( b_closed )
        {
          if ( v17 > b )
            *Roots = b;
        }
        return result;
      }
      return 0;
    }
    v44.p = &v42;
    v44.deg = v7;
    if ( v7 >= 1 )
    {
      do
      {
        Rootsa[result + 21] = (float)result * v43[result - 1];
        ++result;
      }
      while ( result <= v7 );
    }
    v21 = polyZeroes(Polya, v7 - 1, a, 0, b, 0, Rootsa);
    v49 = v21;
    if ( v21 == -1 )
      return 0;
    v50 = 0;
    v51 = 0;
    if ( v21 >= 0 )
    {
      v22 = _mask__AbsFloat_;
      v23 = k;
      v24 = v45;
      v54 = Roots - 2;
      do
      {
        if ( v8 > v7 )
          break;
        v25 = v51;
        if ( v51 )
        {
          v28 = v46;
          j = v23;
        }
        else
        {
          v26 = v43[v7 - 1];
          v27 = v7 - 1;
          for ( j = a; v27 >= 0; v26 = (float)(v26 * a) + v43[v27] )
            --v27;
          v28 = v26;
          if ( v24 >= COERCE_FLOAT(LODWORD(v26) & v22) && a_closed )
          {
            Roots[v8++] = a;
            ++v54;
          }
        }
        if ( v25 == v49 )
        {
          v23 = b;
          v50 = 0;
        }
        else
        {
          v23 = Rootsa[v25];
        }
        v29 = v7 - 1;
        v30 = &v43[v7 - 1];
        v31 = *v30;
        for ( k = v23; v29 >= 0; v31 = (float)(v31 * v23) + v43[v29] )
          --v29;
        v46 = v31;
        if ( v50 )
        {
          v50 = 0;
        }
        else if ( v24 <= COERCE_FLOAT(LODWORD(v31) & v22) )
        {
          if ( v28 < 0.0 && v31 > 0.0 || v28 > 0.0 && v31 < 0.0 )
          {
            v32 = *v30;
            v33 = v7 - 1;
            v34 = v32;
            v47 = v32;
            if ( v7 - 1 >= 0 )
            {
              do
                v34 = (float)(v34 * j) + v43[--v33];
              while ( v33 >= 0 );
              v47 = v34;
            }
            if ( sMachineTolerance <= COERCE_FLOAT(LODWORD(v34) & v22) )
            {
              v36 = v7 - 1;
              v48 = v32;
              if ( v7 - 1 >= 0 )
              {
                do
                  v32 = (float)(v32 * v23) + v43[--v36];
                while ( v36 >= 0 );
                v48 = v32;
              }
              if ( sMachineTolerance <= COERCE_FLOAT(LODWORD(v32) & v22) )
              {
                v35 = ag_zeroin2(&v44, j, k, v47, v48);
                v22 = _mask__AbsFloat_;
                v23 = k;
                v24 = v45;
              }
              else
              {
                v35 = LODWORD(v23);
              }
            }
            else
            {
              v35 = LODWORD(j);
            }
            ++v54;
            LODWORD(Roots[v8++]) = v35;
            if ( v8 > 1 )
            {
              v37 = Roots[v8 - 1];
              v38 = v54;
              v39 = *v54;
              if ( *v54 >= (float)(v37 - v24) )
              {
                --v8;
                --v54;
                *v38 = (float)(v37 + v39) * 0.5;
              }
            }
          }
        }
        else if ( v25 != v49 || b_closed )
        {
          Roots[v8++] = v23;
          ++v54;
          v50 = 1;
        }
        ++v51;
      }
      while ( v51 <= v49 );
    }
    return v8;
  }
  return result;
}
