void __thiscall vostok::render::textures_handler<1>::apply(
        vostok::render::textures_handler<1> *this,
        vostok::render::textures_handler<1> *thisa)
{
  int v2; // edi
  int v3; // ebx
  ID3D11ShaderResourceView **v4; // esi
  ID3D11ShaderResourceView **m_tmp_buffer; // ebp
  int end; // [esp+Ch] [ebp-204h] BYREF
  ID3D11ShaderResourceView *tmp_buffer[128]; // [esp+10h] [ebp-200h] BYREF

  v2 = 0;
  memset((int)tmp_buffer, 0, sizeof(tmp_buffer));
  vostok::render::textures_handler<1>::fill_changes_buffer(
    (vostok::render::textures_handler<0> *)&end,
    thisa,
    tmp_buffer,
    &end);
  if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 38)
    && (v3 = thisa->m_diff_range_end - thisa->m_diff_range_start, v3 > 0) )
  {
    v4 = tmp_buffer;
    m_tmp_buffer = thisa->m_tmp_buffer;
    do
    {
      if ( *v4 != *m_tmp_buffer )
      {
        (*(void (__stdcall **)(int, int, int, ID3D11ShaderResourceView **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                          + 32))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          v2,
          1,
          v4);
        *m_tmp_buffer = *v4;
      }
      ++v2;
      ++v4;
      ++m_tmp_buffer;
    }
    while ( v2 < v3 );
    thisa->m_diff_range_end = 0;
    thisa->m_diff_range_start = 0;
  }
  else
  {
    thisa->m_diff_range_start = 0;
    thisa->m_diff_range_end = 0;
  }
}


void __usercall vostok::render::textures_handler<2>::apply(
        vostok::render::textures_handler<2> *this@<ecx>,
        int a2@<esi>)
{
  vostok::render::textures_handler<0> *v2; // ecx
  int v3; // eax
  int v4; // ecx
  int end; // [esp+8h] [ebp-4h] BYREF

  memset(a2 + 12, 0, 0x200u);
  vostok::render::textures_handler<1>::fill_changes_buffer(
    v2,
    (_DWORD *)a2,
    (ID3D11ShaderResourceView **)(a2 + 12),
    &end);
  v3 = *(_DWORD *)(a2 + 4);
  v4 = *(_DWORD *)(a2 + 8) - v3;
  if ( v4 > 0 )
    (*(void (__stdcall **)(int, int, int, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                              + 124))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v3,
      v4,
      a2 + 4 * v3 + 12);
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
}


void __usercall vostok::render::textures_handler<0>::apply(
        vostok::render::textures_handler<0> *this@<ecx>,
        int a2@<esi>)
{
  vostok::render::textures_handler<0> *v2; // ecx
  int v3; // eax
  int v4; // ecx
  int end; // [esp+8h] [ebp-4h] BYREF

  memset(a2 + 12, 0, 0x200u);
  vostok::render::textures_handler<1>::fill_changes_buffer(
    v2,
    (_DWORD *)a2,
    (ID3D11ShaderResourceView **)(a2 + 12),
    &end);
  v3 = *(_DWORD *)(a2 + 4);
  v4 = *(_DWORD *)(a2 + 8) - v3;
  if ( v4 > 0 )
    (*(void (__stdcall **)(int, int, int, int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                              + 100))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v3,
      v4,
      a2 + 4 * v3 + 12);
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
}
