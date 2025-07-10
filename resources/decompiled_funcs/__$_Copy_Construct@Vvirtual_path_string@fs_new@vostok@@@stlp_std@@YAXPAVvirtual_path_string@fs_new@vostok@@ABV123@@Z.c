void __usercall stlp_std::_Copy_Construct<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *__p@<esi>,
        const vostok::fs_new::virtual_path_string *__val@<eax>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // edi

  if ( __p )
  {
    m_begin = (unsigned __int8 *)__val->m_string.m_begin;
    v3 = __val->m_string.m_end - __val->m_string.m_begin;
    __p->m_string.m_max_end = &__p->m_separator;
    v4 = v3;
    __p->m_string.m_begin = __p->m_string.m_buffer;
    __p->m_string.m_end = __p->m_string.m_buffer;
    memcpy((unsigned __int8 *)__p->m_string.m_buffer, m_begin, v3);
    __p->m_string.m_end += v4;
    *__p->m_string.m_end = 0;
    __p->m_separator = 47;
  }
}
