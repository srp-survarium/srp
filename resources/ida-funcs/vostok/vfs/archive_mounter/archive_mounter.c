void __thiscall vostok::vfs::archive_mounter::archive_mounter(
        vostok::vfs::archive_mounter *this,
        vostok::vfs::query_mount_arguments *args,
        vostok::vfs::virtual_file_system *vfs_data)
{
  vostok::memory::base_allocator *v3; // eax
  vostok::vfs::vfs_mount *v4; // eax
  vostok::vfs::vfs_mount *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  vostok::vfs::vfs_mount *v7; // [esp+4h] [ebp-34h]
  vostok::vfs::vfs_mount *v8; // [esp+8h] [ebp-30h]
  vostok::vfs::vfs_mount *v10; // [esp+2Ch] [ebp-Ch]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> parent_mount; // [esp+30h] [ebp-8h] BYREF
  vostok::vfs::vfs_mount *mount_ptr_raw; // [esp+34h] [ebp-4h]

  vostok::vfs::mounter::mounter(this, args, vfs_data);
  this->__vftable = (vostok::vfs::archive_mounter_vtbl *)&vostok::vfs::archive_mounter::`vftable';
  this->m_mount_root_base = 0;
  this->m_nodes_buffer = 0;
  this->m_reverse_byte_order = 0;
  this->m_branch_lock = 0;
  vostok::vfs::query_mount_arguments::convert_pathes_to_absolute(&this->m_args);
  if ( !vostok::vfs::mounter::try_mount_from_history(this) )
  {
    survarium::weapon_user_dead_state::finalize(0);
    mount_ptr_raw = (vostok::vfs::vfs_mount *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(v3, 0x40u);
    if ( mount_ptr_raw )
    {
      v10 = (vostok::vfs::vfs_mount *)operator new(0x40u, mount_ptr_raw);
      if ( v10 )
      {
        vostok::vfs::vfs_mount::vfs_mount(v10, 0, this->m_args.allocator);
        v7 = v4;
      }
      else
      {
        v7 = 0;
      }
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    mount_ptr_raw = v8;
    if ( v8 )
    {
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
        &this->m_mount_ptr,
        mount_ptr_raw,
        v8);
      if ( this->m_args.submount_node )
      {
        v5 = vostok::vfs::mount_of_node<1>(this->m_args.submount_node);
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          &parent_mount,
          v5);
        this->m_mount_id = *(_DWORD *)&stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                         v6,
                                         (int)&parent_mount)[13][1].m_storage[24];
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&parent_mount);
      }
      if ( this->m_args.submount_type == submount_type_subfat )
      {
        vostok::vfs::archive_mounter::mount_sub_fat(this);
      }
      else
      {
        if ( this->m_args.mount_id )
          this->m_mount_id = this->m_args.mount_id;
        if ( !this->m_mount_id )
          this->m_mount_id = vostok::vfs::next_mount_id();
        vostok::vfs::archive_mounter::mount_archive(this);
      }
    }
    else
    {
      vostok::vfs::mounter::finish_with_out_of_memory(this);
    }
  }
}
