void __thiscall vostok::resources::managed_cook::translate_request_path(
        vostok::resources::managed_cook *this,
        char *request,
        vostok::fs_new::virtual_path_string *new_request)
{
  char *m_begin; // ecx

  m_begin = new_request->m_string.m_begin;
  if ( new_request->m_string.m_begin != request )
  {
    new_request->m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&new_request->m_string, request);
  }
}
