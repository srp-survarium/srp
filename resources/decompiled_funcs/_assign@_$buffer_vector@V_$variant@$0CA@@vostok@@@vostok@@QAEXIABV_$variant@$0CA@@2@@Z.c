void __thiscall vostok::buffer_vector<vostok::variant<32>>::assign(
        vostok::buffer_vector<vostok::variant<32> > *this,
        unsigned int count,
        const vostok::variant<32> *value)
{
  vostok::variant<32> *v3; // ecx
  vostok::variant<32> *I; // [esp+10h] [ebp-4h]

  vostok::buffer_vector<vostok::variant<32>>::destroy(this->m_begin, &this->m_end);
  v3 = &this->m_begin[count];
  this->m_end = v3;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
  for ( I = this->m_begin; I != this->m_end; ++I )
    vostok::buffer_vector<vostok::variant<32>>::construct(I, value);
}
