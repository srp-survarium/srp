vostok::fixed_string<512> *__thiscall vostok::resources::query_result::log_string(
        vostok::resources::query_result *this,
        vostok::fixed_string<512> *result)
{
  char *m_requery_path; // eax

  result->m_begin = result->m_buffer;
  result->m_end = result->m_buffer;
  result->m_max_end = (char *)&result[1];
  result->m_buffer[0] = 0;
  result->m_buffer[0] = 0;
  m_requery_path = this->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = this->m_request_path;
  vostok::buffer_string::assignf(result, "'%s' [quid %d][class %d]", m_requery_path, this->m_uid, this->m_class_id);
  return result;
}
