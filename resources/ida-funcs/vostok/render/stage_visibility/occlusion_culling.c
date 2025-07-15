void __usercall vostok::render::stage_visibility::occlusion_culling(
        vostok::render::stage_visibility *this@<ecx>,
        vostok::render::stage_visibility *a2@<esi>)
{
  vostok::render::stage_visibility *v2; // ecx
  vostok::render::stage_visibility *v3; // ecx
  unsigned int v4; // edi
  vostok::render::hw_hiz_occlusion_manager *m_occlusion_manager; // eax
  vostok::render::renderer_context *m_context; // [esp-8h] [ebp-14h]
  const vostok::math::float4 *m_static_bounds_array; // [esp-4h] [ebp-10h]
  unsigned int occlusion_info_index_iterator; // [esp+4h] [ebp-8h] BYREF
  vostok::math::float4 *bounds_it; // [esp+8h] [ebp-4h] BYREF

  bounds_it = a2->m_static_bounds_array;
  occlusion_info_index_iterator = 0;
  vostok::render::stage_visibility::get_results_and_prepare_bounds_models(
    &occlusion_info_index_iterator,
    a2,
    &bounds_it);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_lights(
    v2,
    (vostok::math::float4 **)a2,
    &bounds_it,
    (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&occlusion_info_index_iterator);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_grass(
    (vostok::render::stage_visibility *)&occlusion_info_index_iterator,
    (vostok::math::float4 **)a2,
    &bounds_it,
    (vostok::render::grass_patch **)&occlusion_info_index_iterator);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_decals(
    (vostok::fixed_string<512> *(__thiscall **)(struct vostok::resources::resource_base *, vostok::fixed_string<512> *))&occlusion_info_index_iterator,
    a2,
    &bounds_it);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_env_probes(
    &occlusion_info_index_iterator,
    a2,
    &bounds_it);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_ambient_volumes(
    &occlusion_info_index_iterator,
    a2,
    &bounds_it);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_particles(
    (vostok::render::stage_visibility *)&bounds_it,
    (vostok::math::float4 **)a2,
    &bounds_it,
    (vostok::particle::render_particle_emitter_instance **)&occlusion_info_index_iterator);
  vostok::render::stage_visibility::get_results_and_prepare_bounds_portals(
    v3,
    a2,
    &bounds_it,
    &occlusion_info_index_iterator);
  v4 = occlusion_info_index_iterator;
  m_occlusion_manager = a2->m_occlusion_manager;
  m_static_bounds_array = a2->m_static_bounds_array;
  m_context = a2->m_context;
  a2->m_current_occlusion_buffer_size = occlusion_info_index_iterator;
  vostok::render::hw_hiz_occlusion_manager::process_culling(m_occlusion_manager, m_context, m_static_bounds_array, v4);
}
