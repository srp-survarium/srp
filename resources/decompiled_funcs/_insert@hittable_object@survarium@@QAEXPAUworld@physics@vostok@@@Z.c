void __thiscall survarium::hittable_object::insert(survarium::hittable_object *this, vostok::physics::world *world)
{
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  this->m_physics_world = world;
  this->m_rigid_body->user_data = this;
  world->add(world, this->m_rigid_body, this->m_group, this->m_mask);
}
