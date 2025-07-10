void __cdecl vostok::vfs::destroy_temp_physical_node(vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  vostok::memory::base_allocator *v3; // eax
  vostok::vfs::physical_file_mount_root_node<1> *mount_root; // [esp+Ch] [ebp-8h]

  mount_root = vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>(node);
  survarium::weapon_user_dead_state::finalize(v1);
  survarium::weapon_user_dead_state::finalize(v2);
  if ( mount_root )
    vostok::memory::base_allocator::free_impl(v3, mount_root);
}
