char __thiscall survarium::swf_input_translator::process_keyboard(
        survarium::swf_input_translator *this,
        survarium::swf_input_translator *input_world,
        vostok::input::enum_keyboard key,
        survarium::flash_movie::keyb_btn_action action,
        survarium::flash_movie *movie,
        unsigned int time_current_ms)
{
  int v6; // esi
  survarium::dik_to_swf_bind *bind; // edi
  char v9; // al
  int v10; // edx
  vostok::input::enum_keyboard i; // ebx
  survarium::dik_to_swf_bind *v12; // edi
  char v13; // al
  int v14; // edx
  wchar_t c; // [esp+14h] [ebp-4h] BYREF

  v6 = (*(int (__thiscall **)(survarium::swf_input_translator *))(*(_DWORD *)&this->char_map._M_t._M_header._M_data._M_color
                                                                + 36))(this);
  if ( action == kb_key_down || action == kb_key_up )
  {
    bind = survarium::swf_input_translator::get_bind(input_world, key);
    if ( !bind )
      return 0;
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 16))(v6);
    survarium::flash_movie::HandleKeyboard(v9, v10, movie, action, bind->scan);
    if ( bind->is_character && action == kb_key_down )
    {
      if ( !(*(unsigned __int8 (__thiscall **)(int, vostok::input::enum_keyboard, wchar_t *))(*(_DWORD *)v6 + 8))(
              v6,
              key,
              &c) )
        return 0;
      survarium::flash_movie::HandleChar(c, movie);
    }
    movie->m_last_keyb_hold_time = time_current_ms + 500;
  }
  if ( action == kb_key_hold && movie->m_last_keyb_hold_time + 100 < time_current_ms )
  {
    for ( i = 0; (unsigned int)i < 0x100; ++i )
    {
      if ( (**(unsigned __int8 (__thiscall ***)(int, vostok::input::enum_keyboard))v6)(v6, i) )
      {
        v12 = survarium::swf_input_translator::get_bind(input_world, i);
        if ( v12 )
        {
          if ( i == key_back || i == key_delete || i == key_left || i == key_right || i == key_up || i == key_down )
          {
            v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 16))(v6);
            survarium::flash_movie::HandleKeyboard(v13, v14, movie, kb_key_down, v12->scan);
          }
          if ( v12->is_character )
          {
            if ( (*(unsigned __int8 (__thiscall **)(int, vostok::input::enum_keyboard, wchar_t *))(*(_DWORD *)v6 + 8))(
                   v6,
                   key,
                   &c) )
            {
              survarium::flash_movie::HandleChar(c, movie);
            }
          }
        }
      }
    }
    movie->m_last_keyb_hold_time = time_current_ms;
  }
  return 1;
}
