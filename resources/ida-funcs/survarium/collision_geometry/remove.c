void __thiscall survarium::collision_geometry::remove(survarium::collision_geometry *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::physics::bt_ghost_object::remove(this->m_physics_world, this->m_ghost_object);
  this->m_physics_world = 0;
}
