void __thiscall survarium::options_item_int::fill_value(survarium::options_item_int *this, survarium::flash_value *val)
{
  survarium::flash_value::SetUInt((survarium::flash_value *)this, (int)val, this->m_current_value);
}
