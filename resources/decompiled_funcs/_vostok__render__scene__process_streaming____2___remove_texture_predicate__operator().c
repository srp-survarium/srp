bool __usercall vostok::render::scene::process_streaming_::_2_::remove_texture_predicate::operator()@<al>(
        const vostok::render::streamable_texture_info *info@<eax>,
        vostok::render::scene::process_streaming::__l2::remove_texture_predicate *this)
{
  vostok::render::res_texture *m_object; // eax

  m_object = info->texture.m_object;
  return m_object->m_loaded && m_object->m_reference_count == 1;
}
