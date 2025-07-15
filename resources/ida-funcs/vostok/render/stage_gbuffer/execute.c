void __thiscall vostok::render::stage_gbuffer::execute(vostok::render::stage_gbuffer *this)
{
  float z; // eax
  int v3; // edi
  bool v4; // zf
  const vostok::buffer_vector<vostok::render::render_surface_instance *> *m_object; // esi
  vostok::render::render_surface_instance **m_max_end; // edi
  unsigned int v7; // edi
  void *v8; // esp
  vostok::render::remove_model_if_predicate v9; // xmm0_4
  void *v10; // esp
  vostok::render::renderer *v11; // ecx
  vostok::command_line::key *v12; // ecx
  vostok::render::stage_gbuffer *v13; // ecx
  vostok::render::stage_gbuffer *v14; // ecx
  vostok::render::render_target *v15; // edi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v16; // eax
  vostok::render::renderer_context *m_context; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v18; // eax
  vostok::render::renderer *v19; // ecx
  vostok::render::render_target *v20; // eax
  vostok::render::ambient_light **v21; // eax
  float m_screen_factor; // eax
  vostok::render::renderer *v23; // ecx
  vostok::render::stage_gbuffer *v24; // ecx
  vostok::render::stage_gbuffer *v25; // ecx
  vostok::render::res_effect *v26; // ecx
  vostok::render::res_effect *v27; // eax
  vostok::render::backend *v28; // ecx
  pix_event_wrapper_dx11 *v29; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v30; // eax
  float v31; // eax
  int v32; // eax
  vostok::render::backend *v33; // ecx
  int z_low; // eax
  vostok::render::backend *v35; // ecx
  vostok::render::backend **v36; // edi
  vostok::render::render_surface *m_flags; // ecx
  vostok::resources::vfs_sub_fat_resource *v38; // eax
  vostok::render::render_surface_vtbl *v39; // edi
  vostok::render::res_effect *v40; // eax
  vostok::render::res_effect *v41; // ecx
  vostok::render::res_geometry *v42; // ecx
  vostok::render::backend *v43; // ecx
  float v44; // esi
  int v45; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v46; // [esp+4h] [ebp-850h] BYREF
  unsigned int v47; // [esp+8h] [ebp-84Ch]
  vostok::memory::base_allocator *v48; // [esp+Ch] [ebp-848h] BYREF
  bool v49; // [esp+10h] [ebp-844h]
  _BYTE *v50; // [esp+18h] [ebp-83Ch]
  _BYTE *v51; // [esp+1Ch] [ebp-838h]
  vostok::render::sort_surfaces_predicate_entry *v52; // [esp+20h] [ebp-834h]
  _BYTE v53[2048]; // [esp+24h] [ebp-830h] BYREF
  vostok::render::sort_surfaces_predicate_entry v54; // [esp+824h] [ebp-30h] BYREF
  const vostok::render::render_target *v55; // [esp+83Ch] [ebp-18h]
  vostok::render::ambient_light **end; // [esp+840h] [ebp-14h] BYREF
  vostok::render::render_target *rt; // [esp+844h] [ebp-10h] BYREF
  pix_event_wrapper_dx11 wszName[5]; // [esp+84Bh] [ebp-9h] BYREF
  vostok::render::remove_model_if_predicate __pred; // [esp+850h] [ebp-4h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, wszName, (int)L"stage_gbuffer");
  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_g_stage
    && this->is_enabled(this)
    && this->is_effects_ready(this) )
  {
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    v3 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7440);
    v4 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == v3;
    *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) = v3;
    *(_BYTE *)(LODWORD(z) + 117) |= !v4;
    *(_BYTE *)(LODWORD(z) + 7591) = s_debug_profile_dip;
    *(_BYTE *)(LODWORD(z) + 7590) = 1;
    m_object = (const vostok::buffer_vector<vostok::render::render_surface_instance *> *)this->m_context->m_scene_view.m_object;
    m_max_end = m_object[1464].m_max_end;
    m_object = (const vostok::buffer_vector<vostok::render::render_surface_instance *> *)((char *)m_object + 17572);
    v7 = m_max_end - m_object->m_begin;
    v8 = alloca(4 * v7);
    vostok::buffer_vector<vostok::render::render_surface_instance *>::buffer_vector<vostok::render::render_surface_instance *>(
      (vostok::render::render_surface_instance **)&v48,
      m_object,
      (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v54.ps,
      v7);
    v9.m_screen_factor = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_gbuffer_min_screen_factor;
    end = (vostok::render::ambient_light **)LODWORD(v54.distance);
    if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_shading_quality )
      v9.m_screen_factor = v9.m_screen_factor * 0.5;
    __pred.m_screen_factor = v9.m_screen_factor;
    LODWORD(__pred.m_screen_factor) = (vostok::render::remove_model_if_predicate)stlp_std::remove_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_if_predicate>(
                                                                                   (vostok::render::render_surface_instance **)v54.ps,
                                                                                   (vostok::render::render_surface_instance *)LODWORD(v54.distance),
                                                                                   v9.m_screen_factor,
                                                                                   (vostok::render::render_surface_instance **)LODWORD(v54.distance),
                                                                                   v9);
    vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
      (vostok::buffer_vector<vostok::render::ambient_light *> *)&v54.ps,
      (vostok::render::ambient_light ***)&__pred,
      &end);
    v10 = alloca(4 * ((signed int)(LODWORD(v54.distance) - (unsigned int)v54.ps) >> 2));
    vostok::buffer_vector<vostok::render::render_surface_instance *>::buffer_vector<vostok::render::render_surface_instance *>(
      (vostok::render::render_surface_instance **)&v48,
      (const vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v54.ps,
      (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v54,
      (signed int)(LODWORD(v54.distance) - (unsigned int)v54.ps) >> 2);
    v50 = v53;
    v51 = v53;
    v52 = &v54;
    *(_DWORD *)&wszName[1] = 0;
    vostok::render::renderer::sort_models(v11, &v54, 1u, 1, v48, v49);
    if ( vostok::command_line::key::is_set(v12, (int)&s_z_only_1) )
    {
      vostok::render::backend::set_render_targets(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        0,
        0,
        0,
        0);
      vostok::render::stage_gbuffer::render_grass(v13, (bool)v48);
      vostok::render::stage_gbuffer::render_particles(v14, (int)this);
      vostok::render::stage_gbuffer::render_models(
        (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v54,
        this,
        (unsigned int *)&wszName[1],
        1,
        0);
    }
    v15 = vostok::render::renderer_context::get_rt(
            this->m_context,
            rt_surface_parameters,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&__pred)->m_object;
    v16 = vostok::render::renderer_context::get_rt(
            this->m_context,
            rt_albedo,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&end);
    m_context = this->m_context;
    v55 = v16->m_object;
    v18 = vostok::render::renderer_context::get_rt(
            m_context,
            rt_normal,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v18->m_object,
      v55,
      v15,
      0);
    v20 = rt;
    if ( rt )
    {
      --rt->m_reference_count;
      if ( !v20->m_reference_count )
        vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v21 = end;
    if ( end )
    {
      *end = (vostok::render::ambient_light *)((char *)*end - 1);
      if ( !*v21 )
        vostok::render::resource_manager::release(
          (vostok::render::render_target *)end,
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    m_screen_factor = __pred.m_screen_factor;
    if ( LODWORD(__pred.m_screen_factor) )
    {
      --*(_DWORD *)__pred.m_screen_factor;
      if ( !*(_DWORD *)LODWORD(m_screen_factor) )
        vostok::render::resource_manager::release(
          (vostok::render::render_target *)__pred.m_screen_factor,
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    vostok::render::renderer::foreground_begin(v19, (int)this->m_renderer);
    vostok::render::stage_gbuffer::render_models(
      (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v54,
      this,
      (unsigned int *)&wszName[1],
      0,
      1);
    vostok::render::renderer::foreground_end(v23, (int)this->m_renderer);
    vostok::render::stage_gbuffer::render_grass(v24, (bool)v48);
    vostok::render::stage_gbuffer::render_particles(v25, (int)this);
    vostok::render::stage_gbuffer::render_models(
      (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v54,
      this,
      (unsigned int *)&wszName[1],
      0,
      0);
    v27 = this->m_copy_depth_rt.m_object;
    if ( v27 )
    {
      v27->m_cur_technique = 0;
      vostok::render::res_effect::apply_pass(v26, (int)v27);
      vostok::render::backend::set_ps_texture(
        v28,
        SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        "t_depth_render_target",
        *(vostok::render::res_texture **)(*(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                                    + 7388)
                                        + 224));
      v47 = (unsigned int)this->m_context;
      v46.m_object = (vostok::render::render_target *)v47;
      vostok::render::renderer_context::get_rt((vostok::render::renderer_context *)v47, rt_position, &v46);
      vostok::render::fill_surface(v46.m_object, (vostok::render::renderer_context *)v47);
      v26 = (vostok::render::res_effect *)v47;
    }
    vostok::render::stage_gbuffer::render_forward_models((vostok::render::stage_gbuffer *)v26, (int)this);
    v51 = v50;
    D3DPERF_EndEvent();
    if ( this->m_fill_view_space_depth )
    {
      pix_event_wrapper_dx11::pix_event_wrapper_dx11(v29, wszName, (int)L"stage_gbuffer_0000");
      v30 = vostok::render::renderer_context::get_rt(
              this->m_context,
              rt_position,
              (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&__pred);
      vostok::render::backend::set_render_targets(
        (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        v30->m_object,
        0,
        0,
        0);
      v31 = __pred.m_screen_factor;
      if ( LODWORD(__pred.m_screen_factor) )
      {
        --*(_DWORD *)__pred.m_screen_factor;
        if ( !*(_DWORD *)LODWORD(v31) )
          vostok::render::resource_manager::release(
            (vostok::render::render_target *)__pred.m_screen_factor,
            vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      }
      v32 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
      vostok::render::backend::clear_render_targets(
        v33,
        (_DWORD *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        (vostok::math::color)v32,
        (vostok::math::color)v32,
        (vostok::math::color)v32,
        (vostok::math::color)v32);
      z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
      v35 = *(vostok::render::backend **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                        + 7440);
      v36 = (vostok::render::backend **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                       + 7384);
      v4 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == (_DWORD)v35;
      v47 = 3;
      *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 117) |= !v4;
      *v36 = v35;
      vostok::render::backend::clear_depth_stencil(v35, z_low, v47, *(float *)&v48, v49);
      m_flags = (vostok::render::render_surface *)this->m_context->m_scene_view.m_object[62].vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags;
      v38 = this->m_context->m_scene_view.m_object[62].m_sub_fat.m_object;
      *(_DWORD *)&wszName[1] = m_flags;
      v55 = (const vostok::render::render_target *)v38;
      if ( m_flags != (vostok::render::render_surface *)v38 )
      {
        while ( 1 )
        {
          v39 = m_flags->__vftable;
          rt = (vostok::render::render_target *)m_flags->add_shadow_vertices;
          if ( vostok::render::render_surface::get_material_effects(m_flags, (int)rt)->m_effects[1].m_object
            && rt[2].m_name.m_pointer.m_object != (vostok::strings::shared::profile *)2 )
          {
            if ( rt->m_name.m_pointer.m_object )
            {
              vostok::render::renderer_context::set_w(
                (const vostok::math::float4x4 *)v39[1].add_shadow_vertices,
                this->m_context);
              v40 = this->m_fill_depth_effect.m_object;
              v40->m_cur_technique = 2;
              vostok::render::res_effect::apply_pass(v41, (int)v40);
              (*(void (__thiscall **)(void (__thiscall *)(vostok::render::render_surface *), _DWORD))(*(_DWORD *)v39[1].~vostok::render::render_surface + 68))(
                v39[1].~vostok::render::render_surface,
                0);
              vostok::render::res_geometry::apply(v42, (int)rt->m_name.m_pointer.m_object);
              vostok::render::backend::render_indexed(
                (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                3 * (int)rt->m_zrt,
                v43,
                D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
                0,
                0);
            }
          }
          *(_DWORD *)&wszName[1] += 4;
          if ( *(const vostok::render::render_target **)&wszName[1] == v55 )
            break;
          m_flags = *(vostok::render::render_surface **)&wszName[1];
        }
      }
      D3DPERF_EndEvent();
    }
    v44 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::reset_render_targets(
      (vostok::render::backend *)v29,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    v45 = *(_DWORD *)(LODWORD(v44) + 7440);
    v4 = *(_DWORD *)(LODWORD(v44) + 7384) == v45;
    *(_DWORD *)(LODWORD(v44) + 7384) = v45;
    *(_BYTE *)(LODWORD(v44) + 117) |= !v4;
    *(_BYTE *)(LODWORD(v44) + 7590) = 1;
    *(_BYTE *)(LODWORD(v44) + 7591) = 0;
    s_debug_profile_dip = 0;
  }
  else
  {
    this->execute_disabled(this);
    D3DPERF_EndEvent();
  }
}
