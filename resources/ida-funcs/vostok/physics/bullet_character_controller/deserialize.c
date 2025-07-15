void __thiscall vostok::physics::bullet_character_controller::deserialize(
        vostok::physics::bullet_character_controller *this,
        vostok::physics::bullet_character_controller *reader,
        vostok::network_core::buffer_reader *current_time_in_ms)
{
  const unsigned __int8 *m_pointer; // eax
  int v4; // xmm0_4
  const unsigned __int8 *v5; // esi
  bool v6; // al
  bool v7; // zf
  const vostok::math::float2 *p_m_crouch_shape_dim; // eax
  int v9; // [esp+14h] [ebp-1Ch]
  int v10; // [esp+1Ch] [ebp-14h]
  unsigned __int64 v11; // [esp+20h] [ebp-10h]
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  reader->m_jumping = vostok::network_core::buffer_reader::r<bool>(current_time_in_ms);
  reader->m_input_is_in_crouch = vostok::network_core::buffer_reader::r<bool>(current_time_in_ms);
  reader->m_logic_is_in_crouch = vostok::network_core::buffer_reader::r<bool>(current_time_in_ms);
  reader->m_capsule_is_in_crouch = vostok::network_core::buffer_reader::r<bool>(current_time_in_ms);
  reader->m_can_stand = vostok::network_core::buffer_reader::r<bool>(current_time_in_ms);
  m_pointer = current_time_in_ms->m_pointer;
  v11 = *(_QWORD *)m_pointer;
  v4 = *((_DWORD *)m_pointer + 2);
  current_time_in_ms->m_pointer = m_pointer + 12;
  reader->m_fall_and_slide_velocity.mVec128.m128_u64[0] = v11;
  reader->m_fall_and_slide_velocity.mVec128.m128_u64[1] = v4 ^ (unsigned int)_mask__NegFloat_;
  v5 = current_time_in_ms->m_pointer;
  v9 = *(_DWORD *)v5;
  v5 += 4;
  v10 = *((_DWORD *)v5 + 1);
  HIDWORD(v11) = *(_DWORD *)v5;
  current_time_in_ms->m_pointer += 12;
  reader->m_supporting_surface_normal.mVec128.m128_i32[0] = v9;
  reader->m_supporting_surface_normal.mVec128.m128_i32[1] = HIDWORD(v11);
  reader->m_supporting_surface_normal.mVec128.m128_u64[1] = v10 ^ (unsigned int)_mask__NegFloat_;
  v6 = vostok::network_core::buffer_reader::r<bool>(current_time_in_ms);
  v7 = !reader->m_capsule_is_in_crouch;
  reader->m_is_sprinting = v6;
  p_m_crouch_shape_dim = &reader->m_crouch_shape_dim;
  if ( v7 )
    p_m_crouch_shape_dim = &reader->m_stand_shape_dim;
  vostok::physics::bullet_character_controller::setup_shape_dim(
    p_m_crouch_shape_dim,
    (int)reader,
    (int)&reader->m_harmless_fall_speed,
    (int)&savedregs,
    reader);
}
