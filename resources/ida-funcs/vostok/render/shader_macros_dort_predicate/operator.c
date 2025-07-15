bool __usercall vostok::render::shader_macros_dort_predicate::operator()@<al>(
        const char *first@<eax>,
        const char *second@<ecx>,
        vostok::render::shader_macros_dort_predicate *this)
{
  return strcmp(first, second) < 0;
}
