void __cdecl vostok::vfs::free_node_impl(
        vostok::vfs::virtual_file_system *file_system,
        vostok::vfs::base_node<1> *node,
        vostok::vfs::base_node<1> **root_write_lock,
        __int16 hash,
        vostok::memory::base_allocator *allocator,
        vostok::vfs::erase_from_hashset_enum erase_from_hashset)
{
  int v6; // ecx
  vostok::vfs::base_node<1> *v7; // edi
  vostok::buffer_string *v8; // ecx
  const char *v9; // eax
  vostok::buffer_string *v10; // ecx
  unsigned __int16 m_flags; // ax
  int v12; // ecx
  vostok::vfs::physical_folder_mount_root_node<1> *v14; // eax
  vostok::vfs::base_node<1> *pointer; // eax
  vostok::vfs::base_node<1> *v16; // esi
  vostok::vfs::base_node<1> *v17; // esi
  bool v18; // al
  unsigned __int16 v19; // ax
  vostok::vfs::base_folder_node<1> *v20; // eax
  vostok::vfs::physical_folder_node<1> *v21; // esi
  vostok::vfs::base_folder_node<1> *p_folder; // eax
  vostok::vfs::physical_folder_mount_root_node<1> *v23; // eax
  int v24; // [esp-4h] [ebp-23Ch]
  char *v25; // [esp-4h] [ebp-23Ch]
  int v26; // [esp-4h] [ebp-23Ch]
  unsigned int v27; // [esp-4h] [ebp-23Ch]
  unsigned int v28; // [esp-4h] [ebp-23Ch]
  const char *v29; // [esp+0h] [ebp-238h]
  _DWORD v30[3]; // [esp+10h] [ebp-228h] BYREF
  _BYTE v31[512]; // [esp+1Ch] [ebp-21Ch] BYREF
  char v32; // [esp+21Ch] [ebp-1Ch] BYREF
  int v33; // [esp+220h] [ebp-18h]
  _DWORD v34[4]; // [esp+228h] [ebp-10h] BYREF
  bool v35; // [esp+247h] [ebp+Fh]
  vostok::vfs::base_node<1> **root_write_locka; // [esp+248h] [ebp+10h]

  v6 = -(*(_DWORD *)(&file_system->mount_history.gap0 + (_DWORD)&loc_20165 + 3) != 0);
  v7 = node;
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v6) != 0 )
  {
    v34[2] = 0;
    v34[0] = &file_system->hashset;
    v34[1] = node;
    v34[3] = 2;
    if ( node )
      vostok::vfs::vfs_iterator::vfs_iterator((vostok::vfs::vfs_iterator *)node, (int)v34);
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)v6,
      &file_system->mount_history.gap0 + (_DWORD)&loc_20165 + 3,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v34);
  }
  v30[0] = v31;
  v30[1] = v31;
  v30[2] = &v32;
  v31[0] = 0;
  vostok::fs_new::path_string_impl::assignf(
    (int)v30,
    (vostok::buffer_string *)v6,
    (vostok::buffer_string *)&stru_7FCCD0.m_max_end,
    node->m_name,
    node);
  if ( (node->m_flags & 1) != 0 )
  {
    v9 = (const char *)vostok::vfs::cast_folder<1>(node);
    vostok::buffer_string::appendf(v30, v10, (vostok::buffer_string *)" folder[0x%08x]", v9);
  }
  else
  {
    vostok::buffer_string::appendf(v30, v8, (vostok::buffer_string *)" file", v29);
  }
  m_flags = node->m_flags;
  v12 = v24;
  if ( (m_flags & 8) != 0 )
  {
    v25 = " mount-root";
  }
  else
  {
    v12 = 1024;
    if ( (m_flags & 0x400) != 0x400 )
      goto LABEL_13;
    v25 = " mount-helper";
  }
  vostok::buffer_string::append((vostok::buffer_string *)v12, (int)v30, v25);
