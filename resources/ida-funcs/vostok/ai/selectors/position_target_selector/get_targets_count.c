int __thiscall vostok::ai::selectors::position_target_selector::get_targets_count(
        vostok::ai::selectors::position_target_selector *this)
{
  return this->m_selected_positions.m_end - this->m_selected_positions.m_begin;
}
