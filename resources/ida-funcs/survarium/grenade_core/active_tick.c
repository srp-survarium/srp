void __thiscall survarium::grenade_core::active_tick(
        survarium::grenade_core *this,
        const unsigned int time_delta_ms,
        const unsigned int current_time)
{
  vostok::physics::world **p_m_physics_world; // esi
  vostok::physics::world_vtbl *v4; // edi
  btCollisionObject *v5; // eax

  p_m_physics_world = &this->m_physics_world;
  if ( this->m_physics_world )
  {
    v4 = (*p_m_physics_world)->__vftable;
    v5 = this->m_rigid_body->get_bt_collision_obect(this->m_rigid_body);
    v4->update_single_aabb(*p_m_physics_world, v5);
  }
}
