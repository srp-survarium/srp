void __thiscall vostok::resources::fs_task_erase::call_user_callback(vostok::resources::fs_task_erase *this)
{
  boost::function<void __cdecl(bool)> *p_m_callback; // edi

  p_m_callback = &this->m_callback;
  if ( boost::function0<void>::operator void (__thiscall boost::function0<void>::dummy::*)(void)((boost::function0<void> *)&this->m_callback) )
    boost::function1<void,bool>::operator()(p_m_callback, this->m_result);
}
