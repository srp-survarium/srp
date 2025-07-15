void __thiscall survarium::options_item_float::fill_value(
        survarium::options_item_float *this,
        survarium::flash_value *val)
{
  survarium::flash_value::SetNumber((survarium::flash_value *)this, (int)val, this->m_current_value);
}
