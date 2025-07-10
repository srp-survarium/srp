void __userpurge vostok::physics::bt_character_controller::set_walk_direction(
        const vostok::math::float3 *direction@<eax>,
        vostok::physics::bt_character_controller *this)
{
  vostok::physics::bullet_character_controller *m_bt_controller; // ecx
  btVector3 walk_vector; // [esp+0h] [ebp-10h] BYREF

  walk_vector.mVec128.m128_u64[0] = *(_QWORD *)&direction->x;
  m_bt_controller = this->m_bt_controller;
  walk_vector.mVec128.m128_f32[2] = -direction->z;
  walk_vector.mVec128.m128_i32[3] = 0;
  vostok::physics::bullet_character_controller::set_desired_walk_vector(&walk_vector, m_bt_controller);
}
