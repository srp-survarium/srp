// local variable allocation has failed, the output may be wrong!
void __thiscall vostok::resources::fs_task_mount::execute_may_destroy_this(vostok::resources::fs_task_mount *this)
{
  vostok::vfs::virtual_file_system *v2; // ebp
  char *m_begin; // ebx
  vostok::resources::recursive_bool m_recursive; // ecx
  vostok::fs_new::asynchronous_device_interface *v5; // esi
  vostok::vfs::query_mount_arguments *v6; // eax
  vostok::fs_new::asynchronous_device_interface *v7; // esi
  vostok::resources::fs_task_unmount *v8; // ecx
  int v9; // eax
  vostok::vfs::vfs_intrusive_mount_base *v10; // ecx
  vostok::resources::unmanaged_resource *v11; // eax
  vostok::resources::unmanaged_resource *v12; // ebx
  void *v13; // eax
  vostok::resources::fs_task_unmount *v14; // eax
  vostok::resources::fs_task_unmount *m_object; // eax
  _BYTE v16[124]; // [esp-2Ch] [ebp-A0Ch] OVERLAPPED BYREF
  vostok::vfs::query_mount_arguments result; // [esp+508h] [ebp-4D8h] BYREF

  v2 = (vostok::vfs::virtual_file_system *)((char *)&loc_20600
                                          + (unsigned int)vostok::resources::g_resources_manager.m_variable);
  vostok::vfs::query_mount_arguments::query_mount_arguments((vostok::vfs::query_mount_arguments *)&v16[92]);
  m_begin = this->m_descriptor.m_begin;
  if ( this->m_type == type_mount_physical )
  {
    m_recursive = this->m_recursive;
    v5 = *(vostok::fs_new::asynchronous_device_interface **)((char *)&loc_205F8
                                                           + (unsigned int)vostok::resources::g_resources_manager.m_variable);
    *(_DWORD *)&v16[40] = this->m_watcher_enabled;
    *(_DWORD *)&v16[36] = 1;
    *(_DWORD *)&v16[32] = m_recursive;
    boost::function<void __cdecl (vostok::vfs::mount_result)>::function<void __cdecl (vostok::vfs::mount_result)>(
      (boost::function<void __cdecl(vostok::vfs::mount_result)> *)v16,
      0);
    v6 = vostok::vfs::query_mount_arguments::mount_physical_path(
           &result,
           &vostok::memory::g_resources_unmanaged_allocator,
           (vostok::vfs::query_mount_arguments *)&this->m_virtual_path,
           &this->m_physical_path,
           (vostok::fixed_string<16> *)m_begin,
           v5,
           0,
           *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)v16,
           *(survarium::game_camera **)&v16[32],
           *(vostok::vfs::lock_operation_enum *)&v16[36],
           *(vostok::fs_new::watcher_enabled_bool *)&v16[40]);
  }
  else
  {
    v7 = *(vostok::fs_new::asynchronous_device_interface **)((char *)&loc_205F8
                                                           + (unsigned int)vostok::resources::g_resources_manager.m_variable);
    *(_DWORD *)&v16[40] = 1;
    boost::function<void __cdecl (vostok::vfs::mount_result)>::function<void __cdecl (vostok::vfs::mount_result)>(
      (boost::function<void __cdecl(vostok::vfs::mount_result)> *)&v16[8],
      0);
    v6 = vostok::vfs::query_mount_arguments::mount_archive(
           &result,
           &vostok::memory::g_resources_unmanaged_allocator,
           (vostok::vfs::query_mount_arguments *)&this->m_virtual_path,
           &this->m_archive_physical_path,
           this->m_fat_physical_path,
           (vostok::fixed_string<16> *)m_begin,
           v7,
           0,
           *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)&v16[8],
           *(vostok::vfs::lock_operation_enum *)&v16[40]);
  }
  vostok::vfs::query_mount_arguments::operator=((vostok::vfs::query_mount_arguments *)&v16[92], v6);
  vostok::vfs::query_mount_arguments::~query_mount_arguments(&result);
  *(_DWORD *)&v16[84] = vostok::resources::g_resources_manager.m_variable;
  v16[68] = 0;
  *(_DWORD *)&v16[80] = vostok::resources::resources_manager::dispatch_callbacks;
  *(_DWORD *)&v16[4] = vostok::resources::g_resources_manager.m_variable;
  *(_DWORD *)&v16[12] = 0;
  *(_DWORD *)&v16[8] = *(_DWORD *)&v16[68];
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         (boost::detail::function::function_buffer *)&v16[20],
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::resources::resources_manager::dispatch_callbacks,
         *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > *)&v16[4]) )
  {
    *(_DWORD *)&v16[12] = &stru_95BE78.m_string.m_buffer[13];
  }
  else
  {
    *(_DWORD *)&v16[12] = 0;
  }
  vostok::vfs::query_mount_and_wait(
    (vostok::vfs::mount_result *)&v16[72],
    v2,
    (vostok::vfs::query_mount_arguments *)&v16[92],
    *(boost::function<void __cdecl(void)> *)&v16[12]);
  v9 = *(_DWORD *)&v16[72];
  if ( *(_DWORD *)&v16[72]
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v10 = *(vostok::vfs::vfs_intrusive_mount_base **)&v16[72];
    _InterlockedExchangeAdd(*(volatile signed __int32 **)&v16[72], 1u);
    v11 = *(vostok::resources::unmanaged_resource **)(v9 + 24);
    v12 = 0;
    *(_DWORD *)&v16[64] = 0;
    if ( v11 )
    {
      v12 = v11;
      *(_DWORD *)&v16[64] = v11;
      _InterlockedExchangeAdd(&v11->m_reference_count, 1u);
    }
    if ( !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
    {
      *(_DWORD *)&v16[40] = v10;
      vostok::vfs::vfs_intrusive_mount_base::destroy(v10, *(survarium::game_camera *)&v16[40]);
    }
    v13 = vostok::memory::g_resources_helper_allocator.call_malloc(&vostok::memory::g_resources_helper_allocator, 40);
    if ( v13 )
      vostok::resources::fs_task_unmount::fs_task_unmount(
        (vostok::resources::fs_task_unmount *)&v16[64],
        (int)v13,
        (const vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)&v16[64]);
    else
      v14 = 0;
    v8 = 0;
    if ( v14 )
    {
      v8 = v14;
      _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
    }
    m_object = this->m_mount_ptr.m_object;
    this->m_mount_ptr.m_object = v8;
    if ( m_object )
    {
      v8 = (vostok::resources::fs_task_unmount *)&m_object->vostok::resources::intrusive_fs_task_unmount_base;
      if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::intrusive_fs_task_unmount_base::destroy(
          m_object,
          *(vostok::resources::intrusive_fs_task_unmount_base **)&v16[44]);
    }
    if ( v12 )
    {
      v8 = (vostok::resources::fs_task_unmount *)&v12->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)v8, v12);
    }
  }
  vostok::resources::fs_task::on_task_ready_may_destroy_this(v8, this);
  vostok::vfs::mount_result::~mount_result((vostok::vfs::mount_result *)&v16[72]);
  vostok::vfs::query_mount_arguments::~query_mount_arguments((vostok::vfs::query_mount_arguments *)&v16[92]);
}
