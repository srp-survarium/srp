void __thiscall vostok::network::http_client::on_error_impl(
        vostok::network::http_client *this,
        boost::system::error_code error_code)
{
  this->m_busy = 0;
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_error)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
      (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&this->m_on_error,
      (const char *)error_code.m_val,
      (const vostok::network_core::udp_match_packet *)error_code.m_cat);
}
