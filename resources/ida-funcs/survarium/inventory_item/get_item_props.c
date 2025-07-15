void __thiscall survarium::inventory_item::get_item_props(
        survarium::inventory_item *this,
        survarium::inventory_item_props *props)
{
  props->dict_id = this->m_dict_id;
  props->amount = this->m_amount;
}
