char __thiscall vostok::render::render_cc_u32::fill_macro(
        vostok::render::render_cc_u32 *this,
        vostok::render::shader_macro *out_macro)
{
  const char *m_define_name; // esi
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  char *m_begin; // eax
  unsigned int v10; // [esp-4h] [ebp-Ch]
  const char *v11; // [esp-4h] [ebp-Ch]

  m_define_name = this->m_define_name;
  if ( !m_define_name )
    return 0;
  if ( !strcmp(m_define_name, "GLOBAL_SHADOWMAP_QUALITY") && (v4 = *this->m_value) != 0 && v4 != 3
    || !strcmp(m_define_name, "GLOBAL_LIGHTING_QUALITY") && (v5 = *this->m_value) != 0 && v5 != 3
    || !strcmp(m_define_name, "GLOBAL_SHADING_QUALITY") && (v6 = *this->m_value) != 0 && v6 != 3
    || !strcmp(m_define_name, "GLOBAL_POST_PROCESS_QUALITY") && (v7 = *this->m_value) != 0 && v7 != 3 )
  {
    v10 = 3;
  }
  else
  {
    v10 = *this->m_value;
  }
  vostok::buffer_string::assignf(&out_macro->definition, "%d", v10);
  m_begin = out_macro->name.m_string.m_begin;
  if ( out_macro->name.m_string.m_begin != this->m_define_name )
  {
    v11 = this->m_define_name;
    out_macro->name.m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&out_macro->name.m_string, v11);
  }
  return 1;
}
