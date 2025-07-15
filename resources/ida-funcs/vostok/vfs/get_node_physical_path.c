vostok::fs_new::native_path_string *__usercall vostok::vfs::get_node_physical_path<vostok::vfs::base_node,1>@<eax>(
        vostok::vfs::base_node<1> *node@<edi>,
        vostok::vfs::base_node<1> *a2@<ecx>,
        vostok::fs_new::native_path_string *a3)
{
  vostok::fixed_string<260> *v3; // ecx
  vostok::vfs::physical_folder_mount_root_node<1> *mount_root; // esi
  unsigned __int16 m_flags; // ax
  vostok::vfs::universal_file_node<1> *v6; // eax
  vostok::vfs::base_node<1> *pointer; // ecx
  vostok::fixed_string<260> *v9; // [esp-4h] [ebp-470h]
  vostok::fs_new::native_path_string result; // [esp+Ch] [ebp-460h] BYREF
  vostok::fixed_string<260> s; // [esp+124h] [ebp-348h] BYREF
  char v12; // [esp+234h] [ebp-238h]
  vostok::fs_new::virtual_path_string v13; // [esp+23Ch] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string v14; // [esp+354h] [ebp-118h] BYREF

  mount_root = vostok::vfs::base_node<1>::get_mount_root(a2, (int)node);
  m_flags = node->m_flags;
  if ( (m_flags & 4) != 0 )
  {
    vostok::fixed_string<260>::fixed_string<260>(v3, &a3->m_string, (char *)mount_root->physical_path.pointer);
LABEL_12:
    a3->m_separator = 92;
    return a3;
  }
  if ( (m_flags & 0x2000) != 0x2000 )
  {
    v13.m_string.m_begin = v13.m_string.m_buffer;
    v13.m_string.m_end = v13.m_string.m_buffer;
    v13.m_string.m_max_end = &v13.m_separator;
    v13.m_string.m_buffer[0] = 0;
    v13.m_separator = 47;
    vostok::vfs::base_node<1>::get_full_path(node, &v13);
    v14.m_string.m_begin = v14.m_string.m_buffer;
    v14.m_string.m_end = v14.m_string.m_buffer;
    v14.m_string.m_max_end = &v14.m_separator;
    v14.m_string.m_buffer[0] = 0;
    v14.m_separator = 47;
    if ( mount_root )
      pointer = mount_root->node.pointer;
    else
      pointer = 0;
    vostok::vfs::base_node<1>::get_full_path(pointer, &v14);
    vostok::fs_new::native_path_string::convert(
      &result,
      &v13.m_string.m_begin[v14.m_string.m_end - v14.m_string.m_begin]);
    vostok::fixed_string<260>::fixed_string<260>(v9, &s, (char *)mount_root->physical_path.pointer);
    v12 = 92;
    if ( result.m_string.m_end != result.m_string.m_begin && *result.m_string.m_begin != 92 )
    {
      *s.m_end++ = 92;
      *s.m_end = 0;
    }
    vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(&result, &s);
    vostok::fixed_string<260>::fixed_string<260>(&a3->m_string, &s);
    goto LABEL_12;
  }
  v6 = vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(node);
  vostok::fs_new::native_path_string::native_path_string(a3, (char **)v6);
  return a3;
}


vostok::fs_new::native_path_string *__usercall vostok::vfs::get_node_physical_path<vostok::vfs::physical_file_node,1>@<eax>(
        vostok::vfs::physical_file_node<1> *node@<eax>,
        vostok::vfs::base_node<1> *a2@<ecx>,
        vostok::fs_new::native_path_string *a3)
{
  vostok::vfs::base_node<1> *p_base; // edi
  vostok::fixed_string<260> *v4; // ecx
  vostok::vfs::physical_folder_mount_root_node<1> *mount_root; // esi
  unsigned __int16 m_flags; // ax
  vostok::vfs::universal_file_node<1> *v7; // eax
  vostok::vfs::base_node<1> *pointer; // ecx
  vostok::fixed_string<260> *v10; // [esp-4h] [ebp-470h]
  vostok::fs_new::native_path_string result; // [esp+Ch] [ebp-460h] BYREF
  vostok::fixed_string<260> s; // [esp+124h] [ebp-348h] BYREF
  char v13; // [esp+234h] [ebp-238h]
  vostok::fs_new::virtual_path_string v14; // [esp+23Ch] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string v15; // [esp+354h] [ebp-118h] BYREF

  if ( node )
    p_base = &node->base;
  else
    p_base = 0;
  mount_root = vostok::vfs::base_node<1>::get_mount_root(a2, (int)p_base);
  m_flags = p_base->m_flags;
  if ( (m_flags & 4) != 0 )
  {
    vostok::fixed_string<260>::fixed_string<260>(v4, &a3->m_string, (char *)mount_root->physical_path.pointer);
LABEL_15:
    a3->m_separator = 92;
    return a3;
  }
  if ( (m_flags & 0x2000) != 0x2000 )
  {
    v14.m_string.m_begin = v14.m_string.m_buffer;
    v14.m_string.m_end = v14.m_string.m_buffer;
    v14.m_string.m_max_end = &v14.m_separator;
    v14.m_string.m_buffer[0] = 0;
    v14.m_separator = 47;
    vostok::vfs::base_node<1>::get_full_path(p_base, &v14);
    v15.m_string.m_begin = v15.m_string.m_buffer;
    v15.m_string.m_end = v15.m_string.m_buffer;
    v15.m_string.m_max_end = &v15.m_separator;
    v15.m_string.m_buffer[0] = 0;
    v15.m_separator = 47;
    if ( mount_root )
      pointer = mount_root->node.pointer;
    else
      pointer = 0;
    vostok::vfs::base_node<1>::get_full_path(pointer, &v15);
    vostok::fs_new::native_path_string::convert(
      &result,
      &v14.m_string.m_begin[v15.m_string.m_end - v15.m_string.m_begin]);
    vostok::fixed_string<260>::fixed_string<260>(v10, &s, (char *)mount_root->physical_path.pointer);
    v13 = 92;
    if ( result.m_string.m_end != result.m_string.m_begin && *result.m_string.m_begin != 92 )
    {
      *s.m_end++ = 92;
      *s.m_end = 0;
    }
    vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(&result, &s);
    vostok::fixed_string<260>::fixed_string<260>(&a3->m_string, &s);
    goto LABEL_15;
  }
  v7 = vostok::vfs::node_cast<vostok::vfs::universal_file_node,vostok::vfs::base_node,1>(p_base);
  vostok::fs_new::native_path_string::native_path_string(a3, (char **)v7);
  return a3;
}
