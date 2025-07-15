vostok::resources::query_result *__thiscall vostok::resources::queries_result::operator[](
        vostok::resources::queries_result *this,
        unsigned int index)
{
  return &this->m_queries[index];
}


vostok::resources::query_result *__usercall vostok::resources::queries_result::operator[]@<eax>(
        vostok::resources::queries_result *this@<ecx>,
        unsigned int index@<eax>)
{
  return &this->m_queries[index];
}
