void __thiscall vostok::ai::planning::pddl_world_state_property_impl::pddl_world_state_property_impl(
        vostok::ai::planning::pddl_world_state_property_impl *this,
        const vostok::ai::planning::pddl_world_state_property_impl *__that)
{
  unsigned int *end; // [esp+18h] [ebp-8h] BYREF
  unsigned int *m_buffer; // [esp+1Ch] [ebp-4h]

  m_buffer = (unsigned int *)this->m_indices.m_buffer;
  this->m_indices.m_begin = (unsigned int *)this->m_indices.m_buffer;
  this->m_indices.m_end = m_buffer;
  end = __that->m_indices.m_end;
  vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
    &this->m_indices,
    __that->m_indices.m_begin,
    (const unsigned int *const *)&end);
  this->m_predicate = __that->m_predicate;
  this->m_result = __that->m_result;
}
