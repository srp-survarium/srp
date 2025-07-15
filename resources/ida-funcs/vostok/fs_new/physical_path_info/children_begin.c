vostok::fs_new::physical_path_initializer *__userpurge vostok::fs_new::physical_path_info::children_begin@<eax>(
        vostok::fs_new::physical_path_info *this@<ecx>,
        vostok::fs_new::physical_path_info *a2@<esi>,
        vostok::fs_new::physical_path_initializer *result)
{
  vostok::fs_new::device_file_system_interface *device; // eax
  int v4; // edi
  char *v5; // eax
  vostok::fs_new::physical_path_info_data *v6; // ecx
  unsigned __int64 v8; // [esp+8h] [ebp-144h] BYREF
  const vostok::fs_new::physical_path_info *v9; // [esp+10h] [ebp-13Ch]
  vostok::fs_new::physical_path_info_data v10; // [esp+18h] [ebp-134h] BYREF
  vostok::fs_new::device_file_system_interface *v11; // [esp+140h] [ebp-Ch]

  if ( a2->data.type == type_file )
  {
    vostok::fs_new::physical_path_initializer::physical_path_initializer(
      (vostok::fs_new::physical_path_initializer *)this,
      result);
  }
  else
  {
    vostok::fs_new::physical_path_initializer::physical_path_initializer(
      (vostok::fs_new::physical_path_initializer *)this,
      &v8);
    device = a2->device;
    v8 = -1;
    v11 = device;
    v9 = a2;
    vostok::fs_new::physical_path_info::initialize_full_path_if_needed(a2);
    v4 = a2->data.path.m_string.m_end - a2->data.path.m_string.m_begin;
    *a2->data.path.m_string.m_end++ = 92;
    *a2->data.path.m_string.m_end = 0;
    *a2->data.path.m_string.m_end++ = 42;
    *a2->data.path.m_string.m_end = 0;
    a2->device->find_first(a2->device, &v8, &v10, a2->data.path.m_string.m_begin);
    v5 = &a2->data.path.m_string.m_begin[v4];
    a2->data.path.m_string.m_end = v5;
    *v5 = 0;
    result->search_handle = v8;
    result->parent = v9;
    vostok::fs_new::physical_path_info_data::physical_path_info_data(v6, (int)&result->data, &v10);
    result->device = v11;
  }
  return result;
}
