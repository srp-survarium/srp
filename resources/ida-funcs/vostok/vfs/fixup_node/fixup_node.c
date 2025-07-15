void __userpurge vostok::vfs::fixup_node::fixup_node(
        vostok::vfs::fixup_node *this@<edi>,
        vostok::vfs::base_node<1> *const node@<ecx>,
        vostok::vfs::mount_root_node_base<1> *mount_root@<eax>,
        char *const buffer_origin)
{
  unsigned __int16 m_flags; // dx
  int v5; // eax
  char *v6; // esi
  vostok::vfs::base_node<1> *v7; // ecx
  vostok::vfs::base_node<1> *v8; // eax
  vostok::vfs::base_folder_node<1> *pointer; // edx
  char *v10; // ecx
  vostok::vfs::base_node<1> *v11; // eax
  vostok::vfs::base_node<1> *v12; // edx
  char *v13; // ecx
  vostok::vfs::base_node<1> *v14; // edx
  vostok::vfs::mount_root_node_base<1> *v15; // ecx
  vostok::vfs::base_node<1> *v16; // eax
  vostok::const_buffer buffer; // [esp+8h] [ebp-14h] BYREF
  vostok::const_buffer v18; // [esp+10h] [ebp-Ch] BYREF

  this->mount_root = mount_root;
  this->node = node;
  this->buffer_origin = buffer_origin;
  m_flags = node->m_flags;
  if ( (m_flags & 0x100) == 0x100 )
  {
    *((_DWORD *)node - 2) += buffer_origin;
  }
  else if ( (m_flags & 0x200) == 0x200 )
  {
    v5 = *((_DWORD *)node - 2);
    if ( v5 )
      v6 = &buffer_origin[v5];
    else
      v6 = 0;
    *((_DWORD *)node - 2) = v6;
  }
  else if ( (m_flags & 8) != 0 )
  {
    vostok::vfs::fixup_node::fixup_folder_mount_root((vostok::vfs::fixup_node *)node, &this->node);
  }
  else if ( (m_flags & 1) != 0 )
  {
    vostok::vfs::fixup_node::fixup_folder_node((vostok::vfs::fixup_node *)node, (int)this);
  }
  else if ( (m_flags & 0x1000) == 0x1000 )
  {
    *((_DWORD *)node - 4) += buffer_origin;
  }
  else if ( (m_flags & 0x40) != 0 )
  {
    v18.m_data = 0;
    v18.m_size = 0;
    vostok::vfs::get_inline_data<1>(node, &v18);
    v7 = this->node;
    buffer.m_data = &v18.m_data[(unsigned int)this->buffer_origin];
    buffer.m_size = v18.m_size;
    vostok::vfs::set_inline_data<1>(v7, &buffer);
  }
  v8 = this->node;
  pointer = this->node->m_parent.pointer;
  if ( pointer )
    v10 = (char *)pointer + (unsigned int)this->buffer_origin;
  else
    v10 = 0;
  v8->m_parent.pointer = (vostok::vfs::base_folder_node<1> *)v10;
  HIDWORD(v8->m_parent.max_storage) = 0;
  v11 = this->node;
  v12 = this->node->m_next.pointer;
  buffer.m_data = 0;
  if ( v12 )
    v13 = (char *)v12 + (unsigned int)this->buffer_origin;
  else
    v13 = 0;
  v14 = 0;
  v11->m_next.pointer = (vostok::vfs::base_node<1> *)v13;
  HIDWORD(v11->m_next.max_storage) = 0;
  v15 = this->mount_root;
  buffer.m_data = 0;
  if ( v15 )
    v14 = v15->node.pointer;
  v16 = this->node;
  if ( v14 == this->node )
  {
    HIDWORD(v16->m_mount_helper_parent.max_storage) = 0;
    v16->m_mount_root.pointer = 0;
  }
  else
  {
    buffer.m_data = 0;
    v16->m_mount_root.pointer = v15;
    HIDWORD(v16->m_mount_helper_parent.max_storage) = 0;
  }
}
