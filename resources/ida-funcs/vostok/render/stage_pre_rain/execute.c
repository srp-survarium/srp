void __thiscall vostok::render::stage_pre_rain::execute(vostok::render::stage_pre_rain *this)
{
  vostok::render::renderer_context *m_context; // eax
  vostok::render::base_scene_view *v3; // ecx
  long double v4; // rdi
  float v5; // xmm0_4
  vostok::render::backend *v6; // ecx
  double v7; // st7
  vostok::render::stage_pre_rain *v8; // ecx
  vostok::render::res_effect *v9; // ecx
  vostok::render::res_effect *m_object; // eax
  vostok::render::system_renderer *v11; // esi
  vostok::render::render_target *v12; // ecx
  vostok::render::render_target *v13; // ecx
  vostok::render::backend *v14; // ecx
  vostok::render::res_effect *v15; // eax
  vostok::render::res_effect *v16; // ecx
  float z; // esi
  vostok::render::backend *v18; // ecx
  vostok::math::float4x4 *v19; // eax
  vostok::render::backend *v20; // ecx
  vostok::render::backend *v21; // ecx
  vostok::render::backend *v22; // ecx
  vostok::render::system_renderer *v23; // esi
  vostok::render::render_target *v24; // ecx
  vostok::render::render_target *v25; // ecx
  vostok::math::float4x4 *v26; // eax
  float v27; // esi
  vostok::render::backend *v28; // ecx
  int v29; // ecx
  bool v30; // zf
  vostok::render::system_renderer *v31; // [esp-18h] [ebp-ACh]
  vostok::render::system_renderer *v32; // [esp-18h] [ebp-ACh]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v33; // [esp-14h] [ebp-A8h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v34; // [esp-10h] [ebp-A4h] BYREF
  vostok::render::render_target *v35; // [esp-Ch] [ebp-A0h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v36; // [esp-8h] [ebp-9Ch]
  vostok::render::render_target *v37; // [esp-4h] [ebp-98h]
  int v38; // [esp+0h] [ebp-94h]
  float v39; // [esp+4h] [ebp-90h]
  float v40; // [esp+8h] [ebp-8Ch]
  float v41; // [esp+Ch] [ebp-88h]
  float v42; // [esp+10h] [ebp-84h] BYREF
  vostok::math::float4x4 wszName_1; // [esp+14h] [ebp-80h] BYREF
  vostok::math::float4x4 v44; // [esp+54h] [ebp-40h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&v42 + 3,
    (int)L"stage_rain");
  if ( this->is_effects_ready(this) )
  {
    if ( this->is_enabled(this)
      && (m_context = this->m_context, LOBYTE(m_context->m_scene_view.m_object[2].grm_satisfaction_tree_hook.left_))
      && vostok::quasi_singleton<vostok::render::options>::pinst->current.m_pre_rain_normal_modify_render_stage
      && (v3 = m_context->m_scene_view.m_object, byte_10E2C[(_DWORD)v3])
      && (HIDWORD(v4) = 2, v3[4].type != 2) )
    {
      v5 = (float)(m_context->m_time_delta * 2.0) + this->m_rain_offset_counter;
      LODWORD(v4) = &s_random;
      *(float *)&v38 = 0.5;
      this->m_rain_offset_counter = v5;
      if ( this->m_rain_offset_counter >= vostok::math::random32::random_f(&s_random, *(const float *)&v38)
                                        + s_bm_current_air_resistance )
      {
        v7 = vostok::math::random32::random_f(&s_random, 0.75) + this->m_rain_offset;
        this->m_rain_offset_counter = 0.0;
        this->m_rain_offset = v7;
      }
      vostok::render::backend::flush_rt_shader_resources(
        v6,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      vostok::render::stage_pre_rain::render_rain_shadow_map(v8, v4, (vostok::math::float4x4 *)this, &wszName_1);
      if ( s_rain_debug1 )
      {
        m_object = this->m_wet_surface_effect.m_object;
        m_object->m_cur_technique = 2;
        vostok::render::res_effect::apply_pass(v9, (int)m_object);
        v11 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
        v38 = 1;
        v37 = 0;
        v36.m_object = 0;
        v34.m_object = v12;
        v35 = 0;
        vostok::render::renderer_context::get_rt(this->m_context, rt_parameters_copy, &v34);
        v33.m_object = v13;
        v31 = (vostok::render::system_renderer *)v13;
        vostok::render::renderer_context::get_rt(this->m_context, rt_normal_copy, &v33);
        vostok::render::system_renderer::fill_surface(
          v31,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v11,
          v33.m_object,
          v34.m_object,
          v35,
          v36,
          v37,
          (D3D11_VIEWPORT *)v38,
          v39,
          v40,
          v41,
          v42);
        vostok::render::backend::flush_rt_shader_resources(
          v14,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
        v15 = this->m_wet_surface_effect.m_object;
        v15->m_cur_technique = 0;
        vostok::render::res_effect::apply_pass(v16, (int)v15);
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v18,
          (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          this->m_eye_ray_corner_parameter,
          this->m_context->m_eye_rays);
        v19 = vostok::math::transpose(&wszName_1, &v44);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v20,
          (vostok::render::constants_handler<1> *)LODWORD(z),
          this->m_view_to_shadow_parameter,
          (const vostok::math::float3 *)v19);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v21,
          (vostok::render::constants_handler<1> *)LODWORD(z),
          this->m_rain_offset_parameter,
          (const vostok::math::float3 *)&this->m_rain_offset);
        vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
          v22,
          (vostok::render::constants_handler<1> *)LODWORD(z),
          this->m_rain_density_parameter,
          (const vostok::math::float3 *)&this->m_context->m_scene_view.m_object[2].grm_satisfaction_tree_hook.right_);
        v23 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
        v38 = 1;
        v37 = 0;
        v36.m_object = 0;
        v34.m_object = v24;
        v35 = 0;
        vostok::render::renderer_context::get_rt(this->m_context, rt_surface_parameters, &v34);
        v33.m_object = v25;
        v32 = (vostok::render::system_renderer *)v25;
        vostok::render::renderer_context::get_rt(this->m_context, rt_normal, &v33);
        vostok::render::system_renderer::fill_surface(
          v32,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v23,
          v33.m_object,
          v34.m_object,
          v35,
          v36,
          v37,
          (D3D11_VIEWPORT *)v38,
          v39,
          v40,
          v41,
          v42);
      }
      qmemcpy(&this->m_renderer->m_view_to_rain_shadow, &wszName_1, sizeof(this->m_renderer->m_view_to_rain_shadow));
      v26 = vostok::math::float4x4::identity(0, &v44);
      vostok::render::renderer_context::set_w(v26, this->m_context);
      v27 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::reset_render_targets(
        v28,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      v29 = *(_DWORD *)(LODWORD(v27) + 7440);
      v30 = *(_DWORD *)(LODWORD(v27) + 7384) == v29;
      *(_DWORD *)(LODWORD(v27) + 7384) = v29;
      *(_BYTE *)(LODWORD(v27) + 117) |= !v30;
    }
    else
    {
      this->execute_disabled(this);
    }
  }
  D3DPERF_EndEvent();
}
