void __thiscall vostok::network::match_client::on_disconnect_impl(
        vostok::network::match_client *this,
        boost::function4<void,unsigned int,float,float,char const *> *type)
{
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_disconnected)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function1<void,enum vostok::network_core::disconnect_event_types_enum>::operator()(
      &this->m_on_disconnected,
      type);
}
