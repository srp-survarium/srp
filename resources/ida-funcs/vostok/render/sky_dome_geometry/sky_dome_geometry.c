void __usercall vostok::render::sky_dome_geometry::sky_dome_geometry(
        vostok::render::sky_dome_geometry *this@<ecx>,
        int a2@<eax>)
{
  void *v3; // esp
  void *v4; // esp
  float v5; // xmm0_4
  long double *v6; // edi
  int v7; // ecx
  int v8; // eax
  __m128 v9; // xmm0
  __m128i v10; // xmm0
  float *v11; // ebx
  double v12; // xmm0_8
  __m128i v13; // xmm0
  float v14; // xmm1_4
  __m128 v15; // xmm0
  __m128i v16; // xmm0
  float *v17; // ebx
  double v18; // xmm0_8
  __m128i v19; // xmm0
  float v20; // xmm1_4
  int v21; // eax
  _WORD *v22; // edi
  int v23; // eax
  vostok::render::resource_manager *v24; // ecx
  _WORD *v25; // edi
  vostok::render::res_declaration *declaration; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v27; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v28; // eax
  long double v29[315]; // [esp-21D8h] [ebp-2210h] BYREF
  _BYTE v30[6160]; // [esp-1800h] [ebp-1838h] BYREF
  void *v31; // [esp+10h] [ebp-28h]
  float v32; // [esp+14h] [ebp-24h]
  float v33; // [esp+18h] [ebp-20h]
  float v34; // [esp+1Ch] [ebp-1Ch]
  float v35; // [esp+20h] [ebp-18h]
  int v36; // [esp+24h] [ebp-14h]
  void *data; // [esp+28h] [ebp-10h]
  float v38; // [esp+2Ch] [ebp-Ch]
  int v39; // [esp+30h] [ebp-8h]
  int v40; // [esp+34h] [ebp-4h]

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 24;
  v3 = alloca(6144);
  data = v30;
  *(float *)&v39 = COERCE_FLOAT(v30);
  v4 = alloca(2520);
  v5 = SNaN;
  v6 = v29;
  v31 = v29;
  v7 = 256;
  do
  {
    v8 = v39;
    v39 += 24;
    if ( v8 )
    {
      *(float *)(v8 + 16) = v5;
      *(float *)(v8 + 20) = v5;
    }
    --v7;
  }
  while ( v7 );
  v9 = 0;
  v40 = 0;
  v38 = 0.0;
  do
  {
    v9.m128_f32[0] = (float)(v9.m128_f32[0] * 0.06666667) * 1.7453293;
    v35 = v9.m128_f32[0];
    *(float *)&v39 = 0.0;
    v10 = (__m128i)_mm_cvtps_pd(v9);
    __libm_sse2_cos(v29[0]);
    *(float *)v10.m128i_i32 = *(double *)v10.m128i_i64;
    v34 = *(float *)v10.m128i_i32;
    *(double *)v10.m128i_i64 = v35;
    __libm_sse2_sin(v10);
    *(float *)v10.m128i_i32 = *(double *)v10.m128i_i64;
    v36 = v10.m128i_i32[0];
    v32 = (float)(v38 * 0.0625) + 0.03125;
    v11 = (float *)((char *)data + 24 * v40 + 8);
    do
    {
      v33 = *(float *)&v39 * 0.44879895;
      v12 = (float)(*(float *)&v39 * 0.44879895);
      __libm_sse2_cos(v29[0]);
      *(float *)&v12 = v12;
      *(v11 - 2) = *(float *)&v12 * *(float *)&v36;
      v13 = (__m128i)LODWORD(v34);
      *(v11 - 1) = v34;
      *(double *)v13.m128i_i64 = v33;
      __libm_sse2_sin(v13);
      v14 = s_bm_current_air_resistance;
      ++v40;
      *(float *)v13.m128i_i32 = *(double *)v13.m128i_i64;
      *v11 = *(float *)v13.m128i_i32 * *(float *)&v36;
      v11[1] = v14;
      *(v11 - 2) = *(v11 - 2) * 10.0;
      *(v11 - 1) = *(v11 - 1) * 10.0;
      *v11 = *v11 * 10.0;
      *(float *)v13.m128i_i32 = v32;
      v11[1] = v11[1] * 10.0;
      v11[2] = *(float *)v13.m128i_i32;
      v11[3] = (float)(*(float *)&v39 * 0.125) + 0.0625;
      *(float *)&v39 = *(float *)&v39 + v14;
      v11 += 6;
    }
    while ( gran1 > *(float *)&v39 );
    v9 = (__m128)LODWORD(v38);
    v9.m128_f32[0] = v38 + v14;
    v38 = v9.m128_f32[0];
  }
  while ( v9.m128_f32[0] < 16.0 );
  v15 = 0;
  v38 = 0.0;
  do
  {
    v15.m128_f32[0] = (float)(v15.m128_f32[0] * 0.06666667) * 1.7453293;
    v32 = v15.m128_f32[0];
    *(float *)&v39 = 0.0;
    v16 = (__m128i)_mm_cvtps_pd(v15);
    __libm_sse2_cos(v29[0]);
    *(float *)v16.m128i_i32 = *(double *)v16.m128i_i64;
    v33 = *(float *)v16.m128i_i32;
    *(double *)v16.m128i_i64 = v32;
    __libm_sse2_sin(v16);
    *(float *)v16.m128i_i32 = *(double *)v16.m128i_i64;
    v36 = v16.m128i_i32[0];
    v35 = (float)(v38 * 0.0625) + 0.03125;
    v17 = (float *)((char *)data + 24 * v40 + 8);
    do
    {
      v34 = 6.2831855 - (float)(*(float *)&v39 * 0.44879895);
      v18 = v34;
      __libm_sse2_cos(v29[0]);
      *(float *)&v18 = v18;
      *(v17 - 2) = *(float *)&v18 * *(float *)&v36;
      v19 = (__m128i)LODWORD(v33);
      *(v17 - 1) = v33;
      *(double *)v19.m128i_i64 = v34;
      __libm_sse2_sin(v19);
      v20 = s_bm_current_air_resistance;
      ++v40;
      *(float *)v19.m128i_i32 = *(double *)v19.m128i_i64;
      *v17 = *(float *)v19.m128i_i32 * *(float *)&v36;
      v17[1] = v20;
      *(v17 - 2) = *(v17 - 2) * 10.0;
      *(v17 - 1) = *(v17 - 1) * 10.0;
      *v17 = *v17 * 10.0;
      *(float *)v19.m128i_i32 = v35;
      v17[1] = v17[1] * 10.0;
      v17[2] = *(float *)v19.m128i_i32;
      v17[3] = (float)(*(float *)&v39 * 0.125) + 0.0625;
      *(float *)&v39 = *(float *)&v39 + v20;
      v17 += 6;
    }
    while ( gran1 > *(float *)&v39 );
    v15 = (__m128)LODWORD(v38);
    v15.m128_f32[0] = v38 + v20;
    v38 = v15.m128_f32[0];
  }
  while ( v15.m128_f32[0] < 16.0 );
  v39 = 9;
  do
  {
    v21 = (unsigned __int16)v39;
    v36 = 7;
    do
    {
      *(_WORD *)v6 = v21 - 9;
      v22 = (_WORD *)v6 + 1;
      *v22++ = v21 - 1;
      *v22++ = v21;
      *v22++ = v21;
      *v22++ = v21 - 8;
      *v22 = v21 - 9;
      v6 = (long double *)(v22 + 1);
      ++v21;
      --v36;
    }
    while ( *(float *)&v36 != 0.0 );
    v39 += 8;
  }
  while ( (unsigned __int16)v39 < 0x81u );
  v39 = 137;
  do
  {
    v23 = (unsigned __int16)v39;
    v36 = 7;
    do
    {
      v24 = (vostok::render::resource_manager *)(v23 - 9);
      *(_WORD *)v6 = v23 - 9;
      v25 = (_WORD *)v6 + 1;
      *v25++ = v23;
      *v25++ = v23 - 1;
      *v25++ = v23 - 8;
      *v25++ = v23;
      *v25 = v23 - 9;
      v6 = (long double *)(v25 + 1);
      ++v23;
      --v36;
    }
    while ( *(float *)&v36 != 0.0 );
    v39 += 8;
  }
  while ( (unsigned __int16)v39 < 0x101u );
  declaration = vostok::render::resource_manager::create_declaration(
                  v24,
                  (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  vertex_layout,
                  2u);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2,
    declaration);
  vostok::render::resource_manager::create_buffer(
    *(_DWORD *)(a2 + 12) << 8,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    *(void **)(a2 + 12),
    (vostok::render::enum_buffer_type)data,
    0,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v27,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 4),
    (vostok::render::hw_buffer_pool *)a2);
  vostok::render::resource_manager::create_buffer(
    0x9D8u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)v31,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v28,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 8),
    (vostok::render::hw_buffer_pool *)a2);
  *(_DWORD *)(a2 + 16) = 1260;
}
