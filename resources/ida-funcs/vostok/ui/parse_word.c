void __usercall vostok::ui::parse_word(
        char *str@<eax>,
        float *length@<edi>,
        int a3@<ecx>,
        vostok::ui::ui_font *font,
        char **next_word)
{
  char v6; // al
  char v7; // [esp+1h] [ebp-1h] BYREF

  v7 = HIBYTE(a3);
  *length = 0.0;
  while ( *str )
  {
    v7 = *str;
    *length = *(float *)(font->get_char_tc(font, (const unsigned __int8 *)&v7) + 8) + *length;
    v6 = *str;
    if ( *str == 32 || v6 == 9 || v6 == 13 || v6 == 10 || v6 == 44 || v6 == 46 || v6 == 58 || v6 == 33 )
    {
      ++str;
      break;
    }
    ++str;
  }
  *next_word = str;
}
