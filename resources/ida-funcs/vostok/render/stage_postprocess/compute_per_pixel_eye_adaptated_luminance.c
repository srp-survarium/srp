void __usercall vostok::render::stage_postprocess::compute_per_pixel_eye_adaptated_luminance(
        vostok::render::stage_postprocess *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> a2@<edi>)
{
  unsigned int m_checksum; // ebx
  int m_order; // eax
  unsigned int v4; // ebx
  vostok::render::backend *v5; // ecx
  float v6; // xmm1_4
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v7; // xmm0_4
  float z; // esi
  float v9; // xmm0_4
  vostok::render::backend *v10; // ecx
  vostok::strings::shared::profile *m_object; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *t; // eax
  vostok::render::backend *v13; // ecx
  vostok::render::resource_manager *v14; // ecx
  bool v15; // zf
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v16; // eax
  vostok::render::backend *v17; // ecx
  vostok::render::resource_manager *v18; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v19; // eax
  vostok::render::backend *v20; // ecx
  vostok::render::resource_manager *v21; // ecx
  vostok::render::stage_postprocess *v22; // ecx
  vostok::render::backend *v23; // ecx
  int v24; // eax
  vostok::render::res_effect *v25; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v26; // eax
  vostok::render::backend *v27; // ecx
  vostok::render::resource_manager *v28; // ecx
  vostok::render::stage_postprocess *v29; // ecx
  ID3D11Texture3D *m_surface_3d; // [esp-8h] [ebp-18h]
  ID3D11RenderTargetView *m_rt; // [esp-8h] [ebp-18h]
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v32; // [esp-4h] [ebp-14h] BYREF
  float v33; // [esp+8h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v34; // [esp+Ch] [ebp-4h] BYREF

  m_checksum = a2.m_object->m_name.m_pointer.m_object[1016].m_checksum;
  m_order = a2.m_object[1].m_order;
  *(_DWORD *)(m_order + 22048) = 0;
  v4 = m_checksum + 280;
  vostok::render::res_effect::apply_pass((vostok::render::res_effect *)this, m_order);
  v6 = *(float *)&a2.m_object->m_name.m_pointer.m_object[732].m_reference_count;
  *(float *)&v7.m_object = 0.0;
  if ( v6 <= 0.0 || (*(float *)&v7.m_object = FLOAT_0_033333335, v6 > 0.033333335) )
    v34.m_object = v7.m_object;
  else
    v34.m_object = (vostok::render::res_texture *)a2.m_object->m_name.m_pointer.m_object[732].m_reference_count;
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v32.m_object = (vostok::render::render_target *)&v33;
  m_surface_3d = a2.m_object[4].m_surface_3d;
  v33 = *(float *)&v34.m_object;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v5,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    (const vostok::render::shader_constant_host *)m_surface_3d,
    (const vostok::math::float3 *)&v33);
  v9 = (float)(s_bm_current_air_resistance / *(float *)(v4 + 492)) * *(float *)&v34.m_object;
  v32.m_object = (vostok::render::render_target *)&v33;
  m_rt = a2.m_object[4].m_rt;
  v33 = v9;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v10,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    (const vostok::render::shader_constant_host *)m_rt,
    (const vostok::math::float3 *)&v33);
  m_object = a2.m_object->m_name.m_pointer.m_object;
  v32.m_object = (vostok::render::render_target *)&v34;
  if ( fist_pass )
  {
    t = vostok::render::renderer_context::get_t(
          (vostok::render::renderer_context *)m_object,
          rt_frame_luminance0,
          (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v32.m_object);
    vostok::render::backend::set_ps_texture(
      v13,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_previous_luminance",
      t->m_object);
    if ( *(float *)&v34.m_object != 0.0 )
    {
      v15 = v34.m_object->m_reference_count-- == 1;
      if ( v15 )
        vostok::render::resource_manager::release(
          v14,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v34.m_object);
    }
    fist_pass = 0;
  }
  else
  {
    v16 = vostok::render::renderer_context::get_t(
            (vostok::render::renderer_context *)m_object,
            rt_frame_luminance_previous,
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v32.m_object);
    vostok::render::backend::set_ps_texture(
      v17,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_previous_luminance",
      v16->m_object);
    if ( *(float *)&v34.m_object != 0.0 )
    {
      v15 = v34.m_object->m_reference_count-- == 1;
      if ( v15 )
        vostok::render::resource_manager::release(
          v18,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v34.m_object);
    }
  }
  v19 = vostok::render::renderer_context::get_t(
          (vostok::render::renderer_context *)a2.m_object->m_name.m_pointer.m_object,
          rt_frame_luminance0,
          &v34);
  vostok::render::backend::set_ps_texture(
    v20,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_current_luminanace",
    v19->m_object);
  if ( *(float *)&v34.m_object != 0.0 )
  {
    v15 = v34.m_object->m_reference_count-- == 1;
    if ( v15 )
      vostok::render::resource_manager::release(
        v21,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v34.m_object);
  }
  v32.m_object = (vostok::render::render_target *)v21;
  vostok::render::renderer_context::get_rt(
    (vostok::render::renderer_context *)a2.m_object->m_name.m_pointer.m_object,
    rt_frame_luminance_current,
    &v32);
  vostok::render::stage_postprocess::fill_surface2(v22, a2, v32.m_object);
  vostok::render::backend::flush_rt_shader_resources(
    v23,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
  v24 = a2.m_object[1].m_order;
  *(_DWORD *)(v24 + 22048) = 1;
  vostok::render::res_effect::apply_pass(v25, v24);
  v26 = vostok::render::renderer_context::get_t(
          (vostok::render::renderer_context *)a2.m_object->m_name.m_pointer.m_object,
          rt_frame_luminance_current,
          &v34);
  vostok::render::backend::set_ps_texture(
    v27,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    "t_luminance",
    v26->m_object);
  if ( *(float *)&v34.m_object != 0.0 )
  {
    v15 = v34.m_object->m_reference_count-- == 1;
    if ( v15 )
      vostok::render::resource_manager::release(
        v28,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        v34.m_object);
  }
  v32.m_object = (vostok::render::render_target *)v28;
  vostok::render::renderer_context::get_rt(
    (vostok::render::renderer_context *)a2.m_object->m_name.m_pointer.m_object,
    rt_frame_luminance_previous,
    &v32);
  vostok::render::stage_postprocess::fill_surface2(v29, a2, v32.m_object);
}
