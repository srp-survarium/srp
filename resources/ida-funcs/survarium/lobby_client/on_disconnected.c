void __thiscall survarium::lobby_client::on_disconnected(survarium::lobby_client *this)
{
  int v1; // ecx

  this->m_net_client_connected = 0;
  v1 = -(this->m_on_disconnected.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v1) != 0 )
    boost::function0<void>::operator()((boost::function0<bool> *)v1);
}
