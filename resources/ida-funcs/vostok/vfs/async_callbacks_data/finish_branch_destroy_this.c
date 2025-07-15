void __usercall vostok::vfs::async_callbacks_data::finish_branch_destroy_this(
        vostok::vfs::async_callbacks_data *this@<ecx>,
        int a2@<eax>)
{
  unsigned int v3; // eax
  vostok::vfs::async_callbacks_data *v4; // ecx
  boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *v5; // ecx
  vostok::vfs::vfs_locked_iterator *v6; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v7; // [esp-34h] [ebp-54h] BYREF
  unsigned int v8; // [esp-14h] [ebp-34h]
  vostok::vfs::virtual_file_system *v9; // [esp-10h] [ebp-30h]
  vostok::memory::base_allocator *v10; // [esp-Ch] [ebp-2Ch]
  unsigned int v11; // [esp-8h] [ebp-28h]
  boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *v12; // [esp-4h] [ebp-24h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> a0; // [esp+Ch] [ebp-14h] BYREF
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  int v16; // [esp+18h] [ebp-8h]
  int v17; // [esp+1Ch] [ebp-4h]

  if ( *(_DWORD *)(a2 + 96) == 1 )
  {
    vostok::vfs::upgrade_branch(*(vostok::vfs::base_node<1> **)(a2 + 72), lock_type_write, lock_operation_try_lock);
    v3 = *(_DWORD *)(a2 + 80);
    v12 = *(boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> **)(a2 + 28);
    v11 = *(_DWORD *)(a2 + 92);
    v10 = *(vostok::memory::base_allocator **)(a2 + 88);
    v9 = *(vostok::vfs::virtual_file_system **)(a2 + 84);
    v8 = v3;
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(a2 + 40),
      &v7);
    vostok::vfs::try_find_async(*(char **)(a2 + 20), v7, v8, v9, v10, v11, (unsigned int)v12);
  }
  else
  {
    vostok::vfs::unlock_and_decref_branch(
      *(vostok::vfs::base_node<1> **)(a2 + 72),
      lock_type_write,
      *(_DWORD *)(a2 + 92));
    v5 = v12;
    v12 = *(boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> **)(a2 + 96);
    a0.m_object = 0;
    v14 = 0;
    v15 = 0;
    v16 = 0;
    v17 = 0;
    boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
      v5,
      (_DWORD *)(a2 + 40),
      &a0,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v12);
    vostok::vfs::vfs_locked_iterator::clear(v6, (int)&a0);
  }
  vostok::vfs::async_callbacks_data::delete_this(v4, a2);
}
