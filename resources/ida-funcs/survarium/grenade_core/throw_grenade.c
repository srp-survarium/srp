void __thiscall survarium::grenade_core::throw_grenade(
        survarium::grenade_core *this,
        const vostok::math::float4x4 *transform,
        const vostok::math::float3 *impulse)
{
  vostok::physics::bt_dynamic_rigid_body *m_rigid_body; // ecx
  vostok::physics::bt_dynamic_rigid_body *v5; // ecx
  vostok::math::float3 v6; // [esp+10h] [ebp-Ch] BYREF

  survarium::grenade_set_core::current_time_in_ms((survarium::grenade_set_core *)this, (int)this->m_owner);
  m_rigid_body = this->m_rigid_body;
  this->m_physics_world = this->m_game_world_core->m_physics_world;
  m_rigid_body->set_transform(m_rigid_body, transform);
  this->m_rigid_body->user_data = &this->vostok::collision::game_object;
  this->m_physics_world->add(this->m_physics_world, this->m_rigid_body, 2064u, 8u);
  vostok::physics::bt_dynamic_rigid_body::set_linear_velocity(impulse, this->m_rigid_body);
  v5 = this->m_rigid_body;
  memset(&v6, 0, sizeof(v6));
  vostok::physics::bt_dynamic_rigid_body::set_angular_velocity(v5, &v6);
}
