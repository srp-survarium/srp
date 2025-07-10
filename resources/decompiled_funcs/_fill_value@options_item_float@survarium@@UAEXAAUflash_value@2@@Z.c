void __thiscall survarium::options_item_float::fill_value(
        survarium::options_item_float *this,
        survarium::flash_value *val)
{
  float m_current_value; // [esp+8h] [ebp-4h]

  m_current_value = this->m_current_value;
  if ( (*(_DWORD *)&val->body[4] & 0x40) != 0 )
  {
    (*(void (__stdcall **)(survarium::flash_value *, _DWORD))(**(_DWORD **)val->body + 8))(
      val,
      *(_DWORD *)&val->body[8]);
    *(_DWORD *)val->body = 0;
  }
  *(_DWORD *)&val->body[4] = 5;
  *(double *)&val->body[8] = m_current_value;
}
