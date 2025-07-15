void __thiscall vostok::render::stage_atmosphere::fill_surfaces(
        vostok::render::stage_atmosphere *this,
        vostok::render::stage_atmosphere *surf0,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> surf1,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> use_base_depth_stencil,
        unsigned int offset)
{
  ID3D11RenderTargetView *m_rt; // edx
  const char *m_conflicted_key_name; // eax
  ID3D11RenderTargetView *v7; // edx
  ID3D11RenderTargetView *v8; // edx
  int v9; // esi
  bool v10; // zf
  int y; // eax
  unsigned __int64 *v12; // eax
  unsigned int v13; // xmm0_4
  survarium::game *m_game; // edx
  const char *v15; // eax
  vostok::render::backend *v16; // ecx
  unsigned int v17; // esi
  const char *v18; // edi
  const char *v19; // ebp
  bool v20; // al
  survarium::game *v21; // ecx
  vostok::render::resource_manager *v22; // ecx
  unsigned __int64 v23; // [esp+20h] [ebp-44h]
  unsigned __int64 v24; // [esp+28h] [ebp-3Ch]
  D3D11_VIEWPORT view_port; // [esp+30h] [ebp-34h] BYREF
  D3D11_VIEWPORT view_port_saved; // [esp+48h] [ebp-1Ch] BYREF

  if ( use_base_depth_stencil.m_object )
  {
    if ( surf1.m_object )
      m_rt = surf1.m_object->m_rt;
    else
      m_rt = 0;
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != m_rt )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
      *((_BYTE *)m_conflicted_key_name + 163) = 1;
    }
    v7 = use_base_depth_stencil.m_object->m_rt;
    if ( *((ID3D11RenderTargetView **)m_conflicted_key_name + 536) != v7 )
    {
      *((_DWORD *)m_conflicted_key_name + 536) = v7;
LABEL_16:
      *((_BYTE *)m_conflicted_key_name + 164) = 1;
    }
  }
  else
  {
    if ( surf1.m_object )
      v8 = surf1.m_object->m_rt;
    else
      v8 = 0;
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != v8 )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = v8;
      *((_BYTE *)m_conflicted_key_name + 163) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 536) )
    {
      *((_DWORD *)m_conflicted_key_name + 536) = 0;
      goto LABEL_16;
    }
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
  if ( (_BYTE)offset )
  {
    v9 = *((_DWORD *)m_conflicted_key_name + 547);
    v10 = *((_DWORD *)m_conflicted_key_name + 539) == v9;
    *((_DWORD *)m_conflicted_key_name + 539) = v9;
  }
  else
  {
    v10 = *((_DWORD *)m_conflicted_key_name + 539) == 0;
    *((_DWORD *)m_conflicted_key_name + 539) = 0;
  }
  *((_BYTE *)m_conflicted_key_name + 167) |= !v10;
  view_port.Width = (float)surf1.m_object->m_width;
  offset = surf1.m_object->m_height;
  view_port.Height = (float)offset;
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  LODWORD(view_port.MaxDepth) = clear_value;
  view_port.MinDepth = 0.0;
  view_port.TopLeftX = 0.0;
  view_port.TopLeftY = 0.0;
  offset = 1;
  (*(void (__stdcall **)(int, unsigned int *, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(y, &offset, &view_port_saved);
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &view_port);
  v12 = (unsigned __int64 *)vostok::render::vertex_buffer::lock(
                              (vostok::render::vertex_buffer *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                              + 40),
                              4u,
                              0x18u,
                              &offset);
  v13 = (unsigned int)clear_value;
  *v12 = 0xBF800000BF800000uLL;
  LODWORD(v24) = 0;
  HIDWORD(v24) = v13;
  v12[1] = v24;
  *((_DWORD *)v12 + 4) = 0;
  *((_DWORD *)v12 + 5) = v13;
  v12 += 3;
  LODWORD(v23) = -1082130432;
  HIDWORD(v23) = v13;
  *v12 = v23;
  *((_DWORD *)v12 + 4) = 0;
  *((_DWORD *)v12 + 5) = 0;
  LODWORD(v24) = 0;
  HIDWORD(v24) = v13;
  v12[1] = v24;
  v12 += 3;
  *v12 = v13 | 0xBF80000000000000uLL;
  LODWORD(v24) = 0;
  HIDWORD(v24) = v13;
  v12[1] = v24;
  *((_DWORD *)v12 + 4) = v13;
  *((_DWORD *)v12 + 5) = v13;
  v12 += 3;
  *((_DWORD *)v12 + 4) = v13;
  LODWORD(v23) = v13;
  HIDWORD(v23) = v13;
  HIDWORD(v24) = v13;
  *v12 = v23;
  *((_DWORD *)v12 + 5) = 0;
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  LODWORD(v24) = 0;
  v12[1] = v24;
  v15 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 12) += *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 14) * *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 15);
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 60))(
    m_game->m_game_world.m_mouse_pos.y,
    *(_DWORD *)(*((_DWORD *)v15 + 10) + 4),
    0);
  vostok::render::res_geometry::apply(surf0->m_screen_vertex_geometry.m_object);
  v17 = 6;
  v18 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v19 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v20 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v20;
  if ( v20 )
    *((_DWORD *)v18 + 529) = 4;
  vostok::render::backend::flush(v16, (int)v18);
  if ( v19[104] )
  {
    ++*((_DWORD *)v19 + 25);
    v17 = 3 * s_max_triagles_per_dip_value < 6 ? 3 * s_max_triagles_per_dip_value - 6 + 6 : 6;
  }
  if ( !v19[37] )
    (*(void (__stdcall **)(int, unsigned int, _DWORD, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                   + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v17,
      0,
      offset);
  v21 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  *((_DWORD *)v19 + 21) += v17 / 3;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)v21->m_game_world.m_mouse_pos.y + 176))(
    v21->m_game_world.m_mouse_pos.y,
    1,
    &view_port_saved);
  if ( surf1.m_object )
  {
    if ( !--surf1.m_object->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)surf1.m_object);
  }
  if ( use_base_depth_stencil.m_object )
  {
    if ( !--use_base_depth_stencil.m_object->m_reference_count )
      vostok::render::resource_manager::release(
        v22,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)use_base_depth_stencil.m_object);
  }
}
