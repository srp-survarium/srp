void __thiscall survarium::game::on_application_activate(survarium::game *this)
{
  HWND v2; // eax
  vostok::input::world *m_input_world; // ecx

  v2 = this->m_engine->get_main_window_handle(this->m_engine);
  SetWindowTextA(v2, String);
  vostok::threading::mutex::lock(&this->m_application_activation);
  m_input_world = this->m_input_world;
  if ( m_input_world )
    m_input_world->on_activate(m_input_world);
  this->m_is_active = 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&this->m_application_activation);
}
