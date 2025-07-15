void __cdecl vostok::vfs::relink_children_of_folder(
        vostok::vfs::base_node<1> *overlapper,
        unsigned int separator_mount_id)
{
  vostok::vfs::base_node<1> *pointer; // esi
  vostok::vfs::base_folder_node<1> *v3; // ebx
  vostok::vfs::mount_root_node_base<1> *v4; // esi
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v5; // ecx
  bool *v6; // [esp+0h] [ebp-30h]
  vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper v7; // [esp+10h] [ebp-20h] BYREF
  vostok::vfs::mount_root_node_base<1> *v8; // [esp+18h] [ebp-18h]
  int v9; // [esp+1Ch] [ebp-14h]
  int v10; // [esp+20h] [ebp-10h]
  int v11; // [esp+24h] [ebp-Ch]
  vostok::vfs::mount_root_node_base<1> *v12; // [esp+2Ch] [ebp-4h]
  vostok::vfs::base_node<1> *node; // [esp+38h] [ebp+8h]

  pointer = overlapper;
  if ( overlapper )
    node = (vostok::vfs::base_node<1> *)vostok::vfs::cast_folder<1>(overlapper);
  else
    node = 0;
  v3 = 0;
  while ( pointer )
  {
    if ( vostok::vfs::mount_id_of_node<1>(pointer) < separator_mount_id )
    {
      v3 = vostok::vfs::cast_folder<1>(pointer);
      break;
    }
    pointer = pointer->m_next_overlapped.pointer;
  }
  v4 = node->m_mount_root.pointer;
  v7.pointer = 0;
  v9 = 0;
  v8 = 0;
  v11 = 0;
  v10 = 0;
  while ( v4 )
  {
    v12 = (vostok::vfs::mount_root_node_base<1> *)v4->async_device.pointer;
    if ( vostok::vfs::mount_id_of_node<1>((vostok::vfs::base_node<1> *)v4) >= separator_mount_id )
    {
      vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        v5,
        &v7,
        (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper)(unsigned int)v4,
        v6);
      if ( ((int)v4->descriptor.pointer & 1) != 0 )
        vostok::vfs::relink_children_of_folder((vostok::vfs::base_node<1> *)v4, separator_mount_id);
    }
    else
    {
      v4->virtual_path.pointer = (const char *)v3;
      v4->async_device.pointer = (vostok::fs_new::asynchronous_device_interface *)v3->m_first_child.pointer;
      HIDWORD(v4->async_device.max_storage) = HIDWORD(v3->m_first_child.max_storage);
      v3->m_first_child.pointer = (vostok::vfs::base_node<1> *)v4;
    }
    v4 = v12;
  }
  node->m_mount_root.pointer = v8;
  HIDWORD(node->m_mount_helper_parent.max_storage) = v9;
}
