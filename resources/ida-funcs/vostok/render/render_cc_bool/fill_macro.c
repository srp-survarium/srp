char __thiscall vostok::render::render_cc_bool::fill_macro(
        vostok::render::render_cc_bool *this,
        vostok::render::shader_macro *out_macro)
{
  char *v3; // edx
  char *m_begin; // ecx
  char *m_define_name; // edx
  char *v6; // eax

  if ( !this->m_define_name )
    return 0;
  v3 = "1";
  if ( !*this->m_value )
    v3 = "0";
  m_begin = out_macro->definition.m_begin;
  if ( m_begin != v3 )
  {
    out_macro->definition.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&out_macro->definition, v3);
  }
  m_define_name = (char *)this->m_define_name;
  v6 = out_macro->name.m_string.m_begin;
  if ( out_macro->name.m_string.m_begin != m_define_name )
  {
    out_macro->name.m_string.m_end = v6;
    *v6 = 0;
    vostok::buffer_string::operator+=(&out_macro->name.m_string, m_define_name);
  }
  return 1;
}
