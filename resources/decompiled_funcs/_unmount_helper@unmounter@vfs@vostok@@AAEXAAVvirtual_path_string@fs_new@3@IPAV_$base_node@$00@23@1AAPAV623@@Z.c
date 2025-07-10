void __thiscall vostok::vfs::unmounter::unmount_helper(
        vostok::vfs::unmounter *this,
        vostok::fs_new::virtual_path_string *path,
        unsigned int hash,
        vostok::vfs::base_node<1> *parent_to_unmount,
        vostok::vfs::base_node<1> *node_to_unmount,
        vostok::vfs::base_node<1> **out_overlap_of_node_to_unmount)
{
  survarium::game_camera *v6; // ecx
  vostok::vfs::is_exact_node v8; // [esp+20Ch] [ebp-14h] BYREF
  vostok::vfs::base_node<1> *first_to_unmount; // [esp+210h] [ebp-10h] BYREF
  vostok::vfs::base_node<1> *next_to_last; // [esp+214h] [ebp-Ch] BYREF
  vostok::vfs::is_exact_node predicate; // [esp+218h] [ebp-8h] BYREF
  vostok::vfs::base_node<1> *last_to_unmount; // [esp+21Ch] [ebp-4h] BYREF

  first_to_unmount = 0;
  last_to_unmount = 0;
  next_to_last = 0;
  v8.helper_node = parent_to_unmount;
  vostok::vfs::unmounter::find_range_to_unmount<vostok::vfs::is_exact_node>(
    this,
    path,
    hash,
    &v8,
    &first_to_unmount,
    &last_to_unmount,
    &next_to_last);
  *out_overlap_of_node_to_unmount = next_to_last;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)out_overlap_of_node_to_unmount);
  survarium::weapon_user_dead_state::finalize(v6);
  predicate.helper_node = node_to_unmount;
  vostok::vfs::unmounter::recursive_unmount_folder_range<vostok::vfs::is_exact_node const>(
    this,
    path,
    hash,
    &predicate,
    first_to_unmount,
    last_to_unmount);
}
