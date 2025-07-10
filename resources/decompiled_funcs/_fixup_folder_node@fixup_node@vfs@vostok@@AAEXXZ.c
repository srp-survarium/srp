void __thiscall vostok::vfs::fixup_node::fixup_folder_node(vostok::vfs::fixup_node *this)
{
  char *v2; // [esp+Ch] [ebp-18h]
  vostok::vfs::base_folder_node<1> *folder_node; // [esp+1Ch] [ebp-8h]

  folder_node = vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::base_node,1>(this->node);
  if ( folder_node->m_first_child.pointer )
    v2 = (char *)folder_node->m_first_child.pointer + (unsigned int)this->buffer_origin;
  else
    v2 = 0;
  folder_node->m_first_child.pointer = (vostok::vfs::base_node<1> *)v2;
  HIDWORD(folder_node->m_first_child.max_storage) = 0;
}
