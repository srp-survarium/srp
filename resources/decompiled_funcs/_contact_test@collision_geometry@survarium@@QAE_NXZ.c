char __thiscall survarium::collision_geometry::contact_test(survarium::collision_geometry *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return vostok::physics::bt_ghost_object::contact_test(
           (vostok::physics::bt_ghost_object *)this,
           (int)this->m_ghost_object,
           this->m_physics_world);
}
