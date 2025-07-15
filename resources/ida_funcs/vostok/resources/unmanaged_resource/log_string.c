vostok::fixed_string<512> *__thiscall vostok::resources::unmanaged_resource::log_string(
        vostok::resources::unmanaged_resource *this,
        vostok::fixed_string<512> *result)
{
  _BYTE *v3; // eax
  unsigned int size; // ebp
  _BYTE *v5; // ebx
  vostok::resources::resource_base::creation_source_enum m_creation_source; // eax
  const char *v7; // eax
  vostok::fs_new::virtual_path_string *virtual_path; // eax
  const char *m_begin; // [esp-10h] [ebp-138h]
  unsigned int v11; // [esp-Ch] [ebp-134h]
  unsigned int m_uid; // [esp-8h] [ebp-130h]
  _BYTE *v13; // [esp-4h] [ebp-12Ch]
  unsigned int v14; // [esp+10h] [ebp-118h]
  vostok::fs_new::virtual_path_string v15; // [esp+14h] [ebp-114h] BYREF

  v3 = __RTCastToVoid((void **)&this->__vftable);
  size = this->m_memory_usage_self.size;
  v5 = v3;
  result->m_begin = result->m_buffer;
  result->m_end = result->m_buffer;
  result->m_max_end = (char *)&result[1];
  result->m_buffer[0] = 0;
  result->m_buffer[0] = 0;
  m_creation_source = this->m_creation_source;
  if ( m_creation_source == creation_source_physical_path || m_creation_source == creation_source_user_data )
  {
    v13 = v5;
    m_uid = this->m_uid;
    goto LABEL_13;
  }
  if ( m_creation_source != creation_source_created_by_user )
  {
    if ( m_creation_source == creation_source_deallocate_buffer_helper )
    {
      vostok::buffer_string::assignf(
        result,
        "unmanaged resource buffer '%s', size = %d [ruid %d] [rptr 0x%x]",
        "<was not saved>",
        size,
        this->m_uid,
        v5);
      return result;
    }
    if ( this->m_fat_it.m_node )
    {
      v14 = this->m_uid;
      virtual_path = vostok::vfs::vfs_iterator::get_virtual_path(&this->m_fat_it, &v15);
      v13 = v5;
      m_uid = v14;
      v11 = size;
      m_begin = virtual_path->m_string.m_begin;
LABEL_14:
      vostok::buffer_string::assignf(
        result,
        "unmanaged resource '%s', size = %d [ruid %d] [rptr 0x%x]",
        m_begin,
        v11,
        m_uid,
        v13);
      return result;
    }
    v13 = v5;
    m_uid = this->m_uid;
LABEL_13:
    v11 = size;
    m_begin = "<was not saved>";
    goto LABEL_14;
  }
  v7 = "sub-fat";
  if ( this->m_class_id != vfs_sub_fat_class )
    v7 = "unmanaged user-resource";
  vostok::buffer_string::assignf(
    result,
    "%s: '%s', size = %d [ruid %d] [rptr 0x%x]",
    v7,
    "<was not saved>",
    size,
    this->m_uid,
    v5);
  return result;
}
