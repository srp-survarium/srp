void __cdecl vostok::vfs::log_vfs_root(vostok::vfs::virtual_file_system *vfs, bool assert_empty)
{
  survarium::game_camera *v2; // ecx
  vostok::vfs::base_node<1> *node; // [esp+4h] [ebp-4h]

  node = vostok::vfs::vfs_hashset::find_no_lock(&vfs->hashset, (const char *)&buf, check_locks_false);
  if ( assert_empty )
    survarium::weapon_user_dead_state::finalize(v2);
  if ( node )
    vostok::vfs::log_vfs_nodes(node, 0, 0);
}
