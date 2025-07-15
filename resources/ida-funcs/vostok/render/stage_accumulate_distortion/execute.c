// bad sp value at call has been detected, the output may be wrong!
void __thiscall vostok::render::stage_accumulate_distortion::execute(vostok::render::stage_accumulate_distortion *this)
{
  vostok::render::renderer_context *m_context; // edx
  _DWORD *v3; // eax
  vostok::render::backend *v4; // ecx
  _DWORD *v5; // eax
  vostok::render::render_target *m_object; // esi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *rt; // eax
  _DWORD *v8; // eax
  vostok::render::render_target *v9; // eax
  unsigned __int8 v10; // al
  vostok::render::backend *v11; // ecx
  int v12; // esi
  _DWORD *v13; // edi
  bool v14; // zf
  vostok::render::backend *v15; // ecx
  pix_event_wrapper_dx11 *v16; // ecx
  vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *p_m_flags; // esi
  vostok::render::render_target **m_flags; // eax
  int v19; // edi
  vostok::render::render_particle_emitter_instance *v20; // ecx
  vostok::render::render_particle_emitter_instance *v21; // ecx
  vostok::render::res_effect *v22; // eax
  vostok::render::res_effect *v23; // ecx
  vostok::render::renderer_context *v24; // eax
  float x; // esi
  vostok::render::renderer_context *v26; // eax
  vostok::render::particle_shader_constants *v27; // ecx
  vostok::math::float3 *v28; // esi
  vostok::render::render_particle_emitter_instance *v29; // ecx
  vostok::render::backend *v30; // ecx
  pix_event_wrapper_dx11 *v31; // ecx
  vostok::render::render_surface_instance **m_begin; // ecx
  int v33; // edi
  int v34; // esi
  vostok::render::material_effects *material_effects; // eax
  int v36; // eax
  vostok::render::res_effect *v37; // ecx
  vostok::render::res_geometry *v38; // ecx
  vostok::render::backend *v39; // ecx
  vostok::render::backend *v40; // ecx
  float v41; // esi
  vostok::render::backend *v42; // ecx
  int v43; // edi
  vostok::math::float4x4 *v44; // ecx
  vostok::math::float4x4 *v45; // eax
  vostok::math::float3 v46; // [esp-24h] [ebp-20D0h]
  vostok::math::float3 v47; // [esp-18h] [ebp-20C4h] BYREF
  vostok::math::float3 v48; // [esp-Ch] [ebp-20B8h]
  float z; // [esp+0h] [ebp-20ACh]
  vostok::particle::enum_particle_screen_alignment v50; // [esp+4h] [ebp-20A8h]
  vostok::math::float3 v51; // [esp+8h] [ebp-20A4h]
  pix_event_wrapper_dx11 wszName[5]; // [esp+1Bh] [ebp-2091h] BYREF
  unsigned int m_width; // [esp+20h] [ebp-208Ch]
  vostok::render::render_target *v54; // [esp+24h] [ebp-2088h] BYREF
  vostok::render::render_surface_instance **i; // [esp+28h] [ebp-2084h]
  D3D11_VIEWPORT v56; // [esp+2Ch] [ebp-2080h] BYREF
  D3D11_VIEWPORT v57; // [esp+44h] [ebp-2068h] BYREF
  vostok::math::float4x4 v58; // [esp+5Ch] [ebp-2050h] BYREF
  vostok::buffer_vector<vostok::render::render_surface_instance *> v59; // [esp+9Ch] [ebp-2010h] BYREF
  _BYTE v60[8192]; // [esp+A8h] [ebp-2004h] BYREF
  char v61; // [esp+20A8h] [ebp-4h] BYREF

  if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_distortion_stage || !this->is_enabled(this) )
    goto LABEL_32;
  v59.m_begin = (vostok::render::render_surface_instance **)v60;
  v59.m_end = (vostok::render::render_surface_instance **)v60;
  v51.x = 0.0;
  v59.m_max_end = (vostok::render::render_surface_instance **)&v61;
  vostok::render::scene::select_models(
    (vostok::render::scene *)&this->m_context->m_vp,
    (int)this->m_context->m_scene,
    &this->m_context->m_vp,
    &this->m_context->m_vp,
    &v59,
    (vostok::math::float4x4 *)&this->m_context->m_view_pos,
    (const vostok::math::float3 *)1,
    0,
    SLOBYTE(v51.elements[1]));
  wszName[0] = (pix_event_wrapper_dx11)(v59.m_begin != v59.m_end);
  m_context = this->m_context;
  if ( *(int *)((char *)&dword_8B9664 + (unsigned int)m_context->m_scene)
    && m_context->m_scene_view.m_object[202].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags != *((_DWORD *)&m_context->m_scene_view.m_object[202].vostok::resources::resource_flags + 3) )
  {
    wszName[0] = (pix_event_wrapper_dx11)1;
  }
  if ( wszName[0] )
  {
    v50 = 17;
    qmemcpy(
      (void *)&v57,
      (const void *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 120),
      sizeof(v57));
    m_width = vostok::render::renderer_context::get_rt(
                m_context,
                rt_distortion,
                (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&wszName[1])->m_object->m_width;
    v3 = *(_DWORD **)&wszName[1];
    v56.Width = (float)m_width;
    if ( *(_DWORD *)&wszName[1] )
    {
      --**(_DWORD **)&wszName[1];
      if ( !*v3 )
        vostok::render::resource_manager::release(
          *(vostok::render::render_target **)&wszName[1],
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    m_width = vostok::render::renderer_context::get_rt(
                this->m_context,
                rt_distortion,
                (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&wszName[1])->m_object->m_height;
    v5 = *(_DWORD **)&wszName[1];
    v56.Height = (float)m_width;
    if ( *(_DWORD *)&wszName[1] )
    {
      --**(_DWORD **)&wszName[1];
      if ( !*v5 )
        vostok::render::resource_manager::release(
          *(vostok::render::render_target **)&wszName[1],
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v56.MinDepth = 0.0;
    v56.MaxDepth = s_bm_current_air_resistance;
    v56.TopLeftX = 0.0;
    v56.TopLeftY = 0.0;
    vostok::render::backend::set_viewports(
      v4,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      &v56,
      (const D3D11_VIEWPORT *)LODWORD(v51.y));
    m_object = vostok::render::renderer_context::get_rt(
                 this->m_context,
                 rt_distortion_mask,
                 (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v54)->m_object;
    rt = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_distortion,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&wszName[1]);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      rt->m_object,
      m_object,
      0,
      0);
    v8 = *(_DWORD **)&wszName[1];
    if ( *(_DWORD *)&wszName[1] )
    {
      --**(_DWORD **)&wszName[1];
      if ( !*v8 )
        vostok::render::resource_manager::release(
          *(vostok::render::render_target **)&wszName[1],
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v9 = v54;
    if ( v54 )
    {
      --v54->m_reference_count;
      if ( !v9->m_reference_count )
        vostok::render::resource_manager::release(v54, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
    }
    v10 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
    vostok::render::backend::clear_render_targets(
      v11,
      LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.elements[2]),
      v10);
    v12 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7440);
    v13 = (_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384);
    v14 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == v12;
    v51.x = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    LOBYTE(v15) = !v14;
    *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 117) |= !v14;
    *v13 = v12;
    vostok::render::backend::flush_rt_shader_resources(v15, SLODWORD(v51.x));
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(v16, wszName, (int)L"stage_accumulate_distortion");
    if ( *(int *)((char *)&dword_8B9664 + (unsigned int)this->m_context->m_scene) )
    {
      p_m_flags = &this->m_context->m_scene_view.m_object[202].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
      m_flags = (vostok::render::render_target **)p_m_flags->m_flags;
      m_width = (unsigned int)p_m_flags;
      while ( 1 )
      {
        *(_DWORD *)&wszName[1] = m_flags;
        if ( m_flags == (vostok::render::render_target **)p_m_flags[1].m_flags )
          break;
        v19 = (int)*m_flags;
        v20 = (vostok::render::render_particle_emitter_instance *)**((_DWORD **)&(*m_flags)[4].m_memory_usage + 1);
        v54 = *m_flags;
        i = (vostok::render::render_surface_instance **)v20;
        if ( v20 )
        {
          if ( vostok::render::render_particle_emitter_instance::get_material_effects(v20, v19)->m_effects[3].m_object )
          {
            v22 = vostok::render::render_particle_emitter_instance::get_material_effects(v21, v19)->m_effects[3].m_object;
            v22->m_cur_technique = 0;
            vostok::render::res_effect::apply_pass(v23, (int)v22);
            v51.x = *(float *)(v19 + 372);
            v24 = this->m_context;
            v50 = *(_DWORD *)(v19 + 368);
            *(_QWORD *)&v48.elements[1] = *(_QWORD *)&v24->m_view_pos.x;
            z = v24->m_view_pos.z;
            *(_QWORD *)&v47.elements[1] = *(_QWORD *)&v24->m_camera_right_vector.x;
            v48.x = v24->m_camera_right_vector.z;
            *(_QWORD *)&v46.elements[1] = *(_QWORD *)&v24->m_camera_up_vector.x;
            v47.x = v24->m_camera_up_vector.z;
            x = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x;
            v46.x = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x;
            vostok::render::particle_shader_constants::set(
              (vostok::render::particle_shader_constants *)v24,
              v46,
              v47,
              v48,
              SLODWORD(z),
              v50,
              SLODWORD(v51.x));
            v26 = this->m_context;
            LODWORD(v51.x) = v27;
            v51.x = v26->m_current_time;
            vostok::render::particle_shader_constants::set_time(v27, x, v51);
            v28 = (vostok::math::float3 *)v54;
            vostok::render::renderer_context::set_w((const vostok::math::float4x4 *)&v54[2].m_format, this->m_context);
            vostok::render::render_particle_emitter_instance::render(
              v29,
              (int)this,
              (int)&v47.y,
              (int)v28,
              v28,
              (const unsigned int)this->m_context,
              (unsigned int)i);
            p_m_flags = (vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *)m_width;
          }
          m_flags = *(vostok::render::render_target ***)&wszName[1];
        }
        ++m_flags;
      }
    }
    D3DPERF_EndEvent();
    vostok::render::backend::flush_rt_shader_resources(
      v30,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(v31, wszName, (int)L"stage_distortion_models");
    m_begin = v59.m_begin;
    *(_DWORD *)&wszName[1] = v59.m_begin;
    for ( i = v59.m_end; *(vostok::render::render_surface_instance ***)&wszName[1] != i; *(_DWORD *)&wszName[1] += 4 )
    {
      v33 = **(_DWORD **)&wszName[1];
      v34 = *(_DWORD *)(**(_DWORD **)&wszName[1] + 16);
      material_effects = vostok::render::render_surface::get_material_effects(
                           (vostok::render::render_surface *)m_begin,
                           v34);
      v14 = material_effects->m_effects[3].m_object == 0;
      m_width = (unsigned int)material_effects;
      if ( !v14 )
      {
        vostok::render::renderer_context::set_w(*(const vostok::math::float4x4 **)(v33 + 36), this->m_context);
        v36 = *(_DWORD *)(m_width + 52);
        *(_DWORD *)(v36 + 22048) = 0;
        vostok::render::res_effect::apply_pass(v37, v36);
        vostok::render::res_geometry::apply(v38, *(_DWORD *)(v34 + 4));
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          3 * *(_DWORD *)(v34 + 24),
          v39,
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          0,
          0);
      }
    }
    D3DPERF_EndEvent();
    vostok::render::backend::set_viewports(
      v40,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      &v57,
      (const D3D11_VIEWPORT *)LODWORD(v51.y));
    v41 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::reset_render_targets(
      v42,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    v43 = *(_DWORD *)(LODWORD(v41) + 7440);
    v14 = *(_DWORD *)(LODWORD(v41) + 7384) == v43;
    *(_DWORD *)(LODWORD(v41) + 7384) = v43;
    LOBYTE(v44) = !v14;
    *(_BYTE *)(LODWORD(v41) + 117) |= !v14;
    v45 = vostok::math::float4x4::identity(v44, &v58);
    vostok::render::renderer_context::set_w(v45, this->m_context);
  }
  else
  {
LABEL_32:
    this->execute_disabled(this);
  }
}
