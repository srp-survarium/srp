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
