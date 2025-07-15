BOOL __usercall vostok::render::operator==@<eax>(
        const vostok::render::hw_buffer_pool_range *left@<ecx>,
        const vostok::render::hw_buffer_pool_range *right@<eax>)
{
  return left->owner == right->owner
      && left->begin_offset == right->begin_offset
      && left->end_offset == right->end_offset;
}


bool __usercall vostok::render::operator<@<al>(
        const vostok::render::binary_shader_key_type *left@<eax>,
        const vostok::render::binary_shader_key_type *right@<esi>)
{
  char *m_begin; // ebx

  m_begin = right->shader_name.m_string.m_begin;
  return vostok::detail::strcmp_s(left->shader_name.m_string.m_begin, m_begin) == (const char *)-1
      || vostok::detail::strcmp_s(left->shader_name.m_string.m_begin, m_begin) != (const char *)1
      && (vostok::render::union_base::operator<(&left->configuration, &right->configuration)
       || (*(_DWORD *)&left->configuration.0 == *(_DWORD *)&right->configuration.0
        && HIDWORD(left->configuration.configuration[0]) == HIDWORD(right->configuration.configuration[0])
        && LODWORD(left->configuration.configuration[1]) == LODWORD(right->configuration.configuration[1])
        && HIDWORD(left->configuration.configuration[1]) == HIDWORD(right->configuration.configuration[1])
        || vostok::render::union_base::operator<(&left->configuration, &right->configuration))
       && left->type < right->type);
}
