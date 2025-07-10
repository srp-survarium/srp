void __userpurge vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this@<esi>,
        const char *p0@<edi>,
        const char *p1)
{
  unsigned int v3; // eax

  `vector constructor iterator'(
    (char *)this,
    8u,
    6,
    (void *(__thiscall *)(void *))vostok::render::lod_render_info::lod_render_info);
  this->m_count = 2;
  if ( p0 )
    v3 = strlen(p0);
  else
    v3 = 0;
  this->m_strings[0].first = p0;
  this->m_strings[0].second = v3;
  if ( p1 )
  {
    this->m_strings[1].second = strlen(p1);
    this->m_strings[1].first = p1;
  }
  else
  {
    this->m_strings[1].first = 0;
    this->m_strings[1].second = 0;
  }
}
