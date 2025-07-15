void __cdecl vostok::render::on_fs_iterator_materials_ready_children(
        vostok::fixed_vector<vostok::fixed_string<128>,2048> *out_material_names,
        const char *materials_path,
        const vostok::vfs::vfs_iterator *fs_it)
{
  vostok::vfs::base_node<1> *m_link_target; // edx
  vostok::vfs::base_node<1> *m_node; // ecx
  vostok::vfs::vfs_iterator::type_enum m_type; // eax
  unsigned __int8 *m_name; // esi
  vostok::buffer_string *v7; // ecx
  const char *v8; // edi
  vostok::vfs::vfs_iterator *v9; // ecx
  vostok::vfs::vfs_iterator *v10; // eax
  vostok::vfs::vfs_iterator *v11; // ecx
  vostok::vfs::vfs_iterator *v12; // eax
  int v13; // eax
  int v14; // eax
  vostok::buffer_string *v15; // ecx
  vostok::fixed_string<128> *v16; // ecx
  vostok::buffer_vector<vostok::fixed_string<128> > *v17; // ecx
  vostok::vfs::vfs_iterator *v18; // [esp-4h] [ebp-298h]
  vostok::buffer_string *v19; // [esp-4h] [ebp-298h]
  char *materials_patha[3]; // [esp+10h] [ebp-284h] BYREF
  _BYTE v21[124]; // [esp+1Ch] [ebp-278h] BYREF
  vostok::fixed_string<128> value; // [esp+98h] [ebp-1FCh] BYREF
  vostok::buffer_string v23; // [esp+128h] [ebp-16Ch] BYREF
  _BYTE v24[260]; // [esp+134h] [ebp-160h] BYREF
  char v25; // [esp+238h] [ebp-5Ch] BYREF
  vostok::vfs::vfs_hashset *v26; // [esp+240h] [ebp-54h] BYREF
  char v27; // [esp+250h] [ebp-44h] BYREF
  char v28; // [esp+260h] [ebp-34h] BYREF
  char v29; // [esp+270h] [ebp-24h] BYREF
  vostok::vfs::vfs_iterator v30; // [esp+280h] [ebp-14h] BYREF

  m_link_target = fs_it->m_link_target;
  v30.m_hashset = fs_it->m_hashset;
  m_node = fs_it->m_node;
  m_type = fs_it->m_type;
  v30.m_node = m_node;
  v30.m_link_target = m_link_target;
  for ( v30.m_type = m_type; v30.m_node; m_node = v30.m_node )
  {
    m_name = (unsigned __int8 *)m_node->m_name;
    if ( vostok::vfs::vfs_iterator::is_folder(&v30) )
    {
      materials_patha[0] = v21;
      materials_patha[1] = v21;
      materials_patha[2] = &value.m_buffer[124];
      v21[0] = 0;
      value.m_buffer[124] = 47;
      vostok::fs_new::path_string_impl::assignf(
        materials_patha,
        v7,
        (vostok::buffer_string *)"%s/%s",
        materials_path,
        m_name);
      v8 = materials_patha[0];
      v10 = vostok::vfs::vfs_iterator::children_begin(v9, &v26, &v30);
      vostok::render::on_fs_iterator_materials_ready_children(out_material_names, v8, v10);
      v12 = (vostok::vfs::vfs_iterator *)&v27;
    }
    else
    {
      strstr(m_name, ".orig");
      v11 = v18;
      if ( v13 || (strstr(m_name, ".rej"), v11 = (vostok::vfs::vfs_iterator *)v19, v14) )
      {
        v12 = (vostok::vfs::vfs_iterator *)&v28;
      }
      else
      {
        v23.m_begin = v24;
        v23.m_end = v24;
        v23.m_max_end = &v25;
        v24[0] = 0;
        v25 = 47;
        vostok::fs_new::path_string_impl::assignf(&v23, v19, (vostok::buffer_string *)"%s/%s", materials_path, m_name);
        while ( vostok::buffer_string::ends_with(v15, (int)&v23, ".material") )
        {
          v23.m_end -= 9;
          *v23.m_end = 0;
        }
        vostok::buffer_string::replace(v15, &v23, "resources/material_instances/", (char *)uri);
        vostok::fixed_string<128>::fixed_string<128>(v16, &value, v23.m_begin);
        vostok::buffer_vector<vostok::fixed_string<128>>::push_back(v17, (int)out_material_names, &value);
        v12 = (vostok::vfs::vfs_iterator *)&v29;
      }
    }
    vostok::vfs::vfs_iterator::operator++(v11, &v30, v12);
  }
}
