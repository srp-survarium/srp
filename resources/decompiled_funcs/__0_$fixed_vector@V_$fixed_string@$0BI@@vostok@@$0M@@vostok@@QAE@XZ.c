void __thiscall vostok::fixed_vector<vostok::fixed_string<24>,12>::fixed_vector<vostok::fixed_string<24>,12>(
        vostok::fixed_vector<vostok::fixed_string<24>,12> *this)
{
  this->m_begin = (vostok::fixed_string<24> *)this->m_buffer;
  this->m_end = (vostok::fixed_string<24> *)this->m_buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
