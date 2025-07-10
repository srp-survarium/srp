void __thiscall vostok::render::stage_postprocess::process_blur(
        vostok::render::stage_postprocess *this,
        vostok::render::stage_postprocess *rt0,
        vostok::render::render_target *t0,
        vostok::render::res_texture *rt1,
        vostok::render::render_target *t1,
        vostok::render::res_texture *kernel_index,
        unsigned int kernel_indexa)
{
  float v7; // edx
  double m_height; // st7
  int v9; // esi
  void *v10; // esp
  unsigned int *v11; // edi
  void *v12; // esp
  void *v13; // esp
  void *v14; // esp
  double v15; // st7
  void *v16; // esp
  unsigned int v17; // ebx
  unsigned int *v18; // eax
  unsigned int *v19; // ecx
  _DWORD *v20; // edx
  float v21; // xmm0_4
  float v22; // edi
  int v23; // ebx
  char *v24; // ebx
  unsigned int v25; // ebx
  unsigned int v26; // xmm0_4
  unsigned int v27; // xmm3_4
  unsigned int v28; // xmm2_4
  unsigned int v29; // ebx
  unsigned int *v30; // eax
  char *v31; // edx
  unsigned int *v32; // ecx
  char *v33; // edi
  unsigned int v34; // esi
  int v35; // ebx
  unsigned int v36; // xmm1_4
  unsigned int v37; // xmm2_4
  unsigned int v38; // xmm3_4
  _DWORD *v39; // eax
  int v40; // ecx
  const char *m_conflicted_key_name; // esi
  const char *v42; // esi
  DXGI_FORMAT m_blur_offsets_weights; // eax
  unsigned __int16 v44; // cx
  vostok::render::backend *v45; // ecx
  _DWORD *v46; // eax
  const char *v47; // esi
  const char *v48; // esi
  DXGI_FORMAT v49; // eax
  unsigned __int16 v50; // cx
  vostok::render::render_target *v51; // [esp-4h] [ebp-60h]
  unsigned int v52[3]; // [esp+4h] [ebp-58h] BYREF
  unsigned int v53[3]; // [esp+8h] [ebp-54h] BYREF
  unsigned __int64 v54; // [esp+10h] [ebp-4Ch]
  unsigned __int64 v55; // [esp+18h] [ebp-44h]
  unsigned int *v56; // [esp+20h] [ebp-3Ch]
  int buffer_size[3]; // [esp+24h] [ebp-38h] BYREF
  char *v58; // [esp+30h] [ebp-2Ch]
  char *v59; // [esp+34h] [ebp-28h]
  int v60; // [esp+38h] [ebp-24h]
  int t_w; // [esp+3Ch] [ebp-20h]
  float bloom_radius; // [esp+40h] [ebp-1Ch]
  int t_h; // [esp+44h] [ebp-18h]
  int v64; // [esp+48h] [ebp-14h]
  unsigned int *v65; // [esp+4Ch] [ebp-10h]
  float *out_weights; // [esp+50h] [ebp-Ch]
  float *out_offsets; // [esp+54h] [ebp-8h]
  unsigned int i; // [esp+58h] [ebp-4h]

  vostok::render::backend::flush_rt_shader_resources(
    (vostok::render::backend *)this,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v7 = *(float *)&t0->m_height;
  *(float *)&t_w = (float)t0->m_width;
  m_height = (double)(int)t0->m_height;
  if ( v7 < 0.0 )
    m_height = m_height + 4294967300.0;
  *(float *)&t_h = m_height;
  v9 = supported_kernels[kernel_indexa];
  v10 = alloca(4 * v9);
  v11 = v52;
  v56 = v52;
  v12 = alloca(4 * v9);
  out_offsets = (float *)v52;
  v13 = alloca(4 * v9);
  out_weights = (float *)v52;
  v14 = alloca(4 * v9);
  v65 = v52;
  bloom_radius = (double)(unsigned int)(v9 - 1) * 0.5;
  v15 = *(float *)&t_w;
  t_w = HIWORD(i) | 0xC00;
  *(_QWORD *)buffer_size = (__int64)v15;
  vostok::render::get_gaussain_weights_offsets(
    (__int64)v15,
    COERCE_FLOAT(v52),
    (float *)v52,
    (float *)v52,
    v9,
    bloom_radius);
  t_w = HIWORD(i) | 0xC00;
  *(_QWORD *)buffer_size = (__int64)*(float *)&t_h;
  vostok::render::get_gaussain_weights_offsets(
    buffer_size[0],
    COERCE_FLOAT(v52),
    out_weights,
    (float *)v52,
    v9,
    bloom_radius);
  v16 = alloca(16 * v9);
  v17 = 0;
  bloom_radius = COERCE_FLOAT(v52);
  i = 0;
  if ( v9 >= 4 )
  {
    t_h = (char *)out_offsets - (char *)v52;
    v64 = (char *)v65 - (char *)v52;
    v18 = (unsigned int *)buffer_size;
    v19 = v53;
    v60 = (char *)out_weights - (char *)v52;
    v59 = (char *)((char *)out_offsets - (char *)v65);
    v17 = i;
    t_w = (int)(out_weights + 3);
    v58 = (char *)((char *)out_weights - (char *)v65);
    v20 = v65 + 2;
    buffer_size[1] = (char *)out_offsets - (char *)out_weights;
    do
    {
      v21 = out_offsets[v17];
      v22 = *(float *)&t_w;
      v23 = t_h;
      *(float *)&v54 = v21;
      HIDWORD(v54) = *(v19 - 1);
      LODWORD(v55) = *(v20 - 2);
      HIDWORD(v55) = *(_DWORD *)(t_w - 12);
      *((_QWORD *)v18 - 4) = v54;
      *((_QWORD *)v18 - 3) = v55;
      LODWORD(v54) = *(unsigned int *)((char *)v19 + v23);
      HIDWORD(v54) = *v19;
      LODWORD(v55) = *(unsigned int *)((char *)v19 + v64);
      v24 = v59;
      HIDWORD(v55) = *(unsigned int *)((char *)v19 + v60);
      *((_QWORD *)v18 - 2) = v54;
      *((_QWORD *)v18 - 1) = v55;
      LODWORD(v54) = *(_DWORD *)((char *)v20 + (_DWORD)v24);
      HIDWORD(v54) = v19[1];
      LODWORD(v55) = *v20;
      v25 = buffer_size[1];
      HIDWORD(v55) = *(_DWORD *)((char *)v20 + (_DWORD)v58);
      *(_QWORD *)v18 = v54;
      *((_QWORD *)v18 + 1) = v55;
      v26 = *(_DWORD *)(v25 + LODWORD(v22));
      v27 = *(_DWORD *)LODWORD(v22);
      v28 = v20[1];
      v29 = i;
      v54 = __PAIR64__(v19[2], v26);
      *((_QWORD *)v18 + 2) = v54;
      v55 = __PAIR64__(v27, v28);
      v17 = v29 + 4;
      t_w = LODWORD(v22) + 16;
      *((_QWORD *)v18 + 3) = __PAIR64__(v27, v28);
      v19 += 4;
      v20 += 4;
      v18 += 16;
      i = v17;
    }
    while ( v17 < v9 - 3 );
    v11 = v56;
  }
  if ( v17 < v9 )
  {
    t_h = (char *)out_offsets - (char *)v11;
    v64 = (char *)v65 - (char *)v11;
    v30 = &v52[4 * v17];
    v31 = (char *)((char *)out_weights - (char *)v11);
    v32 = &v11[v17];
    v33 = (char *)((char *)out_offsets - (char *)v11);
    v34 = v9 - v17;
    v35 = v64;
    do
    {
      v36 = *v32;
      v37 = *(unsigned int *)((char *)v32 + v35);
      v38 = *(unsigned int *)((char *)v32 + (_DWORD)v31);
      LODWORD(v54) = *(unsigned int *)((char *)v32 + (_DWORD)v33);
      HIDWORD(v54) = v36;
      *(_QWORD *)v30 = v54;
      v55 = __PAIR64__(v38, v37);
      *((_QWORD *)v30 + 1) = __PAIR64__(v38, v37);
      ++v32;
      v30 += 4;
      --v34;
    }
    while ( v34 );
  }
  v39 = &rt0->m_sh_blur[kernel_indexa].m_object->__vftable;
  v40 = (v39[71] - v39[70]) >> 2;
  if ( v40 )
  {
    v39[69] = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v40, v52[0]);
  }
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)m_conflicted_key_name + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                              (vostok::render::textures_handler<0> *)v40,
                                              (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                            + 1488,
                                              (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                                              rt1);
  v42 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  m_blur_offsets_weights = (DXGI_FORMAT)rt0->m_blur_offsets_weights;
  if ( *(_DWORD *)(m_blur_offsets_weights + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                   + 573) )
  {
    v44 = *(_WORD *)(m_blur_offsets_weights + 20);
    if ( v44 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(m_blur_offsets_weights + 22),
        (unsigned __int8)*(_WORD *)(m_blur_offsets_weights + 16) * *(unsigned __int16 *)(m_blur_offsets_weights + 18),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * v44),
        (const char *)LODWORD(bloom_radius));
  }
  ++*((_DWORD *)v42 + 23);
  v51 = 0;
  if ( t1 )
  {
    v51 = t1;
    ++t1->m_reference_count;
  }
  vostok::render::stage_postprocess::fill_surface(
    (vostok::render::stage_postprocess *)t1,
    rt0,
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v51,
    0);
  vostok::render::backend::flush_rt_shader_resources(
    v45,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v46 = &rt0->m_sh_blur[kernel_indexa].m_object->__vftable;
  if ( (unsigned int)((v46[71] - v46[70]) >> 2) > 1 )
  {
    v46[69] = 1;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)kernel_indexa, v52[0]);
  }
  v47 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v47 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                            (vostok::render::textures_handler<0> *)kernel_index,
                            (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                          + 1488,
                            (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                            kernel_index);
  v48 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v49 = (DXGI_FORMAT)rt0->m_blur_offsets_weights;
  if ( *(_DWORD *)(v49 + 40) == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                + 573) )
  {
    v50 = *(_WORD *)(v49 + 20);
    if ( v50 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *(unsigned __int16 *)(v49 + 22),
        (unsigned __int8)*(_WORD *)(v49 + 16) * *(unsigned __int16 *)(v49 + 18),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * v50),
        (const char *)LODWORD(bloom_radius));
  }
  ++*((_DWORD *)v48 + 23);
  ++t0->m_reference_count;
  vostok::render::stage_postprocess::fill_surface(
    (vostok::render::stage_postprocess *)t0,
    rt0,
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)t0,
    0);
}
