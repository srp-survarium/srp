void __usercall vostok::render::renderer::perform_surfaces_clearing(vostok::render::renderer *this@<ecx>, int a2@<esi>)
{
  vostok::render::render_target *m_object; // ebx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  vostok::render::render_target *v4; // eax
  vostok::render::render_target *v5; // eax
  vostok::render::render_target *v6; // eax
  unsigned __int8 v7; // bl
  vostok::render::backend *v8; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v9; // eax
  vostok::render::backend *v10; // ecx
  vostok::render::render_target *v11; // eax
  vostok::render::render_target *v12; // ebx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v13; // eax
  vostok::render::backend *v14; // ecx
  vostok::render::render_target *v15; // eax
  vostok::render::render_target *v16; // eax
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v17; // eax
  vostok::render::backend *v18; // ecx
  vostok::render::render_target *v19; // eax
  int z_low; // eax
  vostok::render::untyped_buffer *v21; // edx
  vostok::render::backend *v22; // ecx
  _DWORD *i; // ebx
  float v24; // [esp+Ch] [ebp-18h]
  unsigned __int8 v25; // [esp+10h] [ebp-14h]
  vostok::render::render_target *v26; // [esp+14h] [ebp-10h]
  vostok::render::render_target *v27; // [esp+18h] [ebp-Ch] BYREF
  vostok::render::render_target *v28; // [esp+1Ch] [ebp-8h] BYREF
  vostok::render::render_target *rt; // [esp+20h] [ebp-4h] BYREF

  m_object = vostok::render::renderer_context::get_rt(
               *(vostok::render::renderer_context **)(a2 + 480),
               rt_sun_translucensy_help_data,
               (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v27)->m_object;
  v26 = vostok::render::renderer_context::get_rt(
          *(vostok::render::renderer_context **)(a2 + 480),
          rt_accumulator_specular,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v28)->m_object;
  v3 = vostok::render::renderer_context::get_rt(
         *(vostok::render::renderer_context **)(a2 + 480),
         rt_accumulator_diffuse,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v3->m_object,
    v26,
    m_object,
    0);
  v4 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v4->m_reference_count )
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  v5 = v28;
  if ( v28 )
  {
    --v28->m_reference_count;
    if ( !v5->m_reference_count )
      vostok::render::resource_manager::release(v28, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  v6 = v27;
  if ( v27 )
  {
    --v27->m_reference_count;
    if ( !v6->m_reference_count )
      vostok::render::resource_manager::release(v27, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  v7 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 0.0);
  vostok::render::backend::clear_render_targets(
    v8,
    LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.elements[2]),
    v7);
  v9 = vostok::render::renderer_context::get_rt(
         *(vostok::render::renderer_context **)(a2 + 480),
         rt_particle_lighting,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v27);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v9->m_object,
    0,
    0,
    0);
  v11 = v27;
  if ( v27 )
  {
    --v27->m_reference_count;
    if ( !v11->m_reference_count )
      vostok::render::resource_manager::release(v27, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  vostok::render::backend::clear_render_targets(
    v10,
    LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.elements[2]),
    v7);
  v12 = vostok::render::renderer_context::get_rt(
          *(vostok::render::renderer_context **)(a2 + 480),
          rt_generic_1,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v28)->m_object;
  v13 = vostok::render::renderer_context::get_rt(
          *(vostok::render::renderer_context **)(a2 + 480),
          rt_generic_0,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v27);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v13->m_object,
    v12,
    0,
    0);
  v15 = v27;
  if ( v27 )
  {
    --v27->m_reference_count;
    if ( !v15->m_reference_count )
      vostok::render::resource_manager::release(v27, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  v16 = v28;
  if ( v28 )
  {
    --v28->m_reference_count;
    if ( !v16->m_reference_count )
      vostok::render::resource_manager::release(v28, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  vostok::render::backend::clear_render_targets(
    v14,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    0,
    0.0,
    0.0,
    0.0);
  v17 = vostok::render::renderer_context::get_rt(
          *(vostok::render::renderer_context **)(a2 + 480),
          rt_lpv_accumulation,
          (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v27);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v17->m_object,
    0,
    0,
    0);
  v19 = v27;
  if ( v27 )
  {
    --v27->m_reference_count;
    if ( !v19->m_reference_count )
      vostok::render::resource_manager::release(v27, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
  }
  vostok::render::backend::clear_render_targets(
    v18,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    0,
    0.0,
    0.0,
    0.0);
  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  v21 = *(vostok::render::untyped_buffer **)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                           + 7440);
  v22 = (vostok::render::backend *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)
                                  + 7384);
  *(_BYTE *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 117) |= *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7384) != (_DWORD)v21;
  v22->vertex_small.m_buffer.m_object = v21;
  vostok::render::backend::clear_depth_stencil(v22, z_low, 3u, v24, v25);
  for ( i = *(_DWORD **)(a2 + 344); i != *(_DWORD **)(a2 + 348); ++i )
  {
    if ( *i )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*i + 16))(*i);
  }
}
