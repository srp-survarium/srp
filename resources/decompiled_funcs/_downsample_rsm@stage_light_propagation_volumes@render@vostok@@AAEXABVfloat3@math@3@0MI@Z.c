void __thiscall vostok::render::stage_light_propagation_volumes::downsample_rsm(
        vostok::render::stage_light_propagation_volumes *this,
        int light_direction,
        const vostok::math::float3 *grid_origin,
        const vostok::math::float3 *grid_scale,
        float cascade_index,
        unsigned int cascade_indexa)
{
  vostok::render::stage_light_propagation_volumes *v6; // ebx
  float v7; // eax
  int v8; // ecx
  unsigned int v9; // ebp
  const char *m_conflicted_key_name; // eax
  bool v11; // zf
  int y; // eax
  double m_rsm_downsampled_size; // st7
  const char *v14; // esi
  char v15; // al
  const char *v16; // ecx
  const char *v17; // esi
  vostok::render::textures_handler<0> *v18; // ecx
  vostok::render::stage_light_propagation_volumes *v19; // ecx
  const char *v20; // esi
  vostok::render::backend *v21; // ecx
  int v22; // eax
  survarium::game *m_game; // edx
  unsigned int v24; // [esp+4h] [ebp-40h]
  D3D11_VIEWPORT tmp_viewport; // [esp+14h] [ebp-30h] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+2Ch] [ebp-18h] BYREF

  v6 = (vostok::render::stage_light_propagation_volumes *)light_direction;
  v7 = *(float *)(light_direction + 712);
  v8 = (*(_DWORD *)(LODWORD(v7) + 284) - *(_DWORD *)(LODWORD(v7) + 280)) >> 2;
  if ( v8 )
  {
    *(_DWORD *)(LODWORD(v7) + 276) = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v8, v24);
  }
  vostok::render::stage_light_propagation_volumes::set_rsm_contants(v6, grid_scale, grid_origin, cascade_index);
  v9 = cascade_indexa;
  vostok::render::backend::set_render_targets(
    (ID3D11RenderTargetView *)v6->m_radiance_volume[cascade_indexa].m_rt_rms_albedo.m_object,
    v6->m_radiance_volume[cascade_indexa].m_rt_rms_normal.m_object,
    v6->m_radiance_volume[cascade_indexa].m_rt_rms_position.m_object,
    0,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v11 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == 0;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = 0;
  *((_BYTE *)m_conflicted_key_name + 167) |= !v11;
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  light_direction = 1;
  (*(void (__stdcall **)(int, int *, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(y, &light_direction, &orig_viewport);
  m_rsm_downsampled_size = (double)v6->m_rsm_downsampled_size;
  tmp_viewport.TopLeftX = 0.0;
  tmp_viewport.TopLeftY = 0.0;
  tmp_viewport.Width = m_rsm_downsampled_size;
  tmp_viewport.MinDepth = 0.0;
  tmp_viewport.Height = m_rsm_downsampled_size;
  LODWORD(tmp_viewport.MaxDepth) = clear_value;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &tmp_viewport);
  v14 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v15 = vostok::render::textures_handler<0>::set_overwrite(
          (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                + 1488),
          (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 1488,
          (vostok::render::res_texture *)&stru_964DF4,
          v6->m_radiance_volume[v9].m_t_rms_albedo_source.m_object);
  v16 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v14 + 159) = v15;
  *((_BYTE *)v16 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                            (vostok::render::textures_handler<0> *)(v16 + 1488),
                            (char *)v16 + 1488,
                            (vostok::render::res_texture *)&stru_964DF4.m_rescale_min.elements[2],
                            v6->m_radiance_volume[v9].m_t_rms_normal_source.m_object);
  v17 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v17 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                            v18,
                            (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                          + 1488,
                            (vostok::render::res_texture *)((char *)&stru_964DF4 + 48),
                            v6->m_radiance_volume[v9].m_t_rms_position_source.m_object);
  vostok::render::stage_light_propagation_volumes::render_quad(v19, v6);
  v20 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::reset_render_targets(
    v21,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v22 = *((_DWORD *)v20 + 547);
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
  *((_BYTE *)v20 + 167) |= *((_DWORD *)v20 + 539) != v22;
  *((_DWORD *)v20 + 539) = v22;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)m_game->m_game_world.m_mouse_pos.y + 176))(
    m_game->m_game_world.m_mouse_pos.y,
    1,
    &orig_viewport);
}
