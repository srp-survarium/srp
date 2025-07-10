unsigned int *__thiscall vostok::buffer_vector<unsigned int>::operator[](
        vostok::buffer_vector<unsigned int> *this,
        unsigned int index)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return &this->m_begin[index];
}
