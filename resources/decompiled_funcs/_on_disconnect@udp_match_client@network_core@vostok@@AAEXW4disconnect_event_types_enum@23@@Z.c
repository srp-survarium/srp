void __thiscall vostok::network_core::udp_match_client::on_disconnect(
        vostok::network_core::udp_match_client *this,
        boost::function4<void,unsigned int,float,float,char const *> *disconnect_type)
{
  if ( this->m_is_receiving )
    boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::cancel(&this->m_socket);
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_disconnect)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::operator()(
      &this->m_on_disconnect,
      disconnect_type);
}
