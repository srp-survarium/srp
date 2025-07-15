void __thiscall survarium::oxygen_tank::get_item_props(
        survarium::oxygen_tank *this,
        survarium::inventory_item_props *props)
{
  survarium::inventory_item::get_item_props(this, props);
  props->amount = this->m_amount_ms;
  props->cooldown = (unsigned __int64)((double)this->m_amount_ms / (double)this->m_max_amount * s_spot_max_distance);
}
