void __usercall vostok::strings::detail::tuples::helper<2>::add_string<char const *>(
        vostok::strings::detail::tuples *self@<edi>,
        const char *p@<edx>)
{
  if ( p )
  {
    self->m_strings[2].first = p;
    self->m_strings[2].second = strlen(p);
  }
  else
  {
    self->m_strings[2].first = 0;
    self->m_strings[2].second = 0;
  }
}
