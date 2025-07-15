void __cdecl vostok::render::on_fs_iterator_materials_ready_children(
        vostok::render::vector<vostok::fs_new::virtual_path_string> *out_material_names,
        const char *materials_path,
        const vostok::vfs::vfs_iterator *fs_it)
{
  unsigned __int8 *name; // esi
  char *m_begin; // esi
  const vostok::vfs::vfs_iterator *v5; // eax
  vostok::vfs::vfs_iterator *v6; // eax
  int v7; // eax
  vostok::buffer_string *v8; // ecx
  vostok::buffer_string *v9; // ecx
  stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *v10; // ecx
  vostok::vfs::vfs_iterator it; // [esp+14h] [ebp-284h] BYREF
  char *other; // [esp+24h] [ebp-274h] BYREF
  vostok::vfs::vfs_iterator v13; // [esp+28h] [ebp-270h] BYREF
  char v14; // [esp+38h] [ebp-260h] BYREF
  vostok::vfs::vfs_iterator result; // [esp+48h] [ebp-250h] BYREF
  vostok::vfs::vfs_iterator v16; // [esp+58h] [ebp-240h] BYREF
  vostok::fs_new::virtual_path_string request_path; // [esp+68h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string new_materials_path; // [esp+180h] [ebp-118h] BYREF

  vostok::vfs::vfs_iterator::vfs_iterator(&it, fs_it);
  if ( it.m_node )
  {
    while ( 1 )
    {
      name = (unsigned __int8 *)vostok::vfs::vfs_iterator::get_name(&it);
      if ( vostok::vfs::vfs_iterator::is_folder(&it) )
        break;
      strstr(name, ".orig");
      if ( !v7 )
      {
        request_path.m_string.m_begin = request_path.m_string.m_buffer;
        request_path.m_string.m_end = request_path.m_string.m_buffer;
        request_path.m_string.m_max_end = &request_path.m_separator;
        request_path.m_string.m_buffer[0] = 0;
        request_path.m_separator = 47;
        vostok::fs_new::path_string_impl::assignf(&request_path, "%s/%s", materials_path, (const char *)name);
        vostok::buffer_string::rtrim(v8, &request_path.m_string);
        vostok::buffer_string::replace(v9, "resources/material_instances/", (const char *)&buf);
        other = request_path.m_string.m_begin;
        vostok::fs_new::virtual_path_string::virtual_path_string(&new_materials_path, (const char **)&other);
        stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::push_back(
          (const stlp_std::__false_type *)&new_materials_path,
          v10,
          &out_material_names->_M_impl);
        v6 = (vostok::vfs::vfs_iterator *)&v14;
        goto LABEL_7;
      }
      vostok::vfs::vfs_iterator::operator++(&it, &v16);
LABEL_8:
      if ( !it.m_node )
        return;
    }
    new_materials_path.m_string.m_begin = new_materials_path.m_string.m_buffer;
    new_materials_path.m_string.m_end = new_materials_path.m_string.m_buffer;
    new_materials_path.m_string.m_max_end = &new_materials_path.m_separator;
    new_materials_path.m_string.m_buffer[0] = 0;
    new_materials_path.m_separator = 47;
    vostok::fs_new::path_string_impl::assignf(&new_materials_path, "%s/%s", materials_path, (const char *)name);
    m_begin = new_materials_path.m_string.m_begin;
    v5 = vostok::vfs::vfs_iterator::children_begin(&it, &result);
    vostok::render::on_fs_iterator_materials_ready_children(out_material_names, m_begin, v5);
    v6 = &v13;
LABEL_7:
    vostok::vfs::vfs_iterator::operator++(&it, v6);
    goto LABEL_8;
  }
}
