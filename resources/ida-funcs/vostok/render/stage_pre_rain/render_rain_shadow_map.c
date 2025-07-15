// local variable allocation has failed, the output may be wrong!
vostok::math::float4x4 *__thiscall vostok::render::stage_pre_rain::render_rain_shadow_map(
        vostok::render::stage_pre_rain *this,
        vostok::render::stage_pre_rain *result,
        vostok::math::float4x4 *a3)
{
  vostok::render::base_scene_view *m_object; // edi
  vostok::math::float4x4 *rotation_z; // ebp
  vostok::math::float4x4 *v5; // eax
  double m_shadow_map_size; // st7
  float v7; // ebp
  float v8; // edx
  float v9; // xmm1_4
  float v10; // xmm2_4
  double v11; // st7
  const vostok::math::float4x4 *orthographic_projection; // eax
  void *v13; // edi
  vostok::render::renderer_context *v14; // ecx
  float v15; // eax
  void *v16; // edi
  const char *m_conflicted_key_name; // eax
  float v18; // ecx
  int v19; // esi
  bool v20; // zf
  int y; // eax
  double v22; // st7
  float v23; // eax
  vostok::render::render_surface_instance **M_start; // eax
  vostok::render::render_surface_instance *v25; // esi
  vostok::render::render_surface *m_render_surface; // edi
  vostok::render::enum_vertex_input_type m_vertex_input_type; // ecx
  survarium::game_action_id *v28; // ecx
  float v29; // eax
  unsigned int primitive_count; // eax
  const char *v31; // edi
  unsigned int v32; // ebp
  const char *v33; // esi
  float v34; // ebp
  float v35; // esi
  const vostok::math::float4x4 *v36; // xmm2_4
  float v37; // eax
  const vostok::math::float4x4 *v38; // eax
  const char *v39; // esi
  vostok::render::backend *v40; // ecx
  int v41; // eax
  void **v42; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  float result_4; // [esp+28h] [ebp-168h]
  float v46; // [esp+2Ch] [ebp-164h]
  vostok::render::stage_pre_rain *v47; // [esp+2Ch] [ebp-164h]
  unsigned int v48; // [esp+2Ch] [ebp-164h]
  float v49; // [esp+30h] [ebp-160h]
  float v50; // [esp+34h] [ebp-15Ch]
  float v51; // [esp+38h] [ebp-158h]
  vostok::render::render_surface_instance *const *end_d; // [esp+3Ch] [ebp-154h] BYREF
  vostok::render::render_surface_instance **it_d; // [esp+40h] [ebp-150h]
  vostok::math::float3 local_up_in_world_space; // [esp+44h] [ebp-14Ch] BYREF
  int v55; // [esp+50h] [ebp-140h]
  vostok::math::float3 view_dir; // [esp+54h] [ebp-13Ch] BYREF
  vostok::math::float4_pod direction; // [esp+60h] [ebp-130h] OVERLAPPED BYREF
  vostok::math::float3 adjastment; // [esp+70h] [ebp-120h] BYREF
  int v59; // [esp+7Ch] [ebp-114h]
  vostok::math::float3 v60; // [esp+80h] [ebp-110h] BYREF
  int v61; // [esp+8Ch] [ebp-104h]
  vostok::render::vector<vostok::render::render_surface_instance *> m_caster_model; // [esp+90h] [ebp-100h] BYREF
  D3D11_VIEWPORT tmp_viewport; // [esp+9Ch] [ebp-F4h] BYREF
  vostok::math::float4x4 shadow_view_transform; // [esp+B4h] [ebp-DCh] BYREF
  vostok::math::float4x4 shadow_full_transform; // [esp+F4h] [ebp-9Ch] BYREF
  vostok::math::float4x4 shadow_projection_transform; // [esp+134h] [ebp-5Ch] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+174h] [ebp-1Ch] BYREF

  m_object = result->m_context->m_scene_view.m_object;
  rotation_z = vostok::math::create_rotation_z(
                 (int)&shadow_full_transform,
                 COERCE_VOSTOK_MATH_FLOAT4X4_(*(float *)&m_object[2].m_uid));
  v5 = vostok::math::create_rotation_x(
         &shadow_projection_transform,
         COERCE_VOSTOK_MATH_FLOAT4X4_(*((float *)&m_object[2].m_reconstruction_size + 1)));
  vostok::math::mul4x3(&shadow_view_transform, v5, rotation_z);
  m_shadow_map_size = (double)result->m_shadow_map_size;
  v7 = *(float *)&result->m_context;
  v8 = *(float *)(LODWORD(v7) + 16940);
  *(_QWORD *)&view_dir.x = *(_QWORD *)(LODWORD(v7) + 16932);
  view_dir.z = v8;
  direction.x = -shadow_view_transform.j.x;
  direction.y = -shadow_view_transform.j.y;
  direction.z = -shadow_view_transform.j.z;
  *(float *)&it_d = m_shadow_map_size;
  v9 = *(float *)(LODWORD(v7) + 16904) - (float)((float)-shadow_view_transform.j.y * 100.0);
  v10 = *(float *)(LODWORD(v7) + 16908);
  view_dir.x = (float)(*(float *)(LODWORD(v7) + 16900) - (float)((float)-shadow_view_transform.j.x * 100.0))
             + (float)((float)((float)(view_dir.x * 0.5) * 0.5) * *(float *)&it_d);
  *(_QWORD *)&local_up_in_world_space.x = (unsigned int)clear_value;
  view_dir.y = v9 + (float)((float)((float)(view_dir.y * 0.5) * 0.5) * *(float *)&it_d);
  view_dir.z = (float)(v10 - (float)((float)-shadow_view_transform.j.z * 100.0))
             + (float)((float)((float)(v8 * 0.5) * 0.5) * *(float *)&it_d);
  local_up_in_world_space.z = 0.0;
  vostok::math::create_camera_direction(&view_dir, (const vostok::math::float3 *)&direction, &local_up_in_world_space);
  v11 = (double)result->m_shadow_map_size;
  *(float *)&end_d = v11;
  result_4 = v11 * 0.5;
  orthographic_projection = vostok::math::create_orthographic_projection(
                              (vostok::math *)LODWORD(result_4),
                              (struct vostok::math::float4x4 *)LODWORD(result_4),
                              v46,
                              v49,
                              v50,
                              v51);
  vostok::math::mul4x3(&shadow_full_transform, &shadow_view_transform, orthographic_projection);
  memset(&local_up_in_world_space, 0, sizeof(local_up_in_world_space));
  vostok::render::stage_pre_rain::compute_aligment(&local_up_in_world_space, (int)&adjastment, *(float *)&it_d, v47);
  *(_QWORD *)&v60.x = (unsigned int)clear_value;
  v60.z = 0.0;
  local_up_in_world_space.x = adjastment.x + view_dir.x;
  local_up_in_world_space.y = adjastment.y + view_dir.y;
  local_up_in_world_space.z = adjastment.z + view_dir.z;
  qmemcpy(
    (void *)&shadow_view_transform,
    vostok::math::create_camera_direction(&local_up_in_world_space, (const vostok::math::float3 *)&direction, &v60),
    sizeof(shadow_view_transform));
  v13 = *(void **)(LODWORD(v7) + 13432);
  if ( v13 )
    qmemcpy(v13, (const void *)(LODWORD(v7) + 15620), 0x40u);
  *(_DWORD *)(LODWORD(v7) + 13432) += 64;
  vostok::render::renderer_context::set_v(
    (vostok::render::renderer_context *)&shadow_view_transform,
    (const vostok::math::float4x4 *)LODWORD(v7));
  v15 = *(float *)&result->m_context;
  v16 = *(void **)(LODWORD(v15) + 14464);
  if ( v16 )
  {
    qmemcpy(v16, (const void *)(LODWORD(v15) + 15940), 0x40u);
    v14 = 0;
  }
  *(_DWORD *)(LODWORD(v15) + 14464) += 64;
  vostok::render::renderer_context::set_p(v14, (const vostok::math::float4x4 *)LODWORD(v15));
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) )
  {
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = 0;
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
  v18 = *(float *)&result->m_rt_rain_shadow_map.m_object;
  if ( v18 == 0.0 )
    v19 = 0;
  else
    v19 = *(_DWORD *)(LODWORD(v18) + 20);
  v20 = *((_DWORD *)m_conflicted_key_name + 539) == v19;
  *((_DWORD *)m_conflicted_key_name + 539) = v19;
  *((_BYTE *)m_conflicted_key_name + 167) |= !v20;
  if ( s_debug_enabled_ds_clearing_value && v19 )
    (*(void (__stdcall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                         + 212))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      v19,
      3,
      1.0,
      0);
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  end_d = (vostok::render::render_surface_instance *const *)1;
  (*(void (__stdcall **)(int, vostok::render::render_surface_instance *const **, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(
    y,
    &end_d,
    &orig_viewport);
  v22 = (double)result->m_shadow_map_size;
  tmp_viewport.TopLeftX = 0.0;
  tmp_viewport.TopLeftY = 0.0;
  tmp_viewport.Width = v22;
  tmp_viewport.MinDepth = 0.0;
  tmp_viewport.Height = v22;
  LODWORD(tmp_viewport.MaxDepth) = clear_value;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &tmp_viewport);
  v23 = *(float *)&result->m_context;
  memset(&m_caster_model, 0, sizeof(m_caster_model));
  vostok::render::scene::select_models(
    *(vostok::render::scene **)(LODWORD(v23) + 12388),
    (const vostok::math::float4x4 *)(LODWORD(v23) + 16260),
    &m_caster_model,
    (const vostok::math::float3 *)(LODWORD(v23) + 16900),
    1u,
    0);
  M_start = (vostok::render::render_surface_instance **)m_caster_model._M_impl._M_start;
  it_d = (vostok::render::render_surface_instance **)m_caster_model._M_impl._M_start;
  end_d = (vostok::render::render_surface_instance *const *)m_caster_model._M_impl._M_finish;
  if ( s_rain_debug0 && m_caster_model._M_impl._M_start != m_caster_model._M_impl._M_finish )
  {
    do
    {
      v25 = *M_start;
      m_render_surface = (*M_start)->m_render_surface;
      if ( m_render_surface->m_render_geometry.geom.m_object )
      {
        m_vertex_input_type = m_render_surface->m_vertex_input_type;
        if ( m_vertex_input_type == static_mesh_vertex_input_type
          || m_vertex_input_type == static_mesh_vertex_colored_input_type )
        {
          v28 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
          if ( (!*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                 + 288)
             || !v25->m_occluded)
            && v25->m_dynamic_screen_factor >= 0.0040000002 )
          {
            v29 = *(float *)&result->m_effect_shadow_direct.m_object;
            if ( (*(_DWORD *)(LODWORD(v29) + 284) - *(_DWORD *)(LODWORD(v29) + 280)) >> 2 )
            {
              *(_DWORD *)(LODWORD(v29) + 276) = 0;
              vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v28, v48);
            }
            v25->m_parent->set_constants(v25->m_parent);
            vostok::render::res_geometry::apply(m_render_surface->m_render_geometry.geom.m_object);
            vostok::render::renderer_context::set_w(result->m_context, v25->m_transform);
            primitive_count = m_render_surface->m_render_geometry.primitive_count;
            v31 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            v32 = 3 * primitive_count;
            LOBYTE(primitive_count) = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                      + 529) != 4;
            v33 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = primitive_count;
            if ( (_BYTE)primitive_count )
              *((_DWORD *)v31 + 529) = 4;
            vostok::render::backend::flush((vostok::render::backend *)4, (int)v31);
            if ( v33[104] )
            {
              ++*((_DWORD *)v33 + 25);
              v32 += 3 * s_max_triagles_per_dip_value < v32 ? 3 * s_max_triagles_per_dip_value - v32 : 0;
            }
            if ( !v33[37] )
              (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                       + 48))(
                `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
                v32,
                0,
                0);
            M_start = it_d;
            *((_DWORD *)v33 + 21) += v32 / 3;
          }
        }
      }
      it_d = ++M_start;
    }
    while ( M_start != end_d );
  }
  v34 = *(float *)&result->m_context;
  qmemcpy((void *)&shadow_full_transform, (const void *)(LODWORD(v34) + 16260), sizeof(shadow_full_transform));
  vostok::render::renderer_context::set_v(0, (const vostok::math::float4x4 *)LODWORD(v34));
  *(_DWORD *)(LODWORD(v34) + 13432) -= 64;
  v35 = *(float *)&result->m_context;
  vostok::render::renderer_context::set_p(
    (vostok::render::renderer_context *)(*(_DWORD *)(LODWORD(v35) + 14464) - 64),
    (const vostok::math::float4x4 *)LODWORD(v35));
  v36 = clear_value;
  *(_DWORD *)(LODWORD(v35) + 14464) -= 64;
  v37 = *(float *)&result->m_context;
  *(_QWORD *)&local_up_in_world_space.x = 0;
  v55 = 0;
  adjastment.x = 0.0;
  v59 = 0;
  v60.z = 0.0;
  v61 = 0;
  *(_QWORD *)&v60.x = LODWORD(FLOAT_0_5);
  *(_QWORD *)&shadow_view_transform.i.x = LODWORD(FLOAT_0_5);
  *(_QWORD *)&shadow_view_transform.lines[0].elements[2] = 0;
  LODWORD(direction.w) = v36;
  LODWORD(local_up_in_world_space.z) = v36;
  *(_QWORD *)&adjastment.elements[1] = 3204448256LL;
  *(_QWORD *)&shadow_view_transform.lines[1].x = *(_QWORD *)&adjastment.x;
  memset(&shadow_view_transform.lines[1].elements[2], 0, 16);
  *(_QWORD *)&shadow_view_transform.lines[2].elements[2] = (unsigned int)v36;
  direction.x = FLOAT_0_5;
  *(_QWORD *)&direction.elements[1] = LODWORD(FLOAT_0_5) | 0xBA83126F00000000uLL;
  shadow_view_transform.c = direction;
  vostok::math::mul4x3(
    &shadow_projection_transform,
    (const vostok::math::float4x4 *)(LODWORD(v37) + 15748),
    &shadow_full_transform);
  vostok::math::mul4x3(a3, &shadow_projection_transform, &shadow_view_transform);
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &orig_viewport);
  v38 = vostok::math::float4x4::identity(&shadow_full_transform);
  vostok::render::renderer_context::set_w(result->m_context, v38);
  v39 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  vostok::render::backend::reset_render_targets(
    v40,
    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
  v41 = *((_DWORD *)v39 + 547);
  v20 = *((_DWORD *)v39 + 539) == v41;
  *((_DWORD *)v39 + 539) = v41;
  *((_BYTE *)v39 + 167) |= !v20;
  v42 = m_caster_model._M_impl._M_start;
  if ( m_caster_model._M_impl._M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v42);
  }
  return a3;
}
