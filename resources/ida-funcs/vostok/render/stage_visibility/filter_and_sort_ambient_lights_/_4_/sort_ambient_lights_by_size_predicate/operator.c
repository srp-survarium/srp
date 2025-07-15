BOOL __userpurge vostok::render::stage_visibility::filter_and_sort_ambient_lights_::_4_::sort_ambient_lights_by_size_predicate::operator()@<eax>(
        const vostok::render::ambient_light *left@<eax>,
        vostok::render::stage_visibility::filter_and_sort_ambient_lights::__l4::sort_ambient_lights_by_size_predicate *this,
        const vostok::render::ambient_light *right)
{
  return left->m_properties.radius > *(float *)&this[96];
}
