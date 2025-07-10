void __usercall vostok::render::radiance_volume::begin_render_to_cells(
        vostok::render::radiance_volume *this@<ecx>,
        int a2@<esi>)
{
  int y; // eax
  const char *m_conflicted_key_name; // eax
  double v4; // st7
  int v5; // [esp+4h] [ebp-24h] BYREF
  D3D11_VIEWPORT cells_viewport; // [esp+Ch] [ebp-1Ch] BYREF

  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  v5 = 1;
  (*(void (__stdcall **)(int, int *, int))(*(_DWORD *)y + 380))(y, &v5, a2 + 96);
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 167) |= *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) != 0;
  *((_DWORD *)m_conflicted_key_name + 539) = 0;
  v4 = (double)*(unsigned int *)(a2 + 200);
  cells_viewport.TopLeftX = 0.0;
  cells_viewport.TopLeftY = 0.0;
  cells_viewport.Width = v4;
  cells_viewport.MinDepth = 0.0;
  cells_viewport.Height = v4;
  LODWORD(cells_viewport.MaxDepth) = clear_value;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &cells_viewport);
}
