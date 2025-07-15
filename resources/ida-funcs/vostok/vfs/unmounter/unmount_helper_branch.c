void __thiscall vostok::vfs::unmounter::unmount_helper_branch(
        vostok::vfs::unmounter *this,
        vostok::vfs::virtual_file_system **parent_to_unmount_helper,
        vostok::vfs::base_node<1> *child_to_unmount,
        vostok::vfs::base_node<1> *overlap_of_unmount,
        vostok::vfs::base_node<1> *child_to_unmount_hash,
        vostok::vfs::is_exact_node *predicate)
{
  vostok::vfs::virtual_file_system **v7; // edi
  char *v8; // eax
  vostok::vfs::base_node<1> *p_m_next; // ebx
  vostok::vfs::is_exact_node *v10; // eax
  vostok::vfs::base_node<1> *v11; // esi
  vostok::vfs::unmounter *v12; // ecx
  char *v13; // eax
  int v14; // eax
  vostok::vfs::base_node<1> *v15; // ecx
  vostok::fs_new::virtual_path_string hash; // [esp+Ch] [ebp-128h] BYREF
  vostok::vfs::base_node<1> *pointer; // [esp+124h] [ebp-10h]
  vostok::vfs::is_exact_node v18; // [esp+128h] [ebp-Ch] BYREF
  vostok::vfs::base_node<1> *last_to_unmount; // [esp+12Ch] [ebp-8h] BYREF
  vostok::vfs::base_node<1> *v20; // [esp+130h] [ebp-4h] BYREF
  char v21; // [esp+143h] [ebp+Fh]

  hash.m_string.m_begin = hash.m_string.m_buffer;
  hash.m_string.m_end = hash.m_string.m_buffer;
  v7 = parent_to_unmount_helper;
  hash.m_string.m_max_end = &hash.m_separator;
  v8 = (char *)*parent_to_unmount_helper;
  hash.m_string.m_buffer[0] = 0;
  hash.m_separator = 47;
  vostok::fs_new::get_path_without_last_item<vostok::fs_new::virtual_path_string>(&hash, *(char **)v8);
  v21 = 0;
  while ( (hash.m_string.m_end != hash.m_string.m_begin
        || v21 == LOBYTE(hash.m_string.m_end) - LOBYTE(hash.m_string.m_begin))
       && child_to_unmount )
  {
    p_m_next = (vostok::vfs::base_node<1> *)&child_to_unmount->m_next;
    pointer = (vostok::vfs::base_node<1> *)p_m_next->m_mount_root.pointer;
    v10 = (vostok::vfs::is_exact_node *)vostok::fs_new::path_crc32(
                                          hash.m_string.m_begin,
                                          hash.m_string.m_end - hash.m_string.m_begin,
                                          0);
    v11 = overlap_of_unmount;
    predicate = v10;
    if ( overlap_of_unmount )
    {
      last_to_unmount = 0;
      v20 = 0;
      overlap_of_unmount = 0;
      child_to_unmount_hash = p_m_next;
      vostok::vfs::unmounter::find_range_to_unmount<vostok::vfs::is_exact_node>(
        (vostok::vfs::unmounter *)parent_to_unmount_helper,
        &hash,
        &last_to_unmount,
        (__int16)v10,
        (const vostok::vfs::is_exact_node *)&child_to_unmount_hash,
        &v20,
        &overlap_of_unmount);
      child_to_unmount_hash = overlap_of_unmount;
      v18.helper_node = v11;
      vostok::vfs::unmounter::recursive_unmount_folder_range<vostok::vfs::is_exact_node const>(
        v12,
        (vostok::vfs::unmounter *)parent_to_unmount_helper,
        &hash,
        predicate,
        &v18,
        last_to_unmount,
        v20);
      v7 = parent_to_unmount_helper;
    }
    overlap_of_unmount = p_m_next;
    if ( hash.m_string.m_end == hash.m_string.m_begin
      && v21 == LOBYTE(hash.m_string.m_end) - LOBYTE(hash.m_string.m_begin) )
    {
      v21 = 1;
    }
    child_to_unmount = pointer;
    v13 = hash.m_string.m_end - 1;
    if ( hash.m_string.m_end - 1 < hash.m_string.m_begin )
      goto LABEL_18;
    while ( 1 )
    {
      if ( *v13 == 47 )
      {
        v14 = v13 - hash.m_string.m_begin;
        goto LABEL_17;
      }
      if ( v13 == hash.m_string.m_begin )
        break;
      --v13;
    }
    v14 = -1;
LABEL_17:
    if ( v14 == -1 )
    {
LABEL_18:
      hash.m_string.m_end = hash.m_string.m_begin;
      *hash.m_string.m_begin = 0;
    }
    else
    {
      hash.m_string.m_end = &hash.m_string.m_begin[v14];
      hash.m_string.m_begin[v14] = 0;
    }
  }
  v15 = overlap_of_unmount;
  if ( overlap_of_unmount )
  {
    if ( child_to_unmount_hash )
      child_to_unmount_hash->m_next_overlapped.pointer = overlap_of_unmount->m_next_overlapped.pointer;
    vostok::vfs::free_node(
      v7[2],
      v15,
      &(*v7)->hashset.m_hashset.m_buffer[232],
      (unsigned int)predicate,
      (vostok::memory::base_allocator *)(*v7)->hashset.m_hashset.m_buffer[215]);
  }
}
