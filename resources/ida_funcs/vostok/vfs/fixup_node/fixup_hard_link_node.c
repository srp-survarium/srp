void __thiscall vostok::vfs::fixup_node::fixup_hard_link_node(vostok::vfs::fixup_node *this)
{
  char *v2; // [esp+4h] [ebp-Ch]
  vostok::vfs::hard_link_node<1> *hard_link; // [esp+8h] [ebp-8h]

  hard_link = vostok::vfs::node_cast<vostok::vfs::soft_link_node,vostok::vfs::base_node,1>(this->node);
  if ( hard_link->referenced.pointer )
    v2 = (char *)hard_link->referenced.pointer + (unsigned int)this->buffer_origin;
  else
    v2 = 0;
  hard_link->referenced.pointer = (vostok::vfs::base_node<1> *)v2;
}
