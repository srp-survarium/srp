void __usercall vostok::render::res_texture::set_name(vostok::render::res_texture *this@<eax>, char *name@<edx>)
{
  vostok::fs_new::virtual_path_string *p_m_name; // eax
  char *m_begin; // ecx

  p_m_name = &this->m_name;
  m_begin = p_m_name->m_string.m_begin;
  if ( p_m_name->m_string.m_begin != name )
  {
    p_m_name->m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&p_m_name->m_string, name);
  }
}
