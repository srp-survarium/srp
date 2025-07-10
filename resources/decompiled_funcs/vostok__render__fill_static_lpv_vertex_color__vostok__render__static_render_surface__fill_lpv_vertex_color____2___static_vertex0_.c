void __usercall vostok::render::fill_static_lpv_vertex_color__vostok::render::static_render_surface::fill_lpv_vertex_color_::_2_::static_vertex0_(
        vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *in_materail_effects_instance@<edx>,
        vostok::render::batched_geometry_interface *in_out_lpv_geometry,
        vostok::render::render_geometry *in_render_geometry,
        const vostok::math::float4x4 *in_transform)
{
  vostok::render::untyped_buffer *v4; // eax
  vostok::render::untyped_buffer *v5; // ebp
  vostok::render::untyped_buffer *v6; // esi
  int v7; // edi
  vostok::render::untyped_buffer *v8; // eax
  vostok::render::untyped_buffer *v9; // ebx
  _DWORD *v10; // edi
  char *v11; // esi
  _DWORD *v12; // ebp
  int v13; // ebx
  unsigned __int8 **v14; // eax
  char v15; // cl
  unsigned __int8 *v16; // eax
  unsigned int v17; // ebx
  vostok::render::untyped_buffer *v18; // eax
  void (__thiscall *add_data)(vostok::render::batched_geometry_interface *, const vostok::render::batched_vertex_source *, const unsigned int, const unsigned __int16 *, const unsigned int, const vostok::math::float4x4 *, const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *); // edx
  vostok::resources::unmanaged_resource *v20; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_ib; // eax
  vostok::render::untyped_buffer *v22; // eax
  vostok::render::untyped_buffer *v23; // edi
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v25; // ebp
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v27; // ecx
  vostok::render::res_geometry *v28; // eax
  bool v29; // zf
  unsigned __int8 *v30; // edx
  vostok::render::grass_render_model *v31; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v33; // edx
  void *v34; // esi
  void *v35; // edx
  void *v36; // esi
  void *v37; // edx
  void *v38; // esi
  vostok::resources::unmanaged_resource *v39; // edi
  vostok::render::untyped_buffer *v40; // edi
  vostok::render::untyped_buffer *v41; // edi
  vostok::render::untyped_buffer *v42; // edi
  vostok::render::material_effects_instance *m_object; // [esp+68h] [ebp-40A8h]
  vostok::math::float2 v44; // [esp+68h] [ebp-40A8h]
  unsigned int m_size; // [esp+6Ch] [ebp-40A4h]
  vostok::resources::unmanaged_resource *resource; // [esp+80h] [ebp-4090h] BYREF
  vostok::render::untyped_buffer *buffer; // [esp+84h] [ebp-408Ch]
  unsigned __int8 *dst; // [esp+88h] [ebp-4088h]
  vostok::render::untyped_buffer *v49; // [esp+8Ch] [ebp-4084h]
  void *v50; // [esp+90h] [ebp-4080h]
  void *mem; // [esp+94h] [ebp-407Ch]
  void *data; // [esp+98h] [ebp-4078h]
  vostok::render::untyped_buffer *v53; // [esp+9Ch] [ebp-4074h]
  int v54; // [esp+A0h] [ebp-4070h]
  unsigned __int8 *src[3]; // [esp+A4h] [ebp-406Ch] BYREF
  D3D11_INPUT_ELEMENT_DESC dcl; // [esp+B0h] [ebp-4060h] BYREF
  const char *v57; // [esp+CCh] [ebp-4044h]
  int v58; // [esp+D0h] [ebp-4040h]
  int v59; // [esp+D4h] [ebp-403Ch]
  int v60; // [esp+D8h] [ebp-4038h]
  int v61; // [esp+DCh] [ebp-4034h]
  int v62; // [esp+E0h] [ebp-4030h]
  int v63; // [esp+E4h] [ebp-402Ch]
  const char *v64; // [esp+E8h] [ebp-4028h]
  int v65; // [esp+ECh] [ebp-4024h]
  int v66; // [esp+F0h] [ebp-4020h]
  int v67; // [esp+F4h] [ebp-401Ch]
  int v68; // [esp+F8h] [ebp-4018h]
  int v69; // [esp+FCh] [ebp-4014h]
  int v70; // [esp+100h] [ebp-4010h]
  vostok::math::color result; // [esp+10Ch] [ebp-4004h] BYREF
  vostok::math::color results[64][64]; // [esp+110h] [ebp-4000h] BYREF

  memset(results, 0xFFu, sizeof(results));
  m_object = 0;
  if ( in_materail_effects_instance->m_object )
  {
    m_object = in_materail_effects_instance->m_object;
    _InterlockedExchangeAdd(&in_materail_effects_instance->m_object->m_reference_count, 1u);
  }
  if ( vostok::render::read_diffuse_colors_64_(
         (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base>)m_object,
         (vostok::math::color (*)[64][64])results) )
  {
    v4 = in_render_geometry->geom.m_object->m_vb.m_object;
    v5 = 0;
    v53 = 0;
    if ( v4 )
    {
      ++v4->m_reference_count;
      v53 = v4;
      v5 = v4;
    }
    m_size = v5->m_size;
    buffer = (vostok::render::untyped_buffer *)(m_size / in_render_geometry->geom.m_object->m_vb_stride);
    v6 = buffer;
    v7 = 20 * (_DWORD)buffer;
    mem = vostok::memory::doug_lea_allocator::malloc_impl(
            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
            m_size);
    v54 = 20 * (_DWORD)buffer;
    data = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
             20 * (_DWORD)buffer);
    v50 = vostok::memory::doug_lea_allocator::malloc_impl(
            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
            36 * (_DWORD)buffer);
    v8 = vostok::render::resource_manager::create_buffer(
           v5->m_size,
           20 * (_BYTE)buffer,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           mem,
           enum_buffer_type_vertex,
           0,
           1);
    v9 = 0;
    v49 = 0;
    if ( v8 )
    {
      ++v8->m_reference_count;
      v49 = v8;
      v9 = v8;
    }
    (*(void (__stdcall **)(int, ID3D11Buffer *, ID3D11Buffer *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                               + 188))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v9->m_hardware_buffer,
      v5->m_hardware_buffer);
    (*(void (__stdcall **)(int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                               + 444))(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y);
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD, int, _DWORD, unsigned __int8 **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                        + 56))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v9->m_hardware_buffer,
      0,
      1,
      0,
      src);
    if ( v6 )
    {
      v10 = (char *)v50 + 12;
      v11 = (char *)mem + 12;
      v12 = (char *)data + 12;
      v13 = src[0] - (unsigned __int8 *)mem;
      resource = (vostok::resources::unmanaged_resource *)buffer;
      do
      {
        *(_QWORD *)(v11 - 12) = *(_QWORD *)&v11[v13 - 12];
        *(_QWORD *)(v11 - 4) = *(_QWORD *)&v11[v13 - 4];
        *(_QWORD *)(v11 + 4) = *(_QWORD *)&v11[v13 + 4];
        *(_QWORD *)(v11 + 12) = *(_QWORD *)&v11[v13 + 12];
        v44.x = *((float *)v11 + 3);
        v44.y = *((float *)v11 + 4);
        v14 = (unsigned __int8 **)vostok::render::interpolated_color_64_(
                                    &result,
                                    (vostok::math::color (*)[64][64])results,
                                    v44);
        v15 = v11[7];
        dst = *v14;
        HIBYTE(dst) = v15;
        v16 = dst;
        v12[1] = dst;
        *(_QWORD *)(v12 - 3) = *(_QWORD *)(v11 - 12);
        *(v12 - 1) = *((_DWORD *)v11 - 1);
        *v12 = *(_DWORD *)v11;
        v10[3] = v16;
        *(_QWORD *)(v10 - 3) = *(_QWORD *)(v11 - 12);
        *(v10 - 1) = *((_DWORD *)v11 - 1);
        *v10 = *(_DWORD *)v11;
        v10[1] = 0;
        v10[2] = 0;
        v10[4] = *((_DWORD *)v11 + 3);
        v10[5] = *((_DWORD *)v11 + 4);
        v11 += 32;
        v12 += 5;
        v10 += 9;
        resource = (vostok::resources::unmanaged_resource *)((char *)resource - 1);
      }
      while ( resource );
      v7 = v54;
      v6 = buffer;
      v9 = v49;
    }
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                       + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v9->m_hardware_buffer,
      0);
    v17 = in_render_geometry->geom.m_object->m_ib.m_object->m_size;
    dst = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                               v17);
    v18 = vostok::render::resource_manager::create_buffer(
            v17,
            v7,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            dst,
            enum_buffer_type_index,
            0,
            1);
    buffer = 0;
    if ( v18 )
    {
      ++v18->m_reference_count;
      buffer = v18;
    }
    (*(void (__stdcall **)(int, ID3D11Buffer *, ID3D11Buffer *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                               + 188))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      buffer->m_hardware_buffer,
      in_render_geometry->geom.m_object->m_ib.m_object->m_hardware_buffer);
    (*(void (__stdcall **)(int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                               + 444))(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y);
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD, int, _DWORD, unsigned __int8 **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                        + 56))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      buffer->m_hardware_buffer,
      0,
      1,
      0,
      src);
    memcpy(dst, src[0], v17);
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                       + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      buffer->m_hardware_buffer,
      0);
    if ( in_out_lpv_geometry )
    {
      add_data = in_out_lpv_geometry->add_data;
      resource = 0;
      add_data(
        in_out_lpv_geometry,
        (const vostok::render::batched_vertex_source *)v50,
        (const unsigned int)v6,
        (const unsigned __int16 *)dst,
        v17 >> 1,
        in_transform,
        (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)&resource);
      if ( resource )
      {
        if ( !_InterlockedExchangeAdd(&resource->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(
            &resource->vostok::resources::unmanaged_intrusive_base,
            resource);
      }
    }
    v20 = (vostok::resources::unmanaged_resource *)vostok::render::resource_manager::create_buffer(
                                                     v7,
                                                     v7,
                                                     (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                                                     data,
                                                     enum_buffer_type_vertex,
                                                     0,
                                                     0);
    resource = 0;
    if ( v20 )
    {
      ++v20->__vftable;
      resource = v20;
    }
    v59 = 28;
    v66 = 28;
    p_m_ib = &in_render_geometry->geom.m_object->m_ib;
    dcl.SemanticName = "POSITION";
    dcl.SemanticIndex = 0;
    dcl.Format = DXGI_FORMAT_R32G32B32_FLOAT;
    memset(&dcl.InputSlot, 0, 16);
    v57 = "NORMAL";
    v58 = 0;
    v60 = 0;
    v61 = 12;
    v62 = 0;
    v63 = 0;
    v64 = "TEXCOORD";
    v65 = 0;
    v67 = 0;
    v68 = 16;
    v69 = 0;
    v70 = 0;
    v22 = p_m_ib->m_object;
    v23 = 0;
    if ( v22 )
    {
      v23 = v22;
      ++v22->m_reference_count;
    }
    declaration = vostok::render::resource_manager::create_declaration(
                    3u,
                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                    (stlp_std::forward_iterator_tag *)&dcl);
    v25 = 0;
    if ( declaration )
    {
      ++declaration->m_reference_count;
      v25 = declaration;
    }
    geometry = vostok::render::resource_manager::create_geometry(
                 v25,
                 (vostok::render::untyped_buffer *)resource,
                 (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                 0x14u,
                 v23);
    v27 = 0;
    if ( geometry )
    {
      ++geometry->m_reference_count;
      v27 = geometry;
    }
    v28 = in_render_geometry->lpv_pass_geom.m_object;
    in_render_geometry->lpv_pass_geom.m_object = v27;
    if ( v28 )
    {
      v29 = v28->m_reference_count-- == 1;
      if ( v29 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v28);
    }
    v30 = dst;
    v31 = vostok::render::g_allocator.m_object;
    if ( dst )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v30);
      v31 = vostok::render::g_allocator.m_object;
    }
    v33 = mem;
    if ( mem )
    {
      v34 = (void *)HIDWORD(v31->m_reconstruction_info_actuality_tick);
      BYTE2(v31->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v34, v33);
      v31 = vostok::render::g_allocator.m_object;
    }
    v35 = data;
    if ( data )
    {
      v36 = (void *)HIDWORD(v31->m_reconstruction_info_actuality_tick);
      BYTE2(v31->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v36, v35);
      v31 = vostok::render::g_allocator.m_object;
    }
    v37 = v50;
    if ( v50 )
    {
      v38 = (void *)HIDWORD(v31->m_reconstruction_info_actuality_tick);
      BYTE2(v31->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v38, v37);
    }
    if ( v25 )
    {
      v29 = v25->m_reference_count-- == 1;
      if ( v29 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v25);
    }
    if ( v23 )
    {
      v29 = v23->m_reference_count-- == 1;
      if ( v29 )
        vostok::render::resource_manager::release(
          (vostok::render::res_state *)v23,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    }
    v39 = resource;
    if ( resource )
    {
      v29 = resource->__vftable-- == (vostok::resources::unmanaged_resource_vtbl *)1;
      if ( v29 )
        vostok::render::resource_manager::release(
          (vostok::render::res_state *)v39,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    }
    v40 = buffer;
    v29 = buffer->m_reference_count-- == 1;
    if ( v29 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v40,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    v41 = v49;
    v29 = v49->m_reference_count-- == 1;
    if ( v29 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v41,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    v42 = v53;
    v29 = v53->m_reference_count-- == 1;
    if ( v29 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v42,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
}
