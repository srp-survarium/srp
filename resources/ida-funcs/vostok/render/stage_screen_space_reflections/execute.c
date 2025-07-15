void __thiscall vostok::render::stage_screen_space_reflections::execute(
        vostok::render::stage_screen_space_reflections *this)
{
  const vostok::buffer_vector<vostok::render::render_surface_instance *> *m_object; // esi
  vostok::render::render_surface_instance **m_begin; // edi
  unsigned int v4; // edi
  void *v5; // esp
  vostok::render::render_surface_instance **m_end; // esi
  vostok::render::render_surface *v7; // ecx
  vostok::render::res_texture *v8; // eax
  vostok::render::render_surface *v9; // ecx
  vostok::render::render_surface_instance **v10; // edi
  vostok::render::render_surface_instance *v11; // esi
  vostok::render::res_texture *v12; // eax
  vostok::render::backend *v13; // ecx
  ID3D11DeviceContext *m_context; // esi
  ID3D11Resource *m_surface; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *t; // eax
  vostok::render::resource_manager *v17; // ecx
  bool v18; // zf
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *rt; // eax
  float z; // esi
  vostok::render::res_texture *v21; // eax
  int v22; // edi
  vostok::render::renderer *v23; // ecx
  vostok::render::renderer *v24; // ecx
  vostok::render::render_surface *v25; // [esp-4h] [ebp-2Ch]
  vostok::render::render_surface_instance *v26; // [esp+0h] [ebp-28h] BYREF
  vostok::buffer_vector<vostok::render::render_surface_instance *> __first; // [esp+Ch] [ebp-1Ch] BYREF
  vostok::render::ambient_light **end; // [esp+18h] [ebp-10h] BYREF
  vostok::render::remove_inappropriate_models_predicate __pred[4]; // [esp+1Ch] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v30; // [esp+20h] [ebp-8h] BYREF
  wchar_t wszName; // [esp+27h] [ebp-1h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&wszName,
    (int)L"stage_composition");
  if ( this->is_effects_ready(this) )
  {
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_ssr_stage && this->is_enabled(this) )
    {
      m_object = (const vostok::buffer_vector<vostok::render::render_surface_instance *> *)this->m_context->m_scene_view.m_object;
      m_begin = m_object[781].m_begin;
      m_object = (const vostok::buffer_vector<vostok::render::render_surface_instance *> *)((char *)m_object + 9368);
      v4 = m_begin - m_object->m_begin;
      v5 = alloca(4 * v4);
      vostok::buffer_vector<vostok::render::render_surface_instance *>::buffer_vector<vostok::render::render_surface_instance *>(
        &v26,
        m_object,
        &__first,
        v4);
      m_end = __first.m_end;
      __pred[0] = 0;
      v25 = *(vostok::render::render_surface **)__pred;
      end = (vostok::render::ambient_light **)__first.m_end;
      v8 = (vostok::render::res_texture *)stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_inappropriate_models_predicate>(
                                            __first.m_begin,
                                            v7,
                                            __first.m_end);
      v9 = v25;
      if ( v8 != (vostok::render::res_texture *)m_end )
      {
        v10 = (vostok::render::render_surface_instance **)&v8->vostok::render::resource_intrusive_base;
        v30.m_object = v8;
        if ( &v8->vostok::render::resource_intrusive_base != (vostok::render::resource_intrusive_base *)m_end )
        {
          do
          {
            v11 = *v10;
            if ( !vostok::render::remove_inappropriate_models_predicate::operator()(*v10, v9) )
            {
              v12 = v30.m_object;
              v30.m_object = (vostok::render::res_texture *)((char *)v30.m_object + 4);
              v12->__vftable = (vostok::render::res_texture_vtbl *)v11;
            }
            ++v10;
          }
          while ( v10 != __first.m_end );
        }
        v8 = v30.m_object;
      }
      *(_DWORD *)__pred = v8;
      vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
        (vostok::buffer_vector<vostok::render::ambient_light *> *)&__first,
        (vostok::render::ambient_light ***)__pred,
        &end);
      if ( __first.m_begin != __first.m_end )
      {
        m_context = vostok::quasi_singleton<vostok::render::device>::pinst->m_context;
        m_surface = vostok::render::renderer_context::get_t(
                      this->m_context,
                      rt_generic_0,
                      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__pred)->m_object->m_surface;
        t = vostok::render::renderer_context::get_t(this->m_context, rt_generic_1, &v30);
        m_context->CopyResource(m_context, t->m_object->m_surface, m_surface);
        if ( v30.m_object )
        {
          v18 = v30.m_object->m_reference_count-- == 1;
          if ( v18 )
            vostok::render::resource_manager::release(
              v17,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v30.m_object);
        }
        if ( *(_DWORD *)__pred )
        {
          v18 = (*(_DWORD *)(*(_DWORD *)__pred + 4))-- == 1;
          if ( v18 )
            vostok::render::resource_manager::release(
              v17,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              *(vostok::render::res_texture **)__pred);
        }
        vostok::render::stage_screen_space_reflections::accumulate_models_local_reflections(
          (vostok::render::stage_screen_space_reflections *)v17,
          (const vostok::buffer_vector<vostok::render::render_surface_instance *> *)this,
          (int **)&__first);
        rt = vostok::render::renderer_context::get_rt(
               this->m_context,
               rt_generic_0,
               (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__pred);
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
        vostok::render::backend::set_render_targets(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          rt->m_object,
          0,
          0,
          0);
        v21 = *(vostok::render::res_texture **)__pred;
        if ( *(_DWORD *)__pred )
        {
          --**(_DWORD **)__pred;
          if ( !v21->__vftable )
          {
            vostok::render::resource_manager::release(
              *(vostok::render::render_target **)__pred,
              vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
            z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          }
        }
        v22 = *(_DWORD *)(LODWORD(z) + 7440);
        *(_BYTE *)(LODWORD(z) + 117) |= *(_DWORD *)(LODWORD(z) + 7384) != v22;
        *(_DWORD *)(LODWORD(z) + 7384) = v22;
        vostok::render::stage_screen_space_reflections::render_models_with_reflections(&__first, this, 0);
        vostok::render::renderer::foreground_begin(v23, (int)this->m_renderer);
        vostok::render::stage_screen_space_reflections::render_models_with_reflections(&__first, this, 1);
        vostok::render::renderer::foreground_end(v24, (int)this->m_renderer);
      }
      vostok::render::backend::reset_render_targets(
        v13,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    }
    else
    {
      this->execute_disabled(this);
    }
  }
  D3DPERF_EndEvent();
}
