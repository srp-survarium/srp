void __usercall vostok::ui::parse_word(
        const char *str@<eax>,
        float *length@<edi>,
        vostok::ui::ui_font *font,
        const char **next_word)
{
  const char **v4; // ebp
  const char *v5; // esi
  char v6; // al
  char v7; // al

  v4 = next_word;
  v5 = str;
  *length = 0.0;
  v6 = *str;
  if ( v6 )
  {
    while ( 1 )
    {
      LOBYTE(next_word) = v6;
      *length = *(float *)(font->get_char_tc(font, (const unsigned __int8 *)&next_word) + 8) + *length;
      v7 = *v5;
      if ( *v5 == 32 || v7 == 9 || v7 == 13 || v7 == 10 || v7 == 44 || v7 == 46 || v7 == 58 || v7 == 33 )
        break;
      v6 = *++v5;
      if ( !v6 )
      {
        *v4 = v5;
        return;
      }
    }
    ++v5;
  }
  *v4 = v5;
}
