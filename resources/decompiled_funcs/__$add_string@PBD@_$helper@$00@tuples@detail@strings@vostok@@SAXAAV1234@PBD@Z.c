void __usercall vostok::strings::detail::tuples::helper<1>::add_string<char const *>(
        vostok::strings::detail::tuples *self@<edi>,
        const char *p@<edx>)
{
  if ( p )
  {
    self->m_strings[1].first = p;
    self->m_strings[1].second = strlen(p);
  }
  else
  {
    self->m_strings[1].first = 0;
    self->m_strings[1].second = 0;
  }
}
