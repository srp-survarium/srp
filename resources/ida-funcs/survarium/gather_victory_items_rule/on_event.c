void __thiscall survarium::gather_victory_items_rule::on_event(
        survarium::gather_victory_items_rule *this,
        survarium::event_id_type event_id,
        _DWORD *event_args,
        unsigned int current_time_ms)
{
  unsigned __int8 *v4; // eax

  if ( event_id == gather_victory_item_event )
  {
    v4 = &this->m_team_points[*event_args];
    if ( event_args[1] )
      --*v4;
    else
      ++*v4;
    if ( this->m_team_points[0] == this->m_victory_items._M_impl._M_finish - this->m_victory_items._M_impl._M_start
      || this->m_team_points[1] == this->m_victory_items._M_impl._M_finish - this->m_victory_items._M_impl._M_start )
    {
      this->m_complete_time = current_time_ms;
    }
    else
    {
      this->m_complete_time = -1;
    }
  }
}
