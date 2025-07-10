void __thiscall vostok::ui::ui_text<vostok::ui::dynamic_text>::split_and_set_text(
        vostok::ui::ui_text<vostok::ui::dynamic_text> *this,
        const char *str,
        float width,
        const char **ret_str)
{
  const char *v5; // ebx
  float v6; // xmm0_4
  float v7; // xmm1_4
  const vostok::ui::ui_font *m_font; // [esp-18h] [ebp-428h]
  const vostok::ui::ui_font *v9; // [esp-18h] [ebp-428h]
  float curr_word_len; // [esp+0h] [ebp-410h] BYREF
  const char *next_word; // [esp+4h] [ebp-40Ch] BYREF
  float size; // [esp+8h] [ebp-408h]
  char text[1024]; // [esp+10h] [ebp-400h] BYREF

  m_font = this->m_font;
  v5 = str;
  curr_word_len = 0.0;
  next_word = 0;
  size = 0.0;
  vostok::ui::parse_word(str, m_font, &curr_word_len, &next_word);
  v6 = curr_word_len;
  if ( width > curr_word_len )
  {
    v7 = size;
    do
    {
      if ( !strlen(v5) )
        break;
      if ( v5 == next_word )
      {
        v9 = this->m_font;
        size = v7 + v6;
        vostok::ui::parse_word(v5, v9, &curr_word_len, &next_word);
        v6 = curr_word_len;
        v7 = size;
      }
      else
      {
        ++v5;
      }
    }
    while ( width > (float)(v7 + v6) );
  }
  strncpy_s(text, 0x400u, str, strlen(str) - strlen(v5));
  this->set_text(this, text);
  *ret_str = &next_word[strlen(next_word) + 1] != next_word + 1 ? v5 : 0;
}
