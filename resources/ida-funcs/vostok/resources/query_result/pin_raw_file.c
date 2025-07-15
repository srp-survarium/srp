vostok::resources::query_result_for_cook **__userpurge vostok::resources::query_result::pin_raw_file@<eax>(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::query_result_for_cook **a2@<esi>,
        vostok::resources::query_result *result)
{
  unsigned int m_offset_to_file; // ebx
  vostok::const_buffer *v4; // eax
  vostok::resources::query_result_for_cook *m_data; // ecx
  vostok::resources::query_result_for_cook *raw_file_size; // eax
  vostok::resources::query_result_for_cook *v7; // ecx
  const char *v9; // [esp+8h] [ebp-Ch] BYREF

  m_offset_to_file = result->m_offset_to_file;
  v4 = vostok::resources::query_result::pin_raw_buffer(result, &v9);
  m_data = (vostok::resources::query_result_for_cook *)v4->m_data;
  a2[1] = (vostok::resources::query_result_for_cook *)v4->m_size;
  a2[1] = (vostok::resources::query_result_for_cook *)((char *)a2[1] - m_offset_to_file);
  *a2 = m_data;
  *a2 = (vostok::resources::query_result_for_cook *)((char *)*a2 + m_offset_to_file);
  raw_file_size = (vostok::resources::query_result_for_cook *)vostok::resources::query_result_for_cook::get_raw_file_size(
                                                                m_data,
                                                                result);
  v7 = *a2;
  a2[1] = raw_file_size;
  *a2 = v7;
  return a2;
}
