vostok::fixed_string<512> *__thiscall vostok::resources::unmanaged_resource::log_string(
        vostok::resources::unmanaged_resource *this,
        vostok::fixed_string<512> *result)
{
  vostok::buffer_string *v3; // eax
  unsigned int size; // ebx
  vostok::buffer_string *v6; // ecx
  vostok::resources::resource_base::creation_source_enum m_creation_source; // eax
  const char *v8; // eax
  vostok::fs_new::virtual_path_string *virtual_path; // eax
  const char *m_begin; // [esp-10h] [ebp-134h]
  unsigned int v12; // [esp-Ch] [ebp-130h]
  unsigned int v13; // [esp-8h] [ebp-12Ch]
  vostok::buffer_string *v14; // [esp-4h] [ebp-128h]
  vostok::fs_new::virtual_path_string v15; // [esp+Ch] [ebp-118h] BYREF
  vostok::buffer_string *v16; // [esp+120h] [ebp-4h]
  unsigned int m_uid; // [esp+12Ch] [ebp+8h]

  v3 = (vostok::buffer_string *)__RTCastToVoid((void **)&this->__vftable);
  size = this->m_memory_usage_self.size;
  v6 = v3;
  result->m_max_end = (char *)&result[1];
  result->m_begin = result->m_buffer;
  result->m_end = result->m_buffer;
  result->m_buffer[0] = 0;
  m_creation_source = this->m_creation_source;
  v16 = v6;
  if ( m_creation_source == creation_source_physical_path || m_creation_source == creation_source_user_data )
    goto LABEL_11;
  if ( m_creation_source != creation_source_created_by_user )
  {
    if ( m_creation_source == creation_source_deallocate_buffer_helper )
    {
      vostok::fs_new::path_string_impl::assignf(
        result,
        v6,
        (vostok::buffer_string *)"unmanaged resource buffer '%s', size = %d [ruid %d] [rptr 0x%x]",
        "<was not saved>",
        size,
        this->m_uid,
        v6);
      return result;
    }
    if ( this->m_fat_it.m_node )
    {
      m_uid = this->m_uid;
      virtual_path = vostok::vfs::vfs_iterator::get_virtual_path(
                       (vostok::vfs::vfs_iterator *)v6,
                       (vostok::fs_new::virtual_path_string *)&this->m_fat_it,
                       &v15);
      v14 = v16;
      v13 = m_uid;
      v12 = size;
      m_begin = virtual_path->m_string.m_begin;
LABEL_12:
      vostok::fs_new::path_string_impl::assignf(
        result,
        v6,
        (vostok::buffer_string *)"unmanaged resource '%s', size = %d [ruid %d] [rptr 0x%x]",
        m_begin,
        v12,
        v13,
        v14);
      return result;
    }
LABEL_11:
    v14 = v6;
    v13 = this->m_uid;
    v12 = size;
    m_begin = "<was not saved>";
    goto LABEL_12;
  }
  v8 = "sub-fat";
  if ( this->m_class_id != vfs_sub_fat_class )
    v8 = "unmanaged user-resource";
  vostok::fs_new::path_string_impl::assignf(
    result,
    v6,
    (vostok::buffer_string *)"%s: '%s', size = %d [ruid %d] [rptr 0x%x]",
    v8,
    "<was not saved>",
    size,
    this->m_uid,
    v6);
  return result;
}
