void __thiscall vostok::render::stage_ambient_lighting::render_ambient_volumes(
        vostok::render::stage_ambient_lighting *this,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> wszName)
{
  vostok::render::render_target *m_object; // ebx
  vostok::render::renderer_context *v3; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *rt; // eax
  float z; // esi
  vostok::render::ambient_volume *v6; // ecx
  vostok::render::render_target *v7; // eax
  int v8; // edi
  bool v9; // zf
  int *v10; // eax
  int v11; // edx
  int m_surface_3d; // eax
  vostok::render::res_effect *v13; // ecx
  vostok::render::res_geometry *v14; // ecx
  vostok::render::backend *v15; // ecx
  vostok::render::res_geometry *v16; // ecx
  float v17; // esi
  vostok::render::backend *v18; // ecx
  vostok::render::backend *v19; // ecx
  int v20; // [esp+10h] [ebp-Ch]
  const vostok::math::float3 *v21; // [esp+10h] [ebp-Ch]
  int *m_memory_type_data; // [esp+14h] [ebp-8h]
  int *m_construct_thread_id; // [esp+18h] [ebp-4h]

  m_object = wszName.m_object;
  pix_event_wrapper_dx11::pix_event_wrapper_dx11(
    (pix_event_wrapper_dx11 *)this,
    (pix_event_wrapper_dx11 *)&wszName.m_object + 3,
    (int)L"render_ambient_volumes");
  v3 = (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object;
  m_construct_thread_id = (int *)v3->m_scene_view.m_object[216].m_construct_thread_id;
  m_memory_type_data = (int *)v3->m_scene_view.m_object[216].m_memory_type_data;
  if ( m_construct_thread_id != m_memory_type_data )
  {
    rt = vostok::render::renderer_context::get_rt(v3, rt_accumulator_diffuse, &wszName);
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      rt->m_object,
      0,
      0,
      0);
    v7 = wszName.m_object;
    if ( wszName.m_object )
    {
      --wszName.m_object->m_reference_count;
      if ( !v7->m_reference_count )
      {
        vostok::render::resource_manager::release(
          wszName.m_object,
          vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
        z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
      }
    }
    v8 = *(_DWORD *)(LODWORD(z) + 7440);
    v9 = *(_DWORD *)(LODWORD(z) + 7384) == v8;
    *(_DWORD *)(LODWORD(z) + 7384) = v8;
    v10 = m_construct_thread_id;
    LOBYTE(v6) = !v9;
    *(_BYTE *)(LODWORD(z) + 117) |= !v9;
    while ( v10 != m_memory_type_data )
    {
      v20 = *v10;
      if ( !vostok::render::ambient_volume::is_occluded(v6, *v10) && *(_BYTE *)(v11 + 72) )
      {
        vostok::render::renderer_context::set_w(
          (const vostok::math::float4x4 *)(v11 + 4),
          (vostok::render::renderer_context *)m_object->m_name.m_pointer.m_object);
        m_surface_3d = (int)m_object->m_surface_3d;
        *(_DWORD *)(m_surface_3d + 22048) = 0;
        vostok::render::res_effect::apply_pass(v13, m_surface_3d);
        vostok::render::res_geometry::apply(v14, m_object[3].m_format);
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          0x24u,
          v15,
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          0,
          0);
        wszName.m_object = 0;
        v21 = (const vostok::math::float3 *)(v20 + 68);
        do
        {
          vostok::render::res_effect::apply((vostok::render::res_effect *)wszName.m_object, m_object->m_memory_usage);
          vostok::render::res_geometry::apply(v16, m_object[3].m_format);
          v17 = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
            v18,
            (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            (const vostok::render::shader_constant_host *)m_object[3].m_name.m_pointer.m_object,
            v21);
          vostok::render::backend::render_indexed(
            (vostok::render::backend *)LODWORD(v17),
            0x24u,
            v19,
            D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
            0,
            0);
          ++wszName.m_object;
        }
        while ( (unsigned int)wszName.m_object < 2 );
      }
      v10 = ++m_construct_thread_id;
    }
  }
  D3DPERF_EndEvent();
}
