void __usercall vostok::render::stage_forward::accumulate_local_reflections(
        vostok::render::stage_forward *this@<ecx>,
        int a2@<eax>)
{
  int y; // eax
  _DWORD *v4; // eax
  int v5; // ecx
  bool v6; // zf
  _DWORD *v7; // eax
  vostok::render::resource_manager *v8; // ecx
  int v9; // eax
  const vostok::math::float4x4 *v10; // xmm0_4
  vostok::render::render_surface_instance *const *M_start; // edx
  _DWORD *v12; // eax
  int v13; // ebx
  _DWORD *v14; // eax
  vostok::render::resource_manager *v15; // ecx
  int v16; // edi
  const char *m_conflicted_key_name; // eax
  int v18; // edi
  vostok::render::render_surface_instance *v19; // edi
  vostok::render::render_surface *m_render_surface; // ebx
  vostok::render::material_effects_instance *m_object; // eax
  vostok::render::material_effects *p_m_material_effects; // ebp
  vostok::render::res_effect *v23; // ecx
  _DWORD *v24; // eax
  const char *v25; // edi
  vostok::render::constants_handler<1> *v26; // ebp
  const vostok::math::float3 *v27; // eax
  _DWORD *v28; // eax
  int v29; // xmm0_4
  int v30; // eax
  int v31; // edx
  int v32; // ecx
  int v33; // eax
  int v34; // ecx
  unsigned int v35; // ebx
  bool v36; // al
  void **v37; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::scene *v39; // [esp+0h] [ebp-C8h]
  unsigned int v40; // [esp+14h] [ebp-B4h]
  void **it_d; // [esp+28h] [ebp-A0h]
  vostok::render::render_surface_instance *const *end_d; // [esp+2Ch] [ebp-9Ch] BYREF
  vostok::render::render_surface *v43; // [esp+30h] [ebp-98h]
  float use_rain; // [esp+34h] [ebp-94h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> m_dynamic_visuals; // [esp+38h] [ebp-90h] BYREF
  _DWORD src_ptr[4]; // [esp+44h] [ebp-84h] BYREF
  D3D11_VIEWPORT view_port; // [esp+54h] [ebp-74h] BYREF
  D3D11_VIEWPORT prev_view_port; // [esp+6Ch] [ebp-5Ch] BYREF
  vostok::math::float4x4 result; // [esp+84h] [ebp-44h] BYREF

  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  end_d = (vostok::render::render_surface_instance *const *)1;
  (*(void (__stdcall **)(int, vostok::render::render_surface_instance *const **, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(
    y,
    &end_d,
    &prev_view_port);
  v4 = *(_DWORD **)(**(_DWORD **)(a2 + 4) + 1112);
  v5 = 0;
  if ( v4 )
  {
    v5 = *(_DWORD *)(**(_DWORD **)(a2 + 4) + 1112);
    ++*v4;
  }
  view_port.Width = (float)*(unsigned int *)(v5 + 28);
  v6 = (*(_DWORD *)v5)-- == 1;
  if ( v6 )
    vostok::render::resource_manager::release(
      (vostok::render::resource_manager *)v5,
      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
      (const char *)v5);
  v7 = *(_DWORD **)(**(_DWORD **)(a2 + 4) + 1112);
  v8 = 0;
  if ( v7 )
  {
    v8 = *(vostok::render::resource_manager **)(**(_DWORD **)(a2 + 4) + 1112);
    ++*v7;
  }
  view_port.Height = (float)LODWORD(v8->m_num_bytes_of_texture_video_memory);
  v6 = v8->sh_created-- == 1;
  if ( v6 )
    vostok::render::resource_manager::release(
      v8,
      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
      (const char *)v8);
  view_port.MinDepth = 0.0;
  LODWORD(view_port.MaxDepth) = clear_value;
  view_port.TopLeftX = 0.0;
  view_port.TopLeftY = 0.0;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &view_port);
  v9 = *(_DWORD *)(a2 + 4);
  if ( *(_BYTE *)(*(_DWORD *)(v9 + 12392) + 604) )
    v10 = clear_value;
  else
    v10 = 0;
  memset(&m_dynamic_visuals, 0, sizeof(m_dynamic_visuals));
  v39 = *(vostok::render::scene **)(v9 + 12388);
  LODWORD(use_rain) = v10;
  vostok::render::scene::select_models(
    v39,
    (const vostok::math::float4x4 *)(v9 + 16260),
    &m_dynamic_visuals,
    (const vostok::math::float3 *)(v9 + 16900),
    1u,
    0);
  end_d = (vostok::render::render_surface_instance *const *)m_dynamic_visuals._M_impl._M_finish;
  M_start = (vostok::render::render_surface_instance *const *)m_dynamic_visuals._M_impl._M_start;
  it_d = m_dynamic_visuals._M_impl._M_start;
  if ( (((char *)m_dynamic_visuals._M_impl._M_finish - (char *)m_dynamic_visuals._M_impl._M_start) & 0xFFFFFFFC) != 0 )
  {
    v12 = *(_DWORD **)(**(_DWORD **)(a2 + 4) + 1272);
    v13 = 0;
    if ( v12 )
    {
      v13 = *(_DWORD *)(**(_DWORD **)(a2 + 4) + 1272);
      ++*v12;
    }
    v14 = *(_DWORD **)(**(_DWORD **)(a2 + 4) + 1112);
    v15 = 0;
    if ( v14 )
    {
      v15 = *(vostok::render::resource_manager **)(**(_DWORD **)(a2 + 4) + 1112);
      ++*v14;
      v16 = v14[4];
    }
    else
    {
      v16 = 0;
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) != v16 )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v16;
      *((_BYTE *)m_conflicted_key_name + 163) = 1;
    }
    if ( v13 )
      v18 = *(_DWORD *)(v13 + 16);
    else
      v18 = 0;
    if ( *((_DWORD *)m_conflicted_key_name + 536) != v18 )
    {
      *((_DWORD *)m_conflicted_key_name + 536) = v18;
      *((_BYTE *)m_conflicted_key_name + 164) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 537) )
    {
      *((_DWORD *)m_conflicted_key_name + 537) = 0;
      *((_BYTE *)m_conflicted_key_name + 165) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 538) )
    {
      *((_DWORD *)m_conflicted_key_name + 538) = 0;
      *((_BYTE *)m_conflicted_key_name + 166) = 1;
    }
    if ( v15 )
    {
      v6 = v15->sh_created-- == 1;
      if ( v6 )
      {
        vostok::render::resource_manager::release(
          v15,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v15);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        M_start = (vostok::render::render_surface_instance *const *)it_d;
      }
    }
    if ( v13 )
    {
      v6 = (*(_DWORD *)v13)-- == 1;
      if ( v6 )
      {
        vostok::render::resource_manager::release(
          v15,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v13);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        M_start = (vostok::render::render_surface_instance *const *)it_d;
      }
    }
    v6 = *((_DWORD *)m_conflicted_key_name + 539) == 0;
    *((_DWORD *)m_conflicted_key_name + 539) = 0;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v6;
  }
  for ( ; M_start != end_d; it_d = (void **)M_start )
  {
    v19 = *M_start;
    if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 288)
      || !v19->m_occluded )
    {
      m_render_surface = v19->m_render_surface;
      m_object = v19->m_render_surface->m_materail_effects_instance.m_object;
      v43 = v19->m_render_surface;
      if ( !m_object || s_use_one_material_value )
        p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
      else
        p_m_material_effects = &m_object->m_material_effects;
      if ( p_m_material_effects->has_local_reflections && p_m_material_effects->m_effects[17].m_object )
      {
        v19->m_parent->set_constants(v19->m_parent);
        vostok::render::renderer_context::set_w(*(vostok::render::renderer_context **)(a2 + 4), v19->m_transform);
        v24 = &p_m_material_effects->m_effects[17].m_object->__vftable;
        if ( (unsigned int)((v24[71] - v24[70]) >> 2) > 1 )
        {
          v24[69] = 1;
          vostok::render::res_effect::apply_pass(v23, v40);
        }
        vostok::render::res_geometry::apply(m_render_surface->m_render_geometry.geom.m_object);
        v25 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v26 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                     + 1476);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(a2 + 104),
          (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
        + 123,
          (const vostok::math::float3 *)(*(_DWORD *)(a2 + 4) + 16772));
        ++*((_DWORD *)v25 + 23);
        v27 = (const vostok::math::float3 *)vostok::math::transpose(
                                              &result,
                                              (const vostok::math::float4x4 *)(*(_DWORD *)(a2 + 8) + 4));
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(a2 + 108),
          v26,
          v27);
        ++*((_DWORD *)v25 + 23);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(a2 + 112),
          v26,
          (const vostok::math::float3 *)(a2 + 128));
        ++*((_DWORD *)v25 + 23);
        v28 = *(_DWORD **)(*(_DWORD *)(a2 + 4) + 12392);
        src_ptr[0] = v28[112];
        src_ptr[1] = v28[113];
        src_ptr[2] = v28[114];
        v29 = v28[121];
        v30 = *(_DWORD *)(a2 + 92);
        v31 = *(_DWORD *)(v30 + 40);
        src_ptr[3] = v29;
        if ( v31 == *((_DWORD *)v25 + 573) )
        {
          v32 = *(unsigned __int16 *)(v30 + 20);
          if ( v32 != 0xFFFF )
          {
            vostok::render::shader_constant_buffer::set_memory(
              *(unsigned __int16 *)(v30 + 22),
              (unsigned __int8)*(_WORD *)(v30 + 16),
              *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v25 + 371) + 16) + 4 * v32),
              (const char *)src_ptr);
            m_render_surface = v43;
          }
        }
        ++*((_DWORD *)v25 + 23);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(a2 + 96),
          v26,
          (const vostok::math::float3 *)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 12392) + 496));
        ++*((_DWORD *)v25 + 23);
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          *(const vostok::render::shader_constant_host **)(a2 + 100),
          v26,
          (const vostok::math::float3 *)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 12392) + 488));
        ++*((_DWORD *)v25 + 23);
        v33 = *(_DWORD *)(a2 + 116);
        if ( *(_DWORD *)(v33 + 40) == *((_DWORD *)v25 + 573) )
        {
          v34 = *(unsigned __int16 *)(v33 + 20);
          if ( v34 != 0xFFFF )
            vostok::render::shader_constant_buffer::set_memory(
              *(unsigned __int16 *)(v33 + 22),
              (unsigned __int8)*(_WORD *)(v33 + 16),
              *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v25 + 371) + 16) + 4 * v34),
              (const char *)&use_rain);
        }
        ++*((_DWORD *)v25 + 23);
        v35 = 3 * m_render_surface->m_render_geometry.primitive_count;
        v36 = *((_DWORD *)v25 + 529) != 4;
        *((_BYTE *)v25 + 162) = v36;
        if ( v36 )
          *((_DWORD *)v25 + 529) = 4;
        vostok::render::backend::flush((vostok::render::backend *)4, (int)v25);
        if ( v25[104] )
        {
          ++*((_DWORD *)v25 + 25);
          v35 += 3 * s_max_triagles_per_dip_value < v35 ? 3 * s_max_triagles_per_dip_value - v35 : 0;
        }
        if ( !v25[37] )
          (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                   + 48))(
            `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
            v35,
            0,
            0);
        *((_DWORD *)v25 + 21) += v35 / 3;
        M_start = (vostok::render::render_surface_instance *const *)it_d;
      }
    }
    ++M_start;
  }
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &prev_view_port);
  v37 = m_dynamic_visuals._M_impl._M_start;
  if ( m_dynamic_visuals._M_impl._M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v37);
  }
}
