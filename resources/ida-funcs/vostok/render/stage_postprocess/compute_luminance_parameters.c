vostok::math::float4 *__usercall vostok::render::stage_postprocess::compute_luminance_parameters@<eax>(
        vostok::render::stage_postprocess *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> a2@<eax>,
        vostok::math::float4 *a3@<edi>,
        float *a4@<esi>)
{
  vostok::render::renderer_context *m_object; // ecx
  int v6; // ebx
  vostok::render::enum_render_target_index *t; // eax
  vostok::render::stage_postprocess *v8; // ecx
  vostok::render::resource_manager *v9; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v13; // [esp+4h] [ebp-4h] BYREF

  m_object = (vostok::render::renderer_context *)a2.m_object->m_name.m_pointer.m_object;
  v6 = (int)&m_object->m_scene_view.m_object[1];
  *a4 = FLOAT_0_25;
  a4[1] = FLOAT_0_25;
  a4[2] = FLOAT_0_25;
  a4[3] = FLOAT_0_25;
  t = (vostok::render::enum_render_target_index *)vostok::render::renderer_context::get_t(m_object, rt_generic_0, &v13);
  vostok::render::stage_postprocess::measure_per_pixel_luminance(v8, a2, *t, a3);
  if ( *(float *)&v13.m_object != 0.0 && v13.m_object->m_reference_count-- == 1 )
    vostok::render::resource_manager::release(
      v9,
      (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      v13.m_object);
  v13.m_object = *(vostok::render::res_texture **)(v6 + 492);
  v13.m_object = (vostok::render::res_texture *)((unsigned int)v13.m_object & 0x7FFFFFFF);
  if ( *(float *)&v13.m_object >= 0.050000001 )
    vostok::render::stage_postprocess::compute_per_pixel_eye_adaptated_luminance(
      (vostok::render::stage_postprocess *)v9,
      a2);
  return (vostok::math::float4 *)a4;
}
