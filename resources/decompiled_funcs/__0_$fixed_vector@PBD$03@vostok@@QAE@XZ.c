void __thiscall vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>(
        vostok::fixed_vector<void const *,4> *this)
{
  this->m_begin = (const void **)this->m_buffer;
  this->m_end = (const void **)this->m_buffer;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
