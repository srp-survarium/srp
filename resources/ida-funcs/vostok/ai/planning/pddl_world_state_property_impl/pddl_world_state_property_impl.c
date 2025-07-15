void __usercall vostok::ai::planning::pddl_world_state_property_impl::pddl_world_state_property_impl(
        vostok::ai::planning::pddl_world_state_property_impl *this@<eax>,
        const vostok::ai::planning::pddl_world_state_property_impl *__that@<edi>)
{
  vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
    &this->m_indices,
    (unsigned int *)this->m_indices.m_buffer,
    &__that->m_indices);
  this->m_predicate = __that->m_predicate;
  this->m_result = __that->m_result;
}
