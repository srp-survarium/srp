void __thiscall vostok::render::stage_debug::execute(vostok::render::stage_debug *this)
{
  vostok::render::stage_debug *v1; // ebp
  vostok::render::backend *v2; // ecx
  vostok::render::render_target *m_object; // eax
  vostok::render::resource_manager *v4; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  const char *m_conflicted_key_name; // eax
  vostok::render::renderer_context *m_context; // eax
  void **M_finish; // ecx
  void **M_start; // edx
  int v11; // esi
  int v12; // eax
  vostok::render::material_effects *v13; // edi
  _DWORD *v14; // eax
  int v15; // ecx
  const char *v16; // edi
  unsigned int v17; // ebp
  bool v18; // al
  const char *v19; // esi
  __int64 v20; // rax
  void **v21; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int v23; // [esp+0h] [ebp-28h]
  void **it_d; // [esp+10h] [ebp-18h]
  void **end_d; // [esp+18h] [ebp-10h]
  vostok::render::vector<vostok::render::render_surface_instance *> m_dynamic_visuals; // [esp+1Ch] [ebp-Ch] BYREF

  v1 = this;
  if ( ((unsigned __int8 (__fastcall *)(vostok::render::stage_debug *))this->is_enabled)(this)
    && v1->m_debug_environment_probe_preview_effect.m_object )
  {
    vostok::render::backend::flush_rt_shader_resources(
      v2,
      (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
    m_object = v1->m_context->m_targets->m_family[45].target.m_object;
    v4 = 0;
    if ( m_object )
    {
      v4 = (vostok::render::resource_manager *)v1->m_context->m_targets->m_family[45].target.m_object;
      ++m_object->m_reference_count;
      m_rt = m_object->m_rt;
    }
    else
    {
      m_rt = 0;
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != m_rt )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
      *((_BYTE *)m_conflicted_key_name + 163) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 536) )
    {
      *((_DWORD *)m_conflicted_key_name + 536) = 0;
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
    if ( v4 )
    {
      if ( v4->sh_created-- == 1 )
        vostok::render::resource_manager::release(
          v4,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v4);
    }
    m_context = v1->m_context;
    memset(&m_dynamic_visuals, 0, sizeof(m_dynamic_visuals));
    vostok::render::scene::select_models(
      m_context->m_scene,
      &m_context->m_vp,
      &m_dynamic_visuals,
      (const vostok::math::float3 *)&m_context->m_view_pos,
      1u,
      0);
    M_finish = m_dynamic_visuals._M_impl._M_finish;
    M_start = m_dynamic_visuals._M_impl._M_start;
    it_d = m_dynamic_visuals._M_impl._M_start;
    for ( end_d = m_dynamic_visuals._M_impl._M_finish; M_start != end_d; it_d = M_start )
    {
      M_finish = (void **)*M_start;
      v11 = *(_DWORD *)*M_start;
      v12 = *(_DWORD *)(v11 + 148);
      if ( !v12 || s_use_one_material_value )
        v13 = s_nomaterial_material_effects[*(_DWORD *)(v11 + 4)];
      else
        v13 = (vostok::render::material_effects *)(v12 + 264);
      if ( v13->stage_enable[27] )
      {
        vostok::render::renderer_context::set_w(v1->m_context, (const vostok::math::float4x4 *)M_finish[1]);
        v14 = &v13->m_effects[27].m_object->__vftable;
        v15 = (v14[71] - v14[70]) >> 2;
        if ( v15 )
        {
          v14[69] = 0;
          vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v15, v23);
        }
        vostok::render::res_geometry::apply(*(vostok::render::res_geometry **)(v11 + 48));
        v16 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v17 = 3 * *(_DWORD *)(v11 + 68);
        v18 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
        v19 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v18;
        if ( v18 )
          *((_DWORD *)v16 + 529) = 4;
        vostok::render::backend::flush((vostok::render::backend *)4, (int)v16);
        if ( v19[104] )
        {
          ++*((_DWORD *)v19 + 25);
          v17 += 3 * s_max_triagles_per_dip_value < v17 ? 3 * s_max_triagles_per_dip_value - v17 : 0;
        }
        if ( !v19[37] )
          (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                   + 48))(
            `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
            v17,
            0,
            0);
        v20 = 2863311531LL * v17;
        v1 = this;
        *((_DWORD *)v19 + 21) += HIDWORD(v20) >> 1;
        M_start = it_d;
      }
      ++M_start;
    }
    vostok::render::stage_debug::render_environment_probe_preview((vostok::render::stage_debug *)M_finish, (int)v1);
    v21 = m_dynamic_visuals._M_impl._M_start;
    if ( m_dynamic_visuals._M_impl._M_start )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v21);
    }
  }
  else
  {
    v1->execute_disabled(v1);
  }
}
