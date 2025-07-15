void __thiscall vostok::render::stage_postprocess::fill_surface(
        vostok::render::stage_postprocess *this,
        vostok::render::stage_postprocess *surf0,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> surf1,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> surf1a)
{
  ID3D11RenderTargetView *m_rt; // ecx
  const char *m_conflicted_key_name; // eax
  ID3D11RenderTargetView *v6; // ecx
  char *v7; // eax
  const vostok::math::float4x4 *v8; // xmm1_4
  survarium::game *m_game; // edx
  const char *v10; // eax
  unsigned int v11; // esi
  const char *v12; // edi
  const char *v13; // ebx
  bool v14; // al
  vostok::render::resource_manager *v15; // ecx
  float t_h; // [esp+Ch] [ebp-Ch]
  float t_w; // [esp+10h] [ebp-8h]
  unsigned int offset; // [esp+14h] [ebp-4h] BYREF

  t_w = (float)surf1.m_object->m_width;
  m_rt = surf1.m_object->m_rt;
  t_h = (float)surf1.m_object->m_height;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
       + 535) != m_rt )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
    *((_BYTE *)m_conflicted_key_name + 163) = 1;
  }
  if ( surf1a.m_object )
    v6 = surf1a.m_object->m_rt;
  else
    v6 = 0;
  if ( *((ID3D11RenderTargetView **)m_conflicted_key_name + 536) != v6 )
  {
    *((_DWORD *)m_conflicted_key_name + 536) = v6;
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
  v7 = (char *)vostok::render::vertex_buffer::lock(
                 (vostok::render::vertex_buffer *)(m_conflicted_key_name + 40),
                 4u,
                 0x1Cu,
                 &offset);
  v8 = clear_value;
  *(_DWORD *)v7 = 0;
  *(_QWORD *)(v7 + 4) = LODWORD(t_h);
  *((_DWORD *)v7 + 3) = v8;
  *((_DWORD *)v7 + 5) = 0;
  *((_DWORD *)v7 + 6) = v8;
  *((_DWORD *)v7 + 4) = -1;
  *((_DWORD *)v7 + 11) = -1;
  *((_DWORD *)v7 + 7) = 0;
  *((_DWORD *)v7 + 8) = 0;
  *((_DWORD *)v7 + 9) = 0;
  *((_DWORD *)v7 + 10) = v8;
  *((_DWORD *)v7 + 12) = 0;
  *((_DWORD *)v7 + 13) = 0;
  v7 += 28;
  *((_DWORD *)v7 + 11) = -1;
  *((float *)v7 + 7) = t_w;
  *((_QWORD *)v7 + 4) = LODWORD(t_h);
  *((_DWORD *)v7 + 10) = v8;
  *((_DWORD *)v7 + 12) = v8;
  *((_DWORD *)v7 + 13) = v8;
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  v7 += 56;
  *((_DWORD *)v7 + 4) = -1;
  *(_QWORD *)v7 = LODWORD(t_w);
  *((_DWORD *)v7 + 2) = 0;
  *((_DWORD *)v7 + 3) = v8;
  *((_DWORD *)v7 + 5) = v8;
  *((_DWORD *)v7 + 6) = 0;
  v10 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 12) += *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 14) * *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 15);
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 60))(
    m_game->m_game_world.m_mouse_pos.y,
    *(_DWORD *)(*((_DWORD *)v10 + 10) + 4),
    0);
  vostok::render::res_geometry::apply(surf0->m_context->m_g_quad_uv.m_object);
  v11 = 6;
  v12 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v13 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v14 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v14;
  if ( v14 )
    *((_DWORD *)v12 + 529) = 4;
  vostok::render::backend::flush((vostok::render::backend *)4, (int)v12);
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
      offset);
  *((_DWORD *)v13 + 21) += v11 / 3;
  if ( surf1.m_object )
  {
    if ( !--surf1.m_object->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)surf1.m_object);
  }
  if ( surf1a.m_object )
  {
    if ( !--surf1a.m_object->m_reference_count )
      vostok::render::resource_manager::release(
        v15,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)surf1a.m_object);
  }
}
