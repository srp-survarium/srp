void __thiscall vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
        vostok::buffer_vector<unsigned int> *this,
        const unsigned int *begin,
        const unsigned int *const *end)
{
  unsigned int *v3; // ecx
  unsigned int *I; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = &this->m_begin[*end - begin];
  this->m_end = v3;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
  I = this->m_begin;
  while ( begin != *end )
    vostok::buffer_vector<vostok::variant<32> const *>::construct(
      (const vostok::variant<32> **)I++,
      (const vostok::variant<32> *const *)begin++);
}
