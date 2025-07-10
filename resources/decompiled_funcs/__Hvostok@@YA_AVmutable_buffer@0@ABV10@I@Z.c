vostok::mutable_buffer *__cdecl vostok::operator+(
        vostok::mutable_buffer *result,
        const vostok::mutable_buffer *buffer,
        vostok::mutable_buffer *offs)
{
  unsigned int m_size; // edx
  vostok::mutable_buffer resulta; // [esp+4h] [ebp-8h] BYREF

  m_size = buffer->m_size;
  resulta.m_data = buffer->m_data;
  resulta.m_size = m_size;
  vostok::mutable_buffer::operator+=(offs, &resulta);
  *result = resulta;
  return result;
}
