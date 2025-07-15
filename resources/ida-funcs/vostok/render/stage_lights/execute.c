void __thiscall vostok::render::stage_lights::execute(vostok::render::stage_lights *this)
{
  vostok::math::float4x4 *v2; // ecx
  vostok::math::float4x4 *v3; // eax
  vostok::render::render_target *m_object; // esi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // eax
  float v6; // esi
  _DWORD *v7; // eax
  vostok::render::render_target *v8; // eax
  vostok::render::stage_lights *v9; // ecx
  bool v10; // zf
  int **p_type; // esi
  int *i; // ebx
  vostok::render::light *v13; // edx
  _BYTE *v14; // eax
  vostok::math::float4x4 *v15; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v16; // eax
  vostok::render::stage_lights *v17; // ecx
  vostok::render::render_target *v18; // eax
  vostok::render::stage_lights *v19; // ecx
  vostok::math::float4x4 *v20; // ecx
  vostok::math::float4x4 *v21; // eax
  float z; // esi
  vostok::render::backend *v23; // ecx
  int v24; // ecx
  const vostok::render::render_target *v25; // [esp-Ch] [ebp-64h]
  pix_event_wrapper_dx11 wszName[5]; // [esp+Fh] [ebp-49h] BYREF
  vostok::render::render_target *rt; // [esp+14h] [ebp-44h] BYREF
  vostok::math::float4x4 v28; // [esp+18h] [ebp-40h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, wszName, (int)L"stage_lights");
  if ( this->is_effects_ready(this) )
  {
    if ( !this->is_enabled(this) )
    {
LABEL_3:
      this->execute_disabled(this);
      goto LABEL_26;
    }
    if ( this->m_is_forward_lighting_pass )
    {
      if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_lighting_stage )
        goto LABEL_3;
      v16 = vostok::render::renderer_context::get_rt(
              this->m_context,
              rt_generic_0,
              (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
      vostok::render::backend::set_render_targets(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        v16->m_object,
        0,
        0,
        0);
      v18 = rt;
      if ( rt )
      {
        --rt->m_reference_count;
        if ( !v18->m_reference_count )
          vostok::render::resource_manager::release(
            rt,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      }
      vostok::render::stage_lights::render_forward_lighting(v17, (vostok::render::backend *)this, 0);
      vostok::render::stage_lights::accumulate_particle_lighting(
        v19,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this,
        vostok::quasi_singleton<vostok::render::options>::pinst->current.m_particles_quality != 2);
      v21 = vostok::math::float4x4::identity(v20, &v28);
      vostok::render::renderer_context::set_w(v21, this->m_context);
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::reset_render_targets(
        v23,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      v24 = *(_DWORD *)(LODWORD(z) + 7440);
      v10 = *(_DWORD *)(LODWORD(z) + 7384) == v24;
      *(_DWORD *)(LODWORD(z) + 7384) = v24;
      *(_BYTE *)(LODWORD(z) + 117) |= !v10;
    }
    else
    {
      if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_deferred_lighting_stage )
        goto LABEL_3;
      v3 = vostok::math::float4x4::identity(v2, &v28);
      vostok::render::renderer_context::set_w(v3, this->m_context);
      m_object = vostok::render::renderer_context::get_rt(
                   this->m_context,
                   rt_accumulator_specular,
                   (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt)->m_object;
      v5 = vostok::render::renderer_context::get_rt(
             this->m_context,
             rt_accumulator_diffuse,
             (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&wszName[1]);
      v25 = m_object;
      v6 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::set_render_targets(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        v5->m_object,
        v25,
        0,
        0);
      v7 = *(_DWORD **)&wszName[1];
      if ( *(_DWORD *)&wszName[1] )
      {
        --**(_DWORD **)&wszName[1];
        if ( !*v7 )
        {
          vostok::render::resource_manager::release(
            *(vostok::render::render_target **)&wszName[1],
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
          v6 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        }
      }
      v8 = rt;
      if ( rt )
      {
        --rt->m_reference_count;
        if ( !v8->m_reference_count )
        {
          vostok::render::resource_manager::release(
            rt,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
          v6 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        }
      }
      v9 = *(vostok::render::stage_lights **)(LODWORD(v6) + 7440);
      v10 = *(_DWORD *)(LODWORD(v6) + 7384) == (_DWORD)v9;
      *(_DWORD *)(LODWORD(v6) + 7384) = v9;
      *(_BYTE *)(LODWORD(v6) + 117) |= !v10;
      p_type = (int **)&this->m_context->m_scene_view.m_object[158].type;
      for ( i = *p_type; i != p_type[1]; ++i )
      {
        if ( (!vostok::render::light::is_occluded((vostok::render::light *)v9, *i) || v13->m_force_refresh)
          && v13->m_enabled )
        {
          vostok::render::stage_lights::render_light(v9, (vostok::render::res_geometry *)this, v13);
          v14 = (_BYTE *)(*i + 680);
          if ( *v14 )
            *v14 = 0;
        }
      }
      v15 = vostok::math::float4x4::identity((vostok::math::float4x4 *)v9, &v28);
      vostok::render::renderer_context::set_w(v15, this->m_context);
    }
  }
LABEL_26:
  D3DPERF_EndEvent();
}
