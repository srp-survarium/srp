void __thiscall survarium::collision_geometry::get_overlapping_objects(
        survarium::collision_geometry *this,
        vostok::physics::bt_ghost_object *result)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::physics::bt_ghost_object::get_overlapping_objects(result, this->m_ghost_object, result);
}
