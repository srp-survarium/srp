void __usercall vostok::render::constants_handler<1>::apply(
        vostok::render::constants_handler<1> *this@<ecx>,
        unsigned int *a2@<esi>)
{
  unsigned int v2; // ebx
  unsigned int v3; // edi
  vostok::render::constants_handler<0> *v4; // ecx
  unsigned int end; // [esp+8h] [ebp-40h] BYREF
  ID3D11Buffer *tmp_buffer[15]; // [esp+Ch] [ebp-3Ch] BYREF

  v2 = a2[1];
  v3 = *a2;
  if ( v2 != *a2 )
  {
    memset((int)tmp_buffer, 0, sizeof(tmp_buffer));
    vostok::render::constants_handler<2>::fill_changes_buffer(v4, a2, tmp_buffer, &end);
    (*(void (__stdcall **)(int, unsigned int, unsigned int, ID3D11Buffer **))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                            + 64))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v3,
      v2 - v3,
      &tmp_buffer[v3]);
    a2[1] = 0;
    *a2 = 0;
  }
}
