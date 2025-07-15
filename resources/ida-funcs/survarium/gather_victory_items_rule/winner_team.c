int __thiscall survarium::gather_victory_items_rule::winner_team(survarium::gather_victory_items_rule *this)
{
  unsigned __int8 v1; // al
  unsigned __int8 v2; // cl

  v1 = this->m_team_points[0];
  v2 = this->m_team_points[1];
  if ( v1 <= v2 )
    return (v1 >= v2) + 1;
  else
    return 0;
}
