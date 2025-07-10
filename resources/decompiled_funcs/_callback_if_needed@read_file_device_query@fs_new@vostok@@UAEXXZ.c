void __thiscall vostok::fs_new::read_file_device_query::callback_if_needed(
        vostok::fs_new::read_file_device_query *this)
{
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_args.callback)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function1<void,bool>::operator()(&this->m_args.callback, this->m_result);
}
