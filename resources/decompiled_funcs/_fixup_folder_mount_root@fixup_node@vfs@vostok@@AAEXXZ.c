void __thiscall vostok::vfs::fixup_node::fixup_folder_mount_root(vostok::vfs::fixup_node *this)
{
  vostok::fixed_string<32> *v2; // [esp+64h] [ebp-14h]
  vostok::fs_new::native_path_string *v3; // [esp+68h] [ebp-10h]
  vostok::fs_new::native_path_string *v4; // [esp+6Ch] [ebp-Ch]
  vostok::fs_new::virtual_path_string *v5; // [esp+70h] [ebp-8h]
  vostok::vfs::base_node<1> *mount_root; // [esp+74h] [ebp-4h]

  vostok::vfs::fixup_node::fixup_folder_node(this);
  mount_root = vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::base_node,1>(this->node);
  v5 = (vostok::fs_new::virtual_path_string *)operator new(0x114u, &mount_root->m_name[53]);
  if ( v5 )
    vostok::fs_new::virtual_path_string::virtual_path_string(v5);
  v4 = (vostok::fs_new::native_path_string *)operator new(0x114u, &mount_root->m_name[313]);
  if ( v4 )
    vostok::fs_new::native_path_string::native_path_string(v4);
  v3 = (vostok::fs_new::native_path_string *)operator new(0x114u, &mount_root->m_name[573]);
  if ( v3 )
    vostok::fs_new::native_path_string::native_path_string(v3);
  v2 = (vostok::fixed_string<32> *)operator new(0x2Cu, &mount_root->m_name[833]);
  if ( v2 )
    vostok::fixed_string<32>::fixed_string<32>(v2);
  *(_DWORD *)&mount_root->m_name[13] = this->node;
}
