BOOL __cdecl vostok::render::sorted_vector_predicate(
        const vostok::render::shader_constant_host *first,
        const vostok::shared_string *second)
{
  return first->m_name.m_pointer.m_object < second->m_pointer.m_object;
}
