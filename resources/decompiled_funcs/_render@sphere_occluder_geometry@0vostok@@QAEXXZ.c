void __usercall vostok::render::sphere_occluder_geometry::render(
        vostok::render::sphere_occluder_geometry *this@<ecx>,
        vostok::render::res_geometry **a2@<eax>)
{
  const char *m_conflicted_key_name; // edi
  unsigned int v3; // esi
  bool v4; // al
  const char *v5; // ebx

  vostok::render::res_geometry::apply(*a2);
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v3 = 540;
  v4 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
  v5 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v4;
  if ( v4 )
    *((_DWORD *)m_conflicted_key_name + 529) = 4;
  vostok::render::backend::flush((vostok::render::backend *)4, (int)m_conflicted_key_name);
  if ( v5[104] )
  {
    ++*((_DWORD *)v5 + 25);
    v3 = 3 * s_max_triagles_per_dip_value < 0x21C ? 3 * s_max_triagles_per_dip_value - 540 + 540 : 540;
  }
  if ( !v5[37] )
    (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                             + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v3,
      0,
      0);
  *((_DWORD *)v5 + 21) += v3 / 3;
}
