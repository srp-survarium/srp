void __thiscall vostok::network_core::async_connector::async_connector(vostok::network_core::async_connector *this)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx

  this->m_host.values_.px = 0;
  this->m_host.values_.pn.pi_ = 0;
  this->m_host.index_ = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_host.values_.pn,
    &this->m_on_connected.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v1, &this->m_on_error.vtable);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_allocator);
  this->m_allocator.in_use_ = 0;
  this->m_socket = 0;
  this->m_connection_state = host_name_is_unresolved;
}
