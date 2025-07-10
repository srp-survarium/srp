void __thiscall vostok::render::stage_lights::fill_surface(
        vostok::render::stage_lights *this,
        vostok::render::stage_lights *surf,
        vostok::render::resource_manager *surfa)
{
  unsigned int sl_created; // ecx
  const char *m_conflicted_key_name; // eax
  _DWORD *v5; // eax
  unsigned int v6; // xmm0_4
  survarium::game *m_game; // edx
  const char *v8; // eax
  vostok::render::backend *v9; // ecx
  unsigned int v10; // esi
  const char *v11; // edi
  const char *v12; // ebp
  bool v13; // al
  unsigned int offset[3]; // [esp+Ch] [ebp-20h] BYREF
  unsigned __int64 v15; // [esp+18h] [ebp-14h]
  __int64 v16; // [esp+20h] [ebp-Ch]

  if ( surfa )
    sl_created = surfa->sl_created;
  else
    sl_created = 0;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) != sl_created )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = sl_created;
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
  *((_BYTE *)m_conflicted_key_name + 167) |= *((_DWORD *)m_conflicted_key_name + 539) != 0;
  *((_DWORD *)m_conflicted_key_name + 539) = 0;
  v5 = vostok::render::vertex_buffer::lock(
         (vostok::render::vertex_buffer *)(m_conflicted_key_name + 40),
         4u,
         0x18u,
         offset);
  v6 = (unsigned int)clear_value;
  *(_QWORD *)v5 = 0xBF800000BF800000uLL;
  HIDWORD(v16) = v6;
  v5[5] = v6;
  LODWORD(v16) = 0;
  *((_QWORD *)v5 + 1) = v16;
  v5[4] = 0;
  v5 += 6;
  LODWORD(v15) = -1082130432;
  HIDWORD(v15) = v6;
  *(_QWORD *)v5 = v15;
  HIDWORD(v16) = v6;
  LODWORD(v16) = 0;
  *((_QWORD *)v5 + 1) = v16;
  v5[4] = 0;
  v5[5] = 0;
  v5 += 6;
  v15 = v6 | 0xBF80000000000000uLL;
  *(_QWORD *)v5 = v15;
  v5[4] = v6;
  v5[5] = v6;
  HIDWORD(v16) = v6;
  LODWORD(v16) = 0;
  *((_QWORD *)v5 + 1) = v16;
  v5 += 6;
  offset[1] = v6;
  v5[4] = v6;
  LODWORD(v15) = v6;
  HIDWORD(v15) = v6;
  HIDWORD(v16) = v6;
  *(_QWORD *)v5 = v15;
  offset[2] = 0;
  v5[5] = 0;
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  LODWORD(v16) = 0;
  *((_QWORD *)v5 + 1) = v16;
  v8 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 12) += *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 14) * *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 15);
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 60))(
    m_game->m_game_world.m_mouse_pos.y,
    *(_DWORD *)(*((_DWORD *)v8 + 10) + 4),
    0);
  vostok::render::res_geometry::apply(surf->m_screen_vertex_geometry.m_object);
  v10 = 6;
  v11 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v12 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v13 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v13;
  if ( v13 )
    *((_DWORD *)v11 + 529) = 4;
  vostok::render::backend::flush(v9, (int)v11);
  if ( v12[104] )
  {
    ++*((_DWORD *)v12 + 25);
    v10 = 3 * s_max_triagles_per_dip_value < 6 ? 3 * s_max_triagles_per_dip_value - 6 + 6 : 6;
  }
  if ( !v12[37] )
    (*(void (__stdcall **)(int, unsigned int, _DWORD, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                   + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v10,
      0,
      offset[0]);
  *((_DWORD *)v12 + 21) += v10 / 3;
  if ( surfa )
  {
    if ( !--surfa->sh_created )
      vostok::render::resource_manager::release(
        surfa,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)surfa);
  }
}
