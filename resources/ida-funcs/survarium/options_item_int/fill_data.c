void __thiscall survarium::options_item_int::fill_data(survarium::options_item_int *this, survarium::flash_value *val)
{
  survarium::options_tab *m_parent_tab; // edx
  const char **m_values; // ecx
  int v5; // ecx
  unsigned __int8 i; // [esp+25h] [ebp-431h]
  survarium::flash_value str_val; // [esp+26h] [ebp-430h] BYREF
  int v8; // [esp+3Eh] [ebp-418h] BYREF
  int v9; // [esp+42h] [ebp-414h]
  wchar_t *v10; // [esp+46h] [ebp-410h]
  wchar_t val_txt[512]; // [esp+56h] [ebp-400h] BYREF

  for ( i = 0; i < this->m_values_count; ++i )
  {
    m_parent_tab = this->m_parent_tab;
    m_values = this->m_values;
    *(_DWORD *)str_val.body = 0;
    *(_DWORD *)&str_val.body[4] = 0;
    survarium::text_translator::translate_text(&m_parent_tab->m_game->m_text_translator, m_values[i], val_txt);
    v5 = 0;
    v8 = 0;
    v9 = 7;
    v10 = val_txt;
    if ( (str_val.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)str_val.body + 8))(
        *(_DWORD *)str_val.body,
        &str_val,
        *(_DWORD *)&str_val.body[8]);
      v5 = v8;
      *(_DWORD *)str_val.body = 0;
    }
    *(_DWORD *)&str_val.body[4] = 7;
    *(_DWORD *)&str_val.body[8] = val_txt;
    if ( (v9 & 0x40) != 0 )
      (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v5 + 8))(v5, &v8, v10);
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, survarium::flash_value *))(**(_DWORD **)val->body + 52))(
      *(_DWORD *)val->body,
      *(_DWORD *)&val->body[8],
      i,
      &str_val);
    if ( (str_val.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)str_val.body + 8))(
        *(_DWORD *)str_val.body,
        &str_val,
        *(_DWORD *)&str_val.body[8]);
  }
}
