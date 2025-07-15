void __userpurge vostok::vfs::mounter::merge_root_node_with_tree(
        vostok::vfs::base_node<1> *new_root_node@<ecx>,
        vostok::vfs::base_node<1> *top_root_node@<eax>,
        vostok::vfs::mounter *this,
        bool *added_ontop)
{
  unsigned int v6; // ebx
  vostok::vfs::base_folder_node<1> *v7; // ebx
  vostok::vfs::base_folder_node<1> *v8; // eax
  vostok::vfs::virtual_file_system *m_file_system; // eax
  boost::function<void __cdecl(vostok::vfs::vfs_iterator &)> *p_on_node_hides; // edi
  const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v11; // eax
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v12; // ecx
  _DWORD v13[4]; // [esp+Ch] [ebp-14h] BYREF
  vostok::vfs::base_node<1> *v14; // [esp+1Ch] [ebp-4h]

  v14 = 0;
  v6 = vostok::vfs::mount_id_of_node<1>(new_root_node);
  if ( top_root_node )
  {
    do
    {
      if ( vostok::vfs::mount_id_of_node<1>(top_root_node) <= v6 )
        break;
      v14 = top_root_node;
      top_root_node = top_root_node->m_next_overlapped.pointer;
    }
    while ( top_root_node );
    if ( top_root_node && (top_root_node->m_flags & 1) != 0 && (new_root_node->m_flags & 1) != 0 )
    {
      v7 = vostok::vfs::cast_folder<1>(top_root_node);
      v8 = vostok::vfs::cast_folder<1>(new_root_node);
      vostok::vfs::transfer_children_to_empty_folder(v8, v7);
    }
    if ( v14 )
      v14->m_next_overlapped.pointer = new_root_node;
  }
  new_root_node->m_next_overlapped.pointer = top_root_node;
  m_file_system = this->m_file_system;
  p_on_node_hides = &m_file_system->on_node_hides;
  if ( (m_file_system->on_node_hides.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0
    && top_root_node )
  {
    v13[2] = 0;
    v13[0] = &m_file_system->hashset;
    v13[1] = top_root_node;
    v13[3] = 2;
    vostok::vfs::vfs_iterator::vfs_iterator((vostok::vfs::vfs_iterator *)top_root_node, (int)v13);
    boost::function1<void,vostok::collision::object const &>::operator()(v12, p_on_node_hides, v11);
  }
  *added_ontop = v14 == 0;
}
