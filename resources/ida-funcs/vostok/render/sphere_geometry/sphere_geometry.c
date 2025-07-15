void __userpurge vostok::render::sphere_geometry::sphere_geometry(
        vostok::render::sphere_geometry *this@<ecx>,
        __m128i a2@<xmm0>,
        _DWORD *num_sides,
        unsigned int num_rings,
        unsigned int a4)
{
  int v5; // ebx
  int v6; // eax
  void *v7; // esp
  void *v8; // esp
  void *v9; // esp
  int v10; // eax
  long double v11; // rdi
  long double *v12; // ecx
  __m128 v13; // xmm0
  __m128i v14; // xmm0
  float v15; // eax
  float v16; // xmm1_4
  float v17; // ecx
  int v18; // edx
  float *v19; // eax
  float v20; // xmm3_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  __int16 v24; // cx
  __int16 v25; // dx
  _WORD *v26; // edi
  __int16 v27; // cx
  __int16 v28; // dx
  vostok::render::res_declaration *declaration; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v30; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v31; // eax
  float v32; // [esp+0h] [ebp-98h]
  float v33; // [esp+0h] [ebp-98h]
  long double v34[2]; // [esp+4h] [ebp-94h] BYREF
  vostok::math::float4x4 v35; // [esp+14h] [ebp-84h] BYREF
  float v36; // [esp+58h] [ebp-40h]
  float v37; // [esp+5Ch] [ebp-3Ch]
  float v38; // [esp+60h] [ebp-38h]
  float v39; // [esp+64h] [ebp-34h]
  void *v40; // [esp+68h] [ebp-30h]
  int v41; // [esp+6Ch] [ebp-2Ch]
  int v42; // [esp+70h] [ebp-28h]
  long double *v43; // [esp+74h] [ebp-24h]
  float v44; // [esp+78h] [ebp-20h]
  long double *v45; // [esp+7Ch] [ebp-1Ch]
  float v46; // [esp+80h] [ebp-18h]
  float v47; // [esp+84h] [ebp-14h]
  void *data; // [esp+88h] [ebp-10h]
  float v49; // [esp+8Ch] [ebp-Ch]
  long double *v50; // [esp+90h] [ebp-8h]
  unsigned int v51; // [esp+A4h] [ebp+Ch]

  HIDWORD(v11) = num_sides;
  *num_sides = 0;
  num_sides[1] = 0;
  num_sides[2] = 0;
  v5 = 6 * a4 * num_rings;
  v41 = (num_rings + 1) * (a4 + 1);
  v6 = 24 * v41;
  num_sides[3] = 24;
  v7 = alloca(v6);
  data = v34;
  v42 = 24 * (a4 + 1);
  v8 = alloca(v42);
  v50 = v34;
  v45 = v34;
  v9 = alloca(12 * a4 * num_rings);
  v10 = a4 + 1;
  LODWORD(v11) = v34;
  v43 = v34;
  v40 = v34;
  if ( *(float *)&a4 != NAN )
  {
    a2 = (__m128i)LODWORD(SNaN);
    do
    {
      v12 = v50;
      v50 += 3;
      if ( v12 )
      {
        *((_DWORD *)v12 + 4) = a2.m128i_i32[0];
        *((_DWORD *)v12 + 5) = a2.m128i_i32[0];
      }
      --v10;
    }
    while ( v10 );
  }
  v50 = 0;
  if ( *(float *)&a4 != NAN )
  {
    v44 = *(float *)&a4;
    v46 = (float)a4;
    LODWORD(v49) = v45 + 1;
    do
    {
      v47 = (double)(unsigned int)v50 / v46;
      v13 = (__m128)LODWORD(v47);
      v13.m128_f32[0] = v47 * 3.1415927;
      v44 = v47 * 3.1415927;
      v14 = (__m128i)_mm_cvtps_pd(v13);
      __libm_sse2_sin(v14);
      *(float *)v14.m128i_i32 = *(double *)v14.m128i_i64;
      *(_DWORD *)(LODWORD(v49) - 8) = v14.m128i_i32[0];
      *(double *)v14.m128i_i64 = v44;
      __libm_sse2_cos(v34[0]);
      v15 = v49;
      v16 = s_bm_current_air_resistance;
      *(float *)(LODWORD(v49) + 12) = v47;
      v50 = (long double *)((char *)v50 + 1);
      *(float *)v14.m128i_i32 = *(double *)v14.m128i_i64;
      *(_DWORD *)(LODWORD(v15) - 4) = v14.m128i_i32[0];
      a2 = 0;
      *(_DWORD *)LODWORD(v15) = 0;
      *(float *)(LODWORD(v15) + 4) = v16;
      *(_DWORD *)(LODWORD(v15) + 8) = 0;
      LODWORD(v49) = LODWORD(v15) + 24;
    }
    while ( (unsigned int)v50 < a4 + 1 );
  }
  v17 = *(float *)&num_rings;
  v50 = 0;
  if ( *(float *)&num_rings != NAN )
  {
    v44 = *(float *)&num_rings;
    v46 = (float)num_rings;
    LODWORD(v49) = (char *)data + 20;
    do
    {
      v47 = (float)(unsigned int)v50;
      v32 = v47 * 6.2831855 / v46;
      vostok::math::create_rotation_y(v11, a2, &v35, v32);
      v18 = a4 + 1;
      v17 = v33;
      v44 = v47 / v46;
      if ( *(float *)&a4 != NAN )
      {
        v17 = v49;
        v39 = s_bm_current_air_resistance;
        v19 = (float *)v45 + 1;
        do
        {
          v20 = v19[1];
          v21 = *(v19 - 1);
          v22 = *v19;
          v23 = (float)((float)((float)(v35.i.y * v21) + (float)(v35.k.y * v20)) + (float)(v35.j.y * *v19)) + v35.c.y;
          v36 = (float)((float)((float)(v35.i.x * v21) + (float)(v35.k.x * v20)) + (float)(v35.j.x * *v19)) + v35.c.x;
          a2 = (__m128i)LODWORD(v44);
          v37 = v23;
          v38 = (float)((float)((float)(v35.i.z * v21) + (float)(v35.k.z * v20)) + (float)(v35.j.z * v22)) + v35.c.z;
          *(float *)(LODWORD(v17) - 20) = v36;
          *(float *)(LODWORD(v17) - 20 + 4) = v37;
          *(float *)(LODWORD(v17) - 20 + 8) = v38;
          *(_DWORD *)(LODWORD(v17) - 4) = a2.m128i_i32[0];
          *(float *)(LODWORD(v17) - 20 + 12) = v39;
          *(float *)LODWORD(v17) = v19[4];
          LODWORD(v17) += 24;
          v19 += 6;
          --v18;
        }
        while ( v18 );
        v11 = COERCE_DOUBLE(__PAIR64__((unsigned int)num_sides, (unsigned int)v43));
      }
      LODWORD(v49) += v42;
      v50 = (long double *)((char *)v50 + 1);
    }
    while ( (unsigned int)v50 < num_rings + 1 );
  }
  if ( *(float *)&num_rings != 0.0 )
  {
    v17 = *(float *)&a4;
    v49 = 0.0;
    v50 = (long double *)(a4 + 1);
    v45 = (long double *)num_rings;
    do
    {
      v51 = 0;
      if ( v17 != 0.0 )
      {
        do
        {
          v24 = LOWORD(v49);
          *(_WORD *)LODWORD(v11) = LOWORD(v49) + v51;
          v25 = (__int16)v50;
          v26 = (_WORD *)(LODWORD(v11) + 2);
          v27 = v24 + v51 + 1;
          *v26++ = v27;
          v28 = v51 + v25;
          *v26++ = v28;
          *v26++ = v28;
          *v26++ = v27;
          v17 = *(float *)&a4;
          *v26 = (_WORD)v50 + v51 + 1;
          LODWORD(v11) = v26 + 1;
          ++v51;
        }
        while ( v51 < a4 );
      }
      LODWORD(v49) += LODWORD(v17) + 1;
      v50 = (long double *)((char *)v50 + LODWORD(v17) + 1);
      v45 = (long double *)((char *)v45 - 1);
    }
    while ( v45 );
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  (vostok::render::resource_manager *)LODWORD(v17),
                  (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  sphere_geometry_vertex_layout,
                  2u);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)HIDWORD(v11),
    declaration);
  vostok::render::resource_manager::create_buffer(
    v41 * *(_DWORD *)(HIDWORD(v11) + 12),
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    *(void **)(HIDWORD(v11) + 12),
    (vostok::render::enum_buffer_type)data,
    0,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v30,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(HIDWORD(v11) + 4),
    (vostok::render::hw_buffer_pool *)HIDWORD(v11));
  vostok::render::resource_manager::create_buffer(
    2 * v5,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)v40,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v31,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(HIDWORD(v11) + 8),
    (vostok::render::hw_buffer_pool *)(HIDWORD(v11) + 8));
  num_sides[4] = v5;
}
