void __thiscall vostok::buffer_vector<vostok::animation::mixing::animation_interval>::buffer_vector<vostok::animation::mixing::animation_interval>(
        vostok::buffer_vector<vostok::animation::mixing::animation_interval> *this,
        vostok::animation::mixing::animation_interval *buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  this->m_begin = buffer;
  this->m_end = &buffer[live_count];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)buffer);
}
