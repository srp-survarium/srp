void __thiscall vostok::vfs::query_mount_arguments::convert_pathes_to_absolute(
        vostok::vfs::query_mount_arguments *this)
{
  vostok::buffer_string *v1; // ecx
  vostok::fs_new::native_path_string *p_archive_physical_path; // [esp+248h] [ebp-138h]
  vostok::fs_new::native_path_string *p_fat_physical_path; // [esp+254h] [ebp-12Ch]

  vostok::buffer_string::make_lowercase(&this->virtual_path.m_string, (int)this);
  if ( this->type == mount_type_physical_path )
  {
    vostok::buffer_string::make_lowercase(&this->physical_path.m_string, (int)&this->physical_path);
    vostok::fs_new::convert_to_absolute_path_inplace(&this->physical_path, assert_on_fail_true);
  }
  else
  {
    vostok::buffer_string::make_lowercase(&this->archive_physical_path.m_string, (int)&this->archive_physical_path);
    vostok::buffer_string::make_lowercase(v1, (int)&this->fat_physical_path);
    if ( vostok::fs_new::path_string_impl::length(&this->fat_physical_path) )
    {
      if ( !vostok::fs_new::path_string_impl::length(&this->archive_physical_path) )
      {
        p_archive_physical_path = &this->archive_physical_path;
        if ( &this->archive_physical_path != &this->fat_physical_path )
          vostok::buffer_string::operator=(
            (vostok::fixed_string<32> *)&this->fat_physical_path,
            (vostok::fixed_string<32> *)p_archive_physical_path);
        vostok::fs_new::path_string_impl::verify_self(p_archive_physical_path);
      }
    }
    else
    {
      p_fat_physical_path = &this->fat_physical_path;
      if ( &this->fat_physical_path != &this->archive_physical_path )
        vostok::buffer_string::operator=(
          (vostok::fixed_string<32> *)&this->archive_physical_path,
          (vostok::fixed_string<32> *)p_fat_physical_path);
      vostok::fs_new::path_string_impl::verify_self(p_fat_physical_path);
    }
    vostok::fs_new::convert_to_absolute_path_inplace(&this->archive_physical_path, assert_on_fail_true);
    vostok::fs_new::convert_to_absolute_path_inplace(&this->fat_physical_path, assert_on_fail_true);
  }
}
