survarium::inventory_holder *__thiscall survarium::base_player::cast_to_inventory_holder(survarium::base_player *this)
{
  if ( this == (survarium::base_player *)272 )
    return 0;
  else
    return (survarium::inventory_holder *)&this[-1].m_temp_previous_position.elements[2];
}
