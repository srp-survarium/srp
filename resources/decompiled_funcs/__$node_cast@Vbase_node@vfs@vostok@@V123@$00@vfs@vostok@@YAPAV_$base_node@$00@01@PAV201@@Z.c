vostok::sound::sound_world *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)node);
  else
    return 0;
}
