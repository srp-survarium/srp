void __thiscall vostok::render::stage_forward::render_opaque_models(
        vostok::render::stage_forward *this,
        vostok::render::stage_forward *thisa)
{
  vostok::render::renderer_context *m_context; // ecx
  vostok::render::base_scene_view *m_object; // eax
  vostok::render::render_surface_instance **m_parent; // edx
  const char *v5; // eax
  const char *v6; // ecx
  int v7; // edx
  const char *m_conflicted_key_name; // eax
  bool v9; // zf
  int v10; // ecx
  vostok::render::render_surface_instance *v11; // edi
  vostok::render::render_surface *m_render_surface; // esi
  vostok::render::material_effects_instance *v13; // eax
  vostok::render::material_effects *p_m_material_effects; // ebp
  _DWORD *v15; // eax
  unsigned int v16; // ecx
  const char *v17; // edi
  unsigned int v18; // ebp
  bool v19; // al
  const char *v20; // esi
  unsigned int v21; // [esp+0h] [ebp-18h]
  vostok::render::render_surface_instance **opaque_it_d; // [esp+10h] [ebp-8h]
  char *m_deleter; // [esp+14h] [ebp-4h]

  m_context = thisa->m_context;
  m_object = m_context->m_scene_view.m_object;
  m_parent = (vostok::render::render_surface_instance **)m_object[4].m_sub_fat.m_parent;
  m_deleter = (char *)m_object[4].m_deleter;
  opaque_it_d = m_parent;
  if ( ((m_deleter - (char *)m_parent) & 0xFFFFFFFC) != 0 )
  {
    v5 = (const char *)m_context->m_targets->m_family[47].target.m_object;
    v6 = 0;
    if ( v5 )
    {
      v6 = v5;
      ++*(_DWORD *)v5;
      v7 = *((_DWORD *)v5 + 4);
    }
    else
    {
      v7 = 0;
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) != v7 )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v7;
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
    if ( v6 )
    {
      v9 = (*(_DWORD *)v6)-- == 1;
      if ( v9 )
      {
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v6);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    v10 = *((_DWORD *)m_conflicted_key_name + 547);
    v9 = *((_DWORD *)m_conflicted_key_name + 539) == v10;
    *((_DWORD *)m_conflicted_key_name + 539) = v10;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v9;
    m_parent = opaque_it_d;
  }
  for ( ; m_parent != (vostok::render::render_surface_instance **)m_deleter; opaque_it_d = m_parent )
  {
    v11 = *m_parent;
    if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 288)
      || !v11->m_occluded )
    {
      m_render_surface = v11->m_render_surface;
      v13 = v11->m_render_surface->m_materail_effects_instance.m_object;
      if ( !v13 || s_use_one_material_value )
        p_m_material_effects = s_nomaterial_material_effects[m_render_surface->m_vertex_input_type];
      else
        p_m_material_effects = &v13->m_material_effects;
      if ( p_m_material_effects->is_emissive && p_m_material_effects->m_effects[0].m_object )
      {
        vostok::render::renderer_context::set_w(thisa->m_context, v11->m_transform);
        v15 = &p_m_material_effects->m_effects[0].m_object->__vftable;
        v16 = (v15[71] - v15[70]) >> 2;
        if ( v16 > 5 )
        {
          v15[69] = 5;
          vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v16, v21);
        }
        vostok::render::res_geometry::apply(m_render_surface->m_render_geometry.geom.m_object);
        v11->m_parent->set_constants(v11->m_parent);
        v17 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        v18 = 3 * m_render_surface->m_render_geometry.primitive_count;
        v19 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
        v20 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v19;
        if ( v19 )
          *((_DWORD *)v17 + 529) = 4;
        vostok::render::backend::flush((vostok::render::backend *)4, (int)v17);
        if ( v20[104] )
        {
          ++*((_DWORD *)v20 + 25);
          v18 += 3 * s_max_triagles_per_dip_value < v18 ? 3 * s_max_triagles_per_dip_value - v18 : 0;
        }
        if ( !v20[37] )
          (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                   + 48))(
            `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
            v18,
            0,
            0);
        *((_DWORD *)v20 + 21) += v18 / 3;
      }
      m_parent = opaque_it_d;
    }
    ++m_parent;
  }
}
