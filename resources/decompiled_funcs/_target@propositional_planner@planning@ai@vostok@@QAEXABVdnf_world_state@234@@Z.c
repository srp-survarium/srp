void __thiscall vostok::ai::planning::propositional_planner::target(
        vostok::ai::planning::propositional_planner *this,
        const vostok::ai::planning::dnf_world_state *target)
{
  bool v2; // [esp+0h] [ebp-3Ch]

  v2 = 0;
  if ( this->m_actual
    && this->m_target_state.m_hash == target->m_hash
    && stlp_std::operator==<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(
         &this->m_target_state.m_properties,
         &target->m_properties) )
  {
    v2 = 1;
  }
  this->m_actual = v2;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::operator=(
    &this->m_target_state.m_properties._M_impl,
    &target->m_properties._M_impl);
  this->m_target_state.m_hash = target->m_hash;
}
