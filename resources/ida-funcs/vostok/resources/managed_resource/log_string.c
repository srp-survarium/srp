vostok::fixed_string<512> *__thiscall vostok::resources::managed_resource::log_string(
        vostok::resources::managed_resource *this,
        vostok::fixed_string<512> *result)
{
  unsigned int size; // ebx
  vostok::fixed_string<512> *v4; // ecx
  vostok::resources::resource_base::creation_source_enum m_creation_source; // eax
  vostok::vfs::vfs_iterator *p_m_fat_it; // ebx
  vostok::buffer_string *v7; // ecx
  vostok::buffer_string *v8; // ecx
  int raw_file_size; // eax
  vostok::vfs::base_node<1> *m_link_target; // eax
  unsigned int m_uid; // esi
  unsigned int file; // eax
  vostok::buffer_string *v13; // ecx
  unsigned int v14; // eax
  vostok::vfs::base_node<1> *m_node; // eax
  vostok::fs_new::virtual_path_string v17; // [esp+Ch] [ebp-11Ch] BYREF
  unsigned int v18; // [esp+120h] [ebp-8h]
  _BYTE *v19; // [esp+124h] [ebp-4h]

  size = this->m_memory_usage_self.size;
  v18 = size;
  v19 = __RTCastToVoid((void **)&this->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable);
  v4 = result + 1;
  result->m_begin = result->m_buffer;
  result->m_end = result->m_buffer;
  result->m_max_end = (char *)&result[1];
  result->m_buffer[0] = 0;
  result->m_buffer[0] = 0;
  m_creation_source = this->m_creation_source;
  if ( m_creation_source == creation_source_physical_path || m_creation_source == creation_source_user_data )
  {
    vostok::fs_new::path_string_impl::assignf(
      result,
      v4,
      (vostok::buffer_string *)"managed resource : '%s', size = %d [ruid %d] [rptr 0x%x]",
      "<was not saved>",
      size,
      this->m_uid,
      v19);
  }
  else
  {
    p_m_fat_it = &this->m_fat_it;
    vostok::vfs::vfs_iterator::get_virtual_path(
      (vostok::vfs::vfs_iterator *)v4,
      (vostok::fs_new::virtual_path_string *)&this->m_fat_it,
      &v17);
    if ( this->m_fat_it.m_node )
    {
      if ( vostok::vfs::vfs_iterator::is_compressed(&this->m_fat_it)
        && (raw_file_size = vostok::vfs::vfs_iterator::get_raw_file_size(&this->m_fat_it), v18 == raw_file_size) )
      {
        m_link_target = this->m_fat_it.m_link_target;
        m_uid = this->m_uid;
        if ( !m_link_target )
          m_link_target = p_m_fat_it->m_node;
        file = vostok::vfs::get_file_size<1>(m_link_target);
        vostok::buffer_string::appendf(
          result,
          v13,
          (vostok::buffer_string *)"managed compressed resource '%s', uncompressed = %d, compressed = %d [ruid %d] [rptr 0x%x]",
          v17.m_string.m_begin,
          file,
          v18,
          m_uid,
          v19);
      }
      else
      {
        if ( this->m_fat_it.m_node )
        {
          m_node = this->m_fat_it.m_link_target;
          if ( !m_node )
            m_node = this->m_fat_it.m_node;
          v14 = vostok::vfs::get_file_size<1>(m_node);
        }
        else
        {
          v14 = 0;
        }
        vostok::buffer_string::appendf(
          result,
          v8,
          (vostok::buffer_string *)"managed resource '%s', size = %d, raw_file_size = %d [ruid %d] [rptr 0x%x]",
          v17.m_string.m_begin,
          v18,
          v14,
          this->m_uid,
          v19);
      }
    }
    else
    {
      vostok::fs_new::path_string_impl::assignf(
        result,
        v7,
        (vostok::buffer_string *)"managed resource '%s', size = %d [ruid %d] [rptr 0x%x]",
        "<was not saved>",
        this->m_memory_usage_self.size,
        this->m_uid,
        v19);
    }
  }
  return result;
}


vostok::fixed_string<512> *__thiscall vostok::resources::managed_resource::log_string(
        char *this,
        vostok::fixed_string<512> *a2)
{
  return vostok::resources::managed_resource::log_string((vostok::resources::managed_resource *)(this - 208), a2);
}
