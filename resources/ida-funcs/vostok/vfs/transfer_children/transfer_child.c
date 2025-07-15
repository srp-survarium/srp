void __userpurge vostok::vfs::transfer_children::transfer_child(
        vostok::vfs::transfer_children *this@<eax>,
        vostok::vfs::base_node<1> *const child@<esi>,
        const vostok::fs_new::virtual_path_string *path,
        unsigned int hash)
{
  vostok::vfs::base_node<1> *v5; // eax
  vostok::vfs::base_node<1> *v6; // edi
  vostok::vfs::base_folder_node<1> *v7; // eax
  unsigned int v8; // eax
  vostok::vfs::base_node<1> *m_dest_start; // ebx
  vostok::vfs::base_node<1> *m_source_folder; // eax
  vostok::vfs::base_folder_node<1> *v11; // eax
  bool *v12; // [esp+0h] [ebp-158h]
  vostok::vfs::transfer_children v13; // [esp+8h] [ebp-150h] BYREF
  unsigned int v14; // [esp+14Ch] [ebp-Ch]
  vostok::vfs::base_node<1> *dest_start; // [esp+150h] [ebp-8h] BYREF
  vostok::vfs::base_node<1> *node; // [esp+154h] [ebp-4h] BYREF

  dest_start = 0;
  node = 0;
  vostok::vfs::transfer_children::find_first_and_last_overlapper(this, path, &dest_start, &node, hash, child);
  v5 = node;
  if ( node )
  {
    node->m_next_overlapped.pointer = child;
    v8 = vostok::vfs::mount_id_of_node<1>(v5);
    node = 0;
    m_dest_start = this->m_dest_start;
    v14 = v8;
    while ( m_dest_start )
    {
      if ( vostok::vfs::mount_id_of_node<1>(m_dest_start) < v14 )
      {
        node = m_dest_start;
        break;
      }
      m_dest_start = m_dest_start->m_next_overlapped.pointer;
    }
    if ( (node->m_flags & 1) == 0 )
      goto LABEL_17;
    m_source_folder = (vostok::vfs::base_node<1> *)this->m_source_folder;
    if ( m_source_folder )
      m_source_folder = (vostok::vfs::base_node<1> *)((char *)m_source_folder + 16);
    if ( node == m_source_folder )
    {
LABEL_17:
      vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)node,
        (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *)&this->m_new_source_nodes,
        (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper)(unsigned int)child,
        v12);
    }
    else
    {
      v11 = vostok::vfs::cast_folder<1>(node);
      child->m_parent.pointer = v11;
      child->m_next.max_storage = v11->m_first_child.max_storage;
      v11->m_first_child.pointer = child;
    }
    if ( (child->m_flags & 1) != 0 && dest_start )
      vostok::vfs::transfer_children::transfer_children(&v13, this->m_hashset, path, hash, dest_start, child);
  }
  else
  {
    v6 = this->m_dest_start;
    if ( v6 )
      v7 = vostok::vfs::cast_folder<1>(v6);
    else
      v7 = 0;
    child->m_parent.pointer = v7;
    child->m_next.max_storage = v7->m_first_child.max_storage;
    v7->m_first_child.pointer = child;
  }
}
