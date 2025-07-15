char __thiscall vostok::render::render_cc_float::fill_macro(
        vostok::render::render_cc_float *this,
        vostok::render::shader_macro *out_macro)
{
  char *m_begin; // eax
  const char *m_define_name; // [esp+4h] [ebp-Ch]

  if ( !this->m_define_name )
    return 0;
  vostok::buffer_string::assignf(
    &out_macro->definition,
    (const char *)&stru_95AF78.m_key_bindings[63].m_keyboard[1],
    *this->m_value);
  m_begin = out_macro->name.m_string.m_begin;
  if ( out_macro->name.m_string.m_begin != this->m_define_name )
  {
    m_define_name = this->m_define_name;
    out_macro->name.m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&out_macro->name.m_string, m_define_name);
  }
  return 1;
}
