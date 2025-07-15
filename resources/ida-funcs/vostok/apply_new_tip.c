void __usercall vostok::apply_new_tip(
        vostok::ui::text_edit *text_edit@<edi>,
        int a2@<esi>,
        vostok::enum_tips_mode mode,
        char *new_tip)
{
  vostok::ui::text_edit_vtbl *v4; // eax
  int v5; // eax
  char *v6; // eax
  vostok::fixed_string<512> *v7; // ecx
  int v8; // eax
  char *m_begin; // ecx
  int v10; // eax
  vostok::ui::text *v11; // eax
  int v12; // eax
  vostok::buffer_string string[43]; // [esp+0h] [ebp-20Ch] BYREF

  v4 = text_edit->__vftable;
  if ( mode == tm_arg_list )
  {
    v5 = ((int (__thiscall *)(vostok::ui::text_edit *, int))v4->text)(text_edit, a2);
    v6 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 12))(v5);
    vostok::fixed_string<512>::fixed_string<512>(v7, string, v6);
    strchr(string[0].m_begin, 0x20u);
    m_begin = string[0].m_begin;
    if ( v8 )
      v10 = v8 - (unsigned int)string[0].m_begin;
    else
      v10 = -1;
    string[0].m_end = &string[0].m_begin[v10 + 1];
    *string[0].m_end = 0;
    vostok::buffer_string::append((vostok::buffer_string *)m_begin, (int)string, new_tip);
    v11 = text_edit->text(text_edit);
    v11->set_text(v11, string[0].m_begin);
  }
  else
  {
    v12 = (int)v4->text(text_edit);
    (*(void (__thiscall **)(int, char *))(*(_DWORD *)v12 + 8))(v12, new_tip);
  }
}
