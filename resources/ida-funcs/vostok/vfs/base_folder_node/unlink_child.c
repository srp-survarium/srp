char __userpurge vostok::vfs::base_folder_node<1>::unlink_child@<al>(
        vostok::vfs::base_folder_node<1> *this@<ecx>,
        vostok::vfs::base_node<1> **a2@<esi>,
        vostok::vfs::base_node<1> *in_child,
        bool assert_if_not_child)
{
  vostok::vfs::base_node<1> *child; // eax
  vostok::vfs::base_node<1> *v5; // ecx
  vostok::vfs::base_node<1> *pointer; // eax
  vostok::vfs::base_node<1> *out_prev_node; // [esp+4h] [ebp-4h] BYREF

  out_prev_node = 0;
  child = vostok::vfs::base_folder_node<1>::find_child(this, a2, in_child->m_name, &out_prev_node);
  v5 = out_prev_node;
  pointer = child->m_next.pointer;
  if ( out_prev_node )
  {
    out_prev_node->m_next.pointer = pointer;
    HIDWORD(v5->m_next.max_storage) = 0;
  }
  else
  {
    *a2 = pointer;
  }
  return 1;
}