LABEL_13:
  if ( (node->m_flags & 0x300) != 0 )
  {
    root_write_locka = 0;
  }
  else
  {
    v14 = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(node);
    root_write_locka = (vostok::vfs::base_node<1> **)v14;
    if ( v14 )
    {
      pointer = v14->first_erased.pointer;
      if ( pointer )
      {
        do
        {
          v16 = pointer->m_next.pointer;
          vostok::vfs::free_node_impl(file_system, pointer, root_write_lock, 0, allocator, erase_from_hashset_false);
          pointer = v16;
        }
        while ( v16 );
      }
    }
  }
  v35 = node == *root_write_lock;
  if ( v7 == *root_write_lock )
  {
    v17 = v7->m_next_overlapped.pointer;
    if ( v17 )
    {
      vostok::vfs::lock_node(v17, lock_type_write, lock_operation_lock);
      v12 = v26;
      *root_write_lock = v17;
    }
    else
    {
      *root_write_lock = 0;
    }
  }
  v18 = root_write_locka && *((_BYTE *)root_write_locka + 100);
  if ( erase_from_hashset == erase_from_hashset_true && !v18 )
    vostok::vfs::vfs_hashset::erase((vostok::vfs::vfs_hashset *)v12, (int)&file_system->hashset, hash, v7);
  if ( v35 )
    vostok::vfs::unlock_node(v7, lock_type_write);
  v19 = v7->m_flags;
  if ( (v19 & 0x2000) == 0x2000 )
  {
    v20 = (vostok::vfs::base_folder_node<1> *)vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(v7);
    if ( !v20 )
      return;
    v27 = 81;
    goto LABEL_67;
  }
  if ( (v19 & 2) != 0 )
  {
    if ( (v19 & 0x800) == 0x800 )
    {
      v28 = 89;
      goto LABEL_37;
    }
    if ( (v19 & 1) != 0 )
    {
      v21 = vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(v7);
      p_folder = 0;
      v33 = 0;
      if ( v21 )
        p_folder = &v21->folder;
      p_folder->m_first_child.pointer = 0;
      HIDWORD(p_folder->m_first_child.max_storage) = 0;
      if ( v21->children_arena.m_data )
        allocator->call_free(
          allocator,
          (void *)v21->children_arena.m_data,
          "vostok::vfs::free_node_impl",
          ".\\free_node.cpp",
          115u);
      v21->children_arena.m_data = 0;
      v21->children_arena.m_size = 0;
      if ( (v7->m_flags & 8) != 0 )
      {
        v23 = vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(v7);
        if ( v23 )
          allocator->call_free(allocator, v23, "vostok::vfs::free_node_impl", ".\\free_node.cpp", 122u);
      }
      else if ( (v21->m_folder_flags.m_flags & 4) == 0 )
      {
        allocator->call_free(allocator, v21, "vostok::vfs::free_node_impl", ".\\free_node.cpp", 127u);
      }
    }
    else
    {
      if ( (v19 & 8) != 0 )
      {
        v7 -= 2;
        if ( !v7 )
          return;
        v28 = 97;
LABEL_37:
        allocator->call_free(allocator, v7, "vostok::vfs::free_node_impl", ".\\free_node.cpp", v28);
        return;
      }
      v20 = (vostok::vfs::base_folder_node<1> *)vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(v7);
      if ( (v20->m_first_child.max_storage & 0x800000000LL) == 0 && v20 )
      {
        v27 = 105;
LABEL_67:
        allocator->call_free(allocator, v20, "vostok::vfs::free_node_impl", ".\\free_node.cpp", v27);
      }
    }
  }
  else
  {
    if ( (v19 & 4) == 0 )
    {
      if ( (v19 & 0x400) == 0x400 )
      {
        v20 = (vostok::vfs::base_folder_node<1> *)vostok::vfs::node_cast<vostok::vfs::mount_helper_node,vostok::vfs::base_node,1>(v7);
        if ( !v20 )
          return;
        v27 = 163;
      }
      else
      {
        v20 = vostok::vfs::cast_folder<1>(v7);
        if ( !v20 )
          return;
        v27 = 170;
      }
      goto LABEL_67;
    }
    if ( (v19 & 0x200) != 0x200 && (v19 & 0x100) != 0x100 && (v19 & 0x800) != 0x800 && (v19 & 8) != 0 )
    {
      v20 = *(vostok::vfs::base_folder_node<1> **)&vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(v7)->m_name[869];
      if ( v20 )
      {
        v27 = 156;
        goto LABEL_67;
      }
    }
  }
}
