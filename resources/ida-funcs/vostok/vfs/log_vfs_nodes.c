void __cdecl vostok::vfs::log_vfs_nodes(vostok::vfs::base_node<1> *node, unsigned int level, const char *original_name)
{
  vostok::fixed_string<512> *v3; // ecx
  const char *v4; // eax
  vostok::fixed_string<512> *v5; // ecx
  vostok::vfs::archive_folder_mount_root_node<1> *pointer; // [esp+8h] [ebp-8E8h]
  unsigned int i; // [esp+68h] [ebp-888h]
  unsigned int v8; // [esp+6Ch] [ebp-884h]
  vostok::fs_new::path_string_impl v9; // [esp+78h] [ebp-878h] BYREF
  vostok::vfs::base_node<1> *child; // [esp+18Ch] [ebp-764h]
  vostok::fs_new::virtual_path_string path; // [esp+190h] [ebp-760h] BYREF
  const char *file_name; // [esp+2ACh] [ebp-644h]
  vostok::vfs::mount_root_node_base<1> *mount_root; // [esp+2B0h] [ebp-640h]
  vostok::vfs::base_node<1> *referenced_node; // [esp+2B4h] [ebp-63Ch]
  vostok::fixed_string<512> string; // [esp+2B8h] [ebp-638h] BYREF
  vostok::fixed_string<512> type; // [esp+4C8h] [ebp-428h] BYREF
  vostok::vfs::base_folder_node<1> *folder; // [esp+6DCh] [ebp-214h]
  vostok::fixed_string<512> folder_addr; // [esp+6E0h] [ebp-210h] BYREF

  if ( node )
  {
    if ( (node->m_flags & 0x300) != 0 )
    {
      referenced_node = vostok::vfs::find_referenced_link_node(node);
      vostok::vfs::log_vfs_nodes(referenced_node, level, node->m_name);
    }
    else
    {
      vostok::fixed_string<512>::fixed_string<512>(
        (vostok::fixed_string<512> *)((node->m_flags & 0x300) != 0),
        (int)&string);
      v8 = vostok::strings::length("  ");
      for ( i = 0; i < level; ++i )
        vostok::buffer_string::append(&string, "  ", &begin_src[v8]);
      if ( original_name )
        vostok::buffer_string::operator+=(&string, original_name);
      else
        vostok::buffer_string::operator+=(&string, node->m_name);
      vostok::fixed_string<512>::fixed_string<512>(v3, (int)&type);
      if ( (node->m_flags & 0x400) == 0x400 )
      {
        vostok::fixed_string<16>::operator=(&stru_956E4C, &type);
      }
      else
      {
        if ( (node->m_flags & 8) == 8 )
          pointer = vostok::vfs::cast_mount_root_node_base<1>(node);
        else
          pointer = (vostok::vfs::archive_folder_mount_root_node<1> *)node->m_mount_root.pointer;
        mount_root = pointer;
        vostok::fs_new::path_string_impl::path_string_impl(
          &v9,
          92,
          (const vostok::platform_pointer_selector<char,1>::helper *)&pointer->physical_path);
        file_name = (const char *)vostok::fs_new::file_name_from_path<vostok::fs_new::native_path_string>((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v9);
        vostok::fixed_string<16>::operator=((vostok::fixed_string<16> *)file_name, &type);
        if ( (node->m_flags & 8) == 8 )
          vostok::buffer_string::operator+=(&type, stru_956E4C.m_buffer);
      }
      if ( (node->m_flags & 0x80) == 0x80 )
        vostok::fixed_string<16>::operator=(&stru_956E68, &type);
      if ( (node->m_flags & 0x800) == 0x800 )
        vostok::buffer_string::operator+=(&type, stru_956E68.m_buffer);
      if ( original_name )
      {
        vostok::fs_new::virtual_path_string::virtual_path_string(&path);
        vostok::vfs::base_node<1>::get_full_path(node, (vostok::fs_new::native_path_string *)&path);
        v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&path);
        vostok::buffer_string::appendf(&type, (vostok::buffer_string *)&stru_956E68.m_buffer[12], v4);
      }
      folder = vostok::vfs::cast_folder<1>(node);
      vostok::fixed_string<512>::fixed_string<512>(v5, (int)&folder_addr);
      if ( folder )
        vostok::buffer_string::assignf(&folder_addr, (const char *)&stru_956624, folder);
      if ( folder )
      {
        for ( child = folder->m_first_child.pointer; child; child = child->m_next.pointer )
          vostok::vfs::log_vfs_nodes(child, level + 1, 0);
      }
    }
  }
}
