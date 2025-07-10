void __userpurge vostok::render::backend::clear_render_targets(
        vostok::render::backend *this@<ecx>,
        int a2@<eax>,
        float a3@<xmm0>,
        float g,
        float b,
        float a,
        float a7)
{
  _DWORD *v7; // esi
  int v8; // edi
  float color_elements[4]; // [esp+0h] [ebp-10h] BYREF

  if ( s_debug_enabled_rt_clearing_value )
  {
    color_elements[0] = a3;
    color_elements[1] = g;
    color_elements[2] = b;
    color_elements[3] = a;
    v7 = (_DWORD *)(a2 + 2140);
    v8 = 4;
    do
    {
      if ( *v7 )
        (*(void (__stdcall **)(int, _DWORD, float *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 200))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          *v7,
          color_elements);
      ++v7;
      --v8;
    }
    while ( v8 );
  }
}
