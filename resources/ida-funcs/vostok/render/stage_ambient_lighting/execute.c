void __thiscall vostok::render::stage_ambient_lighting::execute(vostok::render::stage_ambient_lighting *this)
{
  float z; // eax
  int v3; // edi
  vostok::render::stage_ambient_lighting *v4; // ecx
  bool v5; // zf
  vostok::render::stage_ambient_lighting *v6; // ecx
  vostok::render::stage_ambient_lighting *v7; // ecx
  vostok::render::stage_ambient_lighting *v8; // ecx
  vostok::render::stage_ambient_lighting *v9; // ecx
  float v10; // esi
  vostok::render::backend *v11; // ecx
  int v12; // ecx
  wchar_t wszName[2]; // [esp+Fh] [ebp-1h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)wszName,
    (int)L"stage_ambient_lighting");
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_ambient_lighting_stage
    && this->is_enabled(this)
    && this->is_effects_ready(this) )
  {
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    v3 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7440);
    v4 = (vostok::render::stage_ambient_lighting *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                                  + 7384);
    v5 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == v3;
    *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) = v3;
    *(_BYTE *)(LODWORD(z) + 117) |= !v5;
    if ( this->m_probes_generating )
      vostok::render::stage_ambient_lighting::render_skylight(v4, (int)this);
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(
      (pix_event_wrapper_dx11 *)v4,
      (pix_event_wrapper_dx11 *)wszName,
      (int)L"render_sky_ambient_occlusion");
    D3DPERF_EndEvent();
    vostok::render::stage_ambient_lighting::render_ambient_volumes(
      v6,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this);
    vostok::render::stage_ambient_lighting::render_environment_probes(
      v7,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this);
    vostok::render::stage_ambient_lighting::apply_ssao_and_height_based_ambient(v8, (int)this);
    vostok::render::stage_ambient_lighting::render_ambient_lights(
      v9,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)this);
    v10 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::reset_render_targets(
      v11,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    v12 = *(_DWORD *)(LODWORD(v10) + 7440);
    v5 = *(_DWORD *)(LODWORD(v10) + 7384) == v12;
    *(_DWORD *)(LODWORD(v10) + 7384) = v12;
    *(_BYTE *)(LODWORD(v10) + 117) |= !v5;
  }
  else
  {
    this->execute_disabled(this);
  }
  D3DPERF_EndEvent();
}
