BOOL __cdecl vostok::render::res_const_table_predicates::sort(
        const vostok::render::shader_constant *c1,
        const vostok::render::shader_constant *c2)
{
  return c1->m_host->m_name.m_pointer.m_object < c2->m_host->m_name.m_pointer.m_object;
}
