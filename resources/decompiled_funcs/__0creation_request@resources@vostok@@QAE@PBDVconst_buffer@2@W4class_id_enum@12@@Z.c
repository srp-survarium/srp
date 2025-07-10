void __userpurge vostok::resources::creation_request::creation_request(
        vostok::resources::creation_request *this@<ecx>,
        vostok::const_buffer *a2@<eax>,
        const char *name,
        vostok::const_buffer data,
        vostok::resources::class_id_enum id)
{
  a2->m_data = (const char *)this;
  a2->m_size = (unsigned int)name;
  a2[1] = data;
}
