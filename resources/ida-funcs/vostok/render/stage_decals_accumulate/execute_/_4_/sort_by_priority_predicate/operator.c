BOOL __userpurge vostok::render::stage_decals_accumulate::execute_::_4_::sort_by_priority_predicate::operator()@<eax>(
        const vostok::render::decal_instance *const b@<eax>,
        vostok::render::stage_decals_accumulate::execute::__l4::sort_by_priority_predicate *this,
        const vostok::render::decal_instance *const a)
{
  return b->m_properties.draw_priority > *(float *)&this[92];
}
