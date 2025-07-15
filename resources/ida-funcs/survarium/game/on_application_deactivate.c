void __thiscall survarium::game::on_application_deactivate(survarium::game *this)
{
  vostok::input::world **p_m_input_world; // edi

  p_m_input_world = &this->m_input_world;
  if ( this->m_input_world )
  {
    vostok::threading::mutex::lock(
      (vostok::threading::mutex *)this,
      (_RTL_CRITICAL_SECTION *)&this->m_application_activation);
    (*p_m_input_world)->on_deactivate(*p_m_input_world);
    this->m_is_active = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->m_application_activation);
  }
}
