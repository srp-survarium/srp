void __thiscall vostok::buffer_vector<unsigned int>::assign(
        vostok::buffer_vector<unsigned int> *this,
        unsigned int count,
        const unsigned int *value)
{
  unsigned int *I; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_end = &this->m_begin[count];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  for ( I = this->m_begin; I != this->m_end; ++I )
    vostok::buffer_vector<vostok::variant<32> const *>::construct(
      (const vostok::variant<32> **)I,
      (const vostok::variant<32> *const *)value);
}
