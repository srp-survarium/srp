void __usercall vostok::vfs::async_callbacks_data::finish_tree_may_destroy_this(
        vostok::vfs::async_callbacks_data *this@<ecx>,
        int a2@<eax>)
{
  vostok::vfs::async_callbacks_data *v3; // ecx
  vostok::vfs::vfs_locked_iterator *v4; // ecx
  boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *v5; // ecx
  vostok::vfs::async_callbacks_data *v6; // ecx
  boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *v7; // [esp-4h] [ebp-24h]
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v8; // [esp-4h] [ebp-24h]
  vostok::vfs::vfs_locked_iterator out_iterator; // [esp+Ch] [ebp-14h] BYREF

  if ( *(_DWORD *)(a2 + 96) == 1 )
  {
    if ( *(_DWORD *)(a2 + 108) )
    {
      vostok::vfs::upgrade_branch(*(vostok::vfs::base_node<1> **)(a2 + 72), lock_type_write, lock_operation_try_lock);
      vostok::vfs::async_callbacks_data::continue_find_tree(v3, (vostok::vfs::async_callbacks_data *)a2);
      return;
    }
    memset(&out_iterator, 0, sizeof(out_iterator));
    vostok::vfs::make_iterator((vostok::vfs::find_environment *)(a2 + 16), &out_iterator);
    boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
      v7,
      (_DWORD *)(a2 + 40),
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&out_iterator,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)1);
  }
  else
  {
    vostok::vfs::free_nodes_to_expand(
      (vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)(a2 + 100),
      *(vostok::memory::base_allocator **)(a2 + 88));
    vostok::vfs::unlock_and_decref_recursively(
      *(vostok::vfs::base_node<1> **)(a2 + 72),
      lock_type_write,
      *(vostok::vfs::find_enum *)(a2 + 80),
      (vostok::vfs::vfs_hashset *)(*(_DWORD *)(a2 + 84) + 24),
      *(_DWORD *)(a2 + 92));
    v8 = *(const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> **)(a2 + 96);
    memset(&out_iterator, 0, sizeof(out_iterator));
    boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
      v5,
      (_DWORD *)(a2 + 40),
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&out_iterator,
      v8);
  }
  vostok::vfs::vfs_locked_iterator::clear(v4, (int)&out_iterator);
  vostok::vfs::async_callbacks_data::delete_this(v6, a2);
}
