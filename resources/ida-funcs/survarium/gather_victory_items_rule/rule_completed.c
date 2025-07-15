BOOL __thiscall survarium::gather_victory_items_rule::rule_completed(
        survarium::gather_victory_items_rule *this,
        unsigned int time_ms)
{
  unsigned int m_complete_time; // eax

  m_complete_time = this->m_complete_time;
  return m_complete_time != -1 && m_complete_time <= time_ms;
}
