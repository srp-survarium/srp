void __usercall vostok::render::stage_postprocess::execute(
        vostok::render::stage_postprocess *this@<ecx>,
        float y@<edi>)
{
  vostok::render::renderer_context *m_context; // esi
  vostok::render::options *v4; // eax
  vostok::render::backend *m_antialiasing_method; // ecx
  vostok::render::stage_postprocess *v6; // ecx
  vostok::render::stage_postprocess *v7; // ecx
  int v8; // ecx
  vostok::render::stage_postprocess *v9; // ecx
  vostok::render::base_scene_view *m_object; // eax
  pix_event_wrapper_dx11 *v11; // ecx
  bool v12; // zf
  vostok::render::res_effect *v13; // eax
  vostok::render::res_effect *v14; // ecx
  vostok::render::environment_properties *v15; // ecx
  vostok::math::float3 *sun_direction; // eax
  vostok::render::backend *v17; // ecx
  int v18; // ecx
  vostok::render::stage_postprocess *v19; // ecx
  vostok::render::res_effect *v20; // eax
  vostok::render::res_effect *v21; // ecx
  float z; // esi
  vostok::render::backend *v23; // ecx
  float v24; // xmm0_4
  float v25; // xmm1_4
  vostok::render::backend *v26; // ecx
  float v27; // xmm0_4
  float v28; // xmm1_4
  vostok::render::backend *v29; // ecx
  unsigned int v30; // xmm0_4
  vostok::render::backend *v31; // ecx
  int v32; // ecx
  vostok::render::stage_postprocess *v33; // ecx
  vostok::render::stage_postprocess *v34; // ecx
  vostok::math::float4 *v35; // eax
  float v36; // xmm0_4
  int *t; // eax
  vostok::render::res_texture *v38; // ecx
  int v39; // edi
  vostok::render::resource_manager *v40; // ecx
  _DWORD *v41; // eax
  float v42; // esi
  double v43; // st7
  unsigned int v44; // xmm2_4
  unsigned int v45; // xmm0_4
  float v46; // xmm3_4
  int v47; // ecx
  int v48; // ecx
  vostok::render::render_target *v49; // eax
  vostok::render::res_effect *v50; // ecx
  vostok::render::render_target *v51; // eax
  vostok::render::res_effect *v52; // eax
  vostok::render::backend *v53; // ecx
  unsigned int v54; // ecx
  vostok::render::stage_postprocess *v55; // ecx
  unsigned int v56; // esi
  int v57; // ecx
  int v58; // ecx
  vostok::render::stage_postprocess *v59; // ecx
  int v60; // ecx
  int v61; // ecx
  vostok::render::stage_postprocess *v62; // ecx
  vostok::render::res_effect *v63; // eax
  vostok::render::res_effect *v64; // ecx
  unsigned int v65; // ecx
  vostok::render::res_effect *v66; // eax
  vostok::render::res_effect *v67; // ecx
  vostok::render::backend *v68; // ecx
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_reconstruction_info_actuality_tick; // eax
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v70; // eax
  vostok::render::res_texture *v71; // eax
  unsigned int v72; // xmm0_4
  int v73; // ecx
  vostok::render::stage_postprocess *v74; // ecx
  pix_event_wrapper_dx11 *v75; // ecx
  vostok::render::res_effect *v76; // ecx
  int v77; // eax
  vostok::render::res_effect *v78; // eax
  float v79; // esi
  double v80; // st7
  vostok::render::backend *v81; // ecx
  vostok::render::backend *v82; // ecx
  float v83; // esi
  vostok::render::backend *v84; // ecx
  vostok::render::backend *v85; // ecx
  unsigned int v86; // ecx
  vostok::render::backend *v87; // ecx
  vostok::render::res_effect *v88; // eax
  vostok::render::res_effect *v89; // ecx
  float m_fxaa_quality_subpix; // xmm0_4
  float m_fxaa_quality_edge_threshold; // xmm1_4
  float m_fxaa_quality_edge_threshold_min; // xmm2_4
  vostok::render::backend *v93; // ecx
  int v94; // ecx
  vostok::render::stage_postprocess *v95; // ecx
  vostok::render::backend *v96; // ecx
  vostok::render::res_effect *v97; // eax
  vostok::render::res_effect *v98; // ecx
  int v99; // ecx
  vostok::render::stage_postprocess *v100; // ecx
  vostok::render::res_effect *v101; // eax
  vostok::render::res_effect *v102; // ecx
  int v103; // ecx
  vostok::render::stage_postprocess *v104; // ecx
  vostok::render::res_effect *v105; // eax
  vostok::render::res_effect *v106; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v107; // eax
  vostok::render::backend *v108; // ecx
  vostok::render::resource_manager *v109; // ecx
  _DWORD *v110; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v111; // eax
  vostok::render::backend *v112; // ecx
  vostok::shared_string *p_m_name; // eax
  unsigned int v114; // ecx
  vostok::render::renderer_context *v115; // ecx
  ID3D11DeviceContext *v116; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v117; // eax
  vostok::render::renderer_context *v118; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v119; // eax
  vostok::render::resource_manager *v120; // ecx
  _DWORD *v121; // eax
  vostok::render::resource_intrusive_base *v122; // eax
  vostok::render::res_effect *v123; // eax
  vostok::math::float4x4 *v124; // eax
  float v125; // esi
  vostok::render::backend *v126; // ecx
  vostok::render::backend *v127; // ecx
  int v128; // ecx
  vostok::render::stage_postprocess *v129; // ecx
  ID3D11DeviceContext *v130; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v131; // eax
  vostok::render::renderer_context *v132; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v133; // eax
  vostok::render::resource_intrusive_base *v134; // eax
  _DWORD *v135; // eax
  int v136; // ecx
  vostok::render::backend *v137; // ecx
  vostok::render::res_effect *v138; // ecx
  unsigned int m_motion_blur_quality; // eax
  unsigned int v140; // eax
  float v141; // xmm0_4
  vostok::render::res_effect *v142; // eax
  vostok::math::float4x4 *v143; // eax
  float v144; // esi
  vostok::render::backend *v145; // ecx
  vostok::render::backend *v146; // ecx
  float m_time_delta; // xmm0_4
  vostok::render::backend *v148; // ecx
  vostok::render::backend *v149; // ecx
  int v150; // ecx
  vostok::render::stage_postprocess *v151; // ecx
  vostok::render::res_effect *v152; // ecx
  vostok::render::res_effect *v153; // eax
  vostok::math::float4x4 *v154; // eax
  float v155; // esi
  vostok::render::backend *v156; // ecx
  vostok::render::backend *v157; // ecx
  float v158; // xmm0_4
  vostok::render::backend *v159; // ecx
  vostok::render::backend *v160; // ecx
  int v161; // ecx
  vostok::render::stage_postprocess *v162; // ecx
  vostok::render::res_effect *v163; // eax
  vostok::math::float4x4 *v164; // eax
  float v165; // esi
  vostok::render::backend *v166; // ecx
  vostok::render::backend *v167; // ecx
  float v168; // xmm0_4
  vostok::render::backend *v169; // ecx
  vostok::render::backend *v170; // ecx
  int v171; // ecx
  vostok::render::stage_postprocess *v172; // ecx
  vostok::render::res_effect *v173; // eax
  int v174; // ecx
  vostok::render::stage_postprocess *v175; // ecx
  float v176; // eax
  int v177; // esi
  vostok::render::res_effect *v178; // eax
  float v179; // esi
  vostok::render::backend *v180; // ecx
  vostok::render::backend *v181; // ecx
  vostok::render::system_renderer *v182; // esi
  vostok::render::system_renderer *v183; // ecx
  int v184; // esi
  int v185; // ecx
  vostok::render::res_effect *v186; // eax
  vostok::render::res_effect *v187; // ecx
  float v188; // esi
  vostok::render::backend *v189; // ecx
  vostok::render::backend *v190; // ecx
  vostok::render::backend *v191; // ecx
  vostok::render::system_renderer *v192; // esi
  vostok::render::system_renderer *v193; // ecx
  vostok::render::res_effect *v194; // eax
  vostok::render::res_effect *v195; // ecx
  vostok::render::system_renderer *v196; // esi
  vostok::render::system_renderer *v197; // ecx
  unsigned int m_post_process_quality; // esi
  pix_event_wrapper_dx11 v199; // al
  int v200; // ecx
  vostok::render::res_effect *v201; // ecx
  vostok::render::res_effect *v202; // eax
  float v203; // xmm0_4
  float v204; // esi
  unsigned int v205; // xmm1_4
  unsigned int v206; // xmm0_4
  vostok::render::backend *v207; // ecx
  vostok::render::backend *v208; // ecx
  int v209; // ecx
  vostok::render::stage_postprocess *v210; // ecx
  ID3D11DeviceContext *v211; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v212; // eax
  vostok::render::renderer_context *v213; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v214; // eax
  vostok::render::resource_manager *v215; // ecx
  vostok::math::float4x4 *p_m_v; // esi
  vostok::math::float4x4 *v217; // eax
  vostok::render::system_renderer *v218; // [esp-4h] [ebp-ECh]
  vostok::render::system_renderer *v219; // [esp-4h] [ebp-ECh]
  vostok::render::system_renderer *v220; // [esp-4h] [ebp-ECh]
  __int64 v221; // [esp+0h] [ebp-E8h] BYREF
  __int128 v222; // [esp+8h] [ebp-E0h] BYREF
  float v223; // [esp+18h] [ebp-D0h]
  const vostok::math::float4 *v224; // [esp+1Ch] [ebp-CCh]
  const vostok::render::environment_properties *v225; // [esp+20h] [ebp-C8h]
  float v226; // [esp+24h] [ebp-C4h]
  pix_event_wrapper_dx11 wszName[3]; // [esp+29h] [ebp-BFh] BYREF
  vostok::render::render_target *rt; // [esp+2Ch] [ebp-BCh] BYREF
  vostok::math::float3 arg; // [esp+30h] [ebp-B8h] BYREF
  char v230; // [esp+3Fh] [ebp-A9h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v231; // [esp+40h] [ebp-A8h] BYREF
  vostok::math::float3 v232; // [esp+44h] [ebp-A4h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v233; // [esp+50h] [ebp-98h] BYREF
  vostok::math::float3 v234; // [esp+54h] [ebp-94h] BYREF
  float v235; // [esp+60h] [ebp-88h]
  vostok::math::float3 v236; // [esp+64h] [ebp-84h] BYREF
  float v237; // [esp+70h] [ebp-78h]
  vostok::math::float3 v238; // [esp+74h] [ebp-74h] BYREF
  vostok::math::float3 v239; // [esp+80h] [ebp-68h] BYREF
  vostok::math::float3 v240; // [esp+8Ch] [ebp-5Ch] BYREF
  vostok::math::float3 v241; // [esp+98h] [ebp-50h] BYREF
  float w; // [esp+A4h] [ebp-44h]
  vostok::math::float4x4 v243; // [esp+A8h] [ebp-40h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, wszName, (int)L"stage_postprocess");
  if ( !this->is_effects_ready(this) )
    goto LABEL_134;
  if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_stage
    || !this->is_enabled(this)
    || (m_context = this->m_context, !byte_10E2C[(unsigned int)m_context->m_scene_view.m_object]) )
  {
    this->execute_disabled(this);
    goto LABEL_134;
  }
  v4 = vostok::quasi_singleton<vostok::render::options>::pinst;
  m_antialiasing_method = (vostok::render::backend *)vostok::quasi_singleton<vostok::render::options>::pinst->current.m_antialiasing_method;
  wszName[2] = 0;
  v230 = 0;
  if ( m_antialiasing_method )
  {
    if ( m_antialiasing_method == (vostok::render::backend *)1 )
    {
      wszName[2] = (pix_event_wrapper_dx11)1;
      v230 = 1;
    }
  }
  else
  {
    wszName[2] = 0;
  }
  wszName[1] = (pix_event_wrapper_dx11)(m_antialiasing_method == (vostok::render::backend *)2);
  if ( !LOBYTE(vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.elements[1]) )
  {
    qmemcpy(&this->m_prev_view_matrix, &m_context->m_v, sizeof(this->m_prev_view_matrix));
    LODWORD(y) = &this->m_sliced_cube_geometry;
    m_antialiasing_method = 0;
    LOBYTE(vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.elements[1]) = 1;
  }
  wszName[0] = (pix_event_wrapper_dx11)(v4->current.m_motion_blur_quality != 0);
  if ( !*(_BYTE *)wszName )
  {
    if ( !v4->current.m_use_motion_vectors_in_taa || !*(_BYTE *)&wszName[1] )
      goto LABEL_18;
LABEL_17:
    vostok::render::backend::flush_rt_shader_resources(
      m_antialiasing_method,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    vostok::render::stage_postprocess::accumulate_motion_vectors(v6, (int)this);
    goto LABEL_18;
  }
  if ( *(_BYTE *)&wszName[1] || v4->current.m_post_process_quality )
    goto LABEL_17;
LABEL_18:
  HIDWORD(v222) = m_antialiasing_method;
  vostok::render::renderer_context::get_rt(
    this->m_context,
    rt_light_scattering_mask,
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
  + 3);
  vostok::render::stage_postprocess::clear_surface(v7, (vostok::render::render_target *)HIDWORD(v222));
  HIDWORD(v222) = v8;
  vostok::render::renderer_context::get_rt(
    this->m_context,
    rt_light_scattering_result,
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
  + 3);
  vostok::render::stage_postprocess::clear_surface(v9, (vostok::render::render_target *)HIDWORD(v222));
  m_object = this->m_context->m_scene_view.m_object;
  v11 = (pix_event_wrapper_dx11 *)&m_object[1];
  v12 = LOBYTE(m_object[1].m_children_resources.m_last) == 0;
  LODWORD(arg.y) = &m_object[1];
  memset(&v238, 0, sizeof(v238));
  if ( !v12 && vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality )
  {
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(v11, wszName, (int)L"scattering_mask_pass");
    v13 = this->m_god_rays_effect.m_object;
    v13->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass(v14, (int)v13);
    sun_direction = vostok::render::environment_properties::get_sun_direction(
                      v15,
                      (int)&this->m_context->m_scene_view.m_object[1],
                      &v236.x);
    *(_QWORD *)&v238.x = *(_QWORD *)&sun_direction->x;
    HIDWORD(v222) = &v238;
    DWORD2(v222) = this->m_sun_direction_parameter;
    v238.z = sun_direction->z;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v17,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      (const vostok::render::shader_constant_host *)DWORD2(v222),
      &v238);
    HIDWORD(v222) = v18;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_light_scattering_mask,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 3);
    vostok::render::stage_postprocess::fill_surface2(
      v19,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      (vostok::render::render_target *)HIDWORD(v222));
    v20 = this->m_god_rays_effect.m_object;
    v20->m_cur_technique = 1;
    vostok::render::res_effect::apply_pass(v21, (int)v20);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v23,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      this->m_sun_direction_parameter,
      &v238);
    y = arg.y;
    v24 = *(float *)(LODWORD(arg.y) + 140);
    v234.x = *(float *)(LODWORD(arg.y) + 108);
    v25 = *(float *)(LODWORD(arg.y) + 112);
    HIDWORD(v222) = &v234;
    DWORD2(v222) = this->m_god_rays_parameters0;
    v234.y = v25;
    v234.z = *(float *)(LODWORD(arg.y) + 116);
    v235 = v24;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v26,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      (const vostok::render::shader_constant_host *)DWORD2(v222),
      &v234);
    v27 = *(float *)(LODWORD(y) + 144);
    *(_QWORD *)&v234.x = *(_QWORD *)(LODWORD(y) + 124);
    v28 = *(float *)(LODWORD(y) + 132);
    HIDWORD(v222) = &v234;
    DWORD2(v222) = this->m_god_rays_parameters1;
    v234.z = v28;
    v235 = v27;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v29,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      (const vostok::render::shader_constant_host *)DWORD2(v222),
      &v234);
    v30 = *(_DWORD *)(LODWORD(y) + 148);
    HIDWORD(v222) = &v234;
    DWORD2(v222) = this->m_god_rays_parameters2;
    *(_QWORD *)&v234.x = v30;
    v234.z = 0.0;
    v235 = 0.0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v31,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      (const vostok::render::shader_constant_host *)DWORD2(v222),
      &v234);
    HIDWORD(v222) = v32;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_light_scattering_result,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 3);
    vostok::render::stage_postprocess::fill_surface2(
      v33,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      (vostok::render::render_target *)HIDWORD(v222));
    D3DPERF_EndEvent();
  }
  vostok::render::backend::flush_rt_views((vostok::render::backend *)v11);
  if ( s_debug_pp_0 )
  {
    v35 = vostok::render::stage_postprocess::compute_luminance_parameters(
            v34,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
            (vostok::math::float4 *)LODWORD(y),
            &v234.x);
  }
  else
  {
    v234.x = FLOAT_0_25;
    v234.y = FLOAT_0_25;
    v234.z = FLOAT_0_25;
    v235 = FLOAT_0_25;
    v35 = (vostok::math::float4 *)&v234;
  }
  v36 = *(float *)(LODWORD(arg.y) + 584);
  v241 = *(vostok::math::float3 *)&v35->x;
  w = v35->w;
  arg.x = v36;
  if ( (_S6_8 & 1) == 0 )
  {
    _S6_8 |= 1u;
    randomizer_174.m_seed = 1000;
  }
  t = (int *)vostok::render::renderer_context::get_t(
               this->m_context,
               rt_present,
               (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&arg.elements[2]);
  v39 = 0;
  *(float *)&v233.m_object = (double)vostok::render::res_texture::width(v38, *t) * 0.00052083336;
  if ( LODWORD(arg.z) )
  {
    v41 = (_DWORD *)(LODWORD(arg.z) + 4);
    --*(_DWORD *)(LODWORD(arg.z) + 4);
    if ( !*v41 )
      vostok::render::resource_manager::release(
        v40,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_texture *)LODWORD(arg.z));
  }
  v42 = arg.y;
  if ( *(_BYTE *)(LODWORD(arg.y) + 516)
    && !(*(unsigned int *)((char *)&dword_10DF8 + (unsigned int)this->m_context->m_scene_view.m_object)
       % *(_DWORD *)(LODWORD(arg.y) + 524)) )
  {
    v232.x = vostok::math::random32::random_f(&randomizer_174, 1.0);
    v43 = vostok::math::random32::random_f(&randomizer_174, 1.0);
    *(vostok::render::stage_postprocess_vtbl **)((char *)&this->__vftable + (_DWORD)&loc_2637F + 1) = (vostok::render::stage_postprocess_vtbl *)LODWORD(v232.x);
    v232.y = v43;
    *(vostok::render::stage_postprocess_vtbl **)((char *)&this->__vftable + (_DWORD)&loc_26383 + 1) = (vostok::render::stage_postprocess_vtbl *)LODWORD(v232.y);
  }
  v44 = *(unsigned int *)((char *)&this->__vftable + (_DWORD)&loc_26383 + 1);
  *(float *)&v45 = *(float *)(LODWORD(v42) + 520) * *(float *)&v233.m_object;
  v46 = *(float *)(LODWORD(v42) + 504);
  LODWORD(v234.x) = *(vostok::render::stage_postprocess_vtbl **)((char *)&this->__vftable + (_DWORD)&loc_2637F + 1);
  *(_QWORD *)&v234.elements[1] = __PAIR64__(v45, v44);
  v235 = v46;
  if ( s_debug_pp_2 )
  {
    pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)v40, wszName, (int)L"bright_pass");
    HIDWORD(v222) = v47;
    vostok::render::renderer_context::get_t(
      this->m_context,
      rt_generic_0,
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 3);
    DWORD2(v222) = v48;
    DWORD1(v222) = v48;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_bright_pixels_2x,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 2);
    vostok::render::renderer::downsample(
      (vostok::render::renderer *)DWORD1(v222),
      (int)this->m_renderer,
      (vostok::render::render_target *)DWORD2(v222),
      *(vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&v222 + 12));
    LODWORD(v232.x) = vostok::render::renderer_context::get_rt(
                        this->m_context,
                        rt_bright_pixels_2x,
                        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt)->m_object->m_width;
    v49 = rt;
    v232.x = (float)LODWORD(v232.x);
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v49->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v231.m_object = (vostok::render::res_texture *)vostok::render::renderer_context::get_rt(
                                                     this->m_context,
                                                     rt_bright_pixels_2x,
                                                     (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt)->m_object->m_height;
    v51 = rt;
    *(float *)&v231.m_object = (float)(unsigned int)v231.m_object;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v51->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v52 = this->m_sh_gather_bloom.m_object;
    v52->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass(v50, (int)v52);
    vostok::render::bloom_shader_constants::set(
      &this->m_bloom_shader_constants,
      LODWORD(v42) + 564,
      *(_DWORD *)(LODWORD(v42) + 552),
      &this->m_bloom_shader_constants.m_bloom_parameters,
      v223,
      (const struct vostok::math::float3 *)v224);
    v236.x = (float)(s_bm_current_air_resistance / v232.x) * 0.5;
    HIDWORD(v222) = &v236;
    DWORD2(v222) = this->m_downsample_parameters;
    v236.y = (float)(s_bm_current_air_resistance / *(float *)&v231.m_object) * 0.5;
    v236.z = (float)(s_bm_current_air_resistance / v232.x) * -0.5;
    v237 = (float)(s_bm_current_air_resistance / *(float *)&v231.m_object) * -0.5;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v53,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      (const vostok::render::shader_constant_host *)DWORD2(v222),
      &v236);
    *((_QWORD *)&v222 + 1) = v54;
    DWORD1(v222) = v54;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_bloom_4x,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 2);
    vostok::render::stage_postprocess::fill_surface(
      (vostok::render::stage_postprocess *)DWORD1(v222),
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      (vostok::render::render_target *)DWORD2(v222),
      (vostok::render::render_target *)HIDWORD(v222));
    v56 = *(_DWORD *)(LODWORD(arg.y) + 560);
    if ( v56 )
    {
      if ( v56 > 7 )
        v56 = 7;
    }
    else
    {
      v56 = 0;
    }
    vostok::render::stage_postprocess::process_blur(
      v55,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      rt_bloom_4x,
      (vostok::render::res_texture *)0x2B,
      v56);
    HIDWORD(v222) = v57;
    vostok::render::renderer_context::get_t(
      this->m_context,
      rt_bloom_4x,
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 3);
    DWORD2(v222) = v58;
    DWORD1(v222) = v58;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_bloom_8x,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 2);
    vostok::render::renderer::downsample(
      (vostok::render::renderer *)DWORD1(v222),
      (int)this->m_renderer,
      (vostok::render::render_target *)DWORD2(v222),
      *(vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&v222 + 12));
    vostok::render::stage_postprocess::process_blur(
      v59,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      rt_bloom_8x,
      (vostok::render::res_texture *)0x2C,
      v56);
    HIDWORD(v222) = v60;
    vostok::render::renderer_context::get_t(
      this->m_context,
      rt_bloom_8x,
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 3);
    DWORD2(v222) = v61;
    DWORD1(v222) = v61;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_bloom_16x,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 2);
    vostok::render::renderer::downsample(
      (vostok::render::renderer *)DWORD1(v222),
      (int)this->m_renderer,
      (vostok::render::render_target *)DWORD2(v222),
      *(vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&v222 + 12));
    vostok::render::stage_postprocess::process_blur(
      v62,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      rt_bloom_16x,
      (vostok::render::res_texture *)0x2D,
      v56);
    v63 = this->m_sh_gather_bloom.m_object;
    v63->m_cur_technique = 1;
    vostok::render::res_effect::apply_pass(v64, (int)v63);
    *((_QWORD *)&v222 + 1) = v65;
    DWORD1(v222) = v65;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_bloom_combine,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 2);
    vostok::render::stage_postprocess::fill_surface(
      (vostok::render::stage_postprocess *)DWORD1(v222),
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      (vostok::render::render_target *)DWORD2(v222),
      (vostok::render::render_target *)HIDWORD(v222));
    D3DPERF_EndEvent();
    v42 = arg.y;
    v39 = 0;
  }
  if ( s_debug_pp_5 && *(_BYTE *)(LODWORD(v42) + 508) )
  {
    vostok::render::backend::flush_rt_shader_resources(
      (vostok::render::backend *)v40,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    v66 = this->m_lens_flares_effect.m_object;
    v66->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass(v67, (int)v66);
    if ( *(_DWORD *)(LODWORD(v42) + 16) )
    {
      m_reconstruction_info_actuality_tick = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)this->m_context->m_scene_view.m_object[1].m_reconstruction_info_actuality_tick;
      if ( m_reconstruction_info_actuality_tick
        && (v70 = m_reconstruction_info_actuality_tick + 66, v70->m_object)
        && (v68 = (vostok::render::backend *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) != 0 )
      {
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt,
          v70);
        v39 = 0;
      }
      else
      {
        rt = 0;
      }
      vostok::render::backend::set_ps_texture(
        v68,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        "t_lensdirt",
        (vostok::render::res_texture *)rt);
      if ( rt )
      {
        v71 = (vostok::render::res_texture *)rt;
        --rt->m_name.m_pointer.m_object;
        if ( !v71->m_reference_count )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)v68,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v71);
      }
    }
    v72 = *(_DWORD *)(LODWORD(arg.y) + 512);
    HIDWORD(v222) = &v236;
    DWORD2(v222) = this->m_lens_flares_parameters;
    *(_QWORD *)&v236.x = v72;
    v236.z = 0.0;
    v237 = 0.0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v68,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      (const vostok::render::shader_constant_host *)DWORD2(v222),
      &v236);
    HIDWORD(v222) = v73;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_lens_flares,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 3);
    vostok::render::stage_postprocess::fill_surface2(
      v74,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      (vostok::render::render_target *)HIDWORD(v222));
    v42 = arg.y;
  }
  vostok::render::stage_postprocess::process_color_grading_texture(
    (vostok::render::stage_postprocess *)v40,
    (const vostok::render::environment_properties *)this,
    LODWORD(v42));
  if ( s_debug_pp_6 )
  {
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(v75, wszName, (int)L"complex_blend");
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality )
    {
      v77 = *(unsigned __int8 *)(LODWORD(v42) + 580);
      if ( *(_BYTE *)(LODWORD(v42) + 580) )
        v39 = *(unsigned __int8 *)(LODWORD(v42) + 592);
    }
    else
    {
      v77 = 0;
    }
    v78 = this->m_sh_complex_blend[v77][v39].m_object;
    v78->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass(v76, (int)v78);
    v79 = arg.y;
    *((float *)&v222 + 3) = *(float *)(LODWORD(arg.y) + 588);
    *((float *)&v222 + 2) = arg.x;
    v232.x = s_bm_current_air_resistance;
    v80 = *(float *)(LODWORD(arg.y) + 612);
    v232.y = s_bm_current_air_resistance;
    *((float *)&v222 + 1) = v80;
    v232.z = s_bm_current_air_resistance;
    *(float *)&v222 = *(float *)(LODWORD(arg.y) + 608);
    *((float *)&v221 + 1) = *(float *)(LODWORD(arg.y) + 596);
    *(float *)&v221 = *(float *)(LODWORD(arg.y) + 600);
    vostok::render::dof_shader_constants::set(
      &this->m_dof_shader_constants,
      &v232,
      v81,
      v221,
      v222,
      *((__int64 *)&v222 + 1),
      v223);
    *((float *)&v222 + 3) = v79;
    DWORD2(v222) = &v234;
    *((float *)&v222 + 1) = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_gamma_correction_factor;
    v239.x = s_bm_current_air_resistance;
    v239.y = s_bm_current_air_resistance;
    v239.z = s_bm_current_air_resistance;
    v232.x = s_bm_current_air_resistance;
    v232.y = s_bm_current_air_resistance;
    v232.z = s_bm_current_air_resistance;
    v240.x = s_bm_current_air_resistance;
    v240.y = s_bm_current_air_resistance;
    v240.z = s_bm_current_air_resistance;
    v236.x = s_bm_current_air_resistance;
    v236.y = s_bm_current_air_resistance;
    v236.z = s_bm_current_air_resistance;
    vostok::render::scene_shader_constants::set(
      &this->m_scene_shader_constants,
      (vostok::render::backend *)&v236,
      &v239,
      &v240,
      &v232,
      *(const vostok::math::float3 *)((char *)&v222 + 4),
      v223,
      v224,
      v225);
    vostok::render::backend::set_ps_texture(
      v82,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_color_grading_lut",
      this->m_current_color_grading_lut.m_object);
    v83 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v84,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      this->m_sun_direction_parameter,
      &v238);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v85,
      (vostok::render::constants_handler<1> *)LODWORD(v83),
      this->m_frame_luminance_parameter,
      &v241);
    *((_QWORD *)&v222 + 1) = v86;
    DWORD1(v222) = v86;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_generic_1,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 2);
    vostok::render::stage_postprocess::fill_surface(
      (vostok::render::stage_postprocess *)DWORD1(v222),
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      (vostok::render::render_target *)DWORD2(v222),
      (vostok::render::render_target *)HIDWORD(v222));
    D3DPERF_EndEvent();
  }
  if ( s_debug_pp_7 )
  {
    if ( wszName[2] )
    {
      if ( !*(_BYTE *)&wszName[1] )
      {
        pix_event_wrapper_dx11::pix_event_wrapper_dx11(v75, wszName, (int)L"fxaa");
        vostok::render::backend::flush_rt_shader_resources(
          v87,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
        v88 = this->m_post_process_antialiasing_shader_fxaa.m_object;
        v88->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass(v89, (int)v88);
        m_fxaa_quality_subpix = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_fxaa_quality_subpix;
        m_fxaa_quality_edge_threshold = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_fxaa_quality_edge_threshold;
        m_fxaa_quality_edge_threshold_min = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_fxaa_quality_edge_threshold_min;
        HIDWORD(v222) = &v236;
        DWORD2(v222) = this->m_fxaa_parameters;
        *(_QWORD *)&v236.x = __PAIR64__(LODWORD(m_fxaa_quality_edge_threshold), LODWORD(m_fxaa_quality_subpix));
        v236.z = m_fxaa_quality_edge_threshold_min;
        v237 = 0.0;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v93,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::render::shader_constant_host *)DWORD2(v222),
          &v236);
        HIDWORD(v222) = v94;
        vostok::render::renderer_context::get_rt(
          this->m_context,
          rt_generic_0,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
        + 3);
        vostok::render::stage_postprocess::fill_surface2(
          v95,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
          (vostok::render::render_target *)HIDWORD(v222));
        D3DPERF_EndEvent();
      }
      if ( v230 && !*(_BYTE *)&wszName[1] )
      {
        pix_event_wrapper_dx11::pix_event_wrapper_dx11(v75, wszName, (int)L"sharpen");
        vostok::render::backend::flush_rt_shader_resources(
          v96,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
        v97 = this->m_post_process_shader_sharpen.m_object;
        v97->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass(v98, (int)v97);
        HIDWORD(v222) = v99;
        vostok::render::renderer_context::get_rt(
          this->m_context,
          rt_generic_1,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
        + 3);
        vostok::render::stage_postprocess::fill_surface2(
          v100,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
          (vostok::render::render_target *)HIDWORD(v222));
        v101 = this->m_post_process_shader_sharpen.m_object;
        v101->m_cur_technique = 1;
        vostok::render::res_effect::apply_pass(v102, (int)v101);
        HIDWORD(v222) = v103;
        vostok::render::renderer_context::get_rt(
          this->m_context,
          rt_present,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
        + 3);
        vostok::render::stage_postprocess::fill_surface2(
          v104,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
          (vostok::render::render_target *)HIDWORD(v222));
LABEL_79:
        D3DPERF_EndEvent();
        goto LABEL_80;
      }
    }
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(v75, wszName, (int)L"copy_rewrite");
    v105 = this->m_sh_effect_copy_image.m_object;
    v105->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass(v106, (int)v105);
    if ( !*(_BYTE *)&wszName[2] || *(_BYTE *)&wszName[1] )
    {
      v111 = vostok::render::renderer_context::get_t(
               this->m_context,
               rt_generic_1,
               (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
      vostok::render::backend::set_ps_texture(
        v112,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        "t_base",
        v111->m_object);
      if ( !rt )
        goto LABEL_78;
      p_m_name = &rt->m_name;
      --rt->m_name.m_pointer.m_object;
      if ( p_m_name->m_pointer.m_object )
        goto LABEL_78;
      HIDWORD(v222) = rt;
    }
    else
    {
      v107 = vostok::render::renderer_context::get_t(
               this->m_context,
               rt_generic_0,
               (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&arg.elements[2]);
      vostok::render::backend::set_ps_texture(
        v108,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        "t_base",
        v107->m_object);
      if ( !LODWORD(arg.z) )
        goto LABEL_78;
      v110 = (_DWORD *)(LODWORD(arg.z) + 4);
      --*(_DWORD *)(LODWORD(arg.z) + 4);
      if ( *v110 )
        goto LABEL_78;
      HIDWORD(v222) = LODWORD(arg.z);
    }
    vostok::render::resource_manager::release(
      v109,
      (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      (vostok::render::res_texture *)HIDWORD(v222));
LABEL_78:
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      (vostok::render::backend *)v109,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      this->m_gamma_correction_factor,
      (const vostok::math::float3 *)&vostok::quasi_singleton<vostok::render::options>::pinst->current.m_gamma_correction_factor);
    *((_QWORD *)&v222 + 1) = v114;
    DWORD1(v222) = v114;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_present,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 2);
    vostok::render::stage_postprocess::fill_surface(
      (vostok::render::stage_postprocess *)DWORD1(v222),
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      (vostok::render::render_target *)DWORD2(v222),
      (vostok::render::render_target *)HIDWORD(v222));
    goto LABEL_79;
  }
LABEL_80:
  v115 = this->m_context;
  rt = (vostok::render::render_target *)v115->m_eye_rays;
  if ( wszName[1] )
  {
    v116 = vostok::quasi_singleton<vostok::render::device>::pinst->m_context;
    v117 = vostok::render::renderer_context::get_t(v115, rt_present, &v231);
    v118 = this->m_context;
    LODWORD(arg.x) = v117->m_object->m_surface;
    v119 = vostok::render::renderer_context::get_t(
             v118,
             rt_albedo,
             (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&arg.elements[2]);
    v116->CopyResource(v116, v119->m_object->m_surface, (ID3D11Resource *)LODWORD(arg.x));
    if ( LODWORD(arg.z) )
    {
      v121 = (_DWORD *)(LODWORD(arg.z) + 4);
      --*(_DWORD *)(LODWORD(arg.z) + 4);
      if ( !*v121 )
        vostok::render::resource_manager::release(
          v120,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)LODWORD(arg.z));
    }
    if ( *(float *)&v231.m_object != 0.0 )
    {
      v122 = &v231.m_object->vostok::render::resource_intrusive_base;
      --v231.m_object->m_reference_count;
      if ( !v122->m_reference_count )
        vostok::render::resource_manager::release(
          v120,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v231.m_object);
    }
    v123 = this->m_temporal_antialiasing_effect.m_object;
    v123->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v120, (int)v123);
    v124 = vostok::math::transpose(&this->m_prev_view_matrix, &v243);
    v125 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v126,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      this->m_prev_view_matrix_parameter,
      (const vostok::math::float3 *)v124);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v127,
      (vostok::render::constants_handler<1> *)LODWORD(v125),
      this->m_c_eye_ray_corner,
      (const vostok::math::float3 *)rt);
    LODWORD(arg.x) = *(int *)((char *)&dword_10DF8 + (unsigned int)this->m_context->m_scene_view.m_object) & 1;
    vostok::render::backend::set_ps_constant<unsigned int>(
      (vostok::render::backend *)LODWORD(v125),
      this->m_c_frame_index,
      (const int *)&arg);
    HIDWORD(v222) = v128;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_present,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 3);
    vostok::render::stage_postprocess::fill_surface2(
      v129,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      (vostok::render::render_target *)HIDWORD(v222));
    v130 = vostok::quasi_singleton<vostok::render::device>::pinst->m_context;
    v131 = vostok::render::renderer_context::get_t(
             this->m_context,
             rt_albedo,
             (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v232);
    v132 = this->m_context;
    LODWORD(arg.x) = v131->m_object->m_surface;
    v133 = vostok::render::renderer_context::get_t(v132, rt_previous_present, &v231);
    v130->CopyResource(v130, v133->m_object->m_surface, (ID3D11Resource *)LODWORD(arg.x));
    if ( *(float *)&v231.m_object != 0.0 )
    {
      v134 = &v231.m_object->vostok::render::resource_intrusive_base;
      --v231.m_object->m_reference_count;
      if ( !v134->m_reference_count )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v115,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v231.m_object);
    }
    if ( LODWORD(v232.x) )
    {
      v135 = (_DWORD *)(LODWORD(v232.x) + 4);
      --*(_DWORD *)(LODWORD(v232.x) + 4);
      if ( !*v135 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)v115,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)LODWORD(v232.x));
    }
    goto LABEL_94;
  }
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality )
  {
LABEL_94:
    if ( wszName[0] )
    {
      HIDWORD(v222) = v115;
      vostok::render::renderer_context::get_t(
        this->m_context,
        rt_present,
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
      + 3);
      DWORD2(v222) = v136;
      DWORD1(v222) = v136;
      vostok::render::renderer_context::get_rt(
        this->m_context,
        rt_present_downsampled,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
      + 2);
      vostok::render::renderer::downsample(
        (vostok::render::renderer *)DWORD1(v222),
        (int)this->m_renderer,
        (vostok::render::render_target *)DWORD2(v222),
        *(vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&v222 + 12));
      vostok::render::backend::flush_rt_shader_resources(
        v137,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      m_motion_blur_quality = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_motion_blur_quality;
      if ( m_motion_blur_quality )
      {
        v140 = m_motion_blur_quality - 1;
        if ( v140 )
        {
          if ( v140 == 1 )
            v141 = FLOAT_0_60000002;
          else
            v141 = s_bm_current_air_resistance;
        }
        else
        {
          v141 = FLOAT_0_2;
        }
      }
      else
      {
        v141 = 0.0;
      }
      v142 = this->m_motion_blur_effect.m_object;
      arg.z = v141;
      v142->m_cur_technique = 0;
      vostok::render::res_effect::apply_pass(v138, (int)v142);
      v143 = vostok::math::transpose(&this->m_prev_view_matrix, &v243);
      v144 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v145,
        (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        this->m_prev_view_matrix_parameter,
        (const vostok::math::float3 *)v143);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v146,
        (vostok::render::constants_handler<1> *)LODWORD(v144),
        this->m_c_eye_ray_corner,
        (const vostok::math::float3 *)rt);
      m_time_delta = this->m_context->m_time_delta;
      HIDWORD(v222) = &arg;
      DWORD2(v222) = this->m_frame_delta_parameter;
      arg.x = m_time_delta;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v148,
        (vostok::render::constants_handler<1> *)LODWORD(v144),
        (const vostok::render::shader_constant_host *)DWORD2(v222),
        &arg);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v149,
        (vostok::render::constants_handler<1> *)LODWORD(v144),
        this->m_motion_blur_scale_parameter,
        (vostok::math::float3 *)&arg.elements[2]);
      HIDWORD(v222) = v150;
      vostok::render::renderer_context::get_rt(
        this->m_context,
        rt_motion_blur_result,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
      + 3);
      vostok::render::stage_postprocess::fill_surface2(
        v151,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
        (vostok::render::render_target *)HIDWORD(v222));
      if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality > 1 )
      {
        v153 = this->m_motion_blur_effect.m_object;
        v153->m_cur_technique = 1;
        vostok::render::res_effect::apply_pass(v152, (int)v153);
        v154 = vostok::math::transpose(&this->m_prev_view_matrix, &v243);
        v155 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v156,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          this->m_prev_view_matrix_parameter,
          (const vostok::math::float3 *)v154);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v157,
          (vostok::render::constants_handler<1> *)LODWORD(v155),
          this->m_c_eye_ray_corner,
          (const vostok::math::float3 *)rt);
        v158 = this->m_context->m_time_delta;
        HIDWORD(v222) = &arg;
        DWORD2(v222) = this->m_frame_delta_parameter;
        arg.x = v158;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v159,
          (vostok::render::constants_handler<1> *)LODWORD(v155),
          (const vostok::render::shader_constant_host *)DWORD2(v222),
          &arg);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v160,
          (vostok::render::constants_handler<1> *)LODWORD(v155),
          this->m_motion_blur_scale_parameter,
          (vostok::math::float3 *)&arg.elements[2]);
        HIDWORD(v222) = v161;
        vostok::render::renderer_context::get_rt(
          this->m_context,
          rt_present_downsampled,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
        + 3);
        vostok::render::stage_postprocess::fill_surface2(
          v162,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
          (vostok::render::render_target *)HIDWORD(v222));
      }
      if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality > 2 )
      {
        v163 = this->m_motion_blur_effect.m_object;
        v163->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass(v152, (int)v163);
        v164 = vostok::math::transpose(&this->m_prev_view_matrix, &v243);
        v165 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v166,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          this->m_prev_view_matrix_parameter,
          (const vostok::math::float3 *)v164);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v167,
          (vostok::render::constants_handler<1> *)LODWORD(v165),
          this->m_c_eye_ray_corner,
          (const vostok::math::float3 *)rt);
        v168 = this->m_context->m_time_delta;
        HIDWORD(v222) = &arg;
        DWORD2(v222) = this->m_frame_delta_parameter;
        arg.x = v168;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v169,
          (vostok::render::constants_handler<1> *)LODWORD(v165),
          (const vostok::render::shader_constant_host *)DWORD2(v222),
          &arg);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v170,
          (vostok::render::constants_handler<1> *)LODWORD(v165),
          this->m_motion_blur_scale_parameter,
          (vostok::math::float3 *)&arg.elements[2]);
        HIDWORD(v222) = v171;
        vostok::render::renderer_context::get_rt(
          this->m_context,
          rt_motion_blur_result,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
        + 3);
        vostok::render::stage_postprocess::fill_surface2(
          v172,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
          (vostok::render::render_target *)HIDWORD(v222));
      }
      vostok::render::backend::flush_rt_shader_resources(
        (vostok::render::backend *)v152,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      v173 = this->m_motion_blur_effect.m_object;
      if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality == 2 )
        v173->m_cur_technique = 3;
      else
        v173->m_cur_technique = 2;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)2, (int)v173);
      HIDWORD(v222) = v174;
      vostok::render::renderer_context::get_rt(
        this->m_context,
        rt_present,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
      + 3);
      vostok::render::stage_postprocess::fill_surface2(
        v175,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
        (vostok::render::render_target *)HIDWORD(v222));
    }
  }
  v176 = arg.y;
  if ( *(_BYTE *)(LODWORD(arg.y) + 153) )
  {
    v177 = LODWORD(arg.y) + 156;
    if ( *(float *)(LODWORD(arg.y) + 156) > 0.0099999998 )
    {
      v178 = this->m_channel_blur_effect.m_object;
      v178->m_cur_technique = 0;
      vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v115, (int)v178);
      HIDWORD(v222) = v177;
      DWORD2(v222) = this->m_c_channel_blur_amount;
      v179 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v180,
        (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        (const vostok::render::shader_constant_host *)DWORD2(v222),
        (const vostok::math::float3 *)HIDWORD(v222));
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v181,
        (vostok::render::constants_handler<1> *)LODWORD(v179),
        this->m_c_channel_blur_power,
        (const vostok::math::float3 *)(LODWORD(arg.y) + 160));
      v182 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
      v222 = 0u;
      v221 = (unsigned int)v183;
      v218 = v183;
      vostok::render::renderer_context::get_rt(
        this->m_context,
        rt_present,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v221);
      vostok::render::system_renderer::fill_surface(
        v218,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v182,
        (vostok::render::render_target *)v221,
        (vostok::render::render_target *)HIDWORD(v221),
        (vostok::render::render_target *)v222,
        *(vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&v222 + 4),
        (vostok::render::render_target *)DWORD2(v222),
        (D3D11_VIEWPORT *)HIDWORD(v222),
        v223,
        *(float *)&v224,
        *(float *)&v225,
        v226);
      v176 = arg.y;
    }
  }
  if ( *(_BYTE *)(LODWORD(v176) + 152) )
  {
    v184 = LODWORD(v176) + 168;
    if ( *(float *)(LODWORD(v176) + 168) > 0.0099999998 && *(float *)(LODWORD(v176) + 164) > 0.001 )
    {
      HIDWORD(v222) = v115;
      vostok::render::renderer_context::get_t(
        this->m_context,
        rt_present,
        (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
      + 3);
      DWORD2(v222) = v185;
      DWORD1(v222) = v185;
      vostok::render::renderer_context::get_rt(
        this->m_context,
        rt_present_downsampled,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
      + 2);
      vostok::render::renderer::downsample(
        (vostok::render::renderer *)DWORD1(v222),
        (int)this->m_renderer,
        (vostok::render::render_target *)DWORD2(v222),
        *(vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&v222 + 12));
      v186 = this->m_radial_motion_blur_effect.m_object;
      v186->m_cur_technique = 0;
      vostok::render::res_effect::apply_pass(v187, (int)v186);
      HIDWORD(v222) = v184;
      DWORD2(v222) = this->m_c_radial_blur_amount;
      v188 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v189,
        (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        (const vostok::render::shader_constant_host *)DWORD2(v222),
        (const vostok::math::float3 *)HIDWORD(v222));
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v190,
        (vostok::render::constants_handler<1> *)LODWORD(v188),
        this->m_c_radial_blur_intensity,
        (const vostok::math::float3 *)(LODWORD(arg.y) + 164));
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v191,
        (vostok::render::constants_handler<1> *)LODWORD(v188),
        this->m_c_radial_blur_power,
        (const vostok::math::float3 *)(LODWORD(arg.y) + 172));
      v192 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
      v222 = 0u;
      v221 = (unsigned int)v193;
      v219 = v193;
      vostok::render::renderer_context::get_rt(
        this->m_context,
        rt_radial_motion_blur_result,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v221);
      vostok::render::system_renderer::fill_surface(
        v219,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v192,
        (vostok::render::render_target *)v221,
        (vostok::render::render_target *)HIDWORD(v221),
        (vostok::render::render_target *)v222,
        *(vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&v222 + 4),
        (vostok::render::render_target *)DWORD2(v222),
        (D3D11_VIEWPORT *)HIDWORD(v222),
        v223,
        *(float *)&v224,
        *(float *)&v225,
        v226);
      v194 = this->m_radial_motion_blur_effect.m_object;
      v194->m_cur_technique = 1;
      vostok::render::res_effect::apply_pass(v195, (int)v194);
      v196 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
      v222 = 0u;
      v221 = (unsigned int)v197;
      v220 = v197;
      vostok::render::renderer_context::get_rt(
        this->m_context,
        rt_present,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v221);
      vostok::render::system_renderer::fill_surface(
        v220,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v196,
        (vostok::render::render_target *)v221,
        (vostok::render::render_target *)HIDWORD(v221),
        (vostok::render::render_target *)v222,
        *(vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&v222 + 4),
        (vostok::render::render_target *)DWORD2(v222),
        (D3D11_VIEWPORT *)HIDWORD(v222),
        v223,
        *(float *)&v224,
        *(float *)&v225,
        v226);
      v176 = arg.y;
    }
  }
  m_post_process_quality = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality;
  if ( !m_post_process_quality
    || (v12 = *(_BYTE *)(LODWORD(v176) + 528) == 0, wszName[2] = (pix_event_wrapper_dx11)1, v12) )
  {
    wszName[2] = 0;
  }
  if ( !m_post_process_quality
    || (v12 = *(_BYTE *)(LODWORD(v176) + 544) == 0, wszName[1] = (pix_event_wrapper_dx11)1, v12) )
  {
    wszName[1] = 0;
  }
  v199 = *(pix_event_wrapper_dx11 *)(LODWORD(v176) + 516);
  wszName[0] = v199;
  if ( *(_BYTE *)&wszName[2] || *(_BYTE *)&wszName[1] || *(_BYTE *)&v199 )
  {
    HIDWORD(v222) = vostok::quasi_singleton<vostok::render::options>::pinst;
    vostok::render::renderer_context::get_t(
      this->m_context,
      rt_present,
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 3);
    DWORD2(v222) = v200;
    DWORD1(v222) = v200;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_present_downsampled,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 2);
    vostok::render::renderer::downsample(
      (vostok::render::renderer *)DWORD1(v222),
      (int)this->m_renderer,
      (vostok::render::render_target *)DWORD2(v222),
      *(vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&v222 + 12));
    v201 = (vostok::render::res_effect *)(unsigned __int8)wszName[0];
    v202 = this->m_aberration_sharpen_effect[*(_BYTE *)&wszName[2]][*(_BYTE *)&wszName[1]][*(_BYTE *)wszName].m_object;
    v202->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass(v201, (int)v202);
    v203 = *(float *)(LODWORD(arg.y) + 532);
    v204 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    v236.x = *(float *)(LODWORD(arg.y) + 536) * v203;
    *(float *)&v205 = *(float *)(LODWORD(arg.y) + 540) * v203;
    *(float *)&v206 = *(float *)(LODWORD(arg.y) + 548) * *(float *)&v233.m_object;
    HIDWORD(v222) = &v236;
    DWORD2(v222) = this->m_aberration_parameters;
    *(_QWORD *)&v236.elements[1] = __PAIR64__(v206, v205);
    v237 = 0.0;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v207,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      (const vostok::render::shader_constant_host *)DWORD2(v222),
      &v236);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v208,
      (vostok::render::constants_handler<1> *)LODWORD(v204),
      this->m_image_grain_parameters,
      &v234);
    HIDWORD(v222) = v209;
    vostok::render::renderer_context::get_rt(
      this->m_context,
      rt_albedo,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v222
    + 3);
    vostok::render::stage_postprocess::fill_surface2(
      v210,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      (vostok::render::render_target *)HIDWORD(v222));
    v211 = vostok::quasi_singleton<vostok::render::device>::pinst->m_context;
    v212 = vostok::render::renderer_context::get_t(
             this->m_context,
             rt_albedo,
             (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v232);
    v213 = this->m_context;
    LODWORD(arg.x) = v212->m_object->m_surface;
    v214 = vostok::render::renderer_context::get_t(v213, rt_present, &v233);
    v211->CopyResource(v211, v214->m_object->m_surface, (ID3D11Resource *)LODWORD(arg.x));
    if ( *(float *)&v233.m_object != 0.0 )
    {
      v12 = v233.m_object->m_reference_count-- == 1;
      if ( v12 )
        vostok::render::resource_manager::release(
          v215,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v233.m_object);
    }
    if ( LODWORD(v232.x) )
    {
      v12 = (*(_DWORD *)(LODWORD(v232.x) + 4))-- == 1;
      if ( v12 )
        vostok::render::resource_manager::release(
          v215,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)LODWORD(v232.x));
    }
  }
  p_m_v = &this->m_context->m_v;
  LODWORD(arg.x) = this->m_context;
  qmemcpy(&this->m_prev_view_matrix, p_m_v, sizeof(this->m_prev_view_matrix));
  v217 = vostok::math::float4x4::identity(0, &v243);
  vostok::render::renderer_context::set_w(v217, (vostok::render::renderer_context *)LODWORD(arg.x));
LABEL_134:
  D3DPERF_EndEvent();
}
