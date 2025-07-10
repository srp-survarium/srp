void __thiscall vostok::fs_new::query_physical_path_device_query::callback_if_needed(
        vostok::fs_new::query_physical_path_device_query *this)
{
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_callback)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
      (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)&this->m_callback,
      (const vostok::ai::sensors::sensed_object *)&this->m_result);
}
