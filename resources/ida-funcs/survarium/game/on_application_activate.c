void __thiscall survarium::game::on_application_activate(survarium::game *this)
{
  vostok::threading::mutex *p_m_application_activation; // edi
  vostok::input::world *m_input_world; // ecx

  p_m_application_activation = &this->m_application_activation;
  vostok::threading::mutex::lock(
    (vostok::threading::mutex *)this,
    (_RTL_CRITICAL_SECTION *)&this->m_application_activation);
  m_input_world = this->m_input_world;
  if ( m_input_world )
    m_input_world->on_activate(m_input_world);
  this->m_is_active = 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)p_m_application_activation);
}
