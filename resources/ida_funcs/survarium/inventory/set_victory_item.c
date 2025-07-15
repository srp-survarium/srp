void __thiscall survarium::inventory::set_victory_item(survarium::inventory *this, survarium::victory_item_core *item)
{
  if ( item )
  {
    this->m_victory_item = item;
    this->m_victory_item->m_carrier_id = this->m_holder->cast_to_base_player(this->m_holder)->id;
  }
  else
  {
    this->m_victory_item->m_carrier_id = -1;
    this->m_victory_item = 0;
  }
}
