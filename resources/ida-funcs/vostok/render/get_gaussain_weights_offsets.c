void __usercall vostok::render::get_gaussain_weights_offsets(
        float *out_offsets@<ecx>,
        unsigned int buffer_size@<eax>,
        long double a3@<esi:edi>,
        float *out_weights,
        float __formal,
        float bloom_kernel)
{
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float *v9; // esi
  int v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // eax
  float v13; // xmm0_4
  long double v14; // [esp-Ch] [ebp-20h]
  float v15; // [esp+0h] [ebp-14h]
  float v16; // [esp+4h] [ebp-10h]
  float v17; // [esp+8h] [ebp-Ch]
  float v18; // [esp+Ch] [ebp-8h]
  unsigned int v19; // [esp+10h] [ebp-4h]

  v19 = 0;
  v6 = bloom_kernel * 0.5;
  v18 = 0.0;
  v7 = s_bm_current_air_resistance;
  if ( __formal != 0.0 )
  {
    v14 = a3;
    v8 = s_bm_current_air_resistance / v6;
    v16 = s_bm_current_air_resistance / v6;
    v9 = out_weights;
    v10 = (char *)out_offsets - (char *)out_weights;
    v15 = 1.0 / (double)buffer_size;
    while ( 1 )
    {
      v17 = (float)v19;
      *(float *)((char *)v9 + v10) = (v17 - bloom_kernel) * v15;
      __libm_sse2_exp(v14);
      ++v19;
      v11 = (float)((float)((float)(v17 - bloom_kernel) * v8) * (float)((float)(v17 - bloom_kernel) * v8)) * -0.5;
      *v9++ = v11;
      v18 = v11 + v18;
      if ( v19 >= LODWORD(__formal) )
        break;
      v8 = v16;
    }
    v7 = s_bm_current_air_resistance;
  }
  v12 = 0;
  if ( __formal != 0.0 )
  {
    v13 = v7 / v18;
    do
    {
      out_weights[v12] = out_weights[v12] * v13;
      ++v12;
    }
    while ( v12 < LODWORD(__formal) );
  }
}
