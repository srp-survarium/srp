void __thiscall survarium::game_world::play_particle(
        survarium::game_world *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *particle,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        const vostok::math::float3 *normal)
{
  __int64 v6; // xmm0_8
  float z; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp-8h] [ebp-58h] BYREF
  const vostok::math::float4x4 *p_m; // [esp-4h] [ebp-54h]
  vostok::math::float4x4 m; // [esp+10h] [ebp-40h] BYREF

  vostok::math::create_rotation(direction, normal, &m);
  v6 = *(_QWORD *)&position->x;
  z = position->z;
  p_m = &m;
  *(_QWORD *)&m.lines[3].x = v6;
  m.c.z = z;
  v8.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v8,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)particle);
  vostok::render::scene_renderer::play_particle_system(
    *(vostok::render::scene_renderer **)(this[-1].m_input_mode + 148),
    *(_DWORD *)(*(_DWORD *)(this[-1].m_input_mode + 148) + 16),
    (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)&this[-1].m_enemies_for_team_1._M_impl._M_finish,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v8.m_object,
    p_m);
}
