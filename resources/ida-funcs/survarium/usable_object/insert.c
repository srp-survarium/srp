void __thiscall survarium::usable_object::insert(survarium::usable_object *this, vostok::physics::world *world)
{
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < this->m_collision_geometries_count; ++i )
    survarium::collision_geometry::subscribe(this->m_collision_geometries[i], world, this);
}
