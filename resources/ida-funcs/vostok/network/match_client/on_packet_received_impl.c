void __thiscall vostok::network::match_client::on_packet_received_impl(
        vostok::network::match_client *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *message_type,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *reader)
{
  int v3; // ecx
  _DWORD *v4; // eax
  int v5; // ecx

  if ( vostok::network::match_client::is_connected(this) )
  {
    v4 = (_DWORD *)(v3 + 168);
    v5 = -(*(_DWORD *)(v3 + 168) != 0);
    if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v5) != 0 )
      boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
        (boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *)v5,
        v4,
        message_type,
        reader);
  }
}
