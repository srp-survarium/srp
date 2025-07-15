void __thiscall vostok::vfs::async_link_helper::on_link_received(
        vostok::vfs::async_link_helper *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *iterator,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *result)
{
  boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
    (boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *)this,
    this,
    iterator,
    result);
  vostok::vfs::unlock_and_decref_branch(this->original_node, lock_type_read, this->original_mount_operation_id);
  this->allocator->call_free(
    this->allocator,
    this,
    "vostok::vfs::async_link_helper::delete_this",
    ".\\find_async_link.cpp",
    56u);
}
