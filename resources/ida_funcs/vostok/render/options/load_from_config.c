void __userpurge vostok::render::options::load_from_config(
        vostok::configs::binary_config_value *config@<edi>,
        vostok::render::options *this)
{
  vostok::console_commands::console_command *i; // esi
  const vostok::configs::binary_config_value *v3; // eax
  unsigned __int16 type; // dx
  float v5; // xmm0_4
  bool v6; // zf
  survarium::keyboard_key_descr **v7; // eax
  int pointer; // [esp+4h] [ebp-144h]
  vostok::fs_new::virtual_path_string value; // [esp+30h] [ebp-118h] BYREF

  for ( i = this->first_command; i; i = i->m_next )
  {
    if ( vostok::configs::binary_config_value::value_exists(config, i->m_name) )
    {
      v3 = vostok::configs::binary_config_value::operator[](config, i->m_name);
      type = v3->type;
      if ( type )
      {
        value.m_string.m_buffer[0] = 0;
        value.m_separator = 47;
        value.m_string.m_begin = value.m_string.m_buffer;
        if ( type == 1 )
        {
          value.m_string.m_end = value.m_string.m_buffer;
          pointer = (int)v3->data.pointer;
          value.m_string.m_max_end = &value.m_separator;
          vostok::fs_new::path_string_impl::assignf(&value, "%d", pointer);
          i->execute(i, value.m_string.m_begin);
        }
        else
        {
          value.m_string.m_end = value.m_string.m_buffer;
          value.m_string.m_max_end = &value.m_separator;
          if ( type == 2 )
            v5 = *(float *)&v3->data.pointer;
          else
            v5 = (float)(int)v3->data.pointer;
          vostok::fs_new::path_string_impl::assignf(
            &value,
            (const char *)&stru_95AF78.m_key_bindings[63].m_keyboard[1],
            v5);
          i->execute(i, value.m_string.m_begin);
        }
      }
      else
      {
        v6 = v3->data.pointer == 0;
        v7 = &stru_95AF78.m_key_bindings[4].m_keyboard[1];
        if ( v6 )
          v7 = (survarium::keyboard_key_descr **)&stru_95AF78.m_key_bindings[6];
        i->execute(i, (const char *)v7);
      }
    }
    if ( i == this->last_command )
      break;
  }
}
