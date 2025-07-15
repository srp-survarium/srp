BOOL __usercall vostok::render::union_base::operator<@<eax>(
        const vostok::render::union_base::shader_configuration *left@<ecx>,
        const vostok::render::union_base::shader_configuration *right@<eax>)
{
  return left->configuration[0] < right->configuration[0]
      || *(_DWORD *)&left->0 == *(_DWORD *)&right->0
      && HIDWORD(left->configuration[0]) == HIDWORD(right->configuration[0])
      && left->configuration[1] < right->configuration[1];
}
