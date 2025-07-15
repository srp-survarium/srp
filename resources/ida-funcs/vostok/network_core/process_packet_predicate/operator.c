void __userpurge vostok::network_core::process_packet_predicate::operator()(
        vostok::network_core::process_packet_predicate *this@<ecx>,
        _DWORD *a2@<eax>,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *message_type,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *reader)
{
  _DWORD *v4; // eax
  int v5; // ecx

  v4 = (_DWORD *)(*a2 + 2856);
  v5 = -(*v4 != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v5) != 0 )
    boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
      (boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *)v5,
      v4,
      message_type,
      reader);
}
