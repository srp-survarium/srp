void __userpurge vostok::render::stage_light_propagation_volumes::inject_occluders(
        vostok::render::stage_light_propagation_volumes *this@<ecx>,
        int a2@<eax>,
        const vostok::math::float3 *cascade_index,
        const vostok::math::float3 *light_position,
        vostok::math::float3 *light_direction,
        vostok::render::vector<vostok::math::float4x4> transforms)
{
  int v7; // edi
  vostok::render::radiance_volume *v8; // ecx
  vostok::math::float3 *v9; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi

  v7 = 476 * (_DWORD)this;
  vostok::render::radiance_volume::inject_occluders(
    *(vostok::render::radiance_volume **)(a2 + 4),
    476 * (_DWORD)this + *(_DWORD *)(a2 + 44),
    *(vostok::render::renderer_context **)(a2 + 4),
    cascade_index,
    light_position,
    *(_DWORD *)(a2 + 56));
  vostok::render::radiance_volume::inject_occluder_geometry(
    v8,
    v7 + *(_DWORD *)(a2 + 44),
    *(vostok::render::renderer_context **)(a2 + 4),
    cascade_index,
    light_position,
    (const vostok::render::vector<vostok::math::float4x4> *)&light_direction);
  v9 = light_direction;
  if ( light_direction )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v9);
  }
}
