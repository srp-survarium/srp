vostok::fs_new::native_path_string *__usercall vostok::resources::query_result::absolute_physical_path@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::fixed_string<260> *v4; // ecx
  vostok::vfs::base_node<1> *m_link_target; // ecx
  vostok::fs_new::native_path_string *physical_path; // eax
  vostok::fs_new::native_path_string *v7; // eax
  vostok::fs_new::native_path_string v9; // [esp+Ch] [ebp-354h] BYREF
  vostok::fs_new::native_path_string v10; // [esp+120h] [ebp-240h] BYREF
  vostok::fs_new::native_path_string v11; // [esp+238h] [ebp-128h] BYREF
  _DWORD v12[4]; // [esp+350h] [ebp-10h] BYREF

  vostok::fs_new::native_path_string::native_path_string(&v11);
  if ( (this->m_flags & 8) != 0 )
  {
    vostok::fixed_string<260>::fixed_string<260>(
      v4,
      (vostok::buffer_string *)a2,
      this->m_save_generated_data->m_physical_path);
  }
  else
  {
    v12[0] = this->m_fat_it.m_hashset;
    v12[1] = this->m_fat_it.m_node;
    m_link_target = this->m_fat_it.m_link_target;
    v12[3] = this->m_fat_it.m_type;
    v12[2] = m_link_target;
    physical_path = vostok::vfs::vfs_iterator::get_physical_path(
                      (vostok::vfs::vfs_iterator *)m_link_target,
                      (int)v12,
                      &v9);
    if ( &v11 != physical_path )
      vostok::buffer_string::operator=(&physical_path->m_string, &v11.m_string);
    if ( v11.m_string.m_end == v11.m_string.m_begin )
    {
      v7 = &v11;
    }
    else
    {
      vostok::fs_new::native_path_string::native_path_string(&v10);
      vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
        &v11,
        (char *)a2,
        &v10,
        assert_on_fail_true);
      v7 = &v10;
    }
    vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)a2, &v7->m_string);
  }
  *(_BYTE *)(a2 + 272) = 92;
  return (vostok::fs_new::native_path_string *)a2;
}
