void __thiscall vostok::vfs::unmounter::recursive_unmount_node<vostok::vfs::is_exact_node const>(
        vostok::vfs::unmounter *this,
        vostok::fs_new::virtual_path_string *path,
        unsigned int hash,
        vostok::vfs::is_exact_node *predicate,
        vostok::vfs::base_node<1> **node_to_unmount,
        vostok::vfs::base_node<1> **overlap_of_node_to_unmount)
{
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  vostok::vfs::transfer_children v9; // [esp+20Ch] [ebp-150h] BYREF
  vostok::vfs::base_node<1> *after_last; // [esp+34Ch] [ebp-10h]
  vostok::vfs::base_node<1> *first_to_unmount; // [esp+350h] [ebp-Ch] BYREF
  vostok::vfs::base_node<1> *next_to_last; // [esp+354h] [ebp-8h] BYREF
  vostok::vfs::base_node<1> *last_to_unmount; // [esp+358h] [ebp-4h] BYREF

  *node_to_unmount = 0;
  first_to_unmount = 0;
  last_to_unmount = 0;
  next_to_last = 0;
  vostok::vfs::unmounter::find_range_to_unmount<vostok::vfs::is_exact_node>(
    this,
    path,
    hash,
    predicate,
    &first_to_unmount,
    &last_to_unmount,
    &next_to_last);
  if ( last_to_unmount )
  {
    if ( (last_to_unmount->m_flags & 1) == 1 )
    {
      vostok::vfs::unmounter::recursive_unmount_folder_range<vostok::vfs::is_exact_node const>(
        this,
        path,
        hash,
        predicate,
        first_to_unmount,
        last_to_unmount);
    }
    else
    {
      after_last = last_to_unmount->m_next_overlapped.pointer;
      if ( next_to_last && (next_to_last->m_flags & 1) == 1 && after_last && (after_last->m_flags & 1) == 1 )
      {
        vostok::vfs::transfer_children::transfer_children(
          &v9,
          this->m_hashset,
          path,
          hash,
          first_to_unmount,
          after_last);
        survarium::weapon_user_dead_state::finalize(v6);
        survarium::weapon_user_dead_state::finalize(v7);
      }
    }
    *overlap_of_node_to_unmount = next_to_last;
    *node_to_unmount = last_to_unmount;
  }
}
