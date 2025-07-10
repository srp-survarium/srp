void __thiscall survarium::collision_geometry::contact_test(
        survarium::collision_geometry *this,
        vostok::physics::base_physics_object *object,
        vostok::physics::contact_test_predicate *predicate)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::physics::bt_ghost_object::contact_test(object, this->m_ghost_object, this->m_physics_world, predicate);
}
