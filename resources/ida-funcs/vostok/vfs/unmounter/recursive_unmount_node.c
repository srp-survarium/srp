void __thiscall vostok::vfs::unmounter::recursive_unmount_node<vostok::vfs::is_exact_node const>(
        vostok::vfs::unmounter *this,
        vostok::fs_new::virtual_path_string *path,
        vostok::vfs::is_exact_node *hash,
        vostok::vfs::is_exact_node *predicate,
        vostok::vfs::base_node<1> **node_to_unmount,
        vostok::vfs::base_node<1> **overlap_of_node_to_unmount)
{
  vostok::vfs::unmounter *v6; // ecx
  vostok::vfs::base_node<1> *v7; // esi
  vostok::vfs::base_node<1> *v8; // edi
  vostok::vfs::base_node<1> *pointer; // eax
  vostok::vfs::base_node<1> *first_to_unmount; // [esp+8h] [ebp-150h] BYREF
  vostok::vfs::base_node<1> *next_to_last; // [esp+Ch] [ebp-14Ch] BYREF
  vostok::fs_new::virtual_path_string *v12; // [esp+10h] [ebp-148h]
  vostok::vfs::base_node<1> *last_to_unmount; // [esp+14h] [ebp-144h] BYREF
  vostok::vfs::transfer_children v14; // [esp+18h] [ebp-140h] BYREF

  *node_to_unmount = 0;
  first_to_unmount = 0;
  last_to_unmount = 0;
  next_to_last = 0;
  v12 = (vostok::fs_new::virtual_path_string *)this;
  vostok::vfs::unmounter::find_range_to_unmount<vostok::vfs::is_exact_node>(
    this,
    path,
    &first_to_unmount,
    (__int16)hash,
    predicate,
    &last_to_unmount,
    &next_to_last);
  v7 = last_to_unmount;
  if ( last_to_unmount )
  {
    v8 = next_to_last;
    if ( (last_to_unmount->m_flags & 1) != 0 )
    {
      vostok::vfs::unmounter::recursive_unmount_folder_range<vostok::vfs::is_exact_node const>(
        v6,
        (vostok::vfs::unmounter *)v12,
        path,
        hash,
        predicate,
        first_to_unmount,
        last_to_unmount);
    }
    else
    {
      pointer = last_to_unmount->m_next_overlapped.pointer;
      if ( next_to_last && (next_to_last->m_flags & 1) != 0 && pointer && (pointer->m_flags & 1) != 0 )
        vostok::vfs::transfer_children::transfer_children(
          &v14,
          (vostok::vfs::vfs_hashset *)v12->m_string.m_end,
          path,
          (unsigned int)hash,
          first_to_unmount,
          last_to_unmount->m_next_overlapped.pointer);
    }
    *overlap_of_node_to_unmount = v8;
    *node_to_unmount = v7;
  }
}
