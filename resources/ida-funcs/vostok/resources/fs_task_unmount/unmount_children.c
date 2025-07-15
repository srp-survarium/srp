void __thiscall vostok::resources::fs_task_unmount::unmount_children(
        vostok::resources::fs_task_unmount *this,
        vostok::vfs::vfs_mount *sub_fat)
{
  vostok::vfs::vfs_mount *v2; // ebx
  unsigned int m_size; // eax
  void *v4; // esp
  vostok::vfs::vfs_mount *v5; // ecx
  vostok::vfs::vfs_mount *m_object; // edi
  unsigned int v7; // esi
  vostok::vfs::vfs_mount **v8; // esi
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *next_of_object; // eax
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v10[2]; // [esp-8h] [ebp-3Ch] BYREF
  _DWORD v11[4]; // [esp+0h] [ebp-34h] BYREF
  vostok::vfs::vfs_mount **v12; // [esp+10h] [ebp-24h]
  vostok::vfs::vfs_mount **v13; // [esp+14h] [ebp-20h]
  vostok::threading::simple_lock::mutex_raii v14; // [esp+18h] [ebp-1Ch] BYREF
  _DWORD *v15; // [esp+20h] [ebp-14h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v16; // [esp+24h] [ebp-10h] BYREF
  vostok::resources::fs_task_unmount *v17; // [esp+28h] [ebp-Ch]
  unsigned int v18; // [esp+2Ch] [ebp-8h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v19; // [esp+30h] [ebp-4h] BYREF

  v2 = sub_fat;
  m_size = sub_fat->children.m_size;
  v17 = this;
  v18 = m_size;
  if ( m_size )
  {
    v4 = alloca(4 * m_size);
    v15 = v11;
    v12 = (vostok::vfs::vfs_mount **)v11;
    v13 = (vostok::vfs::vfs_mount **)&v11[m_size];
    v14.lock = &sub_fat->children.m_policy;
    vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, (int)&sub_fat->children.m_policy);
    v14.locked = 1;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v19,
      &v2->children.m_first);
    while ( 1 )
    {
      m_object = v19.m_object;
      v7 = 0;
      if ( !v19.m_object
        || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        break;
      }
      v8 = v12;
      if ( v12 >= v13
        && !`vostok::buffer_vector<vostok::vfs::vfs_mount *>::push_back'::`11'::debug_macro_helper_ignore_always )
      {
        HIBYTE(sub_fat) = 0;
        vostok::debug::on_error(
          (bool *)&sub_fat + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::vfs::vfs_mount *>::push_back",
          (const char *)0x12E,
          "buffer overflow",
          (const char *)v10[1].m_object);
        if ( vostok::debug::is_debugger_present() || HIBYTE(sub_fat) )
          __debugbreak();
      }
      if ( v8 )
        *v8 = m_object;
      v10[0].m_object = v5;
      v12 = v8 + 1;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        v10,
        &v19);
      next_of_object = vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy>::get_next_of_object(
                         &v16,
                         (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v10[0].m_object);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
        next_of_object,
        &v19);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v16);
    }
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v19);
    if ( v18 )
    {
      do
        vostok::resources::fs_task_unmount::unmount_children(v17, (vostok::vfs::vfs_mount *)v15[v7++]);
      while ( v7 < v18 );
    }
    vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v14);
  }
  if ( v17->m_sub_fat_ptr.m_object->mount_ptr.m_object != v2 )
    vostok::resources::game_resources_manager::release_sub_fat(
      vostok::resources::g_game_resources_manager.m_variable,
      (vostok::resources::vfs_sub_fat_resource *)v2->user_data,
      (vostok::resources::game_resources_manager *)this);
}
