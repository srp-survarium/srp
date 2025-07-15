void __thiscall survarium::options_item_bool::fill_value(
        survarium::options_item_bool *this,
        survarium::flash_value *val)
{
  survarium::flash_value::SetBoolean((survarium::flash_value *)this, (int)val, this->m_current_value);
}
