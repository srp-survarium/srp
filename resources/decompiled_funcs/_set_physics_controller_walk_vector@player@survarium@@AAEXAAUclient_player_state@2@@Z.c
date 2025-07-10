void __thiscall survarium::player::set_physics_controller_walk_vector(
        survarium::player *this,
        survarium::client_player_state *state)
{
  btTransform *transform; // eax
  vostok::physics::bt_character_controller *physics_controller; // ecx
  const btTransform *v4; // eax
  btMatrix3x3 *v5; // ecx
  vostok::physics::bullet_character_controller *m_bt_controller; // ecx
  unsigned int v7; // xmm1_4
  unsigned int v8; // xmm2_4
  vostok::physics::bullet_character_controller **p_m_bt_controller; // [esp+8Ch] [ebp-D4h]
  btVector3 walk_vector; // [esp+90h] [ebp-D0h] BYREF
  __int64 v11; // [esp+D0h] [ebp-90h]
  float v12; // [esp+D8h] [ebp-88h]
  vostok::math::float4x4 m; // [esp+E0h] [ebp-80h] BYREF

  transform = vostok::physics::bullet_character_controller::get_transform(
                (vostok::physics::bullet_character_controller *)state->physics_controller,
                (btTransform *)&m,
                (int)state->physics_controller->m_bt_controller);
  vostok::physics::from_bullet(transform);
  qmemcpy((void *)&m, &state->transform, sizeof(m));
  physics_controller = state->physics_controller;
  *(_QWORD *)&m.lines[3].x = v11;
  m.c.z = v12;
  p_m_bt_controller = &physics_controller->m_bt_controller;
  v4 = vostok::physics::from_vostok(&m);
  vostok::physics::bullet_character_controller::set_transform(*p_m_bt_controller, v4, v5);
  m_bt_controller = state->physics_controller->m_bt_controller;
  *(float *)&v7 = state->transform.c.x - *(float *)&v11;
  *(float *)&v8 = state->transform.c.y - *((float *)&v11 + 1);
  walk_vector.mVec128.m128_f32[2] = -(float)(state->transform.c.z - v12);
  walk_vector.mVec128.m128_u64[0] = __PAIR64__(v8, v7);
  walk_vector.mVec128.m128_i32[3] = 0;
  vostok::physics::bullet_character_controller::set_desired_walk_vector(&walk_vector, m_bt_controller);
}
