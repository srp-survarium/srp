void __thiscall vostok::ai::selectors::position_target_selector::fill_targets_list(
        vostok::ai::selectors::position_target_selector *this)
{
  this->clear_targets(this);
  vostok::ai::brain_unit::get_available_movement_targets(this->m_brain_unit, &this->m_selected_positions);
  stlp_std::sort<vostok::ai::movement_target const * *,vostok::ai::selectors::sort_by_distance_predicate>(
    this->m_selected_positions.m_begin,
    this->m_selected_positions.m_end,
    (vostok::ai::selectors::sort_by_distance_predicate)this->m_brain_unit);
}
