int __usercall vostok::ui::calc_string_length_n@<eax>(
        int str@<eax>,
        const unsigned __int16 str_len@<cx>,
        vostok::ui::ui_font *f)
{
  char *v3; // esi
  bool v4; // zf
  const vostok::math::float3 *(__thiscall *get_char_tc)(struct vostok::ui::ui_font *, const unsigned __int8 *); // edx
  char v7; // [esp+3h] [ebp-5h] BYREF
  float result; // [esp+4h] [ebp-4h]

  v3 = (char *)str;
  v4 = *(_BYTE *)str == 0;
  for ( result = 0.0; !v4; result = *(float *)(str + 8) + result )
  {
    if ( !str_len )
      break;
    get_char_tc = f->get_char_tc;
    v7 = *v3;
    str = (int)get_char_tc(f, (const unsigned __int8 *)&v7);
    ++v3;
    --str_len;
    v4 = *v3 == 0;
  }
  return str;
}
