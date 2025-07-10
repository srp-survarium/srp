int __userpurge vostok::ui::ui_text_edit::calc_right_word_position@<eax>(
        vostok::ui::ui_text_edit *this@<ecx>,
        int a2@<eax>,
        unsigned __int16 caret)
{
  int v3; // esi
  int v4; // edi
  int v5; // eax
  char v6; // dl
  int v7; // eax
  char *v8; // ecx
  bool v9; // bl
  char v10; // cl
  bool v11; // cl
  bool v12; // zf

  v3 = a2 + 4;
  v4 = (*(int (__thiscall **)(int))(*(_DWORD *)(a2 + 4) + 12))(a2 + 4);
  v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(v3);
  v6 = *(_BYTE *)(v5 + caret + 1);
  v7 = v5 + caret + 1;
  v8 = (char *)(v7 - 1);
  if ( v6 )
  {
    while ( 1 )
    {
      v9 = v6 == 32
        || v6 == 9
        || v6 == 13
        || v6 == 10
        || v6 == 44
        || v6 == 46
        || v6 == 58
        || v6 == 33
        || v6 == 40
        || v6 == 41
        || v6 == 45
        || v6 == 43
        || v6 == 42;
      v10 = *v8;
      v11 = v10 == 32
         || v10 == 9
         || v10 == 13
         || v10 == 10
         || v10 == 44
         || v10 == 46
         || v10 == 58
         || v10 == 33
         || v10 == 40
         || v10 == 41
         || v10 == 45
         || v10 == 43
         || v10 == 42;
      if ( !v9 )
        break;
      if ( v11 && v6 != 32 )
      {
        v12 = v6 == 9;
LABEL_37:
        if ( !v12 )
          return v7 - v4;
      }
      v6 = *(_BYTE *)(v7 + 1);
      v8 = (char *)v7++;
      if ( !v6 )
        return v7 - v4;
    }
    v12 = !v11;
    goto LABEL_37;
  }
  return v7 - v4;
}
