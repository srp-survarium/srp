char __thiscall vostok::ui::insert_char_action::execute(
        vostok::ui::insert_char_action *this,
        vostok::input::enum_keyboard_action action)
{
  vostok::ui::insert_char_action *v2; // esi
  char m_char_shift; // al
  bool v4; // zf
  int v5; // eax
  int v6; // eax
  const unsigned __int16 *pctype; // eax
  vostok::ui::ui_text_edit *v8; // ecx
  char string[128]; // [esp+4h] [ebp-84h] BYREF
  int v11; // [esp+84h] [ebp-4h]

  v2 = this;
  if ( (this->m_parent->m_shift_state.m_data.dummy & 0x30) != 0 )
    m_char_shift = this->m_char_shift;
  else
    m_char_shift = this->m_char;
  v4 = !this->m_b_translate;
  LOBYTE(v11) = m_char_shift;
  if ( !v4 && this->m_input_world )
  {
    if ( (_S5_6 & 1) == 0 )
    {
      _S5_6 |= 1u;
      current_locale = (localeinfo_struct *)_create_locale(0, (char *)uri);
    }
    v5 = (int)v2->m_input_world->get_keyboard(v2->m_input_world);
    if ( (*(unsigned __int8 (__thiscall **)(int, vostok::input::enum_keyboard, char *, int))(*(_DWORD *)v5 + 4))(
           v5,
           v2->m_key,
           string,
           128) )
    {
      if ( current_locale )
      {
        if ( current_locale->locinfo->mb_cur_max > 1 )
        {
          v6 = _isctype_l(string[0], 259, current_locale);
          goto LABEL_15;
        }
        pctype = current_locale->locinfo->pctype;
      }
      else
      {
        pctype = __pctype_func();
      }
      this = (vostok::ui::insert_char_action *)string[0];
      v6 = pctype[string[0]] & 0x103;
LABEL_15:
      if ( v6 )
      {
        _strlwr_s_l(string, 0x80u, current_locale);
        LOBYTE(v11) = string[0];
      }
    }
  }
  vostok::ui::ui_text_edit::delete_selection((vostok::ui::ui_text_edit *)this, (int)v2->m_parent);
  vostok::ui::ui_text_edit::insert_character(v8, (int)v2->m_parent, v11);
  return 1;
}
