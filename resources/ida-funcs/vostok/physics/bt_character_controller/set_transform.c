void __userpurge vostok::physics::bt_character_controller::set_transform(
        const vostok::math::float4x4 *transform@<esi>,
        vostok::physics::bt_character_controller *this)
{
  const btTransform *v2; // eax

  v2 = vostok::physics::from_vostok(transform);
  vostok::physics::bullet_character_controller::set_transform(this->m_bt_controller, v2, (btMatrix3x3 *)this);
}
