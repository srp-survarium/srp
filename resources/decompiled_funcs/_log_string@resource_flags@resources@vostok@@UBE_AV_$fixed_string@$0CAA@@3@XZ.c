vostok::fixed_string<512> *__thiscall vostok::resources::resource_flags::log_string(
        vostok::resources::resource_flags *this,
        vostok::fixed_string<512> *result)
{
  vostok::fixed_string<512> *v2; // eax

  v2 = result;
  result->m_begin = result->m_buffer;
  result->m_end = result->m_buffer;
  result->m_max_end = (char *)&result[1];
  result->m_buffer[0] = 0;
  *result->m_end = 0;
  return v2;
}
