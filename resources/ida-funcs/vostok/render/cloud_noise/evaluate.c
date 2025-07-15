float __usercall vostok::render::cloud_noise::evaluate@<xmm0>(float x, float y, unsigned int num_octaves)
{
  unsigned int v3; // eax
  unsigned int v4; // edx
  float v5; // xmm0_4
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // edx
  signed int v9; // edi
  float v10; // ecx
  float v11; // xmm0_4
  signed int v12; // edi
  unsigned int v13; // ebp
  float v14; // xmm1_4
  int v15; // eax
  signed int v16; // edi
  unsigned int v17; // ebx
  unsigned int v18; // esi
  float v19; // xmm0_4
  float v20; // xmm1_4
  double v21; // st6
  float v22; // xmm0_4
  float result; // [esp+0h] [ebp-30h]
  float resulta; // [esp+0h] [ebp-30h]
  unsigned int octave_index[2]; // [esp+4h] [ebp-2Ch] BYREF
  float v26; // [esp+Ch] [ebp-24h]
  float v27; // [esp+10h] [ebp-20h]
  float v28; // [esp+14h] [ebp-1Ch]
  float v29; // [esp+18h] [ebp-18h]
  float v30; // [esp+1Ch] [ebp-14h]
  float v31; // [esp+20h] [ebp-10h]
  float v32; // [esp+24h] [ebp-Ch]
  float v33; // [esp+28h] [ebp-8h]
  float v34; // [esp+2Ch] [ebp-4h]

  octave_index[0] = 1;
  v3 = vostok::math::max<unsigned int>(&num_octaves, octave_index);
  v4 = 0;
  num_octaves = v3;
  result = 0.0;
  octave_index[0] = 0;
  if ( v3 )
  {
    while ( 1 )
    {
      if ( v4 )
      {
        v6 = 1;
        v5 = retry_to_increase_quality_period_sec;
        if ( v4 > 1 )
        {
          if ( (int)(v4 - 1) >= 8 )
          {
            v7 = ((v4 - 9) >> 3) + 1;
            v6 = 8 * v7 + 1;
            do
            {
              --v7;
              v5 = (float)((float)((float)((float)((float)((float)((float)(v5 * 2.0) * 2.0) * 2.0) * 2.0) * 2.0) * 2.0)
                         * 2.0)
                 * 2.0;
            }
            while ( v7 );
          }
          if ( v6 < v4 )
          {
            v8 = v4 - v6;
            do
            {
              --v8;
              v5 = v5 * 2.0;
            }
            while ( v8 );
          }
        }
      }
      else
      {
        v5 = *(float *)&clear_value;
      }
      *(float *)&octave_index[1] = v5;
      v9 = ~(~(LODWORD(v5) - 1) & 0x80000000) & LODWORD(v5);
      LODWORD(v26) = (v9 >> 31)
                   ^ ((158 - (unsigned __int8)(v9 >> 23) - 96 + 64) >> 31)
                   & (((v9 | 0xFF800000) << 8 >> (-98 - (v9 >> 23)))
                    - ((v9 >> 31) & ((v9 & (((1 << (-98 - (v9 >> 23) - 96)) - 1) >> 8)) == 0)));
      v26 = (float)LODWORD(v26);
      v27 = v26 * x;
      v10 = fabs(v26 * x);
      v28 = v26 * y;
      v26 = fabs(v26 * y);
      v11 = (float)(v10 - (float)(((int)v27 >> 31) ^ (((int)v27 >> 31) + (int)v27))) * 8.0;
      v29 = v11;
      v12 = ~(~(LODWORD(v11) - 1) & 0x80000000) & LODWORD(v11);
      v30 = v11;
      v13 = (v12 >> 31)
          ^ ((158 - (unsigned __int8)(v12 >> 23) - 96 + 64) >> 31)
          & (((v12 | 0xFF800000) << 8 >> (-98 - (v12 >> 23)))
           - ((v12 >> 31) & ((v12 & (((1 << (-98 - (v12 >> 23) - 96)) - 1) >> 8)) == 0)));
      v14 = (float)(COERCE_FLOAT(LODWORD(v28) & 0x7FFFFFFF) - (float)(((int)v28 >> 31) ^ (((int)v28 >> 31) + (int)v28)))
          * 8.0;
      v15 = v13 + 1;
      if ( v13 + 1 >= 7 )
        v15 = 7;
      v31 = (float)(COERCE_FLOAT(LODWORD(v28) & 0x7FFFFFFF) - (float)(((int)v28 >> 31) ^ (((int)v28 >> 31) + (int)v28)))
          * 8.0;
      v16 = ~(~(LODWORD(v14) - 1) & 0x80000000) & LODWORD(v14);
      v32 = v31;
      v18 = ((v16 >> 31)
           ^ ((158 - (unsigned __int8)(v16 >> 23) - 96 + 64) >> 31)
           & (((v16 | 0xFF800000) << 8 >> (-98 - (v16 >> 23)))
            - ((v16 >> 31) & ((v16 & (((1 << (-98 - (v16 >> 23) - 96)) - 1) >> 8)) == 0))))
          + 1;
      if ( v18 >= 7 )
        v18 = 7;
      v33 = v11;
      v34 = (float)(COERCE_FLOAT(LODWORD(v28) & 0x7FFFFFFF) - (float)(((int)v28 >> 31) ^ (((int)v28 >> 31) + (int)v28)))
          * 8.0;
      v26 = fabs(v34);
      v19 = COERCE_FLOAT(LODWORD(v11) & 0x7FFFFFFF) - (float)(((int)v11 >> 31) ^ (((int)v11 >> 31) + (int)v11));
      v20 = COERCE_FLOAT(LODWORD(v14) & 0x7FFFFFFF) - (float)(((int)v14 >> 31) ^ (((int)v14 >> 31) + (int)v14));
      v17 = (v16 >> 31)
          ^ ((158 - (unsigned __int8)(v16 >> 23) - 96 + 64) >> 31)
          & (((v16 | 0xFF800000) << 8 >> (-98 - (v16 >> 23)))
           - ((v16 >> 31) & ((v16 & (((1 << (-98 - (v16 >> 23) - 96)) - 1) >> 8)) == 0)));
      result = (float)((float)((float)((float)(aperiodic_noise_table[v17][v15] * v19)
                                     + (float)(aperiodic_noise_table[v17][v13] * (float)(*(float *)&clear_value - v19)))
                             * (float)(*(float *)&clear_value - v20))
                     + (float)((float)((float)(aperiodic_noise_table[v18][v15] * v19)
                                     + (float)(aperiodic_noise_table[v18][v13] * (float)(*(float *)&clear_value - v19)))
                             * v20))
             + result;
      if ( ++octave_index[0] >= num_octaves )
        break;
      v4 = octave_index[0];
    }
    v3 = num_octaves;
  }
  num_octaves = v3;
  v21 = result / (double)v3;
  if ( v21 <= 0.0 )
    return 0.0;
  v22 = v21;
  resulta = v21;
  if ( *(float *)&clear_value < resulta )
    return *(float *)&clear_value;
  return v22;
}
