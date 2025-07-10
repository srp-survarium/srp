char __thiscall vostok::ai::planning::propositional_planner::update(
        vostok::ai::planning::propositional_planner *this,
        vostok::ai::planning::search *search_service,
        vostok::fixed_string<16> *id)
{
  bool v4; // [esp+4h] [ebp-BCh]
  bool v5; // [esp+8h] [ebp-B8h]

  if ( vostok::ai::planning::propositional_planner::actual(this) )
    return 1;
  this->m_actual = 1;
  vostok::fixed_string<16>::operator=(id, &this->m_current_id);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::clear(&this->m_current_state.m_properties._M_impl);
  this->m_current_state.m_hash = 0;
  if ( this->m_forward_search )
  {
    v5 = vostok::ai::planning::search_forward::search(&search_service->m_search_forward, this, &search_service->m_plan)
      && search_service->m_plan._M_impl._M_start != search_service->m_plan._M_impl._M_finish;
    this->m_failed = !v5;
  }
  else
  {
    v4 = vostok::ai::planning::search_backward::search(
           &search_service->m_search_backward,
           this,
           &search_service->m_plan)
      && search_service->m_plan._M_impl._M_start != search_service->m_plan._M_impl._M_finish;
    this->m_failed = !v4;
  }
  return 0;
}
