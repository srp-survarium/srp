void __thiscall vostok::network_core::async_connector::reset(vostok::network_core::async_connector *this)
{
  this->m_connection_state = host_name_is_unresolved;
}
