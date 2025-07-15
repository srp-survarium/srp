BOOL __cdecl vostok::render::res_const_table_predicates::sort(
        const vostok::render::shader_constant *a1,
        const vostok::render::shader_constant *a2)
{
  return a1->m_host->m_name.m_pointer.m_object < a2->m_host->m_name.m_pointer.m_object;
}
