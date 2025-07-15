void __thiscall vostok::render::stage_postprocess::execute(vostok::render::stage_postprocess *this)
{
  vostok::render::base_scene_view *m_object; // ecx
  vostok::render::textures_handler<0> *v3; // ecx
  vostok::render::res_texture *v4; // eax
  vostok::render::res_texture *v5; // esi
  const char *v6; // edi
  vostok::render::res_texture *v7; // ecx
  const char *v8; // esi
  vostok::render::shader_constant_host *m_gamma_correction_factor; // eax
  int v10; // ecx
  unsigned __int16 v11; // cx
  const vostok::render::renderer_context_targets *v12; // eax
  vostok::render::render_target *v13; // eax
  const vostok::math::float4x4 *v14; // eax
  bool v15; // zf
  vostok::render::enum_render_target_index v16; // ecx
  vostok::render::stage_postprocess *v17; // ecx
  vostok::render::enum_render_target_index v18; // ecx
  vostok::render::stage_postprocess *v19; // ecx
  vostok::render::backend *v20; // ecx
  vostok::render::enum_render_target_index v21; // ecx
  vostok::render::stage_postprocess *v22; // ecx
  vostok::render::enum_render_target_index v23; // ecx
  vostok::render::stage_postprocess *v24; // ecx
  vostok::render::lights_db *v25; // eax
  vostok::render::light *v26; // esi
  vostok::render::res_texture *v27; // ecx
  float z; // eax
  __int64 v29; // xmm0_8
  const char *m_conflicted_key_name; // esi
  vostok::render::enum_render_target_index m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_sun_direction_parameter; // eax
  vostok::render::stage_postprocess *v33; // ecx
  const char *v34; // esi
  vostok::render::shader_constant_host *v35; // eax
  unsigned __int16 v36; // cx
  const vostok::render::post_process_parameters *v37; // edi
  vostok::render::shader_constant_host *m_god_rays_parameters0; // eax
  int v39; // ecx
  float god_rays_color_blend_power; // xmm0_4
  unsigned __int16 v41; // cx
  vostok::render::shader_constant_buffer *v42; // edx
  unsigned __int16 m_class_id; // cx
  unsigned __int16 m_slot_index; // ax
  vostok::render::shader_constant_host *m_god_rays_parameters1; // eax
  int v46; // ecx
  float god_rays_intensity; // xmm0_4
  unsigned __int16 v48; // cx
  vostok::render::shader_constant_buffer *v49; // edx
  unsigned __int16 v50; // cx
  unsigned __int16 v51; // ax
  vostok::render::shader_constant_host *m_god_rays_parameters2; // eax
  vostok::render::enum_render_target_index v53; // ecx
  vostok::render::shader_constant_buffer *v54; // edx
  unsigned __int16 v55; // cx
  unsigned __int16 v56; // ax
  vostok::render::stage_postprocess *v57; // ecx
  vostok::render::res_texture *v58; // eax
  vostok::render::res_texture *v59; // esi
  double Width; // st7
  vostok::render::res_texture *v61; // eax
  vostok::render::res_texture *v62; // esi
  vostok::render::res_texture *Height; // ecx
  char v64; // dl
  vostok::render::backend *v65; // ecx
  unsigned int v66; // eax
  vostok::render::res_texture *v67; // xmm3_4
  float v68; // xmm1_4
  float v69; // xmm5_4
  __int64 v70; // xmm2_8
  __int64 v71; // xmm2_8
  __int64 v72; // xmm2_8
  __int64 v73; // xmm2_8
  __int64 v74; // xmm4_8
  __int64 v75; // xmm4_8
  __int64 v76; // xmm4_8
  __int64 v77; // xmm1_8
  __int64 v78; // xmm0_8
  const vostok::render::renderer_context_targets *m_targets; // eax
  vostok::render::render_target *v80; // eax
  const vostok::render::renderer_context_targets *v81; // eax
  vostok::render::render_target *v82; // eax
  const vostok::render::renderer_context_targets *v83; // eax
  vostok::render::render_target *v84; // eax
  const vostok::render::renderer_context_targets *v85; // eax
  vostok::render::render_target *v86; // eax
  vostok::render::stage_postprocess *v87; // ecx
  const char *v88; // esi
  vostok::render::shader_constant_host *m_frame_luminance_parameter; // eax
  vostok::render::enum_render_target_index v90; // ecx
  vostok::render::shader_constant_buffer *v91; // edx
  unsigned __int16 v92; // cx
  unsigned __int16 v93; // ax
  vostok::render::enum_render_target_index v94; // ecx
  vostok::render::stage_postprocess *v95; // ecx
  unsigned int dof_blur_kernel; // edi
  int v97; // esi
  void *v98; // esp
  void *v99; // esp
  void *v100; // esp
  void *v101; // esp
  float *v102; // edi
  void *v103; // esp
  float *v104; // edx
  float *v105; // ecx
  float *p_y; // eax
  unsigned int v107; // esi
  float v108; // xmm0_4
  char *v109; // esi
  float v110; // edi
  float v111; // esi
  unsigned int v112; // esi
  float v113; // xmm0_4
  unsigned int v114; // xmm3_4
  unsigned int v115; // xmm2_4
  float v116; // xmm1_4
  unsigned int v117; // esi
  unsigned int v118; // edi
  _QWORD *v119; // eax
  char *v120; // edx
  unsigned int v121; // esi
  float *v122; // ecx
  unsigned int v123; // xmm3_4
  unsigned int v124; // xmm2_4
  float v125; // xmm1_4
  vostok::render::res_effect *v126; // eax
  int v127; // ecx
  vostok::render::res_texture *v128; // eax
  vostok::render::res_texture *v129; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *M_start; // eax
  vostok::render::res_texture *v131; // ecx
  const vostok::render::res_texture *v132; // esi
  vostok::render::res_texture *v133; // eax
  vostok::render::res_texture *v134; // esi
  const char *v135; // edi
  vostok::render::res_texture *v136; // ecx
  const char *v137; // esi
  vostok::render::render_target *v138; // ecx
  vostok::render::stage_postprocess *v139; // ecx
  vostok::render::backend *v140; // ecx
  vostok::render::res_texture *v141; // eax
  const vostok::render::res_texture *v142; // esi
  vostok::render::res_texture *v143; // ecx
  vostok::render::res_texture *v144; // eax
  vostok::render::res_texture *v145; // esi
  const char *v146; // edi
  vostok::render::res_texture *v147; // ecx
  const char *v148; // esi
  vostok::render::enum_render_target_index v149; // ecx
  vostok::render::stage_postprocess *v150; // ecx
  float vignette_power; // xmm0_4
  float image_grain_scale; // xmm1_4
  float y; // xmm2_4
  unsigned int blur_kernel; // edi
  unsigned int v155; // eax
  signed int v156; // esi
  void *v157; // esp
  void *v158; // esp
  void *v159; // esp
  void *v160; // esp
  float *v161; // edi
  float *v162; // ecx
  void *v163; // esp
  const vostok::render::post_process_parameters **v164; // eax
  float *v165; // edx
  float *v166; // eax
  float *v167; // esi
  float v168; // xmm0_4
  unsigned int v169; // esi
  vostok::render::res_texture *v170; // edi
  int v171; // esi
  char *v172; // esi
  float v173; // xmm0_4
  vostok::render::res_texture_vtbl *v174; // xmm3_4
  unsigned int v175; // xmm2_4
  float v176; // xmm1_4
  float *v177; // esi
  unsigned int v178; // edi
  float *v179; // eax
  unsigned int v180; // edx
  int v181; // esi
  unsigned int v182; // xmm3_4
  unsigned int v183; // xmm2_4
  float v184; // xmm1_4
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v185; // ecx
  vostok::render::res_texture *v186; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v187; // eax
  vostok::render::res_texture *v188; // ecx
  const vostok::render::res_texture *v189; // esi
  vostok::render::res_texture *v190; // esi
  const char *v191; // edi
  vostok::render::textures_handler<0> *v192; // ecx
  vostok::render::res_texture *v193; // ecx
  const char *v194; // esi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v195; // edi
  vostok::render::stage_postprocess *v196; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v197; // ecx
  vostok::render::res_texture *v198; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v199; // eax
  vostok::render::res_texture *v200; // ecx
  const vostok::render::res_texture *v201; // esi
  vostok::render::res_texture *v202; // esi
  const char *v203; // edi
  vostok::render::textures_handler<0> *v204; // ecx
  vostok::render::res_texture *v205; // ecx
  const char *v206; // esi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v207; // edi
  vostok::render::stage_postprocess *v208; // ecx
  const char *v209; // esi
  const char *v210; // esi
  float lens_flares_multiplier; // xmm0_4
  vostok::render::shader_constant_host *m_lens_flares_parameters; // eax
  vostok::render::enum_render_target_index v213; // ecx
  vostok::render::stage_postprocess *v214; // ecx
  vostok::render::backend *v215; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_target; // edi
  vostok::render::stage_postprocess *v217; // ecx
  int use_image_grain; // eax
  BOOL use_bokeh_dof; // ecx
  BOOL use_bokeh_image; // edx
  vostok::render::post_process_parameters *v221; // edi
  double frame_desaturation; // st7
  survarium::game_action_id *v223; // esi
  const char *v224; // esi
  const char *v225; // esi
  vostok::render::constants_handler<1> *v226; // edi
  vostok::render::enum_render_target_index v227; // ecx
  vostok::render::stage_postprocess *v228; // ecx
  survarium::game_action_id *v229; // eax
  vostok::render::shader_constant_host *m_fxaa_parameters; // ecx
  vostok::render::enum_render_target_index v231; // ecx
  vostok::render::stage_postprocess *v232; // ecx
  vostok::render::enum_render_target_index v233; // ecx
  vostok::render::stage_postprocess *v234; // ecx
  vostok::render::enum_render_target_index v235; // ecx
  vostok::render::stage_postprocess *v236; // ecx
  const char *v237; // esi
  vostok::render::res_texture *v238; // ecx
  const char *v239; // esi
  vostok::render::enum_render_target_index v240; // ecx
  vostok::render::stage_postprocess *v241; // ecx
  vostok::render::enum_render_target_index v242; // ecx
  vostok::render::stage_postprocess *v243; // ecx
  vostok::render::backend *v244; // ecx
  vostok::render::enum_render_target_index v245; // ecx
  vostok::render::stage_postprocess *v246; // ecx
  survarium::game_action_id *v247; // eax
  int v248; // esi
  ID3D11Resource *m_surface; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *t; // eax
  vostok::render::res_texture *v251; // ecx
  vostok::render::res_texture *v252; // esi
  vostok::render::render_target *v253; // eax
  const char *v254; // esi
  vostok::render::constants_handler<1> *v255; // edi
  const vostok::math::float3 *v256; // ecx
  vostok::render::shader_constant_host *m_c_frame_index; // eax
  vostok::render::enum_render_target_index v258; // ecx
  vostok::render::stage_postprocess *v259; // ecx
  int v260; // esi
  ID3D11Resource *v261; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v262; // eax
  vostok::render::stage_postprocess *v263; // ecx
  vostok::render::render_target *v264; // eax
  const char *v265; // esi
  vostok::render::constants_handler<1> *v266; // edi
  const vostok::math::float3 *v267; // eax
  vostok::render::shader_constant_host *m_frame_delta_parameter; // eax
  survarium::game_action_id *v269; // eax
  vostok::render::enum_render_target_index v270; // ecx
  vostok::render::stage_postprocess *v271; // ecx
  int v272; // esi
  ID3D11Resource *v273; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v274; // eax
  vostok::render::res_texture *v275; // ecx
  const vostok::render::post_process_parameters *v276; // esi
  float aberration_power; // xmm0_4
  const char *v278; // esi
  vostok::render::enum_render_target_index v279; // ecx
  vostok::render::stage_postprocess *v280; // ecx
  int v281; // esi
  ID3D11Resource *v282; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v283; // eax
  vostok::render::res_texture *v284; // ecx
  const vostok::math::float4x4 *v285; // eax
  float far_blur_amout; // [esp+10h] [ebp-6Ch]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> bokeh_dof_radius; // [esp+14h] [ebp-68h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> bokeh_dof_density; // [esp+18h] [ebp-64h] BYREF
  const vostok::render::post_process_parameters *v289[2]; // [esp+1Ch] [ebp-60h] BYREF
  int v290; // [esp+24h] [ebp-58h] BYREF
  vostok::math::float4x4 result; // [esp+28h] [ebp-54h] BYREF
  vostok::math::float4 frame_luminance_parameter; // [esp+68h] [ebp-14h] BYREF
  vostok::math::float3 sun_direction; // [esp+78h] [ebp-4h] BYREF
  vostok::math::float4 image_grain_parameters; // [esp+84h] [ebp+8h] BYREF
  int v295; // [esp+94h] [ebp+18h]
  int v296; // [esp+98h] [ebp+1Ch]
  char *v297; // [esp+9Ch] [ebp+20h]
  float v298; // [esp+A0h] [ebp+24h]
  float bloom_radius; // [esp+A4h] [ebp+28h]
  float *out_weights; // [esp+A8h] [ebp+2Ch]
  float *v301; // [esp+ACh] [ebp+30h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> t_w; // [esp+B0h] [ebp+34h] BYREF
  const vostok::render::post_process_parameters *pp_parameters; // [esp+B4h] [ebp+38h]
  float dof_radius; // [esp+B8h] [ebp+3Ch]
  unsigned int kernel_index; // [esp+BCh] [ebp+40h]
  float *out_offsets; // [esp+C0h] [ebp+44h]
  unsigned int dof_kernel_index; // [esp+C4h] [ebp+48h]
  float *v308; // [esp+C8h] [ebp+4Ch]
  unsigned int buffer_size[2]; // [esp+CCh] [ebp+50h] BYREF
  unsigned int bloom_kernal; // [esp+D4h] [ebp+58h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> s_u; // [esp+D8h] [ebp+5Ch] BYREF
  unsigned int i; // [esp+DCh] [ebp+60h]
  vostok::math::float4 lens_flares_parameters; // [esp+E0h] [ebp+64h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> t_h; // [esp+F0h] [ebp+74h] BYREF

  if ( !vostok::render::stage_postprocess::is_effects_ready(this, this) )
    return;
  if ( !this->is_enabled(this) )
  {
    this->execute_disabled(this);
    return;
  }
  if ( !prev_view_initialized )
  {
    qmemcpy((void *)&this->m_prev_view_matrix, &this->m_context->m_v, sizeof(this->m_prev_view_matrix));
    prev_view_initialized = 1;
  }
  m_object = this->m_context->m_scene_view.m_object;
  if ( LOBYTE(m_object[4].m_memory_usage_self.size) )
  {
    v15 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 50) == 0;
    pp_parameters = (const vostok::render::post_process_parameters *)&m_object[1];
    if ( !v15 && LOBYTE(m_object[3].m_children_resources.m_thread_id) )
    {
      vostok::render::res_effect::apply(0, &this->m_post_process_downsample_frame_effect.m_object->__vftable);
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)2,
        &bokeh_dof_density,
        this->m_context,
        v16);
      vostok::render::stage_postprocess::fill_surface2(v17, this, bokeh_dof_density);
      vostok::render::res_effect::apply(
        (vostok::render::res_effect *)1,
        &this->m_post_process_downsample_frame_effect.m_object->__vftable);
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)1,
        &bokeh_dof_density,
        this->m_context,
        v18);
      vostok::render::stage_postprocess::fill_surface2(v19, this, bokeh_dof_density);
      vostok::render::backend::flush_rt_shader_resources(
        v20,
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      vostok::render::res_effect::apply(
        (vostok::render::res_effect *)2,
        &this->m_post_process_downsample_frame_effect.m_object->__vftable);
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)2,
        &bokeh_dof_density,
        this->m_context,
        v21);
      vostok::render::stage_postprocess::fill_surface2(v22, this, bokeh_dof_density);
      vostok::render::res_effect::apply(0, &this->m_image_space_reflections_effect.m_object->__vftable);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
        this->m_context->m_eye_rays,
        this->m_c_eye_ray_corner);
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)0x2F,
        &bokeh_dof_density,
        this->m_context,
        v23);
      vostok::render::stage_postprocess::fill_surface2(v24, this, bokeh_dof_density);
    }
    v25 = this->m_context->m_scene->m_lights.m_object;
    memset(&sun_direction, 0, sizeof(sun_direction));
    v26 = vostok::render::lights_db::get_sun(
            (vostok::render::lights_db *)m_object,
            (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v25,
            (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&bloom_kernal)->m_object;
    vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&bloom_kernal);
    if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 50)
      && *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 287)
      && v26
      && v26->m_enabled )
    {
      vostok::render::res_effect::apply(0, &this->m_god_rays_effect.m_object->__vftable);
      z = v26->direction.z;
      v29 = *(_QWORD *)&v26->direction.x;
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      m_buffer_index = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                       + 573);
      sun_direction.z = z;
      m_sun_direction_parameter = this->m_sun_direction_parameter;
      *(_QWORD *)&sun_direction.x = v29;
      if ( m_sun_direction_parameter->m_update_markers[1] == m_buffer_index )
      {
        m_buffer_index = m_sun_direction_parameter->m_shader_slots[1].m_buffer_index;
        if ( (unsigned __int16)m_buffer_index != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            m_sun_direction_parameter->m_shader_slots[1].m_slot_index,
            (unsigned __int8)m_sun_direction_parameter->m_shader_slots[1].m_class_id,
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * (unsigned __int16)m_buffer_index),
            (const char *)&sun_direction);
      }
      ++*((_DWORD *)m_conflicted_key_name + 23);
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)4,
        &bokeh_dof_density,
        this->m_context,
        m_buffer_index);
      vostok::render::stage_postprocess::fill_surface2(v33, this, bokeh_dof_density);
      vostok::render::res_effect::apply((vostok::render::res_effect *)1, &this->m_god_rays_effect.m_object->__vftable);
      v34 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v35 = this->m_sun_direction_parameter;
      if ( v35->m_update_markers[1] == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                       + 573) )
      {
        v36 = v35->m_shader_slots[1].m_buffer_index;
        if ( v36 != 0xFFFF )
          vostok::render::shader_constant_buffer::set_memory(
            v35->m_shader_slots[1].m_slot_index,
            (unsigned __int8)v35->m_shader_slots[1].m_class_id,
            *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                     + 371)
                                                                   + 16)
                                                       + 4 * v36),
            (const char *)&sun_direction);
      }
      ++*((_DWORD *)v34 + 23);
      v37 = pp_parameters;
      m_god_rays_parameters0 = this->m_god_rays_parameters0;
      v39 = *((_DWORD *)v34 + 573);
      god_rays_color_blend_power = pp_parameters->god_rays_color_blend_power;
      *(_QWORD *)&lens_flares_parameters.x = *(_QWORD *)&pp_parameters->god_rays_color_0.x;
      lens_flares_parameters.z = pp_parameters->god_rays_color_0.z;
      lens_flares_parameters.w = god_rays_color_blend_power;
      if ( m_god_rays_parameters0->m_update_markers[1] == v39 )
      {
        v41 = m_god_rays_parameters0->m_shader_slots[1].m_buffer_index;
        if ( v41 != 0xFFFF )
        {
          v42 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v34 + 371) + 16) + 4 * v41);
          m_class_id = m_god_rays_parameters0->m_shader_slots[1].m_class_id;
          m_slot_index = m_god_rays_parameters0->m_shader_slots[1].m_slot_index;
          t_h.m_object = (vostok::render::res_texture *)(unsigned __int8)m_class_id;
          vostok::render::shader_constant_buffer::set_memory(
            m_slot_index,
            (unsigned __int8)m_class_id,
            v42,
            (const char *)&lens_flares_parameters);
        }
      }
      ++*((_DWORD *)v34 + 23);
      m_god_rays_parameters1 = this->m_god_rays_parameters1;
      v46 = *((_DWORD *)v34 + 573);
      god_rays_intensity = v37->god_rays_intensity;
      *(_QWORD *)&lens_flares_parameters.x = *(_QWORD *)&v37->god_rays_color_1.x;
      lens_flares_parameters.z = v37->god_rays_color_1.z;
      lens_flares_parameters.w = god_rays_intensity;
      if ( m_god_rays_parameters1->m_update_markers[1] == v46 )
      {
        v48 = m_god_rays_parameters1->m_shader_slots[1].m_buffer_index;
        if ( v48 != 0xFFFF )
        {
          v49 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v34 + 371) + 16) + 4 * v48);
          v50 = m_god_rays_parameters1->m_shader_slots[1].m_class_id;
          v51 = m_god_rays_parameters1->m_shader_slots[1].m_slot_index;
          t_h.m_object = (vostok::render::res_texture *)(unsigned __int8)v50;
          vostok::render::shader_constant_buffer::set_memory(
            v51,
            (unsigned __int8)v50,
            v49,
            (const char *)&lens_flares_parameters);
        }
      }
      ++*((_DWORD *)v34 + 23);
      m_god_rays_parameters2 = this->m_god_rays_parameters2;
      v53 = *((_DWORD *)v34 + 573);
      *(_QWORD *)&lens_flares_parameters.x = LODWORD(v37->god_rays_attenuation_power);
      *(_QWORD *)&lens_flares_parameters.elements[2] = 0;
      if ( m_god_rays_parameters2->m_update_markers[1] == v53 )
      {
        v53 = m_god_rays_parameters2->m_shader_slots[1].m_buffer_index;
        if ( (unsigned __int16)v53 != 0xFFFF )
        {
          v54 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v34 + 371) + 16)
                                                           + 4 * (unsigned __int16)v53);
          v55 = m_god_rays_parameters2->m_shader_slots[1].m_class_id;
          v56 = m_god_rays_parameters2->m_shader_slots[1].m_slot_index;
          t_h.m_object = (vostok::render::res_texture *)(unsigned __int8)v55;
          vostok::render::shader_constant_buffer::set_memory(
            v56,
            (unsigned __int8)v55,
            v54,
            (const char *)&lens_flares_parameters);
        }
      }
      ++*((_DWORD *)v34 + 23);
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)5,
        &bokeh_dof_density,
        this->m_context,
        v53);
      vostok::render::stage_postprocess::fill_surface2(v57, this, bokeh_dof_density);
    }
    else
    {
      v37 = pp_parameters;
    }
    v58 = this->m_context->m_targets->m_family[30].texture.m_object;
    v59 = 0;
    if ( v58 )
    {
      v59 = this->m_context->m_targets->m_family[30].texture.m_object;
      ++v58->m_reference_count;
    }
    Width = (double)v59->m_desc.Width;
    --v59->m_reference_count;
    *(float *)&t_w.m_object = Width;
    if ( !v59->m_reference_count )
      vostok::render::res_texture::destroy_impl(v27, v59);
    v61 = this->m_context->m_targets->m_family[30].texture.m_object;
    v62 = 0;
    if ( v61 )
    {
      v62 = this->m_context->m_targets->m_family[30].texture.m_object;
      ++v61->m_reference_count;
    }
    Height = (vostok::render::res_texture *)v62->m_desc.Height;
    --v62->m_reference_count;
    *(float *)&t_h.m_object = (float)(unsigned int)Height;
    if ( !v62->m_reference_count )
      vostok::render::res_texture::destroy_impl(Height, v62);
    v64 = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 105);
    if ( v64 )
      v65 = (vostok::render::backend *)*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                       + 27);
    else
      v65 = *(vostok::render::backend **)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                          + 540)
                                        + 144);
    buffer_size[1] = (unsigned int)v65;
    *(float *)&s_u.m_object = 1.0 / (double)(unsigned int)v65;
    if ( v64 )
      v66 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 28);
    else
      v66 = *(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                        + 540)
                      + 148);
    buffer_size[1] = v66;
    v67 = s_u.m_object;
    *(_QWORD *)&lens_flares_parameters.elements[2] = 0;
    LODWORD(v68) = (unsigned int)s_u.m_object ^ 0x80000000;
    LODWORD(lens_flares_parameters.x) = (unsigned int)s_u.m_object ^ 0x80000000;
    *(float *)&bloom_kernal = 1.0 / (double)v66;
    lens_flares_parameters.y = *(float *)&bloom_kernal;
    v69 = *(float *)&bloom_kernal;
    v70 = *(_QWORD *)&lens_flares_parameters.x;
    lens_flares_parameters.y = *(float *)&bloom_kernal;
    *(_QWORD *)&this->kernel_offsets[0].x = v70;
    v71 = *(_QWORD *)&lens_flares_parameters.elements[2];
    LODWORD(lens_flares_parameters.x) = v67;
    *(_QWORD *)&lens_flares_parameters.elements[2] = 0;
    *(_QWORD *)&this->kernel_offsets[0].elements[2] = v71;
    v72 = *(_QWORD *)&lens_flares_parameters.x;
    lens_flares_parameters.x = v68;
    *(_QWORD *)&this->kernel_offsets[1].x = v72;
    v73 = *(_QWORD *)&lens_flares_parameters.elements[2];
    *(_QWORD *)&lens_flares_parameters.elements[2] = 0;
    *(_QWORD *)&this->kernel_offsets[1].elements[2] = v73;
    lens_flares_parameters.y = -v69;
    *(_QWORD *)&this->kernel_offsets[2].x = *(_QWORD *)&lens_flares_parameters.x;
    v74 = *(_QWORD *)&lens_flares_parameters.elements[2];
    LODWORD(lens_flares_parameters.x) = v67;
    *(_QWORD *)&lens_flares_parameters.elements[1] = COERCE_UNSIGNED_INT(-v69);
    lens_flares_parameters.w = 0.0;
    *(_QWORD *)&this->kernel_offsets[2].elements[2] = v74;
    v75 = *(_QWORD *)&lens_flares_parameters.x;
    *(_QWORD *)&this->kernel_offsets[4].x = LODWORD(v68);
    *(_QWORD *)&this->kernel_offsets[3].x = v75;
    v76 = *(_QWORD *)&lens_flares_parameters.elements[2];
    lens_flares_parameters.y = 0.0;
    *(_QWORD *)&this->kernel_offsets[4].elements[2] = LODWORD(lens_flares_parameters.z);
    LODWORD(lens_flares_parameters.x) = v67;
    *(_QWORD *)&lens_flares_parameters.elements[2] = 0;
    *(_QWORD *)&this->kernel_offsets[5].x = *(_QWORD *)&lens_flares_parameters.x;
    lens_flares_parameters.x = 0.0;
    lens_flares_parameters.y = -v69;
    *(_QWORD *)&this->kernel_offsets[5].elements[2] = *(_QWORD *)&lens_flares_parameters.elements[2];
    *(_QWORD *)&lens_flares_parameters.elements[2] = 0;
    *(_QWORD *)&this->kernel_offsets[6].x = *(_QWORD *)&lens_flares_parameters.x;
    v77 = *(_QWORD *)&lens_flares_parameters.elements[2];
    lens_flares_parameters.x = 0.0;
    lens_flares_parameters.w = 0.0;
    *(_QWORD *)&lens_flares_parameters.elements[1] = LODWORD(v69);
    *(_QWORD *)&this->kernel_offsets[7].x = *(_QWORD *)&lens_flares_parameters.x;
    v78 = *(_QWORD *)&lens_flares_parameters.elements[2];
    *(_QWORD *)&this->kernel_offsets[3].elements[2] = v76;
    *(_QWORD *)&this->kernel_offsets[6].elements[2] = v77;
    *(_QWORD *)&this->kernel_offsets[7].elements[2] = v78;
    vostok::render::backend::flush_rt_views(v65);
    m_targets = this->m_context->m_targets;
    bokeh_dof_density.m_object = 0;
    v80 = m_targets->m_family[30].target.m_object;
    if ( v80 )
    {
      bokeh_dof_density.m_object = v80;
      ++v80->m_reference_count;
    }
    vostok::render::stage_postprocess::clear_surface(
      (vostok::render::stage_postprocess *)&bokeh_dof_density,
      bokeh_dof_density);
    v81 = this->m_context->m_targets;
    bokeh_dof_density.m_object = 0;
    v82 = v81->m_family[31].target.m_object;
    if ( v82 )
    {
      bokeh_dof_density.m_object = v82;
      ++v82->m_reference_count;
    }
    vostok::render::stage_postprocess::clear_surface(
      (vostok::render::stage_postprocess *)&bokeh_dof_density,
      bokeh_dof_density);
    v83 = this->m_context->m_targets;
    bokeh_dof_density.m_object = 0;
    v84 = v83->m_family[32].target.m_object;
    if ( v84 )
    {
      bokeh_dof_density.m_object = v84;
      ++v84->m_reference_count;
    }
    vostok::render::stage_postprocess::clear_surface(
      (vostok::render::stage_postprocess *)&bokeh_dof_density,
      bokeh_dof_density);
    v85 = this->m_context->m_targets;
    bokeh_dof_density.m_object = 0;
    v86 = v85->m_family[33].target.m_object;
    if ( v86 )
    {
      bokeh_dof_density.m_object = v86;
      ++v86->m_reference_count;
    }
    vostok::render::stage_postprocess::clear_surface(
      (vostok::render::stage_postprocess *)&bokeh_dof_density,
      bokeh_dof_density);
    vostok::render::stage_postprocess::compute_luminance_parameters(v87, this, (unsigned int)&frame_luminance_parameter);
    if ( s_debug_pp_2 && v37->enable_bloom )
    {
      vostok::render::res_effect::apply(0, &this->m_sh_gather_bloom.m_object->__vftable);
      vostok::render::dof_shader_constants::set(
        &v37->dof_height_lights,
        &this->m_dof_shader_constants,
        COERCE_UNSIGNED_INT(v37->dof_focus_distance),
        COERCE_UNSIGNED_INT(v37->dof_focus_region),
        v37->dof_focus_power,
        COERCE_UNSIGNED_INT(v37->dof_near_blur_amount),
        COERCE_UNSIGNED_INT(v37->dof_far_blur_amount),
        COERCE_UNSIGNED_INT(v37->bokeh_dof_radius),
        COERCE_UNSIGNED_INT(v37->bokeh_dof_density));
      v88 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::constants_handler<1>::set_constant_array<vostok::math::float4>(
        (vostok::render::constants_handler<1> *)this->m_kernel_offsets,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        this->kernel_offsets,
        (unsigned int)v289[0]);
      ++*((_DWORD *)v88 + 23);
      vostok::render::bloom_shader_constants::set(
        &this->m_bloom_shader_constants,
        v37->bloom_scale,
        &this->m_bloom_shader_constants,
        COERCE_UNSIGNED_INT(v37->bloom_max_color),
        &v37->bloom_halo_color);
      m_frame_luminance_parameter = this->m_frame_luminance_parameter;
      v90 = *((_DWORD *)v88 + 573);
      if ( m_frame_luminance_parameter->m_update_markers[1] == v90 )
      {
        v90 = m_frame_luminance_parameter->m_shader_slots[1].m_buffer_index;
        if ( (unsigned __int16)v90 != 0xFFFF )
        {
          v91 = *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v88 + 371) + 16)
                                                           + 4 * (unsigned __int16)v90);
          v92 = m_frame_luminance_parameter->m_shader_slots[1].m_class_id;
          v93 = m_frame_luminance_parameter->m_shader_slots[1].m_slot_index;
          bloom_kernal = (unsigned __int8)v92;
          vostok::render::shader_constant_buffer::set_memory(
            v93,
            (unsigned __int8)v92,
            v91,
            (const char *)&frame_luminance_parameter);
        }
      }
      ++*((_DWORD *)v88 + 23);
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)0x20,
        &bokeh_dof_density,
        this->m_context,
        v90);
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)0x1E,
        &bokeh_dof_radius,
        this->m_context,
        v94);
      vostok::render::stage_postprocess::fill_surface(v95, this, bokeh_dof_radius, bokeh_dof_density);
    }
    if ( s_debug_pp_3 )
    {
      dof_blur_kernel = v37->dof_blur_kernel;
      if ( dof_blur_kernel )
      {
        dof_kernel_index = dof_blur_kernel;
        if ( dof_blur_kernel > 7 )
          dof_kernel_index = 7;
      }
      else
      {
        dof_kernel_index = 0;
      }
      bloom_kernal = supported_kernels[dof_kernel_index];
      v97 = bloom_kernal;
      v98 = alloca(4 * bloom_kernal);
      out_weights = (float *)v289;
      v99 = alloca(4 * bloom_kernal);
      out_offsets = (float *)v289;
      v100 = alloca(4 * bloom_kernal);
      v308 = (float *)v289;
      v101 = alloca(4 * bloom_kernal);
      v102 = (float *)v289;
      v301 = (float *)v289;
      dof_radius = (double)(bloom_kernal - 1) * 0.5;
      s_u.m_object = (vostok::render::res_texture *)(HIWORD(i) | 0xC00);
      *(_QWORD *)buffer_size = (__int64)*(float *)&t_w.m_object;
      vostok::render::get_gaussain_weights_offsets(
        buffer_size[0],
        COERCE_FLOAT(v289),
        (float *)v289,
        (float *)v289,
        bloom_kernal,
        dof_radius);
      s_u.m_object = (vostok::render::res_texture *)(HIWORD(i) | 0xC00);
      *(_QWORD *)buffer_size = (__int64)*(float *)&t_h.m_object;
      vostok::render::get_gaussain_weights_offsets(
        buffer_size[0],
        COERCE_FLOAT(v289),
        v308,
        (float *)v289,
        v97,
        dof_radius);
      v103 = alloca(16 * v97);
      kernel_index = (unsigned int)v289;
      i = 0;
      if ( v97 >= 4 )
      {
        LODWORD(dof_radius) = out_offsets + 3;
        v104 = (float *)&v290;
        v297 = (char *)((char *)out_offsets - (char *)out_weights);
        v296 = (char *)v301 - (char *)out_weights;
        v295 = (char *)v308 - (char *)out_weights;
        v105 = out_weights + 1;
        LODWORD(bloom_radius) = (char *)out_offsets - (char *)v301;
        s_u.m_object = (vostok::render::res_texture *)((char *)v308 - (char *)v301);
        p_y = &result.j.y;
        buffer_size[1] = (char *)v308 - (char *)out_offsets;
        v107 = i;
        do
        {
          lens_flares_parameters.x = *(float *)(LODWORD(dof_radius) - 12);
          lens_flares_parameters.y = *(v105 - 1);
          lens_flares_parameters.z = *(v104 - 2);
          v108 = v308[v107];
          v109 = v297;
          lens_flares_parameters.w = v108;
          *((vostok::math::float4 *)p_y - 2) = lens_flares_parameters;
          lens_flares_parameters.x = *(float *)((char *)v105 + (_DWORD)v109);
          v110 = dof_radius;
          lens_flares_parameters.y = *v105;
          lens_flares_parameters.z = *(float *)((char *)v105 + v296);
          v111 = bloom_radius;
          lens_flares_parameters.w = *(float *)((char *)v105 + v295);
          *((vostok::math::float4 *)p_y - 1) = lens_flares_parameters;
          lens_flares_parameters.x = *(float *)((char *)v104 + LODWORD(v111));
          lens_flares_parameters.y = v105[1];
          lens_flares_parameters.z = *v104;
          v112 = buffer_size[1];
          lens_flares_parameters.w = *(float *)((char *)&s_u.m_object->__vftable + (unsigned int)v104);
          *(vostok::math::float4 *)p_y = lens_flares_parameters;
          v113 = *(float *)(v112 + LODWORD(v110));
          v114 = *(_DWORD *)LODWORD(v110);
          v115 = *((_DWORD *)v105 + 2);
          v116 = v104[1];
          v117 = i;
          lens_flares_parameters.w = v113;
          *(_QWORD *)&lens_flares_parameters.x = __PAIR64__(v115, v114);
          *((_QWORD *)p_y + 2) = __PAIR64__(v115, v114);
          LODWORD(dof_radius) = LODWORD(v110) + 16;
          v118 = bloom_kernal;
          lens_flares_parameters.z = v116;
          v107 = v117 + 4;
          *((_QWORD *)p_y + 3) = *(_QWORD *)&lens_flares_parameters.elements[2];
          v105 += 4;
          v104 += 4;
          p_y += 16;
          i = v107;
        }
        while ( v107 < v118 - 3 );
        v102 = v301;
        v97 = bloom_kernal;
      }
      if ( i < v97 )
      {
        s_u.m_object = (vostok::render::res_texture *)((char *)v308 - (char *)v102);
        buffer_size[1] = (char *)out_weights - (char *)v102;
        v119 = (_QWORD *)(kernel_index + 16 * i);
        v120 = (char *)((char *)out_offsets - (char *)v102);
        v121 = v97 - i;
        v122 = &v102[i];
        do
        {
          v123 = *(_DWORD *)&v120[(_DWORD)v122];
          v124 = *(_DWORD *)((char *)v122 + buffer_size[1]);
          v125 = *v122;
          lens_flares_parameters.w = *(float *)((char *)v122 + (unsigned int)s_u.m_object);
          *(_QWORD *)&lens_flares_parameters.x = __PAIR64__(v124, v123);
          *v119 = __PAIR64__(v124, v123);
          lens_flares_parameters.z = v125;
          v119[1] = *(_QWORD *)&lens_flares_parameters.elements[2];
          ++v122;
          v119 += 2;
          --v121;
        }
        while ( v121 );
      }
      v126 = this->m_sh_blur[dof_kernel_index].m_object;
      v127 = v126->m_techniques._M_impl._M_finish - v126->m_techniques._M_impl._M_start;
      if ( v127 )
      {
        v126->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v127, (unsigned int)v289[0]);
      }
      v128 = this->m_context->m_targets->m_family[30].texture.m_object;
      v129 = 0;
      if ( v128 )
      {
        v129 = this->m_context->m_targets->m_family[30].texture.m_object;
        ++v128->m_reference_count;
      }
      M_start = this->m_textures.m_container._M_impl._M_start;
      v131 = 0;
      if ( v129 )
      {
        ++v129->m_reference_count;
        v131 = v129;
      }
      v132 = M_start->m_object;
      M_start->m_object = v131;
      if ( v132 )
      {
        if ( !--v132->m_reference_count )
          vostok::render::res_texture::destroy_impl(v131, v132);
      }
      if ( v129 )
      {
        if ( !--v129->m_reference_count )
          vostok::render::res_texture::destroy_impl(v131, v129);
      }
      v133 = this->m_context->m_targets->m_family[30].texture.m_object;
      v134 = 0;
      if ( v133 )
      {
        v134 = this->m_context->m_targets->m_family[30].texture.m_object;
        ++v133->m_reference_count;
      }
      v135 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v135 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                 (vostok::render::textures_handler<0> *)v131,
                                 (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                               + 1488,
                                 (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                                 v134);
      if ( v134 )
      {
        if ( !--v134->m_reference_count )
          vostok::render::res_texture::destroy_impl(v136, v134);
      }
      v137 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::constants_handler<1>::set_constant_array<vostok::math::float4>(
        (vostok::render::constants_handler<1> *)this->m_blur_offsets_weights,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        (const vostok::math::float4 *)kernel_index,
        (unsigned int)v289[0]);
      bokeh_dof_density.m_object = v138;
      ++*((_DWORD *)v137 + 23);
      bokeh_dof_density.m_object = 0;
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)0x1F,
        &bokeh_dof_radius,
        this->m_context,
        (vostok::render::enum_render_target_index)v138);
      vostok::render::stage_postprocess::fill_surface(v139, this, bokeh_dof_radius, bokeh_dof_density);
      vostok::render::backend::flush_rt_shader_resources(
        v140,
        (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
      vostok::render::res_effect::apply(
        (vostok::render::res_effect *)1,
        &this->m_sh_blur[dof_kernel_index].m_object->__vftable);
      v141 = this->m_context->m_targets->m_family[31].texture.m_object;
      v142 = 0;
      *(float *)&bloom_kernal = 0.0;
      if ( *(float *)&v141 != 0.0 )
      {
        v142 = v141;
        ++v141->m_reference_count;
        bloom_kernal = (unsigned int)v141;
      }
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&bloom_kernal,
        &this->m_textures.m_container._M_impl._M_start[1].m_object);
      if ( v142 )
      {
        if ( !--v142->m_reference_count )
          vostok::render::res_texture::destroy_impl(v143, v142);
      }
      v144 = this->m_context->m_targets->m_family[31].texture.m_object;
      v145 = 0;
      if ( v144 )
      {
        v145 = this->m_context->m_targets->m_family[31].texture.m_object;
        ++v144->m_reference_count;
      }
      v146 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)v146 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                 (vostok::render::textures_handler<0> *)v143,
                                 (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                               + 1488,
                                 (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                                 v145);
      if ( v145 )
      {
        if ( !--v145->m_reference_count )
          vostok::render::res_texture::destroy_impl(v147, v145);
      }
      v148 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      vostok::render::constants_handler<1>::set_constant_array<vostok::math::float4>(
        (vostok::render::constants_handler<1> *)this->m_blur_offsets_weights,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        (const vostok::math::float4 *)kernel_index,
        (unsigned int)v289[0]);
      ++*((_DWORD *)v148 + 23);
      bokeh_dof_density.m_object = 0;
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)0x1E,
        &bokeh_dof_radius,
        this->m_context,
        v149);
      vostok::render::stage_postprocess::fill_surface(v150, this, bokeh_dof_radius, bokeh_dof_density);
      v37 = pp_parameters;
    }
    if ( (_S7_3 & 1) == 0 )
    {
      _S7_3 |= 1u;
      randomizer_65.m_seed = 1000;
    }
    if ( !(LODWORD(this->m_context->m_scene_view.m_object[4].m_current_satisfaction_update_tick)
         % v37->image_grain_update_frequency) )
    {
      *(float *)&buffer_size[1] = vostok::math::random32::random_f(&randomizer_65, 1.0);
      v298 = vostok::math::random32::random_f(&randomizer_65, 1.0);
      bloom_radius = *(float *)&buffer_size[1];
      this->m_image_grain_random_offsets.x = v298;
      this->m_image_grain_random_offsets.y = bloom_radius;
    }
    vignette_power = v37->vignette_power;
    image_grain_scale = v37->image_grain_scale;
    y = this->m_image_grain_random_offsets.y;
    image_grain_parameters.x = this->m_image_grain_random_offsets.x;
    *(_QWORD *)&image_grain_parameters.elements[1] = __PAIR64__(LODWORD(image_grain_scale), LODWORD(y));
    image_grain_parameters.w = vignette_power;
    if ( !s_debug_pp_4 )
    {
LABEL_154:
      if ( s_debug_pp_5 && v37->use_dynamic_lens_flares )
      {
        vostok::render::backend::flush_rt_shader_resources(
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
        vostok::render::res_effect::apply(0, &this->m_lens_flares_effect.m_object->__vftable);
        if ( v37->lens_flares_mask_texture.m_object )
        {
          bokeh_dof_density.m_object = (vostok::render::render_target *)v37->lens_flares_mask_texture.m_object;
          v209 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          *((_BYTE *)v209 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                     (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                           + 1488),
                                     (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                   + 1488,
                                     (vostok::render::res_texture *)&stru_9656C8.m_desc.Usage,
                                     (vostok::render::res_texture *)bokeh_dof_density.m_object);
        }
        v210 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        lens_flares_multiplier = v37->lens_flares_multiplier;
        bokeh_dof_density.m_object = (vostok::render::render_target *)&lens_flares_parameters;
        *(_QWORD *)&lens_flares_parameters.x = LODWORD(lens_flares_multiplier);
        bokeh_dof_radius.m_object = (vostok::render::render_target *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                    + 1476);
        m_lens_flares_parameters = this->m_lens_flares_parameters;
        *(_QWORD *)&lens_flares_parameters.elements[2] = 0;
        vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
          m_lens_flares_parameters,
          (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
        + 123,
          (const vostok::math::float3 *)&lens_flares_parameters);
        ++*((_DWORD *)v210 + 23);
        vostok::render::renderer_context::get_rt(
          (vostok::render::renderer_context *)0x2C,
          &bokeh_dof_density,
          this->m_context,
          v213);
        vostok::render::stage_postprocess::fill_surface2(v214, this, bokeh_dof_density);
      }
      else
      {
        p_target = &this->m_context->m_targets->m_family[44].target;
        bokeh_dof_density.m_object = 0;
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
          &bokeh_dof_density,
          p_target);
        vostok::render::stage_postprocess::clear_surface(v217, bokeh_dof_density);
        v37 = pp_parameters;
      }
      if ( !s_debug_pp_6 )
      {
LABEL_176:
        if ( s_debug_pp_7 )
        {
          v229 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
          if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                + 269) )
            goto LABEL_184;
          if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                + 293) )
          {
            vostok::render::backend::flush_rt_shader_resources(
              v215,
              (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
            vostok::render::res_effect::apply(0, &this->m_post_process_antialiasing_shader_fxaa.m_object->__vftable);
            m_fxaa_parameters = this->m_fxaa_parameters;
            *(_QWORD *)&image_grain_parameters.x = *(_QWORD *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                                                             + 17);
            *(_QWORD *)&image_grain_parameters.elements[2] = *((unsigned int *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                                                             + 19);
            vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
              (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
              (const vostok::math::float3 *)&image_grain_parameters,
              m_fxaa_parameters);
            vostok::render::renderer_context::get_rt(
              (vostok::render::renderer_context *)0x2F,
              &bokeh_dof_density,
              this->m_context,
              v231);
            vostok::render::stage_postprocess::fill_surface2(v232, this, bokeh_dof_density);
            v229 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
          }
          if ( *((_BYTE *)v229 + 269) && *((_BYTE *)v229 + 272) && !*((_BYTE *)v229 + 293) )
          {
            vostok::render::backend::flush_rt_shader_resources(
              v215,
              (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
            vostok::render::res_effect::apply(0, &this->m_post_process_shader_sharpen.m_object->__vftable);
            vostok::render::renderer_context::get_rt(
              (vostok::render::renderer_context *)0x30,
              &bokeh_dof_density,
              this->m_context,
              v233);
            vostok::render::stage_postprocess::fill_surface2(v234, this, bokeh_dof_density);
            vostok::render::res_effect::apply(
              (vostok::render::res_effect *)1,
              &this->m_post_process_shader_sharpen.m_object->__vftable);
            vostok::render::renderer_context::get_rt(
              (vostok::render::renderer_context *)0x2D,
              &bokeh_dof_density,
              this->m_context,
              v235);
            vostok::render::stage_postprocess::fill_surface2(v236, this, bokeh_dof_density);
          }
          else
          {
LABEL_184:
            vostok::render::res_effect::apply(0, &this->m_sh_effect_copy_image.m_object->__vftable);
            if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                  + 269)
              || *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                 + 293) )
            {
              bokeh_dof_density.m_object = (vostok::render::render_target *)vostok::render::renderer_context::get_t(
                                                                              (vostok::render::renderer_context *)0x30,
                                                                              &t_h,
                                                                              this->m_context,
                                                                              (vostok::render::enum_render_target_index)v289[0])->m_object;
              v237 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
              *((_BYTE *)v237 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                         (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                               + 1488),
                                         (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                       + 1488,
                                         (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                                         (vostok::render::res_texture *)bokeh_dof_density.m_object);
              if ( *(float *)&t_h.m_object != 0.0 )
              {
                v15 = t_h.m_object->m_reference_count-- == 1;
                if ( v15 )
                  vostok::render::res_texture::destroy_impl(v238, t_h.m_object);
              }
            }
            else
            {
              vostok::render::renderer_context::get_t(
                (vostok::render::renderer_context *)0x2F,
                (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&buffer_size[1],
                this->m_context,
                (vostok::render::enum_render_target_index)v289[0]);
              vostok::render::backend::set_ps_texture(
                (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                (vostok::render::textures_handler<0> *)&stru_963F84.m_name.m_string.m_buffer[116]);
              vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&buffer_size[1]);
            }
            v239 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
              this->m_gamma_correction_factor,
              (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
            + 123,
              (const vostok::math::float3 *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
            + 8);
            ++*((_DWORD *)v239 + 23);
            bokeh_dof_density.m_object = 0;
            vostok::render::renderer_context::get_rt(
              (vostok::render::renderer_context *)0x2D,
              &bokeh_dof_radius,
              this->m_context,
              v240);
            vostok::render::stage_postprocess::fill_surface(v241, this, bokeh_dof_radius, bokeh_dof_density);
          }
        }
        bloom_kernal = (unsigned int)this->m_context->m_eye_rays;
        if ( s_debug_pp_8 )
        {
          vostok::render::res_effect::apply(0, &this->m_olta_effect.m_object->__vftable);
          vostok::render::renderer_context::get_rt(
            (vostok::render::renderer_context *)0xC,
            &bokeh_dof_density,
            this->m_context,
            v242);
          vostok::render::stage_postprocess::fill_surface2(v243, this, bokeh_dof_density);
          vostok::render::backend::flush_rt_shader_resources(
            v244,
            (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
          vostok::render::res_effect::apply((vostok::render::res_effect *)1, &this->m_olta_effect.m_object->__vftable);
          vostok::render::renderer_context::get_rt(
            (vostok::render::renderer_context *)0x2D,
            &bokeh_dof_density,
            this->m_context,
            v245);
          vostok::render::stage_postprocess::fill_surface2(v246, this, bokeh_dof_density);
        }
        v247 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
        if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
             + 293) )
        {
          v248 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
          bokeh_dof_density.m_object = (vostok::render::render_target *)&this->m_context->m_targets->m_family[45].texture;
          *(float *)&s_u.m_object = 0.0;
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)bokeh_dof_density.m_object,
            &s_u.m_object,
            (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)bokeh_dof_density.m_object);
          m_surface = s_u.m_object->m_surface;
          t = vostok::render::renderer_context::get_t(
                (vostok::render::renderer_context *)0xC,
                &t_h,
                this->m_context,
                (vostok::render::enum_render_target_index)v289[0]);
          (*(void (__stdcall **)(int, ID3D11Resource *, ID3D11Resource *))(*(_DWORD *)v248 + 188))(
            v248,
            t->m_object->m_surface,
            m_surface);
          if ( *(float *)&t_h.m_object != 0.0 )
          {
            v15 = t_h.m_object->m_reference_count-- == 1;
            if ( v15 )
              vostok::render::res_texture::destroy_impl(v251, t_h.m_object);
          }
          v252 = s_u.m_object;
          v15 = s_u.m_object->m_reference_count-- == 1;
          if ( v15 )
            vostok::render::res_texture::destroy_impl(v251, v252);
          vostok::render::res_effect::apply(0, &this->m_temporal_antialiasing_effect.m_object->__vftable);
          v253 = (vostok::render::render_target *)vostok::math::transpose(&result, &this->m_prev_view_matrix);
          v254 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          bokeh_dof_density.m_object = v253;
          v255 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                        + 1476);
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            this->m_prev_view_matrix_parameter,
            (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
          + 123,
            (const vostok::math::float3 *)v253);
          v256 = (const vostok::math::float3 *)bloom_kernal;
          ++*((_DWORD *)v254 + 23);
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            this->m_c_eye_ray_corner,
            v255,
            v256);
          ++*((_DWORD *)v254 + 23);
          m_c_frame_index = this->m_c_frame_index;
          buffer_size[1] = this->m_context->m_scene_view.m_object[4].m_current_satisfaction_update_tick & 1;
          vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
            m_c_frame_index,
            v255,
            (const vostok::math::float3 *)&buffer_size[1]);
          ++*((_DWORD *)v254 + 23);
          vostok::render::renderer_context::get_rt(
            (vostok::render::renderer_context *)0x2D,
            &bokeh_dof_density,
            this->m_context,
            v258);
          vostok::render::stage_postprocess::fill_surface2(v259, this, bokeh_dof_density);
          v260 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
          v261 = vostok::render::renderer_context::get_t(
                   (vostok::render::renderer_context *)0xC,
                   &t_w,
                   this->m_context,
                   (vostok::render::enum_render_target_index)v289[0])->m_object->m_surface;
          v262 = vostok::render::renderer_context::get_t(
                   (vostok::render::renderer_context *)0x2E,
                   &t_h,
                   this->m_context,
                   (vostok::render::enum_render_target_index)v289[0]);
          (*(void (__stdcall **)(int, ID3D11Resource *, ID3D11Resource *))(*(_DWORD *)v260 + 188))(
            v260,
            v262->m_object->m_surface,
            v261);
          if ( *(float *)&t_h.m_object != 0.0 )
          {
            v15 = t_h.m_object->m_reference_count-- == 1;
            if ( v15 )
              vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v215, t_h.m_object);
          }
          if ( *(float *)&t_w.m_object != 0.0 )
          {
            v15 = t_w.m_object->m_reference_count-- == 1;
            if ( v15 )
              vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v215, t_w.m_object);
          }
          v247 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
        }
        if ( !*((_BYTE *)v247 + 294) )
        {
          if ( !*((_BYTE *)v247 + 303) )
            goto LABEL_212;
          if ( !*((_BYTE *)v247 + 293) )
          {
LABEL_213:
            if ( !*((_DWORD *)v247 + 50) )
            {
LABEL_230:
              qmemcpy((void *)&this->m_prev_view_matrix, &this->m_context->m_v, sizeof(this->m_prev_view_matrix));
              v285 = vostok::math::float4x4::identity(&result);
              vostok::render::renderer_context::set_w(this->m_context, v285);
              return;
            }
LABEL_214:
            if ( *((_BYTE *)v247 + 294) )
            {
              vostok::render::backend::flush_rt_shader_resources(
                v215,
                (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
              vostok::render::res_effect::apply(0, &this->m_motion_blur_effect.m_object->__vftable);
              v264 = (vostok::render::render_target *)vostok::math::transpose(&result, &this->m_prev_view_matrix);
              v265 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
              bokeh_dof_density.m_object = v264;
              v266 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                            + 1476);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                this->m_prev_view_matrix_parameter,
                (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
              + 123,
                (const vostok::math::float3 *)v264);
              v267 = (const vostok::math::float3 *)bloom_kernal;
              ++*((_DWORD *)v265 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                this->m_c_eye_ray_corner,
                v266,
                v267);
              ++*((_DWORD *)v265 + 23);
              m_frame_delta_parameter = this->m_frame_delta_parameter;
              buffer_size[1] = LODWORD(this->m_context->m_time_delta);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                m_frame_delta_parameter,
                v266,
                (const vostok::math::float3 *)&buffer_size[1]);
              v269 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
              ++*((_DWORD *)v265 + 23);
              vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                this->m_motion_blur_scale_parameter,
                v266,
                (const vostok::math::float3 *)(v269 + 23));
              ++*((_DWORD *)v265 + 23);
              vostok::render::renderer_context::get_rt(
                (vostok::render::renderer_context *)0xC,
                &bokeh_dof_density,
                this->m_context,
                v270);
              vostok::render::stage_postprocess::fill_surface2(v271, this, bokeh_dof_density);
              v272 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
              v273 = vostok::render::renderer_context::get_t(
                       (vostok::render::renderer_context *)0xC,
                       &s_u,
                       this->m_context,
                       (vostok::render::enum_render_target_index)v289[0])->m_object->m_surface;
              v274 = vostok::render::renderer_context::get_t(
                       (vostok::render::renderer_context *)0x2D,
                       (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&bloom_kernal,
                       this->m_context,
                       (vostok::render::enum_render_target_index)v289[0]);
              (*(void (__stdcall **)(int, ID3D11Resource *, ID3D11Resource *))(*(_DWORD *)v272 + 188))(
                v272,
                v274->m_object->m_surface,
                v273);
              if ( *(float *)&bloom_kernal != 0.0 )
              {
                v15 = (*(_DWORD *)(bloom_kernal + 4))-- == 1;
                if ( v15 )
                  vostok::render::res_texture::destroy_impl(v275, (const vostok::render::res_texture *)bloom_kernal);
              }
              if ( *(float *)&s_u.m_object != 0.0 )
              {
                v15 = s_u.m_object->m_reference_count-- == 1;
                if ( v15 )
                  vostok::render::res_texture::destroy_impl(v275, s_u.m_object);
              }
              v247 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
            }
            if ( *((_DWORD *)v247 + 50) )
            {
              v276 = pp_parameters;
              if ( pp_parameters->use_aberration )
              {
                vostok::render::res_effect::apply(0, &this->m_aberration_effect.m_object->__vftable);
                *(_QWORD *)&image_grain_parameters.x = *(_QWORD *)&v276->aberration_max_variance;
                aberration_power = v276->aberration_power;
                v278 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
                *(_QWORD *)&image_grain_parameters.elements[2] = LODWORD(aberration_power);
                vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
                  this->m_aberration_parameters,
                  (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                + 123,
                  (const vostok::math::float3 *)&image_grain_parameters);
                ++*((_DWORD *)v278 + 23);
                vostok::render::renderer_context::get_rt(
                  (vostok::render::renderer_context *)0xC,
                  &bokeh_dof_density,
                  this->m_context,
                  v279);
                vostok::render::stage_postprocess::fill_surface2(v280, this, bokeh_dof_density);
                v281 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
                v282 = vostok::render::renderer_context::get_t(
                         (vostok::render::renderer_context *)0xC,
                         &t_w,
                         this->m_context,
                         (vostok::render::enum_render_target_index)v289[0])->m_object->m_surface;
                v283 = vostok::render::renderer_context::get_t(
                         (vostok::render::renderer_context *)0x2D,
                         &t_h,
                         this->m_context,
                         (vostok::render::enum_render_target_index)v289[0]);
                (*(void (__stdcall **)(int, ID3D11Resource *, ID3D11Resource *))(*(_DWORD *)v281 + 188))(
                  v281,
                  v283->m_object->m_surface,
                  v282);
                if ( *(float *)&t_h.m_object != 0.0 )
                {
                  v15 = t_h.m_object->m_reference_count-- == 1;
                  if ( v15 )
                    vostok::render::res_texture::destroy_impl(v284, t_h.m_object);
                }
                if ( *(float *)&t_w.m_object != 0.0 )
                {
                  v15 = t_w.m_object->m_reference_count-- == 1;
                  if ( v15 )
                    vostok::render::res_texture::destroy_impl(v284, t_w.m_object);
                }
              }
            }
            goto LABEL_230;
          }
        }
        if ( *((_BYTE *)v247 + 293) || *((_DWORD *)v247 + 50) )
        {
          vostok::render::backend::flush_rt_shader_resources(
            v215,
            (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
          vostok::render::stage_postprocess::accumulate_motion_vectors(v263, this);
          v247 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
        }
LABEL_212:
        if ( *((_BYTE *)v247 + 293) )
          goto LABEL_214;
        goto LABEL_213;
      }
      use_image_grain = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                        + 50);
      if ( use_image_grain )
      {
        use_bokeh_dof = v37->use_bokeh_dof;
        if ( v37->use_bokeh_dof )
        {
          use_bokeh_image = v37->use_bokeh_image;
          goto LABEL_164;
        }
      }
      else
      {
        use_bokeh_dof = 0;
      }
      use_bokeh_image = 0;
