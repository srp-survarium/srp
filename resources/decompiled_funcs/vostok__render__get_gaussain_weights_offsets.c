void __usercall vostok::render::get_gaussain_weights_offsets(
        int buffer_size@<eax>,
        float a2@<edi>,
        float *out_weights,
        float *out_offsets,
        int __formal,
        float bloom_kernel)
{
  float v6; // xmm0_4
  const vostok::math::float4x4 *v7; // xmm1_4
  int v9; // esi
  float *v10; // edi
  float v11; // xmm1_4
  int v12; // ebp
  float v13; // xmm0_4
  unsigned int v15; // ecx
  unsigned int v16; // edx
  float v17; // xmm2_4
  float *v18; // eax
  float v19; // xmm1_4
  float v20; // [esp-10h] [ebp-1Ch]
  float v21; // [esp+0h] [ebp-Ch]
  int v23; // [esp+8h] [ebp-4h]
  int v24; // [esp+8h] [ebp-4h]
  float v25; // [esp+8h] [ebp-4h]
  float sum; // [esp+18h] [ebp+Ch]

  v6 = 0.0;
  v7 = clear_value;
  v9 = 0;
  v20 = a2;
  sum = 0.0;
  if ( *(float *)&__formal != 0.0 )
  {
    v23 = buffer_size;
    __asm { fild    [esp+1Ch+var_4] }
    if ( buffer_size < 0 )
      __asm { fadd    dword ptr ds:stru_984D24.m_working_macro_list.m_buffer.m_store+1074h }
    __asm { fld1 }
    v10 = out_weights;
    __asm { fdivrp  st(1), st }
    v11 = *(float *)&clear_value / (float)(bloom_kernel * 0.5);
    v21 = v11;
    __asm { fstp    [esp+1Ch+var_8] }
    while ( 1 )
    {
      v24 = v9;
      __asm { fild    [esp+1Ch+var_4] }
      if ( v9 < 0 )
        __asm { fadd    dword ptr ds:stru_984D24.m_working_macro_list.m_buffer.m_store+1074h }
      __asm
      {
        fst     [esp+1Ch+var_4]
        fsub    [esp+1Ch+bloom_kernel]
      }
      __asm { fmul    [esp+1Ch+var_8] }
      v13 = (float)((float)((float)(v25 - bloom_kernel) * v11) * (float)((float)(v25 - bloom_kernel) * v11)) * -0.5;
      __asm { fstp    dword ptr [edi+ebp] }
      v12 = (char *)out_offsets - (char *)out_weights;
      *(float *)((char *)v10 + v12) = _ET1;
      expf(v20);
      *v10 = v13;
      v6 = v13 + sum;
      ++v9;
      ++v10;
      sum = v6;
      if ( v9 >= (unsigned int)__formal )
        break;
      v11 = v21;
    }
    v7 = clear_value;
  }
  v15 = 0;
  if ( __formal >= 4 )
  {
    v16 = ((unsigned int)(__formal - 4) >> 2) + 1;
    v17 = *(float *)&v7 / v6;
    v18 = out_weights + 2;
    v15 = 4 * v16;
    do
    {
      *(v18 - 2) = *(v18 - 2) * v17;
      *(v18 - 1) = v17 * *(v18 - 1);
      *v18 = *v18 * v17;
      v18[1] = v17 * v18[1];
      v18 += 4;
      --v16;
    }
    while ( v16 );
  }
  if ( v15 < __formal )
  {
    v19 = *(float *)&v7 / v6;
    do
    {
      out_weights[v15] = out_weights[v15] * v19;
      ++v15;
    }
    while ( v15 < __formal );
  }
}
