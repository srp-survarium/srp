void __thiscall vostok::render::radiance_volume::prepare(
        vostok::render::radiance_volume *this,
        vostok::render::radiance_volume *view_position,
        const vostok::math::float3 *view_direction,
        float *offset_from_center)
{
  vostok::render::backend *v5; // ecx
  vostok::render::backend *v6; // ecx
  vostok::render::backend *v7; // ecx
  float m_scale; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  signed int v13; // eax
  bool v14; // zf
  float v15; // [esp+Ch] [ebp-28h]
  float v16; // [esp+Ch] [ebp-28h]
  float v17; // [esp+Ch] [ebp-28h]
  vostok::math::float3 cascade_origin; // [esp+1Ch] [ebp-18h] BYREF
  __int64 v19; // [esp+28h] [ebp-Ch]
  int v20; // [esp+30h] [ebp-4h]
  float cell_size; // [esp+3Ch] [ebp+8h]

  vostok::render::backend::set_render_targets(
    (ID3D11RenderTargetView *)view_position->m_3d_rt_radiance_r.m_object,
    view_position->m_3d_rt_radiance_g.m_object,
    view_position->m_3d_rt_radiance_b.m_object,
    0,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  vostok::render::backend::clear_render_targets(
    v5,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
    0.0,
    0.0,
    0.0,
    0.0,
    v15);
  vostok::render::backend::set_render_targets(
    (ID3D11RenderTargetView *)view_position->m_3d_rt_radiance_intermediate_r.m_object,
    view_position->m_3d_rt_radiance_intermediate_g.m_object,
    view_position->m_3d_rt_radiance_intermediate_b.m_object,
    0,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  vostok::render::backend::clear_render_targets(
    v6,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
    0.0,
    0.0,
    0.0,
    0.0,
    v16);
  vostok::render::backend::set_render_targets(
    (ID3D11RenderTargetView *)view_position->m_3d_rt_accumulated_propagation_r.m_object,
    view_position->m_3d_rt_accumulated_propagation_g.m_object,
    view_position->m_3d_rt_accumulated_propagation_b.m_object,
    0,
    (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  vostok::render::backend::clear_render_targets(
    v7,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
    0.0,
    0.0,
    0.0,
    0.0,
    v17);
  m_scale = view_position->m_scale;
  v9 = view_direction->y - (float)(m_scale * 0.5);
  v10 = view_direction->z - (float)(m_scale * 0.5);
  v11 = (float)((float)(m_scale * *offset_from_center) * 0.2) + (float)(view_direction->x - (float)(m_scale * 0.5));
  v12 = offset_from_center[2] * m_scale;
  cell_size = m_scale / (double)view_position->m_num_cells;
  cascade_origin.y = (float)(*(float *)&clear_value / cell_size) * v9;
  cascade_origin.z = (float)(*(float *)&clear_value / cell_size) * (float)((float)(v12 * 0.2) + v10);
  cascade_origin.x = (float)(int)vostok::math::floor((float)(*(float *)&clear_value / cell_size) * v11);
  cascade_origin.y = (float)(int)vostok::math::floor(cascade_origin.y);
  v13 = vostok::math::floor(cascade_origin.z);
  cascade_origin.x = cascade_origin.x * cell_size;
  v14 = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 274) == 0;
  cascade_origin.y = cascade_origin.y * cell_size;
  cascade_origin.z = (float)v13 * cell_size;
  if ( v14 )
  {
    v20 = 0;
    v19 = 0;
    memset(&cascade_origin, 0, sizeof(cascade_origin));
  }
  vostok::render::radiance_volume::set_origin((vostok::render::radiance_volume *)&cascade_origin, (int)view_position);
}
