void __thiscall vostok::network::tcp_packet_client::on_packet_received_impl(
        vostok::network::tcp_packet_client *this,
        boost::function4<void,unsigned int,float,float,char const *> *reader)
{
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::operator()(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
      reader);
}
