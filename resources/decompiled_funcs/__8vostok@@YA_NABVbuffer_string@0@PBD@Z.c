BOOL __usercall vostok::operator==@<eax>(const vostok::buffer_string *s1@<ecx>, const char *s2@<eax>)
{
  return vostok::detail::strcmp_s(s1->m_begin, s2) == 0;
}
