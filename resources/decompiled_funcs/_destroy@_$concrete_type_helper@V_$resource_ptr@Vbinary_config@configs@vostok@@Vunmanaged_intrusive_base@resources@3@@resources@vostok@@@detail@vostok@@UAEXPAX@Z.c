void __thiscall vostok::detail::concrete_type_helper<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::destroy(
        vostok::detail::concrete_type_helper<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > *this,
        vostok::resources::unmanaged_resource **buffer)
{
  if ( *buffer )
  {
    if ( !_InterlockedExchangeAdd(&(*buffer)->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &(*buffer)->vostok::resources::unmanaged_intrusive_base,
        *buffer);
  }
}
