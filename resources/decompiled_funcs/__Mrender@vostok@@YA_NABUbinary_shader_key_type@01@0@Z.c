BOOL __usercall vostok::render::operator<@<eax>(
        const vostok::render::binary_shader_key_type *left@<edi>,
        const vostok::render::binary_shader_key_type *right@<esi>)
{
  return vostok::operator<(&left->shader_name.m_string, &right->shader_name.m_string)
      || vostok::fs_new::path_string_impl::operator==(&left->shader_name, &right->shader_name)
      && (vostok::render::union_base::operator<(&left->configuration, &right->configuration)
       || *(_DWORD *)&left->configuration.0 == *(_DWORD *)&right->configuration.0
       && HIDWORD(left->configuration.configuration[0]) == HIDWORD(right->configuration.configuration[0])
       && LODWORD(left->configuration.configuration[1]) == LODWORD(right->configuration.configuration[1])
       && HIDWORD(left->configuration.configuration[1]) == HIDWORD(right->configuration.configuration[1])
       && left->type < right->type);
}
