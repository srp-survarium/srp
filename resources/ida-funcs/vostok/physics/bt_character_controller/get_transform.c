vostok::math::float4x4 *__usercall vostok::physics::bt_character_controller::get_transform@<eax>(
        vostok::physics::bt_character_controller *this@<ecx>,
        int a2@<eax>)
{
  btTransform *transform; // eax
  btTransform v5; // [esp+10h] [ebp-40h] BYREF

  transform = vostok::physics::bullet_character_controller::get_transform(
                (vostok::physics::bullet_character_controller *)this,
                &v5,
                (int)this->m_bt_controller);
  vostok::physics::from_bullet(transform);
  return (vostok::math::float4x4 *)a2;
}
