vostok::vfs::base_node<1> *__userpurge vostok::vfs::query_notification_operation::find_node_on_virtual_path@<eax>(
        vostok::vfs::overlapped_node_iterator *it@<eax>,
        vostok::vfs::overlapped_node_iterator *this,
        vostok::vfs::overlapped_node_iterator *it_end)
{
  vostok::vfs::base_node<1> *node; // edi

  while ( 1 )
  {
    node = it->node;
    if ( (node != 0) == (it_end->node != 0) )
      return 0;
    if ( (vostok::vfs::base_node<1> *)vostok::vfs::mount_id_of_node<1>(it->node) == this[2].node )
      break;
    vostok::vfs::overlapped_node_iterator::operator++(this, (int)it);
  }
  return node;
}
