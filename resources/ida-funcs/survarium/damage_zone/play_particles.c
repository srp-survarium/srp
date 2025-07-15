void __thiscall survarium::damage_zone::play_particles(
        survarium::damage_zone *this,
        const survarium::damage_zone *particles,
        const survarium::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > *particlesa)
{
  unsigned int v3; // esi
  vostok::math::float3 *M_start; // edi
  unsigned int v5; // ebx
  const vostok::math::float3 *v6; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v7; // edi
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v9; // [esp-8h] [ebp-68h]
  const vostok::math::float4x4 *v10; // [esp-4h] [ebp-64h]
  int v11; // [esp+Ch] [ebp-54h]
  vostok::vectora<vostok::math::float3> shapes_centers; // [esp+10h] [ebp-50h] BYREF
  vostok::math::float4x4 result; // [esp+20h] [ebp-40h] BYREF

  v3 = 0;
  shapes_centers._M_impl._M_start = 0;
  shapes_centers._M_impl._M_finish = 0;
  shapes_centers._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  shapes_centers._M_impl._M_end_of_storage._M_data = 0;
  survarium::collision_sensor::get_shapes_centers(&particles->survarium::damage_zone_core, &shapes_centers);
  M_start = shapes_centers._M_impl._M_start;
  v5 = shapes_centers._M_impl._M_finish - shapes_centers._M_impl._M_start;
  if ( v5 )
  {
    v11 = 0;
    do
    {
      v6 = &M_start[v11];
      v7 = particlesa->_M_impl._M_start;
      v10 = vostok::math::create_translation(&result, v6);
      v9.m_object = 0;
      m_object = v7[v3].m_object;
      if ( m_object )
      {
        v9.m_object = v7[v3].m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      vostok::render::scene_renderer::play_particle_system(
        (vostok::render::scene_renderer *)&particles->m_game_world->m_render_scene,
        &particles->m_game_world->m_render_scene,
        v9,
        v10);
      ++v11;
      M_start = shapes_centers._M_impl._M_start;
      ++v3;
    }
    while ( v3 < v5 );
  }
  if ( M_start )
    shapes_centers._M_impl._M_end_of_storage.m_allocator->call_free(
      shapes_centers._M_impl._M_end_of_storage.m_allocator,
      M_start);
}
