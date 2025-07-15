bool __usercall vostok::render::scene::process_streaming_::_6_::remove_requested_texture_predicate::operator()@<al>(
        const vostok::render::requested_streamable_texture *req@<eax>,
        vostok::render::scene::process_streaming::__l6::remove_requested_texture_predicate *this)
{
  vostok::render::res_texture *m_object; // eax

  m_object = req->texture.m_object;
  return m_object && (m_object->m_reference_count == 1 || !m_object->m_streamed || m_object->m_max_uses_mips < 5);
}
