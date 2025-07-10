void __userpurge vostok::render::hw_hiz_occlusion_manager::render_model_bounds(
        vostok::render::hw_hiz_occlusion_manager *this@<ecx>,
        unsigned int in_num_bounds@<eax>,
        bool a3@<bl>,
        unsigned int a4@<esi>,
        vostok::render::renderer_context *in_context,
        vostok::render::hw_hiz_point_list *in_bounds)
{
  const vostok::math::float4x4 *v7; // eax
  int v8; // ecx
  int y; // eax
  signed int m_culling_buffer_height; // edx
  double v11; // st7
  vostok::render::render_target *m_object; // eax
  vostok::render::backend *m_rt; // ecx
  const char *m_conflicted_key_name; // eax
  vostok::render::res_effect *v15; // ecx
  vostok::render::res_effect *v16; // eax
  const char *v17; // esi
  signed int v18; // ecx
  double v19; // st7
  vostok::render::shader_constant_host *m_render_target_size_parameter; // eax
  unsigned int v21; // edx
  const char *v22; // esi
  int m_buffer_index; // ecx
  signed int m_rasterize_height; // eax
  double v25; // st7
  vostok::render::shader_constant_host *m_rasterize_size_parameter; // eax
  unsigned int v27; // ecx
  int v28; // ecx
  float v29; // [esp+24h] [ebp-9Ch]
  char src_ptr[4]; // [esp+38h] [ebp-88h] BYREF
  float v31; // [esp+3Ch] [ebp-84h]
  int v32; // [esp+40h] [ebp-80h]
  int v33; // [esp+44h] [ebp-7Ch]
  int v34; // [esp+48h] [ebp-78h] BYREF
  D3D11_VIEWPORT view_port; // [esp+4Ch] [ebp-74h] BYREF
  D3D11_VIEWPORT prev_view_port; // [esp+64h] [ebp-5Ch] BYREF
  vostok::math::float4x4 v37; // [esp+7Ch] [ebp-44h] BYREF

  vostok::render::hw_hiz_occlusion_manager::check_culling_buffer(this, in_num_bounds, a3, a4);
  vostok::render::hw_hiz_point_list::set_points(
    in_bounds,
    (const vostok::math::float4 *)&this->m_hw_hiz_point_list,
    (const unsigned int)in_bounds);
  v7 = vostok::math::float4x4::identity(&v37);
  vostok::render::renderer_context::set_w(v8, v7, in_context);
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  v34 = 1;
  (*(void (__stdcall **)(int, int *, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(y, &v34, &prev_view_port);
  m_culling_buffer_height = this->m_culling_buffer_height;
  view_port.Width = (float)this->m_culling_buffer_width;
  v11 = (double)(int)this->m_culling_buffer_height;
  if ( m_culling_buffer_height < 0 )
    v11 = v11 + 4294967300.0;
  view_port.Height = v11;
  view_port.MinDepth = 0.0;
  LODWORD(view_port.MaxDepth) = clear_value;
  view_port.TopLeftX = 0.0;
  view_port.TopLeftY = 0.0;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &view_port);
  m_object = this->m_rt_culling_result.m_object;
  if ( m_object )
    m_rt = (vostok::render::backend *)m_object->m_rt;
  else
    m_rt = 0;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((vostok::render::backend **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
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
  LOBYTE(m_rt) = *((_DWORD *)m_conflicted_key_name + 539) != 0;
  *((_BYTE *)m_conflicted_key_name + 167) |= (unsigned __int8)m_rt;
  *((_DWORD *)m_conflicted_key_name + 539) = 0;
  vostok::render::backend::clear_render_targets(m_rt, (int)m_conflicted_key_name, 0.0, 0.0, 0.0, 0.0, v29);
  v16 = this->m_hiz_occlusion_effect.m_object;
  if ( (unsigned int)(v16->m_techniques._M_impl._M_finish - v16->m_techniques._M_impl._M_start) > 6 )
  {
    v16->m_cur_technique = 6;
    vostok::render::res_effect::apply_pass(v15, (int)v16);
  }
  v17 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v17 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                            (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                  + 1488),
                            (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                          + 1488,
                            (vostok::render::res_texture *)&stru_967C04,
                            this->m_t_depth_mips.m_object);
  v18 = this->m_culling_buffer_height;
  *(float *)src_ptr = (float)this->m_culling_buffer_width;
  v19 = (double)(int)this->m_culling_buffer_height;
  if ( v18 < 0 )
    v19 = v19 + 4294967300.0;
  m_render_target_size_parameter = this->m_render_target_size_parameter;
  v31 = v19;
  v21 = m_render_target_size_parameter->m_update_markers[0];
  v22 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v32 = 0;
  v33 = 0;
  if ( v21 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 572) )
  {
    m_buffer_index = m_render_target_size_parameter->m_shader_slots[0].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_render_target_size_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_render_target_size_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 51)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        src_ptr);
  }
  ++*((_DWORD *)v22 + 23);
  m_rasterize_height = this->m_rasterize_height;
  *(float *)src_ptr = (float)this->m_rasterize_width;
  v25 = (double)(int)this->m_rasterize_height;
  if ( m_rasterize_height < 0 )
    v25 = v25 + 4294967300.0;
  m_rasterize_size_parameter = this->m_rasterize_size_parameter;
  v31 = v25;
  v27 = m_rasterize_size_parameter->m_update_markers[1];
  v32 = 0;
  v33 = 0;
  if ( v27 == *((_DWORD *)v22 + 573) )
  {
    v28 = m_rasterize_size_parameter->m_shader_slots[1].m_buffer_index;
    if ( v28 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_rasterize_size_parameter->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_rasterize_size_parameter->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v22 + 371) + 16) + 4 * v28),
        src_ptr);
  }
  ++*((_DWORD *)v22 + 23);
  vostok::render::hw_hiz_point_list::render(&this->m_hw_hiz_point_list, this->m_current_num_bounds);
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &prev_view_port);
}
