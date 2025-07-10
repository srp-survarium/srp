void __usercall stlp_std::swap<vostok::size_policy>(vostok::size_policy *__a@<ecx>, vostok::size_policy *__b@<eax>)
{
  unsigned int m_size; // edx

  m_size = __a->m_size;
  __a->m_size = __b->m_size;
  __b->m_size = m_size;
}
