char __usercall vostok::ui::calc_string_length@<al>(vostok::ui::ui_font *f@<edi>, const char *str@<eax>)
{
  const char *v2; // esi
  char v3; // al
  float v4; // xmm0_4
  char v5; // [esp+3h] [ebp-5h] BYREF
  float result; // [esp+4h] [ebp-4h]

  v2 = str;
  v3 = *str;
  for ( result = 0.0; v3; result = v4 + result )
  {
    v5 = v3;
    v4 = *(float *)(f->get_char_tc(f, (const unsigned __int8 *)&v5) + 8);
    v3 = *++v2;
  }
  return v3;
}
