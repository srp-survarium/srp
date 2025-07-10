char __thiscall vostok::ui::insert_char_action::execute(
        vostok::ui::insert_char_action *this,
        vostok::input::enum_keyboard_action action)
{
  vostok::ui::insert_char_action *v2; // edi
  int v3; // eax
  int v4; // eax
  unsigned __int16 v5; // ax
  vostok::ui::ui_text_edit *v6; // ecx
  char c; // [esp+Ch] [ebp-84h]
  char buff[128]; // [esp+10h] [ebp-80h] BYREF

  v2 = this;
  if ( (this->m_parent->m_shift_state.m_data.dummy & 0x30) != 0 )
  {
    c = this->m_char_shift;
  }
  else
  {
    LOBYTE(this) = this->m_char;
    c = v2->m_char;
  }
  if ( v2->m_b_translate && v2->m_input_world )
  {
    if ( (_S3_8 & 1) == 0 )
    {
      _S3_8 |= 1u;
      current_locale = (localeinfo_struct *)_create_locale(0, (char *)&buf);
    }
    v3 = (int)v2->m_input_world->get_keyboard(v2->m_input_world);
    if ( (*(unsigned __int8 (__thiscall **)(int, vostok::input::enum_keyboard, char *, int))(*(_DWORD *)v3 + 4))(
           v3,
           v2->m_key,
           buff,
           128) )
    {
      this = (vostok::ui::insert_char_action *)current_locale;
      if ( current_locale )
      {
        if ( current_locale->locinfo->mb_cur_max > 1 )
        {
          v4 = _isctype_l(buff[0], 259, current_locale);
          this = (vostok::ui::insert_char_action *)current_locale;
          goto LABEL_15;
        }
        v5 = current_locale->locinfo->pctype[buff[0]];
      }
      else
      {
        v5 = __pctype_func()[buff[0]];
        this = (vostok::ui::insert_char_action *)current_locale;
      }
      v4 = v5 & 0x103;
LABEL_15:
      if ( v4 )
      {
        _strlwr_s_l(buff, 0x80u, (localeinfo_struct *)this);
        c = buff[0];
      }
    }
  }
  vostok::ui::ui_text_edit::delete_selection((vostok::ui::ui_text_edit *)this);
  vostok::ui::ui_text_edit::insert_character(v6, c);
  return 1;
}
