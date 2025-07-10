void __userpurge vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this@<esi>,
        const char *p0@<edi>,
        const char *p1,
        char *p2)
{
  unsigned int v4; // eax
  unsigned int v5; // eax

  `vector constructor iterator'(
    (char *)this,
    8u,
    6,
    (void *(__thiscall *)(void *))vostok::render::lod_render_info::lod_render_info);
  this->m_count = 3;
  if ( p0 )
    v4 = strlen(p0);
  else
    v4 = 0;
  this->m_strings[0].first = p0;
  this->m_strings[0].second = v4;
  if ( p1 )
    v5 = strlen(p1);
  else
    v5 = 0;
  this->m_strings[1].first = p1;
  this->m_strings[1].second = v5;
  if ( p2 )
  {
    this->m_strings[2].second = strlen(p2);
    this->m_strings[2].first = p2;
  }
  else
  {
    this->m_strings[2].first = 0;
    this->m_strings[2].second = 0;
  }
}
