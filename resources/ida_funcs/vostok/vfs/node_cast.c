vostok::vfs::archive_compressed_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_compressed_file<1>(node);
  else
    return 0;
}


const vostok::vfs::archive_compressed_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>(
        const vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_compressed_file<1>(node);
  else
    return 0;
}


vostok::vfs::archive_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_file<1>(node);
  else
    return 0;
}


const vostok::vfs::archive_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>(
        const vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_file<1>(node);
  else
    return 0;
}


vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_folder_mount_root<1>(node);
  else
    return 0;
}


vostok::vfs::archive_folder_mount_root_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::mount_root_node_base,1>(
        vostok::vfs::mount_root_node_base<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_folder_mount_root<1>(node->node.pointer);
  else
    return 0;
}


vostok::vfs::archive_inline_compressed_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_inline_compressed_file<1>(node);
  else
    return 0;
}


const vostok::vfs::archive_inline_compressed_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>(
        const vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_inline_compressed_file<1>(node);
  else
    return 0;
}


vostok::vfs::archive_inline_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_inline_file<1>(node);
  else
    return 0;
}


const vostok::vfs::archive_inline_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>(
        const vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_archive_inline_file<1>(node);
  else
    return 0;
}


vostok::vfs::base_folder_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::archive_folder_mount_root_node,1>(
        vostok::vfs::archive_folder_mount_root_node<1> *node)
{
  if ( node )
    return &node->folder;
  else
    return 0;
}


vostok::vfs::base_folder_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_folder<1>(node);
  else
    return 0;
}


const vostok::vfs::base_folder_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(
        const vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_folder<1>(node);
  else
    return 0;
}


vostok::vfs::base_folder_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::mount_helper_node,1>(
        vostok::vfs::mount_helper_node<1> *node)
{
  if ( node )
    return &node->folder;
  else
    return 0;
}


vostok::vfs::base_folder_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_mount_root_node,1>(
        vostok::vfs::physical_folder_mount_root_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_folder<1>(node);
  else
    return 0;
}


vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(
        vostok::vfs::base_folder_node<1> *node)
{
  if ( node )
    return &node->base;
  else
    return 0;
}


vostok::sound::sound_world *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)node);
  else
    return 0;
}


vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::archive_folder_mount_root_node,1>(
        vostok::vfs::archive_folder_mount_root_node<1> *node)
{
  if ( node )
    return &node->folder.base;
  else
    return 0;
}


vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::hard_link_node,1>(
        vostok::vfs::hard_link_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_node<1>(node);
  else
    return 0;
}


vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_helper_node,1>(
        vostok::vfs::mount_helper_node<1> *node)
{
  if ( node )
    return &node->folder.base;
  else
    return 0;
}


vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>(
        vostok::vfs::mount_root_node_base<1> *node)
{
  if ( node )
    return node->node.pointer;
  else
    return 0;
}


vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::physical_file_mount_root_node,1>(
        vostok::vfs::physical_file_mount_root_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_node<1>(node);
  else
    return 0;
}


vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::physical_folder_mount_root_node,1>(
        vostok::vfs::physical_folder_mount_root_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_node<1>(node);
  else
    return 0;
}


vostok::vfs::base_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::physical_folder_node,1>(
        vostok::vfs::physical_folder_node<1> *node)
{
  if ( node )
    return &node->folder.base;
  else
    return 0;
}


vostok::vfs::erased_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::erased_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  survarium::game_camera *v1; // ecx

  if ( !node )
    return 0;
  survarium::weapon_user_dead_state::finalize(v1);
  return (vostok::vfs::erased_node<1> *)node;
}


vostok::vfs::external_subfat_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::external_subfat_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_external_node<1>(node);
  else
    return 0;
}


const vostok::vfs::external_subfat_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::external_subfat_node,vostok::vfs::base_node,1>(
        const vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_external_node<1>(node);
  else
    return 0;
}


vostok::vfs::mount_helper_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::mount_helper_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_mount_helper_node<1>(node);
  else
    return 0;
}


vostok::vfs::mount_root_node_base<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_mount_root_node_base<1>(node);
  else
    return 0;
}


vostok::vfs::physical_file_mount_root_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_physical_file_mount_root<1>(node);
  else
    return 0;
}


vostok::vfs::physical_file_mount_root_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::mount_root_node_base,1>(
        vostok::vfs::mount_root_node_base<1> *node)
{
  if ( node )
    return vostok::vfs::node_cast<vostok::vfs::physical_file_mount_root_node,vostok::vfs::base_node,1>(node->node.pointer);
  else
    return 0;
}


vostok::vfs::physical_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_physical_file<1>(node);
  else
    return 0;
}


const vostok::vfs::physical_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::physical_file_node,vostok::vfs::base_node,1>(
        const vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_physical_file<1>(node);
  else
    return 0;
}


vostok::vfs::physical_folder_mount_root_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_physical_folder_mount_root<1>(node);
  else
    return 0;
}


vostok::vfs::physical_folder_mount_root_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::mount_root_node_base,1>(
        vostok::vfs::mount_root_node_base<1> *node)
{
  if ( node )
    return vostok::vfs::node_cast<vostok::vfs::physical_folder_mount_root_node,vostok::vfs::base_node,1>(node->node.pointer);
  else
    return 0;
}


vostok::vfs::physical_folder_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_physical_folder<1>(node);
  else
    return 0;
}


vostok::vfs::physical_folder_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::physical_folder_node,vostok::vfs::physical_folder_mount_root_node,1>(
        vostok::vfs::physical_folder_mount_root_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_physical_folder<1>(node);
  else
    return 0;
}


vostok::vfs::hard_link_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_soft_link<1>(node);
  else
    return 0;
}


const vostok::vfs::hard_link_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(
        const vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_hard_link<1>(node);
  else
    return 0;
}


vostok::vfs::universal_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(
        vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_universal_file_node<1>(node);
  else
    return 0;
}


const vostok::vfs::universal_file_node<1> *__cdecl vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(
        const vostok::vfs::base_node<1> *node)
{
  if ( node )
    return vostok::vfs::cast_universal_file_node<1>(node);
  else
    return 0;
}
