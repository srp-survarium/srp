void __thiscall vostok::render::stage_postprocess::execute_disabled(vostok::render::stage_postprocess *this)
{
  vostok::render::res_effect *v2; // ecx
  vostok::render::res_effect *m_object; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *t; // eax
  vostok::render::backend *v5; // ecx
  vostok::render::resource_manager *v6; // ecx
  vostok::render::render_target *v8; // ecx
  vostok::math::float4x4 *v9; // ecx
  vostok::math::float4x4 *v10; // eax
  vostok::render::stage_postprocess *v11; // [esp-Ch] [ebp-64h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v12; // [esp-8h] [ebp-60h] BYREF
  vostok::render::render_target *v13; // [esp-4h] [ebp-5Ch]
  pix_event_wrapper_dx11 wszName[5]; // [esp+Fh] [ebp-49h] BYREF
  vostok::math::float3 v15[5]; // [esp+14h] [ebp-44h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, wszName, (int)L"stage_postprocess");
  if ( this->is_effects_ready(this) )
  {
    m_object = this->m_sh_effect_copy_image.m_object;
    m_object->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass(v2, (int)m_object);
    t = vostok::render::renderer_context::get_t(
          this->m_context,
          rt_generic_0,
          (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&wszName[1]);
    vostok::render::backend::set_ps_texture(
      v5,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_base",
      t->m_object);
    if ( *(_DWORD *)&wszName[1] )
    {
      if ( (*(_DWORD *)(*(_DWORD *)&wszName[1] + 4))-- == 1 )
        vostok::render::resource_manager::release(
          v6,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          *(vostok::render::res_texture **)&wszName[1]);
    }
    v13 = (vostok::render::render_target *)v15;
    v12.m_object = (vostok::render::render_target *)this->m_gamma_correction_factor;
    v15[0].x = s_bm_current_air_resistance;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      (vostok::render::backend *)v6,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      (const vostok::render::shader_constant_host *)v12.m_object,
      v15);
    v13 = 0;
    v12.m_object = v8;
    v11 = (vostok::render::stage_postprocess *)v8;
    vostok::render::renderer_context::get_rt(this->m_context, rt_present, &v12);
    vostok::render::stage_postprocess::fill_surface(
      v11,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
      v12.m_object,
      v13);
    v10 = vostok::math::float4x4::identity(v9, (vostok::math::float4x4 *)&v15[0].elements[1]);
    vostok::render::renderer_context::set_w(v10, this->m_context);
    qmemcpy(&this->m_prev_view_matrix, &this->m_context->m_v, sizeof(this->m_prev_view_matrix));
  }
  D3DPERF_EndEvent();
}
