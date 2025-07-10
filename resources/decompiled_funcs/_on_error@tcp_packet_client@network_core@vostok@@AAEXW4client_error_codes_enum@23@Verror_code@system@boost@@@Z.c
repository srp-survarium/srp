void __thiscall vostok::network_core::tcp_packet_client::on_error(
        vostok::network_core::tcp_packet_client *this,
        const char *client_error_code,
        boost::system::error_code error_code)
{
  vostok::network_core::async_connector::reset(&this->m_async_connector);
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_error)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::operator()(
      (boost::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum> *)&this->m_on_error,
      client_error_code,
      (survarium::hit_affects_type_enum)error_code.m_val,
      (survarium::affect_event_type_enum)error_code.m_cat);
}
