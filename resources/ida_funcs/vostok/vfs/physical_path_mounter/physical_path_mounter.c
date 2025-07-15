void __userpurge vostok::vfs::physical_path_mounter::physical_path_mounter(
        vostok::vfs::physical_path_mounter *this@<ecx>,
        unsigned int a2@<ebx>,
        vostok::vfs::query_mount_arguments *args,
        vostok::vfs::virtual_file_system *vfs_data)
{
  bool v4; // al
  vostok::memory::base_allocator *v5; // eax
  vostok::vfs::vfs_mount *v6; // ecx
  vostok::vfs::vfs_mount *v7; // eax
  vostok::vfs::vfs_mount *v8; // [esp+Ch] [ebp-48h]
  vostok::vfs::vfs_mount *v9; // [esp+10h] [ebp-44h]
  vostok::vfs::result_enum m_result; // [esp+1Ch] [ebp-38h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> other; // [esp+20h] [ebp-34h] BYREF
  bool m_out_of_memory; // [esp+26h] [ebp-2Eh]
  vostok::vfs::mount_result v14; // [esp+38h] [ebp-1Ch] BYREF
  vostok::vfs::vfs_mount *v15; // [esp+40h] [ebp-14h]
  vostok::fs_new::synchronous_device_interface device; // [esp+44h] [ebp-10h] BYREF
  vostok::vfs::vfs_mount *mount_ptr_raw; // [esp+50h] [ebp-4h]

  vostok::vfs::mounter::mounter(this, args, vfs_data);
  this->__vftable = (vostok::vfs::physical_path_mounter_vtbl *)&vostok::vfs::physical_path_mounter::`vftable';
  this->m_device = 0;
  vostok::vfs::query_mount_arguments::convert_pathes_to_absolute(&this->m_args);
  v4 = vostok::vfs::mounter::try_mount_from_history(this);
  if ( !v4 )
  {
    if ( !args->submount_node )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v4);
      mount_ptr_raw = (vostok::vfs::vfs_mount *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(v5, 0x40u);
      if ( mount_ptr_raw )
      {
        v15 = (vostok::vfs::vfs_mount *)operator new(0x40u, mount_ptr_raw);
        if ( v15 )
        {
          vostok::vfs::vfs_mount::vfs_mount(v15, 0, this->m_args.allocator);
          v8 = v7;
        }
        else
        {
          v8 = 0;
        }
        v6 = v8;
        v9 = v8;
      }
      else
      {
        v9 = 0;
      }
      mount_ptr_raw = v9;
      if ( !v9 )
      {
        vostok::vfs::mounter::finish_with_out_of_memory(this);
        return;
      }
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
        &this->m_mount_ptr,
        mount_ptr_raw,
        v6);
    }
    if ( this->m_args.asynchronous_device )
    {
      vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
        &device,
        this->m_args.asynchronous_device,
        this->m_args.allocator);
      m_out_of_memory = device.m_out_of_memory;
      if ( device.m_out_of_memory )
      {
        vostok::vfs::mounter::finish_with_out_of_memory(this);
        vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&device);
        return;
      }
      this->m_device = &device;
      vostok::vfs::physical_path_mounter::mount_impl(this, a2);
      vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&device);
    }
    else
    {
      this->m_device = this->m_args.synchronous_device;
      vostok::vfs::physical_path_mounter::mount_impl(this, a2);
    }
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &other,
      &this->m_mount_ptr);
    m_result = this->m_result;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v14.mount,
      &other);
    v14.result = m_result;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&other);
    vostok::vfs::mounter::finish(this, &v14, 0);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v14.mount);
  }
}
