void __cdecl vostok::render::on_fs_iterator_materials_ready(
        char *materials_path,
        const vostok::vfs::vfs_locked_iterator *fs_it,
        volatile int *waiting_for)
{
  vostok::vfs::vfs_iterator *v3; // ecx
  int v4; // edx
  vostok::buffer_string *v5; // ecx
  const char *v6; // edi
  vostok::vfs::vfs_iterator *v7; // ecx
  vostok::vfs::vfs_iterator *v8; // ecx
  vostok::vfs::vfs_iterator *v9; // [esp-4h] [ebp-46164h]
  vostok::vfs::vfs_iterator fs_ita; // [esp+8h] [ebp-46158h] BYREF
  vostok::vfs::vfs_iterator v11; // [esp+18h] [ebp-46148h] BYREF
  vostok::vfs::vfs_hashset *v12; // [esp+28h] [ebp-46138h] BYREF
  _DWORD v13[3]; // [esp+38h] [ebp-46128h] BYREF
  _BYTE v14[260]; // [esp+44h] [ebp-4611Ch] BYREF
  char v15; // [esp+148h] [ebp-46018h] BYREF
  vostok::fixed_vector<vostok::fixed_string<128>,2048> out_material_names; // [esp+150h] [ebp-46010h] BYREF
  char v17; // [esp+4615Ch] [ebp-4h] BYREF

  if ( fs_it->m_node && vostok::vfs::vfs_iterator::get_children_count(&fs_it->vostok::vfs::vfs_iterator) )
  {
    out_material_names.m_begin = (vostok::fixed_string<128> *)out_material_names.m_buffer;
    out_material_names.m_end = (vostok::fixed_string<128> *)out_material_names.m_buffer;
    out_material_names.m_max_end = (vostok::fixed_string<128> *)&v17;
    vostok::vfs::vfs_iterator::children_begin(v3, &fs_ita.m_hashset, &fs_it->vostok::vfs::vfs_iterator);
    while ( fs_ita.m_node )
    {
      if ( vostok::vfs::vfs_iterator::is_folder(&fs_ita) )
      {
        v13[0] = v14;
        v13[1] = v14;
        v13[2] = &v15;
        v14[0] = 0;
        v15 = 47;
        vostok::fs_new::path_string_impl::assignf(v13, v5, (vostok::buffer_string *)"%s/%s", materials_path, v4);
        v6 = (const char *)v13[0];
        v9 = vostok::vfs::vfs_iterator::children_begin(v7, &v12, &fs_ita);
        vostok::render::on_fs_iterator_materials_ready_children(&out_material_names, v6, v9);
      }
      else
      {
        vostok::render::on_fs_iterator_materials_ready_children(&out_material_names, materials_path, &fs_ita);
      }
      vostok::vfs::vfs_iterator::operator++(v8, &fs_ita, &v11);
    }
    vostok::render::process_materials(
      (const vostok::fixed_string<260> *)out_material_names.m_begin,
      waiting_for,
      (const vostok::fixed_string<260> *)out_material_names.m_end);
  }
}
