void __usercall vostok::render::options::register_console_commands(vostok::render::options *this@<ecx>, int a2@<edi>)
{
  vostok::console_commands::cc_float *m_next; // eax
  vostok::render::options *v3; // [esp+8h] [ebp-10h]
  vostok::render::options *v4; // [esp+8h] [ebp-10h]
  vostok::render::options *v5; // [esp+8h] [ebp-10h]
  vostok::render::options *v6; // [esp+8h] [ebp-10h]
  vostok::render::options *v7; // [esp+8h] [ebp-10h]
  vostok::render::options *v8; // [esp+8h] [ebp-10h]
  vostok::render::options *v9; // [esp+8h] [ebp-10h]
  vostok::render::options *v10; // [esp+8h] [ebp-10h]
  vostok::render::options *v11; // [esp+8h] [ebp-10h]
  vostok::render::options *v12; // [esp+8h] [ebp-10h]
  vostok::render::options *v13; // [esp+8h] [ebp-10h]
  vostok::render::options *v14; // [esp+8h] [ebp-10h]
  vostok::render::options *v15; // [esp+8h] [ebp-10h]
  vostok::render::options *v16; // [esp+8h] [ebp-10h]
  vostok::render::options *v17; // [esp+8h] [ebp-10h]
  vostok::render::options *v18; // [esp+8h] [ebp-10h]
  vostok::render::options *v19; // [esp+8h] [ebp-10h]
  vostok::render::options *v20; // [esp+8h] [ebp-10h]
  vostok::render::options *v21; // [esp+8h] [ebp-10h]
  vostok::render::options *v22; // [esp+8h] [ebp-10h]
  vostok::render::options *v23; // [esp+8h] [ebp-10h]
  vostok::render::options *v24; // [esp+8h] [ebp-10h]
  vostok::render::options *v25; // [esp+8h] [ebp-10h]
  vostok::render::options *v26; // [esp+8h] [ebp-10h]
  vostok::render::options *v27; // [esp+8h] [ebp-10h]
  vostok::render::options *v28; // [esp+8h] [ebp-10h]
  vostok::render::options *v29; // [esp+8h] [ebp-10h]
  vostok::render::options *v30; // [esp+8h] [ebp-10h]
  vostok::render::options *v31; // [esp+8h] [ebp-10h]
  vostok::render::options *v32; // [esp+8h] [ebp-10h]
  vostok::render::options *v33; // [esp+8h] [ebp-10h]
  vostok::render::options *v34; // [esp+8h] [ebp-10h]
  vostok::render::options *v35; // [esp+8h] [ebp-10h]
  vostok::render::options *v36; // [esp+8h] [ebp-10h]
  vostok::render::options *v37; // [esp+8h] [ebp-10h]
  vostok::render::options *v38; // [esp+8h] [ebp-10h]
  vostok::render::options *v39; // [esp+8h] [ebp-10h]
  vostok::render::options *v40; // [esp+8h] [ebp-10h]
  vostok::render::options *v41; // [esp+8h] [ebp-10h]
  vostok::render::options *v42; // [esp+8h] [ebp-10h]
  vostok::render::options *v43; // [esp+8h] [ebp-10h]
  vostok::console_commands::command_type v44; // [esp+Ch] [ebp-Ch]

  if ( (_S5_4 & 1) == 0 )
  {
    _S5_4 |= 1u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_grass_lod1_distance",
      ocr_need_nothing,
      (float *)(a2 + 80),
      (float *)(a2 + 376),
      COERCE_FLOAT_(1000.0),
      COERCE_FLOAT(1),
      COERCE_FLOAT(1));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__grass_lod1_distance_cc__);
    this = v3;
  }
  if ( (_S5_4 & 2) == 0 )
  {
    _S5_4 |= 2u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_grass_lod2_distance",
      ocr_need_nothing,
      (float *)(a2 + 84),
      (float *)(a2 + 380),
      COERCE_FLOAT_(1000.0),
      COERCE_FLOAT(1),
      COERCE_FLOAT(1));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__grass_lod2_distance_cc__);
    this = v4;
  }
  if ( (_S5_4 & 4) == 0 )
  {
    _S5_4 |= 4u;
    vostok::render::render_cc_u32::render_cc_u32(
      &light_propagation_volumes_rsm_size_cc,
      0,
      "r_light_propagation_volumes_rsm_size",
      (const char *)0x200,
      (unsigned int *)(a2 + 160),
      (unsigned int *)(a2 + 456),
      1u,
      0x800u,
      1,
      command_type_engine_internal);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__light_propagation_volumes_rsm_size_cc__);
    this = v5;
  }
  if ( (_S5_4 & 8) == 0 )
  {
    _S5_4 |= 8u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_lpv_flux_amplifier",
      ocr_need_nothing,
      (float *)(a2 + 16),
      (float *)(a2 + 312),
      (float *)LODWORD(s_spot_max_distance),
      COERCE_FLOAT(1),
      COERCE_FLOAT(1));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__lpv_flux_amplifier_cc__);
    this = v6;
  }
  if ( (_S5_4 & 0x10) == 0 )
  {
    _S5_4 |= 0x10u;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &lpv_gather_occluders_from_light_view_cc,
      "r_lpv_gather_occluders_from_light_view",
      (const char *)1,
      (bool *)(a2 + 288),
      (bool *)(a2 + 584),
      (bool *)1,
      command_type_engine_internal,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__lpv_gather_occluders_from_light_view_cc__);
    this = v7;
  }
  if ( (_S5_4 & 0x20) == 0 )
  {
    _S5_4 |= 0x20u;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &lpv_gather_occluders_from_camera_view_cc,
      "r_lpv_gather_occluders_from_camera_view",
      (const char *)1,
      (bool *)(a2 + 289),
      (bool *)(a2 + 585),
      (bool *)1,
      command_type_engine_internal,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__lpv_gather_occluders_from_camera_view_cc__);
    this = v8;
  }
  if ( (_S5_4 & 0x40) == 0 )
  {
    _S5_4 |= 0x40u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_lpv_interreflection_contribution",
      ocr_need_nothing,
      (float *)(a2 + 20),
      (float *)(a2 + 316),
      (float *)LODWORD(s_spot_max_distance),
      COERCE_FLOAT(1),
      COERCE_FLOAT(1));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__lpv_interreflection_contribution_cc__);
    this = v9;
  }
  if ( (_S5_4 & 0x80u) == 0 )
  {
    _S5_4 |= 0x80u;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &lpv_movable_cc,
      "r_lpv_movable",
      (const char *)1,
      (bool *)(a2 + 287),
      (bool *)(a2 + 583),
      (bool *)1,
      command_type_engine_internal,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__lpv_movable_cc__);
    this = v10;
  }
  if ( (_S5_4 & 0x100) == 0 )
  {
    _S5_4 |= 0x100u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_lpv_occlusion_amplifier",
      ocr_need_nothing,
      (float *)(a2 + 28),
      (float *)(a2 + 324),
      (float *)LODWORD(s_spot_max_distance),
      COERCE_FLOAT(1),
      COERCE_FLOAT(1));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__lpv_occlusion_amplifier_cc__);
    this = v11;
  }
  if ( (_S5_4 & 0x200) == 0 )
  {
    _S5_4 |= 0x200u;
    vostok::render::render_cc_u32::render_cc_u32(
      &lpv_refresh_once_per_frames_cc,
      0,
      "r_lpv_refresh_once_per_frames",
      (const char *)1,
      (unsigned int *)(a2 + 176),
      (unsigned int *)(a2 + 472),
      1u,
      0x400u,
      1,
      command_type_engine_internal);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__lpv_refresh_once_per_frames_cc__);
    this = v12;
  }
  if ( (_S5_4 & 0x400) == 0 )
  {
    _S5_4 |= 0x400u;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &lpv_use_specular_reflection_cc,
      "r_lpv_use_specular_reflection",
      (const char *)1,
      (bool *)(a2 + 296),
      (bool *)(a2 + 592),
      (bool *)1,
      command_type_engine_internal,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__lpv_use_specular_reflection_cc__);
    this = v13;
  }
  if ( (_S5_4 & 0x800) == 0 )
  {
    _S5_4 |= 0x800u;
    vostok::render::render_cc_u32::render_cc_u32(
      &num_radiance_volume_cells_cc,
      0,
      "r_num_radiance_volume_cells",
      (const char *)0x200,
      (unsigned int *)(a2 + 164),
      (unsigned int *)(a2 + 460),
      8u,
      0x80u,
      1,
      command_type_engine_internal);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__num_radiance_volume_cells_cc__);
    this = v14;
  }
  if ( (_S5_4 & 0x1000) == 0 )
  {
    _S5_4 |= 0x1000u;
    vostok::render::render_cc_u32::render_cc_u32(
      &num_propagate_iterations_cc,
      0,
      "r_num_propagate_iterations",
      (const char *)0x200,
      (unsigned int *)(a2 + 168),
      (unsigned int *)(a2 + 464),
      0,
      0x20u,
      1,
      command_type_engine_internal);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__num_propagate_iterations_cc__);
    this = v15;
  }
  if ( (_S5_4 & 0x2000) == 0 )
  {
    _S5_4 |= 0x2000u;
    vostok::render::render_cc_u32::render_cc_u32(
      &num_shadow_cascades_cc,
      0,
      "r_num_shadow_cascades",
      (const char *)1,
      (unsigned int *)(a2 + 196),
      (unsigned int *)(a2 + 492),
      1u,
      4u,
      1,
      command_type_engine_internal);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__num_shadow_cascades_cc__);
    this = v16;
  }
  if ( (_S5_4 & 0x4000) == 0 )
  {
    _S5_4 |= 0x4000u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_radiance_volume_scale",
      ocr_need_reset_renderer,
      (float *)(a2 + 12),
      (float *)(a2 + 308),
      COERCE_FLOAT_(10000.0),
      COERCE_FLOAT(1),
      COERCE_FLOAT(1));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__radiance_volume_scale_cc__);
    this = v17;
  }
  if ( (_S5_4 & 0x8000) == 0 )
  {
    _S5_4 |= 0x8000u;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &use_hiz_occlusion_culling_cc,
      "r_use_hiz_occlusion_culling",
      (const char *)1,
      (bool *)(a2 + 300),
      (bool *)(a2 + 596),
      (bool *)1,
      command_type_user_specific,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__use_hiz_occlusion_culling_cc__);
    this = v18;
  }
  if ( ((unsigned int)&_sbh_sizeHeaderList & _S5_4) == 0 )
  {
    _S5_4 |= (unsigned int)&_sbh_sizeHeaderList;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_fxaa_quality_subpix",
      ocr_need_nothing,
      (float *)(a2 + 68),
      (float *)(a2 + 364),
      COERCE_FLOAT_(100000.0),
      0.0,
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__fxaa_quality_subpix_cc__);
    this = v19;
  }
  if ( ((unsigned int)&loc_20000 & _S5_4) == 0 )
  {
    _S5_4 |= (unsigned int)&loc_20000;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_fxaa_quality_edge_threshold",
      ocr_need_nothing,
      (float *)(a2 + 72),
      (float *)(a2 + 368),
      COERCE_FLOAT_(100000.0),
      0.0,
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__fxaa_quality_edge_threshold_cc__);
    this = v20;
  }
  if ( (((unsigned int)&loc_3FFFF + 1) & _S5_4) == 0 )
  {
    _S5_4 |= (unsigned int)&loc_3FFFF + 1;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_fxaa_quality_edge_threshold_min",
      ocr_need_nothing,
      (float *)(a2 + 76),
      (float *)(a2 + 372),
      COERCE_FLOAT_(100000.0),
      0.0,
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__fxaa_quality_edge_threshold_min_cc__);
    this = v21;
  }
  if ( (_S5_4 & 0x80000) == 0 )
  {
    _S5_4 |= 0x80000u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_ssao_screen_ratio",
      ocr_need_resize_window,
      (float *)(a2 + 88),
      (float *)(a2 + 384),
      COERCE_FLOAT_(1.0),
      COERCE_FLOAT(1),
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__ssao_screen_ratio_cc__);
    this = v22;
  }
  if ( ((unsigned int)&loc_100000 & _S5_4) == 0 )
  {
    _S5_4 |= (unsigned int)&loc_100000;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &ssao_use_filtering_cc,
      "r_ssao_use_filtering",
      (const char *)0x80,
      (bool *)(a2 + 301),
      (bool *)(a2 + 597),
      (bool *)1,
      command_type_user_specific,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__ssao_use_filtering_cc__);
    this = v23;
  }
  if ( ((unsigned int)&loc_200000 & _S5_4) == 0 )
  {
    _S5_4 |= (unsigned int)&loc_200000;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &ssao_use_temporal_filtering_cc,
      "r_ssao_use_temporal_filtering",
      (const char *)1,
      (bool *)(a2 + 302),
      (bool *)(a2 + 598),
      (bool *)1,
      command_type_user_specific,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__ssao_use_temporal_filtering_cc__);
    this = v24;
  }
  if ( ((unsigned int)&loc_400000 & _S5_4) == 0 )
  {
    _S5_4 |= (unsigned int)&loc_400000;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &use_shader_lods_cc,
      "r_use_shader_lods",
      (const char *)1,
      (bool *)(a2 + 304),
      (bool *)(a2 + 600),
      (bool *)1,
      command_type_user_specific,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__use_shader_lods_cc__);
    this = v25;
  }
  if ( ((unsigned int)"esource_ptr<class vostok::sound::sound_emitter,class vostok::resources::unmanaged_intrusive_base>,const class vostok::sound::sound_propagator_emitter &,class vostok::sound::world_user &)"
      & _S5_4) == 0 )
  {
    _S5_4 |= (unsigned int)"esource_ptr<class vostok::sound::sound_emitter,class vostok::resources::unmanaged_intrusive_base>,const class vostok::sound::sound_propagator_emitter &,class vostok::sound::world_user &)";
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &use_texture_streaming_cc,
      "r_use_texture_streaming",
      (const char *)4,
      (bool *)(a2 + 305),
      (bool *)(a2 + 601),
      (bool *)1,
      command_type_user_specific,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__use_texture_streaming_cc__);
    this = v26;
  }
  if ( ((unsigned int)&s_ui_commands_allocator.m_buffer[2035360] & _S5_4) == 0 )
  {
    _S5_4 |= (unsigned int)&s_ui_commands_allocator.m_buffer[2035360];
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &use_motion_vectors_in_taa_cc,
      "r_use_motion_vectors_in_taa",
      (const char *)1,
      (bool *)(a2 + 306),
      (bool *)(a2 + 602),
      (bool *)1,
      command_type_user_specific,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__use_motion_vectors_in_taa_cc__);
    this = v27;
  }
  if ( ((unsigned int)&s_ui_commands_allocator.m_buffer[18812576] & _S5_4) == 0 )
  {
    _S5_4 |= (unsigned int)&s_ui_commands_allocator.m_buffer[18812576];
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_motion_blur_scale",
      ocr_need_nothing,
      (float *)(a2 + 92),
      (float *)(a2 + 388),
      (float *)LODWORD(s_spot_max_distance),
      COERCE_FLOAT(1),
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__motion_blur_scale_cc__);
    this = v28;
  }
  if ( ((unsigned int)&s_ui_commands_allocator.m_buffer[52367008] & _S5_4) == 0 )
  {
    _S5_4 |= (unsigned int)&s_ui_commands_allocator.m_buffer[52367008];
    vostok::render::render_cc_u32::render_cc_u32(
      &texture_quality_cc,
      0,
      "r_texture_quality",
      (const char *)4,
      (unsigned int *)(a2 + 200),
      (unsigned int *)(a2 + 496),
      0,
      2u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__texture_quality_cc__);
    this = v29;
  }
  if ( (_S5_4 & 0x8000000) == 0 )
  {
    _S5_4 |= 0x8000000u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_gamma_correction_factor",
      ocr_need_nothing,
      (float *)(a2 + 96),
      (float *)(a2 + 392),
      (float *)LODWORD(vostok::sound::s_lpf_param),
      COERCE_FLOAT(1),
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__gamma_correction_factor_cc__);
    this = v30;
  }
  if ( (_S5_4 & 0x10000000) == 0 )
  {
    _S5_4 |= 0x10000000u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_gbuffer_min_screen_factor",
      ocr_need_nothing,
      (float *)(a2 + 100),
      (float *)(a2 + 396),
      COERCE_FLOAT_(1.0),
      0.0,
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__gbuffer_min_screen_factor_cc__);
    this = v31;
  }
  if ( (_S5_4 & 0x20000000) == 0 )
  {
    _S5_4 |= 0x20000000u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_shadow_cascade_0_max_screen_factor",
      ocr_need_nothing,
      (float *)(a2 + 104),
      (float *)(a2 + 400),
      (float *)LODWORD(s_spot_max_distance),
      0.0,
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__shadow_cascade_0_max_screen_factor_cc__);
    this = v32;
  }
  if ( (_S5_4 & 0x40000000) == 0 )
  {
    _S5_4 |= 0x40000000u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_shadow_cascade_1_max_screen_factor",
      ocr_need_nothing,
      (float *)(a2 + 108),
      (float *)(a2 + 404),
      (float *)LODWORD(s_spot_max_distance),
      0.0,
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__shadow_cascade_1_max_screen_factor_cc__);
    this = v33;
  }
  if ( (_S5_4 & 0x80000000) == 0 )
  {
    _S5_4 |= 0x80000000;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_shadow_cascade_2_max_screen_factor",
      ocr_need_nothing,
      (float *)(a2 + 112),
      (float *)(a2 + 408),
      (float *)LODWORD(s_spot_max_distance),
      0.0,
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__shadow_cascade_2_max_screen_factor_cc__);
    this = v34;
  }
  if ( (_S6_1 & 1) == 0 )
  {
    _S6_1 |= 1u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_shadow_cascade_3_max_screen_factor",
      ocr_need_nothing,
      (float *)(a2 + 116),
      (float *)(a2 + 412),
      (float *)LODWORD(s_spot_max_distance),
      0.0,
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__shadow_cascade_3_max_screen_factor_cc__);
    this = v35;
  }
  if ( (_S6_1 & 2) == 0 )
  {
    _S6_1 |= 2u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_shader_lod_1_max_screen_factor",
      ocr_need_nothing,
      (float *)(a2 + 120),
      (float *)(a2 + 416),
      COERCE_FLOAT_(1.0),
      0.0,
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__shader_lod_1_max_screen_factor_cc__);
    this = v36;
  }
  if ( (_S6_1 & 4) == 0 )
  {
    _S6_1 |= 4u;
    vostok::render::render_cc_float::render_cc_float(
      (vostok::render::render_cc_float *)this,
      "r_shader_lod_2_max_screen_factor",
      ocr_need_nothing,
      (float *)(a2 + 124),
      (float *)(a2 + 420),
      COERCE_FLOAT_(1.0),
      0.0,
      COERCE_FLOAT(2));
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__shader_lod_2_max_screen_factor_cc__);
    this = v37;
  }
  if ( (_S6_1 & 8) == 0 )
  {
    _S6_1 |= 8u;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &clear_surfaces_cc,
      "r_clear_surfaces",
      (const char *)1,
      (bool *)(a2 + 262),
      (bool *)(a2 + 558),
      0,
      command_type_user_specific,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__clear_surfaces_cc__);
    this = v38;
  }
  if ( (_S6_1 & 0x10) == 0 )
  {
    _S6_1 |= 0x10u;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &instancing_cc,
      "r_instancing",
      (const char *)1,
      (bool *)(a2 + 263),
      (bool *)(a2 + 559),
      (bool *)1,
      command_type_user_specific,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__instancing_cc__);
    this = v39;
  }
  if ( (_S6_1 & 0x20) == 0 )
  {
    _S6_1 |= 0x20u;
    vostok::render::render_cc_u32::render_cc_u32(
      &max_anisotropic_cc,
      0,
      "r_max_anisotropic",
      (const char *)0x20,
      (unsigned int *)(a2 + 204),
      (unsigned int *)(a2 + 500),
      0,
      0x10u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__max_anisotropic_cc__);
    this = v40;
  }
  if ( (_S6_1 & 0x40) == 0 )
  {
    _S6_1 |= 0x40u;
    vostok::render::render_cc_u32::render_cc_u32(
      &monitor_index_cc,
      0,
      "r_monitor_index",
      (const char *)0x80,
      (unsigned int *)(a2 + 208),
      (unsigned int *)(a2 + 504),
      0,
      5u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__monitor_index_cc__);
    this = v41;
  }
  if ( (_S6_1 & 0x80u) == 0 )
  {
    _S6_1 |= 0x80u;
    vostok::render::render_cc_u32::render_cc_u32(
      &geometry_quality_cc,
      0,
      "r_geometry_quality",
      (const char *)1,
      (unsigned int *)(a2 + 212),
      (unsigned int *)(a2 + 508),
      0,
      5u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__geometry_quality_cc__);
    this = v42;
  }
  if ( (_S6_1 & 0x100) == 0 )
  {
    _S6_1 |= 0x100u;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &vsync_cc,
      "r_vsync",
      (const char *)1,
      (bool *)(a2 + 261),
      (bool *)(a2 + 557),
      (bool *)1,
      command_type_user_specific,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__vsync_cc__);
    this = v43;
  }
  if ( (_S6_1 & 0x200) == 0 )
  {
    _S6_1 |= 0x200u;
    vostok::render::render_cc_bool::render_cc_bool(
      (vostok::render::render_cc_bool *)this,
      &fullscreen_cc,
      "r_fullscreen",
      (const char *)0x80,
      (bool *)(a2 + 260),
      (bool *)(a2 + 556),
      (bool *)1,
      command_type_user_specific,
      v44);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__fullscreen_cc__);
  }
  if ( (_S6_1 & 0x400) == 0 )
  {
    _S6_1 |= 0x400u;
    vostok::render::render_cc_u32::render_cc_u32(
      &resolution_x_cc,
      0,
      "r_resolution_x",
      (const char *)0x80,
      (unsigned int *)(a2 + 252),
      (unsigned int *)(a2 + 548),
      1u,
      0x2000u,
      0,
      command_type_engine_internal);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__resolution_x_cc__);
  }
  if ( (_S6_1 & 0x800) == 0 )
  {
    _S6_1 |= 0x800u;
    vostok::render::render_cc_u32::render_cc_u32(
      &resolution_y_cc,
      0,
      "r_resolution_y",
      (const char *)0x80,
      (unsigned int *)(a2 + 256),
      (unsigned int *)(a2 + 552),
      1u,
      0x2000u,
      0,
      command_type_engine_internal);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__resolution_y_cc__);
  }
  if ( (_S6_1 & 0x1000) == 0 )
  {
    _S6_1 |= 0x1000u;
    vostok::render::render_cc_u32::render_cc_u32(
      &shadow_quality_cc,
      (vostok::render::render_cc *)"GLOBAL_SHADOWMAP_QUALITY",
      "r_shadow_quality",
      (const char *)0x800,
      (unsigned int *)(a2 + 156),
      (unsigned int *)(a2 + 452),
      0,
      3u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__shadow_quality_cc__);
  }
  if ( (_S6_1 & 0x2000) == 0 )
  {
    _S6_1 |= 0x2000u;
    vostok::render::render_cc_u32::render_cc_u32(
      &lighting_quality_cc,
      (vostok::render::render_cc *)"GLOBAL_LIGHTING_QUALITY",
      "r_lighting_quality",
      (const char *)0x800,
      (unsigned int *)(a2 + 216),
      (unsigned int *)(a2 + 512),
      0,
      0x64u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__lighting_quality_cc__);
  }
  if ( (_S6_1 & 0x4000) == 0 )
  {
    _S6_1 |= 0x4000u;
    vostok::render::render_cc_u32::render_cc_u32(
      &post_process_quality_cc,
      (vostok::render::render_cc *)"GLOBAL_POST_PROCESS_QUALITY",
      "r_post_process_quality",
      (const char *)0xC80,
      (unsigned int *)(a2 + 220),
      (unsigned int *)(a2 + 516),
      0,
      0x64u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__post_process_quality_cc__);
  }
  if ( (_S6_1 & 0x8000) == 0 )
  {
    _S6_1 |= 0x8000u;
    vostok::render::render_cc_u32::render_cc_u32(
      &shading_quality_cc,
      (vostok::render::render_cc *)"GLOBAL_SHADING_QUALITY",
      "r_shading_quality",
      (const char *)0x810,
      (unsigned int *)(a2 + 232),
      (unsigned int *)(a2 + 528),
      0,
      0x64u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__shading_quality_cc__);
  }
  if ( ((unsigned int)&_sbh_sizeHeaderList & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&_sbh_sizeHeaderList;
    vostok::render::render_cc_u32::render_cc_u32(
      &particles_quality_cc,
      (vostok::render::render_cc *)"GLOBAL_PARTICLE_QUALITY",
      "r_particles_quality",
      (const char *)0x90,
      (unsigned int *)(a2 + 224),
      (unsigned int *)(a2 + 520),
      0,
      0x64u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__particles_quality_cc__);
  }
  if ( ((unsigned int)&loc_20000 & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&loc_20000;
    vostok::render::render_cc_u32::render_cc_u32(
      &motion_blur_quality_cc,
      0,
      "r_motion_blur_quality",
      (const char *)1,
      (unsigned int *)(a2 + 228),
      (unsigned int *)(a2 + 524),
      0,
      0x64u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__motion_blur_quality_cc__);
  }
  if ( (((unsigned int)&loc_3FFFF + 1) & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&loc_3FFFF + 1;
    vostok::render::render_cc_u32::render_cc_u32(
      &ambient_occlusion_quality_cc,
      0,
      "r_ambient_occlusion_quality",
      (const char *)1,
      (unsigned int *)(a2 + 236),
      (unsigned int *)(a2 + 532),
      0,
      0x64u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__ambient_occlusion_quality_cc__);
  }
  if ( (_S6_1 & 0x80000) == 0 )
  {
    _S6_1 |= 0x80000u;
    vostok::render::render_cc_u32::render_cc_u32(
      &antialiasing_method_cc,
      0,
      "r_antialiasing_method",
      (const char *)1,
      (unsigned int *)(a2 + 240),
      (unsigned int *)(a2 + 536),
      0,
      0x64u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__antialiasing_method_cc__);
  }
  if ( ((unsigned int)&loc_100000 & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&loc_100000;
    vostok::render::render_cc_u32::render_cc_u32(
      &decorations_quality_cc,
      0,
      "r_decorations_quality",
      (const char *)1,
      (unsigned int *)(a2 + 244),
      (unsigned int *)(a2 + 540),
      0,
      0x64u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__decorations_quality_cc__);
  }
  if ( ((unsigned int)&loc_200000 & _S6_1) == 0 )
  {
    _S6_1 |= (unsigned int)&loc_200000;
    vostok::render::render_cc_u32::render_cc_u32(
      &graphics_quality_cc,
      0,
      "r_graphics_quality",
      (const char *)1,
      (unsigned int *)(a2 + 248),
      (unsigned int *)(a2 + 544),
      0,
      0x64u,
      1,
      command_type_user_specific);
    atexit((int (__cdecl *)())vostok::render::options::register_console_commands_::_2_::_dynamic_atexit_destructor_for__graphics_quality_cc__);
  }
  m_next = &grass_lod1_distance_cc.vostok::console_commands::cc_float;
  *(_DWORD *)(a2 + 4) = &grass_lod1_distance_cc.vostok::console_commands::cc_float;
  while ( m_next->m_next )
    m_next = (vostok::console_commands::cc_float *)m_next->m_next;
  *(_DWORD *)(a2 + 8) = m_next;
}
