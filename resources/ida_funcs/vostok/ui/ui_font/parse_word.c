void __thiscall vostok::ui::ui_font::parse_word(
        vostok::ui::ui_font *this,
        const char *str,
        float *out_length,
        const char **out_next_word)
{
  vostok::ui::parse_word(str, out_length, this, out_next_word);
}
