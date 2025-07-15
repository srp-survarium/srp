void __usercall vostok::render::fill_source_vertices_impl__vostok::render::fill_source_vertices_::_2_::static_vertex_(
        int a1@<ebx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::render::render_geometry *in_render_geometry,
        vostok::render::vector<vostok::render::batched_vertex_source> *out_vertices,
        vostok::render::vector<unsigned short> *out_indices,
        int a8,
        int a9,
        int *data,
        unsigned int __n)
{
  vostok::render::untyped_buffer *m_object; // eax
  unsigned int v12; // ebp
  _QWORD *v13; // ebx
  _QWORD *v14; // esi
  stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source> > *v15; // ecx
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v17; // edi
  int v18; // eax
  int v19; // ecx
  unsigned int v20; // esi
  void *v21; // eax
  stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *v22; // ebp
  stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *v23; // ecx
  vostok::render::untyped_buffer *v24; // eax
  vostok::render::res_state *v25; // edi
  vostok::render::grass_render_model *v26; // ecx
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v28; // esi
  bool v29; // zf
  survarium::options_tab *v30; // ebx
  ID3D11RasterizerState *m_rasterizer_state; // eax
  vostok::render::grass_render_model *v32; // esi
  survarium::options_tab *v33; // ebx
  ID3D11RasterizerState *v34; // eax
  vostok::render::grass_render_model *v35; // esi
  survarium::options_tab *v36; // ebx
  ID3D11RasterizerState *v37; // eax
  vostok::render::grass_render_model *v38; // esi
  vostok::render::res_state *vb; // [esp+70h] [ebp-38h]
  vostok::render::res_state *temp_vb; // [esp+74h] [ebp-34h]
  unsigned __int8 *src; // [esp+78h] [ebp-30h] BYREF
  vostok::render::batched_vertex_source __x; // [esp+84h] [ebp-24h] BYREF
  void *dataa; // [esp+C0h] [ebp+18h]

  m_object = in_render_geometry->geom.m_object->m_vb.m_object;
  vb = 0;
  if ( m_object )
  {
    ++m_object->m_reference_count;
    vb = (vostok::render::res_state *)m_object;
  }
  v12 = (unsigned int)vb->m_depth_stencil_state / in_render_geometry->geom.m_object->m_vb_stride;
  v13 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          (unsigned int)vb->m_depth_stencil_state);
  v14 = v13;
  stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::reserve(
    v15,
    (int)out_vertices,
    v12);
  memset(&__x.normal, 255, 16);
  __x.uv.x = SNaN;
  __x.uv.y = SNaN;
  stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::resize(
    v12,
    &out_vertices->_M_impl,
    &__x);
  buffer = vostok::render::resource_manager::create_buffer(
             (unsigned int)vb->m_depth_stencil_state,
             (bool)out_vertices,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             v13,
             enum_buffer_type_vertex,
             0,
             1);
  v17 = 0;
  temp_vb = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    temp_vb = (vostok::render::res_state *)buffer;
    v17 = buffer;
  }
  (*(void (__stdcall **)(int, ID3D11Buffer *, ID3D11RasterizerState *, int, int, int, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                          + 188))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    v17->m_hardware_buffer,
    vb->m_rasterizer_state,
    a3,
    a4,
    a2,
    a1);
  (*(void (__stdcall **)(int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                             + 444))(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y);
  (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD, int, _DWORD, float *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                           + 56))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    v17->m_hardware_buffer,
    0,
    1,
    0,
    &__x.position.y);
  v18 = *data;
  if ( v12 )
  {
    v19 = LODWORD(__x.position.y) - (_DWORD)v13;
    do
    {
      *v14 = *(_QWORD *)((char *)v14 + v19);
      v14[1] = *(_QWORD *)((char *)v14 + v19 + 8);
      v14[2] = *(_QWORD *)((char *)v14 + v19 + 16);
      v14[3] = *(_QWORD *)((char *)v14 + v19 + 24);
      *(_DWORD *)(v18 + 24) = 0;
      *(_QWORD *)v18 = *v14;
      *(_DWORD *)(v18 + 8) = *((_DWORD *)v14 + 2);
      *(_DWORD *)(v18 + 12) = *((_DWORD *)v14 + 3);
      *(_DWORD *)(v18 + 16) = 0;
      *(_DWORD *)(v18 + 20) = 0;
      *(_DWORD *)(v18 + 28) = *((_DWORD *)v14 + 6);
      *(_DWORD *)(v18 + 32) = *((_DWORD *)v14 + 7);
      v14 += 4;
      v18 += 36;
      --v12;
    }
    while ( v12 );
  }
  (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                     + 60))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    v17->m_hardware_buffer,
    0);
  v20 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)a9 + 8) + 8);
  v21 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          v20);
  v22 = (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)__n;
  dataa = v21;
  stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::reserve(
    v23,
    __n,
    v20 >> 1);
  __n = 0;
  stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::resize(
    v22,
    v20 >> 1,
    (unsigned __int16 *)&__n);
  v24 = vostok::render::resource_manager::create_buffer(
          v20,
          v20 >> 1,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          dataa,
          enum_buffer_type_index,
          0,
          1);
  v25 = 0;
  if ( v24 )
  {
    ++v24->m_reference_count;
    v25 = (vostok::render::res_state *)v24;
  }
  (*(void (__cdecl **)(int, ID3D11RasterizerState *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                            + 188))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    v25->m_rasterizer_state,
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)a9 + 8) + 4));
  (*(void (__cdecl **)(int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                           + 444))(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y);
  (*(void (__stdcall **)(int, ID3D11RasterizerState *, _DWORD, int, _DWORD, unsigned __int8 **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                               + 56))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    v25->m_rasterizer_state,
    0,
    1,
    0,
    &src);
  memcpy((unsigned __int8 *)v22->_M_start, src, v20);
  (*(void (__stdcall **)(int, ID3D11RasterizerState *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                              + 60))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    v25->m_rasterizer_state,
    0);
  v26 = vostok::render::g_allocator.m_object;
  if ( v13 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v13);
    v26 = vostok::render::g_allocator.m_object;
  }
  if ( out_vertices )
  {
    v28 = (void *)HIDWORD(v26->m_reconstruction_info_actuality_tick);
    BYTE2(v26->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v28, out_vertices);
  }
  v29 = v25->m_reference_count-- == 1;
  if ( v29 )
  {
    v30 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
    if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
           (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
           v25) )
    {
      v30[2].m_options = (survarium::options_item_base **)((char *)v30[2].m_options
                                                         - (unsigned int)v25->m_depth_stencil_state);
      m_rasterizer_state = v25->m_rasterizer_state;
      v32 = vostok::render::g_allocator.m_object;
      if ( m_rasterizer_state )
      {
        m_rasterizer_state->Release(v25->m_rasterizer_state);
        v25->m_rasterizer_state = 0;
      }
      BYTE2(v32->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v32->m_reconstruction_info_actuality_tick), v25);
    }
  }
  v29 = temp_vb->m_reference_count-- == 1;
  if ( v29 )
  {
    v33 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
    if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
           (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
           temp_vb) )
    {
      v33[2].m_options = (survarium::options_item_base **)((char *)v33[2].m_options
                                                         - (unsigned int)temp_vb->m_depth_stencil_state);
      v34 = temp_vb->m_rasterizer_state;
      v35 = vostok::render::g_allocator.m_object;
      if ( v34 )
      {
        v34->Release(temp_vb->m_rasterizer_state);
        temp_vb->m_rasterizer_state = 0;
      }
      BYTE2(v35->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v35->m_reconstruction_info_actuality_tick), temp_vb);
    }
  }
  v29 = vb->m_reference_count-- == 1;
  if ( v29 )
  {
    v36 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
    if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
           (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
           vb) )
    {
      v36[2].m_options = (survarium::options_item_base **)((char *)v36[2].m_options
                                                         - (unsigned int)vb->m_depth_stencil_state);
      v37 = vb->m_rasterizer_state;
      v38 = vostok::render::g_allocator.m_object;
      if ( v37 )
      {
        v37->Release(vb->m_rasterizer_state);
        vb->m_rasterizer_state = 0;
      }
      BYTE2(v38->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v38->m_reconstruction_info_actuality_tick), vb);
    }
  }
}
