void __userpurge vostok::render::backend::clear_render_targets(
        vostok::render::backend *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::math::color color0,
        vostok::math::color color1,
        vostok::math::color color2,
        vostok::math::color color3)
{
  int v7; // ecx
  double v8; // st7
  int y; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  float color_elements[4]; // [esp+28h] [ebp-10h] BYREF

  if ( s_debug_enabled_rt_clearing_value )
  {
    v7 = a2[535];
    v8 = 0.0039215689;
    if ( v7 )
    {
      color_elements[0] = (double)color0.r * 0.0039215689;
      color_elements[1] = (double)color0.g * 0.0039215689;
      color_elements[2] = (double)color0.b * 0.0039215689;
      y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
      color_elements[3] = 0.0039215689 * (double)color0.a;
      (*(void (__stdcall **)(int, int, float *))(*(_DWORD *)y + 200))(y, v7, color_elements);
      v8 = 0.0039215689;
    }
    v10 = a2[536];
    if ( v10 )
    {
      color_elements[0] = (double)color1.r * v8;
      color_elements[1] = (double)color1.g * v8;
      color_elements[2] = (double)color1.b * v8;
      color_elements[3] = v8 * (double)color1.a;
      (*(void (__stdcall **)(int, int, float *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                               + 200))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v10,
        color_elements);
      v8 = 0.0039215689;
    }
    v11 = a2[537];
    if ( v11 )
    {
      color_elements[0] = (double)color2.r * v8;
      color_elements[1] = (double)color2.g * v8;
      color_elements[2] = (double)color2.b * v8;
      color_elements[3] = v8 * (double)color2.a;
      (*(void (__stdcall **)(int, int, float *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                               + 200))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v11,
        color_elements);
      v8 = 0.0039215689;
    }
    v12 = a2[538];
    if ( v12 )
    {
      color_elements[0] = (double)color3.r * v8;
      color_elements[1] = (double)color3.g * v8;
      color_elements[2] = (double)color3.b * v8;
      color_elements[3] = v8 * (double)color3.a;
      (*(void (__stdcall **)(int, int, float *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                               + 200))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v12,
        color_elements);
    }
  }
}
