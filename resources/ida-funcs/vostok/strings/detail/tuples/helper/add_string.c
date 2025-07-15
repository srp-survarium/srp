void __usercall vostok::strings::detail::tuples::helper<1>::add_string<char const *>(
        vostok::strings::detail::tuples *self@<edi>,
        const char *p@<esi>)
{
  unsigned int v2; // eax

  if ( p )
    v2 = strlen(p);
  else
    v2 = 0;
  self->m_strings[1].first = p;
  self->m_strings[1].second = v2;
}


void __usercall vostok::strings::detail::tuples::helper<2>::add_string<char const *>(
        vostok::strings::detail::tuples *self@<edi>,
        const char *p@<esi>)
{
  unsigned int v2; // eax

  if ( p )
    v2 = strlen(p);
  else
    v2 = 0;
  self->m_strings[2].first = p;
  self->m_strings[2].second = v2;
}


void __usercall vostok::strings::detail::tuples::helper<0>::add_string<char const *>(
        vostok::strings::detail::tuples *self@<edi>,
        const char *p@<esi>)
{
  unsigned int v2; // eax

  if ( p )
    v2 = strlen(p);
  else
    v2 = 0;
  self->m_strings[0].first = p;
  self->m_strings[0].second = v2;
}
