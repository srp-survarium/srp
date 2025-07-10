BOOL __usercall vostok::render::stage_lights::execute_::_15_::sort_by_size_predicate::operator()@<eax>(
        const vostok::render::environment_probe *left@<ecx>,
        const vostok::render::environment_probe *right@<eax>,
        vostok::render::stage_lights::execute::__l15::sort_by_size_predicate *this)
{
  return right->m_properties.radius > left->m_properties.radius;
}
