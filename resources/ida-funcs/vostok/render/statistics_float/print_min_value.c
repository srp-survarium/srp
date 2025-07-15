void __thiscall vostok::render::statistics_float::print_min_value(
        vostok::render::statistics_float *this,
        vostok::fs_new::virtual_path_string *out_result)
{
  vostok::buffer_string *v3; // ecx
  vostok::buffer_string *v4; // ecx
  const char *m_decimal_numbers; // [esp+4h] [ebp-120h]
  vostok::buffer_string v6[22]; // [esp+10h] [ebp-114h] BYREF
  char v7; // [esp+120h] [ebp-4h]

  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)this, v6, "%.");
  m_decimal_numbers = (const char *)this->m_decimal_numbers;
  v7 = 47;
  vostok::buffer_string::appendf(v6, v3, (vostok::buffer_string *)"%df", m_decimal_numbers);
  vostok::fs_new::path_string_impl::assignf(
    out_result,
    v4,
    (vostok::buffer_string *)v6[0].m_begin,
    (const char *)COERCE_UNSIGNED_INT64(this->min_value),
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(this->min_value)));
}
