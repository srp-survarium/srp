void __thiscall survarium::hittable_object::remove(survarium::hittable_object *this)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  this->m_physics_world->remove(this->m_physics_world, this->m_rigid_body);
  this->m_physics_world = 0;
}
