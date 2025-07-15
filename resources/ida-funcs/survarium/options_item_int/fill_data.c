void __thiscall survarium::options_item_int::fill_data(survarium::options_item_int *this, survarium::flash_value *val)
{
  survarium::flash_value *v3; // ecx
  unsigned __int8 i; // [esp+13h] [ebp-21Dh]
  survarium::flash_value v5; // [esp+18h] [ebp-218h] BYREF
  char value[512]; // [esp+30h] [ebp-200h] BYREF

  for ( i = 0; i < this->m_values_count; ++i )
  {
    *(_DWORD *)v5.body = 0;
    *(_DWORD *)&v5.body[4] = 0;
    survarium::text_translator::translate_text(
      (survarium::text_translator *)this->m_values,
      (int)&this->m_parent_tab->m_game->m_text_translator,
      (char *)this->m_values[i],
      value);
    survarium::flash_value::SetString(&v5, value);
    survarium::flash_value::SetElement(v3, val, i, &v5);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v5);
  }
}
