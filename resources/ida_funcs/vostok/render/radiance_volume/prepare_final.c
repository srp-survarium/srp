void __thiscall vostok::render::radiance_volume::prepare_final(
        vostok::render::radiance_volume *this,
        vostok::render::radiance_volume *thisa)
{
  const char *m_conflicted_key_name; // ebp
  vostok::render::backend *v4; // ecx
  const char *v5; // ebp
  _DWORD *v6; // eax
  unsigned int v7; // ecx
  char v8; // al
  const char *v9; // ecx
  const char *v10; // esi
  char v11; // al
  const char *v12; // ecx
  vostok::render::radiance_volume *v13; // ecx
  float z; // edx
  float v15; // eax
  float v16; // [esp+Ch] [ebp-10h]
  unsigned int v17; // [esp+Ch] [ebp-10h]

  vostok::render::radiance_volume::begin_render_to_cells(this, (int)thisa);
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::set_render_targets(
    (ID3D11RenderTargetView *)thisa->m_3d_rt_radiance_r_apply.m_object,
    thisa->m_3d_rt_radiance_g_apply.m_object,
    thisa->m_3d_rt_radiance_b_apply.m_object,
    0,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  vostok::render::backend::clear_render_targets(v4, (int)m_conflicted_key_name, 0.0, 0.0, 0.0, 0.0, v16);
  v5 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::set_render_targets(
    (ID3D11RenderTargetView *)thisa->m_3d_rt_radiance_r_apply.m_object,
    thisa->m_3d_rt_radiance_g_apply.m_object,
    thisa->m_3d_rt_radiance_b_apply.m_object,
    0,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v6 = &thisa->m_lpv_effect.m_object->__vftable;
  v7 = (v6[71] - v6[70]) >> 2;
  if ( v7 > 5 )
  {
    v6[69] = 5;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v7, v17);
    v5 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  }
  v8 = vostok::render::textures_handler<0>::set_overwrite(
         (vostok::render::textures_handler<0> *)v7,
         (char *)v5 + 1488,
         (vostok::render::res_texture *)&stru_964DF4.m_desc.ArraySize,
         thisa->m_3d_t_accumulated_propagation_r.m_object);
  v9 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v5 + 159) = v8;
  v10 = v9;
  v11 = vostok::render::textures_handler<0>::set_overwrite(
          (vostok::render::textures_handler<0> *)(v9 + 1488),
          (char *)v9 + 1488,
          (vostok::render::res_texture *)&stru_964DF4.m_desc.Usage,
          thisa->m_3d_t_accumulated_propagation_g.m_object);
  v12 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v10 + 159) = v11;
  *((_BYTE *)v12 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                            (vostok::render::textures_handler<0> *)(v12 + 1488),
                            (char *)v12 + 1488,
                            (vostok::render::res_texture *)&stru_964DF4.m_desc_3d,
                            thisa->m_3d_t_accumulated_propagation_b.m_object);
  vostok::render::sliced_cube_geometry::draw(&thisa->m_sliced_cube_geometry);
  vostok::render::radiance_volume::end_render_to_cells(v13, thisa);
  z = thisa->m_previous_origin.z;
  v15 = thisa->m_bbox.min.z;
  *(_QWORD *)&thisa->m_prev_previous_origin.x = *(_QWORD *)&thisa->m_previous_origin.x;
  *(_QWORD *)&thisa->m_previous_origin.x = *(_QWORD *)&thisa->m_bbox.min.x;
  thisa->m_prev_previous_origin.z = z;
  thisa->m_previous_origin.z = v15;
}
