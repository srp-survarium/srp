void __thiscall vostok::render::sky_dome_geometry::draw(vostok::render::sky_dome_geometry *this)
{
  const char *m_conflicted_key_name; // edi
  vostok::render::untyped_buffer *m_object; // edx
  unsigned int m_stride; // esi
  bool v4; // al
  vostok::render::untyped_buffer *v5; // eax
  bool v6; // dl
  unsigned int m_num_indices; // ebp
  bool v8; // al

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( (vostok::render::res_declaration *)*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                          + 533) == this->m_vertext_declaration.m_object )
  {
    *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 145) = 0;
  }
  else
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 533) = this->m_vertext_declaration.m_object;
    *((_BYTE *)m_conflicted_key_name + 144) = 1;
    *((_DWORD *)m_conflicted_key_name + 534) = 0;
    *((_BYTE *)m_conflicted_key_name + 145) = 1;
  }
  m_object = this->m_vertex_buffer.m_object;
  m_stride = this->m_stride;
  v4 = *((vostok::render::untyped_buffer **)m_conflicted_key_name + 42) != m_object
    || m_stride != *((_DWORD *)m_conflicted_key_name + 548)
    || *((_DWORD *)m_conflicted_key_name + 549);
  *((_BYTE *)m_conflicted_key_name + 140) |= v4;
  *((_DWORD *)m_conflicted_key_name + 42) = m_object;
  *((_DWORD *)m_conflicted_key_name + 548) = m_stride;
  *((_DWORD *)m_conflicted_key_name + 549) = 0;
  v5 = this->m_index_buffer.m_object;
  v6 = *((vostok::render::untyped_buffer **)m_conflicted_key_name + 45) != v5
    || *((_DWORD *)m_conflicted_key_name + 554);
  *((_BYTE *)m_conflicted_key_name + 143) |= v6;
  *((_DWORD *)m_conflicted_key_name + 45) = v5;
  *((_DWORD *)m_conflicted_key_name + 554) = 0;
  m_num_indices = this->m_num_indices;
  v8 = *((_DWORD *)m_conflicted_key_name + 529) != 4;
  *((_BYTE *)m_conflicted_key_name + 162) = v8;
  if ( v8 )
    *((_DWORD *)m_conflicted_key_name + 529) = 4;
  vostok::render::backend::flush((vostok::render::backend *)4, (int)m_conflicted_key_name);
  if ( m_conflicted_key_name[104] )
  {
    ++*((_DWORD *)m_conflicted_key_name + 25);
    m_num_indices += 3 * s_max_triagles_per_dip_value < m_num_indices
                   ? 3 * s_max_triagles_per_dip_value - m_num_indices
                   : 0;
  }
  if ( !m_conflicted_key_name[37] )
    (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                             + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      m_num_indices,
      0,
      0);
  *((_DWORD *)m_conflicted_key_name + 21) += m_num_indices / 3;
}
