void __thiscall vostok::vfs::fixup_node::fixup_base_node(vostok::vfs::fixup_node *this)
{
  vostok::platform_pointer_selector<vostok::vfs::base_folder_node<1>,1>::helper *v1; // ecx
  vostok::vfs::base_node<1> *v2; // eax
  vostok::vfs::base_node<1> *v3; // edx
  vostok::vfs::mount_root_node_base<1> *mount_root; // [esp+14h] [ebp-54h]
  vostok::vfs::base_node<1> *v6; // [esp+18h] [ebp-50h]
  char *v7; // [esp+1Ch] [ebp-4Ch] BYREF
  int v8; // [esp+20h] [ebp-48h]
  vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *p_m_next; // [esp+24h] [ebp-44h]
  char *v10; // [esp+28h] [ebp-40h]
  char **v11; // [esp+2Ch] [ebp-3Ch]
  vostok::vfs::base_node<1> *v12; // [esp+30h] [ebp-38h]
  vostok::vfs::base_node<1> *node; // [esp+34h] [ebp-34h]
  char *v14; // [esp+38h] [ebp-30h] BYREF
  int v15; // [esp+3Ch] [ebp-2Ch]
  vostok::platform_pointer_selector<vostok::vfs::base_folder_node<1>,1>::helper *p_m_parent; // [esp+40h] [ebp-28h]
  char *v17; // [esp+44h] [ebp-24h]
  char **v18; // [esp+48h] [ebp-20h]
  vostok::vfs::base_folder_node<1> *pointer; // [esp+4Ch] [ebp-1Ch]
  vostok::platform_pointer_selector<vostok::vfs::mount_root_node_base<1>,1>::helper_pod mount_root_pointer; // [esp+58h] [ebp-10h]
  unsigned int next_offs; // [esp+60h] [ebp-8h]
  unsigned int parent_offs; // [esp+64h] [ebp-4h]

  pointer = this->node->m_parent.pointer;
  parent_offs = (unsigned int)pointer;
  if ( pointer )
    v17 = &this->buffer_origin[parent_offs];
  else
    v17 = 0;
  v18 = &v14;
  v15 = 0;
  v14 = v17;
  node = this->node;
  p_m_parent = &node->m_parent;
  v1 = &node->m_parent;
  node->m_parent.pointer = (vostok::vfs::base_folder_node<1> *)v17;
  HIDWORD(v1->max_storage) = v15;
  v12 = this->node->m_next.pointer;
  next_offs = (unsigned int)v12;
  if ( v12 )
    v10 = &this->buffer_origin[next_offs];
  else
    v10 = 0;
  v11 = &v7;
  v8 = 0;
  v7 = v10;
  v6 = this->node;
  p_m_next = &v6->m_next;
  v6->m_next.pointer = (vostok::vfs::base_node<1> *)v10;
  HIDWORD(v6->m_next.max_storage) = v8;
  if ( vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>(this->mount_root) == this->node )
  {
    v3 = this->node;
    v3->m_mount_root.pointer = 0;
    HIDWORD(v3->m_mount_helper_parent.max_storage) = 0;
    v3->m_mount_root.pointer = 0;
  }
  else
  {
    mount_root = this->mount_root;
    mount_root_pointer = (vostok::platform_pointer_selector<vostok::vfs::mount_root_node_base<1>,1>::helper_pod)(unsigned int)mount_root;
    v2 = this->node;
    v2->m_mount_root.pointer = mount_root;
    HIDWORD(v2->m_mount_helper_parent.max_storage) = 0;
  }
}
