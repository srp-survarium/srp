void __thiscall vostok::ui::ui_font::parse_word(
        vostok::ui::ui_font *this,
        char *str,
        float *out_length,
        char **out_next_word)
{
  vostok::ui::parse_word(str, out_length, (int)this, this, out_next_word);
}
