void __thiscall vostok::ai::planning::propositional_planner::propositional_planner(
        vostok::ai::planning::propositional_planner *this)
{
  vostok::ai::planning::propositional_planner_base::propositional_planner_base(
    &this->vostok::ai::planning::propositional_planner_base,
    this);
  this->__vftable = (vostok::ai::planning::propositional_planner_vtbl *)&vostok::ai::planning::propositional_planner::`vftable';
  this->m_current_state.m_properties._M_impl._M_start = 0;
  this->m_current_state.m_properties._M_impl._M_finish = 0;
  this->m_current_state.m_properties._M_impl._M_end_of_storage._M_data = 0;
  this->m_current_state.m_hash = 0;
  this->m_target_state.m_properties._M_impl._M_start = 0;
  this->m_target_state.m_properties._M_impl._M_finish = 0;
  this->m_target_state.m_properties._M_impl._M_end_of_storage._M_data = 0;
  this->m_target_state.m_hash = 0;
  this->m_target_state_offsets._M_impl._M_start = 0;
  this->m_target_state_offsets._M_impl._M_finish = 0;
  this->m_target_state_offsets._M_impl._M_end_of_storage._M_data = 0;
  vostok::fixed_string<32>::fixed_string<32>(&this->m_current_id);
  this->m_failed = 0;
  this->m_forward_search = 0;
}
