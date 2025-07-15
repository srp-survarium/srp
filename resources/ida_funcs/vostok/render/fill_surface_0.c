void __cdecl vostok::render::fill_surface_0(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> surf,
        vostok::render::renderer_context *context)
{
  ID3D11RenderTargetView *m_rt; // eax
  vostok::render::backend *m_conflicted_key_name; // esi
  int v5; // eax
  vostok::render::backend *v6; // ecx
  float *v7; // eax
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm4_4
  const vostok::math::float4x4 *v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  const char *v21; // eax
  vostok::render::backend *v22; // ecx
  unsigned int v23; // esi
  const char *v24; // edi
  const char *v25; // ebp
  bool v26; // al
  float w; // [esp+18h] [ebp-8h]
  unsigned int offset; // [esp+1Ch] [ebp-4h] BYREF
  float h; // [esp+28h] [ebp+8h]

  w = (float)surf.m_object->m_width;
  m_rt = surf.m_object->m_rt;
  h = (float)surf.m_object->m_height;
  m_conflicted_key_name = (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
       + 535) != m_rt )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
    m_conflicted_key_name->m_dirty_targets.render_targets[0] = 1;
  }
  if ( m_conflicted_key_name->m_targets[1] )
  {
    m_conflicted_key_name->m_targets[1] = 0;
    m_conflicted_key_name->m_dirty_targets.render_targets[1] = 1;
  }
  if ( m_conflicted_key_name->m_targets[2] )
  {
    m_conflicted_key_name->m_targets[2] = 0;
    m_conflicted_key_name->m_dirty_targets.render_targets[2] = 1;
  }
  if ( m_conflicted_key_name->m_targets[3] )
  {
    m_conflicted_key_name->m_targets[3] = 0;
    m_conflicted_key_name->m_dirty_targets.render_targets[3] = 1;
  }
  m_conflicted_key_name->m_dirty_targets.depth_stencil |= m_conflicted_key_name->m_zb != 0;
  m_conflicted_key_name->m_zb = 0;
  v5 = vostok::math::color_rgba(0.5, COERCE_VOSTOK_MATH_(0.5), 0.5, 1.0);
  vostok::render::backend::clear_render_targets(v6, m_conflicted_key_name, (vostok::math::color)v5);
  v7 = (float *)vostok::render::vertex_buffer::lock(
                  (vostok::render::vertex_buffer *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                  + 40),
                  4u,
                  0x24u,
                  &offset);
  x = context->m_eye_rays[1].x;
  y = context->m_eye_rays[1].y;
  z = context->m_eye_rays[1].z;
  *v7 = 0.0;
  v7[2] = 0.0;
  v11 = clear_value;
  *((_DWORD *)v7 + 3) = clear_value;
  v7[1] = h;
  v7[4] = x;
  v7[5] = y;
  v7[6] = z;
  v7[7] = 0.0;
  *((_DWORD *)v7 + 8) = v11;
  v12 = context->m_eye_rays[0].x;
  v13 = context->m_eye_rays[0].y;
  v14 = context->m_eye_rays[0].z;
  v7[9] = 0.0;
  v7[10] = 0.0;
  v7[11] = 0.0;
  *((_DWORD *)v7 + 12) = v11;
  v7[13] = v12;
  v7[14] = v13;
  v7[15] = v14;
  v7[16] = 0.0;
  v7[17] = 0.0;
  v15 = context->m_eye_rays[3].x;
  v16 = context->m_eye_rays[3].y;
  v17 = context->m_eye_rays[3].z;
  v7 += 9;
  v7[9] = w;
  *((_QWORD *)v7 + 5) = LODWORD(h);
  *((_DWORD *)v7 + 12) = v11;
  v7[13] = v15;
  v7[14] = v16;
  v7[15] = v17;
  v7 += 9;
  *((_DWORD *)v7 + 7) = v11;
  *((_DWORD *)v7 + 8) = v11;
  v18 = context->m_eye_rays[2].x;
  v19 = context->m_eye_rays[2].y;
  v20 = context->m_eye_rays[2].z;
  v7 += 9;
  *(_QWORD *)v7 = LODWORD(w);
  v7[2] = 0.0;
  *((_DWORD *)v7 + 3) = v11;
  v7[4] = v18;
  v7[5] = v19;
  v7[6] = v20;
  *((_DWORD *)v7 + 7) = v11;
  v7[8] = 0.0;
  v21 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 12) += *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 14) * *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 15);
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                             + 60))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    *(_DWORD *)(*((_DWORD *)v21 + 10) + 4),
    0);
  vostok::render::res_geometry::apply(context->m_g_quad_eye_ray.m_object);
  v23 = 6;
  v24 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v25 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v26 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v26;
  if ( v26 )
    *((_DWORD *)v24 + 529) = 4;
  vostok::render::backend::flush(v22, (int)v24);
  if ( v25[104] )
  {
    ++*((_DWORD *)v25 + 25);
    v23 = 3 * s_max_triagles_per_dip_value < 6 ? 3 * s_max_triagles_per_dip_value - 6 + 6 : 6;
  }
  if ( !v25[37] )
    (*(void (__stdcall **)(int, unsigned int, _DWORD, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                   + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v23,
      0,
      offset);
  *((_DWORD *)v25 + 21) += v23 / 3;
  if ( surf.m_object )
  {
    if ( !--surf.m_object->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)surf.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)surf.m_object);
  }
}
