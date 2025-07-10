float __usercall vostok::render::calculate_streaming_texture_factor@<xmm0>(
        const vostok::math::float3 *positions,
        const vostok::math::float2 *uvs,
        unsigned int num_vertices,
        const unsigned __int16 *vertex_stride,
        unsigned int indices)
{
  stlp_std::priv::_Impl_vector<float,vostok::render::std_allocator<float> > *v5; // ecx
  const unsigned __int16 *v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // edi
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float *v12; // ebx
  float v13; // xmm1_4
  float v14; // xmm2_4
  long double v15; // st6
  float v16; // xmm0_4
  long double v17; // st6
  float v18; // xmm2_4
  float v19; // ecx
  float v20; // xmm0_4
  float *M_finish; // eax
  float *v22; // edi
  float *M_start; // ebx
  int v24; // esi
  int v25; // eax
  int v26; // ecx
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  const stlp_std::__true_type *v29; // [esp+4h] [ebp-48h]
  unsigned int v30; // [esp+8h] [ebp-44h]
  bool v31; // [esp+Ch] [ebp-40h]
  const unsigned __int16 *v32; // [esp+10h] [ebp-3Ch]
  float streaming_factor; // [esp+14h] [ebp-38h]
  float t1; // [esp+18h] [ebp-34h]
  float __x; // [esp+1Ch] [ebp-30h] BYREF
  unsigned int v36; // [esp+20h] [ebp-2Ch]
  float v37; // [esp+24h] [ebp-28h]
  float v38; // [esp+28h] [ebp-24h]
  float v39; // [esp+2Ch] [ebp-20h]
  float v40; // [esp+30h] [ebp-1Ch]
  __int64 l1; // [esp+34h] [ebp-18h]
  vostok::render::vector<float> texel_ratios; // [esp+40h] [ebp-Ch] BYREF

  memset(&texel_ratios, 0, sizeof(texel_ratios));
  stlp_std::priv::_Impl_vector<float,vostok::render::std_allocator<float>>::reserve(
    v5,
    (unsigned int)&texel_ratios,
    indices / 3);
  streaming_factor = 0.0;
  if ( indices / 3 )
  {
    v6 = vertex_stride + 1;
    v32 = vertex_stride + 1;
    v36 = indices / 3;
    while ( 1 )
    {
      v7 = num_vertices * *(v6 - 1);
      v8 = num_vertices * *v6;
      v9 = *(float *)((char *)&positions->y + v7) - *(float *)((char *)&positions->y + v8);
      v10 = *(float *)((char *)&positions->z + v7) - *(float *)((char *)&positions->z + v8);
      v11 = *(float *)((char *)&positions->x + v7) - *(float *)((char *)&positions->x + v8);
      v12 = (float *)((char *)&uvs->x + num_vertices * v6[1]);
      *(float *)&l1 = sqrtf((float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)(v11 * v11));
      v13 = *(float *)((char *)&uvs->y + v7);
      v38 = *(float *)((char *)&uvs->x + v7);
      v14 = (float)(v38 - *(float *)((char *)&uvs->x + v8)) * (float)(v38 - *(float *)((char *)&uvs->x + v8));
      v39 = v13;
      v15 = sqrtf(
              v14
            + (float)((float)(v13 - *(float *)((char *)&uvs->y + v8)) * (float)(v13 - *(float *)((char *)&uvs->y + v8))));
      v37 = v15;
      if ( v15 <= 0.0000099999997 )
        v16 = epsilon_5_210;
      else
        v16 = v37;
      t1 = v16;
      v17 = sqrtf(
              (float)((float)(v38 - *v12) * (float)(v38 - *v12))
            + (float)((float)(v39 - v12[1]) * (float)(v39 - v12[1])));
      v37 = v17;
      if ( v17 <= 0.0000099999997 )
        v18 = epsilon_5_210;
      else
        v18 = v37;
      v40 = v18 * v16;
      v19 = fabs(v18 * v16);
      v37 = v19;
      if ( v19 > 0.0000099999997 )
      {
        v20 = *(float *)&l1 / v16;
        if ( (float)(*(float *)&l1 / t1) <= (float)(*(float *)&l1 / v18) )
          v20 = *(float *)&l1 / v18;
        M_finish = texel_ratios._M_impl._M_finish;
        __x = v20;
        if ( texel_ratios._M_impl._M_finish == texel_ratios._M_impl._M_end_of_storage._M_data )
        {
          stlp_std::priv::_Impl_vector<float,vostok::render::std_allocator<float>>::_M_insert_overflow(
            &texel_ratios._M_impl,
            texel_ratios._M_impl._M_finish,
            (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)LODWORD(v19),
            &__x,
            v29,
            v30,
            v31);
        }
        else
        {
          *texel_ratios._M_impl._M_finish = v20;
          texel_ratios._M_impl._M_finish = M_finish + 1;
        }
      }
      v32 += 3;
      if ( !--v36 )
        break;
      v6 = v32;
    }
  }
  v22 = texel_ratios._M_impl._M_finish;
  M_start = texel_ratios._M_impl._M_start;
  v24 = texel_ratios._M_impl._M_finish - texel_ratios._M_impl._M_start;
  if ( v24 )
  {
    if ( texel_ratios._M_impl._M_start != texel_ratios._M_impl._M_finish )
    {
      v25 = texel_ratios._M_impl._M_finish - texel_ratios._M_impl._M_start;
      v26 = 0;
      if ( v24 != 1 )
      {
        do
        {
          v25 >>= 1;
          ++v26;
        }
        while ( v25 != 1 );
      }
      stlp_std::priv::__introsort_loop<float *,float,int,stlp_std::less<float>>(
        (stlp_std::less<float>)v24,
        texel_ratios._M_impl._M_start,
        texel_ratios._M_impl._M_finish,
        0,
        2 * v26,
        (float *)l1);
      stlp_std::priv::__final_insertion_sort<float *,stlp_std::less<float>>(M_start, v22, (stlp_std::less<float>)l1);
    }
    l1 = (__int64)((double)(unsigned int)v24 * -0.050000001);
    streaming_factor = M_start[-(_DWORD)l1];
  }
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (char *)M_start);
  }
  return streaming_factor;
}
