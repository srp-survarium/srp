void __userpurge vostok::physics::bt_character_controller::set_transform(
        vostok::physics::bt_character_controller *this@<ecx>,
        const btTransform **a2@<esi>,
        const vostok::math::float4x4 *transform,
        const unsigned int current_time_in_ms)
{
  btTransform *v4; // eax
  btTransform *v5; // eax
  vostok::physics::bullet_character_controller *v6; // [esp-4h] [ebp-44h]
  btMatrix3x3 v7; // [esp+0h] [ebp-40h] BYREF

  v4 = vostok::physics::from_vostok(transform, &v7);
  vostok::physics::bullet_character_controller::set_transform(v6, *a2, &v4->m_basis);
  v5 = vostok::physics::from_vostok(transform, &v7);
  vostok::physics::old_bullet_character_controller::set_transform(
    (vostok::physics::old_bullet_character_controller *)v5,
    a2[1]);
}
