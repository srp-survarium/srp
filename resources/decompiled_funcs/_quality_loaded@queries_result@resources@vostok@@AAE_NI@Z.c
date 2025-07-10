BOOL __usercall vostok::resources::queries_result::quality_loaded@<eax>(
        vostok::resources::queries_result *this@<edx>,
        unsigned int quality@<esi>)
{
  int v2; // eax
  unsigned int *i; // ecx
  int v4; // eax
  bool v5; // zf
  vostok::resources::query_result *v6; // eax

  v2 = 0;
  for ( i = &this->m_queries[0].m_quality_index; *i != quality; i += 180 )
    ++v2;
  v4 = v2;
  v5 = this->m_queries[v4].m_error_type == error_type_unset;
  v6 = &this->m_queries[v4];
  return v5 && v6->m_create_resource_result != result_error;
}
