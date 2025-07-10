void __usercall vostok::render::fill_static_lpv_vertex_color__vostok::render::static_render_surface::fill_lpv_vertex_color_::_2_::colored_static_vertex_(
        vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *in_materail_effects_instance@<edx>,
        vostok::render::batched_geometry_interface *in_out_lpv_geometry,
        vostok::render::render_geometry *in_render_geometry,
        const vostok::math::float4x4 *in_transform)
{
  vostok::render::untyped_buffer *v4; // eax
  unsigned int v5; // esi
  unsigned int v6; // ebx
  _QWORD *v7; // edi
  vostok::render::untyped_buffer *v8; // eax
  vostok::render::untyped_buffer *v9; // ebp
  int v10; // ebp
  _DWORD *v11; // ebx
  _DWORD *v12; // esi
  vostok::resources::unmanaged_resource *v13; // ecx
  unsigned __int8 *m_value; // edx
  char v15; // al
  unsigned __int8 *v16; // eax
  vostok::resources::unmanaged_resource *v17; // ecx
  unsigned int v18; // edi
  vostok::render::untyped_buffer *v19; // eax
  void (__thiscall *add_data)(vostok::render::batched_geometry_interface *, const vostok::render::batched_vertex_source *, const unsigned int, const unsigned __int16 *, const unsigned int, const vostok::math::float4x4 *, const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *); // edx
  vostok::resources::unmanaged_resource *v21; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_ib; // eax
  vostok::render::untyped_buffer *v23; // eax
  vostok::render::untyped_buffer *v24; // ebx
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v26; // ebp
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v28; // ecx
  vostok::render::res_geometry *v29; // eax
  bool v30; // zf
  unsigned __int8 *v31; // edx
  vostok::render::grass_render_model *v32; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v34; // edx
  void *v35; // esi
  void *v36; // edx
  void *v37; // esi
  void *v38; // edx
  void *v39; // esi
  vostok::resources::unmanaged_resource *v40; // eax
  vostok::render::untyped_buffer *v41; // edi
  vostok::render::untyped_buffer *v42; // edi
  vostok::render::untyped_buffer *v43; // edi
  vostok::render::material_effects_instance *m_object; // [esp+64h] [ebp-40B0h]
  vostok::math::float2 v45; // [esp+64h] [ebp-40B0h]
  unsigned int m_size; // [esp+68h] [ebp-40ACh]
  vostok::resources::unmanaged_resource *resource; // [esp+80h] [ebp-4094h] BYREF
  vostok::render::untyped_buffer *buffer; // [esp+84h] [ebp-4090h]
  unsigned __int8 *dst; // [esp+88h] [ebp-408Ch]
  vostok::render::untyped_buffer *v50; // [esp+8Ch] [ebp-4088h]
  void *v51; // [esp+90h] [ebp-4084h]
  vostok::render::untyped_buffer *v52; // [esp+94h] [ebp-4080h]
  void *data; // [esp+98h] [ebp-407Ch]
  unsigned int v54; // [esp+9Ch] [ebp-4078h]
  void *mem; // [esp+A0h] [ebp-4074h]
  int v56; // [esp+A4h] [ebp-4070h]
  unsigned __int8 *src[3]; // [esp+A8h] [ebp-406Ch] BYREF
  D3D11_INPUT_ELEMENT_DESC dcl; // [esp+B4h] [ebp-4060h] BYREF
  const char *v59; // [esp+D0h] [ebp-4044h]
  int v60; // [esp+D4h] [ebp-4040h]
  int v61; // [esp+D8h] [ebp-403Ch]
  int v62; // [esp+DCh] [ebp-4038h]
  int v63; // [esp+E0h] [ebp-4034h]
  int v64; // [esp+E4h] [ebp-4030h]
  int v65; // [esp+E8h] [ebp-402Ch]
  const char *v66; // [esp+ECh] [ebp-4028h]
  int v67; // [esp+F0h] [ebp-4024h]
  int v68; // [esp+F4h] [ebp-4020h]
  int v69; // [esp+F8h] [ebp-401Ch]
  int v70; // [esp+FCh] [ebp-4018h]
  int v71; // [esp+100h] [ebp-4014h]
  int v72; // [esp+104h] [ebp-4010h]
  vostok::math::color result; // [esp+110h] [ebp-4004h] BYREF
  vostok::math::color results[64][64]; // [esp+114h] [ebp-4000h] BYREF

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
    v50 = 0;
    if ( v4 )
    {
      ++v4->m_reference_count;
      v50 = v4;
    }
    m_size = v50->m_size;
    v54 = m_size / in_render_geometry->geom.m_object->m_vb_stride;
    v5 = v54;
    v6 = 20 * v54;
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           m_size);
    mem = v7;
    v56 = 20 * v54;
    data = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
             20 * v54);
    v51 = vostok::memory::doug_lea_allocator::malloc_impl(
            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
            36 * v54);
    v8 = vostok::render::resource_manager::create_buffer(
           v50->m_size,
           (bool)v7,
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           v7,
           enum_buffer_type_vertex,
           0,
           1);
    v9 = 0;
    v52 = 0;
    if ( v8 )
    {
      ++v8->m_reference_count;
      v52 = v8;
      v9 = v8;
    }
    (*(void (__stdcall **)(int, ID3D11Buffer *, ID3D11Buffer *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                               + 188))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v9->m_hardware_buffer,
      v50->m_hardware_buffer);
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
    if ( v5 )
    {
      v10 = src[0] - (unsigned __int8 *)v51;
      v11 = (char *)data + 12;
      v12 = (char *)v51 + 12;
      v13 = (vostok::resources::unmanaged_resource *)((_BYTE *)mem - (_BYTE *)v51);
      resource = (vostok::resources::unmanaged_resource *)((_BYTE *)mem - (_BYTE *)v51);
      buffer = (vostok::render::untyped_buffer *)v54;
      while ( 1 )
      {
        *v7 = *(_QWORD *)((char *)v12 + v10 - 12);
        v7[1] = *(_QWORD *)((char *)v12 + v10 - 4);
        v7[2] = *(_QWORD *)((char *)v12 + v10 + 4);
        v7[3] = *(_QWORD *)((char *)v12 + v10 + 12);
        *((_DWORD *)v7 + 8) = *(_DWORD *)((char *)v12 + v10 + 20);
        v45.x = *((float *)v7 + 6);
        v45.y = *(float *)((char *)&v13->m_reconstruction_info_actuality_tick + (_DWORD)v12);
        m_value = (unsigned __int8 *)vostok::render::interpolated_color_64_(
                                       &result,
                                       (vostok::math::color (*)[64][64])results,
                                       v45)->m_value;
        v15 = *((_BYTE *)v7 + 19);
        dst = m_value;
        HIBYTE(dst) = v15;
        v16 = dst;
        v11[1] = dst;
        *(_QWORD *)(v11 - 3) = *v7;
        *(v11 - 1) = *((_DWORD *)v7 + 2);
        v17 = resource;
        *v11 = *(_DWORD *)((char *)v12 + (_DWORD)resource);
        v12[3] = v16;
        *(_QWORD *)(v12 - 3) = *v7;
        *(v12 - 1) = *((_DWORD *)v7 + 2);
        *v12 = *(_DWORD *)((char *)v12 + (_DWORD)v17);
        v12[1] = 0;
        v12[2] = 0;
        v12[4] = *((_DWORD *)v7 + 6);
        v12[5] = *((_DWORD *)v7 + 7);
        v7 = (_QWORD *)((char *)v7 + 36);
        v12 += 9;
        v11 += 5;
        buffer = (vostok::render::untyped_buffer *)((char *)buffer - 1);
        if ( !buffer )
          break;
        v13 = resource;
      }
      v6 = v56;
      v5 = v54;
      v9 = v52;
    }
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                       + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v9->m_hardware_buffer,
      0);
    v18 = in_render_geometry->geom.m_object->m_ib.m_object->m_size;
    dst = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                               v18);
    v19 = vostok::render::resource_manager::create_buffer(
            v18,
            v18,
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            dst,
            enum_buffer_type_index,
            0,
            1);
    buffer = 0;
    if ( v19 )
    {
      ++v19->m_reference_count;
      buffer = v19;
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
    memcpy(dst, src[0], v18);
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
        (const vostok::render::batched_vertex_source *)v51,
        v5,
        (const unsigned __int16 *)dst,
        v18 >> 1,
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
    v21 = (vostok::resources::unmanaged_resource *)vostok::render::resource_manager::create_buffer(
                                                     v6,
                                                     0,
                                                     (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                                                     data,
                                                     enum_buffer_type_vertex,
                                                     0,
                                                     0);
    resource = 0;
    if ( v21 )
    {
      ++v21->__vftable;
      resource = v21;
    }
    v61 = 28;
    v68 = 28;
    p_m_ib = &in_render_geometry->geom.m_object->m_ib;
    dcl.SemanticName = "POSITION";
    dcl.SemanticIndex = 0;
    dcl.Format = DXGI_FORMAT_R32G32B32_FLOAT;
    memset(&dcl.InputSlot, 0, 16);
    v59 = "NORMAL";
    v60 = 0;
    v62 = 0;
    v63 = 12;
    v64 = 0;
    v65 = 0;
    v66 = "TEXCOORD";
    v67 = 0;
    v69 = 0;
    v70 = 16;
    v71 = 0;
    v72 = 0;
    v23 = p_m_ib->m_object;
    v24 = 0;
    if ( v23 )
    {
      v24 = v23;
      ++v23->m_reference_count;
    }
    declaration = vostok::render::resource_manager::create_declaration(
                    3u,
                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                    (stlp_std::forward_iterator_tag *)&dcl);
    v26 = 0;
    if ( declaration )
    {
      ++declaration->m_reference_count;
      v26 = declaration;
    }
    geometry = vostok::render::resource_manager::create_geometry(
                 v26,
                 (vostok::render::untyped_buffer *)resource,
                 (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                 0x14u,
                 v24);
    v28 = 0;
    if ( geometry )
    {
      ++geometry->m_reference_count;
      v28 = geometry;
    }
    v29 = in_render_geometry->lpv_pass_geom.m_object;
    in_render_geometry->lpv_pass_geom.m_object = v28;
    if ( v29 )
    {
      v30 = v29->m_reference_count-- == 1;
      if ( v30 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v29);
    }
    v31 = dst;
    v32 = vostok::render::g_allocator.m_object;
    if ( dst )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v31);
      v32 = vostok::render::g_allocator.m_object;
    }
    v34 = mem;
    if ( mem )
    {
      v35 = (void *)HIDWORD(v32->m_reconstruction_info_actuality_tick);
      BYTE2(v32->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v35, v34);
      v32 = vostok::render::g_allocator.m_object;
    }
    v36 = data;
    if ( data )
    {
      v37 = (void *)HIDWORD(v32->m_reconstruction_info_actuality_tick);
      BYTE2(v32->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v37, v36);
      v32 = vostok::render::g_allocator.m_object;
    }
    v38 = v51;
    if ( v51 )
    {
      v39 = (void *)HIDWORD(v32->m_reconstruction_info_actuality_tick);
      BYTE2(v32->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v39, v38);
    }
    if ( v26 )
    {
      v30 = v26->m_reference_count-- == 1;
      if ( v30 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v26);
    }
    if ( v24 )
    {
      v30 = v24->m_reference_count-- == 1;
      if ( v30 )
        vostok::render::resource_manager::release(
          (vostok::render::res_state *)v24,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    }
    v40 = resource;
    if ( resource )
    {
      v30 = resource->__vftable-- == (vostok::resources::unmanaged_resource_vtbl *)1;
      if ( v30 )
        vostok::render::resource_manager::release(
          (vostok::render::res_state *)v40,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    }
    v41 = buffer;
    v30 = buffer->m_reference_count-- == 1;
    if ( v30 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v41,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    v42 = v52;
    v30 = v52->m_reference_count-- == 1;
    if ( v30 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v42,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
    v43 = v50;
    v30 = v50->m_reference_count-- == 1;
    if ( v30 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)v43,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
}
