vostok::vfs::base_node<1> *__thiscall vostok::vfs::query_notification_operation::find_node_on_virtual_path(
        vostok::vfs::query_notification_operation *this,
        vostok::vfs::overlapped_node_iterator *it,
        vostok::vfs::overlapped_node_iterator *it_end)
{
  vostok::vfs::base_node<1> *node; // [esp+8h] [ebp-4h]

  while ( (it->node != 0) != (it_end->node != 0) )
  {
    node = it->node;
    if ( vostok::vfs::mount_id_of_node<1>(node) == this->m_mount_id )
      return node;
    vostok::vfs::overlapped_node_iterator::operator++(it);
  }
  return 0;
}
