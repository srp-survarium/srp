BOOL __usercall vostok::render::res_effect::push_texture_unique_::_2_::find_texture_predicate::operator()@<eax>(
        vostok::render::res_effect::push_texture_unique::__l2::find_texture_predicate *this@<eax>,
        const vostok::render::texture_named_instance *other@<edx>)
{
  return this->m_texture.m_object == other->texture;
}
