void __usercall stlp_std::_Copy_Construct<vostok::render::material_effects_entry>(
        vostok::render::material_effects_entry *__p@<esi>,
        const vostok::render::material_effects_entry *__val@<eax>)
{
  char *m_begin; // edx
  char *v3; // ecx
  char *v4; // edi

  if ( __p )
  {
    __p->m_material_effects_instance_ptr = __val->m_material_effects_instance_ptr;
    m_begin = __val->m_material_name.m_string.m_begin;
    v3 = (char *)(__val->m_material_name.m_string.m_end - m_begin);
    __p->m_material_name.m_string.m_max_end = &__p->m_material_name.m_separator;
    v4 = v3;
    __p->m_material_name.m_string.m_begin = __p->m_material_name.m_string.m_buffer;
    __p->m_material_name.m_string.m_end = __p->m_material_name.m_string.m_buffer;
    memcpy((unsigned __int8 *)__p->m_material_name.m_string.m_buffer, (unsigned __int8 *)m_begin, (unsigned int)v3);
    __p->m_material_name.m_string.m_end += (unsigned int)v4;
    *__p->m_material_name.m_string.m_end = 0;
    __p->m_material_name.m_separator = 47;
  }
}
