void __thiscall vostok::render::decal_instance::render_geometry(vostok::render::decal_instance *this)
{
  const char *m_conflicted_key_name; // edi
  unsigned int v2; // esi
  bool v3; // al
  const char *v4; // ebx

  vostok::render::res_geometry::apply(*(vostok::render::res_geometry **)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_waiting_for_bind_action
                                                                       + 24));
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v2 = 36;
  v3 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
  v4 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v3;
  if ( v3 )
    *((_DWORD *)m_conflicted_key_name + 529) = 4;
  vostok::render::backend::flush((vostok::render::backend *)4, (int)m_conflicted_key_name);
  if ( v4[104] )
  {
    ++*((_DWORD *)v4 + 25);
    v2 = 3 * s_max_triagles_per_dip_value < 0x24 ? 3 * s_max_triagles_per_dip_value - 36 + 36 : 36;
  }
  if ( !v4[37] )
    (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                             + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v2,
      0,
      0);
  *((_DWORD *)v4 + 21) += v2 / 3;
}
