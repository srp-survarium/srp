void __thiscall vostok::fixed_vector<vostok::console_commands::command_token,12>::fixed_vector<vostok::console_commands::command_token,12>(
        vostok::fixed_vector<stlp_std::pair<char *,unsigned int>,32> *this)
{
  this->m_begin = (stlp_std::pair<char *,unsigned int> *)this->m_buffer;
  this->m_end = (stlp_std::pair<char *,unsigned int> *)this->m_buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
