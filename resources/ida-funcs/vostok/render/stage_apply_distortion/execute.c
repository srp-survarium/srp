void __thiscall vostok::render::stage_apply_distortion::execute(vostok::render::stage_apply_distortion *this)
{
  vostok::render::res_effect *v2; // ecx
  vostok::render::res_effect *m_object; // eax
  vostok::render::system_renderer *v4; // edi
  vostok::render::render_target *v5; // ecx
  vostok::render::res_effect *v6; // eax
  vostok::render::res_effect *v7; // ecx
  vostok::render::system_renderer *v8; // edi
  vostok::render::render_target *v9; // ecx
  float z; // esi
  vostok::render::backend *v11; // ecx
  int v12; // ecx
  bool v13; // zf
  vostok::render::system_renderer *v14; // [esp-1Ch] [ebp-2Ch]
  vostok::render::system_renderer *v15; // [esp-1Ch] [ebp-2Ch]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v16; // [esp-18h] [ebp-28h] BYREF
  vostok::render::render_target *v17; // [esp-14h] [ebp-24h]
  vostok::render::render_target *v18; // [esp-10h] [ebp-20h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v19; // [esp-Ch] [ebp-1Ch]
  vostok::render::render_target *v20; // [esp-8h] [ebp-18h]
  int v21; // [esp-4h] [ebp-14h]
  float v22; // [esp+0h] [ebp-10h]
  float v23; // [esp+4h] [ebp-Ch]
  float v24; // [esp+8h] [ebp-8h]
  float v25; // [esp+Ch] [ebp-4h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&v25 + 3,
    (int)L"stage_apply_distortion");
  if ( this->is_effects_ready(this) )
  {
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_apply_distortion_stage
      && this->is_enabled(this) )
    {
      m_object = this->m_olta_effect.m_object;
      m_object->m_cur_technique = 0;
      vostok::render::res_effect::apply_pass(v2, (int)m_object);
      v21 = 1;
      v4 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
      v20 = 0;
      v19.m_object = 0;
      v18 = 0;
      v16.m_object = v5;
      v17 = 0;
      v14 = (vostok::render::system_renderer *)v5;
      vostok::render::renderer_context::get_rt(this->m_context, rt_generic_1, &v16);
      vostok::render::system_renderer::fill_surface(
        v14,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v4,
        v16.m_object,
        v17,
        v18,
        v19,
        v20,
        (D3D11_VIEWPORT *)v21,
        v22,
        v23,
        v24,
        v25);
      v6 = this->m_sh_apply_distortion.m_object;
      v6->m_cur_technique = 1;
      vostok::render::res_effect::apply_pass(v7, (int)v6);
      v21 = 1;
      v8 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
      v20 = 0;
      v19.m_object = 0;
      v18 = 0;
      v16.m_object = v9;
      v17 = 0;
      v15 = (vostok::render::system_renderer *)v9;
      vostok::render::renderer_context::get_rt(this->m_context, rt_generic_0, &v16);
      vostok::render::system_renderer::fill_surface(
        v15,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v8,
        v16.m_object,
        v17,
        v18,
        v19,
        v20,
        (D3D11_VIEWPORT *)v21,
        v22,
        v23,
        v24,
        v25);
      z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      vostok::render::backend::reset_render_targets(
        v11,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
      v12 = *(_DWORD *)(LODWORD(z) + 7440);
      v13 = *(_DWORD *)(LODWORD(z) + 7384) == v12;
      *(_DWORD *)(LODWORD(z) + 7384) = v12;
      *(_BYTE *)(LODWORD(z) + 117) |= !v13;
    }
    else
    {
      this->execute_disabled(this);
    }
  }
  D3DPERF_EndEvent();
}
