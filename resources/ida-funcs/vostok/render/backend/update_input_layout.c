void __usercall vostok::render::backend::update_input_layout(vostok::render::backend *this@<ecx>, int a2@<esi>)
{
  int v2; // eax

  if ( *(_BYTE *)(a2 + 145) )
  {
    v2 = *(_DWORD *)(a2 + 184);
    if ( v2 )
    {
      if ( !*(_DWORD *)(a2 + 2136) )
        *(_DWORD *)(a2 + 2136) = vostok::render::res_declaration::get(
                                   *(vostok::render::res_declaration **)(a2 + 2132),
                                   *(const vostok::render::res_signature **)(v2 + 12156));
      (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                         + 68))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        *(_DWORD *)(*(_DWORD *)(a2 + 2136) + 4));
    }
  }
}
