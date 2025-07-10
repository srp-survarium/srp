void __thiscall survarium::game::on_application_deactivate(survarium::game *this)
{
  if ( this->m_input_world )
  {
    vostok::threading::mutex::lock(&this->m_application_activation);
    this->m_input_world->on_deactivate(this->m_input_world);
    this->m_is_active = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->m_application_activation);
  }
}
