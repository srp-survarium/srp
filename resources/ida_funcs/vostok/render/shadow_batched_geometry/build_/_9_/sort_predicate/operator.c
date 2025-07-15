BOOL __usercall vostok::render::shadow_batched_geometry::build_::_9_::sort_predicate::operator()@<eax>(
        const vostok::render::shadow_batched_geometry::build::__l2::surface_set *left@<eax>,
        const vostok::render::shadow_batched_geometry::build::__l2::surface_set *right@<edx>,
        vostok::render::shadow_batched_geometry::build::__l9::sort_predicate *this)
{
  return left->surface->m_materail_effects_instance.m_object < right->surface->m_materail_effects_instance.m_object;
}
