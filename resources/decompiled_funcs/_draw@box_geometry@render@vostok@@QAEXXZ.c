void __usercall vostok::render::box_geometry::draw(vostok::render::box_geometry *this@<ecx>, _DWORD *a2@<eax>)
{
  const char *m_conflicted_key_name; // edi
  int v3; // edx
  int v4; // esi
  bool v5; // cl
  int v6; // eax
  bool v7; // cl
  bool v8; // zf
  unsigned int v9; // esi

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 533) == *a2 )
  {
    *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 145) = 0;
  }
  else
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 533) = *a2;
    *((_BYTE *)m_conflicted_key_name + 144) = 1;
    *((_DWORD *)m_conflicted_key_name + 534) = 0;
    *((_BYTE *)m_conflicted_key_name + 145) = 1;
  }
  v3 = a2[1];
  v4 = a2[3];
  v5 = *((_DWORD *)m_conflicted_key_name + 42) != v3
    || v4 != *((_DWORD *)m_conflicted_key_name + 548)
    || *((_DWORD *)m_conflicted_key_name + 549);
  *((_BYTE *)m_conflicted_key_name + 140) |= v5;
  *((_DWORD *)m_conflicted_key_name + 42) = v3;
  *((_DWORD *)m_conflicted_key_name + 548) = v4;
  *((_DWORD *)m_conflicted_key_name + 549) = 0;
  v6 = a2[2];
  v7 = *((_DWORD *)m_conflicted_key_name + 45) != v6 || *((_DWORD *)m_conflicted_key_name + 554);
  *((_BYTE *)m_conflicted_key_name + 143) |= v7;
  v8 = *((_DWORD *)m_conflicted_key_name + 529) == 4;
  *((_DWORD *)m_conflicted_key_name + 45) = v6;
  *((_DWORD *)m_conflicted_key_name + 554) = 0;
  v9 = 36;
  *((_BYTE *)m_conflicted_key_name + 162) = !v8;
  if ( !v8 )
    *((_DWORD *)m_conflicted_key_name + 529) = 4;
  vostok::render::backend::flush((vostok::render::backend *)4, (int)m_conflicted_key_name);
  if ( m_conflicted_key_name[104] )
  {
    ++*((_DWORD *)m_conflicted_key_name + 25);
    v9 = 3 * s_max_triagles_per_dip_value < 0x24 ? 3 * s_max_triagles_per_dip_value - 36 + 36 : 36;
  }
  if ( !m_conflicted_key_name[37] )
    (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                             + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v9,
      0,
      0);
  *((_DWORD *)m_conflicted_key_name + 21) += v9 / 3;
}
