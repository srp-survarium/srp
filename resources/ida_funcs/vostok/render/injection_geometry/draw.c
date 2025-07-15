void __usercall vostok::render::injection_geometry::draw(vostok::render::injection_geometry *this@<ecx>, int *a2@<eax>)
{
  int v3; // eax
  const char *m_conflicted_key_name; // edi
  int v5; // ecx
  int v6; // edx
  bool v7; // al
  bool v8; // al
  bool v9; // zf
  int v10; // ebp

  v3 = *a2;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 533) == v3 )
  {
    *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 145) = 0;
  }
  else
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 533) = v3;
    *((_BYTE *)m_conflicted_key_name + 144) = 1;
    *((_DWORD *)m_conflicted_key_name + 534) = 0;
    *((_BYTE *)m_conflicted_key_name + 145) = 1;
  }
  v5 = a2[1];
  v6 = a2[3];
  v7 = *((_DWORD *)m_conflicted_key_name + 42) != v5
    || v6 != *((_DWORD *)m_conflicted_key_name + 548)
    || *((_DWORD *)m_conflicted_key_name + 549);
  *((_BYTE *)m_conflicted_key_name + 140) |= v7;
  *((_DWORD *)m_conflicted_key_name + 42) = v5;
  *((_DWORD *)m_conflicted_key_name + 548) = v6;
  *((_DWORD *)m_conflicted_key_name + 549) = 0;
  v8 = *((_DWORD *)m_conflicted_key_name + 45) || *((_DWORD *)m_conflicted_key_name + 554);
  *((_BYTE *)m_conflicted_key_name + 143) |= v8;
  v9 = *((_DWORD *)m_conflicted_key_name + 529) == 1;
  *((_DWORD *)m_conflicted_key_name + 45) = 0;
  *((_DWORD *)m_conflicted_key_name + 554) = 0;
  v10 = a2[2];
  *((_BYTE *)m_conflicted_key_name + 162) = !v9;
  if ( !v9 )
    *((_DWORD *)m_conflicted_key_name + 529) = 1;
  vostok::render::backend::flush((vostok::render::backend *)1, (int)m_conflicted_key_name);
  if ( m_conflicted_key_name[104] )
    ++*((_DWORD *)m_conflicted_key_name + 25);
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                          + 52))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    v10,
    0);
  *((_DWORD *)m_conflicted_key_name + 22) += v10;
}
