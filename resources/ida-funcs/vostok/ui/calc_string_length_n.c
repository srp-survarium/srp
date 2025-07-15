int __usercall vostok::ui::calc_string_length_n@<eax>(
        int str@<eax>,
        const unsigned __int16 str_len@<cx>,
        vostok::ui::ui_font *f)
{
  float v3; // xmm0_4
  char *i; // esi
  char v6; // [esp+7h] [ebp-1h] BYREF

  v3 = 0.0;
  for ( i = (char *)str; *i && str_len; ++i )
  {
    v6 = *i;
    str = f->get_char_tc(f, (const unsigned __int8 *)&v6);
    v3 = *(float *)(str + 8) + v3;
    --str_len;
  }
  return str;
}
