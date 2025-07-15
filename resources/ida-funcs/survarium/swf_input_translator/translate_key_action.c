wchar_t __userpurge survarium::swf_input_translator::translate_key_action@<ax>(
        vostok::input::world *input_world@<edi>,
        survarium::dik_to_swf_bind *current@<esi>,
        survarium::swf_input_translator *this,
        bool is_shift_now)
{
  wchar_t c_shift; // bp
  const vostok::input::keyboard *v6; // eax
  wchar_t buff[64]; // [esp+Ch] [ebp-80h] BYREF

  if ( (_BYTE)this )
    c_shift = current->c_shift;
  else
    c_shift = current->c;
  if ( current->translate )
  {
    if ( (_S3_2 & 1) == 0 )
    {
      _S3_2 |= 1u;
      current_locale_0 = (localeinfo_struct *)_create_locale(0, (char *)&buf);
    }
    v6 = input_world->get_keyboard(input_world);
    if ( v6->get_dik_unicode(v6, current->key, buff, 128u) )
    {
      if ( (_BYTE)this )
      {
        if ( buff[0] == current->c )
          buff[0] = c_shift;
        _wcsupr_s_l(buff, 0x40u, current_locale_0);
        return buff[0];
      }
      else
      {
        _wcslwr_s_l(buff, 0x40u, current_locale_0);
        return buff[0];
      }
    }
    else
    {
      return c_shift;
    }
  }
  else if ( (_BYTE)this )
  {
    return current->c_shift;
  }
  else
  {
    return current->c;
  }
}
