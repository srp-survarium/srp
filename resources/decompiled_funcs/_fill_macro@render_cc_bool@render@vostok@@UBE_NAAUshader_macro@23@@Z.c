char __thiscall vostok::render::render_cc_bool::fill_macro(
        vostok::render::render_cc_bool *this,
        vostok::render::shader_macro *out_macro)
{
  survarium::keyboard_key_descr **m_keyboard; // edx
  char *m_begin; // eax
  char *v5; // eax
  const char *m_define_name; // [esp-8h] [ebp-Ch]

  if ( !this->m_define_name )
    return 0;
  m_keyboard = stru_95AF78.m_key_bindings[5].m_keyboard;
  if ( !*this->m_value )
    m_keyboard = &stru_95AF78.m_key_bindings[6].m_keyboard[1];
  m_begin = out_macro->definition.m_begin;
  if ( m_begin != (char *)m_keyboard )
  {
    out_macro->definition.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&out_macro->definition, (const char *)m_keyboard);
  }
  v5 = out_macro->name.m_string.m_begin;
  if ( out_macro->name.m_string.m_begin != this->m_define_name )
  {
    m_define_name = this->m_define_name;
    out_macro->name.m_string.m_end = v5;
    *v5 = 0;
    vostok::buffer_string::operator+=(&out_macro->name.m_string, m_define_name);
  }
  return 1;
}
