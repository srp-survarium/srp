void __usercall get_gaussain_weights_offsets(
        float *out_weights@<ecx>,
        unsigned int buffer_size@<eax>,
        int a3@<edi>,
        float *out_offsets)
{
  unsigned int v4; // ebx
  float *v5; // esi
  float v6; // xmm1_4
  int v7; // edi
  long double v8; // [esp-4h] [ebp-20h]
  float v9; // [esp+10h] [ebp-Ch]
  float v10; // [esp+14h] [ebp-8h]
  float v11; // [esp+18h] [ebp-4h]

  v4 = 0;
  LODWORD(v8) = a3;
  v5 = out_weights;
  v6 = sqrt(1.570796370506287);
  v11 = s_bm_current_air_resistance / v6;
  v7 = (char *)out_offsets - (char *)out_weights;
  v10 = 1.0 / (double)buffer_size;
  do
  {
    v9 = (double)v4 - 4.0;
    *(float *)((char *)v5 + v7) = v9 * v10;
    __libm_sse2_exp(v8);
    *v5 = (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v9 * 0.25) * (float)(v9 * 0.25)) ^ _mask__NegFloat_)
                        * 2.0)
                * v11)
        * 0.5;
    ++v4;
    ++v5;
  }
  while ( v4 < 9 );
}
