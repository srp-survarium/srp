void __thiscall vostok::vfs::archive_mounter::recursive_merge(
        vostok::vfs::archive_mounter *this,
        vostok::fs_new::virtual_path_string *path,
        unsigned int hash,
        vostok::vfs::base_node<1> *node,
        vostok::vfs::base_folder_node<1> *parent)
{
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  unsigned int v7; // eax
  vostok::vfs::base_folder_node<1> *v8; // [esp+0h] [ebp-48h]
  vostok::vfs::base_node<1> *v10; // [esp+14h] [ebp-34h] BYREF
  float v11; // [esp+18h] [ebp-30h]
  vostok::vfs::base_node<1> **v12; // [esp+1Ch] [ebp-2Ch]
  char *s; // [esp+20h] [ebp-28h] BYREF
  char v14; // [esp+26h] [ebp-22h]
  char v15; // [esp+27h] [ebp-21h]
  vostok::vfs::base_node<1> *next_child; // [esp+2Ch] [ebp-1Ch]
  unsigned int child_hash; // [esp+30h] [ebp-18h]
  vostok::fs_new::virtual_path_string *child_path; // [esp+34h] [ebp-14h]
  vostok::vfs::base_node<1> *child; // [esp+38h] [ebp-10h]
  vostok::vfs::base_folder_node<1> *node_folder; // [esp+3Ch] [ebp-Ch]
  vostok::vfs::base_node<1> *node_children; // [esp+40h] [ebp-8h]
  unsigned int saved_path_length; // [esp+44h] [ebp-4h]

  node_children = vostok::vfs::base_node<1>::get_first_child(node);
  v5 = (survarium::game_camera *)((node->m_flags & 1) == 1);
  if ( (node->m_flags & 1) == 1 )
  {
    v12 = &v10;
    v11 = 0.0;
    v10 = 0;
    v5 = (survarium::game_camera *)vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
    v5->__vftable = (survarium::game_camera_vtbl *)v10;
    v5->m_inverted_view_matrix.i.x = v11;
  }
  if ( parent )
  {
    vostok::vfs::mounter::merge_node_with_tree(
      this,
      (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)path,
      hash,
      node,
      parent);
  }
  else
  {
    v15 = 0;
    survarium::weapon_user_dead_state::finalize(v5);
    v14 = 0;
    survarium::weapon_user_dead_state::finalize(v6);
    vostok::vfs::mounter::merge_root_node(this, hash, node, &this->m_args.root_write_lock);
  }
  saved_path_length = vostok::fs_new::path_string_impl::length(path);
  if ( (node->m_flags & 0x300) != 0 )
    v8 = 0;
  else
    v8 = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(node);
  node_folder = v8;
  for ( child = node_children; child; child = next_child )
  {
    next_child = child->m_next.pointer;
    child_path = path;
    s = child->m_name;
    vostok::fs_new::path_string_impl::append_path<char const *>(path, &s);
    v7 = vostok::strings::length(child->m_name);
    child_hash = vostok::fs_new::crc32(child->m_name, v7, hash);
    vostok::vfs::archive_mounter::recursive_merge(this, child_path, child_hash, child, node_folder);
    vostok::fs_new::path_string_impl::set_length(path, saved_path_length);
  }
  if ( parent )
    vostok::vfs::mounter::remove_marked_to_unlink_from_parent(parent);
}
