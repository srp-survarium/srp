unsigned int __thiscall survarium::collision_geometry::get_overlapping_objects_count(
        survarium::collision_geometry *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return vostok::physics::bt_ghost_object::get_overlapping_objects_count(
           (vostok::physics::bt_ghost_object *)this,
           (int)this->m_ghost_object);
}
