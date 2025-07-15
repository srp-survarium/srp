void __usercall vostok::sound::panning_lut::panning_lut(
        vostok::sound::panning_lut *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>,
        _DWORD *a4@<esi>)
{
  _DWORD *v4; // ebx
  long double v5; // st7
  __m128i v6; // xmm0
  int v7; // eax
  int v8; // eax
  int v9; // edi
  float v10; // xmm0_4
  float v11; // xmm0_4
  long double v12; // [esp-8h] [ebp-6Ch]
  int v13; // [esp+0h] [ebp-64h]
  _DWORD v14[8]; // [esp+4h] [ebp-60h]
  float v15; // [esp+24h] [ebp-40h]
  _DWORD v16[8]; // [esp+28h] [ebp-3Ch]
  float v17; // [esp+48h] [ebp-1Ch]
  float v18; // [esp+4Ch] [ebp-18h]
  float v19; // [esp+50h] [ebp-14h]
  unsigned int v20; // [esp+54h] [ebp-10h]
  unsigned int v21; // [esp+58h] [ebp-Ch]
  int v22; // [esp+5Ch] [ebp-8h]
  unsigned __int8 v23; // [esp+63h] [ebp-1h]

  v15 = FLOAT_N1_5707964;
  v12 = COERCE_DOUBLE(__PAIR64__(a2, a3));
  *a4 = &vostok::sound::panning_lut::`vftable';
  v13 = 0;
  v14[0] = 1;
  *(float *)v16 = pi_d2_11;
  v20 = 0;
  v22 = 0;
  v21 = 0;
  v4 = a4 + 1;
  do
  {
    memset(v4, 0, 0x24u);
    v5 = vostok::sound::pos_to_angle(v20);
    v23 = 0;
    v19 = v5;
    v6 = (__m128i)LODWORD(v19);
    v7 = 0;
    while ( 1 )
    {
      v8 = v7;
      if ( v19 >= *(float *)&v16[v8 - 1] && *(float *)&v16[v8] > v19 )
        break;
      v7 = ++v23;
      if ( v23 )
        goto LABEL_8;
    }
    v9 = v23;
    v18 = (float)((float)(v19 - *(float *)&v16[v9 - 1]) * 1.5707964)
        / (float)(*(float *)&v16[v9] - *(float *)&v16[v9 - 1]);
    *(double *)v6.m128i_i64 = v18;
    __libm_sse2_cos(v12);
    *(float *)v6.m128i_i32 = *(double *)v6.m128i_i64;
    a4[v22 + 1 + v14[v9 - 1]] = v6.m128i_i32[0];
    *(double *)v6.m128i_i64 = v18;
    __libm_sse2_sin(v6);
    v10 = *(double *)v6.m128i_i64;
    *(float *)&a4[v22 + 1 + v14[v9]] = v10;
    v6 = (__m128i)LODWORD(v19);
LABEL_8:
    if ( v23 == 1 )
    {
      if ( *(float *)v6.m128i_i32 < -1.5707964 )
        *(float *)v6.m128i_i32 = *(float *)v6.m128i_i32 + 6.2831855;
      v17 = (float)(*(float *)v6.m128i_i32 - 1.5707964) * 0.5;
      *(double *)v6.m128i_i64 = v17;
      __libm_sse2_cos(v12);
      *(float *)v6.m128i_i32 = *(double *)v6.m128i_i64;
      a4[v22 + 2] = v6.m128i_i32[0];
      *(double *)v6.m128i_i64 = v17;
      __libm_sse2_sin(v6);
      v11 = *(double *)v6.m128i_i64;
      *(float *)&a4[v21 / 4 + 1] = v11;
    }
    v21 += 36;
    ++v20;
    v22 += 9;
    v4 += 9;
  }
  while ( v21 < 0x4800 );
}
