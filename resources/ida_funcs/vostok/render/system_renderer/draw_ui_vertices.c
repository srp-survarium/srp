void __thiscall vostok::render::system_renderer::draw_ui_vertices(
        vostok::render::system_renderer *this,
        vostok::render::system_renderer *vertices,
        unsigned __int8 *count,
        unsigned int prim_type,
        int point_type,
        int point_typea)
{
  unsigned int *v6; // ebp
  unsigned __int8 *v7; // eax
  int v8; // ecx
  vostok::render::backend *v9; // ecx
  const char *m_conflicted_key_name; // edi
  unsigned int v11; // ebp
  bool v12; // al
  const char *v13; // ebx

  v6 = (unsigned int *)prim_type;
  if ( vostok::render::system_renderer::is_effects_ready(this, vertices) )
  {
    v7 = (unsigned __int8 *)vostok::render::vertex_buffer::lock(&vertices->m_vertex_stream, *v6, 0x1Cu, &prim_type);
    memcpy(v7, count, 28 * *v6);
    vertices->m_vertex_stream.m_position += vertices->m_vertex_stream.m_lock_count
                                          * vertices->m_vertex_stream.m_lock_stride;
    (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                       + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      vertices->m_vertex_stream.m_buffer.m_object->m_hardware_buffer,
      0);
    vostok::render::res_geometry::apply(vertices->m_ui_geom.m_object);
    if ( point_type )
    {
      vostok::render::res_effect::apply((vostok::render::res_effect *)3, &vertices->m_sh_ui.m_object->__vftable);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v11 = *v6;
      v12 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 3;
      v13 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v12;
      if ( v12 )
        *((_DWORD *)m_conflicted_key_name + 529) = 3;
      vostok::render::backend::flush(v9, (int)m_conflicted_key_name);
      if ( v13[104] )
        ++*((_DWORD *)v13 + 25);
      (*(void (__stdcall **)(int, unsigned int, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                             + 52))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v11,
        prim_type);
    }
    else
    {
      if ( point_typea )
      {
        v8 = 1;
        if ( point_typea != 1 )
          v8 = 2;
      }
      else
      {
        v8 = 0;
      }
      vostok::render::res_effect::apply((vostok::render::res_effect *)v8, &vertices->m_sh_ui.m_object->__vftable);
      vostok::render::backend::render_indexed(
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
        (3 * *v6) >> 1,
        D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
        0,
        prim_type);
    }
  }
}
