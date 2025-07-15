void __thiscall vostok::render::stage_particles::execute(vostok::render::stage_particles *this)
{
  pix_event_wrapper_dx11 *v2; // ecx
  vostok::math::float4x4 *v3; // ecx
  vostok::render::renderer_context *m_context; // edi
  vostok::math::float4x4 *v5; // eax
  const stlp_std::random_access_iterator_tag *v6; // ecx
  float distance_to_camera; // eax
  float *m_begin; // edi
  vostok::render::renderer_context *v9; // ecx
  float y; // xmm1_4
  float z; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  vostok::buffer_vector<vostok::render::stage_particles::particle_emitter_instance_entry> *v15; // ecx
  vostok::buffer_vector<vostok::render::stage_particles::particle_emitter_instance_entry> *v16; // ecx
  int v17; // edi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *rt; // eax
  float v19; // edi
  _DWORD *v20; // eax
  int v21; // ecx
  bool v22; // zf
  vostok::render::res_effect *v23; // ecx
  vostok::render::res_effect *m_object; // eax
  vostok::render::render_target *v25; // ecx
  vostok::render::res_effect *v26; // eax
  vostok::render::res_effect *v27; // ecx
  vostok::render::system_renderer *v28; // edi
  vostok::render::render_target *v29; // ecx
  vostok::render::res_effect *v30; // eax
  vostok::render::res_effect *v31; // ecx
  vostok::render::backend *v32; // ecx
  vostok::render::system_renderer *v33; // esi
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v34; // eax
  float v35; // edi
  _DWORD *v36; // eax
  int v37; // esi
  vostok::math::float4x4 *v38; // ecx
  vostok::math::float4x4 *v39; // eax
  float v40; // esi
  vostok::render::backend *v41; // ecx
  int v42; // ecx
  vostok::render::system_renderer *v43; // [esp-1Ch] [ebp-A0C4h]
  vostok::render::system_renderer *v44; // [esp-1Ch] [ebp-A0C4h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v45; // [esp-18h] [ebp-A0C0h] BYREF
  vostok::render::render_target *v46; // [esp-14h] [ebp-A0BCh] BYREF
  vostok::render::render_target *v47; // [esp-10h] [ebp-A0B8h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v48; // [esp-Ch] [ebp-A0B4h]
  vostok::render::shader_constant_host *m_c_particle_screen_divider; // [esp-8h] [ebp-A0B0h]
  int p_end; // [esp-4h] [ebp-A0ACh]
  float v51; // [esp+0h] [ebp-A0A8h]
  float v52; // [esp+4h] [ebp-A0A4h]
  float v53; // [esp+8h] [ebp-A0A0h]
  float v54; // [esp+Ch] [ebp-A09Ch]
  char wszName; // [esp+12h] [ebp-A096h] BYREF
  char wszName_1; // [esp+13h] [ebp-A095h]
  vostok::render::remove_particle_emitter_predicate __pred[4]; // [esp+14h] [ebp-A094h] BYREF
  vostok::math::float3 end; // [esp+18h] [ebp-A090h] BYREF
  vostok::math::float4x4 v60; // [esp+28h] [ebp-A080h] BYREF
  vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024> v61; // [esp+68h] [ebp-A040h] BYREF
  vostok::render::stage_particles::particle_emitter_instance_entry value; // [esp+1078h] [ebp-9030h] BYREF
  _BYTE v63[12288]; // [esp+1084h] [ebp-9024h] BYREF
  char v64; // [esp+4084h] [ebp-6024h] BYREF
  vostok::fixed_vector<vostok::render::stage_particles::particle_emitter_instance_entry,1024> v65; // [esp+4088h] [ebp-6020h] BYREF
  vostok::buffer_vector<vostok::render::stage_particles::particle_emitter_instance_entry> v66; // [esp+7094h] [ebp-3014h] BYREF
  char *v67; // [esp+70A0h] [ebp-3008h]
  _BYTE v68[12288]; // [esp+70A4h] [ebp-3004h] BYREF
  char v69; // [esp+A0A4h] [ebp-4h] BYREF

  if ( this->is_enabled(this)
    && this->is_effects_ready(this)
    && (vostok::quasi_singleton<vostok::render::options>::pinst->current.m_particles_pre_distortion_stage
     || this->m_stage_mode)
    && (vostok::quasi_singleton<vostok::render::options>::pinst->current.m_particles_stage
     || this->m_stage_mode != post_distortion) )
  {
    pix_event_wrapper_dx11::pix_event_wrapper_dx11(v2, (pix_event_wrapper_dx11 *)&wszName, (int)L"stage_particles");
    m_context = this->m_context;
    if ( !*(int *)((char *)&dword_8B9664 + (unsigned int)m_context->m_scene) )
    {
      v5 = vostok::math::float4x4::identity(v3, &v60);
      vostok::render::renderer_context::set_w(v5, m_context);
LABEL_9:
      D3DPERF_EndEvent();
      return;
    }
    if ( this->m_stage_mode == pre_distortion )
    {
      vostok::render::stage_particles::render_pre_distortion_particles(
        (vostok::render::stage_particles *)v3,
        (vostok::render::render_target *)this);
      goto LABEL_9;
    }
    vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>(
      &v61,
      (const vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024> *)&m_context->m_scene_view.m_object[202].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags);
    __pred[0].m_pre_distortion_only = this->m_stage_mode == pre_distortion;
    LOBYTE(v6) = __pred[0];
    LODWORD(end.x) = v61.m_end;
    *(_DWORD *)&__pred[0].m_pre_distortion_only = stlp_std::remove_if<vostok::particle::render_particle_emitter_instance * *,vostok::render::remove_particle_emitter_predicate>(
                                                    v61.m_begin,
                                                    v6,
                                                    v61.m_end,
                                                    __pred[0]);
    vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
      (vostok::buffer_vector<vostok::render::ambient_light *> *)&v61,
      (vostok::render::ambient_light ***)__pred,
      (vostok::render::ambient_light ***)&end);
    *(_DWORD *)&value.is_lighted = &v64;
    distance_to_camera = COERCE_FLOAT(v63);
    value.instance = (vostok::render::render_particle_emitter_instance *)v63;
    LODWORD(value.distance_to_camera) = v63;
    wszName = 0;
    m_begin = (float *)v61.m_begin;
    if ( v61.m_begin != v61.m_end )
    {
      do
      {
        v9 = this->m_context;
        y = v9->m_view_pos.y;
        z = v9->m_view_pos.z;
        v9 = (vostok::render::renderer_context *)((char *)v9 + 21132);
        v12 = *(float *)&v9->m_targets - *(float *)(*(_DWORD *)m_begin + 232);
        v13 = z - *(float *)(*(_DWORD *)m_begin + 240);
        v14 = (float)(v12 * v12)
            + (float)((float)(y - *(float *)(*(_DWORD *)m_begin + 236))
                    * (float)(y - *(float *)(*(_DWORD *)m_begin + 236)));
        end.y = *m_begin;
        end.z = v14 + (float)(v13 * v13);
        if ( vostok::render::render_particle_emitter_instance::get_material_effects(
               (vostok::render::render_particle_emitter_instance *)v9,
               SLODWORD(end.y))->m_effects[17].m_object != 0 )
          wszName = 1;
        vostok::buffer_vector<vostok::render::stage_particles::particle_emitter_instance_entry>::push_back(
          v15,
          &value,
          &end.y);
        ++m_begin;
      }
      while ( m_begin != (float *)v61.m_end );
      distance_to_camera = value.distance_to_camera;
    }
    v66.m_end = (vostok::render::stage_particles::particle_emitter_instance_entry *)v68;
    v66.m_max_end = (vostok::render::stage_particles::particle_emitter_instance_entry *)v68;
    v67 = &v69;
    v65.m_begin = (vostok::render::stage_particles::particle_emitter_instance_entry *)v65.m_buffer;
    v65.m_end = (vostok::render::stage_particles::particle_emitter_instance_entry *)v65.m_buffer;
    v16 = &v66;
    v65.m_max_end = (vostok::render::stage_particles::particle_emitter_instance_entry *)&v66;
    LODWORD(end.x) = value.instance;
    wszName_1 = 0;
    if ( (vostok::render::render_particle_emitter_instance *)LODWORD(distance_to_camera) != value.instance )
    {
      v17 = LODWORD(distance_to_camera) - 12;
      do
      {
        if ( *(_BYTE *)(v17 + 8) )
          goto LABEL_23;
        if ( wszName_1 )
          vostok::buffer_vector<vostok::render::stage_particles::particle_emitter_instance_entry>::push_back(
            v16,
            (const vostok::render::stage_particles::particle_emitter_instance_entry *)&v66.m_end,
            (_DWORD *)v17);
        if ( *(_BYTE *)(v17 + 8) )
        {
LABEL_23:
          wszName_1 = 1;
        }
        else if ( !wszName_1 )
        {
          vostok::buffer_vector<vostok::render::stage_particles::particle_emitter_instance_entry>::push_back(
            v16,
            (const vostok::render::stage_particles::particle_emitter_instance_entry *)&v65,
            (_DWORD *)v17);
        }
        v17 -= 12;
      }
      while ( v17 + 12 != LODWORD(end.x) );
    }
    rt = vostok::render::renderer_context::get_rt(
           this->m_context,
           rt_generic_0,
           (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__pred);
    v19 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      rt->m_object,
      0,
      0,
      0);
    v20 = *(_DWORD **)&__pred[0].m_pre_distortion_only;
    if ( *(_DWORD *)&__pred[0].m_pre_distortion_only )
    {
      --**(_DWORD **)&__pred[0].m_pre_distortion_only;
      if ( !*v20 )
      {
        vostok::render::resource_manager::release(
          *(vostok::render::render_target **)&__pred[0].m_pre_distortion_only,
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
        v19 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      }
    }
    v21 = *(_DWORD *)(LODWORD(v19) + 7440);
    v22 = *(_DWORD *)(LODWORD(v19) + 7384) == v21;
    *(_DWORD *)(LODWORD(v19) + 7384) = v21;
    *(_BYTE *)(LODWORD(v19) + 117) |= !v22;
    vostok::render::stage_particles::render_particle_entries(
      (const vostok::fixed_vector<vostok::render::stage_particles::particle_emitter_instance_entry,1024> *)&v66.m_end,
      this);
    if ( wszName && this->m_stage_mode == post_distortion )
    {
      m_object = this->m_resolve_particles_effect.m_object;
      m_object->m_cur_technique = 1;
      vostok::render::res_effect::apply_pass(v23, (int)m_object);
      p_end = 1;
      m_c_particle_screen_divider = 0;
      v48.m_object = 0;
      v47 = 0;
      v46 = 0;
      v45.m_object = v25;
      LODWORD(end.x) = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
      v43 = (vostok::render::system_renderer *)v25;
      vostok::render::renderer_context::get_rt(this->m_context, rt_generic_0, &v45);
      vostok::render::system_renderer::fill_surface(
        v43,
        LODWORD(end.x),
        v45.m_object,
        v46,
        v47,
        v48,
        (vostok::render::render_target *)m_c_particle_screen_divider,
        (D3D11_VIEWPORT *)p_end,
        v51,
        v52,
        v53,
        v54);
      v26 = this->m_resolve_particles_effect.m_object;
      v26->m_cur_technique = 5;
      vostok::render::res_effect::apply_pass(v27, (int)v26);
      p_end = 1;
      v28 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
      m_c_particle_screen_divider = 0;
      v48.m_object = 0;
      v47 = 0;
      v45.m_object = v29;
      v46 = 0;
      v44 = (vostok::render::system_renderer *)v29;
      vostok::render::renderer_context::get_rt(this->m_context, rt_generic_0, &v45);
      vostok::render::system_renderer::fill_surface(
        v44,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v28,
        v45.m_object,
        v46,
        v47,
        v48,
        (vostok::render::render_target *)m_c_particle_screen_divider,
        (D3D11_VIEWPORT *)p_end,
        v51,
        v52,
        v53,
        v54);
      v30 = this->m_resolve_particles_effect.m_object;
      v30->m_cur_technique = 0;
      vostok::render::res_effect::apply_pass(v31, (int)v30);
      p_end = (int)&end;
      m_c_particle_screen_divider = this->m_c_particle_screen_divider;
      end.x = retry_to_increase_quality_period_sec;
      vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
        v32,
        (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
        m_c_particle_screen_divider,
        &end);
      p_end = 1;
      m_c_particle_screen_divider = 0;
      v48.m_object = 0;
      v47 = 0;
      v46 = 0;
      v33 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
      v45.m_object = (vostok::render::render_target *)&v46;
      vostok::render::renderer_context::get_rt(this->m_context, rt_generic_0, &v45);
      vostok::render::system_renderer::fill_surface(
        (vostok::render::system_renderer *)&v46,
        (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v33,
        v45.m_object,
        v46,
        v47,
        v48,
        (vostok::render::render_target *)m_c_particle_screen_divider,
        (D3D11_VIEWPORT *)p_end,
        v51,
        v52,
        v53,
        v54);
    }
    v34 = vostok::render::renderer_context::get_rt(
            this->m_context,
            rt_generic_0,
            (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__pred);
    v35 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v34->m_object,
      0,
      0,
      0);
    v36 = *(_DWORD **)&__pred[0].m_pre_distortion_only;
    if ( *(_DWORD *)&__pred[0].m_pre_distortion_only )
    {
      --**(_DWORD **)&__pred[0].m_pre_distortion_only;
      if ( !*v36 )
      {
        vostok::render::resource_manager::release(
          *(vostok::render::render_target **)&__pred[0].m_pre_distortion_only,
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
        v35 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      }
    }
    v37 = *(_DWORD *)(LODWORD(v35) + 7440);
    v22 = *(_DWORD *)(LODWORD(v35) + 7384) == v37;
    *(_DWORD *)(LODWORD(v35) + 7384) = v37;
    *(_BYTE *)(LODWORD(v35) + 117) |= !v22;
    vostok::render::stage_particles::render_particle_entries(&v65, this);
    v65.m_end = v65.m_begin;
    v66.m_max_end = v66.m_end;
    LODWORD(value.distance_to_camera) = value.instance;
    v61.m_end = v61.m_begin;
    D3DPERF_EndEvent();
    v39 = vostok::math::float4x4::identity(v38, &v60);
    vostok::render::renderer_context::set_w(v39, this->m_context);
    v40 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::reset_render_targets(
      v41,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    v42 = *(_DWORD *)(LODWORD(v40) + 7440);
    v22 = *(_DWORD *)(LODWORD(v40) + 7384) == v42;
    *(_DWORD *)(LODWORD(v40) + 7384) = v42;
    *(_BYTE *)(LODWORD(v40) + 117) |= !v22;
  }
  else
  {
    this->execute_disabled(this);
  }
}
