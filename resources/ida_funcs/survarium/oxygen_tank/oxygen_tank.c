void __thiscall survarium::oxygen_tank::oxygen_tank(survarium::oxygen_tank *this)
{
  survarium::inventory_item::inventory_item(this, use_silent);
  this->__vftable = (survarium::oxygen_tank_vtbl *)&survarium::oxygen_tank::`vftable';
  this->m_active = 0;
  this->m_amount_ms = 0;
  this->m_max_amount = 0;
  this->m_influences = 0;
}
