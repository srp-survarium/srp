survarium::loose_ptr_base *__thiscall survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::c_ptr(
        survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *this)
{
  survarium::loose_ptr_base *m_pointer; // eax

  m_pointer = this->m_object->m_pointer;
  if ( m_pointer )
    return m_pointer - 1;
  else
    return 0;
}
