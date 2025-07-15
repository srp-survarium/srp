void __usercall vostok::render::stage_lights::draw_geometry(
        vostok::render::light *l@<eax>,
        vostok::render::stage_lights *this)
{
  const char *m_conflicted_key_name; // edi
  unsigned int v3; // esi
  bool v4; // al
  const char *v5; // ebx
  int y; // eax
  const char *v7; // edi
  bool v8; // al
  const char *v9; // edi
  bool v10; // al

  switch ( *(_DWORD *)&l->flags & 0xF )
  {
    case 0:
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
      {
        y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
        goto LABEL_18;
      }
      break;
    case 1:
      v7 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v3 = 18;
      v8 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
      v5 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v8;
      if ( v8 )
        *((_DWORD *)v7 + 529) = 4;
      vostok::render::backend::flush((vostok::render::backend *)4, (int)v7);
      if ( v5[104] )
      {
        ++*((_DWORD *)v5 + 25);
        v3 = 3 * s_max_triagles_per_dip_value < 0x12 ? 3 * s_max_triagles_per_dip_value - 18 + 18 : 18;
      }
      goto LABEL_16;
    case 2:
    case 3:
      v9 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v3 = 36;
      v10 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
      v5 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v10;
      if ( v10 )
        *((_DWORD *)v9 + 529) = 4;
      vostok::render::backend::flush((vostok::render::backend *)4, (int)v9);
      if ( v5[104] )
      {
        ++*((_DWORD *)v5 + 25);
        v3 = 3 * s_max_triagles_per_dip_value < 0x24 ? 3 * s_max_triagles_per_dip_value - 36 + 36 : 36;
      }
LABEL_16:
      if ( !v5[37] )
      {
        y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
LABEL_18:
        (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)y + 48))(y, v3, 0, 0);
      }
      break;
  }
  *((_DWORD *)v5 + 21) += v3 / 3;
}
