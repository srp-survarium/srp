void __thiscall survarium::options_item_float::revert(survarium::options_item_float *this)
{
  this->m_current_value = this->m_source_value;
  survarium::options_item_base::revert(this);
}
