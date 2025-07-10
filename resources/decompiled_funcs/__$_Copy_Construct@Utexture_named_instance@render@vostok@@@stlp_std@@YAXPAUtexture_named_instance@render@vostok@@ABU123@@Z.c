void __usercall stlp_std::_Copy_Construct<vostok::render::texture_named_instance>(
        vostok::render::texture_named_instance *__p@<ecx>,
        const vostok::render::texture_named_instance *__val@<eax>)
{
  char *m_begin; // edx
  char *v4; // ecx
  char *v5; // edi

  if ( __p )
  {
    __p->texture = __val->texture;
    m_begin = __val->path.m_begin;
    v4 = (char *)(__val->path.m_end - m_begin);
    __p->path.m_max_end = (char *)&__p[1];
    v5 = v4;
    __p->path.m_begin = __p->path.m_buffer;
    __p->path.m_end = __p->path.m_buffer;
    memcpy((unsigned __int8 *)__p->path.m_buffer, (unsigned __int8 *)m_begin, (unsigned int)v4);
    __p->path.m_end += (unsigned int)v5;
    *__p->path.m_end = 0;
  }
}
