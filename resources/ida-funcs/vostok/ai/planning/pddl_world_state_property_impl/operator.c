vostok::ai::planning::pddl_world_state_property_impl *__usercall vostok::ai::planning::pddl_world_state_property_impl::operator=@<eax>(
        vostok::ai::planning::pddl_world_state_property_impl *this@<edi>,
        const vostok::ai::planning::pddl_world_state_property_impl *__that@<esi>)
{
  vostok::render::render_surface_instance **m_end; // [esp+0h] [ebp-4h] BYREF

  m_end = (vostok::render::render_surface_instance **)__that->m_indices.m_end;
  vostok::buffer_vector<vostok::render::render_surface_instance *>::assign<vostok::render::render_surface_instance * *>(
    (vostok::render::render_surface_instance **)__that->m_indices.m_begin,
    &m_end,
    (vostok::buffer_vector<vostok::render::render_surface_instance *> *)this);
  this->m_predicate = __that->m_predicate;
  this->m_result = __that->m_result;
  return this;
}
