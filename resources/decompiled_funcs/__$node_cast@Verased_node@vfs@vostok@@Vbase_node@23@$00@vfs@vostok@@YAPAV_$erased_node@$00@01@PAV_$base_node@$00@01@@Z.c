vostok::vfs::erased_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::erased_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx

  if ( !node )
    return 0;
  survarium::weapon_user_dead_state::finalize(v1);
  return (vostok::vfs::erased_node<1> *)node;
}
