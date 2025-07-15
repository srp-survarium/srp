void __thiscall vostok::render::stage_postprocess::accumulate_motion_vectors(
        vostok::render::stage_postprocess *this,
        int rt)
{
  float z; // eax
  int v3; // ebx
  int v4; // edi
  bool v5; // zf
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // eax
  _DWORD *v7; // eax
  vostok::render::renderer_context *v8; // ecx
  _DWORD *v9; // eax
  vostok::render::backend *v10; // ecx
  _DWORD *v11; // eax
  int v12; // eax
  const vostok::buffer_vector<vostok::render::render_surface_instance *> *v13; // esi
  void *v14; // esp
  const stlp_std::random_access_iterator_tag *v15; // ecx
  void *v16; // esp
  const stlp_std::random_access_iterator_tag *v17; // ecx
  vostok::buffer_vector<vostok::render::render_surface_instance *> *v18; // ecx
  vostok::render::render_surface_instance **i; // edi
  vostok::render::renderer *v20; // ecx
  vostok::render::renderer *v21; // ecx
  vostok::render::backend *v22; // ecx
  vostok::render::render_surface_instance *v23[3]; // [esp+0h] [ebp-5Ch] BYREF
  D3D11_VIEWPORT v24; // [esp+Ch] [ebp-50h] BYREF
  D3D11_VIEWPORT v25; // [esp+24h] [ebp-38h] BYREF
  vostok::buffer_vector<vostok::render::render_surface_instance *> __first; // [esp+3Ch] [ebp-20h] BYREF
  vostok::buffer_vector<vostok::render::ambient_light *> v27; // [esp+48h] [ebp-14h] BYREF
  vostok::render::ambient_light **end[2]; // [esp+54h] [ebp-8h] BYREF

  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v3 = rt;
  v4 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7440);
  v5 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == v4;
  *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) = v4;
  *(_BYTE *)(LODWORD(z) + 117) |= !v5;
  v6 = vostok::render::renderer_context::get_rt(
         *(vostok::render::renderer_context **)(v3 + 4),
         rt_object_motion_vectors,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v6->m_object,
    0,
    0,
    0);
  v7 = (_DWORD *)rt;
  if ( rt )
  {
    --*(_DWORD *)rt;
    if ( !*v7 )
      vostok::render::resource_manager::release(
        (vostok::render::render_target *)rt,
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  qmemcpy(
    (void *)&v24,
    (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
    sizeof(v24));
  v8 = *(vostok::render::renderer_context **)(v3 + 4);
  v25.TopLeftX = 0.0;
  v25.TopLeftY = 0.0;
  end[0] = (vostok::render::ambient_light **)vostok::render::renderer_context::get_rt(
                                               v8,
                                               rt_object_motion_vectors,
                                               (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt)->m_object->m_width;
  v9 = (_DWORD *)rt;
  v25.Width = (float)(unsigned int)end[0];
  if ( rt )
  {
    --*(_DWORD *)rt;
    if ( !*v9 )
      vostok::render::resource_manager::release(
        (vostok::render::render_target *)rt,
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  end[0] = (vostok::render::ambient_light **)vostok::render::renderer_context::get_rt(
                                               *(vostok::render::renderer_context **)(v3 + 4),
                                               rt_object_motion_vectors,
                                               (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt)->m_object->m_height;
  v11 = (_DWORD *)rt;
  v25.Height = (float)(unsigned int)end[0];
  if ( rt )
  {
    --*(_DWORD *)rt;
    if ( !*v11 )
      vostok::render::resource_manager::release(
        (vostok::render::render_target *)rt,
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  v25.MinDepth = 0.0;
  v25.MaxDepth = s_bm_current_air_resistance;
  vostok::render::backend::set_viewports(
    v10,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    &v25,
    (const D3D11_VIEWPORT *)v23[0]);
  v12 = *(_DWORD *)(*(_DWORD *)(v3 + 4) + 16268);
  v13 = (const vostok::buffer_vector<vostok::render::render_surface_instance *> *)(v12 + 1164);
  rt = ((*(_DWORD *)(v12 + 1168) - *(_DWORD *)(v12 + 1164)) >> 2)
     + ((*(_DWORD *)(v12 + 17576) - *(_DWORD *)(v12 + 17572)) >> 2);
  v14 = alloca(4 * rt);
  vostok::buffer_vector<vostok::render::render_surface_instance *>::buffer_vector<vostok::render::render_surface_instance *>(
    v23,
    (const vostok::buffer_vector<vostok::render::render_surface_instance *> *)(v12 + 17572),
    &__first,
    rt);
  LOBYTE(rt) = 1;
  end[0] = (vostok::render::ambient_light **)__first.m_end;
  rt = (int)stlp_std::remove_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_skeletal_filter_predicate>(
              __first.m_begin,
              v15,
              __first.m_end,
              (vostok::render::remove_model_skeletal_filter_predicate)1);
  vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
    (vostok::buffer_vector<vostok::render::ambient_light *> *)&__first,
    (vostok::render::ambient_light ***)&rt,
    end);
  v16 = alloca(4 * (v13->m_end - v13->m_begin));
  vostok::buffer_vector<vostok::render::render_surface_instance *>::buffer_vector<vostok::render::render_surface_instance *>(
    v23,
    v13,
    (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v27,
    v13->m_end - v13->m_begin);
  LOBYTE(rt) = 0;
  end[0] = v27.m_end;
  rt = (int)stlp_std::remove_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_skeletal_filter_predicate>(
              (vostok::render::render_surface_instance **)v27.m_begin,
              v17,
              (vostok::render::render_surface_instance **)v27.m_end,
              0);
  vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
    &v27,
    (vostok::render::ambient_light ***)&rt,
    end);
  for ( i = (vostok::render::render_surface_instance **)v27.m_begin;
        i != (vostok::render::render_surface_instance **)v27.m_end;
        ++i )
  {
    vostok::buffer_vector<vostok::render::render_surface_instance *>::push_back(v18, (int)&__first, i);
  }
  vostok::render::stage_postprocess::render_models(&__first, (vostok::render::stage_postprocess *)v3, 0);
  vostok::render::renderer::foreground_begin(v20, *(_DWORD *)(v3 + 8));
  vostok::render::stage_postprocess::render_models(&__first, (vostok::render::stage_postprocess *)v3, 1);
  vostok::render::renderer::foreground_end(v21, *(_DWORD *)(v3 + 8));
  vostok::render::backend::set_viewports(
    v22,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    &v24,
    (const D3D11_VIEWPORT *)v23[0]);
}
