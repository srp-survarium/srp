unsigned __int8 *__userpurge vostok::ui::ui_text_edit::calc_right_word_position@<eax>(
        vostok::ui::ui_text_edit *this@<ecx>,
        int a2@<eax>,
        unsigned __int16 caret)
{
  int v3; // esi
  int v4; // edi
  unsigned __int8 *v5; // ecx
  unsigned __int8 v6; // bl
  unsigned __int8 *v7; // edx
  bool v8; // al
  bool v9; // zf
  bool is_delim; // [esp+13h] [ebp+Bh]

  v3 = a2 + 4;
  v4 = (*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 4) + 12))(a2 + 4);
  v5 = (unsigned __int8 *)((*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(v3) + caret + 1);
  if ( *v5 )
  {
    v6 = *v5;
    while ( 1 )
    {
      is_delim = vostok::ui::is_delim(v6);
      v8 = vostok::ui::is_delim(*v7);
      if ( !is_delim )
        break;
      if ( v8 && v6 != 32 )
      {
        v9 = v6 == 9;
LABEL_8:
        if ( !v9 )
          return &v5[-v4];
      }
      v6 = *++v5;
      if ( !*v5 )
        return &v5[-v4];
    }
    v9 = !v8;
    goto LABEL_8;
  }
  return &v5[-v4];
}
