unsigned int *__thiscall vostok::buffer_vector<unsigned int>::operator[](
        vostok::buffer_vector<unsigned int> *this,
        unsigned int index)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return &this->m_begin[index];
}


vostok::variant<32> *__usercall vostok::buffer_vector<vostok::variant<32>>::operator[]@<eax>(
        vostok::buffer_vector<vostok::variant<32> > *this@<ecx>,
        unsigned int index@<eax>)
{
  return &this->m_begin[index];
}
