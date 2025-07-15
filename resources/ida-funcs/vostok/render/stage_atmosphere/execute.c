void __thiscall vostok::render::stage_atmosphere::execute(vostok::render::stage_atmosphere *this)
{
  vostok::render::environment_properties *v2; // ecx
  vostok::render::base_scene_view *m_object; // edi
  vostok::math::float3 *sun_direction; // eax
  vostok::render::res_effect *v5; // ecx
  bool v6; // zf
  vostok::render::renderer *m_renderer; // eax
  pix_event_wrapper_dx11 m_scene_changed; // dl
  vostok::render::renderer_context *m_context; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool has_passed_filters; // al
  vostok::render::res_effect *v12; // eax
  volatile int m_thread_id; // xmm0_4
  float z; // esi
  vostok::render::backend *v15; // ecx
  vostok::resources::name_registry_entry *m_name_registry_entry; // xmm0_4
  vostok::resources::resource_base *m_next_for_query_finished_callback; // xmm1_4
  float v18; // xmm2_4
  vostok::resources::query_result *m_destruction_observer; // xmm3_4
  vostok::render::backend *v20; // ecx
  vostok::render::render_target *v21; // ecx
  vostok::render::stage_atmosphere *v22; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v23; // eax
  float v24; // esi
  vostok::render::render_target *v25; // eax
  vostok::render::res_effect *v26; // ecx
  vostok::render::res_effect *v27; // eax
  float v28; // esi
  vostok::render::backend *v29; // ecx
  vostok::render::shader_constant_host *m_to_sun_direction_parameter; // eax
  vostok::render::renderer_context *v31; // eax
  vostok::math::float4x4 *v32; // ecx
  vostok::math::float4x4 *v33; // eax
  vostok::render::sky_dome_geometry *v34; // ecx
  vostok::render::resource_manager *v35; // ecx
  vostok::render::res_texture *v36; // edi
  BOOL v37; // esi
  vostok::render::base_scene_view *v38; // eax
  vostok::shared_string *p_m_name; // eax
  vostok::render::res_texture **stratosphere_texture; // eax
  vostok::render::backend *v41; // ecx
  vostok::render::resource_manager *v42; // ecx
  vostok::render::resource_intrusive_base *v43; // eax
  float w; // xmm3_4
  float v45; // esi
  float x; // xmm1_4
  float y; // xmm2_4
  float v48; // xmm0_4
  unsigned int m_max_uses_height; // xmm0_4
  DXGI_FORMAT m_base_format; // xmm1_4
  vostok::render::backend *v51; // ecx
  vostok::render::backend *v52; // ecx
  __m128 x_low; // xmm0
  __m128i v54; // xmm0
  float v55; // xmm1_4
  vostok::render::shader_constant_host *m_sky_clouds_parameters2; // eax
  vostok::render::backend *v57; // ecx
  vostok::render::sky_dome_geometry *v58; // ecx
  vostok::render::base_scene_view *v59; // eax
  vostok::render::resource_intrusive_base *v60; // eax
  vostok::render::res_texture **sky_clouds_texture; // eax
  vostok::render::backend *v62; // ecx
  vostok::render::resource_manager *v63; // ecx
  vostok::render::resource_intrusive_base *v64; // eax
  float v65; // xmm3_4
  float v66; // esi
  float v67; // xmm1_4
  unsigned int v68; // xmm2_4
  unsigned int v69; // xmm0_4
  unsigned int v70; // xmm0_4
  DXGI_FORMAT v71; // xmm1_4
  vostok::render::backend *v72; // ecx
  vostok::render::backend *v73; // ecx
  __m128 loaded_num_mips; // xmm0
  __m128i v75; // xmm0
  float v76; // xmm1_4
  vostok::render::shader_constant_host *v77; // eax
  vostok::render::backend *v78; // ecx
  vostok::render::sky_dome_geometry *v79; // ecx
  vostok::render::backend *v80; // ecx
  vostok::render::res_effect *v81; // eax
  vostok::math::float3 *m_eye_rays; // edi
  float v83; // esi
  vostok::render::backend *v84; // ecx
  vostok::render::backend *v85; // ecx
  vostok::render::backend *v86; // ecx
  vostok::render::render_target *v87; // ecx
  vostok::render::stage_atmosphere *v88; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v89; // [esp-Ch] [ebp-ACh] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v90; // [esp-8h] [ebp-A8h] BYREF
  unsigned int p_arg; // [esp-4h] [ebp-A4h]
  long double v92; // [esp+0h] [ebp-A0h]
  unsigned __int8 m_atmosphere_changed; // [esp+13h] [ebp-8Dh]
  vostok::math::float3 arg; // [esp+14h] [ebp-8Ch] BYREF
  float v95; // [esp+20h] [ebp-80h]
  int v96; // [esp+24h] [ebp-7Ch]
  pix_event_wrapper_dx11 wszName; // [esp+2Ah] [ebp-76h] BYREF
  bool wszName_1; // [esp+2Bh] [ebp-75h]
  const char *v99; // [esp+2Ch] [ebp-74h]
  vostok::render::res_texture *v100; // [esp+30h] [ebp-70h] BYREF
  vostok::render::render_target *rt; // [esp+34h] [ebp-6Ch] BYREF
  float v102; // [esp+38h] [ebp-68h] BYREF
  unsigned int v103; // [esp+3Ch] [ebp-64h]
  float v104; // [esp+40h] [ebp-60h]
  unsigned int v105; // [esp+44h] [ebp-5Ch]
  int v106; // [esp+48h] [ebp-58h]
  float v107; // [esp+4Ch] [ebp-54h]
  vostok::math::float4x4 v108; // [esp+50h] [ebp-50h] BYREF
  float v109[3]; // [esp+94h] [ebp-Ch] BYREF

  v96 = 0;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, &wszName, (int)L"stage_atmosphere");
  if ( this->is_effects_ready(this) )
  {
    if ( !this->is_enabled(this) )
    {
LABEL_3:
      this->execute_disabled(this);
      goto LABEL_56;
    }
    m_object = this->m_context->m_scene_view.m_object;
    v100 = (vostok::render::res_texture *)m_object;
    sun_direction = vostok::render::environment_properties::get_sun_direction(v2, (int)&m_object[1], v109);
    v6 = this->m_type == atmosphere_on_sky;
    v105 = LODWORD(sun_direction->x) ^ _mask__NegFloat_;
    v103 = LODWORD(sun_direction->y) ^ _mask__NegFloat_;
    LODWORD(v104) = LODWORD(sun_direction->z) ^ _mask__NegFloat_;
    if ( v6 )
    {
      if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_atmosphere_stage )
        goto LABEL_3;
      m_renderer = this->m_renderer;
      m_scene_changed = (pix_event_wrapper_dx11)m_renderer->m_scene_changed;
      m_atmosphere_changed = m_renderer->m_atmosphere_changed;
      m_context = this->m_context;
      v10 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)m_context->m_scene_view.m_object;
      v6 = *(int *)((char *)&dword_10E28 + (_DWORD)v10) == m_context->m_targets->m_id;
      wszName = m_scene_changed;
      wszName_1 = !v6;
      if ( *(_BYTE *)&m_scene_changed || __PAIR16__(wszName_1, 0) != m_atmosphere_changed )
      {
        if ( !vostok::core::g_log_filter_tree
          || (has_passed_filters = vostok::logging::has_passed_filters(
                                     (vostok::logging::filter_tree *)"render_pc_dx11",
                                     (const char *)4),
              v10 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)p_arg,
              has_passed_filters) )
        {
          v99 = "true";
          if ( !wszName_1 )
            v99 = "false";
          v102 = COERCE_FLOAT("true");
          if ( !m_atmosphere_changed )
            v102 = COERCE_FLOAT("false");
          rt = (vostok::render::render_target *)"true";
          if ( !*(_BYTE *)&wszName )
            rt = (vostok::render::render_target *)"false";
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v10,
            &v108);
          v96 = 1;
          vostok::logging::append(
            (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v108,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\stage_atmosphere.cpp",
            0xB6u,
            "void __thiscall vostok::render::stage_atmosphere::execute(void)",
            "render_pc_dx11",
            info,
            "atmosphere recalculated ( scene_changed:%s, parameters_changed:%s, window_resized:%s )",
            (const char *)rt,
            (const char *)LODWORD(v102),
            v99);
        }
        if ( (v96 & 1) != 0 )
        {
          v96 &= ~1u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
            (int *)&v108);
        }
        v12 = this->m_atmospheric_scattering_effect[0].m_object;
        v12->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v10, (int)v12);
        m_thread_id = this->m_context->m_scene_view.m_object[1].m_parent_resources.m_thread_id;
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        *(_QWORD *)&arg.x = __PAIR64__(v103, v105);
        p_arg = (unsigned int)&arg;
        v90.m_object = (vostok::render::render_target *)this->m_to_sun_direction_parameter;
        arg.z = v104;
        v95 = *(float *)&m_thread_id;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v15,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::render::shader_constant_host *)v90.m_object,
          &arg);
        m_name_registry_entry = m_object[1].m_name_registry_entry;
        m_next_for_query_finished_callback = m_object[1].m_next_for_query_finished_callback;
        v18 = *(float *)&m_object[1].m_next_for_grm_observer_list;
        m_destruction_observer = m_object[1].m_destruction_observer;
        p_arg = (unsigned int)&arg;
        v90.m_object = (vostok::render::render_target *)this->m_c_atmosphere_parameters;
        *(_QWORD *)&arg.x = __PAIR64__(
                              (unsigned int)m_next_for_query_finished_callback,
                              (unsigned int)m_name_registry_entry);
        arg.z = v18;
        v95 = *(float *)&m_destruction_observer;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v20,
          (vostok::render::constants_handler<1> *)LODWORD(z),
          (const vostok::render::shader_constant_host *)v90.m_object,
          &arg);
        p_arg = 0;
        v90.m_object = v21;
        v89.m_object = v21;
        vostok::render::renderer_context::get_rt(this->m_context, rt_mie_scattering, &v90);
        vostok::render::renderer_context::get_rt(this->m_context, rt_rayleigh_scattering, &v89);
        vostok::render::stage_atmosphere::fill_surfaces(
          v22,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
          v89.m_object,
          v90.m_object,
          p_arg);
        *(int *)((char *)&dword_10E28 + (unsigned int)this->m_context->m_scene_view.m_object) = this->m_context->m_targets->m_id;
      }
      v23 = vostok::render::renderer_context::get_rt(
              this->m_context,
              rt_generic_0,
              (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
      v24 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_render_targets(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        v23->m_object,
        0,
        0,
        0);
      v25 = rt;
      if ( rt )
      {
        --rt->m_reference_count;
        if ( !v25->m_reference_count )
        {
          vostok::render::resource_manager::release(
            rt,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
          v24 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        }
      }
      v26 = *(vostok::render::res_effect **)(LODWORD(v24) + 7440);
      v6 = *(_DWORD *)(LODWORD(v24) + 7384) == (_DWORD)v26;
      *(_DWORD *)(LODWORD(v24) + 7384) = v26;
      *(_BYTE *)(LODWORD(v24) + 117) |= !v6;
      v6 = LOBYTE(m_object[1].m_creation_source) == 0;
      v99 = (const char *)this->m_context->m_scene_view.m_object[1].m_parent_resources.m_thread_id;
      if ( v6 )
        v99 = 0;
      v27 = this->m_atmospheric_scattering_effect[0].m_object;
      v27->m_cur_technique = 1;
      vostok::render::res_effect::apply_pass(v26, (int)v27);
      v28 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      *(_QWORD *)&arg.x = __PAIR64__(v103, v105);
      p_arg = (unsigned int)&arg;
      v90.m_object = (vostok::render::render_target *)this->m_to_sun_direction_parameter;
      arg.z = v104;
      v95 = *(float *)&v99;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v29,
        (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        (const vostok::render::shader_constant_host *)v90.m_object,
        &arg);
      *(_QWORD *)&arg.x = __PAIR64__(v103, v105);
      arg.z = v104;
      p_arg = (unsigned int)&arg;
      m_to_sun_direction_parameter = this->m_to_sun_direction_parameter;
      v95 = *(float *)&v99;
      vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
        (vostok::render::backend *)LODWORD(v28),
        m_to_sun_direction_parameter,
        (const unsigned int *)&arg);
      v31 = this->m_context;
      qmemcpy(&v108, &v31->m_p, sizeof(v108));
      v108.k.z = FLOAT_1_0000001;
      v108.c.z = FLOAT_N1_0000001;
      vostok::render::renderer_context::push_set_p((vostok::render::renderer_context *)&v108, (int)v31, &v108);
      v33 = vostok::math::float4x4::identity(v32, &v108);
      vostok::render::renderer_context::set_w(v33, this->m_context);
      vostok::render::sky_dome_geometry::draw(v34, (int)&this->m_sky_dome_geometry);
      v36 = v100;
      v6 = LOBYTE(v100[1].max_tiling) == 0;
      v37 = LOBYTE(v100[1].m_desc.Format) != 0;
      v107 = *(float *)&v37;
      if ( v6
        || (v38 = this->m_context->m_scene_view.m_object,
            v96 |= 2u,
            !vostok::render::scene_view::get_stratosphere_texture((vostok::render::scene_view *)&rt, (int)v38)->__vftable)
        || (m_atmosphere_changed = 1,
            !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
      {
        m_atmosphere_changed = 0;
      }
      if ( (v96 & 2) != 0 )
      {
        v96 &= ~2u;
        if ( rt )
        {
          p_m_name = &rt->m_name;
          --rt->m_name.m_pointer.m_object;
          if ( !p_m_name->m_pointer.m_object )
            vostok::render::resource_manager::release(
              v35,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              (vostok::render::res_texture *)rt);
        }
      }
      if ( m_atmosphere_changed )
      {
        vostok::render::res_effect::apply(
          (vostok::render::res_effect *)(3 - (LODWORD(v36[1].m_rescale_min.z) != 0)),
          (int)this->m_atmospheric_scattering_effect[v37].m_object);
        stratosphere_texture = (vostok::render::res_texture **)vostok::render::scene_view::get_stratosphere_texture(
                                                                 (vostok::render::scene_view *)&v102,
                                                                 (int)this->m_context->m_scene_view.m_object);
        vostok::render::backend::set_ps_texture(
          v41,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          "sky_clouds_texture",
          *stratosphere_texture);
        if ( v102 != 0.0 )
        {
          v43 = (vostok::render::resource_intrusive_base *)(LODWORD(v102) + 4);
          --*(_DWORD *)(LODWORD(v102) + 4);
          if ( !v43->m_reference_count )
            vostok::render::resource_manager::release(
              v42,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              (vostok::render::res_texture *)LODWORD(v102));
        }
        w = v36[1].m_rescale_max.w;
        v45 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        x = v36[1].m_rescale_max.x;
        y = v36[1].m_rescale_max.y;
        v48 = v36[1].m_rescale_min.w * w;
        p_arg = (unsigned int)&arg;
        v90.m_object = (vostok::render::render_target *)this->m_sky_clouds_parameters0;
        arg.x = v48;
        arg.y = x * w;
        arg.z = y * w;
        v95 = 0.0;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          (vostok::render::backend *)v42,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::render::shader_constant_host *)v90.m_object,
          &arg);
        m_max_uses_height = v36[1].m_max_uses_height;
        m_base_format = v36[1].m_base_format;
        p_arg = (unsigned int)&arg;
        v90.m_object = (vostok::render::render_target *)this->m_sky_clouds_parameters1;
        *(_QWORD *)&arg.x = __PAIR64__(m_base_format, m_max_uses_height);
        arg.z = 0.0;
        v95 = 0.0;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v51,
          (vostok::render::constants_handler<1> *)LODWORD(v45),
          (const vostok::render::shader_constant_host *)v90.m_object,
          &arg);
        *(_QWORD *)&arg.x = __PAIR64__(v103, v105);
        p_arg = (unsigned int)&arg;
        v90.m_object = (vostok::render::render_target *)this->m_to_sun_direction_parameter;
        arg.z = v104;
        v95 = *(float *)&v99;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v52,
          (vostok::render::constants_handler<1> *)LODWORD(v45),
          (const vostok::render::shader_constant_host *)v90.m_object,
          &arg);
        x_low = (__m128)LODWORD(v36[1].m_rescale_min.x);
        x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * 0.0055555557) * 3.1415927;
        v102 = x_low.m128_f32[0];
        v54 = (__m128i)_mm_cvtps_pd(x_low);
        __libm_sse2_sin(v54);
        *(float *)v54.m128i_i32 = *(double *)v54.m128i_i64;
        v106 = v54.m128i_i32[0];
        *(double *)v54.m128i_i64 = v102;
        __libm_sse2_cos(v92);
        v55 = v36[1].m_rescale_min.y;
        *(float *)v54.m128i_i32 = *(double *)v54.m128i_i64;
        *(_QWORD *)&arg.x = __PAIR64__(v106, v54.m128i_u32[0]);
        p_arg = (unsigned int)&arg;
        m_sky_clouds_parameters2 = this->m_sky_clouds_parameters2;
        arg.z = v55;
        v95 = FLOAT_200000_0;
        vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
          (vostok::render::backend *)LODWORD(v45),
          m_sky_clouds_parameters2,
          (const unsigned int *)&arg);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v57,
          (vostok::render::constants_handler<1> *)LODWORD(v45),
          this->m_sky_clouds_parameters3,
          (const vostok::math::float3 *)&v36[1].m_streamed);
        vostok::render::sky_dome_geometry::draw(v58, (int)&this->m_clouds_geometry);
        *(float *)&v37 = v107;
        v36 = v100;
      }
      if ( !BYTE1(v36[1].num_mips)
        || (v59 = this->m_context->m_scene_view.m_object,
            v96 |= 4u,
            !vostok::render::scene_view::get_sky_clouds_texture((vostok::render::scene_view *)&v100, (int)v59)->__vftable)
        || (m_atmosphere_changed = 1,
            !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
      {
        m_atmosphere_changed = 0;
      }
      if ( (v96 & 4) != 0 )
      {
        if ( v100 )
        {
          v60 = &v100->vostok::render::resource_intrusive_base;
          --v100->m_reference_count;
          if ( !v60->m_reference_count )
            vostok::render::resource_manager::release(
              v35,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v100);
        }
      }
      if ( m_atmosphere_changed )
      {
        vostok::render::res_effect::apply(
          (vostok::render::res_effect *)(3 - (LODWORD(v36[1].m_rescale_min.z) != 0)),
          (int)this->m_atmospheric_scattering_effect[v37].m_object);
        sky_clouds_texture = (vostok::render::res_texture **)vostok::render::scene_view::get_sky_clouds_texture(
                                                               (vostok::render::scene_view *)&v100,
                                                               (int)this->m_context->m_scene_view.m_object);
        vostok::render::backend::set_ps_texture(
          v62,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          "sky_clouds_texture",
          *sky_clouds_texture);
        if ( v100 )
        {
          v64 = &v100->vostok::render::resource_intrusive_base;
          --v100->m_reference_count;
          if ( !v64->m_reference_count )
            vostok::render::resource_manager::release(
              v63,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v100);
        }
        v65 = v36[1].m_rescale_max.w;
        v66 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        v67 = v36[1].m_rescale_max.y;
        *(float *)&v68 = v65 * v36[1].m_rescale_min.w;
        *(float *)&v69 = v36[1].m_rescale_max.x * v65;
        p_arg = (unsigned int)&arg;
        v90.m_object = (vostok::render::render_target *)this->m_sky_clouds_parameters0;
        *(_QWORD *)&arg.x = __PAIR64__(v69, v68);
        arg.z = v67 * v65;
        v95 = 0.0;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          (vostok::render::backend *)v63,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::render::shader_constant_host *)v90.m_object,
          &arg);
        v70 = v36[1].m_max_uses_height;
        v71 = v36[1].m_base_format;
        p_arg = (unsigned int)&arg;
        v90.m_object = (vostok::render::render_target *)this->m_sky_clouds_parameters1;
        *(_QWORD *)&arg.x = __PAIR64__(v71, v70);
        arg.z = 0.0;
        v95 = 0.0;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v72,
          (vostok::render::constants_handler<1> *)LODWORD(v66),
          (const vostok::render::shader_constant_host *)v90.m_object,
          &arg);
        *(_QWORD *)&arg.x = __PAIR64__(v103, v105);
        p_arg = (unsigned int)&arg;
        v90.m_object = (vostok::render::render_target *)this->m_to_sun_direction_parameter;
        arg.z = v104;
        v95 = *(float *)&v99;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v73,
          (vostok::render::constants_handler<1> *)LODWORD(v66),
          (const vostok::render::shader_constant_host *)v90.m_object,
          &arg);
        loaded_num_mips = (__m128)v36[1].loaded_num_mips;
        loaded_num_mips.m128_f32[0] = (float)(loaded_num_mips.m128_f32[0] * 0.0055555557) * 3.1415927;
        v107 = loaded_num_mips.m128_f32[0];
        v75 = (__m128i)_mm_cvtps_pd(loaded_num_mips);
        __libm_sse2_sin(v75);
        *(float *)v75.m128i_i32 = *(double *)v75.m128i_i64;
        v106 = v75.m128i_i32[0];
        *(double *)v75.m128i_i64 = v107;
        __libm_sse2_cos(v92);
        v76 = *(float *)&v36[1].streaming_priority;
        *(float *)v75.m128i_i32 = *(double *)v75.m128i_i64;
        *(_QWORD *)&arg.x = __PAIR64__(v106, v75.m128i_u32[0]);
        p_arg = (unsigned int)&arg;
        v77 = this->m_sky_clouds_parameters2;
        arg.z = v76;
        v95 = FLOAT_100000_0;
        vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
          (vostok::render::backend *)LODWORD(v66),
          v77,
          (const unsigned int *)&arg);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v78,
          (vostok::render::constants_handler<1> *)LODWORD(v66),
          this->m_sky_clouds_parameters3,
          (const vostok::math::float3 *)&v36[1].m_streamed);
        vostok::render::sky_dome_geometry::draw(v79, (int)&this->m_clouds_geometry);
      }
      vostok::render::renderer_context::pop_p((vostok::render::renderer_context *)v35, this->m_context);
      vostok::render::backend::reset_render_targets(
        v80,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    }
    if ( this->m_type == atmosphere_on_geometry )
    {
      if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_atmosphere_on_geometry_stage )
        goto LABEL_3;
      v81 = this->m_atmospheric_scattering_effect[0].m_object;
      m_eye_rays = this->m_context->m_eye_rays;
      v81->m_cur_technique = 8;
      vostok::render::res_effect::apply_pass(v5, (int)v81);
      v83 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      *(_QWORD *)&arg.x = __PAIR64__(v103, v105);
      p_arg = (unsigned int)&arg;
      v90.m_object = (vostok::render::render_target *)this->m_to_sun_direction_parameter;
      arg.z = v104;
      v95 = s_bm_current_air_resistance;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v84,
        (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        (const vostok::render::shader_constant_host *)v90.m_object,
        &arg);
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v85,
        (vostok::render::constants_handler<1> *)LODWORD(v83),
        this->m_c_eye_ray_corner,
        m_eye_rays);
      *(_QWORD *)&arg.x = __PAIR64__(LODWORD(s_bm_current_air_resistance), LODWORD(s_spot_max_distance));
      p_arg = (unsigned int)&arg;
      v90.m_object = (vostok::render::render_target *)this->m_c_inscatter_parameters;
      arg.z = 0.0;
      v95 = 0.0;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v86,
        (vostok::render::constants_handler<1> *)LODWORD(v83),
        (const vostok::render::shader_constant_host *)v90.m_object,
        &arg);
      p_arg = 1;
      v90.m_object = 0;
      v89.m_object = v87;
      vostok::render::renderer_context::get_rt(this->m_context, rt_generic_0, &v89);
      vostok::render::stage_atmosphere::fill_surfaces(
        v88,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
        v89.m_object,
        v90.m_object,
        p_arg);
    }
    vostok::render::backend::reset_render_targets(
      (vostok::render::backend *)v5,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  }
LABEL_56:
  D3DPERF_EndEvent();
}
