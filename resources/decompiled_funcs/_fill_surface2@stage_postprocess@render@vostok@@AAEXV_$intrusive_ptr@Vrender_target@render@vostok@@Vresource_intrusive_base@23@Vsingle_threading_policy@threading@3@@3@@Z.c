void __thiscall vostok::render::stage_postprocess::fill_surface2(
        vostok::render::stage_postprocess *this,
        vostok::render::stage_postprocess *surf,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> surfa)
{
  ID3D11RenderTargetView *m_rt; // ecx
  const char *m_conflicted_key_name; // eax
  _DWORD *v5; // eax
  unsigned int v6; // xmm0_4
  survarium::game *m_game; // edx
  const char *v8; // eax
  int y; // eax
  const char *v10; // edi
  unsigned int v11; // esi
  bool v12; // al
  const char *v13; // ebx
  survarium::game *v14; // eax
  int v15; // [esp+20h] [ebp-50h] BYREF
  unsigned int offset[3]; // [esp+24h] [ebp-4Ch] BYREF
  unsigned __int64 v17; // [esp+30h] [ebp-40h]
  __int64 v18; // [esp+38h] [ebp-38h]
  D3D11_VIEWPORT tmp_viewport; // [esp+40h] [ebp-30h] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+58h] [ebp-18h] BYREF

  if ( surfa.m_object )
    m_rt = surfa.m_object->m_rt;
  else
    m_rt = 0;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
       + 535) != m_rt )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
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
  *((_BYTE *)m_conflicted_key_name + 167) |= *((_DWORD *)m_conflicted_key_name + 539) != 0;
  *((_DWORD *)m_conflicted_key_name + 539) = 0;
  v5 = vostok::render::vertex_buffer::lock(
         (vostok::render::vertex_buffer *)(m_conflicted_key_name + 40),
         4u,
         0x18u,
         offset);
  v6 = (unsigned int)clear_value;
  *(_QWORD *)v5 = 0xBF800000BF800000uLL;
  HIDWORD(v18) = v6;
  v5[5] = v6;
  LODWORD(v18) = 0;
  *((_QWORD *)v5 + 1) = v18;
  v5[4] = 0;
  v5 += 6;
  LODWORD(v17) = -1082130432;
  HIDWORD(v17) = v6;
  *(_QWORD *)v5 = v17;
  HIDWORD(v18) = v6;
  LODWORD(v18) = 0;
  *((_QWORD *)v5 + 1) = v18;
  v5[4] = 0;
  v5[5] = 0;
  v5 += 6;
  v17 = v6 | 0xBF80000000000000uLL;
  *(_QWORD *)v5 = v17;
  v5[4] = v6;
  v5[5] = v6;
  HIDWORD(v18) = v6;
  LODWORD(v18) = 0;
  *((_QWORD *)v5 + 1) = v18;
  v5 += 6;
  offset[1] = v6;
  v5[4] = v6;
  LODWORD(v17) = v6;
  HIDWORD(v17) = v6;
  HIDWORD(v18) = v6;
  *(_QWORD *)v5 = v17;
  offset[2] = 0;
  v5[5] = 0;
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  LODWORD(v18) = 0;
  *((_QWORD *)v5 + 1) = v18;
  v8 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 12) += *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 14) * *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 15);
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 60))(
    m_game->m_game_world.m_mouse_pos.y,
    *(_DWORD *)(*((_DWORD *)v8 + 10) + 4),
    0);
  vostok::render::res_geometry::apply(surf->m_screen_vertex_geometry.m_object);
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  v15 = 1;
  (*(void (__stdcall **)(int, int *, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(y, &v15, &orig_viewport);
  tmp_viewport.TopLeftX = 0.0;
  tmp_viewport.TopLeftY = 0.0;
  tmp_viewport.Width = (float)surfa.m_object->m_width;
  tmp_viewport.Height = (float)surfa.m_object->m_height;
  tmp_viewport.MinDepth = 0.0;
  LODWORD(tmp_viewport.MaxDepth) = clear_value;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &tmp_viewport);
  v10 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v11 = 6;
  v12 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
  v13 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v12;
  if ( v12 )
    *((_DWORD *)v10 + 529) = 4;
  vostok::render::backend::flush((vostok::render::backend *)4, (int)v10);
  if ( v13[104] )
  {
    ++*((_DWORD *)v13 + 25);
    v11 = 3 * s_max_triagles_per_dip_value < 6 ? 3 * s_max_triagles_per_dip_value - 6 + 6 : 6;
  }
  if ( !v13[37] )
    (*(void (__stdcall **)(int, unsigned int, _DWORD, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                   + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v11,
      0,
      offset[0]);
  v14 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  *((_DWORD *)v13 + 21) += v11 / 3;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)v14->m_game_world.m_mouse_pos.y + 176))(
    v14->m_game_world.m_mouse_pos.y,
    1,
    &orig_viewport);
  if ( surfa.m_object )
  {
    if ( !--surfa.m_object->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)surfa.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)surfa.m_object);
  }
}
