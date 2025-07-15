void __thiscall vostok::render::stage_ambient_occlusion::execute(vostok::render::stage_ambient_occlusion *this)
{
  bool v2; // zf
  vostok::render::res_texture *v3; // ecx
  vostok::render::render_target *v4; // ecx
  vostok::render::base_scene_view *m_object; // esi
  pix_event_wrapper_dx11 *v6; // ecx
  vostok::resources::resource_link *m_first; // xmm0_4
  vostok::resources::resource_link *m_last; // xmm1_4
  vostok::render::backend *v9; // ecx
  vostok::math::float4x4 *v10; // ecx
  pix_event_wrapper_dx11 *v11; // ecx
  pix_event_wrapper_dx11 **v12; // esi
  vostok::render::res_effect *v13; // ecx
  vostok::render::res_effect *v14; // eax
  float z; // esi
  vostok::render::backend *v16; // ecx
  vostok::math::float4x4 *v17; // eax
  vostok::render::backend *v18; // ecx
  vostok::render::system_renderer *v19; // esi
  vostok::render::render_target *v20; // ecx
  vostok::render::backend *v21; // ecx
  float v22; // esi
  vostok::math::float4x4 *v23; // eax
  vostok::render::backend *v24; // ecx
  vostok::render::system_renderer *v25; // esi
  vostok::render::render_target *v26; // ecx
  vostok::render::res_effect *v27; // eax
  vostok::render::res_texture *v28; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *t; // eax
  vostok::render::renderer_context *m_context; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v31; // eax
  vostok::render::renderer_context *v32; // ecx
  vostok::render::res_texture *v33; // eax
  vostok::render::res_texture *v34; // ecx
  unsigned int v35; // eax
  vostok::render::resource_manager **v36; // ecx
  vostok::render::resource_manager *v37; // ecx
  vostok::render::res_texture *v38; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v39; // eax
  vostok::render::renderer_context *v40; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v41; // eax
  vostok::render::renderer_context *v42; // ecx
  vostok::render::res_texture *v43; // eax
  vostok::render::res_texture *v44; // ecx
  unsigned int v45; // eax
  vostok::render::resource_manager **v46; // ecx
  vostok::render::resource_manager *v47; // ecx
  float v48; // esi
  int v49; // ecx
  vostok::render::system_renderer *v50; // [esp-1Ch] [ebp-94h]
  vostok::render::system_renderer *v51; // [esp-1Ch] [ebp-94h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v52; // [esp-18h] [ebp-90h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v53; // [esp-14h] [ebp-8Ch] BYREF
  vostok::render::render_target *v54; // [esp-10h] [ebp-88h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v55; // [esp-Ch] [ebp-84h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v56; // [esp-8h] [ebp-80h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v57; // [esp-4h] [ebp-7Ch] BYREF
  float v58; // [esp+0h] [ebp-78h]
  vostok::render::res_texture *v59; // [esp+4h] [ebp-74h]
  float v60; // [esp+8h] [ebp-70h]
  float v61; // [esp+Ch] [ebp-6Ch] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> wszName_1; // [esp+10h] [ebp-68h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v63; // [esp+14h] [ebp-64h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v64; // [esp+18h] [ebp-60h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v65; // [esp+1Ch] [ebp-5Ch] BYREF
  vostok::render::res_texture *v66; // [esp+20h] [ebp-58h]
  vostok::render::res_texture *dest; // [esp+24h] [ebp-54h]
  vostok::math::float3 v68; // [esp+28h] [ebp-50h] BYREF
  int v69; // [esp+34h] [ebp-44h]
  vostok::math::float4x4 v70; // [esp+38h] [ebp-40h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&v61 + 3,
    (int)L"stage_ambient_occlusion");
  if ( !this->is_effects_ready(this) )
    goto LABEL_47;
  if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_ambient_occlusion_quality
    || (v2 = this->m_context->m_scene_view.m_object[2].m_parent_resources.gapC == 0, HIBYTE(v61) = 1, v2) )
  {
    HIBYTE(v61) = 0;
  }
  if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_ambient_occlusion_stage
    || !this->is_enabled(this)
    || !HIBYTE(v61) )
  {
    this->execute_disabled(this);
    goto LABEL_47;
  }
  v2 = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_post_process_quality == 3;
  *(float *)&wszName_1.m_object = 0.0;
  if ( v2 )
    *(float *)&wszName_1.m_object = (float)vostok::quasi_singleton<vostok::render::options>::pinst->current.m_ssao_use_temporal_filtering;
  v57.m_object = v3;
  vostok::render::renderer_context::get_t(this->m_context, rt_position, &v57);
  v56.m_object = v4;
  v55.m_object = v4;
  vostok::render::renderer_context::get_rt(this->m_context, rt_frame_depth_downsampled, &v56);
  vostok::render::renderer::downsample(
    (vostok::render::renderer *)v55.m_object,
    (int)this->m_renderer,
    v56.m_object,
    v57);
  m_object = this->m_context->m_scene_view.m_object;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11(v6, (pix_event_wrapper_dx11 *)&v61 + 3, (int)L"ssao_pass");
  vostok::render::res_effect::apply(
    (vostok::render::res_effect *)(vostok::quasi_singleton<vostok::render::options>::pinst->current.m_ambient_occlusion_quality >= 2),
    (int)this->m_sh_ssao_accumulation.m_object);
  m_first = m_object[2].m_parent_resources.m_first;
  m_last = m_object[2].m_parent_resources.m_last;
  v57.m_object = (vostok::render::res_texture *)&v68;
  v56.m_object = (vostok::render::render_target *)this->m_ao_parameters;
  *(_QWORD *)&v68.x = __PAIR64__((unsigned int)m_last, (unsigned int)m_first);
  v68.z = 0.0;
  v69 = 0;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v9,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    (const vostok::render::shader_constant_host *)v56.m_object,
    &v68);
  v57.m_object = (vostok::render::res_texture *)this->m_context;
  v56.m_object = (vostok::render::render_target *)v57.m_object;
  v55.m_object = (vostok::render::render_target *)v57.m_object;
  vostok::render::renderer_context::get_rt((vostok::render::renderer_context *)v57.m_object, rt_ssao_accumulator, &v56);
  vostok::render::fill_surface_0(v56.m_object, (vostok::render::renderer_context *)v57.m_object);
  D3DPERF_EndEvent();
  if ( (_S6_7 & 1) == 0 )
  {
    _S6_7 |= 1u;
    qmemcpy(&prev_view, vostok::math::float4x4::identity(v10, &v70), sizeof(prev_view));
  }
  v11 = *(pix_event_wrapper_dx11 **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                   + 7440);
  v12 = (pix_event_wrapper_dx11 **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                  + 7384);
  v2 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) == (_DWORD)v11;
  v57.m_object = (vostok::render::res_texture *)L"ssao_filter";
  *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 117) |= !v2;
  v56.m_object = (vostok::render::render_target *)((char *)&v61 + 3);
  *v12 = v11;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11(v11, (pix_event_wrapper_dx11 *)v56.m_object, (int)v57.m_object);
  if ( !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_ssao_use_filtering )
  {
    v27 = this->m_sh_ssao_filter4x4.m_object;
    v27->m_cur_technique = 0;
    vostok::render::res_effect::apply_pass(v13, (int)v27);
LABEL_19:
    v25 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
    v57.m_object = (vostok::render::res_texture *)1;
    v56.m_object = 0;
    v55.m_object = 0;
    v54 = 0;
    v53.m_object = 0;
    goto LABEL_20;
  }
  v14 = this->m_sh_ssao_filter4x4.m_object;
  if ( *(float *)&wszName_1.m_object == 0.0 )
  {
    v14->m_cur_technique = 3;
  }
  else
  {
    v14->m_cur_technique = 2;
    vostok::render::res_effect::apply_pass(v13, (int)v14);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v16,
      (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      this->m_c_eye_ray_corner,
      this->m_context->m_eye_rays);
    v17 = vostok::math::transpose(&prev_view, &v70);
    vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
      v18,
      (vostok::render::constants_handler<1> *)LODWORD(z),
      this->m_prev_view_parameter,
      (const vostok::math::float3 *)v17);
    v57.m_object = 0;
    v19 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
    v56.m_object = 0;
    v55.m_object = 0;
    v54 = 0;
    v52.m_object = v20;
    v53.m_object = 0;
    v50 = (vostok::render::system_renderer *)v20;
    vostok::render::renderer_context::get_rt(this->m_context, rt_ssao_temporal_mask, &v52);
    vostok::render::system_renderer::fill_surface(
      v50,
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v19,
      v52.m_object,
      v53.m_object,
      v54,
      v55,
      v56.m_object,
      (D3D11_VIEWPORT *)v57.m_object,
      v58,
      *(float *)&v59,
      v60,
      v61);
    v14 = this->m_sh_ssao_filter4x4.m_object;
    v14->m_cur_technique = 4;
  }
  vostok::render::res_effect::apply_pass(v13, (int)v14);
  if ( *(float *)&wszName_1.m_object == 0.0 )
    goto LABEL_19;
  v22 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v21,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    this->m_c_eye_ray_corner,
    this->m_context->m_eye_rays);
  v23 = vostok::math::transpose(&prev_view, &v70);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v24,
    (vostok::render::constants_handler<1> *)LODWORD(v22),
    this->m_prev_view_parameter,
    (const vostok::math::float3 *)v23);
  v25 = vostok::quasi_singleton<vostok::render::system_renderer>::pinst;
  v57.m_object = (vostok::render::res_texture *)1;
  v56.m_object = 0;
  v55.m_object = 0;
  v53.m_object = v26;
  v54 = 0;
  vostok::render::renderer_context::get_rt(this->m_context, rt_ssao_accumulator_z, &v53);
