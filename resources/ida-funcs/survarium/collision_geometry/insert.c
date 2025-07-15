void __thiscall survarium::collision_geometry::insert(
        survarium::collision_geometry *this,
        vostok::physics::world *world)
{
  this->m_physics_world = world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)world);
  this->m_ghost_object->user_data = this;
  vostok::physics::bt_ghost_object::insert(this->m_physics_world, this->m_ghost_object, this->m_group, this->m_mask);
}
