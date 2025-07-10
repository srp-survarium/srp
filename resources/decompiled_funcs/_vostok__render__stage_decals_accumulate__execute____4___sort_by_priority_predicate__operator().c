BOOL __usercall vostok::render::stage_decals_accumulate::execute_::_4_::sort_by_priority_predicate::operator()@<eax>(
        const vostok::render::decal_instance *const a@<ecx>,
        const vostok::render::decal_instance *const b@<eax>,
        vostok::render::stage_decals_accumulate::execute::__l4::sort_by_priority_predicate *this)
{
  return b->m_properties.draw_priority > a->m_properties.draw_priority;
}
