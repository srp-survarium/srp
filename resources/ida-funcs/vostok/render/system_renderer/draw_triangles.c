void __thiscall vostok::render::system_renderer::draw_triangles(
        vostok::render::system_renderer *this,
        vostok::render::system_renderer *vertices_begin,
        vostok::render::vertex_colored *vertices_end,
        const unsigned __int16 *indices_begin,
        unsigned __int8 *indices_end,
        const unsigned __int16 *covering_effect,
        bool covering_effecta)
{
  const unsigned __int16 *v7; // ebp
  unsigned int v8; // ebp
  unsigned __int8 *v9; // eax
  unsigned int v10; // ebp
  unsigned __int8 *v11; // eax
  float v12; // eax
  unsigned int v13; // ecx
  int m_grid_mode; // ecx
  const char *m_conflicted_key_name; // edi
  unsigned int v16; // esi
  bool v17; // al
  float v18; // eax
  unsigned int v19; // ecx
  const char *v20; // edi
  unsigned int v21; // ebx
  bool v22; // al
  unsigned int v23; // [esp+Ch] [ebp-14h]

  v7 = indices_begin;
  if ( vostok::render::system_renderer::is_effects_ready(this, vertices_begin) )
  {
    v8 = ((char *)v7 - (char *)vertices_end) >> 4;
    v9 = (unsigned __int8 *)vostok::render::vertex_buffer::lock(
                              &vertices_begin->m_vertex_stream,
                              v8,
                              0x10u,
                              (unsigned int *)&indices_begin);
    memcpy(v9, (unsigned __int8 *)vertices_end, 16 * v8);
    vertices_begin->m_vertex_stream.m_position += vertices_begin->m_vertex_stream.m_lock_count
                                                * vertices_begin->m_vertex_stream.m_lock_stride;
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                       + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      vertices_begin->m_vertex_stream.m_buffer.m_object->m_hardware_buffer,
      0);
    v10 = ((char *)covering_effect - (char *)indices_end) >> 1;
    v11 = (unsigned __int8 *)vostok::render::index_buffer::lock(
                               &vertices_begin->m_index_stream,
                               v10,
                               (unsigned int *)&vertices_end);
    memcpy(v11, indices_end, 2 * v10);
    vertices_begin->m_index_stream.m_position += vertices_begin->m_index_stream.m_lock_size;
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                       + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      vertices_begin->m_index_stream.m_buffer.m_object->m_hardware_buffer,
      0);
    vostok::render::res_geometry::apply(vertices_begin->m_colored_geom.m_object);
    if ( covering_effecta )
    {
      v12 = *(float *)&vertices_begin->m_sh_vcolor.m_object;
      v13 = (*(_DWORD *)(LODWORD(v12) + 284) - *(_DWORD *)(LODWORD(v12) + 280)) >> 2;
      if ( v13 > 3 )
      {
        *(_DWORD *)(LODWORD(v12) + 276) = 3;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v13, v23);
      }
    }
    else
    {
      if ( vertices_begin->m_color_write )
        m_grid_mode = vertices_begin->m_grid_mode;
      else
        m_grid_mode = 2;
      vostok::render::res_effect::apply(
        (vostok::render::res_effect *)m_grid_mode,
        &vertices_begin->m_sh_vcolor.m_object->__vftable);
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      vertices_begin->m_grid_density_constant,
      (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
    + 123,
      (const vostok::math::float3 *)&vertices_begin->m_grid_density);
    ++*((_DWORD *)m_conflicted_key_name + 23);
    v16 = v10;
    v17 = *((_DWORD *)m_conflicted_key_name + 529) != 4;
    *((_BYTE *)m_conflicted_key_name + 162) = v17;
    if ( v17 )
      *((_DWORD *)m_conflicted_key_name + 529) = 4;
    vostok::render::backend::flush((vostok::render::backend *)4, (int)m_conflicted_key_name);
    if ( m_conflicted_key_name[104] )
    {
      ++*((_DWORD *)m_conflicted_key_name + 25);
      v16 = v10 + (3 * s_max_triagles_per_dip_value < v10 ? 3 * s_max_triagles_per_dip_value - v10 : 0);
    }
    if ( !m_conflicted_key_name[37] )
      (*(void (__stdcall **)(int, unsigned int, vostok::render::vertex_colored *, const unsigned __int16 *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y + 48))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v16,
        vertices_end,
        indices_begin);
    *((_DWORD *)m_conflicted_key_name + 21) += v16 / 3;
    v18 = *(float *)&vertices_begin->m_sh_vcolor.m_object;
    v19 = (*(_DWORD *)(LODWORD(v18) + 284) - *(_DWORD *)(LODWORD(v18) + 280)) >> 2;
    if ( v19 > 4 )
    {
      *(_DWORD *)(LODWORD(v18) + 276) = 4;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v19, v23);
    }
    vostok::render::res_geometry::apply(vertices_begin->m_colored_geom.m_object);
    v20 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
      vertices_begin->m_grid_density_constant,
      (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
    + 123,
      (const vostok::math::float3 *)&vertices_begin->m_grid_density);
    ++*((_DWORD *)v20 + 23);
    v21 = v10;
    v22 = *((_DWORD *)v20 + 529) != 4;
    *((_BYTE *)v20 + 162) = v22;
    if ( v22 )
      *((_DWORD *)v20 + 529) = 4;
    vostok::render::backend::flush((vostok::render::backend *)4, (int)v20);
    if ( v20[104] )
    {
      ++*((_DWORD *)v20 + 25);
      v21 = v10 + (3 * s_max_triagles_per_dip_value < v10 ? 3 * s_max_triagles_per_dip_value - v10 : 0);
    }
    if ( !v20[37] )
      (*(void (__stdcall **)(int, unsigned int, vostok::render::vertex_colored *, const unsigned __int16 *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y + 48))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v21,
        vertices_end,
        indices_begin);
    *((_DWORD *)v20 + 21) += v21 / 3;
  }
}
