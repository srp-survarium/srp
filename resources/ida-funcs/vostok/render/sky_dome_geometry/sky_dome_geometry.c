void __thiscall vostok::render::sky_dome_geometry::sky_dome_geometry(
        vostok::render::sky_dome_geometry *this,
        vostok::render::sky_dome_geometry *thisa)
{
  void *v2; // esp
  _BYTE *v3; // edi
  float *v4; // ebx
  void *v5; // esp
  float v6; // xmm0_4
  _BYTE *v7; // esi
  int v8; // ecx
  float *v9; // eax
  int v10; // ebx
  int v11; // edi
  long double v12; // st7
  long double v13; // st7
  long double v14; // st7
  long double v15; // st7
  const vostok::math::float4x4 *v16; // xmm1_4
  void **v17; // xmm0_4
  float v18; // xmm0_4
  float *v19; // edi
  long double v20; // st7
  long double v21; // st7
  long double v22; // st7
  long double v23; // st7
  const vostok::math::float4x4 *v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  unsigned __int16 k; // di
  int v28; // eax
  int v29; // edx
  _WORD *v30; // esi
  float v31; // eax
  int p_m_movie; // edi
  _WORD *v33; // esi
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v35; // ecx
  vostok::render::sky_dome_geometry *v36; // ebx
  vostok::render::res_declaration *m_object; // eax
  bool v38; // zf
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v40; // ecx
  vostok::render::untyped_buffer *v41; // esi
  vostok::render::resource_manager *v42; // edx
  survarium::game *m_game; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *m_movie; // ecx
  ID3D11Buffer *m_hardware_buffer; // eax
  char *v46; // eax
  malloc_state *v47; // esi
  vostok::render::untyped_buffer *v48; // eax
  vostok::render::untyped_buffer *v49; // ecx
  vostok::render::untyped_buffer *v50; // esi
  survarium::game *v51; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **v52; // edi
  survarium::options_tab *v53; // ebx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v54; // ecx
  ID3D11Buffer *v55; // eax
  vostok::render::grass_render_model *v56; // edi
  char *v57; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  _BYTE v59[2520]; // [esp+4h] [ebp-220Ch] BYREF
  _BYTE v60[6160]; // [esp+9DCh] [ebp-1834h] BYREF
  void **v61; // [esp+21ECh] [ebp-24h]
  void **__first; // [esp+21F0h] [ebp-20h]
  float move_y; // [esp+21F4h] [ebp-1Ch]
  float v64; // [esp+21F8h] [ebp-18h]
  float move_xz; // [esp+21FCh] [ebp-14h]
  void *data; // [esp+2200h] [ebp-10h]
  float j; // [esp+2204h] [ebp-Ch]
  float i; // [esp+2208h] [ebp-8h]
  stlp_std::__true_type __formal; // [esp+220Fh] [ebp-1h]

  thisa->m_vertext_declaration.m_object = 0;
  thisa->m_vertex_buffer.m_object = 0;
  thisa->m_index_buffer.m_object = 0;
  thisa->m_stride = 24;
  v2 = alloca(6144);
  v3 = v60;
  data = v60;
  v4 = (float *)v60;
  v5 = alloca(2520);
  v6 = SNaN;
  v7 = v59;
  v61 = (void **)v59;
  v8 = 256;
  do
  {
    v9 = v4;
    v4 += 6;
    if ( v9 )
    {
      v9[4] = v6;
      v9[5] = v6;
    }
    --v8;
  }
  while ( v8 );
  v10 = 0;
  i = 0.0;
  while ( 1 )
  {
    j = 0.0;
    move_xz = i * 0.06666667 * 1.7453293;
    v64 = cosf(move_xz);
    move_xz = sinf(move_xz);
    *(float *)&__first = (float)(i * 0.0625) + 0.03125;
    v11 = (int)&v3[24 * v10 + 8];
    do
    {
      move_y = j * 0.44879895;
      v12 = cosf(move_y);
      v13 = v12 * move_xz;
      *(float *)(v11 - 4) = v64;
      *(float *)(v11 - 8) = v13;
      v14 = sinf(move_y);
      v15 = v14 * move_xz;
      v16 = clear_value;
      *(_DWORD *)(v11 + 4) = clear_value;
      *(float *)v11 = v15;
      *(float *)(v11 - 8) = *(float *)(v11 - 8) * 10.0;
      *(float *)(v11 - 4) = *(float *)(v11 - 4) * 10.0;
      *(float *)v11 = *(float *)v11 * 10.0;
      v17 = __first;
      *(float *)(v11 + 4) = *(float *)(v11 + 4) * 10.0;
      *(_DWORD *)(v11 + 8) = v17;
      v18 = j;
      *(float *)(v11 + 12) = (float)(j * 0.125) + 0.0625;
      ++v10;
      v11 += 24;
      j = v18 + *(float *)&v16;
    }
    while ( (float)(v18 + *(float *)&v16) < 8.0 );
    i = i + *(float *)&v16;
    if ( i >= 16.0 )
      break;
    v3 = data;
  }
  i = 0.0;
  do
  {
    j = 0.0;
    *(float *)&__first = i * 0.06666667 * 1.7453293;
    move_y = cosf(*(float *)&__first);
    move_xz = sinf(*(float *)&__first);
    v64 = (float)(i * 0.0625) + 0.03125;
    v19 = (float *)((char *)data + 24 * v10 + 8);
    do
    {
      *(float *)&__first = 6.2831855 - j * 0.44879895;
      v20 = cosf(*(float *)&__first);
      v21 = v20 * move_xz;
      *(v19 - 1) = move_y;
      *(v19 - 2) = v21;
      v22 = sinf(*(float *)&__first);
      v23 = v22 * move_xz;
      v24 = clear_value;
      *((_DWORD *)v19 + 1) = clear_value;
      *v19 = v23;
      *(v19 - 2) = *(v19 - 2) * 10.0;
      *(v19 - 1) = *(v19 - 1) * 10.0;
      *v19 = *v19 * 10.0;
      v25 = v64;
      v19[1] = v19[1] * 10.0;
      v19[2] = v25;
      v26 = j;
      v19[3] = (float)(j * 0.125) + 0.0625;
      ++v10;
      v19 += 6;
      j = v26 + *(float *)&v24;
    }
    while ( (float)(v26 + *(float *)&v24) < 8.0 );
    i = i + *(float *)&v24;
  }
  while ( i < 16.0 );
  for ( k = 9; k < 0x81u; k += 8 )
  {
    v28 = k;
    v29 = 7;
    do
    {
      v30 = v7 + 2;
      *(v30 - 1) = v28 - 9;
      *v30++ = v28 - 1;
      *v30++ = v28;
      *v30++ = v28;
      *v30++ = v28 - 8;
      *v30 = v28 - 9;
      v7 = v30 + 1;
      ++v28;
      --v29;
    }
    while ( v29 );
  }
  LOWORD(v31) = 137;
  LODWORD(move_xz) = 137;
  do
  {
    LODWORD(v31) = LOWORD(v31);
    p_m_movie = 7;
    do
    {
      v33 = v7 + 2;
      *(v33 - 1) = LOWORD(v31) - 9;
      *v33 = LOWORD(v31);
      v33 += 2;
      *(v33 - 1) = LOWORD(v31) - 8 + 7;
      *v33++ = LOWORD(v31) - 8;
      *v33++ = LOWORD(v31);
      *v33 = LOWORD(v31) - 9;
      v7 = v33 + 1;
      ++LODWORD(v31);
      --p_m_movie;
    }
    while ( p_m_movie );
    LODWORD(v31) = LODWORD(move_xz) + 8;
    move_xz = v31;
  }
  while ( LOWORD(v31) < 0x101u );
  declaration = vostok::render::resource_manager::create_declaration(
                  2u,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (stlp_std::forward_iterator_tag *)vertex_layout);
  v35 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v35 = declaration;
  }
  v36 = thisa;
  m_object = thisa->m_vertext_declaration.m_object;
  thisa->m_vertext_declaration.m_object = v35;
  if ( m_object )
  {
    v38 = m_object->m_reference_count-- == 1;
    if ( v38 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  buffer = vostok::render::resource_manager::create_buffer(
             thisa->m_stride << 8,
             0,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             data,
             enum_buffer_type_vertex,
             0,
             0);
  v40 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v40 = buffer;
  }
  v41 = thisa->m_vertex_buffer.m_object;
  thisa->m_vertex_buffer.m_object = v40;
  if ( v41 )
  {
    v38 = v41->m_reference_count-- == 1;
    if ( v38 )
    {
      v42 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game;
      m_movie = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_movie;
      p_m_movie = (int)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_movie;
      move_y = *(float *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( m_game == (survarium::game *)m_movie )
        goto LABEL_41;
      while ( (vostok::render::untyped_buffer *)m_game->vostok::engine_user::world::__vftable != v41 )
      {
        m_game = (survarium::game *)((char *)m_game + 4);
        if ( m_game == (survarium::game *)m_movie )
          goto LABEL_41;
      }
      __first = (void **)&m_game->survarium::scaleform_game_engine::__vftable;
      if ( &m_game->survarium::scaleform_game_engine != (survarium::scaleform_game_engine *)m_movie )
      {
        __formal = 0;
        stlp_std::priv::__copy_ptrs<void * *,void * *>(
          __first,
          (void **)&m_movie->m_object,
          (void **)&m_game->vostok::engine_user::world::__vftable);
      }
      *(_DWORD *)p_m_movie -= 4;
      *(_DWORD *)(LODWORD(move_y) + 40) -= v41->m_size;
      m_hardware_buffer = v41->m_hardware_buffer;
      p_m_movie = (int)vostok::render::g_allocator.m_object;
      if ( m_hardware_buffer )
      {
        m_hardware_buffer->Release(v41->m_hardware_buffer);
        v41->m_hardware_buffer = 0;
      }
      v46 = (char *)v41;
      v47 = *(malloc_state **)(p_m_movie + 20);
      *(_BYTE *)(p_m_movie + 42) = 0;
      vostok_mspace_free(v47, v46);
    }
  }
  v42 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
LABEL_41:
  v48 = vostok::render::resource_manager::create_buffer(0x9D8u, p_m_movie, v42, v61, enum_buffer_type_index, 0, 0);
  v49 = 0;
  if ( v48 )
  {
    ++v48->m_reference_count;
    v49 = v48;
  }
  v50 = thisa->m_index_buffer.m_object;
  thisa->m_index_buffer.m_object = v49;
  if ( v50 )
  {
    v38 = v50->m_reference_count-- == 1;
    if ( v38 )
    {
      v51 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game;
      v52 = &`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_movie;
      v53 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      v54 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_movie;
      if ( v51 != (survarium::game *)v54 )
      {
        while ( (vostok::render::untyped_buffer *)v51->vostok::engine_user::world::__vftable != v50 )
        {
          v51 = (survarium::game *)((char *)v51 + 4);
          if ( v51 == (survarium::game *)v54 )
            goto LABEL_54;
        }
        v61 = (void **)&v51->survarium::scaleform_game_engine::__vftable;
        if ( &v51->survarium::scaleform_game_engine != (survarium::scaleform_game_engine *)v54 )
        {
          __formal = 0;
          stlp_std::priv::__copy_ptrs<void * *,void * *>(
            v61,
            (void **)&v54->m_object,
            (void **)&v51->vostok::engine_user::world::__vftable);
        }
        --*v52;
        v53[2].m_options = (survarium::options_item_base **)((char *)v53[2].m_options - v50->m_size);
        v55 = v50->m_hardware_buffer;
        v56 = vostok::render::g_allocator.m_object;
        if ( v55 )
        {
          v55->Release(v50->m_hardware_buffer);
          v50->m_hardware_buffer = 0;
        }
        v57 = (char *)v50;
        m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(v56->m_reconstruction_info_actuality_tick);
        BYTE2(v56->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v57);
      }
LABEL_54:
      v36 = thisa;
    }
  }
  v36->m_num_indices = 1260;
}
