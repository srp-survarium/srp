void __usercall vostok::render::samplers_handler<2>::apply(
        vostok::render::samplers_handler<2> *this@<ecx>,
        unsigned int *a2@<eax>)
{
  ID3D11SamplerState **v3; // esi
  vostok::render::samplers_handler<0> *v4; // ecx
  unsigned int end; // [esp+8h] [ebp-4h] BYREF

  v3 = (ID3D11SamplerState **)(a2 + 2);
  memset((int)(a2 + 2), 0, 0x40u);
  end = 0;
  vostok::render::samplers_handler<0>::fill_changes_buffer(v4, a2, v3, &end);
  if ( end != *a2 )
    (*(void (__stdcall **)(int, unsigned int, unsigned int, unsigned int *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                           + 128))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      *a2,
      end - *a2,
      &a2[*a2 + 2]);
  *a2 = 0;
  a2[1] = 0;
}
