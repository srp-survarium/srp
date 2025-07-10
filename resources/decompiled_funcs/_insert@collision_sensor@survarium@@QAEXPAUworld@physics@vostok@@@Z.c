void __thiscall survarium::collision_sensor::insert(survarium::collision_sensor *this, vostok::physics::world *world)
{
  unsigned int i; // [esp+8h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_is_active = 1;
  for ( i = 0; i < this->m_collision_geometries_count; ++i )
    survarium::collision_geometry::subscribe(this->m_collision_geometries[i], world, this);
}
