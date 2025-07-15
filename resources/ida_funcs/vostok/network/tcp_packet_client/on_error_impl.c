void __thiscall vostok::network::tcp_packet_client::on_error_impl(
        vostok::network::tcp_packet_client *this,
        const char *client_error_code,
        const boost::system::error_code error_code)
{
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_error)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::operator()(
      (boost::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum> *)&this->m_on_error,
      client_error_code,
      (survarium::hit_affects_type_enum)error_code.m_val,
      (survarium::affect_event_type_enum)error_code.m_cat);
}
