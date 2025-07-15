void __thiscall vostok::network::match_client::on_packet_received_impl(
        vostok::network::match_client *this,
        unsigned __int8 message_type,
        boost::function4<void,unsigned int,float,float,char const *> *reader)
{
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_packet_received)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function2<void,unsigned char,vostok::network_core::packet_reader &>::operator()(
      &this->m_on_packet_received,
      message_type,
      reader);
}
