const char *__thiscall vostok::resources::query_result_for_user::get_requested_path(
        vostok::resources::query_result_for_user *this)
{
  const char *result; // eax

  result = this->m_requery_path;
  if ( !result )
    return this->m_request_path;
  return result;
}
