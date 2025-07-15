void __usercall vostok::vfs::async_callbacks_data::finish_with_out_of_memory(
        vostok::vfs::async_callbacks_data *this@<ecx>,
        int a2@<eax>)
{
  vostok::vfs::vfs_locked_iterator *v3; // ecx
  vostok::vfs::async_callbacks_data *v4; // ecx
  boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *v5; // [esp-4h] [ebp-24h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> a0; // [esp+Ch] [ebp-14h] BYREF
  int v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+14h] [ebp-Ch]
  int v9; // [esp+18h] [ebp-8h]
  int v10; // [esp+1Ch] [ebp-4h]

  vostok::vfs::unlock_and_decref_branch(*(vostok::vfs::base_node<1> **)(a2 + 72), lock_type_read, *(_DWORD *)(a2 + 92));
  a0.m_object = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
    v5,
    (_DWORD *)(a2 + 40),
    &a0,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)3);
  vostok::vfs::vfs_locked_iterator::clear(v3, (int)&a0);
  vostok::vfs::async_callbacks_data::delete_this(v4, a2);
}
