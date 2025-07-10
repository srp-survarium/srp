void __thiscall survarium::options_item_int::revert(survarium::options_item_int *this)
{
  this->m_current_value = this->m_source_value;
  survarium::options_item_base::revert(this);
}
