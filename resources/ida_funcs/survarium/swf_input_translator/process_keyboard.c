char __userpurge survarium::swf_input_translator::process_keyboard@<al>(
        vostok::input::enum_keyboard key@<eax>,
        survarium::swf_input_translator *a2@<ecx>,
        survarium::swf_input_translator *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard_action action,
        survarium::flash_movie *movie,
        unsigned int time_current_ms)
{
  stlp_std::less<enum vostok::input::enum_keyboard> *bind; // eax
  survarium::dik_to_swf_bind *v8; // esi
  vostok::input::world *v10; // edi
  const vostok::input::keyboard *v11; // eax
  const vostok::input::keyboard *v12; // eax
  wchar_t v13; // ax
  const vostok::input::keyboard *v14; // edi
  vostok::input::enum_keyboard i; // ebx
  survarium::swf_input_translator *v16; // ecx
  stlp_std::less<enum vostok::input::enum_keyboard> *v17; // eax
  survarium::dik_to_swf_bind *v18; // esi
  Scaleform::GFx::Movie *m_movie; // ecx
  wchar_t v20; // ax
  bool v21; // [esp+0h] [ebp-30h]
  survarium::swf_input_translator *is_shift_now; // [esp+10h] [ebp-20h]
  const vostok::input::keyboard *keyboard; // [esp+14h] [ebp-1Ch]
  int v24; // [esp+18h] [ebp-18h] BYREF
  int v25; // [esp+1Ch] [ebp-14h]
  int v26; // [esp+20h] [ebp-10h]
  char v27; // [esp+24h] [ebp-Ch]
  int v28; // [esp+28h] [ebp-8h]
  char v29; // [esp+2Ch] [ebp-4h]

  if ( action == kb_key_down || action == kb_key_up )
  {
    bind = survarium::swf_input_translator::get_bind(a2, &this->char_map, key);
    v8 = (survarium::dik_to_swf_bind *)bind;
    if ( !bind )
      return 0;
    survarium::flash_movie::HandleKeyboard((int)movie, *(Scaleform::Key::Code *)&bind[8].gap0, movie, action);
    if ( v8->is_character && action == kb_key_down )
    {
      v10 = input_world;
      v11 = input_world->get_keyboard(input_world);
      if ( v11->is_key_down(v11, key_lshift)
        || (v12 = input_world->get_keyboard(input_world), LOBYTE(is_shift_now) = 0, v12->is_key_down(v12, key_rshift)) )
      {
        LOBYTE(is_shift_now) = 1;
      }
      v13 = survarium::swf_input_translator::translate_key_action(input_world, v8, is_shift_now, v21);
      if ( !v13 )
        return 0;
      survarium::flash_movie::HandleChar((survarium::flash_movie *)v13, (int)movie);
      movie->m_last_keyb_hold_time = time_current_ms + 500;
    }
    else
    {
      v10 = input_world;
      movie->m_last_keyb_hold_time = time_current_ms + 500;
    }
  }
  else
  {
    v10 = input_world;
  }
  if ( action == kb_key_hold && movie->m_last_keyb_hold_time + 100 < time_current_ms )
  {
    v14 = v10->get_keyboard(v10);
    keyboard = v14;
    if ( v14->is_key_down(v14, key_lshift) || (LOBYTE(is_shift_now) = 0, v14->is_key_down(v14, key_rshift)) )
      LOBYTE(is_shift_now) = 1;
    for ( i = 0; (unsigned int)i < 0x100; ++i )
    {
      if ( v14->is_key_down(v14, i) )
      {
        v17 = survarium::swf_input_translator::get_bind(v16, &this->char_map, i);
        v18 = (survarium::dik_to_swf_bind *)v17;
        if ( v17 )
        {
          if ( i == key_back || i == key_delete || i == key_left || i == key_right )
          {
            m_movie = movie->m_movie;
            v26 = *(_DWORD *)&v17[8].gap0;
            LOBYTE(v25) = 0;
            v24 = 5;
            v27 = 0;
            v28 = 0;
            v29 = 0;
            m_movie->HandleEvent(m_movie, (const Scaleform::GFx::Event *)&v24);
          }
          if ( v18->is_character )
          {
            v20 = survarium::swf_input_translator::translate_key_action(input_world, v18, is_shift_now, v21);
            if ( v20 )
              survarium::flash_movie::HandleChar((survarium::flash_movie *)v20, (int)movie);
            v14 = keyboard;
          }
        }
      }
    }
    movie->m_last_keyb_hold_time = time_current_ms;
  }
  return 1;
}
