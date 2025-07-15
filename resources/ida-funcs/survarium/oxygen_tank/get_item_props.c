bool __thiscall survarium::oxygen_tank::get_item_props(
        survarium::oxygen_tank *this,
        survarium::inventory_item_props *props)
{
  survarium::inventory_item::get_item_props(this, props);
  props->m_amount_ms = this->m_amount_ms;
  props->cooldown = (int)((double)this->m_amount_ms / (double)this->m_max_amount * 100.0);
  return this->m_active;
}
