void __thiscall vostok::render::hw_hiz_point_list::render(
        vostok::render::hw_hiz_point_list *this,
        unsigned int num_points)
{
  const char *m_conflicted_key_name; // edi
  bool v3; // al
  vostok::render::untyped_buffer *m_object; // eax
  BOOL v5; // ecx
  bool v6; // zf

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( (vostok::render::res_declaration *)*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                          + 533) == this->m_declaration.m_object )
  {
    *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 145) = 0;
  }
  else
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 533) = this->m_declaration.m_object;
    *((_BYTE *)m_conflicted_key_name + 144) = 1;
    *((_DWORD *)m_conflicted_key_name + 534) = 0;
    *((_BYTE *)m_conflicted_key_name + 145) = 1;
  }
  v3 = *((_DWORD *)m_conflicted_key_name + 45) || *((_DWORD *)m_conflicted_key_name + 554);
  *((_BYTE *)m_conflicted_key_name + 143) |= v3;
  *((_DWORD *)m_conflicted_key_name + 45) = 0;
  *((_DWORD *)m_conflicted_key_name + 554) = 0;
  m_object = this->m_vertex_buffer.m_object;
  v5 = *((vostok::render::untyped_buffer **)m_conflicted_key_name + 42) != m_object
    || *((_DWORD *)m_conflicted_key_name + 548) != 24
    || *((_DWORD *)m_conflicted_key_name + 549);
  *((_BYTE *)m_conflicted_key_name + 140) |= v5;
  v6 = *((_DWORD *)m_conflicted_key_name + 529) == 1;
  *((_DWORD *)m_conflicted_key_name + 42) = m_object;
  *((_DWORD *)m_conflicted_key_name + 548) = 24;
  *((_DWORD *)m_conflicted_key_name + 549) = 0;
  *((_BYTE *)m_conflicted_key_name + 162) = !v6;
  if ( !v6 )
    *((_DWORD *)m_conflicted_key_name + 529) = 1;
  vostok::render::backend::flush((vostok::render::backend *)v5, (int)m_conflicted_key_name);
  if ( m_conflicted_key_name[104] )
    ++*((_DWORD *)m_conflicted_key_name + 25);
  (*(void (__stdcall **)(int, unsigned int, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                   + 52))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    num_points,
    0);
  *((_DWORD *)m_conflicted_key_name + 22) += num_points;
}
