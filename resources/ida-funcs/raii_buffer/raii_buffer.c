raii_buffer *__userpurge raii_buffer::raii_buffer@<eax>(
        raii_buffer *this@<ecx>,
        raii_buffer *result@<eax>,
        unsigned __int8 *const buffer,
        bool dynamic_allocation)
{
  result->m_buffer = (unsigned __int8 *const)this;
  result->m_dynamic_allocation = (char)buffer;
  return result;
}
