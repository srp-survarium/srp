BOOL __usercall vostok::render::scene::gather_streamable_textures_::_2_::find_texture_predicate::operator()@<eax>(
        vostok::render::scene::gather_streamable_textures::__l2::find_texture_predicate *this@<eax>,
        const vostok::render::streamable_texture_info *other@<edx>)
{
  return this->m_texture == other->texture.m_object;
}
