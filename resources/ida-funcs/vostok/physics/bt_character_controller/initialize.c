void __userpurge vostok::physics::bt_character_controller::initialize(
        vostok::physics::bt_character_controller *this@<ecx>,
        unsigned int a2@<edi>,
        const btTransform **transform,
        vostok::math::float4x4 *current_time_in_ms,
        unsigned __int8 id)
{
  vostok::physics::bullet_character_controller *v5; // ecx
  const btTransform *v6; // ebx
  vostok::physics::bt_character_controller *v7; // ecx
  vostok::physics::old_bullet_character_controller *v8; // esi

  v5 = (vostok::physics::bullet_character_controller *)*transform;
  v5->m_player_id = id;
  v6 = *transform;
  v6->m_basis.m_el[2].mVec128.m128_i32[0] = 0;
  v6->m_basis.m_el[2].mVec128.m128_i32[1] = 0;
  v6->m_basis.m_el[2].mVec128.m128_i32[2] = 0;
  v6->m_basis.m_el[2].mVec128.m128_i32[3] = 0;
  v6->m_origin.mVec128.m128_i32[0] = 0;
  v6->m_origin.mVec128.m128_i32[1] = 0;
  v6->m_origin.mVec128.m128_i32[2] = 0;
  v6->m_origin.mVec128.m128_i32[3] = 0;
  v6[19].m_basis.m_el[1].mVec128.m128_i32[0] = 0;
  v6[19].m_basis.m_el[1].mVec128.m128_i32[1] = 0;
  v6[19].m_basis.m_el[1].mVec128.m128_i32[2] = 0;
  v6[19].m_basis.m_el[1].mVec128.m128_i32[3] = 0;
  v6[7].m_origin.mVec128.m128_i8[1] = 0;
  v6[7].m_origin.mVec128.m128_i8[0] = 0;
  vostok::physics::bullet_character_controller::setup_crouch_state(v5, (int)v6, 0);
  v6[18].m_basis.m_el[0].mVec128.m128_i8[12] = 0;
  v6[18].m_basis.m_el[1] = (btVector3)vostok::physics::bullet_character_controller::ms_up_vector.mVec128;
  v6[7].m_origin.mVec128.m128_i8[4] = 0;
  vostok::physics::bt_character_controller::set_transform(v7, transform, current_time_in_ms, a2);
  transform[1][10].m_basis.m_el[0].mVec128.m128_i8[0] = id;
  v8 = (vostok::physics::old_bullet_character_controller *)transform[1];
  v8->m_walk_vector.mVec128.m128_i32[0] = 0;
  v8->m_walk_vector.mVec128.m128_i32[1] = 0;
  v8->m_walk_vector.mVec128.m128_i32[2] = 0;
  v8->m_walk_vector.mVec128.m128_i32[3] = 0;
  v8->m_air_control_vector.mVec128.m128_i32[0] = 0;
  v8->m_air_control_vector.mVec128.m128_i32[1] = 0;
  v8->m_air_control_vector.mVec128.m128_i32[2] = 0;
  v8->m_air_control_vector.mVec128.m128_i32[3] = 0;
  v8->m_normalizedDirection.mVec128.m128_i32[0] = 0;
  v8->m_normalizedDirection.mVec128.m128_i32[1] = 0;
  v8->m_normalizedDirection.mVec128.m128_i32[2] = 0;
  v8->m_normalizedDirection.mVec128.m128_i32[3] = 0;
  v8->m_walk_vector_applied = 0;
  v8->m_has_updates = 0;
  vostok::physics::old_bullet_character_controller::setup_crouch_state(0, v8, 1);
  v8->m_fall_and_slide_velocity.mVec128.m128_i32[0] = 0;
  v8->m_fall_and_slide_velocity.mVec128.m128_i32[1] = 0;
  v8->m_fall_and_slide_velocity.mVec128.m128_i32[2] = 0;
  v8->m_fall_and_slide_velocity.mVec128.m128_i32[3] = 0;
  v8->m_jumping = 0;
}
