vostok::memory::reader *__userpurge vostok::memory::chunk_reader::open_reader@<eax>(
        vostok::memory::chunk_reader *this@<ecx>,
        vostok::memory::chunk_reader *a2@<edi>,
        const unsigned __int8 **a3@<esi>,
        vostok::memory::chunk_reader::chunk_type *result,
        unsigned int chunk_id)
{
  const unsigned __int8 *v5; // eax
  const unsigned __int8 *m_pointer; // ecx

  v5 = (const unsigned __int8 *)vostok::memory::chunk_reader::chunk_size(this, a2, result, (unsigned int *)&result);
  m_pointer = a2->m_reader.m_pointer;
  a3[2] = v5;
  *a3 = m_pointer;
  a3[1] = m_pointer;
  return (vostok::memory::reader *)a3;
}
