void __thiscall vostok::render::renderer::draw_debug(
        vostok::render::renderer *this,
        vostok::render::renderer *scene,
        vostok::render::scene *view,
        const float frame_time,
        const vostok::ui::font *default_font,
        const vostok::ui::font *num_vst_changes)
{
  const char *m_conflicted_key_name; // esi
  int v7; // eax
  bool v8; // zf
  vostok::render::render_target *m_object; // eax
  vostok::render::resource_manager *v10; // ecx
  ID3D11RenderTargetView *m_rt; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // edx
  int v15; // ebp
  vostok::render::statistics *v16; // edi
  int v17; // ebx
  int v18; // eax
  double v19; // xmm0_8
  double v20; // xmm0_8
  vostok::render::resource_manager *v21; // ecx
  unsigned int texture_video_memory_size; // eax
  vostok::render::statistics *v23; // ecx
  survarium::options_tab *v24; // edx
  unsigned int v25; // eax
  vostok::resources::vfs_sub_fat_resource *m_begin; // edi
  const vostok::math::float4x4 *v27; // eax
  float v28; // ecx
  vostok::resources::vfs_sub_fat_resource *v29; // eax
  vostok::render::grass_world *m_grass; // ecx
  vostok::resources::vfs_sub_fat_resource *v31; // esi
  float value; // [esp+0h] [ebp-6Ch]
  float valuea; // [esp+0h] [ebp-6Ch]
  const vostok::math::float4x4 *v34; // [esp+4h] [ebp-68h]
  unsigned int num_vss_changes; // [esp+18h] [ebp-54h]
  unsigned int num_pst_changes; // [esp+1Ch] [ebp-50h]
  unsigned int num_psc_changes; // [esp+20h] [ebp-4Ch]
  int es2; // [esp+24h] [ebp-48h]
  vostok::math::float4x4 v39; // [esp+2Ch] [ebp-40h] BYREF
  unsigned int num_vst_changesa; // [esp+80h] [ebp+14h]

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v7 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
  v8 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == v7;
  *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v7;
  *((_BYTE *)m_conflicted_key_name + 167) |= !v8;
  *((_BYTE *)m_conflicted_key_name + 37) = 0;
  m_object = scene->m_renderer_context->m_targets->m_family[45].target.m_object;
  v10 = 0;
  if ( m_object )
  {
    v10 = (vostok::render::resource_manager *)scene->m_renderer_context->m_targets->m_family[45].target.m_object;
    ++m_object->m_reference_count;
    m_rt = m_object->m_rt;
  }
  else
  {
    m_rt = 0;
  }
  if ( *((ID3D11RenderTargetView **)m_conflicted_key_name + 535) != m_rt )
  {
    *((_DWORD *)m_conflicted_key_name + 535) = m_rt;
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
  if ( v10 )
  {
    v8 = v10->sh_created-- == 1;
    if ( v8 )
    {
      vostok::render::resource_manager::release(
        v10,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v10);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
  }
  if ( scene->m_picking_lighting_luminance_mode && num_vst_changes )
  {
    vostok::render::renderer::draw_luminance_picker_info(
      (vostok::render::renderer *)v10,
      (float *)&scene->m_picking_lighting_luminance_mode,
      num_vst_changes);
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  }
  if ( s_do_stages_profiling && num_vst_changes )
  {
    vostok::render::renderer::draw_stages_stats((vostok::render::renderer *)v10, num_vst_changes);
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  }
  v12 = *(_DWORD *)m_conflicted_key_name;
  v13 = *((_DWORD *)m_conflicted_key_name + 1);
  v14 = *((_DWORD *)m_conflicted_key_name + 2);
  v15 = *((_DWORD *)m_conflicted_key_name + 3);
  num_vst_changesa = *((_DWORD *)m_conflicted_key_name + 4);
  num_vss_changes = *((_DWORD *)m_conflicted_key_name + 5);
  num_psc_changes = *((_DWORD *)m_conflicted_key_name + 6);
  num_pst_changes = *((_DWORD *)m_conflicted_key_name + 7);
  es2 = *((_DWORD *)m_conflicted_key_name + 8);
  v16 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  vostok::quasi_singleton<vostok::render::statistics>::pinst->debug_stat_group.textures_compression_duration.value = *((float *)m_conflicted_key_name + 541);
  v16->debug_stat_group.dxt_rt_tex_creation_duration.value = *((float *)m_conflicted_key_name + 542);
  v16->debug_stat_group.cpu_textures_compression_duration.value = *((float *)m_conflicted_key_name + 543);
  v16->debug_stat_group.gpu_num_compressed_textures.value = *((_DWORD *)m_conflicted_key_name + 545);
  v17 = *((_DWORD *)m_conflicted_key_name + 544);
  v16->debug_stat_group.num_pixel_shader_changes.value = v13;
  v16->debug_stat_group.num_vertex_shader_changes.value = v12;
  v16->debug_stat_group.num_vs_textures_changes.value = num_vst_changesa;
  v16->debug_stat_group.num_vs_samplers_changes.value = num_vss_changes;
  v16->debug_stat_group.num_ps_textures_changes.value = num_pst_changes;
  v16->debug_stat_group.cpu_num_compressed_textures.value = v17;
  v16->debug_stat_group.num_vs_constants_changes.value = v15;
  v16->debug_stat_group.num_ps_constants_changes.value = num_psc_changes;
  v16->debug_stat_group.num_ps_samplers_changes.value = es2;
  v16->debug_stat_group.num_input_layout_changes.value = v14;
  v16->general_stat_group.cpu_render_frame_time.value = *(float *)&default_font;
  v16->visibility_stat_group.num_total_rendered_triangles.value = *((_DWORD *)m_conflicted_key_name + 21);
  v18 = *((_DWORD *)m_conflicted_key_name + 22);
  v16->general_stat_group.render_frame_time.cpu_time.value = *(float *)&default_font * 1000.0;
  v16->general_stat_group.render_frame_time.gpu_time.value = *(float *)&default_font * 1000.0;
  v19 = 0.0;
  v16->visibility_stat_group.num_total_rendered_points.value = v18;
  if ( *(float *)&default_font > 0.0 )
    v19 = 1.0 / *(float *)&default_font;
  value = v19;
  v20 = 0.0;
  v16->general_stat_group.fps.value = vostok::math::floor(value);
  if ( *(float *)&default_font > 0.0 )
    v20 = 1.0 / *(float *)&default_font;
  valuea = v20;
  v16->general_stat_group.cpu_fps.value = vostok::math::floor(valuea);
  v16->general_stat_group.num_setted_shader_constants.value = *((_DWORD *)m_conflicted_key_name + 23);
  v21 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  v16->visibility_stat_group.num_draw_calls.value = *((_DWORD *)m_conflicted_key_name + 25);
  v16->general_stat_group.render_only_time.value = 0.0;
  texture_video_memory_size = vostok::render::resource_manager::get_texture_video_memory_size(v21);
  v23 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  v16->debug_stat_group.texture_video_memory.value = texture_video_memory_size;
  v23->debug_stat_group.avaliable_video_memory.value = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_block_btn_time;
  v24 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  v25 = scene->m_renderer_context->m_targets->m_memory_usage >> 20;
  v23->debug_stat_group.gbuffer_video_memory.value = v25;
  v23->debug_stat_group.render_tergets_video_memory.value = (*(_DWORD *)&v24[1].m_options_count >> 20) - v25;
  if ( scene->m_stage_debug )
  {
    v23 = *(vostok::render::statistics **)(LODWORD(frame_time) + 276);
    if ( v23 )
      scene->m_stage_debug->execute(scene->m_stage_debug);
  }
  m_begin = (vostok::resources::vfs_sub_fat_resource *)scene->m_stages.m_begin;
  if ( *(&m_begin->m_reconstruction_size + 1) )
  {
    v27 = vostok::math::float4x4::identity(&v39);
    vostok::render::renderer_context::set_w(
      *(&m_begin->m_reconstruction_size + 1),
      v27,
      *(vostok::render::renderer_context **)(*(&m_begin->m_reconstruction_size + 1) + 4));
  }
  if ( scene->m_visibility_stage )
    scene->m_visibility_stage->debug_render(scene->m_visibility_stage);
  if ( s_draw_frame_histogram_value )
    vostok::render::renderer::draw_frame_histogram((vostok::render::renderer *)v23, (int)scene);
  v28 = *(float *)&view->m_portal_system;
  if ( v28 != 0.0 )
    vostok::render::culling::portal_sector_system::render(
      (const vostok::math::float3 *)&scene->m_renderer_context->m_view_pos,
      (vostok::render::culling::portal_sector_system *)LODWORD(v28),
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
      v34);
  v29 = (vostok::resources::vfs_sub_fat_resource *)scene->m_stages.m_begin;
  if ( v29->m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type )
    ((void (__thiscall *)(const vostok::resources::memory_type *))v29->m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type->m_next->resources.m_size)(v29->m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type);
  m_grass = view->m_grass;
  if ( m_grass )
    vostok::render::grass_world::render_debug(m_grass);
  v31 = (vostok::resources::vfs_sub_fat_resource *)scene->m_stages.m_begin;
  if ( v31->type )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v31->type + 12))(v31->type);
}
