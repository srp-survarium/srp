void __fastcall vostok::render::backend::get_viewport(
        unsigned int a1,
        D3D11_VIEWPORT *viewport,
        vostok::render::backend *this)
{
  int y; // eax
  unsigned int count; // [esp+0h] [ebp-4h] BYREF

  count = a1;
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  count = 1;
  (*(void (__stdcall **)(int, unsigned int *, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(y, &count, viewport);
}
