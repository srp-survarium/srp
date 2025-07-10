void __thiscall survarium::usable_object::remove(survarium::usable_object *this)
{
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < this->m_collision_geometries_count; ++i )
    survarium::collision_geometry::unsubscribe(this->m_collision_geometries[i], this);
}
