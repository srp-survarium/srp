char __thiscall vostok::render::render_cc_float::fill_macro(
        vostok::render::render_cc_float *this,
        vostok::render::shader_macro *out_macro)
{
  char *m_define_name; // edx
  char *m_begin; // eax

  if ( !this->m_define_name )
    return 0;
  vostok::fs_new::path_string_impl::assignf(
    &out_macro->definition.m_begin,
    (vostok::buffer_string *)this,
    (vostok::buffer_string *)"%f",
    (const char *)COERCE_UNSIGNED_INT64(*this->m_value),
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*this->m_value)));
  m_define_name = (char *)this->m_define_name;
  m_begin = out_macro->name.m_string.m_begin;
  if ( out_macro->name.m_string.m_begin != m_define_name )
  {
    out_macro->name.m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&out_macro->name.m_string, m_define_name);
  }
  return 1;
}
