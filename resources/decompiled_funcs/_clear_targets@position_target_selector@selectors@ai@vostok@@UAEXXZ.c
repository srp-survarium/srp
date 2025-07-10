void __thiscall vostok::ai::selectors::position_target_selector::clear_targets(
        vostok::ai::selectors::position_target_selector *this)
{
  const vostok::ai::movement_target **i; // [esp+8h] [ebp-4h]

  for ( i = this->m_selected_positions.m_begin; i != this->m_selected_positions.m_end; ++i )
    ;
  this->m_selected_positions.m_end = this->m_selected_positions.m_begin;
}
