void __cdecl vostok::render::fill_surface(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> surf,
        vostok::render::renderer_context *context)
{
  ID3D11RenderTargetView *m_rt; // eax
  vostok::render::backend *m_conflicted_key_name; // esi
  const vostok::math::float4x4 *v5; // xmm0_4
  int v6; // eax
  vostok::render::backend *v7; // ecx
  float *v8; // eax
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm4_4
  const vostok::math::float4x4 *v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  const char *v22; // eax
  vostok::render::backend *v23; // ecx
  unsigned int v24; // esi
  const char *v25; // edi
  const char *v26; // ebp
  bool v27; // al
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
  v5 = clear_value;
  m_conflicted_key_name->m_dirty_targets.depth_stencil |= m_conflicted_key_name->m_zb != 0;
  m_conflicted_key_name->m_zb = 0;
  v6 = vostok::math::color_rgba(*(float *)&v5, COERCE_VOSTOK_MATH_(1.0), 1.0, 0.0);
  vostok::render::backend::clear_render_targets(v7, m_conflicted_key_name, (vostok::math::color)v6);
  v8 = (float *)vostok::render::vertex_buffer::lock(
                  (vostok::render::vertex_buffer *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                  + 40),
                  4u,
                  0x24u,
                  &offset);
  x = context->m_eye_rays[1].x;
  y = context->m_eye_rays[1].y;
  z = context->m_eye_rays[1].z;
  *v8 = 0.0;
  v8[2] = 0.0;
  v12 = clear_value;
  *((_DWORD *)v8 + 3) = clear_value;
  v8[1] = h;
  v8[4] = x;
  v8[5] = y;
  v8[6] = z;
  v8[7] = 0.0;
  *((_DWORD *)v8 + 8) = v12;
  v13 = context->m_eye_rays[0].x;
  v14 = context->m_eye_rays[0].y;
  v15 = context->m_eye_rays[0].z;
  v8[9] = 0.0;
  v8[10] = 0.0;
  v8[11] = 0.0;
  *((_DWORD *)v8 + 12) = v12;
  v8[13] = v13;
  v8[14] = v14;
  v8[15] = v15;
  v8[16] = 0.0;
  v8[17] = 0.0;
  v16 = context->m_eye_rays[3].x;
  v17 = context->m_eye_rays[3].y;
  v18 = context->m_eye_rays[3].z;
  v8 += 9;
  v8[9] = w;
  *((_QWORD *)v8 + 5) = LODWORD(h);
  *((_DWORD *)v8 + 12) = v12;
  v8[13] = v16;
  v8[14] = v17;
  v8[15] = v18;
  v8 += 9;
  *((_DWORD *)v8 + 7) = v12;
  *((_DWORD *)v8 + 8) = v12;
  v19 = context->m_eye_rays[2].x;
  v20 = context->m_eye_rays[2].y;
  v21 = context->m_eye_rays[2].z;
  v8 += 9;
  *(_QWORD *)v8 = LODWORD(w);
  v8[2] = 0.0;
  *((_DWORD *)v8 + 3) = v12;
  v8[4] = v19;
  v8[5] = v20;
  v8[6] = v21;
  *((_DWORD *)v8 + 7) = v12;
  v8[8] = 0.0;
  v22 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 12) += *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 14) * *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 15);
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                             + 60))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    *(_DWORD *)(*((_DWORD *)v22 + 10) + 4),
    0);
  vostok::render::res_geometry::apply(context->m_g_quad_eye_ray.m_object);
  v24 = 6;
  v25 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v26 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v27 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v27;
  if ( v27 )
    *((_DWORD *)v25 + 529) = 4;
  vostok::render::backend::flush(v23, (int)v25);
  if ( v26[104] )
  {
    ++*((_DWORD *)v26 + 25);
    v24 = 3 * s_max_triagles_per_dip_value < 6 ? 3 * s_max_triagles_per_dip_value - 6 + 6 : 6;
  }
  if ( !v26[37] )
    (*(void (__stdcall **)(int, unsigned int, _DWORD, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                   + 48))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v24,
      0,
      offset);
  *((_DWORD *)v26 + 21) += v24 / 3;
  if ( surf.m_object )
  {
    if ( !--surf.m_object->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)surf.m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)surf.m_object);
  }
}
