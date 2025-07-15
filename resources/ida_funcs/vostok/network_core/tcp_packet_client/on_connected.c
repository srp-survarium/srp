void __thiscall vostok::network_core::tcp_packet_client::on_connected(vostok::network_core::tcp_packet_client *this)
{
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_connected)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function0<void>::operator()(&this->m_on_connected);
  vostok::network_core::tcp_packet_client::start_reading(this);
}
