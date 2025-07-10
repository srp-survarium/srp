bool __usercall vostok::render::scene::process_streaming_::_3_::remove_requested_texture_predicate::operator()@<al>(
        const vostok::render::requested_streamable_texture *req@<eax>,
        vostok::render::scene::process_streaming::__l3::remove_requested_texture_predicate *this)
{
  vostok::render::res_texture *m_object; // eax

  m_object = req->texture.m_object;
  return m_object && m_object->m_reference_count == 1;
}
