void __thiscall vostok::physics::old_bullet_character_controller::deserialize(
        vostok::physics::old_bullet_character_controller *this,
        vostok::physics::old_bullet_character_controller *reader,
        vostok::network_core::buffer_reader *current_time_in_ms)
{
  bool v3; // al
  const unsigned __int8 *m_pointer; // esi
  int v5; // xmm0_4
  int v6; // [esp+14h] [ebp-1Ch]
  int v7; // [esp+24h] [ebp-Ch]

  reader->m_jumping = vostok::network_core::buffer_reader::r<bool>(current_time_in_ms);
  v3 = vostok::network_core::buffer_reader::r<bool>(current_time_in_ms);
  vostok::physics::old_bullet_character_controller::setup_crouch_state(v3, reader, 0);
  m_pointer = current_time_in_ms->m_pointer;
  v6 = *(_DWORD *)m_pointer;
  m_pointer += 4;
  v7 = *(_DWORD *)m_pointer;
  v5 = *((_DWORD *)m_pointer + 1);
  current_time_in_ms->m_pointer += 12;
  reader->m_fall_and_slide_velocity.mVec128.m128_i32[0] = v6;
  reader->m_fall_and_slide_velocity.mVec128.m128_i32[1] = v7;
  reader->m_fall_and_slide_velocity.mVec128.m128_u64[1] = v5 ^ (unsigned int)_mask__NegFloat_;
}
