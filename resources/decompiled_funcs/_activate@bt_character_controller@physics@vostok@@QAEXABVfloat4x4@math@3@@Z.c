void __userpurge vostok::physics::bt_character_controller::activate(
        const vostok::math::float4x4 *t@<esi>,
        vostok::physics::bt_character_controller *this)
{
  const btTransform *v2; // eax
  btMatrix3x3 *v3; // ecx

  vostok::physics::bullet_character_controller::insert(this->m_bt_controller, this->m_bt_physics_world->m_dynamicsWorld);
  v2 = vostok::physics::from_vostok(t);
  vostok::physics::bullet_character_controller::set_transform(this->m_bt_controller, v2, v3);
}
