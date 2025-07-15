void __userpurge vostok::render::statistics_base::statistics_base(
        vostok::render::statistics_base *this@<esi>,
        vostok::render::statistics_group *group@<edi>,
        char *name)
{
  vostok::fixed_string<128> *p_m_name; // eax
  char *m_begin; // ecx

  p_m_name = &this->m_name;
  this->__vftable = (vostok::render::statistics_base_vtbl *)&vostok::render::statistics_base::`vftable';
  this->m_name.m_max_end = (char *)&this->m_next;
  this->m_name.m_begin = this->m_name.m_buffer;
  this->m_name.m_end = this->m_name.m_buffer;
  this->m_name.m_buffer[0] = 0;
  this->m_group = group;
  if ( group )
  {
    m_begin = p_m_name->m_begin;
    if ( p_m_name->m_begin != name )
    {
      this->m_name.m_end = m_begin;
      *m_begin = 0;
      vostok::buffer_string::operator+=(p_m_name, name);
    }
    this->m_next = group->first_statistics;
    group->first_statistics = this;
  }
}
