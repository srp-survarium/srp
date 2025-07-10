BOOL __usercall vostok::render::stage_ambient_lighting::execute_::_5_::sort_by_size_predicate::operator()@<eax>(
        const vostok::render::environment_probe *left@<eax>,
        const vostok::render::environment_probe *right@<ecx>,
        vostok::render::stage_ambient_lighting::execute::__l5::sort_by_size_predicate *this)
{
  return left->m_properties.radius > right->m_properties.radius;
}