LABEL_20:
  v52.m_object = (vostok::render::render_target *)v21;
  v51 = (vostok::render::system_renderer *)v21;
  vostok::render::renderer_context::get_rt(this->m_context, rt_ssao_accumulator_full_x, &v52);
  vostok::render::system_renderer::fill_surface(
    v51,
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v25,
    v52.m_object,
    v53.m_object,
    v54,
    v55,
    v56.m_object,
    (D3D11_VIEWPORT *)v57.m_object,
    v58,
    *(float *)&v59,
    v60,
    v61);
  if ( *(float *)&wszName_1.m_object != 0.0 )
  {
    v28 = vostok::render::renderer_context::get_t(this->m_context, rt_ssao_accumulator_full_x, &v65)->m_object;
    t = vostok::render::renderer_context::get_t(this->m_context, rt_ssao_accumulator_full_x, &v64);
    m_context = this->m_context;
    v66 = t->m_object;
    v31 = vostok::render::renderer_context::get_t(m_context, rt_ssao_accumulator_full_x, &v63);
    v32 = this->m_context;
    dest = v31->m_object;
    v33 = (vostok::render::res_texture *)vostok::render::renderer_context::get_t(
                                           v32,
                                           rt_ssao_prev_accumulator_full_x,
                                           &wszName_1);
    v57.m_object = (vostok::render::res_texture *)vostok::render::res_texture::height(v33, (int)v28);
    v35 = vostok::render::res_texture::width(v34, (int)v66);
    vostok::render::resource_manager::copy2D(
      v35,
      *v36,
      dest,
      (unsigned int)v57.m_object,
      LODWORD(v58),
      v59,
      LODWORD(v60),
      LODWORD(v61),
      (unsigned int)wszName_1.m_object,
      (unsigned int)v63.m_object,
      (unsigned int)v64.m_object);
    if ( *(float *)&wszName_1.m_object != 0.0 )
    {
      v2 = wszName_1.m_object->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          v37,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          wszName_1.m_object);
    }
    if ( v63.m_object )
    {
      v2 = v63.m_object->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          v37,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v63.m_object);
    }
    if ( v64.m_object )
    {
      v2 = v64.m_object->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          v37,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v64.m_object);
    }
    if ( v65.m_object )
    {
      v2 = v65.m_object->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          v37,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v65.m_object);
    }
    v38 = vostok::render::renderer_context::get_t(this->m_context, rt_ssao_accumulator_z, &wszName_1)->m_object;
    v39 = vostok::render::renderer_context::get_t(this->m_context, rt_ssao_accumulator_z, &v63);
    v40 = this->m_context;
    dest = v39->m_object;
    v41 = vostok::render::renderer_context::get_t(v40, rt_ssao_accumulator_z, &v64);
    v42 = this->m_context;
    v66 = v41->m_object;
    v43 = (vostok::render::res_texture *)vostok::render::renderer_context::get_t(v42, rt_ssao_prev_accumulator_z, &v65);
    v57.m_object = (vostok::render::res_texture *)vostok::render::res_texture::height(v43, (int)v38);
    v45 = vostok::render::res_texture::width(v44, (int)dest);
    vostok::render::resource_manager::copy2D(
      v45,
      *v46,
      v66,
      (unsigned int)v57.m_object,
      LODWORD(v58),
      v59,
      LODWORD(v60),
      LODWORD(v61),
      (unsigned int)wszName_1.m_object,
      (unsigned int)v63.m_object,
      (unsigned int)v64.m_object);
    if ( v65.m_object )
    {
      v2 = v65.m_object->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          v47,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v65.m_object);
    }
    if ( v64.m_object )
    {
      v2 = v64.m_object->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          v47,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v64.m_object);
    }
    if ( v63.m_object )
    {
      v2 = v63.m_object->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          v47,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v63.m_object);
    }
    if ( *(float *)&wszName_1.m_object != 0.0 )
    {
      v2 = wszName_1.m_object->m_reference_count-- == 1;
      if ( v2 )
        vostok::render::resource_manager::release(
          v47,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          wszName_1.m_object);
    }
  }
  D3DPERF_EndEvent();
  qmemcpy(&prev_view, &this->m_context->m_v, sizeof(prev_view));
  v48 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  vostok::render::backend::reset_render_targets(
    0,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  v49 = *(_DWORD *)(LODWORD(v48) + 7440);
  v2 = *(_DWORD *)(LODWORD(v48) + 7384) == v49;
  *(_DWORD *)(LODWORD(v48) + 7384) = v49;
  *(_BYTE *)(LODWORD(v48) + 117) |= !v2;
LABEL_47:
  D3DPERF_EndEvent();
}
