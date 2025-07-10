vostok::render::shader_constant *__fastcall vostok::render::shader_constant_table::get(
        vostok::render::shader_constant_table *this,
        const vostok::shared_string *name)
{
  vostok::render::shader_constant *result; // eax
  vostok::render::shader_constant *M_finish; // ecx
  vostok::strings::shared::profile *m_object; // edx

  result = this->m_table._M_impl._M_start;
  M_finish = this->m_table._M_impl._M_finish;
  if ( result == M_finish )
    return 0;
  m_object = name->m_pointer.m_object;
  while ( result->m_host->m_name.m_pointer.m_object != m_object )
  {
    if ( ++result == M_finish )
      return 0;
  }
  return result;
}
