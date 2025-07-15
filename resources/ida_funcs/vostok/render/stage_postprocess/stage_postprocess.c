void __userpurge vostok::render::stage_postprocess::stage_postprocess(
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>,
        vostok::render::stage_postprocess *this)
{
  vostok::render::bloom_shader_constants *v3; // ecx
  vostok::render::dof_shader_constants *v4; // ecx
  vostok::render::scene_shader_constants *v5; // ecx
  float v6; // xmm0_4
  char v7; // dl
  vostok::render::effect_options_descriptor *v8; // eax
  vostok::render::effect_options_descriptor *v9; // ecx
  vostok::render::effect_options_descriptor *v10; // eax
  vostok::strings::shared::manager *v11; // ecx
  vostok::strings::shared::profile *v12; // eax
  vostok::render::backend *v13; // ecx
  volatile signed __int32 *p_m_reference_count; // esi
  vostok::strings::shared::manager *v15; // ecx
  vostok::strings::shared::profile *v16; // eax
  vostok::render::backend *v17; // ecx
  volatile signed __int32 *v18; // esi
  vostok::strings::shared::manager *v19; // ecx
  vostok::strings::shared::profile *v20; // eax
  vostok::render::backend *v21; // ecx
  volatile signed __int32 *v22; // esi
  vostok::strings::shared::manager *v23; // ecx
  vostok::strings::shared::profile *v24; // eax
  vostok::render::backend *v25; // ecx
  volatile signed __int32 *v26; // esi
  vostok::strings::shared::manager *v27; // ecx
  vostok::strings::shared::profile *v28; // eax
  vostok::render::backend *v29; // ecx
  volatile signed __int32 *v30; // esi
  vostok::strings::shared::manager *v31; // ecx
  vostok::strings::shared::profile *v32; // eax
  vostok::render::backend *v33; // ecx
  volatile signed __int32 *v34; // esi
  vostok::strings::shared::manager *v35; // ecx
  vostok::strings::shared::profile *v36; // eax
  vostok::render::backend *v37; // ecx
  volatile signed __int32 *v38; // esi
  vostok::strings::shared::manager *v39; // ecx
  vostok::strings::shared::profile *v40; // eax
  vostok::render::backend *v41; // ecx
  volatile signed __int32 *v42; // esi
  vostok::strings::shared::manager *v43; // ecx
  vostok::strings::shared::profile *v44; // eax
  vostok::render::backend *v45; // ecx
  volatile signed __int32 *v46; // esi
  vostok::strings::shared::manager *v47; // ecx
  vostok::strings::shared::profile *v48; // eax
  vostok::render::backend *v49; // ecx
  volatile signed __int32 *v50; // esi
  vostok::strings::shared::manager *v51; // ecx
  vostok::strings::shared::profile *v52; // eax
  vostok::render::backend *v53; // ecx
  volatile signed __int32 *v54; // esi
  vostok::strings::shared::manager *v55; // ecx
  vostok::strings::shared::profile *v56; // eax
  vostok::render::backend *v57; // ecx
  volatile signed __int32 *v58; // esi
  vostok::strings::shared::manager *v59; // ecx
  vostok::strings::shared::profile *v60; // eax
  vostok::render::backend *v61; // ecx
  volatile signed __int32 *v62; // esi
  vostok::strings::shared::manager *v63; // ecx
  vostok::strings::shared::profile *v64; // eax
  vostok::render::backend *v65; // ecx
  volatile signed __int32 *v66; // esi
  vostok::strings::shared::manager *v67; // ecx
  vostok::strings::shared::profile *v68; // eax
  vostok::render::backend *v69; // ecx
  volatile signed __int32 *v70; // esi
  vostok::strings::shared::manager *v71; // ecx
  vostok::strings::shared::profile *v72; // eax
  vostok::strings::shared::manager *v73; // ecx
  vostok::strings::shared::profile *v74; // eax
  vostok::strings::shared::manager *v75; // ecx
  vostok::strings::shared::profile *v76; // eax
  vostok::strings::shared::manager *v77; // ecx
  vostok::strings::shared::profile *v78; // eax
  vostok::strings::shared::manager *v79; // ecx
  vostok::strings::shared::profile *v80; // eax
  vostok::strings::shared::manager *v81; // ecx
  vostok::strings::shared::profile *v82; // eax
  vostok::strings::shared::manager *v83; // ecx
  vostok::strings::shared::profile *v84; // eax
  vostok::render::res_texture *m_object; // eax
  vostok::render::res_texture *v86; // ecx
  vostok::render::res_texture *v87; // esi
  bool v88; // zf
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::res_state *v90; // edi
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v92; // ecx
  vostok::render::res_geometry *v93; // eax
  char v94; // cl
  vostok::shared_string name; // [esp+10h] [ebp-4A8h] BYREF
  char v96; // [esp+1Bh] [ebp-49Dh]
  unsigned __int16 indices[6]; // [esp+1Ch] [ebp-49Ch] BYREF
  vostok::render::effect_options_descriptor desc; // [esp+28h] [ebp-490h] BYREF
  D3D11_INPUT_ELEMENT_DESC screen_vertex_layout[2]; // [esp+40h] [ebp-478h] BYREF
  vostok::math::float4x4 v100; // [esp+78h] [ebp-440h] BYREF
  unsigned __int8 data[1024]; // [esp+B8h] [ebp-400h] BYREF

  this->m_renderer = in_renderer;
  this->m_context = context;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_postprocess_vtbl *)&vostok::render::stage_postprocess::`vftable';
  qmemcpy((void *)&this->m_prev_view_matrix, vostok::math::float4x4::identity(&v100), sizeof(this->m_prev_view_matrix));
  this->m_sh_gather_bloom.m_object = 0;
  this->m_sh_gather_luminance.m_object = 0;
  this->m_sh_gather_luminance_histogram.m_object = 0;
  this->m_sh_eye_adaptation.m_object = 0;
  `vector constructor iterator'(
    (char *)this->m_sh_blur,
    4u,
    8,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)this->m_sh_complex_blend,
    4u,
    8,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  this->m_sh_effect_copy_image.m_object = 0;
  this->m_post_process_antialiasing_shader.m_object = 0;
  this->m_post_process_antialiasing_shader_fxaa.m_object = 0;
  this->m_post_process_antialiasing_shader_sraa.m_object = 0;
  this->m_post_process_shader_sharpen.m_object = 0;
  this->m_god_rays_effect.m_object = 0;
  this->m_post_process_downsample_frame_effect.m_object = 0;
  this->m_image_space_reflections_effect.m_object = 0;
  this->m_lens_flares_effect.m_object = 0;
  this->m_motion_blur_effect.m_object = 0;
  this->m_olta_effect.m_object = 0;
  this->m_temporal_antialiasing_effect.m_object = 0;
  this->m_aberration_effect.m_object = 0;
  this->m_motion_vectors_accumulation_effect.m_object = 0;
  this->m_screen_vertex_ib.m_object = 0;
  this->m_screen_vertex_geometry.m_object = 0;
  this->m_textures.m_reference_count = 0;
  this->m_textures.m_container._M_impl._M_start = 0;
  this->m_textures.m_container._M_impl._M_finish = 0;
  this->m_textures.m_container._M_impl._M_end_of_storage._M_data = 0;
  this->m_textures.m_is_registered = 0;
  this->m_color_grading_base_lut.m_object = 0;
  vostok::render::bloom_shader_constants::bloom_shader_constants(v3, &this->m_bloom_shader_constants.m_bloom_parameters);
  vostok::render::dof_shader_constants::dof_shader_constants(v4, &this->m_dof_shader_constants.m_dof_parameters);
  vostok::render::scene_shader_constants::scene_shader_constants(
    v5,
    &this->m_scene_shader_constants.m_frame_height_lights_and_desaturation_parameters);
  v6 = SNaN;
  v7 = v96;
  this->m_material_post_effects._M_impl._M_start = 0;
  this->m_material_post_effects._M_impl._M_finish = 0;
  this->m_material_post_effects._M_impl._M_end_of_storage._M_data = 0;
  this->m_image_grain_random_offsets.x = v6;
  this->m_image_grain_random_offsets.y = v6;
  this->m_test_material.m_object = 0;
  *(_QWORD *)&this->m_prev_matrix_map._M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&this->m_prev_matrix_map._M_t._M_header._M_data._M_left = 0;
  this->m_prev_matrix_map._M_t._M_header._M_data._M_color = 0;
  this->m_prev_matrix_map._M_t._M_header._M_data._M_parent = 0;
  this->m_prev_matrix_map._M_t._M_header._M_data._M_left = &this->m_prev_matrix_map._M_t._M_header._M_data;
  this->m_prev_matrix_map._M_t._M_header._M_data._M_right = &this->m_prev_matrix_map._M_t._M_header._M_data;
  this->m_prev_matrix_map._M_t._M_node_count = 0;
  this->m_prev_matrix_map._M_t._M_key_compare.gap0 = v7;
  vostok::render::effect_manager::create_effect<vostok::render::effect_gather_bloom>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_gather_bloom);
  vostok::render::effect_manager::create_effect<vostok::render::effect_gather_luminance>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_gather_luminance);
  vostok::render::effect_manager::create_effect<vostok::render::effect_gather_luminance_histogram>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_gather_luminance_histogram);
  vostok::render::effect_manager::create_effect<vostok::render::effect_eye_adaptation>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_eye_adaptation);
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<3>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    this->m_sh_blur);
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<5>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_blur[1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<7>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_blur[2]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<9>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_blur[3]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<13>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_blur[4]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<17>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_blur[5]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<21>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_blur[6]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_blur<25>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_blur[7]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_complex_post_process_blend<0,0,0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    this->m_sh_complex_blend[0][0]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_complex_post_process_blend<1,0,0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    this->m_sh_complex_blend[1][0]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_complex_post_process_blend<1,1,0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    this->m_sh_complex_blend[1][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_complex_post_process_blend<0,0,1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_complex_blend[0][0][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_complex_post_process_blend<1,0,1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_complex_blend[1][0][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_complex_post_process_blend<1,1,1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_complex_blend[1][1][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_copy_image>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_effect_copy_image);
  vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_mlaa>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_post_process_antialiasing_shader);
  vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_fxaa>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_post_process_antialiasing_shader_fxaa);
  vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_sraa>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_post_process_antialiasing_shader_sraa);
  vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_sharpen>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_post_process_shader_sharpen);
  vostok::render::effect_manager::create_effect<vostok::render::effect_god_rays>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_god_rays_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_post_process_downsample_frame>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_post_process_downsample_frame_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_image_space_reflections>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_image_space_reflections_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_lens_flares>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_lens_flares_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_motion_blur>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_motion_blur_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_olta>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_olta_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_temporal_antialiasing>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_temporal_antialiasing_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_aberration>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_aberration_effect);
  desc.data = &data[24];
  desc.type = 3;
  desc.bytes = 0;
  desc.count = 0;
  desc.id = 0;
  desc.destroyer = 0;
  desc.memory_size = 1024;
  v8 = vostok::render::effect_options_descriptor::operator[](
         (vostok::render::effect_options_descriptor *)3,
         (int)&desc,
         (const char *)&key);
  vostok::render::effect_options_descriptor::operator=<enum vostok::render::enum_vertex_input_type>(
    (vostok::render::effect_options_descriptor *)3,
    v8);
  v10 = vostok::render::effect_options_descriptor::operator[](v9, (int)&desc, (const char *)&stru_960A14);
  vostok::render::effect_options_descriptor::operator=<enum D3D11_CULL_MODE>(
    (vostok::render::effect_options_descriptor *)3,
    v10);
  vostok::render::effect_manager::create_effect<vostok::render::effect_motion_vectors_accumulation>(
    (vostok::render::effect_options_descriptor *)&this->m_motion_vectors_accumulation_effect,
    &desc,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
  v12 = vostok::strings::shared::manager::string(v11, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v12 )
  {
    p_m_reference_count = &v12->m_reference_count;
    name.m_pointer.m_object = v12;
    v13 = (vostok::render::backend *)_InterlockedExchangeAdd(&v12->m_reference_count, 1u);
  }
  this->m_blur_offsets_weights = vostok::render::backend::register_constant_host(
                                   v13,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   &name,
                                   rc_float);
  if ( p_m_reference_count )
  {
    v15 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF);
    if ( !v15 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v16 = vostok::strings::shared::manager::string(v15, (const char *)s_manager.m_variable);
  v18 = 0;
  name.m_pointer.m_object = 0;
  if ( v16 )
  {
    v18 = &v16->m_reference_count;
    name.m_pointer.m_object = v16;
    v17 = (vostok::render::backend *)_InterlockedExchangeAdd(&v16->m_reference_count, 1u);
  }
  this->m_kernel_offsets = vostok::render::backend::register_constant_host(
                             v17,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             &name,
                             rc_float);
  if ( v18 )
  {
    v19 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v18, 0xFFFFFFFF);
    if ( !v19 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v20 = vostok::strings::shared::manager::string(v19, (const char *)s_manager.m_variable);
  v22 = 0;
  name.m_pointer.m_object = 0;
  if ( v20 )
  {
    v22 = &v20->m_reference_count;
    name.m_pointer.m_object = v20;
    v21 = (vostok::render::backend *)_InterlockedExchangeAdd(&v20->m_reference_count, 1u);
  }
  this->m_elapsed_time_parameter = vostok::render::backend::register_constant_host(
                                     v21,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     &name,
                                     rc_float);
  if ( v22 )
  {
    v23 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v22, 0xFFFFFFFF);
    if ( !v23 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v24 = vostok::strings::shared::manager::string(v23, (const char *)s_manager.m_variable);
  v26 = 0;
  name.m_pointer.m_object = 0;
  if ( v24 )
  {
    v26 = &v24->m_reference_count;
    name.m_pointer.m_object = v24;
    v25 = (vostok::render::backend *)_InterlockedExchangeAdd(&v24->m_reference_count, 1u);
  }
  this->m_adaptation_factor = vostok::render::backend::register_constant_host(
                                v25,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                &name,
                                rc_float);
  if ( v26 )
  {
    v27 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v26, 0xFFFFFFFF);
    if ( !v27 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v28 = vostok::strings::shared::manager::string(v27, (const char *)s_manager.m_variable);
  v30 = 0;
  name.m_pointer.m_object = 0;
  if ( v28 )
  {
    v30 = &v28->m_reference_count;
    name.m_pointer.m_object = v28;
    v29 = (vostok::render::backend *)_InterlockedExchangeAdd(&v28->m_reference_count, 1u);
  }
  this->m_sun_direction_parameter = vostok::render::backend::register_constant_host(
                                      v29,
                                      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                      &name,
                                      rc_float);
  if ( v30 )
  {
    v31 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v30, 0xFFFFFFFF);
    if ( !v31 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v32 = vostok::strings::shared::manager::string(v31, (const char *)s_manager.m_variable);
  v34 = 0;
  name.m_pointer.m_object = 0;
  if ( v32 )
  {
    v34 = &v32->m_reference_count;
    name.m_pointer.m_object = v32;
    v33 = (vostok::render::backend *)_InterlockedExchangeAdd(&v32->m_reference_count, 1u);
  }
  this->m_frame_luminance_parameter = vostok::render::backend::register_constant_host(
                                        v33,
                                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                        &name,
                                        rc_float);
  if ( v34 )
  {
    v35 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v34, 0xFFFFFFFF);
    if ( !v35 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v36 = vostok::strings::shared::manager::string(v35, (const char *)s_manager.m_variable);
  v38 = 0;
  name.m_pointer.m_object = 0;
  if ( v36 )
  {
    v38 = &v36->m_reference_count;
    name.m_pointer.m_object = v36;
    v37 = (vostok::render::backend *)_InterlockedExchangeAdd(&v36->m_reference_count, 1u);
  }
  this->m_luminance_range_parameter_parameter = vostok::render::backend::register_constant_host(
                                                  v37,
                                                  (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                  &name,
                                                  rc_float);
  if ( v38 )
  {
    v39 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v38, 0xFFFFFFFF);
    if ( !v39 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v40 = vostok::strings::shared::manager::string(v39, (const char *)s_manager.m_variable);
  v42 = 0;
  name.m_pointer.m_object = 0;
  if ( v40 )
  {
    v42 = &v40->m_reference_count;
    name.m_pointer.m_object = v40;
    v41 = (vostok::render::backend *)_InterlockedExchangeAdd(&v40->m_reference_count, 1u);
  }
  this->m_gamma_correction_factor = vostok::render::backend::register_constant_host(
                                      v41,
                                      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                      &name,
                                      rc_float);
  if ( v42 )
  {
    v43 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v42, 0xFFFFFFFF);
    if ( !v43 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v44 = vostok::strings::shared::manager::string(v43, (const char *)s_manager.m_variable);
  v46 = 0;
  name.m_pointer.m_object = 0;
  if ( v44 )
  {
    v46 = &v44->m_reference_count;
    name.m_pointer.m_object = v44;
    v45 = (vostok::render::backend *)_InterlockedExchangeAdd(&v44->m_reference_count, 1u);
  }
  this->m_fxaa_parameters = vostok::render::backend::register_constant_host(
                              v45,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_float);
  if ( v46 )
  {
    v47 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v46, 0xFFFFFFFF);
    if ( !v47 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v48 = vostok::strings::shared::manager::string(v47, (const char *)s_manager.m_variable);
  v50 = 0;
  name.m_pointer.m_object = 0;
  if ( v48 )
  {
    v50 = &v48->m_reference_count;
    name.m_pointer.m_object = v48;
    v49 = (vostok::render::backend *)_InterlockedExchangeAdd(&v48->m_reference_count, 1u);
  }
  this->m_god_rays_parameters0 = vostok::render::backend::register_constant_host(
                                   v49,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   &name,
                                   rc_float);
  if ( v50 )
  {
    v51 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v50, 0xFFFFFFFF);
    if ( !v51 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v52 = vostok::strings::shared::manager::string(v51, (const char *)s_manager.m_variable);
  v54 = 0;
  name.m_pointer.m_object = 0;
  if ( v52 )
  {
    v54 = &v52->m_reference_count;
    name.m_pointer.m_object = v52;
    v53 = (vostok::render::backend *)_InterlockedExchangeAdd(&v52->m_reference_count, 1u);
  }
  this->m_god_rays_parameters1 = vostok::render::backend::register_constant_host(
                                   v53,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   &name,
                                   rc_float);
  if ( v54 )
  {
    v55 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v54, 0xFFFFFFFF);
    if ( !v55 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v56 = vostok::strings::shared::manager::string(v55, (const char *)s_manager.m_variable);
  v58 = 0;
  name.m_pointer.m_object = 0;
  if ( v56 )
  {
    v58 = &v56->m_reference_count;
    name.m_pointer.m_object = v56;
    v57 = (vostok::render::backend *)_InterlockedExchangeAdd(&v56->m_reference_count, 1u);
  }
  this->m_god_rays_parameters2 = vostok::render::backend::register_constant_host(
                                   v57,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   &name,
                                   rc_float);
  if ( v58 )
  {
    v59 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v58, 0xFFFFFFFF);
    if ( !v59 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v60 = vostok::strings::shared::manager::string(v59, (const char *)s_manager.m_variable);
  v62 = 0;
  name.m_pointer.m_object = 0;
  if ( v60 )
  {
    v62 = &v60->m_reference_count;
    name.m_pointer.m_object = v60;
    v61 = (vostok::render::backend *)_InterlockedExchangeAdd(&v60->m_reference_count, 1u);
  }
  this->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
                               v61,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               &name,
                               rc_float);
  if ( v62 )
  {
    v63 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v62, 0xFFFFFFFF);
    if ( !v63 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v64 = vostok::strings::shared::manager::string(v63, (const char *)s_manager.m_variable);
  v66 = 0;
  name.m_pointer.m_object = 0;
  if ( v64 )
  {
    v66 = &v64->m_reference_count;
    name.m_pointer.m_object = v64;
    v65 = (vostok::render::backend *)_InterlockedExchangeAdd(&v64->m_reference_count, 1u);
  }
  this->m_c_frame_index = vostok::render::backend::register_constant_host(
                            v65,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_int);
  if ( v66 )
  {
    v67 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v66, 0xFFFFFFFF);
    if ( !v67 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v68 = vostok::strings::shared::manager::string(v67, (const char *)s_manager.m_variable);
  v70 = 0;
  name.m_pointer.m_object = 0;
  if ( v68 )
  {
    v70 = &v68->m_reference_count;
    name.m_pointer.m_object = v68;
    v69 = (vostok::render::backend *)_InterlockedExchangeAdd(&v68->m_reference_count, 1u);
  }
  this->m_blur_target_size_parameter = vostok::render::backend::register_constant_host(
                                         v69,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         &name,
                                         rc_float);
  if ( v70 )
  {
    v71 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v70, 0xFFFFFFFF);
    if ( !v71 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v72 = vostok::strings::shared::manager::string(v71, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v72);
  this->m_lens_flares_parameters = vostok::render::backend::register_constant_host(
                                     (vostok::render::backend *)&name,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     &name,
                                     rc_float);
  if ( name.m_pointer.m_object )
  {
    v73 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(
                                                &name.m_pointer.m_object->m_reference_count,
                                                0xFFFFFFFF);
    if ( !v73 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v74 = vostok::strings::shared::manager::string(v73, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v74);
  this->m_prev_view_matrix_parameter = vostok::render::backend::register_constant_host(
                                         (vostok::render::backend *)&name,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         &name,
                                         rc_float);
  if ( name.m_pointer.m_object )
  {
    v75 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(
                                                &name.m_pointer.m_object->m_reference_count,
                                                0xFFFFFFFF);
    if ( !v75 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v76 = vostok::strings::shared::manager::string(v75, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v76);
  this->m_prev_world_view_matrix_parameter = vostok::render::backend::register_constant_host(
                                               (vostok::render::backend *)&name,
                                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                               &name,
                                               rc_float);
  if ( name.m_pointer.m_object )
  {
    v77 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(
                                                &name.m_pointer.m_object->m_reference_count,
                                                0xFFFFFFFF);
    if ( !v77 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v78 = vostok::strings::shared::manager::string(v77, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v78);
  this->m_inverse_world_matrix_parameter = vostok::render::backend::register_constant_host(
                                             (vostok::render::backend *)&name,
                                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                             &name,
                                             rc_float);
  if ( name.m_pointer.m_object )
  {
    v79 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(
                                                &name.m_pointer.m_object->m_reference_count,
                                                0xFFFFFFFF);
    if ( !v79 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v80 = vostok::strings::shared::manager::string(v79, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v80);
  this->m_frame_delta_parameter = vostok::render::backend::register_constant_host(
                                    (vostok::render::backend *)&name,
                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                    &name,
                                    rc_float);
  if ( name.m_pointer.m_object )
  {
    v81 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(
                                                &name.m_pointer.m_object->m_reference_count,
                                                0xFFFFFFFF);
    if ( !v81 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v82 = vostok::strings::shared::manager::string(v81, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v82);
  this->m_motion_blur_scale_parameter = vostok::render::backend::register_constant_host(
                                          (vostok::render::backend *)&name,
                                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                          &name,
                                          rc_float);
  if ( name.m_pointer.m_object )
  {
    v83 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(
                                                &name.m_pointer.m_object->m_reference_count,
                                                0xFFFFFFFF);
    if ( !v83 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v84 = vostok::strings::shared::manager::string(v83, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v84);
  this->m_aberration_parameters = vostok::render::backend::register_constant_host(
                                    (vostok::render::backend *)&name,
                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                    &name,
                                    rc_float);
  if ( name.m_pointer.m_object && !_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  m_object = vostok::render::create_color_grading_base_lut_0((vostok::render::res_texture **)&name)->m_object;
  v86 = 0;
  if ( m_object )
  {
    v86 = m_object;
    ++m_object->m_reference_count;
  }
  v87 = this->m_color_grading_base_lut.m_object;
  this->m_color_grading_base_lut.m_object = v86;
  if ( v87 )
  {
    v88 = v87->m_reference_count-- == 1;
    if ( v88 )
      vostok::render::res_texture::destroy_impl(v86, v87);
  }
  if ( name.m_pointer.m_object )
  {
    v88 = name.m_pointer.m_object->next_in_hashset-- == (vostok::strings::shared::profile *)1;
    if ( v88 )
      vostok::render::res_texture::destroy_impl(v86, (const vostok::render::res_texture *)name.m_pointer.m_object);
  }
  name.m_pointer.m_object = 0;
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::resize(
    &this->m_textures.m_container._M_impl,
    0xAu,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&name);
  screen_vertex_layout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
  screen_vertex_layout[1].AlignedByteOffset = 16;
  indices[0] = 0;
  indices[1] = 1;
  indices[2] = 2;
  indices[3] = 3;
  indices[4] = 2;
  indices[5] = 1;
  screen_vertex_layout[0].SemanticName = "POSITION";
  screen_vertex_layout[0].SemanticIndex = 0;
  screen_vertex_layout[0].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  screen_vertex_layout[0].InputSlot = 0;
  screen_vertex_layout[0].AlignedByteOffset = 0;
  screen_vertex_layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[0].InstanceDataStepRate = 0;
  screen_vertex_layout[1].SemanticName = "TEXCOORD";
  screen_vertex_layout[1].SemanticIndex = 0;
  screen_vertex_layout[1].InputSlot = 0;
  screen_vertex_layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[1].InstanceDataStepRate = 0;
  buffer = vostok::render::resource_manager::create_buffer(
             0xCu,
             (bool)&name,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             indices,
             enum_buffer_type_index,
             0,
             0);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    buffer,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&name);
  v90 = (vostok::render::res_state *)this->m_screen_vertex_ib.m_object;
  this->m_screen_vertex_ib.m_object = (vostok::render::untyped_buffer *)name.m_pointer.m_object;
  if ( v90 )
  {
    v88 = v90->m_reference_count-- == 1;
    if ( v88 )
      vostok::render::resource_manager::release(
        v90,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  geometry = vostok::render::resource_manager::create_geometry(
               (stlp_std::forward_iterator_tag *)screen_vertex_layout,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               2u,
               0x18u,
               *((vostok::render::untyped_buffer **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
               + 10),
               this->m_screen_vertex_ib.m_object);
  v92 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v92 = geometry;
  }
  v93 = this->m_screen_vertex_geometry.m_object;
  this->m_screen_vertex_geometry.m_object = v92;
  if ( v93 )
  {
    v88 = v93->m_reference_count-- == 1;
    if ( v88 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v93);
  }
  v94 = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 255);
  this->m_image_grain_random_offsets.y = 0.0;
  this->m_enabled = v94;
  this->m_image_grain_random_offsets.x = 0.0;
}
