void __thiscall survarium::collision_sensor::get_shapes_centers(
        survarium::collision_sensor *this,
        vostok::vectora<vostok::math::float3> *centers)
{
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < this->m_collision_geometries_count; ++i )
    survarium::collision_geometry::get_shapes_centers(this->m_collision_geometries[i], centers);
}
