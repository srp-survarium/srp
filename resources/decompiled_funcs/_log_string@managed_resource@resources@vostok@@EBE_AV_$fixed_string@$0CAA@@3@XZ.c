vostok::fixed_string<512> *__thiscall vostok::resources::managed_resource::log_string(
        vostok::resources::managed_resource *this,
        vostok::fixed_string<512> *result)
{
  unsigned int size; // ebx
  _BYTE *v4; // ebp
  vostok::resources::resource_base::creation_source_enum m_creation_source; // eax
  unsigned int m_uid; // eax
  char *m_begin; // edi
  int file_size; // eax
  int v10; // eax
  unsigned int v11; // [esp-8h] [ebp-130h]
  vostok::vfs::vfs_iterator *p_m_fat_it; // [esp+10h] [ebp-118h]
  vostok::fs_new::virtual_path_string full_path; // [esp+14h] [ebp-114h] BYREF

  size = this->m_memory_usage_self.size;
  v4 = __RTCastToVoid((void **)&this->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable);
  result->m_begin = result->m_buffer;
  result->m_end = result->m_buffer;
  result->m_max_end = (char *)&result[1];
  result->m_buffer[0] = 0;
  result->m_buffer[0] = 0;
  m_creation_source = this->m_creation_source;
  if ( m_creation_source == creation_source_physical_path || m_creation_source == creation_source_user_data )
  {
    vostok::buffer_string::assignf(
      result,
      "managed resource : '%s', size = %d [ruid %d] [rptr 0x%x]",
      "<was not saved>",
      size,
      this->m_uid,
      v4);
    return result;
  }
  p_m_fat_it = &this->m_fat_it;
  vostok::vfs::vfs_iterator::get_virtual_path(&this->m_fat_it, &full_path);
  if ( !this->m_fat_it.m_node )
  {
    vostok::buffer_string::assignf(
      result,
      "managed resource '%s', size = %d [ruid %d] [rptr 0x%x]",
      "<was not saved>",
      this->m_memory_usage_self.size,
      this->m_uid,
      v4);
    return result;
  }
  if ( vostok::vfs::vfs_iterator::is_compressed(p_m_fat_it)
    && size == vostok::vfs::vfs_iterator::get_raw_file_size(p_m_fat_it) )
  {
    m_uid = this->m_uid;
    m_begin = full_path.m_string.m_begin;
    v11 = m_uid;
    file_size = vostok::vfs::vfs_iterator::get_file_size(p_m_fat_it);
    vostok::buffer_string::appendf((vostok::buffer_string *)&stru_95DAC0, m_begin, file_size, size, v11, v4);
    return result;
  }
  else
  {
    if ( this->m_fat_it.m_node )
      v10 = vostok::vfs::vfs_iterator::get_file_size(p_m_fat_it);
    else
      v10 = 0;
    vostok::buffer_string::appendf(
      (vostok::buffer_string *)&stru_95DB20,
      full_path.m_string.m_begin,
      size,
      v10,
      this->m_uid,
      v4);
    return result;
  }
}
