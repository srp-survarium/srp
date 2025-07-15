char __usercall vostok::ui::calc_string_length@<al>(vostok::ui::font *f@<edi>, char *str@<eax>)
{
  float v2; // xmm0_4
  char *v3; // esi
  char result; // al
  char v5; // [esp+7h] [ebp-1h] BYREF

  v2 = 0.0;
  v3 = str;
  for ( result = *str; result; result = *v3 )
  {
    v5 = result;
    v2 = *(float *)(f->get_char_tc(f, (const unsigned __int8 *)&v5) + 8) + v2;
    ++v3;
  }
  return result;
}
