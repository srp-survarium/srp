vostok::fixed_string<512> *__thiscall vostok::resources::query_result::log_string(
        vostok::resources::query_result *this,
        vostok::fixed_string<512> *result)
{
  const char *requested_path; // eax
  vostok::buffer_string *v3; // ecx
  unsigned int m_uid; // [esp-8h] [ebp-Ch]
  vostok::resources::class_id_enum m_class_id; // [esp-4h] [ebp-8h]

  result->m_begin = result->m_buffer;
  result->m_end = result->m_buffer;
  result->m_max_end = (char *)&result[1];
  result->m_buffer[0] = 0;
  result->m_buffer[0] = 0;
  m_class_id = this->m_class_id;
  m_uid = this->m_uid;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(this);
  vostok::fs_new::path_string_impl::assignf(
    result,
    v3,
    (vostok::buffer_string *)"'%s' [quid %d][class %d]",
    requested_path,
    m_uid,
    m_class_id);
  return result;
}
