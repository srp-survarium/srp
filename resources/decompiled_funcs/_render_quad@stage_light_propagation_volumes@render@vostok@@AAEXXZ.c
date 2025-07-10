void __thiscall vostok::render::stage_light_propagation_volumes::render_quad(
        vostok::render::stage_light_propagation_volumes *this,
        vostok::render::stage_light_propagation_volumes *thisa)
{
  _DWORD *v2; // eax
  unsigned int v3; // xmm0_4
  survarium::game *m_game; // edx
  const char *m_conflicted_key_name; // eax
  vostok::render::backend *v6; // ecx
  unsigned int v7; // esi
  const char *v8; // edi
  const char *v9; // ebx
  bool v10; // al
  unsigned int offset[3]; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned __int64 v12; // [esp+18h] [ebp-10h]
  __int64 v13; // [esp+20h] [ebp-8h]

  v2 = vostok::render::vertex_buffer::lock(
         (vostok::render::vertex_buffer *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                         + 40),
         4u,
         0x18u,
         offset);
  v3 = (unsigned int)clear_value;
  *(_QWORD *)v2 = 0xBF800000BF800000uLL;
  HIDWORD(v13) = v3;
  v2[5] = v3;
  LODWORD(v13) = 0;
  *((_QWORD *)v2 + 1) = v13;
  v2[4] = 0;
  v2 += 6;
  LODWORD(v12) = -1082130432;
  HIDWORD(v12) = v3;
  *(_QWORD *)v2 = v12;
  HIDWORD(v13) = v3;
  LODWORD(v13) = 0;
  *((_QWORD *)v2 + 1) = v13;
  v2[4] = 0;
  v2[5] = 0;
  v2 += 6;
  v12 = v3 | 0xBF80000000000000uLL;
  *(_QWORD *)v2 = v12;
  v2[4] = v3;
  v2[5] = v3;
  HIDWORD(v13) = v3;
  LODWORD(v13) = 0;
  *((_QWORD *)v2 + 1) = v13;
  v2 += 6;
  offset[1] = v3;
  v2[4] = v3;
  LODWORD(v12) = v3;
  HIDWORD(v12) = v3;
  HIDWORD(v13) = v3;
  *(_QWORD *)v2 = v12;
  offset[2] = 0;
  v2[5] = 0;
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  LODWORD(v13) = 0;
  *((_QWORD *)v2 + 1) = v13;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 12) += *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 14) * *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 15);
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 60))(
    m_game->m_game_world.m_mouse_pos.y,
    *(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 10) + 4),
    0);
  vostok::render::res_geometry::apply(thisa->m_screen_vertex_geometry.m_object);
  v7 = 6;
  v8 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v9 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v10 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v10;
  if ( v10 )
    *((_DWORD *)v8 + 529) = 4;
  vostok::render::backend::flush(v6, (int)v8);
  if ( v9[104] )
  {
    ++*((_DWORD *)v9 + 25);
    v7 = 3 * s_max_triagles_per_dip_value < 6 ? 3 * s_max_triagles_per_dip_value - 6 + 6 : 6;
  }
  if ( !v9[37] )
    (*(void (__stdcall **)(int, unsigned int, _DWORD, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                   + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v7,
      0,
      offset[0]);
  *((_DWORD *)v9 + 21) += v7 / 3;
}
