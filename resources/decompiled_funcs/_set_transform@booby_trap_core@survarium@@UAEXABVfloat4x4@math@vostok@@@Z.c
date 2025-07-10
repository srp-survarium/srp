void __thiscall survarium::booby_trap_core::set_transform(
        survarium::booby_trap_core *this,
        const vostok::math::float4x4 *transform)
{
  survarium::game_camera *v2; // ecx

  qmemcpy((void *)&this->m_transform, transform, sizeof(this->m_transform));
  (*(void (__thiscall **)(survarium::collision_geometry *, const vostok::math::float4x4 *))(**(_DWORD **)this->survarium::collision_sensor::m_collision_geometries
                                                                                          + 16))(
    *this->survarium::collision_sensor::m_collision_geometries,
    transform);
  (*(void (__thiscall **)(survarium::collision_geometry *, const vostok::math::float4x4 *))(**(_DWORD **)this->survarium::usable_object::m_collision_geometries
                                                                                          + 16))(
    *this->survarium::usable_object::m_collision_geometries,
    transform);
  survarium::weapon_user_dead_state::finalize(v2);
  if ( survarium::booby_trap_set_core::config((survarium::booby_trap_set_core *)this, (int)this->m_owner)->defuse_by_hit )
    survarium::hittable_object::set_transform(&this->survarium::hittable_object, transform);
}
