void __thiscall survarium::lobby_client::on_disconnected(survarium::lobby_client *this)
{
  boost::function<void __cdecl(void)> *p_m_on_disconnected; // esi

  p_m_on_disconnected = &this->m_on_disconnected;
  this->m_net_client_connected = 0;
  if ( boost::function0<void>::operator void (__thiscall boost::function0<void>::dummy::*)(void)(&this->m_on_disconnected) )
    boost::function0<void>::operator()(p_m_on_disconnected);
}
