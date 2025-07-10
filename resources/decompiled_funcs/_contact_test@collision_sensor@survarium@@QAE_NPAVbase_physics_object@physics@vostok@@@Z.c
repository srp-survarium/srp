char __thiscall survarium::collision_sensor::contact_test(
        survarium::collision_sensor *this,
        vostok::physics::base_physics_object *__formal)
{
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < this->m_collision_geometries_count; ++i )
  {
    if ( survarium::collision_geometry::contact_test(this->m_collision_geometries[i]) )
      return 1;
  }
  return 0;
}
