void __thiscall vostok::render::stage_debug::execute(vostok::render::stage_debug *this)
{
  vostok::render::backend *v2; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  vostok::render::render_target *v4; // eax
  vostok::render::render_surface_instance **m_begin; // ecx
  unsigned int m_reference_count; // esi
  int *v7; // edi
  int v8; // eax
  vostok::render::res_effect *v9; // ecx
  vostok::render::res_geometry *v10; // ecx
  int v11; // eax
  vostok::render::backend *v12; // ecx
  bool v13; // [esp+0h] [ebp-2030h]
  vostok::render::render_target *rt; // [esp+10h] [ebp-2020h] BYREF
  pix_event_wrapper_dx11 wszName[5]; // [esp+17h] [ebp-2019h] BYREF
  vostok::render::render_surface_instance **i; // [esp+1Ch] [ebp-2014h]
  vostok::buffer_vector<vostok::render::render_surface_instance *> v17; // [esp+20h] [ebp-2010h] BYREF
  _BYTE v18[8192]; // [esp+2Ch] [ebp-2004h] BYREF
  char v19; // [esp+202Ch] [ebp-4h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, wszName, (int)L"stage_debug");
  if ( this->is_enabled(this) && this->is_effects_ready(this) )
  {
    vostok::render::backend::flush_rt_shader_resources(
      v2,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    v3 = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_present,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v3->m_object,
      0,
      0,
      0);
    v4 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v4->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v17.m_begin = (vostok::render::render_surface_instance **)v18;
    v17.m_end = (vostok::render::render_surface_instance **)v18;
    v17.m_max_end = (vostok::render::render_surface_instance **)&v19;
    vostok::render::scene::select_models(
      (vostok::render::scene *)&this->m_context->m_vp,
      (int)this->m_context->m_scene,
      &this->m_context->m_vp,
      &this->m_context->m_vp,
      &v17,
      (vostok::math::float4x4 *)&this->m_context->m_view_pos,
      (const vostok::math::float3 *)1,
      0,
      v13);
    m_begin = v17.m_begin;
    rt = (vostok::render::render_target *)v17.m_begin;
    for ( i = v17.m_end; rt != (vostok::render::render_target *)i; rt = (vostok::render::render_target *)((char *)rt + 4) )
    {
      m_reference_count = rt->m_reference_count;
      *(_DWORD *)&wszName[1] = *(_DWORD *)(rt->m_reference_count + 16);
      v7 = (int *)&vostok::render::render_surface::get_material_effects(
                     (vostok::render::render_surface *)m_begin,
                     *(int *)&wszName[1])->m_effects[26];
      if ( *v7 )
      {
        vostok::render::renderer_context::set_w(
          *(const vostok::math::float4x4 **)(m_reference_count + 36),
          this->m_context);
        v8 = *v7;
        *(_DWORD *)(v8 + 22048) = 0;
        vostok::render::res_effect::apply_pass(v9, v8);
        vostok::render::res_geometry::apply(v10, *(_DWORD *)(*(_DWORD *)&wszName[1] + 4));
        v11 = *(_DWORD *)&wszName[1];
        *(float *)(m_reference_count + 32) = this->m_context->m_current_time;
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          3 * *(_DWORD *)(v11 + 24),
          v12,
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          0,
          0);
      }
    }
    vostok::render::stage_debug::render_environment_probe_preview((vostok::render::stage_debug *)m_begin, (int)this);
    v17.m_end = v17.m_begin;
  }
  else
  {
    this->execute_disabled(this);
  }
  D3DPERF_EndEvent();
}
