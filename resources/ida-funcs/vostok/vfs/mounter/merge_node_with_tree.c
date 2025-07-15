void __thiscall vostok::vfs::mounter::merge_node_with_tree(
        vostok::vfs::mounter *this,
        vostok::vfs::base_node<1> **path,
        vostok::fs_new::virtual_path_string *hash,
        unsigned __int64 node,
        vostok::vfs::base_node<1> *source_folder)
{
  int v5; // ebx
  vostok::vfs::mounter *v6; // esi
  vostok::vfs::base_folder_node<1> *v7; // ecx
  vostok::vfs::base_node<1> *v8; // eax
  vostok::vfs::base_node<1> *v9; // edi
  vostok::vfs::base_folder_node<1> *pointer; // eax
  vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *p_m_hashset_next; // eax
  vostok::vfs::base_folder_node<1> *v12; // eax
  vostok::vfs::base_folder_node<1> *v13; // eax
  vostok::vfs::base_folder_node<1> *v14; // eax
  vostok::vfs::virtual_file_system *m_file_system; // eax
  const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v16; // eax
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v17; // ecx
  bool v18; // zf
  vostok::vfs::base_folder_node<1> *v19; // eax
  vostok::vfs::vfs_reader_writer_lock *v20; // ecx
  vostok::vfs::base_node<1> *v21; // eax
  vostok::vfs::vfs_hashset *v22; // ecx
  vostok::vfs::base_node<1> *topmost_overlapper; // eax
  vostok::vfs::should_overlap_predicate v24; // eax
  vostok::vfs::vfs_hashset *v25; // ecx
  vostok::vfs::base_node<1> v26; // [esp-Ch] [ebp-180h] BYREF
  _DWORD v27[4]; // [esp+150h] [ebp-24h] BYREF
  unsigned int v28; // [esp+160h] [ebp-14h]
  vostok::vfs::base_folder_node<1> *v29; // [esp+164h] [ebp-10h] BYREF
  vostok::vfs::base_node<1> *v30; // [esp+168h] [ebp-Ch] BYREF
  vostok::vfs::base_node<1> *v31; // [esp+16Ch] [ebp-8h] BYREF
  char hash_7; // [esp+18Bh] [ebp+17h]
  vostok::vfs::base_folder_node<1> *source_folderc; // [esp+18Ch] [ebp+18h]
  vostok::vfs::base_node<1> *source_foldera; // [esp+18Ch] [ebp+18h]
  vostok::vfs::base_node<1> *source_folderb; // [esp+18Ch] [ebp+18h]

  v5 = HIDWORD(node);
  v26.m_next_overlapped.pointer = source_folder;
  v6 = (vostok::vfs::mounter *)path;
  v28 = vostok::vfs::mount_id_of_node<1>((vostok::vfs::base_node<1> *)HIDWORD(node));
  v26.m_mount_root.max_storage = node;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  vostok::vfs::mounter::find_overlapped_and_parent_to_link(
    hash,
    path,
    &v29,
    (vostok::vfs::mount_root_node_base<1> **)&v31,
    &v30,
    v26);
  hash_7 = 0;
  if ( (*(_BYTE *)(v5 + 48) & 8) != 0 )
  {
    v8 = vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>((vostok::vfs::base_node<1> *)v5);
    if ( !v8 || (hash_7 = 1, !*(_DWORD *)&v8->m_name[877]) )
      hash_7 = 0;
  }
  v9 = v30;
  if ( v30 )
  {
    pointer = v30->m_parent.pointer;
    if ( pointer != (vostok::vfs::base_folder_node<1> *)source_folder || hash_7 )
    {
      vostok::vfs::base_folder_node<1>::unlink_child(
        v7,
        &pointer->m_first_child.pointer,
        v30,
        SBYTE4(v26.m_next_overlapped.max_storage));
      if ( !hash_7 )
      {
        p_m_hashset_next = (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)source_folder;
        if ( source_folder )
          p_m_hashset_next = &source_folder->m_hashset_next;
        v12 = (vostok::vfs::base_folder_node<1> *)p_m_hashset_next[1].pointer;
        if ( v12 )
          v12 = vostok::vfs::cast_folder<1>((vostok::vfs::base_node<1> *)v12);
        v9->m_parent.pointer = v12;
        v9->m_next.pointer = v12->m_first_child.pointer;
        HIDWORD(v9->m_next.max_storage) = HIDWORD(v12->m_first_child.max_storage);
        v12->m_first_child.pointer = v9;
      }
      v6 = (vostok::vfs::mounter *)path;
    }
    else
    {
      _InterlockedOr((volatile signed __int32 *)&v30->m_flags, 0x4000u);
    }
  }
  v13 = v29;
  *(_DWORD *)(v5 + 32) = v29;
  *(_DWORD *)(v5 + 24) = v13->m_first_child.pointer;
  *(_DWORD *)(v5 + 28) = HIDWORD(v13->m_first_child.max_storage);
  v13->m_first_child.pointer = (vostok::vfs::base_node<1> *)v5;
  if ( v31 )
  {
    if ( (v31->m_flags & 1) != 0 && (*(_BYTE *)(v5 + 48) & 1) == 0 && v9 && (v9->m_flags & 1) != 0 )
      vostok::vfs::separate_folders_by_file_node(hash->m_string.m_begin, node, v31, v28);
    v31->m_next_overlapped.pointer = (vostok::vfs::base_node<1> *)v5;
  }
  if ( v9 && (v9->m_flags & 1) != 0 && (*(_BYTE *)(v5 + 48) & 1) != 0 )
  {
    source_folderc = vostok::vfs::cast_folder<1>(v9);
    v14 = vostok::vfs::cast_folder<1>((vostok::vfs::base_node<1> *)v5);
    vostok::vfs::transfer_children_to_empty_folder(v14, source_folderc);
  }
  m_file_system = v6->m_file_system;
  source_foldera = (vostok::vfs::base_node<1> *)&m_file_system->on_node_hides;
  if ( (m_file_system->on_node_hides.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0
    && v9 )
  {
    v27[2] = 0;
    v27[0] = &m_file_system->hashset;
    v27[1] = v9;
    v27[3] = 2;
    vostok::vfs::vfs_iterator::vfs_iterator((vostok::vfs::vfs_iterator *)v9, (int)v27);
    boost::function1<void,vostok::collision::object const &>::operator()(v17, source_foldera, v16);
  }
  if ( hash_7 )
  {
    v18 = v31 == 0;
    source_folderb = v9->m_next_overlapped.pointer;
    *(_DWORD *)(v5 + 8) = source_folderb;
    if ( v18 && v6->m_args.root_write_lock == v9 )
    {
      v19 = vostok::vfs::cast_folder<1>((vostok::vfs::base_node<1> *)v5);
      vostok::vfs::vfs_reader_writer_lock::lock(
        v20,
        &v19->m_readers_writers_counters.m_counters,
        lock_type_write,
        lock_operation_lock);
      v9 = v30;
    }
    v21 = (vostok::vfs::base_node<1> *)vostok::vfs::mount_id_of_node<1>((vostok::vfs::base_node<1> *)v5);
    vostok::vfs::vfs_hashset::replace(
      v22,
      (vostok::hash_multiset<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,16,vostok::detail::fixed_size_policy<32768>,vostok::detail::null_hash<vostok::vfs::base_node<1> >,vostok::detail::null_equal<vostok::vfs::base_node<1> >,vostok::threading::single_threading_policy> *)&v6->m_file_system->hashset,
      node,
      (vostok::vfs::base_node<1> *)v5,
      v9,
      v21);
    topmost_overlapper = vostok::vfs::mounter::find_topmost_overlapper(hash, v6, node, (vostok::vfs::base_node<1> *)v5);
    if ( source_folderb && (source_folderb->m_flags & 1) != 0 )
    {
      if ( topmost_overlapper )
        vostok::vfs::transfer_children::transfer_children(
          (vostok::vfs::transfer_children *)((char *)&v26.m_next.max_storage + 4),
          &v6->m_file_system->hashset,
          hash,
          node,
          topmost_overlapper,
          source_folderb);
    }
  }
  else
  {
    *(_DWORD *)(v5 + 8) = v9;
    v24.mount_id = vostok::vfs::mount_id_of_node<1>((vostok::vfs::base_node<1> *)v5);
    vostok::vfs::vfs_hashset::insert(v25, (int)&v6->m_file_system->hashset, node, (vostok::vfs::base_node<1> *)v5, v24);
  }
}
