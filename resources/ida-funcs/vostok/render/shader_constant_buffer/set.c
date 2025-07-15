void __userpurge vostok::render::shader_constant_buffer::set(
        vostok::render::shader_constant_buffer *this@<ecx>,
        vostok::render::shader_constant_buffer *a2@<edi>,
        vostok::render::shader_constant_slot *slot,
        void *ptr,
        unsigned int size)
{
  vostok::render::shader_constant_buffer::set_memory(
    a2,
    HIWORD(this->m_name.m_begin),
    (char *)slot,
    (unsigned __int8)LOWORD(this->m_reference_count));
}


void __userpurge vostok::render::shader_constant_buffer::set(
        vostok::render::shader_constant_buffer *this@<ecx>,
        vostok::render::shader_constant_buffer *a2@<edi>,
        vostok::render::shader_constant_slot *slot,
        void *ptr,
        unsigned int size,
        unsigned int array_size)
{
  vostok::render::shader_constant_buffer::set_memory(
    a2,
    HIWORD(this->m_name.m_begin),
    (char *)slot,
    (unsigned __int8)LOWORD(this->m_reference_count) * HIWORD(this->m_reference_count));
}