LABEL_164:
      if ( use_image_grain )
        use_image_grain = v37->use_image_grain;
      vostok::render::res_effect::apply(
        0,
        &this->m_sh_complex_blend[use_bokeh_dof][use_bokeh_image][use_image_grain].m_object->__vftable);
      v221 = (vostok::render::post_process_parameters *)pp_parameters;
      vostok::render::dof_shader_constants::set(
        &pp_parameters->dof_height_lights,
        &this->m_dof_shader_constants,
        COERCE_UNSIGNED_INT(pp_parameters->dof_focus_distance),
        COERCE_UNSIGNED_INT(pp_parameters->dof_focus_region),
        pp_parameters->dof_focus_power,
        COERCE_UNSIGNED_INT(pp_parameters->dof_near_blur_amount),
        COERCE_UNSIGNED_INT(pp_parameters->dof_far_blur_amount),
        COERCE_UNSIGNED_INT(pp_parameters->bokeh_dof_radius),
        COERCE_UNSIGNED_INT(pp_parameters->bokeh_dof_density));
      frame_desaturation = v221->frame_desaturation;
      v223 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
      bokeh_dof_density.m_object = (vostok::render::render_target *)v221;
      bokeh_dof_radius.m_object = (vostok::render::render_target *)&image_grain_parameters;
      far_blur_amout = frame_desaturation;
      vostok::render::scene_shader_constants::set(
        &this->m_scene_shader_constants,
        &v221->frame_height_lights,
        &v221->frame_fade_color,
        &v221->frame_mid_tones,
        &v221->frame_shadows,
        COERCE_CONST_VOSTOK_MATH_FLOAT3_(v221->frame_fade_amount),
        *((float *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 24),
        far_blur_amout,
        (const vostok::math::float3 *)&image_grain_parameters,
        v221,
        v289[0]);
      if ( *((_DWORD *)v223 + 50) )
      {
        if ( pp_parameters->use_color_grading_lut
          && pp_parameters->color_grading_texture.m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          vostok::render::backend::set_ps_texture(
            (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
            (vostok::render::textures_handler<0> *)&stru_9656C8.m_desc.MiscFlags);
        }
        else
        {
          bokeh_dof_density.m_object = (vostok::render::render_target *)this->m_color_grading_base_lut.m_object;
          v224 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
          *((_BYTE *)v224 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                     (vostok::render::textures_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                           + 1488),
                                     (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                   + 1488,
                                     (vostok::render::res_texture *)&stru_9656C8.m_desc.MiscFlags,
                                     (vostok::render::res_texture *)bokeh_dof_density.m_object);
        }
      }
      v225 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      bokeh_dof_density.m_object = (vostok::render::render_target *)&sun_direction;
      v226 = (vostok::render::constants_handler<1> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                    + 1476);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        this->m_sun_direction_parameter,
        (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
      + 123,
        &sun_direction);
      ++*((_DWORD *)v225 + 23);
      vostok::render::constants_handler<1>::set_constant<vostok::math::float4x4>(
        this->m_frame_luminance_parameter,
        v226,
        (const vostok::math::float3 *)&frame_luminance_parameter);
      ++*((_DWORD *)v225 + 23);
      bokeh_dof_density.m_object = 0;
      vostok::render::renderer_context::get_rt(
        (vostok::render::renderer_context *)0x30,
        &bokeh_dof_radius,
        this->m_context,
        v227);
      vostok::render::stage_postprocess::fill_surface(v228, this, bokeh_dof_radius, bokeh_dof_density);
      goto LABEL_176;
    }
    if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 50)
      && v37->enable_advanced_bloom )
    {
      vostok::render::stage_postprocess::advanced_bloom(
        (vostok::render::stage_postprocess *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start,
        this);
      goto LABEL_154;
    }
    blur_kernel = v37->blur_kernel;
    if ( blur_kernel )
    {
      if ( blur_kernel <= 7 )
      {
        v155 = blur_kernel;
        kernel_index = blur_kernel;
LABEL_124:
        bloom_kernal = supported_kernels[v155];
        v156 = bloom_kernal;
        v157 = alloca(4 * bloom_kernal);
        v301 = (float *)v289;
        v158 = alloca(4 * bloom_kernal);
        dof_kernel_index = (unsigned int)v289;
        v159 = alloca(4 * bloom_kernal);
        v308 = (float *)v289;
        v160 = alloca(4 * bloom_kernal);
        v161 = (float *)v289;
        out_weights = (float *)v289;
        bloom_radius = (double)(bloom_kernal - 1) * 0.5;
        *(_QWORD *)buffer_size = (__int64)*(float *)&t_w.m_object;
        vostok::render::get_gaussain_weights_offsets(
          buffer_size[0],
          COERCE_FLOAT(v289),
          (float *)v289,
          (float *)v289,
          bloom_kernal,
          bloom_radius);
        *(_QWORD *)buffer_size = (__int64)*(float *)&t_h.m_object;
        vostok::render::get_gaussain_weights_offsets(
          buffer_size[0],
          COERCE_FLOAT(v289),
          v308,
          (float *)v289,
          v156,
          bloom_radius);
        v163 = alloca(16 * v156);
        v164 = v289;
        i = (unsigned int)v289;
        out_offsets = 0;
        if ( v156 >= 4 )
        {
          s_u.m_object = (vostok::render::res_texture *)(dof_kernel_index + 12);
          v165 = (float *)&v290;
          buffer_size[1] = dof_kernel_index - (_DWORD)v301;
          LODWORD(bloom_radius) = (char *)out_weights - (char *)v301;
          v295 = (char *)v308 - (char *)v301;
          v162 = v301 + 1;
          v296 = dof_kernel_index - (_DWORD)out_weights;
          LODWORD(dof_radius) = (char *)v308 - (char *)out_weights;
          v166 = &result.j.y;
          v297 = (char *)v308 - dof_kernel_index;
          v167 = out_offsets;
          do
          {
            LODWORD(lens_flares_parameters.x) = s_u.m_object[-1].m_mip_level_cut;
            lens_flares_parameters.y = *(v162 - 1);
            lens_flares_parameters.z = *(v165 - 2);
            v168 = v308[(_DWORD)v167];
            v169 = buffer_size[1];
            lens_flares_parameters.w = v168;
            *((vostok::math::float4 *)v166 - 2) = lens_flares_parameters;
            lens_flares_parameters.x = *(float *)((char *)v162 + v169);
            v170 = s_u.m_object;
            lens_flares_parameters.y = *v162;
            lens_flares_parameters.z = *(float *)((char *)v162 + LODWORD(bloom_radius));
            v171 = v296;
            lens_flares_parameters.w = *(float *)((char *)v162 + v295);
            *((vostok::math::float4 *)v166 - 1) = lens_flares_parameters;
            lens_flares_parameters.x = *(float *)((char *)v165 + v171);
            lens_flares_parameters.y = v162[1];
            lens_flares_parameters.z = *v165;
            v172 = v297;
            lens_flares_parameters.w = *(float *)((char *)v165 + LODWORD(dof_radius));
            *(vostok::math::float4 *)v166 = lens_flares_parameters;
            v173 = *(float *)&v172[(_DWORD)v170];
            v174 = v170->__vftable;
            v175 = *((_DWORD *)v162 + 2);
            v176 = v165[1];
            v177 = out_offsets;
            lens_flares_parameters.w = v173;
            *(_QWORD *)&lens_flares_parameters.x = __PAIR64__(v175, (unsigned int)v174);
            *((_QWORD *)v166 + 2) = __PAIR64__(v175, (unsigned int)v174);
            s_u.m_object = (vostok::render::res_texture *)&v170->m_rescale_min;
            v178 = bloom_kernal;
            lens_flares_parameters.z = v176;
            v167 = v177 + 1;
            *((_QWORD *)v166 + 3) = *(_QWORD *)&lens_flares_parameters.elements[2];
            v162 += 4;
            v165 += 4;
            v166 += 16;
            out_offsets = v167;
          }
          while ( (unsigned int)v167 < v178 - 3 );
          v161 = out_weights;
          v156 = bloom_kernal;
          v164 = (const vostok::render::post_process_parameters **)i;
        }
        if ( (unsigned int)out_offsets < v156 )
        {
          v162 = (float *)&v164[4 * (_DWORD)out_offsets];
          v179 = &v161[(_DWORD)out_offsets];
          LODWORD(dof_radius) = (char *)v308 - (char *)v161;
          buffer_size[1] = (char *)v301 - (char *)v161;
          v180 = dof_kernel_index - (_DWORD)v161;
          v181 = v156 - (_DWORD)out_offsets;
          do
          {
            v182 = *(_DWORD *)((char *)v179 + v180);
            v183 = *(_DWORD *)((char *)v179 + buffer_size[1]);
            v184 = *v179;
            lens_flares_parameters.w = *(float *)((char *)v179 + LODWORD(dof_radius));
            *(_QWORD *)&lens_flares_parameters.x = __PAIR64__(v183, v182);
            *(_QWORD *)v162 = __PAIR64__(v183, v182);
            lens_flares_parameters.z = v184;
            *((_QWORD *)v162 + 1) = *(_QWORD *)&lens_flares_parameters.elements[2];
            ++v179;
            v162 += 4;
            --v181;
          }
          while ( v181 );
        }
        vostok::render::backend::flush_rt_shader_resources(
          (vostok::render::backend *)v162,
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
        vostok::render::res_effect::apply(0, &this->m_sh_blur[kernel_index].m_object->__vftable);
        bokeh_dof_density.m_object = (vostok::render::render_target *)&this->m_context->m_targets->m_family[32].texture;
        *(float *)&t_h.m_object = 0.0;
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
          v185,
          &t_h.m_object,
          (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)bokeh_dof_density.m_object);
        v186 = t_h.m_object;
        v187 = this->m_textures.m_container._M_impl._M_start;
        v188 = 0;
        if ( *(float *)&t_h.m_object != 0.0 )
        {
          ++t_h.m_object->m_reference_count;
          v188 = v186;
        }
        v189 = v187->m_object;
        v187->m_object = v188;
        if ( v189 )
        {
          if ( !--v189->m_reference_count )
            vostok::render::res_texture::destroy_impl(v188, v189);
        }
        if ( v186 )
        {
          if ( !--v186->m_reference_count )
            vostok::render::res_texture::destroy_impl(v188, v186);
        }
        bokeh_dof_density.m_object = (vostok::render::render_target *)&this->m_context->m_targets->m_family[32].texture;
        *(float *)&t_h.m_object = 0.0;
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
          (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v188,
          &t_h.m_object,
          (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)bokeh_dof_density.m_object);
        v190 = t_h.m_object;
        v191 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        *((_BYTE *)v191 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                   v192,
                                   (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                 + 1488,
                                   (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                                   t_h.m_object);
        if ( v190 )
        {
          if ( !--v190->m_reference_count )
            vostok::render::res_texture::destroy_impl(v193, v190);
        }
        v194 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        vostok::render::constants_handler<1>::set_constant_array<vostok::math::float4>(
          (vostok::render::constants_handler<1> *)this->m_blur_offsets_weights,
          (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
        + 123,
          (const vostok::math::float4 *)i,
          (unsigned int)v289[0]);
        ++*((_DWORD *)v194 + 23);
        bokeh_dof_density.m_object = 0;
        v195 = &this->m_context->m_targets->m_family[31].target;
        bokeh_dof_radius.m_object = 0;
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
          &bokeh_dof_radius,
          v195);
        vostok::render::stage_postprocess::fill_surface(v196, this, bokeh_dof_radius, bokeh_dof_density);
        vostok::render::backend::flush_rt_shader_resources(
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name);
        vostok::render::res_effect::apply(
          (vostok::render::res_effect *)2,
          &this->m_sh_blur[kernel_index].m_object->__vftable);
        bokeh_dof_density.m_object = (vostok::render::render_target *)&this->m_context->m_targets->m_family[31].texture;
        *(float *)&t_h.m_object = 0.0;
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
          v197,
          &t_h.m_object,
          (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)bokeh_dof_density.m_object);
        v198 = t_h.m_object;
        v199 = this->m_textures.m_container._M_impl._M_start;
        v200 = 0;
        if ( *(float *)&t_h.m_object != 0.0 )
        {
          ++t_h.m_object->m_reference_count;
          v200 = v198;
        }
        v201 = v199[1].m_object;
        v199[1].m_object = v200;
        if ( v201 )
        {
          if ( !--v201->m_reference_count )
            vostok::render::res_texture::destroy_impl(v200, v201);
        }
        if ( v198 )
        {
          if ( !--v198->m_reference_count )
            vostok::render::res_texture::destroy_impl(v200, v198);
        }
        bokeh_dof_density.m_object = (vostok::render::render_target *)&this->m_context->m_targets->m_family[31].texture;
        *(float *)&t_h.m_object = 0.0;
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
          (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v200,
          &t_h.m_object,
          (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)bokeh_dof_density.m_object);
        v202 = t_h.m_object;
        v203 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        *((_BYTE *)v203 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                   v204,
                                   (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                 + 1488,
                                   (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                                   t_h.m_object);
        if ( v202 )
        {
          if ( !--v202->m_reference_count )
            vostok::render::res_texture::destroy_impl(v205, v202);
        }
        v206 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        vostok::render::constants_handler<1>::set_constant_array<vostok::math::float4>(
          (vostok::render::constants_handler<1> *)this->m_blur_offsets_weights,
          (vostok::render::constants_handler<1> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
        + 123,
          (const vostok::math::float4 *)i,
          (unsigned int)v289[0]);
        ++*((_DWORD *)v206 + 23);
        bokeh_dof_density.m_object = 0;
        v207 = &this->m_context->m_targets->m_family[33].target;
        bokeh_dof_radius.m_object = 0;
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
          &bokeh_dof_radius,
          v207);
        vostok::render::stage_postprocess::fill_surface(v208, this, bokeh_dof_radius, bokeh_dof_density);
        v37 = pp_parameters;
        goto LABEL_154;
      }
      v155 = 7;
    }
    else
    {
      v155 = 0;
    }
    kernel_index = v155;
    goto LABEL_124;
  }
  vostok::render::res_effect::apply(0, &this->m_sh_effect_copy_image.m_object->__vftable);
  v4 = this->m_context->m_targets->m_family[47].texture.m_object;
  v5 = 0;
  if ( v4 )
  {
    v5 = this->m_context->m_targets->m_family[47].texture.m_object;
    ++v4->m_reference_count;
  }
  v6 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v6 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                           v3,
                           (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                         + 1488,
                           (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                           v5);
  if ( v5 )
  {
    if ( !--v5->m_reference_count )
      vostok::render::res_texture::destroy_impl(v7, v5);
  }
  v8 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  m_gamma_correction_factor = this->m_gamma_correction_factor;
  v10 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 573);
  t_h.m_object = (vostok::render::res_texture *)clear_value;
  if ( m_gamma_correction_factor->m_update_markers[1] == v10 )
  {
    v11 = m_gamma_correction_factor->m_shader_slots[1].m_buffer_index;
    if ( v11 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_gamma_correction_factor->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_gamma_correction_factor->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * v11),
        (const char *)&t_h);
  }
  ++*((_DWORD *)v8 + 23);
  bokeh_dof_density.m_object = 0;
  v12 = this->m_context->m_targets;
  bokeh_dof_radius.m_object = 0;
  v13 = v12->m_family[45].target.m_object;
  if ( v13 )
  {
    bokeh_dof_radius.m_object = v13;
    ++v13->m_reference_count;
  }
  vostok::render::stage_postprocess::fill_surface(
    (vostok::render::stage_postprocess *)&bokeh_dof_radius,
    this,
    bokeh_dof_radius,
    bokeh_dof_density);
  v14 = vostok::math::float4x4::identity(&result);
  vostok::render::renderer_context::set_w(this->m_context, v14);
}
