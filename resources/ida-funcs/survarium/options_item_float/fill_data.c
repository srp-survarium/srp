void __thiscall survarium::options_item_float::fill_data(
        survarium::options_item_float *this,
        survarium::flash_value *val)
{
  double m_step; // st7
  vostok::console_commands::console_command *m_console_command; // edi
  survarium::flash_value *v4; // ecx
  survarium::flash_value *v5; // ecx
  float v6; // xmm0_4
  survarium::flash_value *v7; // ecx
  survarium::flash_value *v8; // ecx
  float v9; // xmm0_4
  survarium::flash_value *v10; // ecx
  float value; // [esp+0h] [ebp-2Ch]
  survarium::flash_value v12; // [esp+14h] [ebp-18h] BYREF

  m_step = this->m_step;
  *(_DWORD *)v12.body = 0;
  *(_DWORD *)&v12.body[4] = 0;
  m_console_command = this->m_console_command;
  value = m_step;
  survarium::flash_value::SetNumber((survarium::flash_value *)this, (int)&v12, value);
  survarium::flash_value::SetMember(v4, val, "snapInterval", &v12);
  if ( m_console_command )
    v6 = *((float *)&m_console_command[1].__vftable + 1);
  else
    v6 = 0.0;
  survarium::flash_value::SetNumber(v5, (int)&v12, v6);
  survarium::flash_value::SetMember(v7, val, "minimum", &v12);
  if ( m_console_command )
    v9 = *(float *)&m_console_command[1].m_next;
  else
    v9 = s_spot_max_distance;
  survarium::flash_value::SetNumber(v8, (int)&v12, v9);
  survarium::flash_value::SetMember(v10, val, "maximum", &v12);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v12);
}
