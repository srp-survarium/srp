void __userpurge vostok::render::hw_hiz_occlusion_manager::render_occluders(
        vostok::render::hw_hiz_occlusion_manager *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::render::renderer_context *in_context)
{
  int y; // eax
  int v5; // edx
  double v6; // st7
  int v7; // eax
  int v8; // ecx
  const char *m_conflicted_key_name; // eax
  vostok::render::backend *v10; // ecx
  const vostok::math::float4x4 *v11; // xmm0_4
  int v12; // ecx
  int v13; // ecx
  _DWORD *v14; // eax
  unsigned int v15; // ecx
  const char *v16; // esi
  vostok::render::backend *v17; // ecx
  int v18; // eax
  bool v19; // zf
  float v20; // [esp+24h] [ebp-80h]
  int v21; // [esp+2Ch] [ebp-78h] BYREF
  D3D11_VIEWPORT view_port; // [esp+34h] [ebp-70h] BYREF
  D3D11_VIEWPORT prev_view_port; // [esp+4Ch] [ebp-58h] BYREF
  vostok::math::float4x4 dst; // [esp+64h] [ebp-40h] BYREF

  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  v21 = 1;
  (*(void (__stdcall **)(int, int *, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(y, &v21, &prev_view_port);
  v5 = a2[55];
  view_port.Width = (float)(unsigned int)a2[54];
  v6 = (double)(int)a2[55];
  if ( v5 < 0 )
    v6 = v6 + 4294967300.0;
  view_port.Height = v6;
  view_port.MinDepth = 0.0;
  LODWORD(view_port.MaxDepth) = clear_value;
  view_port.TopLeftX = 0.0;
  view_port.TopLeftY = 0.0;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &view_port);
  v7 = a2[34];
  if ( v7 )
    v8 = *(_DWORD *)(v7 + 16);
  else
    v8 = 0;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) != v8 )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v8;
    *((_BYTE *)m_conflicted_key_name + 163) = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 536) )
  {
    *((_DWORD *)m_conflicted_key_name + 536) = 0;
    *((_BYTE *)m_conflicted_key_name + 164) = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 537) )
  {
    *((_DWORD *)m_conflicted_key_name + 537) = 0;
    *((_BYTE *)m_conflicted_key_name + 165) = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 538) )
  {
    *((_DWORD *)m_conflicted_key_name + 538) = 0;
    *((_BYTE *)m_conflicted_key_name + 166) = 1;
  }
  v10 = (vostok::render::backend *)a2[50];
  if ( v10 )
    v10 = (vostok::render::backend *)v10->num_vss_changes;
  v11 = clear_value;
  *((_BYTE *)m_conflicted_key_name + 167) |= *((_DWORD *)m_conflicted_key_name + 539) != (_DWORD)v10;
  *((_DWORD *)m_conflicted_key_name + 539) = v10;
  vostok::render::backend::clear_render_targets(v10, (int)m_conflicted_key_name, *(float *)&v11, 1.0, 1.0, 1.0, v20);
  if ( s_debug_enabled_ds_clearing_value )
  {
    v12 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539);
    if ( v12 )
      (*(void (__stdcall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                           + 212))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v12,
        3,
        1.0,
        0);
  }
  memset((int)&dst, 0, sizeof(dst));
  dst.i.x = 3.0;
  dst.j.y = 3.0;
  dst.k.z = 3.0;
  LODWORD(dst.c.w) = clear_value;
  vostok::render::renderer_context::set_w(v13, &dst, in_context);
  v14 = (_DWORD *)a2[1];
  v15 = (v14[71] - v14[70]) >> 2;
  if ( v15 > 3 )
  {
    v14[69] = 3;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v15, (int)v14);
  }
  vostok::render::sphere_occluder_geometry::render((vostok::render::sphere_occluder_geometry *)v15);
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &prev_view_port);
  v16 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::reset_render_targets(
    v17,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v18 = *((_DWORD *)v16 + 547);
  v19 = *((_DWORD *)v16 + 539) == v18;
  *((_DWORD *)v16 + 539) = v18;
  *((_BYTE *)v16 + 167) |= !v19;
}
