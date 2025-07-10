void __usercall vostok::apply_new_tip(
        vostok::ui::text_edit *text_edit@<edi>,
        vostok::enum_tips_mode mode,
        char *new_tip)
{
  vostok::ui::text *v3; // eax
  vostok::ui::text_vtbl *v4; // edx
  char *v5; // eax
  char *m_buffer; // ecx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // esi
  vostok::ui::text *v10; // eax
  vostok::fixed_string<512> str; // [esp+4h] [ebp-20Ch] BYREF
  _UNKNOWN *retaddr; // [esp+210h] [ebp+0h] BYREF

  v3 = text_edit->text(text_edit);
  v4 = v3->__vftable;
  if ( mode == tm_arg_list )
  {
    v5 = (char *)v4->get_text(v3);
    m_buffer = str.m_buffer;
    str.m_end = str.m_buffer;
    str.m_buffer[0] = 0;
    if ( v5 )
    {
      for ( ; *v5; ++str.m_end )
      {
        if ( m_buffer >= (char *)&retaddr )
          break;
        *m_buffer = *v5;
        m_buffer = str.m_end + 1;
        ++v5;
      }
      *m_buffer = 0;
    }
    strchr(str.m_buffer, 0x20u);
    if ( v7 )
      v8 = v7 - (_DWORD)str.m_buffer;
    else
      v8 = -1;
    str.m_end = &str.m_buffer[v8 + 1];
    *str.m_end = 0;
    v9 = strlen(new_tip);
    memcpy((unsigned __int8 *)str.m_end, (unsigned __int8 *)new_tip, v9);
    str.m_end[v9] = 0;
    v10 = text_edit->text(text_edit);
    v10->set_text(v10, str.m_buffer);
  }
  else
  {
    v4->set_text(v3, new_tip);
  }
}
