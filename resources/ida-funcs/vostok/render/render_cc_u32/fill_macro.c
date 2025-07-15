char __thiscall vostok::render::render_cc_u32::fill_macro(
        vostok::render::render_cc_u32 *this,
        vostok::render::shader_macro *out_macro)
{
  const char *m_define_name; // esi
  vostok::buffer_string *v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  char *v8; // edx
  char *m_begin; // eax
  unsigned int v11; // [esp-4h] [ebp-Ch]

  m_define_name = this->m_define_name;
  if ( !m_define_name )
    return 0;
  if ( vostok::strings::compare(m_define_name, "GLOBAL_PARTICLE_QUALITY") || (v5 = *this->m_value) == 0 || v5 == 2 )
  {
    if ( (vostok::strings::compare(m_define_name, "GLOBAL_LIGHTING_QUALITY") || (v6 = *this->m_value) == 0 || v6 == 3)
      && (vostok::strings::compare(m_define_name, "GLOBAL_SHADING_QUALITY") || (v7 = *this->m_value) == 0 || v7 == 3) )
    {
      v11 = *this->m_value;
    }
    else
    {
      v11 = 3;
    }
  }
  else
  {
    v11 = 0;
  }
  vostok::fs_new::path_string_impl::assignf(
    &out_macro->definition.m_begin,
    v4,
    (vostok::buffer_string *)"%d",
    (const char *)v11);
  v8 = (char *)this->m_define_name;
  m_begin = out_macro->name.m_string.m_begin;
  if ( out_macro->name.m_string.m_begin != v8 )
  {
    out_macro->name.m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&out_macro->name.m_string, v8);
  }
  return 1;
}
