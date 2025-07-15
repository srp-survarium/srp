void __usercall get_gaussain_weights_offsets(
        float *out_weights@<ecx>,
        int buffer_size@<eax>,
        float a3@<edi>,
        float *out_offsets)
{
  unsigned int v4; // esi
  int v6; // ebx
  float v8; // [esp+4h] [ebp-20h]
  unsigned int v10; // [esp+18h] [ebp-Ch]
  float v11; // [esp+18h] [ebp-Ch]
  int v12; // [esp+20h] [ebp-4h]
  float v13; // [esp+20h] [ebp-4h]

  v4 = 0;
  v12 = buffer_size;
  __asm { fild    [esp+1Ch+var_4] }
  v8 = a3;
  if ( buffer_size < 0 )
    __asm { fadd    dword ptr ds:stru_984D24.m_working_macro_list.m_buffer.m_store+1074h }
  __asm { fld1 }
  __asm { fdivrp  st(1), st }
  __asm { fstp    [esp+20h+var_10] }
  vostok::math::max();
  sqrtf((float)(0.5 * 0.5) * 6.2831855);
  __asm
  {
    fld1
    fdivrp  st(1), st
  }
  v6 = (char *)out_offsets - (char *)out_weights;
  __asm { fstp    [esp+20h+var_4] }
  do
  {
    v10 = v4;
    __asm { fild    [esp+20h+var_C] }
    __asm
    {
      fsub    ds:__real@40800000
      fst     [esp+20h+var_C]
    }
    __asm { fmul    [esp+20h+var_10] }
    __asm { fstp    dword ptr [ebx+edi] }
    *(float *)((char *)out_weights + v6) = _ET1;
    expf(v8);
    *out_weights = (float)((float)((float)-(float)((float)(v11 * 0.25) * (float)(v11 * 0.25))
                                 / (float)((float)(0.5 * 0.5) * 2.0))
                         * v13)
                 * 0.5;
    ++v4;
    ++out_weights;
  }
  while ( v4 < 9 );
}
